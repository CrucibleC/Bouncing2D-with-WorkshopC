# tests

HammerC tests. Test files mirror the layout of `src/`: the tests for `src/core/timer.c` go in `tests/core/timer.test.c`. Modules at the top of `src` are tested in `tests/root/`, since a `.test.c` directly in `tests/` belongs to no runner.

- **One runner per top-level folder:** `../HammerC/hammerc.py` turns every `*.test.c` under `tests/<folder>/` into one executable, `tests_<folder>`, e.g. `tests_util`. Its generated code lands in `tests/<folder>/generated/`, which is not committed.
- **The build finds new test files by itself.** The runners link `bouncing2d_lib`, so `src/` is compiled once and shared with the app.
- **Code that can't run in CI,** e.g. anything needing a window, a GPU or audio, gets a `<module>.test.md` note where its test would go. The note says why there's no test, and what to check by hand.
- **Tests may use any layer** of `src`.
- **WorkshopC doesn't check `tests/`.** It is listed in `third_party_includes` in `workshopc.yaml`.
- **Run them** with `python build.py --windows --test` (no `--windows` on Linux), or run one runner directly, e.g. `build/windows/tests_util.exe --verbose`. `--test` runs them twice: in the normal build, then in a sanitized Debug build in `build/<platform>-sanitize` (`BOUNCING2D_SANITIZE`: ASan, LeakSanitizer and UBSan on Linux; on MinGW, which has no sanitizer runtimes, undefined behavior traps and the runner shows as crashed).
- **CI** (`.github/workflows/ci.yml`) builds and runs every runner on Linux (gcc) and Windows (MinGW-w64 UCRT64 gcc) on every push and pull request, with HammerC checked out from github.com/CrucibleC/HammerC at a pinned commit. The runners run with `--quiet`, so a failing job shows only the failed checks. CI's Debug build is sanitized too, so a leak or undefined behavior fails the job.

## Tests

- `app/app.test.c`: `app_run` runs the headless benchmark and writes `tests_app.log` next to the test runner (removed afterwards).
- `app/fps.test.c`: `app_fps` at 60 and 20 fps, before the first half second, sample averages and their reset, a clock going back.
- `app/hud.test.c`: the layout's positions, button hit tests on all four buttons (inside, the slack, between, outside) and release, digit grouping (0 to `UINT64_MAX`, a too-small buffer), colors, what `app_hud_draw` sends to the window.
- `app/simulation.test.c`: `app_simulation` on the mock window: n² bodies, n clamped, the buttons (more, less stopping at 1, ×10, ÷10 down to 1, ×10 capped at 1000, pressed until mouse up), resize (an empty one is ignored), fixed steps and the 8-step cap, 120 frames staying inside the window, quit.
- `core/collision.test.c`: walls (each side, inside, inward speed kept, corner, wider than the box, bad index) and pairs (equal head-on swap, momentum and energy kept, lighter moves more, separating, apart or touching, coincident centers, zero radius, bad indices).
- `core/grid.test.c`: `core_grid_size_for`, make/resize/copy/move, a pair in four shared cells resolved once, pairs across a border, spheres outside the bounds, a brute-force O(n²) comparison on 50 separate pairs, growth to 1000 spheres, no spheres; `core_grid_sort_spheres` puts spheres in cell order and keeps each one's values together.
- `core/physics.test.c`: `core_physics_move` with dt, `core_physics_resolve_walls` over several spheres, no spheres.
- `core/spawn.test.c`: the largest radius, random radii spread over 0.5 to 1 of it, a 3 × 3 lattice's centers, radius, speeds and alpha, 20 × 20 in 1280 × 720 without overlaps and inside, a wrong count rejected.
- `core/spheres.test.c`: `core_spheres`: make and resize (up, down, same stride) zero everything, a too-big resize changes nothing, array alignment and spacing, independent arrays, `get`, copy/move, count 0, views going stale after resize, move and destroy (empty views never are).
- `core/sprite_batch.test.c`: quad corners, colors, uv, indices, `update`, the minimum radius, a count mismatch, 10 000 spheres, the circle texture's alpha.
- `core/window_mock.test.c`: the mock window: size and headless, events in order and resize, the 64-event queue, the quit after the frame limit (once), per-frame draw statistics, the 60 Hz fake clock.
- `data/bounds.test.c`: `data_bounds_pod`.
- `data/input_event.test.c`: `data_input_event_pod`.
- `data/rgba.test.c`: `data_rgba_pod`.
- `data/sphere.test.c`: `data_sphere_pod`.
- `data/triangle.test.c`: `data_triangle_pod`, `data_triangle_edge`, `data_triangle_contains`.
- `root/memory_block.test.c`: zeroed make, growing keeps old contents and zeroes the new part, shrink then grow, failed resize, move, copy.
- `root/numbers.test.c`: every `cast_<from>_to_<to>` at the edges of every type; its expectations were generated with exact arithmetic.
- `root/span.test.c`: `char_span` and `char_const_span`.
- `util/clock.test.c`: `util_clock_ns` never goes back and does move forward.
- `util/dynamic_array.test.c`: `util_dynamic_array_resize`.
- `util/fs.test.c`: `util_fs_...`, inside `fs_test_tmp/` in the working directory, removed afterwards.
- `util/log.test.c`: `util_log_...`, writing to `log_test_tmp/` in the working directory, removed afterwards.
- `util/random.test.c`: seeding, ranges (including the full `i32` range and swapped bounds), even spread; fixed seeds, so deterministic.
- `util/singleton.test.c`: `util_singleton_subsystem` start and shutdown order, a failure shuts down only what started, NULL parts, shutdown twice, empty spans.
- `util/string.test.c`: `util_string`.
