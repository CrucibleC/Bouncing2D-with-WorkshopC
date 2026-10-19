#ifndef APP_FPS_H
#define APP_FPS_H

#include "numbers.h"
#include "workshopc_tags.h"

// Where one frame's time went, in real nanoseconds
typedef struct app_fps_sample
{
    u64 physics_ns;   // the physics steps (and the occasional spatial sort)
    u64 draw_ns;      // building and submitting the drawing: clear, sprites, HUD
    u64 present_ns;   // presenting: includes waiting for VSync and the GPU
    u32 steps;        // physics steps taken
} app_fps_sample;

// Frames per second, and per-frame averages of the samples, for the HUD: counted over half-second
// windows and published when one ends, so the numbers stay readable
typedef struct app_fps
{
    u64 window_start_ns;   // when the current half-second window began
    u32 frames;            // frames counted in it so far
    u64 physics_ns;        // sums over the current window
    u64 draw_ns;
    u64 present_ns;
    u64 steps;
    f32 value;             // the published values; all 0 until the first window ends
    f32 physics_ms;
    f32 draw_ms;
    f32 present_ms;
    f32 steps_per_frame;
} app_fps;

// { physics_ns, draw_ns, present_ns, steps }
app_fps_sample app_fps_sample_pod(u64 physics_ns, u64 draw_ns, u64 present_ns, u32 steps);

// Starts counting at now_ns
app_fps app_fps_pod(u64 now_ns);
// Counts one frame that ended at now_ns and took sample; publishes new values once half a second
// has passed
void app_fps_frame(MUTABLE REF app_fps* self, u64 now_ns, app_fps_sample sample);
f32 app_fps_value(REF const app_fps* self);
// Per-frame averages over the last window
f32 app_fps_physics_ms(REF const app_fps* self);
f32 app_fps_draw_ms(REF const app_fps* self);
f32 app_fps_present_ms(REF const app_fps* self);
f32 app_fps_steps(REF const app_fps* self);

#endif // APP_FPS_H
