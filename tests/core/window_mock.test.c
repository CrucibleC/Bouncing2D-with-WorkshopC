#include "hammerc.h"

#include "core/window.h"
#include "core/window_mock.h"

void test_window_mock_is_headless_with_a_size(HammerCtx *t)
{
    core_window window = core_window_make("test", 800, 600);
    REQUIRE(core_window_valid(&window));
    CHECK(core_window_headless());
    CHECK(core_window_glyph_size() == 8.0f);
    data_bounds bounds = core_window_bounds(&window);
    CHECK(bounds.min_x == 0.0f && bounds.min_y == 0.0f && bounds.max_x == 800.0f && bounds.max_y == 600.0f);
    data_input_event event;
    CHECK(!core_window_poll_event(&window, &event));
    CHECK_EQ_INT(event.kind, DATA_INPUT_NONE);
    core_window_destroy(&window);
}

void test_window_mock_plays_back_events_in_order(HammerCtx *t)
{
    core_window window = core_window_make("test", 800, 600);
    REQUIRE(core_window_valid(&window));
    CHECK(core_window_mock_push_event(&window, data_input_event_pod(DATA_INPUT_MOUSE_DOWN, 5.0f, 6.0f)));
    CHECK(core_window_mock_push_event(&window, data_input_event_pod(DATA_INPUT_MOUSE_UP, 5.0f, 6.0f)));
    CHECK(core_window_mock_push_event(&window, data_input_event_pod(DATA_INPUT_RESIZE, 1024.0f, 768.0f)));
    data_input_event event;
    REQUIRE(core_window_poll_event(&window, &event));
    CHECK(event.kind == DATA_INPUT_MOUSE_DOWN && event.x == 5.0f && event.y == 6.0f);
    REQUIRE(core_window_poll_event(&window, &event));
    CHECK_EQ_INT(event.kind, DATA_INPUT_MOUSE_UP);
    REQUIRE(core_window_poll_event(&window, &event));
    CHECK_EQ_INT(event.kind, DATA_INPUT_RESIZE);
    CHECK(core_window_bounds(&window).max_x == 1024.0f && core_window_bounds(&window).max_y == 768.0f);
    CHECK(!core_window_poll_event(&window, &event));
    core_window_destroy(&window);
}

void test_window_mock_queue_is_bounded(HammerCtx *t)
{
    core_window window = core_window_make("test", 10, 10);
    REQUIRE(core_window_valid(&window));
    int pushed = 0;
    for (int i = 0; i < 100; i++) {
        pushed += core_window_mock_push_event(&window, data_input_event_pod(DATA_INPUT_MOUSE_UP, 0.0f, 0.0f));
    }
    CHECK_EQ_INT(pushed, 64);
    core_window_destroy(&window);
}

void test_window_mock_quits_after_its_frame_limit(HammerCtx *t)
{
    core_window window = core_window_make("test", 10, 10);
    REQUIRE(core_window_valid(&window));
    CHECK_EQ_UINT(core_window_mock_default_frames(), 600);
    core_window_mock_set_frame_limit(&window, 2);
    data_input_event event;
    core_window_present(&window);
    CHECK(!core_window_poll_event(&window, &event));
    core_window_present(&window);
    REQUIRE(core_window_poll_event(&window, &event));
    CHECK_EQ_INT(event.kind, DATA_INPUT_QUIT);
    CHECK(!core_window_poll_event(&window, &event));   /* only once */
    core_window_destroy(&window);
}

void test_window_mock_counts_drawing_per_frame(HammerCtx *t)
{
    core_window window = core_window_make("test", 10, 10);
    REQUIRE(core_window_valid(&window));
    core_sprite_batch_view sprites = core_sprite_batch_view_pod(5, NULL, NULL, NULL, NULL);
    char text[4] = { 'a', 'b', 'c', '\0' };
    char_span text_span = char_span_pod(text, sizeof text);
    u64 before = core_window_time_ns(&window);
    core_window_clear(&window, data_rgba_pod(0, 0, 0, 255));
    core_window_draw_sprites(&window, &sprites);
    core_window_draw_triangle(&window, data_triangle_pod(0, 0, 1, 0, 0, 1), data_rgba_pod(1, 1, 1, 255));
    core_window_draw_text(&window, 0.0f, 0.0f, 1.0f, char_const_span_pod(text_span), data_rgba_pod(1, 1, 1, 255));
    core_window_draw_text(&window, 0.0f, 0.0f, 1.0f, char_const_span_pod(text_span), data_rgba_pod(1, 1, 1, 255));
    core_window_present(&window);
    core_window_mock_stats stats = core_window_mock_get_stats(&window);
    CHECK_EQ_UINT(stats.frames, 1);
    CHECK_EQ_UINT(stats.sprites, 5);
    CHECK_EQ_UINT(stats.triangles, 1);
    CHECK_EQ_UINT(stats.texts, 2);
    CHECK_EQ_UINT(stats.clears, 1);
    /* the fake clock moved one 60 Hz frame */
    CHECK_EQ_UINT(core_window_time_ns(&window) - before, 16666667);
    /* the next frame starts from zero */
    core_window_present(&window);
    CHECK_EQ_UINT(core_window_mock_get_stats(&window).sprites, 0);
    core_window_destroy(&window);
}
