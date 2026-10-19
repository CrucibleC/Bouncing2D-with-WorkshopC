#include "core/physics.h"

#include <assert.h>

#include "core/collision.h"
#include "workshopc_tags.h"

void core_physics_move(massive const core_spheres_view* spheres, f32 dt)
{
    assert(core_spheres_view_is_current(spheres));   // a view taken before a resize is stale
    // restrict: the arrays never overlap, so the loop can be vectorized
    f32* restrict x = spheres->x;
    f32* restrict y = spheres->y;
    const f32* restrict vx = spheres->vx;
    const f32* restrict vy = spheres->vy;
    size_t count = spheres->count;
    for (size_t i = 0; i < count; i++)
    {
        x[i] += vx[i] * dt;
        y[i] += vy[i] * dt;
    }
}

size_t core_physics_resolve_walls(massive const core_spheres_view* spheres, data_bounds bounds)
{
    assert(core_spheres_view_is_current(spheres));   // a view taken before a resize is stale
    f32* restrict x = spheres->x;
    f32* restrict y = spheres->y;
    f32* restrict vx = spheres->vx;
    f32* restrict vy = spheres->vy;
    const f32* restrict radius = spheres->radius;
    size_t count = spheres->count;
    size_t touched = 0;
    for (size_t i = 0; i < count; i++)
    {
        // Same per-axis logic as core_collision_resolve_walls, inlined so the loop vectorizes
        f32 px = x[i];
        f32 py = y[i];
        f32 pvx = vx[i];
        f32 pvy = vy[i];
        bool hit_x = core_collision_resolve_axis(&px, &pvx, radius[i], bounds.min_x, bounds.max_x);
        bool hit_y = core_collision_resolve_axis(&py, &pvy, radius[i], bounds.min_y, bounds.max_y);
        x[i] = px;
        y[i] = py;
        vx[i] = pvx;
        vy[i] = pvy;
        touched += (hit_x || hit_y) ? 1U : 0U;
    }
    return touched;
}
