# src

The project's code. Folder names become name prefixes: `src/core/timer.h` declares `core_timer_...` names, and files directly in `src` have no prefix.

## Where code goes

| Where | Holds | May use |
|-------|-------|---------|
| top of `src` | Groundwork with no project knowledge that almost every module needs | nothing in the project |
| `util/` | Code that would work unchanged in another project | top level |
| `data/` | What the project's things *are*: pods and enums, plus small pure functions on them. No raii structs, no allocation | `util/`, top level |
| `core/` | What the things *do*: systems, infrastructure, anything that owns resources | `data/`, `util/`, top level |
| `app/` | The top layer that orchestrates everything | everything |

- **Never include upward.** Modules in the same folder may use each other, as long as there are no cycles.
- **Move something to the top of `src`** when most modules use it and it knows nothing about the project.
- **`main.c` calls only into `app/`.**

## Modules

- `memory_block.h`: `memory_block`, the raii owner of all heap memory, and the only module that calls `malloc`/`free`.
- `status.h`: `status`, the app-wide codes for exceptional failures, and `status_to_string` for printing them.
- `span.h`: `char_span` and `char_const_span`, spans of the basic types.
- `compiler.h`: compiler-specific attributes behind macros, e.g. `PRINTF_FORMAT` (`gnu_printf` on MinGW, so `%zu` and the other C99 formats are checked there too).
- `numbers.h`: the number types `u8` to `i64`, `f32` and `f64`, and the clamping `cast_<from>_to_<to>` functions between them and `size_t` (never wrap; NaN to integers is 0).
