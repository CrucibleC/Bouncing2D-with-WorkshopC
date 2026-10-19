#include "core/spheres.h"

#include <assert.h>
#include <stdint.h>
#include <string.h>

#include "workshopc_tags.h"

// Bytes per sphere slot: x, y, vx, vy, radius and the four color bytes
#define CORE_SPHERES_SLOT_SIZE (5 * sizeof(f32) + sizeof(data_rgba))
static_assert(sizeof(data_rgba) == 4, "data_rgba must be four bytes");
static_assert(CORE_SPHERES_SLOT_SIZE == 24, "a sphere slot must be 24 bytes");

// Arrays are a multiple of this many elements long, so each starts 64 bytes after the previous one
static const size_t LANE = 16;

// count rounded up to a multiple of LANE, at least LANE; 0 when that would overflow
static size_t core_spheres_stride_for(size_t count)
{
    if (count > (SIZE_MAX - LANE) / CORE_SPHERES_SLOT_SIZE)
    {
        return 0;
    }
    size_t lanes = count / LANE + (count % LANE != 0 ? 1 : 0);
    return lanes == 0 ? LANE : lanes * LANE;
}

core_spheres_view core_spheres_view_pod(size_t count, MUTABLE f32* x, MUTABLE f32* y, MUTABLE f32* vx,
                                        MUTABLE f32* vy, MUTABLE f32* radius, MUTABLE data_rgba* rgba,
                                        const u32* generation, u32 taken_at)
{
    return (core_spheres_view){ .count = count, .x = x, .y = y, .vx = vx, .vy = vy, .radius = radius, .rgba = rgba,
                                .generation = generation, .taken_at = taken_at };
}

core_spheres_const_view core_spheres_const_view_pod(size_t count, const f32* x, const f32* y, const f32* vx,
                                                    const f32* vy, const f32* radius, const data_rgba* rgba,
                                                    const u32* generation, u32 taken_at)
{
    return (core_spheres_const_view){ .count = count, .x = x, .y = y, .vx = vx, .vy = vy, .radius = radius,
                                      .rgba = rgba, .generation = generation, .taken_at = taken_at };
}

core_spheres core_spheres_make(size_t count)
{
    size_t stride = core_spheres_stride_for(count);
    core_spheres result = {
        .block = memory_block_make(stride, CORE_SPHERES_SLOT_SIZE),
        .count = 0,
        .stride = 0,
        .generation = 0,
    };
    // calloc'd: every sphere starts zeroed
    if (memory_block_valid(&result.block))
    {
        result.count = count;
        result.stride = stride;
    }
    return core_spheres_return(&result);
}

core_spheres core_spheres_copy(REF const core_spheres* self)
{
    core_spheres result = {
        .block = memory_block_copy(&self->block),
        .count = 0,
        .stride = 0,
        .generation = 0,
    };
    if (memory_block_valid(&result.block))
    {
        result.count = self->count;
        result.stride = self->stride;
    }
    return core_spheres_return(&result);
}

core_spheres core_spheres_move(MUTABLE REF core_spheres* self)
{
    core_spheres result = {
        .block = memory_block_move(&self->block),
        .count = self->count,
        .stride = self->stride,
        .generation = 0,
    };
    // Views of the source no longer match: its arrays now belong to result
    self->count = 0;
    self->stride = 0;
    self->generation += 1;
    return result;
}

void core_spheres_destroy(MUTABLE REF core_spheres* self)
{
    memory_block_destroy(&self->block);
    self->count = 0;
    self->stride = 0;
    self->generation += 1;
}

core_spheres core_spheres_return(MUTABLE REF core_spheres* self)
{
    return *self;
}

bool core_spheres_valid(REF const core_spheres* self)
{
    return memory_block_valid(&self->block);
}

status core_spheres_status(REF const core_spheres* self)
{
    return memory_block_status(&self->block);
}

status core_spheres_resize(MUTABLE REF core_spheres* self, size_t count)
{
    size_t stride = core_spheres_stride_for(count);
    if (stride == 0)
    {
        return STATUS_OUT_OF_RANGE;
    }
    // realloc keeps the old block on failure, so the spheres stay as they were
    bool same_size = memory_block_valid(&self->block) && stride == self->stride;
    if (!same_size && !memory_block_resize(&self->block, stride))
    {
        return memory_block_status(&self->block);
    }
    // Every sphere starts over at zero: the arrays moved with the stride, so old values aren't kept
    char* bytes = memory_block_data(&self->block);
    if (bytes != NULL)
    {
        (void)memset(bytes, 0, stride * CORE_SPHERES_SLOT_SIZE);
    }
    self->count = count;
    self->stride = stride;
    self->generation += 1;   // the arrays may have moved, and the old values are gone
    return STATUS_OK;
}

size_t core_spheres_count(REF const core_spheres* self)
{
    return self->count;
}

// The arrays sit stride elements apart: x, y, vx, vy, radius (f32), then rgba (data_rgba).
// Every offset is a multiple of 64 bytes, so each typed pointer is correctly aligned
core_spheres_view core_spheres_get_view(MUTABLE REF core_spheres* self)
{
    char* base = memory_block_data(&self->block);
    if (base == NULL)
    {
        return core_spheres_view_pod(0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0);
    }
    size_t array_bytes = self->stride * sizeof(f32);
    return core_spheres_view_pod(self->count, (f32*)(void*)&base[0], (f32*)(void*)&base[array_bytes],
                                 (f32*)(void*)&base[2 * array_bytes], (f32*)(void*)&base[3 * array_bytes],
                                 (f32*)(void*)&base[4 * array_bytes], (data_rgba*)(void*)&base[5 * array_bytes],
                                 &self->generation, self->generation);
}

core_spheres_const_view core_spheres_get_const_view(REF const core_spheres* self)
{
    const char* base = memory_block_const_data(&self->block);
    if (base == NULL)
    {
        return core_spheres_const_view_pod(0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0);
    }
    size_t array_bytes = self->stride * sizeof(f32);
    return core_spheres_const_view_pod(
        self->count, (const f32*)(const void*)&base[0], (const f32*)(const void*)&base[array_bytes],
        (const f32*)(const void*)&base[2 * array_bytes], (const f32*)(const void*)&base[3 * array_bytes],
        (const f32*)(const void*)&base[4 * array_bytes], (const data_rgba*)(const void*)&base[5 * array_bytes],
        &self->generation, self->generation);
}

bool core_spheres_get(REF const core_spheres* self, size_t index, OUTPUT REF data_sphere* sphere)
{
    core_spheres_const_view view = core_spheres_get_const_view(self);
    if (index >= view.count)
    {
        *sphere = data_sphere_pod(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, data_rgba_pod(0, 0, 0, 0));
        return false;
    }
    // WorkshopC builds pods only through their creator, not from an array element
    data_rgba color = data_rgba_pod(view.rgba[index].r, view.rgba[index].g, view.rgba[index].b, view.rgba[index].a);
    *sphere = data_sphere_pod(view.x[index], view.y[index], view.vx[index], view.vy[index], view.radius[index], color);
    return true;
}
