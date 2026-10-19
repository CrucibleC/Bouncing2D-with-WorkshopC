#include "hammerc.h"

#include "core/physics.h"
#include "core/spheres.h"

static void place(core_spheres_view *view, u32 i, f32 x, f32 y, f32 vx, f32 vy, f32 radius)
{
    view->x[i] = x;
    view->y[i] = y;
    view->vx[i] = vx;
    view->vy[i] = vy;
    view->radius[i] = radius;
}

void test_physics_move_applies_velocity_times_dt(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(3);
    REQUIRE(core_spheres_valid(&spheres));
    core_spheres_view view = core_spheres_get_view(&spheres);
    place(&view, 0, 1.0f, 2.0f, 2.0f, -4.0f, 1.0f);
    place(&view, 1, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
    place(&view, 2, -3.0f, 5.0f, 10.0f, 1.0f, 1.0f);
    core_physics_move(&view, 0.5f);
    CHECK(view.x[0] == 2.0f && view.y[0] == 0.0f);
    CHECK(view.x[1] == 0.0f && view.y[1] == 0.0f);
    CHECK(view.x[2] == 2.0f && view.y[2] == 5.5f);
    /* velocities and radii are untouched */
    CHECK(view.vx[0] == 2.0f && view.vy[0] == -4.0f && view.radius[2] == 1.0f);
    core_spheres_destroy(&spheres);
}

void test_physics_move_with_no_spheres_does_nothing(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(0);
    REQUIRE(core_spheres_valid(&spheres));
    core_spheres_view view = core_spheres_get_view(&spheres);
    core_physics_move(&view, 1.0f);
    CHECK_EQ_UINT(core_physics_resolve_walls(&view, data_bounds_pod(0.0f, 0.0f, 10.0f, 10.0f)), 0);
    core_spheres_destroy(&spheres);
}

void test_physics_resolve_walls_handles_every_sphere(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(4);
    REQUIRE(core_spheres_valid(&spheres));
    core_spheres_view view = core_spheres_get_view(&spheres);
    place(&view, 0, 1.0f, 25.0f, -3.0f, 0.0f, 2.0f);     /* past the left */
    place(&view, 1, 50.0f, 25.0f, 1.0f, 1.0f, 2.0f);     /* inside */
    place(&view, 2, 50.0f, 49.5f, 0.0f, 4.0f, 2.0f);     /* past the bottom */
    place(&view, 3, 99.0f, 0.5f, 2.0f, -2.0f, 2.0f);     /* a corner */
    CHECK_EQ_UINT(core_physics_resolve_walls(&view, data_bounds_pod(0.0f, 0.0f, 100.0f, 50.0f)), 3);
    CHECK(view.x[0] == 2.0f && view.vx[0] == 3.0f);
    CHECK(view.x[1] == 50.0f && view.vx[1] == 1.0f && view.vy[1] == 1.0f);
    CHECK(view.y[2] == 48.0f && view.vy[2] == -4.0f);
    CHECK(view.x[3] == 98.0f && view.vx[3] == -2.0f && view.y[3] == 2.0f && view.vy[3] == 2.0f);
    core_spheres_destroy(&spheres);
}
