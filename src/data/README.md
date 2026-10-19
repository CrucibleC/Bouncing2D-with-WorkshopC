# data

What the project's things *are*: pods and enums, plus small pure functions on them. No raii structs and no allocation: anything that owns resources belongs in `core/`.

Names here start with `data_`. May use: `util/` and the top of `src`.

- **Header-only:** `_pod` creators and small pure functions on pods are `static inline` in the header (no `.c` file), so the compiler can inline them in hot loops. Anything bigger gets a header/source pair like every other folder.

## Modules

- `bounds.h`: `data_bounds`, an axis-aligned box (min_x, min_y, max_x, max_y); a window is (0, 0, width, height).
- `input_event.h`: `data_input_event`, one window event (`data_input_kind`: none, quit, mouse down, mouse up, resize) with a position; a resize carries the new width and height instead.
- `rgba.h`: `data_rgba`, a color with alpha, one byte per channel.
- `sphere.h`: `data_sphere`, the whole of one sphere (position, velocity, radius, color), for adding spheres to and reading them back from the sphere storage in `core/`.
- `triangle.h`: `data_triangle`, three corners in window coordinates, with `data_triangle_contains` (either winding order, edges count as inside).
