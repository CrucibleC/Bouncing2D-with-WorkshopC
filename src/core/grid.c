#include "core/grid.h"

#include <assert.h>
#include <math.h>
#include <string.h>

#include "core/collision.h"
#include "util/dynamic_array.h"
#include "workshopc_tags.h"

// Spheres a cell should hold on average, for core_grid_size_for
static const f64 SPHERES_PER_CELL = 4.0;
// The largest number of columns or rows core_grid_size_for picks
static const u32 MAX_SIDE_CELLS = 4096;
// Each sphere's cell range takes 4 u32 in sphere_cells
static const size_t CELL_RANGE_SIZE = 4;

static u32 core_grid_at_least_one(u32 value)
{
    return value == 0 ? 1 : value;
}

// The cell holding value along one axis, clamped into [0, cells - 1]; NaN goes to cell 0
static u32 core_grid_cell_of(f32 value, f32 min, f32 cells_per_unit, u32 cells)
{
    f32 position = (value - min) * cells_per_unit;
    u32 cell = position > 0.0f ? cast_f32_to_u32(position) : 0;
    return cell < cells ? cell : cells - 1;
}

// Makes block hold at least count elements, growing by doubling; never shrinks
static bool core_grid_reserve(borrows massive memory_block* block, size_t count)
{
    size_t capacity = memory_block_count(block);
    return count <= capacity || memory_block_resize(block, util_dynamic_array_resize(count, capacity));
}

core_grid core_grid_make(u32 columns, u32 rows)
{
    u32 safe_columns = core_grid_at_least_one(columns);
    u32 safe_rows = core_grid_at_least_one(rows);
    return (core_grid){
        .cell_starts = memory_block_make(cast_u32_to_size_t(safe_columns) * safe_rows + 1, sizeof(u32)),
        .entries = memory_block_make(util_dynamic_array_resize(1, 0), sizeof(u32)),
        .sphere_cells = memory_block_make(util_dynamic_array_resize(1, 0) * CELL_RANGE_SIZE, sizeof(u32)),
        .sort_scratch = memory_block_make(util_dynamic_array_resize(1, 0), sizeof(u32)),
        .columns = safe_columns,
        .rows = safe_rows,
    };
}

core_grid core_grid_copy(massive const core_grid* self)
{
    return (core_grid){
        .cell_starts = memory_block_copy(&self->cell_starts),
        .entries = memory_block_copy(&self->entries),
        .sphere_cells = memory_block_copy(&self->sphere_cells),
        .sort_scratch = memory_block_copy(&self->sort_scratch),
        .columns = self->columns,
        .rows = self->rows,
    };
}

core_grid core_grid_move(borrows massive core_grid* self)
{
    return (core_grid){
        .cell_starts = memory_block_move(&self->cell_starts),
        .entries = memory_block_move(&self->entries),
        .sphere_cells = memory_block_move(&self->sphere_cells),
        .sort_scratch = memory_block_move(&self->sort_scratch),
        .columns = self->columns,
        .rows = self->rows,
    };
}

void core_grid_destroy(borrows massive core_grid* self)
{
    memory_block_destroy(&self->sort_scratch);
    memory_block_destroy(&self->sphere_cells);
    memory_block_destroy(&self->entries);
    memory_block_destroy(&self->cell_starts);
}

bool core_grid_valid(massive const core_grid* self)
{
    return memory_block_valid(&self->cell_starts) && memory_block_valid(&self->entries)
        && memory_block_valid(&self->sphere_cells) && memory_block_valid(&self->sort_scratch);
}

status core_grid_status(massive const core_grid* self)
{
    status result = memory_block_status(&self->cell_starts);
    if (result == STATUS_OK)
    {
        result = memory_block_status(&self->entries);
    }
    if (result == STATUS_OK)
    {
        result = memory_block_status(&self->sphere_cells);
    }
    if (result == STATUS_OK)
    {
        result = memory_block_status(&self->sort_scratch);
    }
    return result;
}

status core_grid_resize(borrows massive core_grid* self, u32 columns, u32 rows)
{
    u32 safe_columns = core_grid_at_least_one(columns);
    u32 safe_rows = core_grid_at_least_one(rows);
    if (!memory_block_resize(&self->cell_starts, cast_u32_to_size_t(safe_columns) * safe_rows + 1))
    {
        return memory_block_status(&self->cell_starts);
    }
    self->columns = safe_columns;
    self->rows = safe_rows;
    return STATUS_OK;
}

u32 core_grid_columns(massive const core_grid* self)
{
    return self->columns;
}

u32 core_grid_rows(massive const core_grid* self)
{
    return self->rows;
}

void core_grid_size_for(size_t count, data_bounds bounds, f32 max_diameter, initializes massive u32* columns,
                        initializes massive u32* rows)
{
    *columns = 1;
    *rows = 1;
    f64 width = cast_f32_to_f64(bounds.max_x - bounds.min_x);
    f64 height = cast_f32_to_f64(bounds.max_y - bounds.min_y);
    if (!(width > 0.0) || !(height > 0.0))
    {
        return;
    }
    f64 cells = cast_size_t_to_f64(count) / SPHERES_PER_CELL;
    cells = cells < 1.0 ? 1.0 : cells;
    // Square cells covering the area, but never narrower than one sphere
    f64 cell_size = sqrt(width * height / cells);
    f64 diameter = cast_f32_to_f64(max_diameter);
    cell_size = cell_size < diameter ? diameter : cell_size;
    // Rounding down keeps every cell at least cell_size wide
    u32 fitting_columns = core_grid_at_least_one(cast_f64_to_u32(width / cell_size));
    u32 fitting_rows = core_grid_at_least_one(cast_f64_to_u32(height / cell_size));
    *columns = fitting_columns < MAX_SIDE_CELLS ? fitting_columns : MAX_SIDE_CELLS;
    *rows = fitting_rows < MAX_SIDE_CELLS ? fitting_rows : MAX_SIDE_CELLS;
}

// Counting sort: afterwards cell c's spheres are entries[starts[c] .. starts[c + 1]), and each
// sphere's cell range is in sphere_cells. Returns false when a buffer couldn't grow
static bool core_grid_bin(borrows massive core_grid* self, massive const core_spheres_view* spheres,
                          data_bounds bounds)
{
    size_t count = spheres->count;
    size_t columns = cast_u32_to_size_t(self->columns);
    size_t cells = columns * self->rows;
    if (!core_grid_reserve(&self->sphere_cells, count * CELL_RANGE_SIZE))
    {
        return false;
    }
    u32* starts = memory_block_data(&self->cell_starts);
    u32* ranges = memory_block_data(&self->sphere_cells);
    if (starts == NULL || ranges == NULL)
    {
        return false;
    }
    f32 width = bounds.max_x - bounds.min_x;
    f32 height = bounds.max_y - bounds.min_y;
    f32 columns_per_unit = width > 0.0f ? cast_u32_to_f32(self->columns) / width : 0.0f;
    f32 rows_per_unit = height > 0.0f ? cast_u32_to_f32(self->rows) / height : 0.0f;

    // Pass 1: each sphere's cell range, and how many spheres touch each cell (counted at c + 1)
    (void)memset(starts, 0, (cells + 1) * sizeof(u32));
    for (size_t i = 0; i < count; i++)
    {
        f32 radius = spheres->radius[i];
        u32 first_column = core_grid_cell_of(spheres->x[i] - radius, bounds.min_x, columns_per_unit, self->columns);
        u32 first_row = core_grid_cell_of(spheres->y[i] - radius, bounds.min_y, rows_per_unit, self->rows);
        u32 last_column = core_grid_cell_of(spheres->x[i] + radius, bounds.min_x, columns_per_unit, self->columns);
        u32 last_row = core_grid_cell_of(spheres->y[i] + radius, bounds.min_y, rows_per_unit, self->rows);
        ranges[i * CELL_RANGE_SIZE] = first_column;
        ranges[i * CELL_RANGE_SIZE + 1] = first_row;
        ranges[i * CELL_RANGE_SIZE + 2] = last_column;
        ranges[i * CELL_RANGE_SIZE + 3] = last_row;
        for (u32 row = first_row; row <= last_row; row++)
        {
            for (u32 column = first_column; column <= last_column; column++)
            {
                starts[row * columns + column + 1] += 1;
            }
        }
    }
    // Prefix sums: starts[c] is where cell c begins, starts[cells] the total
    for (size_t c = 1; c <= cells; c++)
    {
        starts[c] += starts[c - 1];
    }
    if (!core_grid_reserve(&self->entries, starts[cells]))
    {
        return false;
    }
    u32* entries = memory_block_data(&self->entries);
    if (entries == NULL)
    {
        return false;
    }

    // Pass 2: write each sphere into its cells, using starts[c] as cell c's write cursor...
    for (size_t i = 0; i < count; i++)
    {
        for (u32 row = ranges[i * CELL_RANGE_SIZE + 1]; row <= ranges[i * CELL_RANGE_SIZE + 3]; row++)
        {
            for (u32 column = ranges[i * CELL_RANGE_SIZE]; column <= ranges[i * CELL_RANGE_SIZE + 2]; column++)
            {
                size_t cell = row * columns + column;
                entries[starts[cell]] = cast_size_t_to_u32(i);
                starts[cell] += 1;
            }
        }
    }
    // ...which leaves starts[c] at cell c's end, i.e. cell c + 1's start: shift back by one
    for (size_t c = cells; c > 0; c--)
    {
        starts[c] = starts[c - 1];
    }
    starts[0] = 0;
    return true;
}

size_t core_grid_resolve_pairs(borrows massive core_grid* self, massive const core_spheres_view* spheres,
                               data_bounds bounds)
{
    assert(core_spheres_view_is_current(spheres));   // a view taken before a resize is stale
    if (spheres->count == 0 || !core_grid_bin(self, spheres, bounds))
    {
        return 0;
    }
    const u32* starts = memory_block_const_data(&self->cell_starts);
    const u32* entries = memory_block_const_data(&self->entries);
    const u32* ranges = memory_block_const_data(&self->sphere_cells);
    if (starts == NULL || entries == NULL || ranges == NULL)
    {
        return 0;
    }
    size_t touched = 0;
    size_t columns = cast_u32_to_size_t(self->columns);
    for (u32 row = 0; row < self->rows; row++)
    {
        for (u32 column = 0; column < self->columns; column++)
        {
            size_t cell = row * columns + column;
            for (u32 first = starts[cell]; first < starts[cell + 1]; first++)
            {
                for (u32 second = first + 1; second < starts[cell + 1]; second++)
                {
                    u32 a = entries[first];
                    u32 b = entries[second];
                    // Only in the first cell both share, so a pair in several cells is resolved once
                    u32 shared_column = ranges[a * CELL_RANGE_SIZE] > ranges[b * CELL_RANGE_SIZE]
                                            ? ranges[a * CELL_RANGE_SIZE]
                                            : ranges[b * CELL_RANGE_SIZE];
                    u32 shared_row = ranges[a * CELL_RANGE_SIZE + 1] > ranges[b * CELL_RANGE_SIZE + 1]
                                         ? ranges[a * CELL_RANGE_SIZE + 1]
                                         : ranges[b * CELL_RANGE_SIZE + 1];
                    bool first_shared_cell = shared_column == column && shared_row == row;
                    if (first_shared_cell && core_collision_resolve_pair(spheres, a, b))
                    {
                        touched += 1;
                    }
                }
            }
        }
    }
    return touched;
}

// values[i] = old values[order[i]], through scratch
static void core_grid_permute_f32(borrows f32* values, borrows f32* scratch, const u32* order, size_t count)
{
    if (values == NULL || scratch == NULL || order == NULL)
    {
        return;
    }
    for (size_t i = 0; i < count; i++)
    {
        scratch[i] = values[order[i]];
    }
    (void)memcpy(values, scratch, count * sizeof(f32));
}

// The same for colors; the scratch bytes simply take data_rgba values this time
static void core_grid_permute_rgba(borrows data_rgba* values, borrows data_rgba* scratch, const u32* order,
                                   size_t count)
{
    if (values == NULL || scratch == NULL || order == NULL)
    {
        return;
    }
    for (size_t i = 0; i < count; i++)
    {
        (void)memcpy(&scratch[i], &values[order[i]], sizeof(data_rgba));
    }
    (void)memcpy(values, scratch, count * sizeof(data_rgba));
}

bool core_grid_sort_spheres(borrows massive core_grid* self, massive const core_spheres_view* spheres,
                            data_bounds bounds)
{
    assert(core_spheres_view_is_current(spheres));   // a view taken before a resize is stale
    size_t count = spheres->count;
    if (count < 2)
    {
        return true;
    }
    size_t cells = cast_u32_to_size_t(self->columns) * self->rows;
    bool reserved = core_grid_reserve(&self->entries, count) && core_grid_reserve(&self->sphere_cells, count)
                 && core_grid_reserve(&self->sort_scratch, count);
    u32* starts = memory_block_data(&self->cell_starts);
    u32* order = memory_block_data(&self->entries);
    u32* keys = memory_block_data(&self->sphere_cells);
    void* scratch = memory_block_data(&self->sort_scratch);
    if (!reserved || starts == NULL || order == NULL || keys == NULL || scratch == NULL)
    {
        return false;
    }
    f32 width = bounds.max_x - bounds.min_x;
    f32 height = bounds.max_y - bounds.min_y;
    f32 columns_per_unit = width > 0.0f ? cast_u32_to_f32(self->columns) / width : 0.0f;
    f32 rows_per_unit = height > 0.0f ? cast_u32_to_f32(self->rows) / height : 0.0f;

    // Counting sort by the cell of each center: count (at key + 1), prefix sums, then place
    (void)memset(starts, 0, (cells + 1) * sizeof(u32));
    for (size_t i = 0; i < count; i++)
    {
        u32 column = core_grid_cell_of(spheres->x[i], bounds.min_x, columns_per_unit, self->columns);
        u32 row = core_grid_cell_of(spheres->y[i], bounds.min_y, rows_per_unit, self->rows);
        keys[i] = row * self->columns + column;
        starts[keys[i] + 1] += 1;
    }
    for (size_t c = 1; c <= cells; c++)
    {
        starts[c] += starts[c - 1];
    }
    // order[new position] = old position; stable, so spheres in one cell keep their order
    for (size_t i = 0; i < count; i++)
    {
        order[starts[keys[i]]] = cast_size_t_to_u32(i);
        starts[keys[i]] += 1;
    }

    core_grid_permute_f32(spheres->x, scratch, order, count);
    core_grid_permute_f32(spheres->y, scratch, order, count);
    core_grid_permute_f32(spheres->vx, scratch, order, count);
    core_grid_permute_f32(spheres->vy, scratch, order, count);
    core_grid_permute_f32(spheres->radius, scratch, order, count);
    core_grid_permute_rgba(spheres->rgba, scratch, order, count);
    return true;
}
