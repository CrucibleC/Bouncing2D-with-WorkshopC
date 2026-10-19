#include "hammerc.h"

#include "app/hud.h"
#include "app/simulation.h"
#include "core/window.h"
#include "core/window_mock.h"
#include "util/log.h"
#include "util/random.h"

/* Each test runs a simulation on an 800 x 600 mock window, quiet in the terminal. */

static void quiet(void)
{
    util_log_set_terminal(false);
    util_random_seed(7);
}

static void loud(void)
{
    util_log_set_terminal(true);
}

/* Presses and releases the mouse at the middle of a button, as it's laid out right now */
static void click(core_window *window, const app_simulation *simulation, app_hud_button button)
{
    app_hud_layout layout = app_hud_layout_pod(800.0f, app_simulation_n(simulation), app_simulation_count(simulation));
    data_triangle triangle = layout.more;
    if (button == APP_HUD_BUTTON_LESS) {
        triangle = layout.less;
    } else if (button == APP_HUD_BUTTON_DIVIDE) {
        triangle = layout.divide;
    } else if (button == APP_HUD_BUTTON_MULTIPLY) {
        triangle = layout.multiply;
    }
    f32 x = (triangle.x0 + triangle.x1 + triangle.x2) / 3.0f;
    f32 y = (triangle.y0 + triangle.y1 + triangle.y2) / 3.0f;
    core_window_mock_push_event(window, data_input_event_pod(DATA_INPUT_MOUSE_DOWN, x, y));
    core_window_mock_push_event(window, data_input_event_pod(DATA_INPUT_MOUSE_UP, x, y));
}

void test_simulation_make_spawns_n_squared_bodies(HammerCtx *t)
{
    quiet();
    app_simulation simulation = app_simulation_make(3, data_bounds_pod(0.0f, 0.0f, 800.0f, 600.0f));
    REQUIRE(app_simulation_valid(&simulation));
    CHECK_EQ_INT(app_simulation_status(&simulation), STATUS_OK);
    CHECK_EQ_UINT(app_simulation_n(&simulation), 3);
    CHECK_EQ_UINT(app_simulation_count(&simulation), 9);
    CHECK_EQ_UINT(app_simulation_spheres(&simulation).rgba[8].a, 255);
    app_simulation_destroy(&simulation);
    loud();
}

void test_simulation_clamps_n(HammerCtx *t)
{
    quiet();
    CHECK_EQ_UINT(app_simulation_max_n(), 1000);
    app_simulation simulation = app_simulation_make(0, data_bounds_pod(0.0f, 0.0f, 800.0f, 600.0f));
    REQUIRE(app_simulation_valid(&simulation));
    CHECK_EQ_UINT(app_simulation_n(&simulation), 1);
    CHECK_EQ_UINT(app_simulation_count(&simulation), 1);
    app_simulation_destroy(&simulation);
    loud();
}

void test_simulation_more_button_grows_n_on_the_next_frame(HammerCtx *t)
{
    quiet();
    core_window window = core_window_make("test", 800, 600);
    app_simulation simulation = app_simulation_make(2, core_window_bounds(&window));
    REQUIRE(core_window_valid(&window) && app_simulation_valid(&simulation));
    click(&window, &simulation, APP_HUD_BUTTON_MORE);
    CHECK(app_simulation_frame(&simulation, &window));
    CHECK_EQ_UINT(app_simulation_n(&simulation), 3);
    CHECK_EQ_UINT(app_simulation_count(&simulation), 9);
    /* drawn: every body, the four buttons and five texts */
    core_window_mock_stats stats = core_window_mock_get_stats(&window);
    CHECK_EQ_UINT(stats.sprites, 9);
    CHECK_EQ_UINT(stats.triangles, 4);
    CHECK_EQ_UINT(stats.texts, 5);
    app_simulation_destroy(&simulation);
    core_window_destroy(&window);
    loud();
}

void test_simulation_button_stays_pressed_until_the_mouse_goes_up(HammerCtx *t)
{
    quiet();
    core_window window = core_window_make("test", 800, 600);
    app_simulation simulation = app_simulation_make(4, core_window_bounds(&window));
    REQUIRE(core_window_valid(&window) && app_simulation_valid(&simulation));
    app_hud_layout layout = app_hud_layout_pod(800.0f, 4, 16);
    f32 x = (layout.less.x0 + layout.less.x1 + layout.less.x2) / 3.0f;
    f32 y = (layout.less.y0 + layout.less.y1 + layout.less.y2) / 3.0f;
    app_simulation_handle_event(&simulation, data_input_event_pod(DATA_INPUT_MOUSE_DOWN, x, y));
    CHECK_EQ_INT(app_simulation_pressed(&simulation), APP_HUD_BUTTON_LESS);
    app_simulation_handle_event(&simulation, data_input_event_pod(DATA_INPUT_MOUSE_UP, x, y));
    CHECK_EQ_INT(app_simulation_pressed(&simulation), APP_HUD_BUTTON_NONE);
    CHECK_EQ_INT(app_simulation_apply_request(&simulation), STATUS_OK);
    CHECK_EQ_UINT(app_simulation_n(&simulation), 3);
    app_simulation_destroy(&simulation);
    core_window_destroy(&window);
    loud();
}

void test_simulation_less_button_stops_at_one(HammerCtx *t)
{
    quiet();
    core_window window = core_window_make("test", 800, 600);
    app_simulation simulation = app_simulation_make(1, core_window_bounds(&window));
    REQUIRE(core_window_valid(&window) && app_simulation_valid(&simulation));
    click(&window, &simulation, APP_HUD_BUTTON_LESS);
    CHECK(app_simulation_frame(&simulation, &window));
    CHECK_EQ_UINT(app_simulation_n(&simulation), 1);
    CHECK_EQ_UINT(app_simulation_count(&simulation), 1);
    app_simulation_destroy(&simulation);
    core_window_destroy(&window);
    loud();
}

void test_simulation_multiply_button_takes_n_times_ten(HammerCtx *t)
{
    quiet();
    core_window window = core_window_make("test", 800, 600);
    app_simulation simulation = app_simulation_make(2, core_window_bounds(&window));
    REQUIRE(core_window_valid(&window) && app_simulation_valid(&simulation));
    click(&window, &simulation, APP_HUD_BUTTON_MULTIPLY);
    CHECK(app_simulation_frame(&simulation, &window));
    CHECK_EQ_UINT(app_simulation_n(&simulation), 20);
    CHECK_EQ_UINT(app_simulation_count(&simulation), 400);
    CHECK_EQ_UINT(core_window_mock_get_stats(&window).sprites, 400);
    app_simulation_destroy(&simulation);
    core_window_destroy(&window);
    loud();
}

void test_simulation_divide_button_takes_n_over_ten_down_to_one(HammerCtx *t)
{
    quiet();
    core_window window = core_window_make("test", 800, 600);
    app_simulation simulation = app_simulation_make(25, core_window_bounds(&window));
    REQUIRE(core_window_valid(&window) && app_simulation_valid(&simulation));
    click(&window, &simulation, APP_HUD_BUTTON_DIVIDE);
    CHECK(app_simulation_frame(&simulation, &window));
    CHECK_EQ_UINT(app_simulation_n(&simulation), 2);   /* 25 / 10, rounded down */
    CHECK_EQ_UINT(app_simulation_count(&simulation), 4);
    click(&window, &simulation, APP_HUD_BUTTON_DIVIDE);
    CHECK(app_simulation_frame(&simulation, &window));
    CHECK_EQ_UINT(app_simulation_n(&simulation), 1);   /* never below 1 */
    click(&window, &simulation, APP_HUD_BUTTON_DIVIDE);
    CHECK(app_simulation_frame(&simulation, &window));
    CHECK_EQ_UINT(app_simulation_n(&simulation), 1);
    app_simulation_destroy(&simulation);
    core_window_destroy(&window);
    loud();
}

void test_simulation_multiply_stops_at_the_largest_n(HammerCtx *t)
{
    quiet();
    app_simulation simulation = app_simulation_make(200, data_bounds_pod(0.0f, 0.0f, 800.0f, 600.0f));
    REQUIRE(app_simulation_valid(&simulation));
    app_hud_layout layout = app_hud_layout_pod(800.0f, 200, 40000);
    f32 x = (layout.multiply.x0 + layout.multiply.x1 + layout.multiply.x2) / 3.0f;
    f32 y = (layout.multiply.y0 + layout.multiply.y1 + layout.multiply.y2) / 3.0f;
    /* only the request is checked: applying it would make a million bodies */
    app_simulation_handle_event(&simulation, data_input_event_pod(DATA_INPUT_MOUSE_DOWN, x, y));
    CHECK_EQ_INT(app_simulation_pressed(&simulation), APP_HUD_BUTTON_MULTIPLY);
    CHECK_EQ_UINT(app_simulation_requested_n(&simulation), 1000);
    CHECK_EQ_UINT(app_simulation_n(&simulation), 200);   /* not applied until the next frame */
    app_simulation_destroy(&simulation);
    loud();
}

void test_simulation_resize_updates_the_bounds(HammerCtx *t)
{
    quiet();
    app_simulation simulation = app_simulation_make(2, data_bounds_pod(0.0f, 0.0f, 800.0f, 600.0f));
    REQUIRE(app_simulation_valid(&simulation));
    app_simulation_handle_event(&simulation, data_input_event_pod(DATA_INPUT_RESIZE, 1024.0f, 768.0f));
    data_bounds bounds = app_simulation_bounds(&simulation);
    CHECK(bounds.max_x == 1024.0f && bounds.max_y == 768.0f);
    app_simulation_destroy(&simulation);
    loud();
}

void test_simulation_ignores_an_empty_resize(HammerCtx *t)
{
    quiet();
    app_simulation simulation = app_simulation_make(2, data_bounds_pod(0.0f, 0.0f, 800.0f, 600.0f));
    REQUIRE(app_simulation_valid(&simulation));
    app_simulation_handle_event(&simulation, data_input_event_pod(DATA_INPUT_RESIZE, 0.0f, 0.0f));
    app_simulation_handle_event(&simulation, data_input_event_pod(DATA_INPUT_RESIZE, 640.0f, 0.0f));
    data_bounds bounds = app_simulation_bounds(&simulation);
    CHECK(bounds.max_x == 800.0f && bounds.max_y == 600.0f);
    app_simulation_destroy(&simulation);
    loud();
}

void test_simulation_advance_runs_fixed_steps(HammerCtx *t)
{
    quiet();
    app_simulation simulation = app_simulation_make(2, data_bounds_pod(0.0f, 0.0f, 800.0f, 600.0f));
    REQUIRE(app_simulation_valid(&simulation));
    app_simulation_advance(&simulation, 1.0 / 60.0);
    CHECK_EQ_UINT(app_simulation_steps(&simulation), 2);       /* two 1/120 s steps */
    app_simulation_advance(&simulation, 1.0);
    CHECK_EQ_UINT(app_simulation_steps(&simulation), 10);      /* at most 8 more; the rest is dropped */
    app_simulation_advance(&simulation, 1.0 / 240.0);
    CHECK_EQ_UINT(app_simulation_steps(&simulation), 10);      /* half a step waits for more time */
    app_simulation_destroy(&simulation);
    loud();
}

void test_simulation_keeps_bodies_inside_the_window(HammerCtx *t)
{
    quiet();
    core_window window = core_window_make("test", 800, 600);
    app_simulation simulation = app_simulation_make(10, core_window_bounds(&window));
    REQUIRE(core_window_valid(&window) && app_simulation_valid(&simulation));
    /* 120 frames: two seconds of fake time, including several spatial sorts */
    for (int frame = 0; frame < 120; frame++) {
        REQUIRE(app_simulation_frame(&simulation, &window));
    }
    core_spheres_const_view view = app_simulation_spheres(&simulation);
    int outside = 0;
    int bad_color = 0;
    for (size_t i = 0; i < view.count; i++) {
        outside += view.x[i] - view.radius[i] < -1e-3f || view.x[i] + view.radius[i] > 800.0f + 1e-3f;
        outside += view.y[i] - view.radius[i] < -1e-3f || view.y[i] + view.radius[i] > 600.0f + 1e-3f;
        bad_color += view.rgba[i].a != 255;
    }
    CHECK_EQ_INT(outside, 0);
    CHECK_EQ_INT(bad_color, 0);
    CHECK_EQ_UINT(app_simulation_count(&simulation), 100);
    CHECK_EQ_UINT(core_window_mock_get_stats(&window).sprites, 100);
    CHECK(app_simulation_steps(&simulation) >= 230);
    app_simulation_destroy(&simulation);
    core_window_destroy(&window);
    loud();
}

void test_simulation_quit_ends_the_frames(HammerCtx *t)
{
    quiet();
    core_window window = core_window_make("test", 800, 600);
    app_simulation simulation = app_simulation_make(2, core_window_bounds(&window));
    REQUIRE(core_window_valid(&window) && app_simulation_valid(&simulation));
    CHECK(app_simulation_frame(&simulation, &window));
    core_window_mock_push_event(&window, data_input_event_pod(DATA_INPUT_QUIT, 0.0f, 0.0f));
    CHECK(!app_simulation_frame(&simulation, &window));
    CHECK(app_simulation_quit_requested(&simulation));
    app_simulation_destroy(&simulation);
    core_window_destroy(&window);
    loud();
}
