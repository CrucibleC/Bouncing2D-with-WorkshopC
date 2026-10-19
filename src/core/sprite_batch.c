#include "core/sprite_batch.h"

#include <assert.h>
#include <math.h>
#include <stdint.h>

#include "util/dynamic_array.h"
#include "workshopc_tags.h"

// Per sphere: 4 vertices of 2 position floats, 4 color floats and 2 texture floats, and 6 indices
static const size_t XY_PER_SPRITE = 8;
static const size_t COLORS_PER_SPRITE = 16;
static const size_t UV_PER_SPRITE = 8;
static const size_t INDICES_PER_SPRITE = 6;
// Every buffer starts with room for this many sprites
static const size_t INITIAL_SPRITES = 8;
// Smaller spheres are drawn with this radius (pixels), so they stay visible
static const f32 MIN_RADIUS = 0.75f;

// Makes block hold at least count elements, growing by doubling; never shrinks
static bool core_sprite_batch_reserve(borrows massive memory_block* block, size_t count)
{
    size_t capacity = memory_block_count(block);
    return count <= capacity || memory_block_resize(block, util_dynamic_array_resize(count, capacity));
}

core_sprite_batch_view core_sprite_batch_view_pod(size_t count, const f32* xy, const f32* colors, const f32* uv,
                                                  const u32* indices)
{
    return (core_sprite_batch_view){ .count = count, .xy = xy, .colors = colors, .uv = uv, .indices = indices };
}

core_sprite_batch core_sprite_batch_make(void)
{
    return (core_sprite_batch){
        .xy = memory_block_make(INITIAL_SPRITES * XY_PER_SPRITE, sizeof(f32)),
        .colors = memory_block_make(INITIAL_SPRITES * COLORS_PER_SPRITE, sizeof(f32)),
        .uv = memory_block_make(INITIAL_SPRITES * UV_PER_SPRITE, sizeof(f32)),
        .indices = memory_block_make(INITIAL_SPRITES * INDICES_PER_SPRITE, sizeof(u32)),
        .count = 0,
    };
}

void core_sprite_batch_destroy(borrows massive core_sprite_batch* self)
{
    memory_block_destroy(&self->indices);
    memory_block_destroy(&self->uv);
    memory_block_destroy(&self->colors);
    memory_block_destroy(&self->xy);
    self->count = 0;
}

bool core_sprite_batch_valid(massive const core_sprite_batch* self)
{
    return memory_block_valid(&self->xy) && memory_block_valid(&self->colors) && memory_block_valid(&self->uv)
        && memory_block_valid(&self->indices);
}

status core_sprite_batch_status(massive const core_sprite_batch* self)
{
    status result = memory_block_status(&self->xy);
    if (result == STATUS_OK)
    {
        result = memory_block_status(&self->colors);
    }
    if (result == STATUS_OK)
    {
        result = memory_block_status(&self->uv);
    }
    if (result == STATUS_OK)
    {
        result = memory_block_status(&self->indices);
    }
    return result;
}

status core_sprite_batch_prepare(borrows massive core_sprite_batch* self, massive const core_spheres_const_view* spheres)
{
    assert(core_spheres_const_view_is_current(spheres));   // a view taken before a resize is stale
    size_t count = spheres->count;
    self->count = 0;
    // Vertex numbers are u32 (4 per sphere) and SDL counts vertices in an int
    if (count > cast_i32_to_size_t(INT32_MAX / 4) || count > SIZE_MAX / COLORS_PER_SPRITE)
    {
        return STATUS_OUT_OF_RANGE;
    }
    bool reserved = core_sprite_batch_reserve(&self->xy, count * XY_PER_SPRITE)
                 && core_sprite_batch_reserve(&self->colors, count * COLORS_PER_SPRITE)
                 && core_sprite_batch_reserve(&self->uv, count * UV_PER_SPRITE)
                 && core_sprite_batch_reserve(&self->indices, count * INDICES_PER_SPRITE);
    f32* restrict colors = memory_block_data(&self->colors);
    f32* restrict uv = memory_block_data(&self->uv);
    u32* restrict indices = memory_block_data(&self->indices);
    if (!reserved || colors == NULL || uv == NULL || indices == NULL)
    {
        return core_sprite_batch_status(self) != STATUS_OK ? core_sprite_batch_status(self) : STATUS_OUT_OF_MEMORY;
    }
    for (size_t i = 0; i < count; i++)
    {
        f32 r = cast_u8_to_f32(spheres->rgba[i].r) / 255.0f;
        f32 g = cast_u8_to_f32(spheres->rgba[i].g) / 255.0f;
        f32 b = cast_u8_to_f32(spheres->rgba[i].b) / 255.0f;
        f32 a = cast_u8_to_f32(spheres->rgba[i].a) / 255.0f;
        for (size_t corner = 0; corner < 4; corner++)
        {
            size_t at = i * COLORS_PER_SPRITE + corner * 4;
            colors[at] = r;
            colors[at + 1] = g;
            colors[at + 2] = b;
            colors[at + 3] = a;
        }
        // Corners in the order top-left, top-right, bottom-right, bottom-left
        size_t uv_at = i * UV_PER_SPRITE;
        uv[uv_at] = 0.0f;
        uv[uv_at + 1] = 0.0f;
        uv[uv_at + 2] = 1.0f;
        uv[uv_at + 3] = 0.0f;
        uv[uv_at + 4] = 1.0f;
        uv[uv_at + 5] = 1.0f;
        uv[uv_at + 6] = 0.0f;
        uv[uv_at + 7] = 1.0f;
        // Two triangles per quad: 0-1-2 and 0-2-3
        u32 first = cast_size_t_to_u32(i * 4);
        size_t index_at = i * INDICES_PER_SPRITE;
        indices[index_at] = first;
        indices[index_at + 1] = first + 1;
        indices[index_at + 2] = first + 2;
        indices[index_at + 3] = first;
        indices[index_at + 4] = first + 2;
        indices[index_at + 5] = first + 3;
    }
    self->count = count;
    core_sprite_batch_update(self, spheres);
    return STATUS_OK;
}

void core_sprite_batch_update(borrows massive core_sprite_batch* self, massive const core_spheres_const_view* spheres)
{
    assert(core_spheres_const_view_is_current(spheres));   // a view taken before a resize is stale
    f32* restrict xy = memory_block_data(&self->xy);
    if (xy == NULL || spheres->count != self->count)
    {
        return;
    }
    const f32* restrict x = spheres->x;
    const f32* restrict y = spheres->y;
    const f32* restrict radius = spheres->radius;
    size_t count = self->count;
    for (size_t i = 0; i < count; i++)
    {
        f32 r = radius[i] < MIN_RADIUS ? MIN_RADIUS : radius[i];
        f32 left = x[i] - r;
        f32 right = x[i] + r;
        f32 top = y[i] - r;
        f32 bottom = y[i] + r;
        size_t at = i * XY_PER_SPRITE;
        xy[at] = left;
        xy[at + 1] = top;
        xy[at + 2] = right;
        xy[at + 3] = top;
        xy[at + 4] = right;
        xy[at + 5] = bottom;
        xy[at + 6] = left;
        xy[at + 7] = bottom;
    }
}

size_t core_sprite_batch_count(massive const core_sprite_batch* self)
{
    return self->count;
}

core_sprite_batch_view core_sprite_batch_get_view(massive const core_sprite_batch* self)
{
    return core_sprite_batch_view_pod(self->count, memory_block_const_data(&self->xy),
                                      memory_block_const_data(&self->colors), memory_block_const_data(&self->uv),
                                      memory_block_const_data(&self->indices));
}

f32 core_sprite_batch_min_radius(void)
{
    return MIN_RADIUS;
}

f32 core_sprite_circle_alpha(u32 size, u32 px, u32 py)
{
    if (size == 0 || px >= size || py >= size)
    {
        return 0.0f;
    }
    f32 center = cast_u32_to_f32(size) * 0.5f;
    f32 dx = cast_u32_to_f32(px) + 0.5f - center;
    f32 dy = cast_u32_to_f32(py) + 0.5f - center;
    // Inside the radius fully opaque, fading out over the outermost pixel
    f32 coverage = center - sqrtf(dx * dx + dy * dy);
    return coverage < 0.0f ? 0.0f : (coverage > 1.0f ? 1.0f : coverage);
}
