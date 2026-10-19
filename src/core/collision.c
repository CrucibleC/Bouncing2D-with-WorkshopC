#include "core/collision.h"

#include <assert.h>
#include <math.h>

#include "workshopc_tags.h"

bool core_collision_resolve_pair(massive const core_spheres_view* spheres, u32 a, u32 b)
{
    assert(core_spheres_view_is_current(spheres));   // a view taken before a resize is stale
    if (a == b || a >= spheres->count || b >= spheres->count)
    {
        return false;
    }
    // restrict: the arrays never overlap, so the compiler needn't reload after each store
    f32* restrict x = spheres->x;
    f32* restrict y = spheres->y;
    f32* restrict vx = spheres->vx;
    f32* restrict vy = spheres->vy;
    const f32* restrict radius = spheres->radius;

    f32 dx = x[b] - x[a];
    f32 dy = y[b] - y[a];
    f32 reach = radius[a] + radius[b];
    f32 distance_squared = dx * dx + dy * dy;
    // Most pairs don't touch: decided without a square root
    if (distance_squared >= reach * reach)
    {
        return false;
    }

    f32 distance = sqrtf(distance_squared);
    // The normal points from a to b; coincident centers get an arbitrary one
    f32 nx = distance > 0.0f ? dx / distance : 1.0f;
    f32 ny = distance > 0.0f ? dy / distance : 0.0f;

    // Mass is area, pi * r * r; pi cancels in every ratio below
    f32 mass_a = radius[a] * radius[a];
    f32 mass_b = radius[b] * radius[b];
    f32 total_mass = mass_a + mass_b;
    // Each sphere moves by the other's share of the mass: the lighter one moves more
    f32 share_a = total_mass > 0.0f ? mass_b / total_mass : 0.5f;
    f32 share_b = total_mass > 0.0f ? mass_a / total_mass : 0.5f;

    f32 overlap = reach - distance;
    x[a] -= nx * overlap * share_a;
    y[a] -= ny * overlap * share_a;
    x[b] += nx * overlap * share_b;
    y[b] += ny * overlap * share_b;

    // Elastic bounce, only while approaching (the relative velocity along the normal is negative)
    f32 approach = (vx[b] - vx[a]) * nx + (vy[b] - vy[a]) * ny;
    if (approach < 0.0f && total_mass > 0.0f)
    {
        f32 change_a = 2.0f * share_a * approach;
        f32 change_b = 2.0f * share_b * approach;
        vx[a] += change_a * nx;
        vy[a] += change_a * ny;
        vx[b] -= change_b * nx;
        vy[b] -= change_b * ny;
    }
    return true;
}

bool core_collision_resolve_walls(massive const core_spheres_view* spheres, u32 index, data_bounds bounds)
{
    assert(core_spheres_view_is_current(spheres));   // a view taken before a resize is stale
    if (index >= spheres->count)
    {
        return false;
    }
    // Loaded once into locals, worked on, stored once
    f32 radius = spheres->radius[index];
    f32 x = spheres->x[index];
    f32 y = spheres->y[index];
    f32 vx = spheres->vx[index];
    f32 vy = spheres->vy[index];
    bool hit_x = core_collision_resolve_axis(&x, &vx, radius, bounds.min_x, bounds.max_x);
    bool hit_y = core_collision_resolve_axis(&y, &vy, radius, bounds.min_y, bounds.max_y);
    spheres->x[index] = x;
    spheres->y[index] = y;
    spheres->vx[index] = vx;
    spheres->vy[index] = vy;
    return hit_x || hit_y;
}
