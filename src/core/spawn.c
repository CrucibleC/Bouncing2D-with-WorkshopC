#include "core/spawn.h"

#include <assert.h>
#include <math.h>

#include "util/random.h"
#include "workshopc_tags.h"

// The largest radius as a share of a lattice cell's smaller side
static const f32 RADIUS_SHARE = 0.4f;
// The smallest radius as a share of the largest: big and small (heavy and light) spheres mix
static const f32 MIN_RADIUS_SHARE = 0.5f;
// Speeds in lattice cells per second
static const f32 SPEED_MIN_CELLS = 0.5f;
static const f32 SPEED_MAX_CELLS = 2.0f;
static const f32 TWO_PI = 6.28318530718f;

f32 core_spawn_lattice_min_radius_share(void)
{
    return MIN_RADIUS_SHARE;
}

f32 core_spawn_lattice_max_radius(u32 n, data_bounds bounds)
{
    f32 width = bounds.max_x - bounds.min_x;
    f32 height = bounds.max_y - bounds.min_y;
    if (n == 0 || !(width > 0.0f) || !(height > 0.0f))
    {
        return 0.0f;
    }
    f32 side = width < height ? width : height;
    return RADIUS_SHARE * side / cast_u32_to_f32(n);
}

bool core_spawn_lattice(massive const core_spheres_view* spheres, u32 n, data_bounds bounds)
{
    assert(core_spheres_view_is_current(spheres));   // a view taken before a resize is stale
    u64 count = cast_u32_to_u64(n) * cast_u32_to_u64(n);
    if (n == 0 || cast_size_t_to_u64(spheres->count) != count)
    {
        return false;
    }
    f32* restrict x = spheres->x;
    f32* restrict y = spheres->y;
    f32* restrict vx = spheres->vx;
    f32* restrict vy = spheres->vy;
    f32* restrict radius = spheres->radius;
    data_rgba* restrict rgba = spheres->rgba;

    f32 cell_width = (bounds.max_x - bounds.min_x) / cast_u32_to_f32(n);
    f32 cell_height = (bounds.max_y - bounds.min_y) / cast_u32_to_f32(n);
    f32 cell = cell_width < cell_height ? cell_width : cell_height;
    f32 max_radius = core_spawn_lattice_max_radius(n, bounds);
    f32 min_radius = MIN_RADIUS_SHARE * max_radius;

    size_t i = 0;
    for (u32 row = 0; row < n; row++)
    {
        for (u32 column = 0; column < n; column++)
        {
            x[i] = bounds.min_x + (cast_u32_to_f32(column) + 0.5f) * cell_width;
            y[i] = bounds.min_y + (cast_u32_to_f32(row) + 0.5f) * cell_height;
            radius[i] = util_random_float(min_radius, max_radius);
            f32 angle = util_random_float(0.0f, TWO_PI);
            f32 speed = util_random_float(SPEED_MIN_CELLS, SPEED_MAX_CELLS) * cell;
            vx[i] = cosf(angle) * speed;
            vy[i] = sinf(angle) * speed;
            rgba[i] = data_rgba_pod(cast_i32_to_u8(util_random_int(0, 255)), cast_i32_to_u8(util_random_int(0, 255)),
                                    cast_i32_to_u8(util_random_int(0, 255)), 255);
            i++;
        }
    }
    return true;
}
