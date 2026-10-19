#include <stdint.h>

#include "hammerc.h"

#include "core/spheres.h"

/* core_spheres is storage only: values come from outside, through the view. */

static int count_nonzero(const core_spheres *spheres)
{
    core_spheres_const_view view = core_spheres_get_const_view(spheres);
    int nonzero = 0;
    for (size_t i = 0; i < view.count; i++) {
        nonzero += view.x[i] != 0.0f || view.y[i] != 0.0f || view.vx[i] != 0.0f || view.vy[i] != 0.0f;
        nonzero += view.radius[i] != 0.0f;
        nonzero += view.rgba[i].r != 0 || view.rgba[i].g != 0 || view.rgba[i].b != 0 || view.rgba[i].a != 0;
    }
    return nonzero;
}

/* Gives every array of every sphere a nonzero value, different per array and per sphere */
static void fill(core_spheres *spheres)
{
    core_spheres_view view = core_spheres_get_view(spheres);
    for (size_t i = 0; i < view.count; i++) {
        view.x[i] = 1.0f + (f32)i;
        view.y[i] = 1000.0f + (f32)i;
        view.vx[i] = 2000.0f + (f32)i;
        view.vy[i] = 3000.0f + (f32)i;
        view.radius[i] = 4000.0f + (f32)i;
        view.rgba[i] = data_rgba_pod((u8)(i + 1), 2, 3, 255);
    }
}

void test_spheres_make_is_zeroed(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(100);
    REQUIRE(core_spheres_valid(&spheres));
    CHECK_EQ_INT(core_spheres_status(&spheres), STATUS_OK);
    CHECK_EQ_UINT(core_spheres_count(&spheres), 100);
    CHECK_EQ_INT(count_nonzero(&spheres), 0);
    core_spheres_destroy(&spheres);
}

void test_spheres_view_arrays_are_aligned_and_a_stride_apart(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(100);   /* stride 112 */
    REQUIRE(core_spheres_valid(&spheres));
    core_spheres_view view = core_spheres_get_view(&spheres);
    CHECK_EQ_UINT(view.count, 100);
    CHECK_EQ_UINT((uintptr_t)view.x % 16, 0);
    CHECK(view.y == view.x + 112);
    CHECK(view.vx == view.y + 112);
    CHECK(view.vy == view.vx + 112);
    CHECK(view.radius == view.vy + 112);
    CHECK((const char *)view.rgba == (const char *)(view.radius + 112));
    /* the stride is a multiple of 16 elements, so arrays start a multiple of 64 bytes apart */
    CHECK_EQ_UINT(((uintptr_t)view.y - (uintptr_t)view.x) % 64, 0);
    core_spheres_destroy(&spheres);
}

void test_spheres_arrays_are_independent(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(20);
    REQUIRE(core_spheres_valid(&spheres));
    core_spheres_view view = core_spheres_get_view(&spheres);
    for (size_t i = 0; i < view.count; i++) {
        view.x[i] = -1.0f;
    }
    view.rgba[19] = data_rgba_pod(1, 2, 3, 4);
    int changed = 0;
    for (size_t i = 0; i < view.count; i++) {
        changed += view.y[i] != 0.0f || view.vx[i] != 0.0f || view.vy[i] != 0.0f || view.radius[i] != 0.0f;
    }
    CHECK_EQ_INT(changed, 0);
    core_spheres_destroy(&spheres);
}

void test_spheres_get_returns_what_the_view_wrote(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(10);
    REQUIRE(core_spheres_valid(&spheres));
    fill(&spheres);
    data_sphere sphere;
    REQUIRE(core_spheres_get(&spheres, 7, &sphere));
    CHECK(sphere.x == 8.0f && sphere.y == 1007.0f);
    CHECK(sphere.vx == 2007.0f && sphere.vy == 3007.0f);
    CHECK(sphere.radius == 4007.0f);
    CHECK(sphere.rgba.r == 8 && sphere.rgba.g == 2 && sphere.rgba.b == 3 && sphere.rgba.a == 255);
    CHECK(!core_spheres_get(&spheres, 10, &sphere));
    CHECK(sphere.radius == 0.0f);
    core_spheres_destroy(&spheres);
}

void test_spheres_resize_zeroes_everything(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(10);
    REQUIRE(core_spheres_valid(&spheres));

    fill(&spheres);
    CHECK_EQ_INT(core_spheres_resize(&spheres, 100), STATUS_OK);   /* stride 16 -> 112 */
    CHECK_EQ_UINT(core_spheres_count(&spheres), 100);
    CHECK_EQ_INT(count_nonzero(&spheres), 0);

    fill(&spheres);
    CHECK_EQ_INT(core_spheres_resize(&spheres, 20), STATUS_OK);    /* stride 112 -> 32 */
    CHECK_EQ_UINT(core_spheres_count(&spheres), 20);
    CHECK_EQ_INT(count_nonzero(&spheres), 0);

    fill(&spheres);
    CHECK_EQ_INT(core_spheres_resize(&spheres, 18), STATUS_OK);    /* same stride 32 */
    CHECK_EQ_UINT(core_spheres_count(&spheres), 18);
    CHECK_EQ_INT(count_nonzero(&spheres), 0);
    core_spheres_destroy(&spheres);
}

void test_spheres_too_big_resize_changes_nothing(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(5);
    REQUIRE(core_spheres_valid(&spheres));
    fill(&spheres);
    CHECK_EQ_INT(core_spheres_resize(&spheres, SIZE_MAX), STATUS_OUT_OF_RANGE);
    CHECK_EQ_UINT(core_spheres_count(&spheres), 5);
    data_sphere sphere;
    REQUIRE(core_spheres_get(&spheres, 4, &sphere));
    CHECK(sphere.x == 5.0f && sphere.radius == 4004.0f);
    core_spheres_destroy(&spheres);
}

void test_spheres_copy_is_independent_and_move_empties(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(16);
    REQUIRE(core_spheres_valid(&spheres));
    fill(&spheres);
    core_spheres copy = core_spheres_copy(&spheres);
    REQUIRE(core_spheres_valid(&copy));
    CHECK_EQ_UINT(core_spheres_count(&copy), 16);
    core_spheres_get_view(&spheres).x[0] = 99.0f;
    CHECK(core_spheres_get_const_view(&copy).x[0] == 1.0f);

    core_spheres moved = core_spheres_move(&spheres);
    CHECK(!core_spheres_valid(&spheres));
    CHECK_EQ_UINT(core_spheres_count(&spheres), 0);
    CHECK_EQ_UINT(core_spheres_get_view(&spheres).count, 0);
    CHECK(core_spheres_get_view(&spheres).x == NULL);
    CHECK_EQ_UINT(core_spheres_count(&moved), 16);
    CHECK(core_spheres_get_const_view(&moved).x[0] == 99.0f);

    /* a moved-from container can be resized back into use, zeroed */
    CHECK_EQ_INT(core_spheres_resize(&spheres, 8), STATUS_OK);
    CHECK_EQ_UINT(core_spheres_count(&spheres), 8);
    CHECK_EQ_INT(count_nonzero(&spheres), 0);

    core_spheres_destroy(&moved);
    core_spheres_destroy(&copy);
    core_spheres_destroy(&spheres);
}

void test_spheres_zero_count_is_valid_and_empty(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(0);
    CHECK(core_spheres_valid(&spheres));
    CHECK_EQ_UINT(core_spheres_count(&spheres), 0);
    CHECK_EQ_UINT(core_spheres_get_view(&spheres).count, 0);
    core_spheres_destroy(&spheres);
}

void test_spheres_views_go_stale_after_resize_move_and_destroy(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(10);
    REQUIRE(core_spheres_valid(&spheres));
    core_spheres_view view = core_spheres_get_view(&spheres);
    core_spheres_const_view read = core_spheres_get_const_view(&spheres);
    CHECK(core_spheres_view_is_current(&view));
    CHECK(core_spheres_const_view_is_current(&read));

    /* resize may move the arrays: both old views are stale, new ones are current */
    REQUIRE_EQ_INT(core_spheres_resize(&spheres, 100), STATUS_OK);
    CHECK(!core_spheres_view_is_current(&view));
    CHECK(!core_spheres_const_view_is_current(&read));
    view = core_spheres_get_view(&spheres);
    CHECK(core_spheres_view_is_current(&view));

    /* moving hands the arrays over: views of the source are stale, views of the target current */
    core_spheres moved = core_spheres_move(&spheres);
    CHECK(!core_spheres_view_is_current(&view));
    core_spheres_view moved_view = core_spheres_get_view(&moved);
    CHECK(core_spheres_view_is_current(&moved_view));

    core_spheres_destroy(&moved);
    CHECK(!core_spheres_view_is_current(&moved_view));
    core_spheres_destroy(&spheres);
}

void test_spheres_empty_views_are_never_stale(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(4);
    REQUIRE(core_spheres_valid(&spheres));
    core_spheres moved = core_spheres_move(&spheres);
    /* the moved-from spheres have no block: an empty, untracked view */
    core_spheres_view empty = core_spheres_get_view(&spheres);
    CHECK_EQ_UINT(empty.count, 0);
    CHECK(empty.generation == NULL);
    CHECK(core_spheres_view_is_current(&empty));
    core_spheres_destroy(&moved);
    core_spheres_destroy(&spheres);
}
