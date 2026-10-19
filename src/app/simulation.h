#ifndef APP_SIMULATION_H
#define APP_SIMULATION_H

#include <stdbool.h>
#include <stddef.h>

#include "app/fps.h"
#include "app/hud.h"
#include "core/grid.h"
#include "core/spheres.h"
#include "core/sprite_batch.h"
#include "core/window.h"
#include "data/bounds.h"
#include "data/input_event.h"
#include "numbers.h"
#include "raii_delete.h"
#include "status.h"
#include "workshopc_tags.h"

// The running simulation: n * n spheres bouncing in the window, the grid that finds their
// collisions, their vertex buffers and the HUD. One frame (app_simulation_frame):
//   1. handle the window's events: quit, button presses (n / 10, n - 1, n + 1, n * 10), resizes
//   2. apply a requested n: new spheres on an n x n lattice, a matching grid
//   3. advance the physics in fixed 1/120 s steps: move, sphere pairs (grid), walls
//   4. draw: spheres, then the HUD; present
// Steps 3 and 4 are timed (physics, draw, present) for the HUD's timing line.
// Everything runs on the calling thread.
typedef struct app_simulation
{
    PRIVATE core_spheres spheres;
    PRIVATE core_grid grid;
    PRIVATE core_sprite_batch sprites;
    PRIVATE app_hud hud;
    PRIVATE app_fps fps;
    PRIVATE data_bounds bounds;
    PRIVATE u32 n;                     // the lattice side in use: n * n spheres
    PRIVATE u32 requested_n;           // what the buttons asked for; applied at the next frame
    PRIVATE f32 radius;                // the largest radius since the last spawn, for grid sizing
    PRIVATE f64 unsimulated_seconds;   // time not yet covered by a physics step
    PRIVATE u64 last_time_ns;          // the window clock at the previous frame
    PRIVATE u64 frames;
    PRIVATE u64 steps;                 // physics steps taken
    PRIVATE u64 step_ns;               // real time spent in physics steps, for the benchmark
    PRIVATE bool quit;
} app_simulation;

// The largest n the buttons reach: n * n spheres must fit the u32 sphere indices
u32 app_simulation_max_n(void);

// n * n spheres (n clamped to 1 .. max) on a lattice over bounds; invalid when allocation fails
app_simulation app_simulation_make(u32 n, data_bounds bounds);
NO_COPY(app_simulation);
NO_MOVE(app_simulation);
void app_simulation_destroy(MUTABLE REF app_simulation* self);
app_simulation app_simulation_return(MUTABLE REF app_simulation* self);
bool app_simulation_valid(REF const app_simulation* self);
status app_simulation_status(REF const app_simulation* self);

// Reacts to one input event: quit, the n buttons (pressing changes the requested n; the button
// stays highlighted until the mouse goes up) or a resize (new bounds and grid)
void app_simulation_handle_event(MUTABLE REF app_simulation* self, data_input_event event);
// Applies the requested n, if it changed: new spheres and grid. On failure (e.g. out of memory)
// the old spheres stay, the request is dropped and a warning is logged
status app_simulation_apply_request(MUTABLE REF app_simulation* self);
// Runs the physics for seconds of simulated time, in fixed steps (at most 8 per call; time
// beyond that is dropped, so a slow frame can't snowball)
void app_simulation_advance(MUTABLE REF app_simulation* self, f64 seconds);
// One whole frame on window (events, request, physics, draw). Returns false once a quit came, and
// then stops right after the events: that frame isn't stepped, drawn or counted
bool app_simulation_frame(MUTABLE REF app_simulation* self, MUTABLE REF core_window* window);

u32 app_simulation_n(REF const app_simulation* self);
// The n the buttons asked for, applied at the start of the next frame
u32 app_simulation_requested_n(REF const app_simulation* self);
size_t app_simulation_count(REF const app_simulation* self);
data_bounds app_simulation_bounds(REF const app_simulation* self);
app_hud_button app_simulation_pressed(REF const app_simulation* self);
u64 app_simulation_frames(REF const app_simulation* self);
u64 app_simulation_steps(REF const app_simulation* self);
// Real nanoseconds spent in physics steps so far
u64 app_simulation_step_ns(REF const app_simulation* self);
bool app_simulation_quit_requested(REF const app_simulation* self);
// Read-only access to the spheres, e.g. for tests
core_spheres_const_view app_simulation_spheres(REF const app_simulation* self);

#endif // APP_SIMULATION_H
