#ifndef CORE_WINDOW_H
#define CORE_WINDOW_H

#include <stdbool.h>
#include <stddef.h>

#include "core/sprite_batch.h"
#include "data/bounds.h"
#include "data/input_event.h"
#include "data/rgba.h"
#include "data/triangle.h"
#include "memory_block.h"
#include "numbers.h"
#include "raii_delete.h"
#include "span.h"
#include "status.h"
#include "util/singleton.h"
#include "workshopc_tags.h"

// The window the simulation draws into. Two implementations share this header:
//   window_sdl.c   a real SDL3 window (CI release builds only, BOUNCING2D_SDL=ON)
//   window_mock.c  a headless stand-in (every local build and every test): no display, a fake
//                  clock, scripted events and draw statistics (core/window_mock.h)
// Nothing here mentions SDL: each implementation defines core_window_impl in its own .c file.
// Coordinates are pixels, (0, 0) at the top left.

typedef struct core_window_impl core_window_impl;   // free struct, defined by the implementation

// Must keep its address (the platform window), so it lives behind its own allocation
typedef struct core_window
{
    PRIVATE memory_block impl;   // one core_window_impl
} core_window;

// The windowing library's setup and teardown (SDL_Init / SDL_Quit), as a subsystem for
// util_singleton_subsystem_init_all; start it before making a window
util_singleton_subsystem core_window_subsystem(void);
// Whether this build has no real window (the mock)
bool core_window_headless(void);
// The size of one text character at scale 1, in pixels
f32 core_window_glyph_size(void);

// A window of width x height pixels; invalid when it can't be made
core_window core_window_make(const char* title, u32 width, u32 height);
NO_COPY(core_window);
NO_MOVE(core_window);
void core_window_destroy(MUTABLE REF core_window* self);
core_window core_window_return(MUTABLE REF core_window* self);
bool core_window_valid(REF const core_window* self);

// Takes the next input event; false when there is none left this frame
bool core_window_poll_event(MUTABLE REF core_window* self, OUTPUT REF data_input_event* event);
// (0, 0, width, height) of the drawable area
data_bounds core_window_bounds(REF const core_window* self);
// The window's clock in nanoseconds: real time, or the mock's fake frame clock
u64 core_window_time_ns(REF const core_window* self);

// Drawing for one frame: clear, draw, then present
void core_window_clear(MUTABLE REF core_window* self, data_rgba color);
void core_window_draw_sprites(MUTABLE REF core_window* self, REF const core_sprite_batch_view* sprites);
void core_window_draw_triangle(MUTABLE REF core_window* self, data_triangle triangle, data_rgba color);
// Text at (x, y), its top left; each character is glyph_size * scale pixels square. The text is
// the characters of the span up to its first '\0' (or its end)
void core_window_draw_text(MUTABLE REF core_window* self, f32 x, f32 y, f32 scale, char_const_span text,
                           data_rgba color);
void core_window_present(MUTABLE REF core_window* self);

#endif // CORE_WINDOW_H
