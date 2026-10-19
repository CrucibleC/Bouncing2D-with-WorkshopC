#include "app/simulation.h"

#include <inttypes.h>

#include "core/physics.h"
#include "core/spawn.h"
#include "util/clock.h"
#include "util/log.h"
#include "workshopc_tags.h"

// n * n bodies; 1000 gives a million. Must stay <= 65535 so n * n fits the u32 sphere indices
static const u32 MAX_N = 1000;
// Fixed physics step: stable and the same on every machine
static const f64 STEP_SECONDS = 1.0 / 120.0;
static const f32 STEP_DT = 1.0f / 120.0f;
static const u32 MAX_STEPS_PER_FRAME = 8;
// How often the spheres are reordered by grid cell, for cache locality
static const u64 SORT_EVERY_FRAMES = 30;

static u32 app_simulation_clamp_n(u32 n)
{
    if (n < 1)
    {
        return 1;
    }
    return n > MAX_N ? MAX_N : n;
}

// The n a button asks for, starting from n: - 1, + 1, / 10 rounded down (so * 10 then / 10 comes
// back to the same n) or * 10; always within 1 .. MAX_N
static u32 app_simulation_next_n(app_hud_button button, u32 n)
{
    u64 next = cast_u32_to_u64(n);
    switch (button)
    {
        case APP_HUD_BUTTON_LESS:
            next = next > 0 ? next - 1 : 0;
            break;
        case APP_HUD_BUTTON_MORE:
            next += 1;
            break;
        case APP_HUD_BUTTON_DIVIDE:
            next /= 10;
            break;
        case APP_HUD_BUTTON_MULTIPLY:
            next *= 10;
            break;
        default:
            break;
    }
    return app_simulation_clamp_n(cast_u64_to_u32(next));
}

static f32 app_simulation_width(massive const app_simulation* self)
{
    return self->bounds.max_x - self->bounds.min_x;
}

// Grid cells for the current spheres and bounds
static status app_simulation_size_grid(borrows massive app_simulation* self)
{
    u32 columns = 0;
    u32 rows = 0;
    core_grid_size_for(core_spheres_count(&self->spheres), self->bounds, 2.0f * self->radius, overwrite(&columns),
                       overwrite(&rows));
    return core_grid_resize(&self->grid, columns, rows);
}

// Spawns an n x n lattice into the spheres (which must hold n * n), then readies the vertex
// buffers and the grid for them
static status app_simulation_fill(borrows massive app_simulation* self, u32 n)
{
    core_spheres_view view = core_spheres_get_view(&self->spheres);
    if (!core_spawn_lattice(&view, n, self->bounds))
    {
        return STATUS_INVALID_STATE;
    }
    self->radius = core_spawn_lattice_max_radius(n, self->bounds);
    core_spheres_const_view read = core_spheres_get_const_view(&self->spheres);
    status result = core_sprite_batch_prepare(&self->sprites, &read);
    if (result == STATUS_OK)
    {
        result = app_simulation_size_grid(self);
    }
    return result;
}

// One fixed physics step: move, sphere pairs through the grid, then walls (last, so nothing is
// drawn outside the window)
static void app_simulation_step(borrows massive app_simulation* self)
{
    u64 start = util_clock_ns();
    core_spheres_view view = core_spheres_get_view(&self->spheres);
    core_physics_move(&view, STEP_DT);
    (void)core_grid_resolve_pairs(&self->grid, &view, self->bounds);
    (void)core_physics_resolve_walls(&view, self->bounds);
    self->step_ns += util_clock_ns() - start;
    self->steps += 1;
}

u32 app_simulation_max_n(void)
{
    return MAX_N;
}

app_simulation app_simulation_make(u32 n, data_bounds bounds)
{
    u32 side = app_simulation_clamp_n(n);
    app_simulation result = {
        .spheres = core_spheres_make(cast_u32_to_size_t(side) * side),
        .grid = core_grid_make(1, 1),
        .sprites = core_sprite_batch_make(),
        .hud = app_hud_pod(),
        .fps = app_fps_pod(0),
        .bounds = bounds,
        .n = side,
        .requested_n = side,
        .radius = 0.0f,
        .unsimulated_seconds = 0.0,
        .last_time_ns = 0,
        .frames = 0,
        .steps = 0,
        .step_ns = 0,
        .quit = false,
    };
    if (app_simulation_valid(&result))
    {
        status filled = app_simulation_fill(&result, side);
        if (filled != STATUS_OK)
        {
            UTIL_LOG_ERROR("couldn't set up %" PRIu32 " x %" PRIu32 " bodies: %s", side, side, status_to_string(filled));
        }
    }
    return app_simulation_return(&result);
}

void app_simulation_destroy(borrows massive app_simulation* self)
{
    core_sprite_batch_destroy(&self->sprites);
    core_grid_destroy(&self->grid);
    core_spheres_destroy(&self->spheres);
}

app_simulation app_simulation_return(borrows massive app_simulation* self)
{
    return *self;
}

bool app_simulation_valid(massive const app_simulation* self)
{
    return core_spheres_valid(&self->spheres) && core_grid_valid(&self->grid) && core_sprite_batch_valid(&self->sprites);
}

status app_simulation_status(massive const app_simulation* self)
{
    status result = core_spheres_status(&self->spheres);
    if (result == STATUS_OK)
    {
        result = core_grid_status(&self->grid);
    }
    if (result == STATUS_OK)
    {
        result = core_sprite_batch_status(&self->sprites);
    }
    return result;
}

void app_simulation_handle_event(borrows massive app_simulation* self, data_input_event event)
{
    switch (event.kind)
    {
        case DATA_INPUT_QUIT:
            self->quit = true;
            break;
        case DATA_INPUT_MOUSE_DOWN:
        {
            // Hit-tested against what is on screen: the layout for the n in use
            app_hud_layout layout = app_hud_layout_pod(app_simulation_width(self), self->n,
                                                       cast_size_t_to_u64(core_spheres_count(&self->spheres)));
            app_hud_button button = app_hud_press(&self->hud, &layout, event.x, event.y);
            self->requested_n = app_simulation_next_n(button, self->requested_n);
            break;
        }
        case DATA_INPUT_MOUSE_UP:
            app_hud_release(&self->hud);
            break;
        case DATA_INPUT_RESIZE:
            // An empty window (e.g. minimized) would pile every sphere into one 1 x 1 grid cell,
            // making collisions O(n²): keep the last real size instead
            if (event.x > 0.0f && event.y > 0.0f)
            {
                self->bounds = data_bounds_pod(0.0f, 0.0f, event.x, event.y);
                (void)app_simulation_size_grid(self);
            }
            break;
        default:
            break;
    }
}

status app_simulation_apply_request(borrows massive app_simulation* self)
{
    if (self->requested_n == self->n)
    {
        return STATUS_OK;
    }
    u32 side = self->requested_n;
    u64 bodies = cast_u32_to_u64(side) * cast_u32_to_u64(side);
    status result = core_spheres_resize(&self->spheres, cast_u32_to_size_t(side) * side);
    if (result != STATUS_OK)
    {
        UTIL_LOG_WARN("couldn't make %" PRIu64 " bodies, keeping %" PRIu32 " x %" PRIu32 ": %s", bodies, self->n,
                      self->n, status_to_string(result));
        self->requested_n = self->n;
        return result;
    }
    self->n = side;
    result = app_simulation_fill(self, side);
    if (result == STATUS_OK)
    {
        UTIL_LOG_INFO("n = %" PRIu32 ": %" PRIu64 " bodies", side, bodies);
    }
    else
    {
        UTIL_LOG_WARN("set up %" PRIu64 " bodies only partly: %s", bodies, status_to_string(result));
    }
    return result;
}

void app_simulation_advance(borrows massive app_simulation* self, f64 seconds)
{
    self->unsimulated_seconds += seconds > 0.0 ? seconds : 0.0;
    u32 steps = 0;
    while (self->unsimulated_seconds >= STEP_SECONDS && steps < MAX_STEPS_PER_FRAME)
    {
        app_simulation_step(self);
        self->unsimulated_seconds -= STEP_SECONDS;
        steps += 1;
    }
    // Behind by more than a frame's worth of steps: drop it rather than fall further behind
    if (self->unsimulated_seconds >= STEP_SECONDS)
    {
        self->unsimulated_seconds = 0.0;
    }
}

// Everything drawn for one frame, without presenting it
static void app_simulation_draw(borrows massive app_simulation* self, borrows massive core_window* window)
{
    core_window_clear(window, data_rgba_pod(16, 16, 24, 255));
    // After a failed prepare (out of memory) the batch still holds the old count: draw no stale
    // sprites then; the next successful prepare (e.g. the periodic sort) brings them back
    if (core_sprite_batch_count(&self->sprites) == core_spheres_count(&self->spheres))
    {
        core_spheres_const_view read = core_spheres_get_const_view(&self->spheres);
        core_sprite_batch_update(&self->sprites, &read);
        core_sprite_batch_view sprites = core_sprite_batch_get_view(&self->sprites);
        core_window_draw_sprites(window, &sprites);
    }
    u64 bodies = cast_size_t_to_u64(core_spheres_count(&self->spheres));
    app_hud_layout layout = app_hud_layout_pod(app_simulation_width(self), self->n, bodies);
    app_hud_draw(&self->hud, &layout, window, self->n, bodies, &self->fps);
}

// Handles every waiting event; false once a quit came
static bool app_simulation_poll(borrows massive app_simulation* self, borrows massive core_window* window)
{
    data_input_event event = data_input_event_pod(DATA_INPUT_NONE, 0.0f, 0.0f);
    while (core_window_poll_event(window, overwrite(&event)))
    {
        app_simulation_handle_event(self, event);
    }
    return !self->quit;
}

// Seconds on the window's clock since the previous frame; 0 for the first
static f64 app_simulation_elapsed_seconds(borrows massive app_simulation* self, u64 now_ns)
{
    if (self->frames == 0)
    {
        self->last_time_ns = now_ns;
    }
    u64 elapsed_ns = now_ns > self->last_time_ns ? now_ns - self->last_time_ns : 0;
    self->last_time_ns = now_ns;
    return cast_u64_to_f64(elapsed_ns) / 1e9;
}

// The physics for seconds of time, then now and then a reorder by grid cell (colors follow their
// spheres, so the vertex buffers are rebuilt)
static void app_simulation_simulate(borrows massive app_simulation* self, f64 seconds)
{
    app_simulation_advance(self, seconds);
    if (self->frames % SORT_EVERY_FRAMES == SORT_EVERY_FRAMES - 1)
    {
        core_spheres_view view = core_spheres_get_view(&self->spheres);
        if (core_grid_sort_spheres(&self->grid, &view, self->bounds))
        {
            core_spheres_const_view read = core_spheres_get_const_view(&self->spheres);
            (void)core_sprite_batch_prepare(&self->sprites, &read);
        }
    }
}

bool app_simulation_frame(borrows massive app_simulation* self, borrows massive core_window* window)
{
    // Closing: no point stepping or drawing a frame nobody will see
    if (!app_simulation_poll(self, window))
    {
        return false;
    }
    (void)app_simulation_apply_request(self);
    u64 now = core_window_time_ns(window);
    if (self->frames == 0)
    {
        self->fps = app_fps_pod(now);
    }
    f64 seconds = app_simulation_elapsed_seconds(self, now);

    // Simulate, draw and present, each timed in real time for the HUD's timing line
    u64 steps_before = self->steps;
    u64 physics_start = util_clock_ns();
    app_simulation_simulate(self, seconds);
    u64 draw_start = util_clock_ns();
    app_simulation_draw(self, window);
    u64 present_start = util_clock_ns();
    core_window_present(window);
    u64 present_end = util_clock_ns();

    // This frame's sample shows in the HUD from the next published window on
    app_fps_frame(&self->fps, now,
                  app_fps_sample_pod(draw_start - physics_start, present_start - draw_start,
                                     present_end - present_start, cast_u64_to_u32(self->steps - steps_before)));
    self->frames += 1;
    return true;
}

u32 app_simulation_n(massive const app_simulation* self)
{
    return self->n;
}

u32 app_simulation_requested_n(massive const app_simulation* self)
{
    return self->requested_n;
}

size_t app_simulation_count(massive const app_simulation* self)
{
    return core_spheres_count(&self->spheres);
}

data_bounds app_simulation_bounds(massive const app_simulation* self)
{
    return self->bounds;
}

app_hud_button app_simulation_pressed(massive const app_simulation* self)
{
    return app_hud_pressed(&self->hud);
}

u64 app_simulation_frames(massive const app_simulation* self)
{
    return self->frames;
}

u64 app_simulation_steps(massive const app_simulation* self)
{
    return self->steps;
}

u64 app_simulation_step_ns(massive const app_simulation* self)
{
    return self->step_ns;
}

bool app_simulation_quit_requested(massive const app_simulation* self)
{
    return self->quit;
}

core_spheres_const_view app_simulation_spheres(massive const app_simulation* self)
{
    return core_spheres_get_const_view(&self->spheres);
}
