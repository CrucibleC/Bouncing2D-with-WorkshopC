#include "hammerc.h"

#include "app/fps.h"

static app_fps_sample no_work(void)
{
    return app_fps_sample_pod(0, 0, 0, 0);
}

void test_fps_starts_at_zero(HammerCtx *t)
{
    app_fps fps = app_fps_pod(1000);
    CHECK(app_fps_value(&fps) == 0.0f);
    CHECK(app_fps_physics_ms(&fps) == 0.0f && app_fps_draw_ms(&fps) == 0.0f);
    CHECK(app_fps_present_ms(&fps) == 0.0f && app_fps_steps(&fps) == 0.0f);
}

void test_fps_updates_every_half_second(HammerCtx *t)
{
    app_fps fps = app_fps_pod(0);
    /* 30 frames 1/60 s apart: the last one ends at exactly 0.5 s */
    for (u64 frame = 1; frame <= 29; frame++) {
        app_fps_frame(&fps, frame * 16666667, no_work());
    }
    CHECK(app_fps_value(&fps) == 0.0f);           /* not half a second yet */
    app_fps_frame(&fps, 500000000, no_work());
    CHECK(app_fps_value(&fps) > 59.9f && app_fps_value(&fps) < 60.1f);
    /* then 10 frames over the next half second: 20 fps */
    for (u64 frame = 1; frame <= 10; frame++) {
        app_fps_frame(&fps, 500000000 + frame * 50000000, no_work());
    }
    CHECK(app_fps_value(&fps) > 19.9f && app_fps_value(&fps) < 20.1f);
}

void test_fps_averages_the_samples_per_frame(HammerCtx *t)
{
    app_fps fps = app_fps_pod(0);
    /* 10 frames over half a second: physics 1 or 3 ms (average 2), draw 0.5 ms, present 4 ms,
       2 or 3 steps (average 2.5) */
    for (u64 frame = 1; frame <= 10; frame++) {
        u64 physics = frame % 2 == 0 ? 3000000 : 1000000;
        u32 steps = frame % 2 == 0 ? 3 : 2;
        app_fps_frame(&fps, frame * 50000000, app_fps_sample_pod(physics, 500000, 4000000, steps));
    }
    CHECK(app_fps_physics_ms(&fps) > 1.99f && app_fps_physics_ms(&fps) < 2.01f);
    CHECK(app_fps_draw_ms(&fps) > 0.49f && app_fps_draw_ms(&fps) < 0.51f);
    CHECK(app_fps_present_ms(&fps) > 3.99f && app_fps_present_ms(&fps) < 4.01f);
    CHECK(app_fps_steps(&fps) > 2.49f && app_fps_steps(&fps) < 2.51f);
    /* the next window starts from nothing: one idle frame publishes zeros */
    app_fps_frame(&fps, 1000000000, no_work());
    CHECK(app_fps_physics_ms(&fps) == 0.0f && app_fps_steps(&fps) == 0.0f);
}

void test_fps_ignores_a_clock_going_backwards(HammerCtx *t)
{
    app_fps fps = app_fps_pod(1000000000);
    app_fps_frame(&fps, 5, no_work());
    CHECK(app_fps_value(&fps) == 0.0f);
}
