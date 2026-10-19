#include "app/app.h"

#include <inttypes.h>

#include "app/simulation.h"
#include "core/window.h"
#include "status.h"
#include "util/clock.h"
#include "util/log.h"
#include "util/random.h"
#include "util/singleton.h"

static const u32 WINDOW_WIDTH = 1280;
static const u32 WINDOW_HEIGHT = 720;
// The starting n: a calm 20 x 20 in a window, a meatier 100 x 100 for the headless benchmark
static const u32 START_N_WINDOW = 20;
static const u32 START_N_HEADLESS = 100;

// The benchmark line: how long frames and physics steps took in real time
static void app_log_timing(massive const app_simulation* simulation, u64 elapsed_ns)
{
    u64 frames = app_simulation_frames(simulation);
    u64 steps = app_simulation_steps(simulation);
    f64 ms_per_frame = frames > 0 ? cast_u64_to_f64(elapsed_ns) / 1e6 / cast_u64_to_f64(frames) : 0.0;
    f64 ms_per_step = steps > 0 ? cast_u64_to_f64(app_simulation_step_ns(simulation)) / 1e6 / cast_u64_to_f64(steps)
                                : 0.0;
    UTIL_LOG_INFO("%" PRIu64 " frames, %" PRIu64 " physics steps, %zu bodies: %.3f ms per frame, %.3f ms per step",
                  frames, steps, app_simulation_count(simulation), ms_per_frame, ms_per_step);
}

// Runs the simulation in window until it is closed (or, headless, until the mock's frame limit)
static status app_run_window(borrows massive core_window* window)
{
    u32 start_n = core_window_headless() ? START_N_HEADLESS : START_N_WINDOW;
    app_simulation simulation = app_simulation_make(start_n, core_window_bounds(window));
    status result = app_simulation_status(&simulation);
    if (app_simulation_valid(&simulation) && result == STATUS_OK)
    {
        UTIL_LOG_INFO("%s: n = %" PRIu32 ", %zu bodies", core_window_headless() ? "headless benchmark" : "window",
                      app_simulation_n(&simulation), app_simulation_count(&simulation));
        u64 start = util_clock_ns();
        while (app_simulation_frame(&simulation, window))
        {
        }
        app_log_timing(&simulation, util_clock_ns() - start);
    }
    else
    {
        result = result != STATUS_OK ? result : STATUS_OUT_OF_MEMORY;
        UTIL_LOG_ERROR("couldn't start the simulation: %s", status_to_string(result));
    }
    app_simulation_destroy(&simulation);
    return result;
}

i32 app_run(void)
{
    // Subsystems in start order; the log comes first, so the others can log while starting
    util_singleton_subsystem subsystems[3] = { util_log_subsystem(), util_random_subsystem(), core_window_subsystem() };
    util_singleton_subsystem_span subsystems_span = util_singleton_subsystem_span_pod(subsystems, 3);

    status result = util_singleton_subsystem_init_all(subsystems_span);
    if (result == STATUS_OK)
    {
        core_window window = core_window_make("Bouncing2D", WINDOW_WIDTH, WINDOW_HEIGHT);
        if (core_window_valid(&window))
        {
            result = app_run_window(&window);
        }
        else
        {
            result = STATUS_UNSUPPORTED;
            UTIL_LOG_ERROR("couldn't open the window");
        }
        core_window_destroy(&window);
    }
    else
    {
        UTIL_LOG_ERROR("startup failed: %s", status_to_string(result));
    }
    util_singleton_subsystem_shutdown_all(subsystems_span);
    return result == STATUS_OK ? 0 : 1;
}
