#ifndef CORE_SPAWN_H
#define CORE_SPAWN_H

#include <stdbool.h>

#include "core/spheres.h"
#include "data/bounds.h"
#include "numbers.h"
#include "workshopc_tags.h"

// Starting positions and values for the spheres (random parts from util_random)

// The largest radius a sphere of an n x n lattice in bounds gets: 0.4 of the smaller cell side, so
// neighbors start apart. The grid is sized from it. 0 for n == 0 or empty bounds
f32 core_spawn_lattice_max_radius(u32 n, data_bounds bounds);
// The smallest radius, as a share of core_spawn_lattice_max_radius (0.5)
f32 core_spawn_lattice_min_radius_share(void);

// Places n * n spheres on an even n x n lattice over bounds, row by row, each centered in its
// cell. Each gets a random radius from min share to 1 times core_spawn_lattice_max_radius, a random
// direction with a speed of 0.5 to 2 cells per second (so motion slows as n grows) and a random
// color with alpha 255. Returns false, and writes nothing, unless spheres->count == n * n and n > 0
bool core_spawn_lattice(REF const core_spheres_view* spheres, u32 n, data_bounds bounds);

#endif // CORE_SPAWN_H
