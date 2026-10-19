#include "app/fps.h"

#include "workshopc_tags.h"

static const u64 UPDATE_NS = 500000000;   // half a second

app_fps_sample app_fps_sample_pod(u64 physics_ns, u64 draw_ns, u64 present_ns, u32 steps)
{
    return (app_fps_sample){ .physics_ns = physics_ns, .draw_ns = draw_ns, .present_ns = present_ns, .steps = steps };
}

app_fps app_fps_pod(u64 now_ns)
{
    return (app_fps){
        .window_start_ns = now_ns,
        .frames = 0,
        .physics_ns = 0,
        .draw_ns = 0,
        .present_ns = 0,
        .steps = 0,
        .value = 0.0f,
        .physics_ms = 0.0f,
        .draw_ms = 0.0f,
        .present_ms = 0.0f,
        .steps_per_frame = 0.0f,
    };
}

// The average per frame of a nanosecond sum, in milliseconds
static f32 app_fps_average_ms(u64 sum_ns, u32 frames)
{
    return cast_f64_to_f32(cast_u64_to_f64(sum_ns) / 1e6 / cast_u32_to_f64(frames));
}

void app_fps_frame(borrows massive app_fps* self, u64 now_ns, app_fps_sample sample)
{
    self->frames += 1;
    self->physics_ns += sample.physics_ns;
    self->draw_ns += sample.draw_ns;
    self->present_ns += sample.present_ns;
    self->steps += sample.steps;
    u64 elapsed = now_ns > self->window_start_ns ? now_ns - self->window_start_ns : 0;
    if (elapsed < UPDATE_NS)
    {
        return;
    }
    self->value = cast_f64_to_f32(cast_u32_to_f64(self->frames) * 1e9 / cast_u64_to_f64(elapsed));
    self->physics_ms = app_fps_average_ms(self->physics_ns, self->frames);
    self->draw_ms = app_fps_average_ms(self->draw_ns, self->frames);
    self->present_ms = app_fps_average_ms(self->present_ns, self->frames);
    self->steps_per_frame = cast_f64_to_f32(cast_u64_to_f64(self->steps) / cast_u32_to_f64(self->frames));
    self->window_start_ns = now_ns;
    self->frames = 0;
    self->physics_ns = 0;
    self->draw_ns = 0;
    self->present_ns = 0;
    self->steps = 0;
}

f32 app_fps_value(massive const app_fps* self)
{
    return self->value;
}

f32 app_fps_physics_ms(massive const app_fps* self)
{
    return self->physics_ms;
}

f32 app_fps_draw_ms(massive const app_fps* self)
{
    return self->draw_ms;
}

f32 app_fps_present_ms(massive const app_fps* self)
{
    return self->present_ms;
}

f32 app_fps_steps(massive const app_fps* self)
{
    return self->steps_per_frame;
}
