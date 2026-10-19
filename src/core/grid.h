#ifndef CORE_GRID_H
#define CORE_GRID_H

#include <stdbool.h>
#include <stddef.h>

#include "core/spheres.h"
#include "data/bounds.h"
#include "memory_block.h"
#include "numbers.h"
#include "raii_delete.h"
#include "status.h"
#include "workshopc_tags.h"

// Grid space partitioning for sphere-sphere collisions. Each step bins the spheres with a counting
// sort (O(spheres + cells)): every cell's spheres become one contiguous slice of u32 indices, a
// sphere in every cell its bounding box touches. Then each overlapping pair is resolved exactly
// once, in the first cell the two share. The buffers are kept between steps and only grow, so
// once they fit, a step allocates nothing. Resize the grid when the sphere count changes
// (core_grid_size_for picks the columns and rows).
typedef struct core_grid
{
    PRIVATE memory_block cell_starts;    // u32, cells + 1: cell c holds entries [starts[c], starts[c + 1])
    PRIVATE memory_block entries;        // u32 sphere indices grouped by cell; grows only
    PRIVATE memory_block sphere_cells;   // u32, 4 per sphere: first column, first row, last column, last row
    PRIVATE memory_block sort_scratch;   // 4 bytes per sphere: one array's values while core_grid_sort_spheres reorders
    PRIVATE u32 columns;
    PRIVATE u32 rows;
} core_grid;

// A grid of columns x rows cells (each at least 1); invalid when an allocation fails
core_grid core_grid_make(u32 columns, u32 rows);
core_grid core_grid_copy(REF const core_grid* self);
core_grid core_grid_move(MUTABLE REF core_grid* self);
void core_grid_destroy(MUTABLE REF core_grid* self);
NO_RETURN(core_grid);
bool core_grid_valid(REF const core_grid* self);
// STATUS_OK, or the first failure among its buffers (e.g. a failed growth in resolve_pairs)
status core_grid_status(REF const core_grid* self);

// Changes the number of cells (each at least 1). On failure the grid is unchanged
status core_grid_resize(MUTABLE REF core_grid* self, u32 columns, u32 rows);
u32 core_grid_columns(REF const core_grid* self);
u32 core_grid_rows(REF const core_grid* self);

// Columns and rows for count spheres in bounds: about 4 spheres per cell, roughly square cells,
// and cells at least max_diameter wide, so each sphere touches at most 4 cells. At least 1 x 1
void core_grid_size_for(size_t count, data_bounds bounds, f32 max_diameter, OUTPUT REF u32* columns,
                        OUTPUT REF u32* rows);

// Bins the spheres into the grid over bounds (spheres outside it go to the edge cells), then
// resolves every overlapping pair exactly once with core_collision_resolve_pair. Returns how many
// pairs touched; 0 when a buffer couldn't grow (core_grid_status tells why)
size_t core_grid_resolve_pairs(MUTABLE REF core_grid* self, REF const core_spheres_view* spheres,
                               data_bounds bounds);

// Reorders the spheres (all six arrays together) by the grid cell holding each center, row by
// row, so spheres near each other on screen sit near each other in memory: fewer cache misses in
// physics and drawing. Positions and velocities are unchanged, only their order. A counting sort,
// O(spheres + cells); run it now and then, e.g. every 30 frames. False when a buffer couldn't grow
// (the spheres are then unchanged)
bool core_grid_sort_spheres(MUTABLE REF core_grid* self, REF const core_spheres_view* spheres,
                            data_bounds bounds);

#endif // CORE_GRID_H
