#ifndef APP_HUD_H
#define APP_HUD_H

#include <stdbool.h>
#include <stddef.h>

#include "app/fps.h"
#include "core/window.h"
#include "data/rgba.h"
#include "data/triangle.h"
#include "numbers.h"
#include "span.h"
#include "workshopc_tags.h"

// The overlay: FPS at the top left (yellow) with a timing line under it, "< < n² > >" buttons at
// the top middle (outer: / 10 and * 10, inner: - 1 and + 1), and the number of bodies at the top
// right ("10 000 000 bodies"). Layout and button state are pure, so they are tested without a
// window; app_hud_draw sends them to the window.

typedef enum app_hud_button
{
    APP_HUD_BUTTON_NONE,
    APP_HUD_BUTTON_LESS,       // the inner left triangle: n - 1
    APP_HUD_BUTTON_MORE,       // the inner right triangle: n + 1
    APP_HUD_BUTTON_DIVIDE,     // the outer left triangle: n / 10
    APP_HUD_BUTTON_MULTIPLY    // the outer right triangle: n * 10
} app_hud_button;

// Where everything goes for one window width, n and body count
typedef struct app_hud_layout
{
    data_triangle less;
    data_triangle more;
    data_triangle divide;
    data_triangle multiply;
    f32 number_x;     // n, at the text scale
    f32 number_y;
    f32 exponent_x;   // the small raised "2"
    f32 exponent_y;
    f32 fps_x;
    f32 fps_y;
    f32 timing_x;     // the timing line under the FPS, at half the text scale
    f32 timing_y;
    f32 count_x;      // the body count, right-aligned
    f32 count_y;
    f32 text_scale;
} app_hud_layout;

// Which button is held down
typedef struct app_hud
{
    app_hud_button pressed;
} app_hud;

// The layout for a window width_px wide showing n and bodies
app_hud_layout app_hud_layout_pod(f32 width_px, u32 n, u64 bodies);
// Nothing pressed
app_hud app_hud_pod(void);

// A mouse press at (x, y): marks and returns the button under it (each has a few pixels of slack
// around its triangle), or APP_HUD_BUTTON_NONE
app_hud_button app_hud_press(MUTABLE REF app_hud* self, REF const app_hud_layout* layout, f32 x, f32 y);
// The mouse went up: nothing is pressed any more
void app_hud_release(MUTABLE REF app_hud* self);
app_hud_button app_hud_pressed(REF const app_hud* self);

// Writes value with a space between every three digits ("10 000 000") and a closing '\0'.
// Returns the length without the '\0'; 0 when out is too small (27 chars fit any u64)
size_t app_hud_format_count(u64 value, char_span out);

data_rgba app_hud_fps_color(void);
data_rgba app_hud_button_color(bool pressed);

// Draws the overlay for this frame
void app_hud_draw(REF const app_hud* self, REF const app_hud_layout* layout, MUTABLE REF core_window* window,
                  u32 n, u64 bodies, REF const app_fps* fps);

#endif // APP_HUD_H
