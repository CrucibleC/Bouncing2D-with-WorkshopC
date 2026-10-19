#ifndef CORE_COLLISION_H
#define CORE_COLLISION_H

#include <stdbool.h>

#include "core/spheres.h"
#include "data/bounds.h"
#include "numbers.h"
#include "workshopc_tags.h"

// Individual collisions, worked out in place on the spheres' arrays. Pure physics: no window, no
// time step, no globals. Only x, y, vx, vy and radius are read; rgba is never touched.
// Mass is a circle's area, pi * r * r; only mass ratios appear, so pi cancels and r * r is used.

// Resolves spheres a and b if they overlap: pushes them apart along the line between their
// centers (the lighter one moves more) until they just touch, and if they are approaching gives
// both an elastic bounce, which keeps momentum and kinetic energy. Returns whether they touched;
// false and no change for a == b or an index >= spheres->count
bool core_collision_resolve_pair(REF const core_spheres_view* spheres, u32 a, u32 b);

// One axis of the wall check for one sphere: position and velocity on that axis, the box's min
// and max on it. Branchless selects, and static inline so a loop over all spheres (e.g.
// core_physics_resolve_walls) inlines and vectorizes it. Returns whether the sphere was past a side
static inline bool core_collision_resolve_axis(MUTABLE REF f32* position, MUTABLE REF f32* velocity,
                                               f32 radius, f32 min, f32 max)
{
    f32 low = min + radius;
    f32 high = max - radius;
    f32 p = *position;
    f32 v = *velocity;
    f32 speed = v < 0.0f ? -v : v;
    bool below = p < low;
    bool above = p > high;
    p = below ? low : p;
    v = below ? speed : v;
    // Applied last, so a sphere wider than the box ends at high
    p = above ? high : p;
    v = above ? -speed : v;
    *position = p;
    *velocity = v;
    return below || above;
}

// Keeps sphere index inside bounds: a sphere past a side is moved back to touch it, and its
// velocity on that axis points inward (a sphere already moving inward keeps its speed). A sphere
// wider than the box ends at max - radius. Returns whether it was past a side; false and no
// change for an index >= spheres->count
bool core_collision_resolve_walls(REF const core_spheres_view* spheres, u32 index, data_bounds bounds);

#endif // CORE_COLLISION_H
