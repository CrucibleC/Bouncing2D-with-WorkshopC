#include <math.h>

#include "hammerc.h"

#include "core/spawn.h"
#include "core/spheres.h"
#include "util/random.h"

void test_spawn_lattice_max_radius(HammerCtx *t)
{
    /* 0.4 of the smaller cell side: 300 x 150 in 3 x 3 has 100 x 50 cells */
    CHECK(fabsf(core_spawn_lattice_max_radius(3, data_bounds_pod(0.0f, 0.0f, 300.0f, 150.0f)) - 20.0f) < 1e-4f);
    CHECK(core_spawn_lattice_max_radius(0, data_bounds_pod(0.0f, 0.0f, 300.0f, 150.0f)) == 0.0f);
    CHECK(core_spawn_lattice_max_radius(3, data_bounds_pod(0.0f, 0.0f, 0.0f, 150.0f)) == 0.0f);
    CHECK(core_spawn_lattice_min_radius_share() == 0.5f);
}

void test_spawn_lattice_radii_are_random_within_the_range(HammerCtx *t)
{
    util_random_seed(3);
    core_spheres spheres = core_spheres_make(400);
    REQUIRE(core_spheres_valid(&spheres));
    core_spheres_view view = core_spheres_get_view(&spheres);
    data_bounds box = data_bounds_pod(0.0f, 0.0f, 1280.0f, 720.0f);
    REQUIRE(core_spawn_lattice(&view, 20, box));
    f32 max_radius = core_spawn_lattice_max_radius(20, box);   /* 0.4 * 36 = 14.4 */
    f32 min_radius = core_spawn_lattice_min_radius_share() * max_radius;
    f32 smallest = view.radius[0];
    f32 largest = view.radius[0];
    int outside = 0;
    for (size_t i = 0; i < view.count; i++) {
        outside += view.radius[i] < min_radius - 1e-4f || view.radius[i] > max_radius + 1e-4f;
        smallest = view.radius[i] < smallest ? view.radius[i] : smallest;
        largest = view.radius[i] > largest ? view.radius[i] : largest;
    }
    CHECK_EQ_INT(outside, 0);
    /* 400 uniform draws spread over most of the range, so the radii really differ */
    CHECK(smallest < min_radius + 0.1f * (max_radius - min_radius));
    CHECK(largest > max_radius - 0.1f * (max_radius - min_radius));
    core_spheres_destroy(&spheres);
}

void test_spawn_lattice_places_an_even_grid(HammerCtx *t)
{
    util_random_seed(1);
    core_spheres spheres = core_spheres_make(9);
    REQUIRE(core_spheres_valid(&spheres));
    core_spheres_view view = core_spheres_get_view(&spheres);
    REQUIRE(core_spawn_lattice(&view, 3, data_bounds_pod(0.0f, 0.0f, 300.0f, 150.0f)));
    const f32 xs[3] = { 50.0f, 150.0f, 250.0f };
    const f32 ys[3] = { 25.0f, 75.0f, 125.0f };
    int wrong = 0;
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            size_t i = (size_t)(row * 3 + column);
            wrong += fabsf(view.x[i] - xs[column]) > 1e-3f || fabsf(view.y[i] - ys[row]) > 1e-3f;
            wrong += view.radius[i] < 10.0f - 1e-4f || view.radius[i] > 20.0f + 1e-4f;   /* 0.5 to 1 of 20 */
            wrong += view.rgba[i].a != 255;
            /* 0.5 to 2 cells per second; the cell is the smaller side, 50 */
            f32 speed = sqrtf(view.vx[i] * view.vx[i] + view.vy[i] * view.vy[i]);
            wrong += speed < 25.0f - 1e-3f || speed > 100.0f + 1e-3f;
        }
    }
    CHECK_EQ_INT(wrong, 0);
    core_spheres_destroy(&spheres);
}

void test_spawn_lattice_starts_without_overlaps_inside_bounds(HammerCtx *t)
{
    util_random_seed(2);
    core_spheres spheres = core_spheres_make(400);
    REQUIRE(core_spheres_valid(&spheres));
    core_spheres_view view = core_spheres_get_view(&spheres);
    data_bounds box = data_bounds_pod(0.0f, 0.0f, 1280.0f, 720.0f);
    REQUIRE(core_spawn_lattice(&view, 20, box));
    int problems = 0;
    for (size_t a = 0; a < view.count; a++) {
        problems += view.x[a] - view.radius[a] < box.min_x || view.x[a] + view.radius[a] > box.max_x;
        problems += view.y[a] - view.radius[a] < box.min_y || view.y[a] + view.radius[a] > box.max_y;
        for (size_t b = a + 1; b < view.count; b++) {
            f32 dx = view.x[b] - view.x[a];
            f32 dy = view.y[b] - view.y[a];
            f32 reach = view.radius[a] + view.radius[b];
            problems += dx * dx + dy * dy < reach * reach;
        }
    }
    CHECK_EQ_INT(problems, 0);
    core_spheres_destroy(&spheres);
}

void test_spawn_lattice_rejects_a_wrong_count(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(8);
    REQUIRE(core_spheres_valid(&spheres));
    core_spheres_view view = core_spheres_get_view(&spheres);
    CHECK(!core_spawn_lattice(&view, 3, data_bounds_pod(0.0f, 0.0f, 300.0f, 300.0f)));
    CHECK(!core_spawn_lattice(&view, 0, data_bounds_pod(0.0f, 0.0f, 300.0f, 300.0f)));
    /* nothing was written: the spheres are still zero */
    CHECK(view.x[0] == 0.0f && view.radius[7] == 0.0f && view.rgba[3].a == 0);
    core_spheres_destroy(&spheres);
}
