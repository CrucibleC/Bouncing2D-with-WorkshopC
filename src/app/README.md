# app

The layer that orchestrates everything: the project's logic at the top level. `main.c` calls only into this folder.

Names here start with `app_`. May use: everything.

## Modules

- `app.h`: `app_run`, the program. It lists the subsystems in start order (`util_log_subsystem()`, `util_random_subsystem()`, `core_window_subsystem()`), starts them, makes a 1280 × 720 `core_window` and runs an `app_simulation` in it until it quits, then shuts down what started. With the mock window (every local build) it is a headless benchmark: n = 100 for the mock's 600 frames, then one line with ms per frame and per physics step. `main.c` only calls it.
- `fps.h`: `app_fps`, frames per second and per-frame averages of an `app_fps_sample` (physics, draw and present ms, steps), over half-second windows of a nanosecond clock.
- `hud.h`: the overlay. `app_hud_layout_pod(width, n, bodies)` places FPS (top left, yellow) with a timing line under it (physics, draw and present ms, steps per frame), the `◀ ◀ n² ▶ ▶` buttons (top middle; outer ÷10 and ×10, inner −1 and +1; the "2" is half-size text raised at n's top right) and "10 000 000 bodies" (top right). `app_hud` holds the pressed button (`app_hud_press` hit-tests with a few pixels of slack, `app_hud_release` on mouse up; drawn in another color while held). `app_hud_format_count` groups digits by three. Pure apart from `app_hud_draw`.
- `simulation.h`: `app_simulation` (raii), the orchestrator. Owns `core_spheres`, `core_grid`, `core_sprite_batch`, the HUD, FPS, n (1 to `app_simulation_max_n()` = 1000) and the bounds. A frame (`app_simulation_frame`): handle every event (buttons only request a new n: ÷10 rounded down, −1, +1, ×10, kept within 1 to 1000), apply the request (new lattice, sprites and grid; a failure keeps the old n), fixed 1/120 s steps from the window's clock (at most 8 per frame, the rest dropped), a spatial sort every 30 frames, then draw and present, each part timed with `util_clock_ns` for the HUD. Returns false once a quit arrived.
