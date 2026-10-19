#ifndef DATA_TRIANGLE_H
#define DATA_TRIANGLE_H

#include <stdbool.h>

#include "numbers.h"

// A triangle in window coordinates, e.g. a HUD button
typedef struct data_triangle
{
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;
    f32 x2;
    f32 y2;
} data_triangle;

// { (x0, y0), (x1, y1), (x2, y2) }
static inline data_triangle data_triangle_pod(f32 x0, f32 y0, f32 x1, f32 y1, f32 x2, f32 y2)
{
    return (data_triangle){ .x0 = x0, .y0 = y0, .x1 = x1, .y1 = y1, .x2 = x2, .y2 = y2 };
}

// Twice the signed area of (a, b, p): positive on one side of the line a -> b, negative on the other
static inline f32 data_triangle_edge(f32 ax, f32 ay, f32 bx, f32 by, f32 px, f32 py)
{
    return (bx - ax) * (py - ay) - (by - ay) * (px - ax);
}

// Whether (x, y) lies inside the triangle or on its edge, for either winding order
static inline bool data_triangle_contains(data_triangle triangle, f32 x, f32 y)
{
    f32 e0 = data_triangle_edge(triangle.x0, triangle.y0, triangle.x1, triangle.y1, x, y);
    f32 e1 = data_triangle_edge(triangle.x1, triangle.y1, triangle.x2, triangle.y2, x, y);
    f32 e2 = data_triangle_edge(triangle.x2, triangle.y2, triangle.x0, triangle.y0, x, y);
    bool any_negative = e0 < 0.0f || e1 < 0.0f || e2 < 0.0f;
    bool any_positive = e0 > 0.0f || e1 > 0.0f || e2 > 0.0f;
    return !(any_negative && any_positive);
}

#endif // DATA_TRIANGLE_H
