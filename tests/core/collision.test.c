#include <math.h>

#include "hammerc.h"

#include "core/collision.h"
#include "core/spheres.h"

/* Each test makes a few zeroed spheres and places them through the view. */

static void place(core_spheres_view *view, u32 i, f32 x, f32 y, f32 vx, f32 vy, f32 radius)
{
    view->x[i] = x;
    view->y[i] = y;
    view->vx[i] = vx;
    view->vy[i] = vy;
    view->radius[i] = radius;
}

static int near(f32 a, f32 b)
{
    return fabsf(a - b) <= 1e-4f * (1.0f + fabsf(a) + fabsf(b));
}

/* ---- walls: a 100 x 50 box ---- */

void test_collision_walls_clamp_each_side_and_turn_inward(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(4);
    REQUIRE(core_spheres_valid(&spheres));
    core_spheres_view view = core_spheres_get_view(&spheres);
    data_bounds box = data_bounds_pod(0.0f, 0.0f, 100.0f, 50.0f);
    place(&view, 0, 1.0f, 25.0f, -3.0f, 0.0f, 2.0f);    /* past the left */
    place(&view, 1, 99.0f, 25.0f, 3.0f, 0.0f, 2.0f);    /* past the right */
    place(&view, 2, 50.0f, 1.0f, 0.0f, -4.0f, 2.0f);    /* past the top (min y) */
    place(&view, 3, 50.0f, 49.5f, 0.0f, 4.0f, 2.0f);    /* past the bottom (max y) */
    for (u32 i = 0; i < 4; i++) {
        CHECK(core_collision_resolve_walls(&view, i, box));
    }
    CHECK(view.x[0] == 2.0f && view.vx[0] == 3.0f);
    CHECK(view.x[1] == 98.0f && view.vx[1] == -3.0f);
    CHECK(view.y[2] == 2.0f && view.vy[2] == 4.0f);
    CHECK(view.y[3] == 48.0f && view.vy[3] == -4.0f);
    /* the other axis is untouched */
    CHECK(view.y[0] == 25.0f && view.vy[0] == 0.0f);
    CHECK(view.x[2] == 50.0f && view.vx[2] == 0.0f);
    core_spheres_destroy(&spheres);
}

void test_collision_walls_leave_a_sphere_inside_alone(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(1);
    REQUIRE(core_spheres_valid(&spheres));
    core_spheres_view view = core_spheres_get_view(&spheres);
    place(&view, 0, 50.0f, 25.0f, -7.0f, 5.0f, 2.0f);
    CHECK(!core_collision_resolve_walls(&view, 0, data_bounds_pod(0.0f, 0.0f, 100.0f, 50.0f)));
    CHECK(view.x[0] == 50.0f && view.y[0] == 25.0f && view.vx[0] == -7.0f && view.vy[0] == 5.0f);
    /* exactly touching is not past the wall */
    place(&view, 0, 2.0f, 25.0f, -7.0f, 0.0f, 2.0f);
    CHECK(!core_collision_resolve_walls(&view, 0, data_bounds_pod(0.0f, 0.0f, 100.0f, 50.0f)));
    CHECK(view.vx[0] == -7.0f);
    core_spheres_destroy(&spheres);
}

void test_collision_walls_keep_inward_speed(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(1);
    REQUIRE(core_spheres_valid(&spheres));
    core_spheres_view view = core_spheres_get_view(&spheres);
    place(&view, 0, 1.0f, 25.0f, 6.0f, 0.0f, 2.0f);     /* past the left, already moving right */
    CHECK(core_collision_resolve_walls(&view, 0, data_bounds_pod(0.0f, 0.0f, 100.0f, 50.0f)));
    CHECK(view.x[0] == 2.0f && view.vx[0] == 6.0f);
    core_spheres_destroy(&spheres);
}

void test_collision_walls_fix_a_corner(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(1);
    REQUIRE(core_spheres_valid(&spheres));
    core_spheres_view view = core_spheres_get_view(&spheres);
    place(&view, 0, 99.0f, 0.5f, 2.0f, -2.0f, 2.0f);
    CHECK(core_collision_resolve_walls(&view, 0, data_bounds_pod(0.0f, 0.0f, 100.0f, 50.0f)));
    CHECK(view.x[0] == 98.0f && view.vx[0] == -2.0f);
    CHECK(view.y[0] == 2.0f && view.vy[0] == 2.0f);
    core_spheres_destroy(&spheres);
}

void test_collision_walls_sphere_wider_than_box_ends_at_max(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(1);
    REQUIRE(core_spheres_valid(&spheres));
    core_spheres_view view = core_spheres_get_view(&spheres);
    place(&view, 0, 5.0f, 5.0f, 1.0f, 0.0f, 8.0f);      /* 16 wide in a 10 x 10 box */
    CHECK(core_collision_resolve_walls(&view, 0, data_bounds_pod(0.0f, 0.0f, 10.0f, 10.0f)));
    CHECK(view.x[0] == 2.0f && view.vx[0] == -1.0f);
    CHECK(!isnan(view.x[0]) && !isnan(view.y[0]));
    core_spheres_destroy(&spheres);
}

void test_collision_walls_out_of_range_index(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(2);
    REQUIRE(core_spheres_valid(&spheres));
    core_spheres_view view = core_spheres_get_view(&spheres);
    CHECK(!core_collision_resolve_walls(&view, 2, data_bounds_pod(0.0f, 0.0f, 10.0f, 10.0f)));
    core_spheres_destroy(&spheres);
}

/* ---- pairs ---- */

void test_collision_pair_equal_head_on_swaps_velocities(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(2);
    REQUIRE(core_spheres_valid(&spheres));
    core_spheres_view view = core_spheres_get_view(&spheres);
    place(&view, 0, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f);
    place(&view, 1, 1.5f, 0.0f, -2.0f, 0.0f, 1.0f);
    CHECK(core_collision_resolve_pair(&view, 0, 1));
    CHECK(near(view.vx[0], -2.0f) && near(view.vx[1], 1.0f));
    CHECK(near(view.vy[0], 0.0f) && near(view.vy[1], 0.0f));
    /* separated to just touching, symmetric for equal masses */
    CHECK(near(view.x[1] - view.x[0], 2.0f));
    CHECK(near(view.x[0], -0.25f) && near(view.x[1], 1.75f));
    core_spheres_destroy(&spheres);
}

void test_collision_pair_unequal_keeps_momentum_and_energy(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(2);
    REQUIRE(core_spheres_valid(&spheres));
    core_spheres_view view = core_spheres_get_view(&spheres);
    place(&view, 0, 0.0f, 0.0f, 3.0f, 1.0f, 1.0f);
    place(&view, 1, 2.2f, 1.0f, -1.0f, -0.5f, 2.0f);
    /* mass is area: pi cancels in every check, so r * r is used */
    f32 ma = 1.0f, mb = 4.0f;
    f32 px = ma * view.vx[0] + mb * view.vx[1];
    f32 py = ma * view.vy[0] + mb * view.vy[1];
    f32 energy = ma * (view.vx[0] * view.vx[0] + view.vy[0] * view.vy[0])
               + mb * (view.vx[1] * view.vx[1] + view.vy[1] * view.vy[1]);
    CHECK(core_collision_resolve_pair(&view, 0, 1));
    CHECK(near(ma * view.vx[0] + mb * view.vx[1], px));
    CHECK(near(ma * view.vy[0] + mb * view.vy[1], py));
    CHECK(near(ma * (view.vx[0] * view.vx[0] + view.vy[0] * view.vy[0])
               + mb * (view.vx[1] * view.vx[1] + view.vy[1] * view.vy[1]), energy));
    f32 dx = view.x[1] - view.x[0];
    f32 dy = view.y[1] - view.y[0];
    CHECK(near(sqrtf(dx * dx + dy * dy), 3.0f));
    core_spheres_destroy(&spheres);
}

void test_collision_pair_lighter_sphere_moves_more(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(2);
    REQUIRE(core_spheres_valid(&spheres));
    core_spheres_view view = core_spheres_get_view(&spheres);
    place(&view, 0, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);      /* mass 1 */
    place(&view, 1, 2.5f, 0.0f, 0.0f, 0.0f, 2.0f);      /* mass 4, overlap 0.5 */
    CHECK(core_collision_resolve_pair(&view, 0, 1));
    CHECK(near(view.x[0], -0.4f));                     /* moves 4/5 of the overlap */
    CHECK(near(view.x[1], 2.6f));                      /* moves 1/5 */
    core_spheres_destroy(&spheres);
}

void test_collision_pair_separating_spheres_keep_velocities(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(2);
    REQUIRE(core_spheres_valid(&spheres));
    core_spheres_view view = core_spheres_get_view(&spheres);
    place(&view, 0, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f);
    place(&view, 1, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f);
    CHECK(core_collision_resolve_pair(&view, 0, 1));
    CHECK(view.vx[0] == -1.0f && view.vx[1] == 1.0f);
    CHECK(near(view.x[1] - view.x[0], 2.0f));
    core_spheres_destroy(&spheres);
}

void test_collision_pair_apart_or_touching_is_unchanged(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(2);
    REQUIRE(core_spheres_valid(&spheres));
    core_spheres_view view = core_spheres_get_view(&spheres);
    place(&view, 0, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f);
    place(&view, 1, 5.0f, 0.0f, -1.0f, 0.0f, 1.0f);
    CHECK(!core_collision_resolve_pair(&view, 0, 1));
    place(&view, 1, 2.0f, 0.0f, -1.0f, 0.0f, 1.0f);    /* exactly touching */
    CHECK(!core_collision_resolve_pair(&view, 0, 1));
    CHECK(view.x[0] == 0.0f && view.x[1] == 2.0f && view.vx[0] == 1.0f && view.vx[1] == -1.0f);
    core_spheres_destroy(&spheres);
}

void test_collision_pair_coincident_centers_give_no_nan(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(2);
    REQUIRE(core_spheres_valid(&spheres));
    core_spheres_view view = core_spheres_get_view(&spheres);
    place(&view, 0, 3.0f, 3.0f, 1.0f, 0.0f, 1.0f);
    place(&view, 1, 3.0f, 3.0f, -1.0f, 0.0f, 1.0f);
    CHECK(core_collision_resolve_pair(&view, 0, 1));
    int nans = 0;
    for (u32 i = 0; i < 2; i++) {
        nans += isnan(view.x[i]) || isnan(view.y[i]) || isnan(view.vx[i]) || isnan(view.vy[i]);
    }
    CHECK_EQ_INT(nans, 0);
    CHECK(near(view.x[1] - view.x[0], 2.0f));
    core_spheres_destroy(&spheres);
}

void test_collision_pair_zero_radius_gives_no_nan(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(2);   /* zeroed: both radius 0, same place */
    REQUIRE(core_spheres_valid(&spheres));
    core_spheres_view view = core_spheres_get_view(&spheres);
    CHECK(!core_collision_resolve_pair(&view, 0, 1));
    CHECK(!isnan(view.x[0]) && !isnan(view.vx[0]));
    core_spheres_destroy(&spheres);
}

void test_collision_pair_rejects_same_or_out_of_range_indices(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(2);
    REQUIRE(core_spheres_valid(&spheres));
    core_spheres_view view = core_spheres_get_view(&spheres);
    place(&view, 0, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
    place(&view, 1, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f);
    CHECK(!core_collision_resolve_pair(&view, 0, 0));
    CHECK(!core_collision_resolve_pair(&view, 0, 2));
    CHECK(!core_collision_resolve_pair(&view, 7, 1));
    CHECK(view.x[0] == 0.0f && view.x[1] == 0.5f);
    core_spheres_destroy(&spheres);
}
