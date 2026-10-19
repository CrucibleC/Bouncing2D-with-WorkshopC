#include <stdint.h>
#include <string.h>

#include "hammerc.h"

#include "app/hud.h"
#include "core/window.h"
#include "core/window_mock.h"

static size_t format(u64 value, char *out, size_t size)
{
    return app_hud_format_count(value, char_span_pod(out, size));
}

void test_hud_layout_centers_the_buttons_around_n(HammerCtx *t)
{
    /* 800 wide, n = 10, 100 bodies. Text is 16 px per character, the exponent 8 px, the
       triangles 16 px with 10 px gaps:
       16 + 10 + 16 + 10 + 32 + 8 + 10 + 16 + 10 + 16 = 144 wide, starting at 328 */
    app_hud_layout layout = app_hud_layout_pod(800.0f, 10, 100);
    CHECK(layout.divide.x0 == 328.0f && layout.divide.y0 == 18.0f);   /* the outer left tip */
    CHECK(layout.less.x0 == 354.0f && layout.less.y0 == 18.0f);       /* the inner left tip */
    CHECK(layout.number_x == 380.0f && layout.number_y == 10.0f);
    CHECK(layout.exponent_x == 412.0f && layout.exponent_y == 6.0f);   /* raised above the number */
    CHECK(layout.more.x0 == 430.0f && layout.more.x1 == 446.0f && layout.more.y1 == 18.0f);
    CHECK(layout.multiply.x0 == 456.0f && layout.multiply.x1 == 472.0f && layout.multiply.y1 == 18.0f);
    CHECK(layout.fps_x == 10.0f && layout.fps_y == 10.0f);
    CHECK(layout.timing_x == 10.0f && layout.timing_y == 32.0f);       /* under the 16 px FPS */
    /* "100 bodies" is 10 characters: right-aligned with a 10 px margin */
    CHECK(layout.count_x == 630.0f && layout.count_y == 10.0f);
    /* "10 000 000 bodies" is 17 characters */
    CHECK(app_hud_layout_pod(800.0f, 10, 10000000).count_x == 800.0f - 10.0f - 17.0f * 16.0f);
}

void test_hud_press_finds_the_buttons_and_release_clears(HammerCtx *t)
{
    app_hud_layout layout = app_hud_layout_pod(800.0f, 10, 100);
    app_hud hud = app_hud_pod();
    CHECK_EQ_INT(app_hud_pressed(&hud), APP_HUD_BUTTON_NONE);
    CHECK_EQ_INT(app_hud_press(&hud, &layout, 362.0f, 18.0f), APP_HUD_BUTTON_LESS);
    CHECK_EQ_INT(app_hud_pressed(&hud), APP_HUD_BUTTON_LESS);
    app_hud_release(&hud);
    CHECK_EQ_INT(app_hud_pressed(&hud), APP_HUD_BUTTON_NONE);
    CHECK_EQ_INT(app_hud_press(&hud, &layout, 438.0f, 18.0f), APP_HUD_BUTTON_MORE);
    CHECK_EQ_INT(app_hud_press(&hud, &layout, 336.0f, 18.0f), APP_HUD_BUTTON_DIVIDE);
    CHECK_EQ_INT(app_hud_pressed(&hud), APP_HUD_BUTTON_DIVIDE);
    CHECK_EQ_INT(app_hud_press(&hud, &layout, 464.0f, 18.0f), APP_HUD_BUTTON_MULTIPLY);
    /* a few pixels of slack around a triangle still count */
    CHECK_EQ_INT(app_hud_press(&hud, &layout, 351.0f, 18.0f), APP_HUD_BUTTON_LESS);
    CHECK_EQ_INT(app_hud_press(&hud, &layout, 475.0f, 18.0f), APP_HUD_BUTTON_MULTIPLY);
    /* the number between the buttons, or far away, is no button */
    CHECK_EQ_INT(app_hud_press(&hud, &layout, 395.0f, 18.0f), APP_HUD_BUTTON_NONE);
    CHECK_EQ_INT(app_hud_press(&hud, &layout, 400.0f, 300.0f), APP_HUD_BUTTON_NONE);
    CHECK_EQ_INT(app_hud_pressed(&hud), APP_HUD_BUTTON_NONE);
}

void test_hud_format_count_groups_digits_by_three(HammerCtx *t)
{
    char out[32];
    CHECK_EQ_UINT(format(0, out, sizeof out), 1);
    CHECK_EQ_STR(out, "0");
    CHECK_EQ_UINT(format(999, out, sizeof out), 3);
    CHECK_EQ_STR(out, "999");
    CHECK_EQ_UINT(format(1000, out, sizeof out), 5);
    CHECK_EQ_STR(out, "1 000");
    CHECK_EQ_UINT(format(10000000, out, sizeof out), 10);
    CHECK_EQ_STR(out, "10 000 000");
    CHECK_EQ_UINT(format(UINT64_MAX, out, sizeof out), 26);
    CHECK_EQ_STR(out, "18 446 744 073 709 551 615");
}

void test_hud_format_count_needs_room(HammerCtx *t)
{
    char small[5];
    CHECK_EQ_UINT(format(1000, small, sizeof small), 0);   /* "1 000" plus '\0' needs 6 */
    CHECK_EQ_STR(small, "");
    char exact[6];
    CHECK_EQ_UINT(format(1000, exact, sizeof exact), 5);
    CHECK_EQ_STR(exact, "1 000");
}

void test_hud_colors(HammerCtx *t)
{
    data_rgba yellow = app_hud_fps_color();
    CHECK(yellow.r == 255 && yellow.g == 255 && yellow.b == 0 && yellow.a == 255);
    data_rgba normal = app_hud_button_color(false);
    data_rgba pressed = app_hud_button_color(true);
    CHECK(normal.r != pressed.r || normal.g != pressed.g || normal.b != pressed.b);
}

void test_hud_draw_sends_text_and_buttons(HammerCtx *t)
{
    core_window window = core_window_make("test", 800, 600);
    REQUIRE(core_window_valid(&window));
    app_hud hud = app_hud_pod();
    app_hud_layout layout = app_hud_layout_pod(800.0f, 10, 100);
    app_fps fps = app_fps_pod(0);
    app_hud_draw(&hud, &layout, &window, 10, 100, &fps);
    core_window_present(&window);
    core_window_mock_stats stats = core_window_mock_get_stats(&window);
    CHECK_EQ_UINT(stats.triangles, 4);
    CHECK_EQ_UINT(stats.texts, 5);   /* FPS, the timing line, n, its exponent, the body count */
    core_window_destroy(&window);
}
