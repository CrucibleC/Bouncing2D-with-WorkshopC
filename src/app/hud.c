#include "app/hud.h"

#include <inttypes.h>
#include <stdio.h>

#include "workshopc_tags.h"

// Room for any HUD text: the timing line is the longest (about 60 characters with large values)
#define APP_HUD_TEXT_SIZE 96

static const f32 TEXT_SCALE = 2.0f;    // 16-pixel characters
static const f32 MARGIN = 10.0f;       // from the window's edges
static const f32 BUTTON_SIZE = 16.0f;  // the triangles, as tall as the text
static const f32 GAP = 10.0f;          // between two triangles, and between a triangle and the number
static const f32 RAISE = 4.0f;         // how far the exponent sits above the number's top
static const f32 HIT_SLACK = 4.0f;     // extra pixels around a triangle that still count as a press
static const size_t BODIES_SUFFIX_LENGTH = 7;   // " bodies"

static size_t app_hud_digit_count(u64 value)
{
    size_t digits = 1;
    u64 remaining = value;
    while (remaining >= 10)
    {
        remaining /= 10;
        digits += 1;
    }
    return digits;
}

// The length of value with its group spaces: "10 000 000" is 10
static size_t app_hud_grouped_length(u64 value)
{
    size_t digits = app_hud_digit_count(value);
    return digits + (digits - 1) / 3;
}

// Whether (x, y) is inside the triangle's bounding box widened by HIT_SLACK
static bool app_hud_hits(data_triangle triangle, f32 x, f32 y)
{
    f32 left = triangle.x0 < triangle.x1 ? triangle.x0 : triangle.x1;
    left = left < triangle.x2 ? left : triangle.x2;
    f32 right = triangle.x0 > triangle.x1 ? triangle.x0 : triangle.x1;
    right = right > triangle.x2 ? right : triangle.x2;
    f32 top = triangle.y0 < triangle.y1 ? triangle.y0 : triangle.y1;
    top = top < triangle.y2 ? top : triangle.y2;
    f32 bottom = triangle.y0 > triangle.y1 ? triangle.y0 : triangle.y1;
    bottom = bottom > triangle.y2 ? bottom : triangle.y2;
    return x >= left - HIT_SLACK && x <= right + HIT_SLACK && y >= top - HIT_SLACK && y <= bottom + HIT_SLACK;
}

// A button pointing left (tip on the left, at middle height) whose box starts at left
static data_triangle app_hud_left_triangle(f32 left, f32 top)
{
    return data_triangle_pod(left, top + BUTTON_SIZE * 0.5f, left + BUTTON_SIZE, top, left + BUTTON_SIZE,
                             top + BUTTON_SIZE);
}

// A button pointing right whose box starts at left
static data_triangle app_hud_right_triangle(f32 left, f32 top)
{
    return data_triangle_pod(left, top, left + BUTTON_SIZE, top + BUTTON_SIZE * 0.5f, left, top + BUTTON_SIZE);
}

app_hud_layout app_hud_layout_pod(f32 width_px, u32 n, u64 bodies)
{
    f32 glyph = core_window_glyph_size() * TEXT_SCALE;
    f32 number_width = cast_size_t_to_f32(app_hud_digit_count(cast_u32_to_u64(n))) * glyph;
    f32 exponent_width = core_window_glyph_size();   // the exponent is drawn at half the text scale
    f32 side_width = BUTTON_SIZE + GAP + BUTTON_SIZE + GAP;   // two triangles and the gap to the number
    f32 group_width = side_width + number_width + exponent_width + side_width;
    f32 left = (width_px - group_width) * 0.5f;
    f32 top = MARGIN;
    f32 less_left = left + BUTTON_SIZE + GAP;
    f32 number_x = less_left + BUTTON_SIZE + GAP;
    f32 exponent_x = number_x + number_width;
    f32 more_left = exponent_x + exponent_width + GAP;
    f32 multiply_left = more_left + BUTTON_SIZE + GAP;
    f32 count_length = cast_size_t_to_f32(app_hud_grouped_length(bodies) + BODIES_SUFFIX_LENGTH);
    return (app_hud_layout){
        .less = app_hud_left_triangle(less_left, top),
        .more = app_hud_right_triangle(more_left, top),
        .divide = app_hud_left_triangle(left, top),
        .multiply = app_hud_right_triangle(multiply_left, top),
        .number_x = number_x,
        .number_y = top,
        .exponent_x = exponent_x,
        .exponent_y = top - RAISE,
        .fps_x = MARGIN,
        .fps_y = MARGIN,
        .timing_x = MARGIN,
        .timing_y = MARGIN + glyph + 6.0f,   // under the FPS, with a small gap
        .count_x = width_px - MARGIN - count_length * glyph,
        .count_y = MARGIN,
        .text_scale = TEXT_SCALE,
    };
}

app_hud app_hud_pod(void)
{
    return (app_hud){ .pressed = APP_HUD_BUTTON_NONE };
}

app_hud_button app_hud_press(MUTABLE REF app_hud* self, REF const app_hud_layout* layout, f32 x, f32 y)
{
    app_hud_button button = APP_HUD_BUTTON_NONE;
    if (app_hud_hits(layout->less, x, y))
    {
        button = APP_HUD_BUTTON_LESS;
    }
    else if (app_hud_hits(layout->more, x, y))
    {
        button = APP_HUD_BUTTON_MORE;
    }
    else if (app_hud_hits(layout->divide, x, y))
    {
        button = APP_HUD_BUTTON_DIVIDE;
    }
    else if (app_hud_hits(layout->multiply, x, y))
    {
        button = APP_HUD_BUTTON_MULTIPLY;
    }
    self->pressed = button;
    return button;
}

void app_hud_release(MUTABLE REF app_hud* self)
{
    self->pressed = APP_HUD_BUTTON_NONE;
}

app_hud_button app_hud_pressed(REF const app_hud* self)
{
    return self->pressed;
}

size_t app_hud_format_count(u64 value, char_span out)
{
    size_t length = app_hud_grouped_length(value);
    if (out.data == NULL || out.size < length + 1)
    {
        if (out.data != NULL && out.size > 0)
        {
            out.data[0] = '\0';
        }
        return 0;
    }
    // Fill from the end: a digit at a time, a space before every completed group of three
    size_t at = length;
    out.data[at] = '\0';
    size_t digits = 0;
    u64 remaining = value;
    do
    {
        if (digits > 0 && digits % 3 == 0)
        {
            at -= 1;
            out.data[at] = ' ';
        }
        at -= 1;
        out.data[at] = "0123456789"[remaining % 10];
        remaining /= 10;
        digits += 1;
    } while (remaining > 0);
    return length;
}

data_rgba app_hud_fps_color(void)
{
    return data_rgba_pod(255, 255, 0, 255);
}

// n, its exponent and the body count
static data_rgba app_hud_text_color(void)
{
    return data_rgba_pod(255, 255, 255, 255);
}

data_rgba app_hud_button_color(bool pressed)
{
    if (pressed)
    {
        return data_rgba_pod(255, 140, 0, 255);
    }
    return data_rgba_pod(200, 200, 200, 255);
}

void app_hud_draw(REF const app_hud* self, REF const app_hud_layout* layout, MUTABLE REF core_window* window,
                  u32 n, u64 bodies, REF const app_fps* fps)
{
    char text[APP_HUD_TEXT_SIZE] = { 0 };
    char_span text_span = char_span_pod(text, sizeof text);
    char grouped[APP_HUD_TEXT_SIZE] = { 0 };
    char_span grouped_span = char_span_pod(grouped, sizeof grouped);
    char exponent[2] = { '2', '\0' };
    char_span exponent_span = char_span_pod(exponent, sizeof exponent);

    (void)snprintf(text_span.data, text_span.size, "FPS %.0f", cast_f32_to_f64(app_fps_value(fps)));
    core_window_draw_text(window, layout->fps_x, layout->fps_y, layout->text_scale, char_const_span_pod(text_span),
                          app_hud_fps_color());
    (void)snprintf(text_span.data, text_span.size, "physics %.1f ms  draw %.1f ms  present %.1f ms  %.1f steps",
                   cast_f32_to_f64(app_fps_physics_ms(fps)), cast_f32_to_f64(app_fps_draw_ms(fps)),
                   cast_f32_to_f64(app_fps_present_ms(fps)), cast_f32_to_f64(app_fps_steps(fps)));
    core_window_draw_text(window, layout->timing_x, layout->timing_y, layout->text_scale * 0.5f,
                          char_const_span_pod(text_span), app_hud_fps_color());

    core_window_draw_triangle(window, layout->divide, app_hud_button_color(self->pressed == APP_HUD_BUTTON_DIVIDE));
    core_window_draw_triangle(window, layout->less, app_hud_button_color(self->pressed == APP_HUD_BUTTON_LESS));
    (void)snprintf(text_span.data, text_span.size, "%" PRIu32, n);
    core_window_draw_text(window, layout->number_x, layout->number_y, layout->text_scale,
                          char_const_span_pod(text_span), app_hud_text_color());
    core_window_draw_text(window, layout->exponent_x, layout->exponent_y, layout->text_scale * 0.5f,
                          char_const_span_pod(exponent_span), app_hud_text_color());
    core_window_draw_triangle(window, layout->more, app_hud_button_color(self->pressed == APP_HUD_BUTTON_MORE));
    core_window_draw_triangle(window, layout->multiply,
                              app_hud_button_color(self->pressed == APP_HUD_BUTTON_MULTIPLY));

    (void)app_hud_format_count(bodies, grouped_span);
    (void)snprintf(text_span.data, text_span.size, "%s bodies", grouped_span.data);
    core_window_draw_text(window, layout->count_x, layout->count_y, layout->text_scale, char_const_span_pod(text_span),
                          app_hud_text_color());
}
