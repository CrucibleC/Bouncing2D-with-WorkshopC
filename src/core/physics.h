#ifndef CORE_PHYSICS_H
#define CORE_PHYSICS_H

#include <stddef.h>

#include "core/spheres.h"
#include "data/bounds.h"
#include "numbers.h"
#include "workshopc_tags.h"

// Whole-array physics steps over every sphere: plain loops over the SoA arrays that the compiler
// can vectorize. Pure: no window, no globals. A frame runs core_physics_move, then
// core_grid_resolve_pairs, then core_physics_resolve_walls (walls last, so nothing ends up
// outside the box when drawn). Use a fixed dt, e.g. 1/120 s, for a stable simulation.

// x += vx * dt and y += vy * dt for every sphere; dt in seconds, velocities in units per second
void core_physics_move(massive const core_spheres_view* spheres, f32 dt);

// core_collision_resolve_walls for every sphere, in one loop. Returns how many were past a side
size_t core_physics_resolve_walls(massive const core_spheres_view* spheres, data_bounds bounds);

#endif // CORE_PHYSICS_H
