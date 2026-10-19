#include <math.h>

#include "hammerc.h"

#include "core/spheres.h"
#include "core/sprite_batch.h"

static void place(core_spheres_view *view, u32 i, f32 x, f32 y, f32 radius, data_rgba color)
{
    view->x[i] = x;
    view->y[i] = y;
    view->radius[i] = radius;
    view->rgba[i] = color;
}

void test_sprite_batch_prepare_writes_quads(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(2);
    core_sprite_batch batch = core_sprite_batch_make();
    REQUIRE(core_spheres_valid(&spheres) && core_sprite_batch_valid(&batch));
    core_spheres_view view = core_spheres_get_view(&spheres);
    place(&view, 0, 10.0f, 20.0f, 5.0f, data_rgba_pod(255, 0, 51, 255));
    place(&view, 1, 100.0f, 50.0f, 2.0f, data_rgba_pod(0, 255, 0, 0));
    core_spheres_const_view read = core_spheres_get_const_view(&spheres);
    REQUIRE_EQ_INT(core_sprite_batch_prepare(&batch, &read), STATUS_OK);

    core_sprite_batch_view sprites = core_sprite_batch_get_view(&batch);
    CHECK_EQ_UINT(sprites.count, 2);
    /* corners: top-left, top-right, bottom-right, bottom-left */
    const f32 xy0[8] = { 5.0f, 15.0f, 15.0f, 15.0f, 15.0f, 25.0f, 5.0f, 25.0f };
    int wrong = 0;
    for (int k = 0; k < 8; k++) {
        wrong += sprites.xy[k] != xy0[k];
    }
    CHECK_EQ_INT(wrong, 0);
    CHECK(sprites.xy[8] == 98.0f && sprites.xy[9] == 48.0f);
    /* colors in 0..1, the same for all four corners */
    CHECK(sprites.colors[0] == 1.0f && sprites.colors[1] == 0.0f && fabsf(sprites.colors[2] - 0.2f) < 1e-6f);
    CHECK(sprites.colors[3] == 1.0f && sprites.colors[12] == 1.0f && sprites.colors[15] == 1.0f);
    CHECK(sprites.colors[16] == 0.0f && sprites.colors[17] == 1.0f && sprites.colors[19] == 0.0f);
    const f32 uv[8] = { 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f };
    wrong = 0;
    for (int k = 0; k < 8; k++) {
        wrong += sprites.uv[k] != uv[k] || sprites.uv[8 + k] != uv[k];
    }
    CHECK_EQ_INT(wrong, 0);
    const u32 indices[12] = { 0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7 };
    wrong = 0;
    for (int k = 0; k < 12; k++) {
        wrong += sprites.indices[k] != indices[k];
    }
    CHECK_EQ_INT(wrong, 0);
    core_sprite_batch_destroy(&batch);
    core_spheres_destroy(&spheres);
}

void test_sprite_batch_update_follows_the_spheres(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(1);
    core_sprite_batch batch = core_sprite_batch_make();
    REQUIRE(core_spheres_valid(&spheres) && core_sprite_batch_valid(&batch));
    core_spheres_view view = core_spheres_get_view(&spheres);
    place(&view, 0, 10.0f, 10.0f, 3.0f, data_rgba_pod(1, 2, 3, 255));
    core_spheres_const_view read = core_spheres_get_const_view(&spheres);
    REQUIRE_EQ_INT(core_sprite_batch_prepare(&batch, &read), STATUS_OK);
    view.x[0] = 50.0f;
    core_sprite_batch_update(&batch, &read);
    CHECK(core_sprite_batch_get_view(&batch).xy[0] == 47.0f);
    core_sprite_batch_destroy(&batch);
    core_spheres_destroy(&spheres);
}

void test_sprite_batch_keeps_tiny_spheres_visible(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(1);
    core_sprite_batch batch = core_sprite_batch_make();
    REQUIRE(core_spheres_valid(&spheres) && core_sprite_batch_valid(&batch));
    core_spheres_view view = core_spheres_get_view(&spheres);
    place(&view, 0, 10.0f, 10.0f, 0.1f, data_rgba_pod(1, 2, 3, 255));
    core_spheres_const_view read = core_spheres_get_const_view(&spheres);
    REQUIRE_EQ_INT(core_sprite_batch_prepare(&batch, &read), STATUS_OK);
    f32 min_radius = core_sprite_batch_min_radius();
    CHECK(core_sprite_batch_get_view(&batch).xy[0] == 10.0f - min_radius);
    core_sprite_batch_destroy(&batch);
    core_spheres_destroy(&spheres);
}

void test_sprite_batch_update_ignores_a_count_mismatch(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(2);
    core_spheres other = core_spheres_make(3);
    core_sprite_batch batch = core_sprite_batch_make();
    REQUIRE(core_spheres_valid(&spheres) && core_spheres_valid(&other) && core_sprite_batch_valid(&batch));
    core_spheres_view view = core_spheres_get_view(&spheres);
    place(&view, 0, 10.0f, 10.0f, 1.0f, data_rgba_pod(1, 2, 3, 255));
    core_spheres_const_view read = core_spheres_get_const_view(&spheres);
    REQUIRE_EQ_INT(core_sprite_batch_prepare(&batch, &read), STATUS_OK);
    core_spheres_const_view wrong = core_spheres_get_const_view(&other);
    core_sprite_batch_update(&batch, &wrong);
    CHECK(core_sprite_batch_get_view(&batch).xy[0] == 9.0f);
    core_sprite_batch_destroy(&batch);
    core_spheres_destroy(&other);
    core_spheres_destroy(&spheres);
}

void test_sprite_batch_grows_for_many_spheres(HammerCtx *t)
{
    core_spheres spheres = core_spheres_make(10000);
    core_sprite_batch batch = core_sprite_batch_make();
    REQUIRE(core_spheres_valid(&spheres) && core_sprite_batch_valid(&batch));
    core_spheres_const_view read = core_spheres_get_const_view(&spheres);
    CHECK_EQ_INT(core_sprite_batch_prepare(&batch, &read), STATUS_OK);
    CHECK_EQ_UINT(core_sprite_batch_count(&batch), 10000);
    CHECK(core_sprite_batch_get_view(&batch).indices[6 * 9999 + 5] == 4 * 9999 + 3);
    core_sprite_batch_destroy(&batch);
    core_spheres_destroy(&spheres);
}

void test_sprite_circle_alpha(HammerCtx *t)
{
    CHECK(core_sprite_circle_alpha(64, 32, 32) == 1.0f);   /* center */
    CHECK(core_sprite_circle_alpha(64, 0, 0) == 0.0f);     /* corner, outside the circle */
    f32 edge = core_sprite_circle_alpha(64, 63, 32);       /* the soft rim */
    CHECK(edge > 0.0f && edge < 1.0f);
    CHECK(core_sprite_circle_alpha(0, 0, 0) == 0.0f);
    CHECK(core_sprite_circle_alpha(64, 64, 0) == 0.0f);    /* outside the texture */
}
