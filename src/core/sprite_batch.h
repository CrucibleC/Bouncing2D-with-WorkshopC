#ifndef CORE_SPRITE_BATCH_H
#define CORE_SPRITE_BATCH_H

#include <stdbool.h>
#include <stddef.h>

#include "core/spheres.h"
#include "memory_block.h"
#include "numbers.h"
#include "raii_delete.h"
#include "status.h"
#include "workshopc_tags.h"

// Vertex data for drawing every sphere in one call: each sphere is a quad (4 vertices, 6 indices)
// showing a white circle texture tinted by the sphere's color. The arrays are separate (SoA), as
// SDL_RenderGeometryRaw takes them:
//   xy      2 f32 per vertex, rewritten every frame from x, y and radius
//   colors  4 f32 per vertex (r, g, b, a in 0..1), written when the spheres change
//   uv      2 f32 per vertex, the same corners for every quad
//   indices 6 u32 per sphere: two triangles per quad
// Only xy changes per frame. Buffers grow and never shrink.
typedef struct core_sprite_batch
{
    confined memory_block xy;
    confined memory_block colors;
    confined memory_block uv;
    confined memory_block indices;
    confined size_t count;   // spheres prepared
} core_sprite_batch;

// The arrays, for the window's draw call: count sprites, 4 * count vertices, 6 * count indices.
// Valid until the next prepare, move or destroy
typedef struct core_sprite_batch_view
{
    size_t count;
    const f32* xy;
    const f32* colors;
    const f32* uv;
    const u32* indices;
} core_sprite_batch_view;

// { count, xy, colors, uv, indices }
core_sprite_batch_view core_sprite_batch_view_pod(size_t count, const f32* xy, const f32* colors, const f32* uv,
                                                  const u32* indices);

// An empty batch; invalid when an allocation fails
core_sprite_batch core_sprite_batch_make(void);
NO_COPY(core_sprite_batch);
NO_MOVE(core_sprite_batch);
void core_sprite_batch_destroy(borrows massive core_sprite_batch* self);
NO_RETURN(core_sprite_batch);
bool core_sprite_batch_valid(massive const core_sprite_batch* self);
status core_sprite_batch_status(massive const core_sprite_batch* self);

// For new or resized spheres: grows the buffers and writes colors, uv and indices for every
// sphere, then the positions. On failure the batch is empty (count 0)
status core_sprite_batch_prepare(borrows massive core_sprite_batch* self, massive const core_spheres_const_view* spheres);
// Every frame: rewrites the quads' corners from x, y and radius (at least the minimum on-screen
// radius). Does nothing when spheres->count differs from the prepared count
void core_sprite_batch_update(borrows massive core_sprite_batch* self, massive const core_spheres_const_view* spheres);
size_t core_sprite_batch_count(massive const core_sprite_batch* self);
core_sprite_batch_view core_sprite_batch_get_view(massive const core_sprite_batch* self);

// The smallest radius a sphere is drawn with, in pixels, so even tiny spheres stay visible
f32 core_sprite_batch_min_radius(void);

// The alpha (0..1) of the circle texture at pixel (px, py) of a size x size texture: 1 inside the
// circle, 0 outside, a one-pixel soft edge in between (anti-aliasing)
f32 core_sprite_circle_alpha(u32 size, u32 px, u32 py);

#endif // CORE_SPRITE_BATCH_H
