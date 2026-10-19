# util

Things with no tie to the project's theme: generic, and useful everywhere. Almost like an internal standard library.

- **A module belongs here only if it would work unchanged in another project.**
- **Once two or more modules share a kind, give them a subfolder,** e.g. `util/text/`, so the name prefix says something.

Names here start with `util_`. May use: the top of `src` only.

## Modules

- `clock.h`: `util_clock_ns`, a monotonic nanosecond clock (QueryPerformanceCounter on Windows, `clock_gettime(CLOCK_MONOTONIC)` elsewhere), for measuring how long work takes.
- `dynamic_array.h`: `util_dynamic_array_resize`, the growth policy shared by every dynamic array (double, minimum 8, never below the needed size).
- `fs.h`: `util_fs_...`, whole-file operations: exists, create (with parent folders), write, append, read into a `util_string`, remove; and `util_fs_executable_path` / `util_fs_executable_folder`. Platform calls stay in `fs.c` (`#if defined(_WIN32)`).
- `log.h`: `util_log_subsystem()` (init: log file named after the executable, next to it), `UTIL_LOG_DEBUG/INFO/WARN/ERROR(...)` macros over `util_log_write`, printf-style lines with time, level and the caller's `file:line`, to the terminal and/or a file (`util_log_set_terminal`, `util_log_set_file`, `util_log_set_min_level`). Default: terminal only.
- `random.h`: `util_random_subsystem()` (init: seed from the clock, logged), `util_random_seed`, `util_random_int` (inclusive, unbiased) and `util_random_float`, from one global PCG32 generator: same seed, same numbers on every platform.
- `singleton.h`: `util_singleton_subsystem`, a module's init and shutdown paired with the init's result, and `util_singleton_subsystem_init_all` (in order, stops at the first failure) / `util_singleton_subsystem_shutdown_all` (reverse, only what started); see the static-raii skill.
- `string.h`: `util_string`, a raii, growable, `'\0'`-terminated string over a `memory_block`.
