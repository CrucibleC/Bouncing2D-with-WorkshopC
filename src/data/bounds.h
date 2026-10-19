#ifndef DATA_BOUNDS_H
#define DATA_BOUNDS_H

#include "numbers.h"

// An axis-aligned box: x from min_x to max_x, y from min_y to max_y. A window is
// (0, 0, width, height)
typedef struct data_bounds
{
    f32 min_x;
    f32 min_y;
    f32 max_x;
    f32 max_y;
} data_bounds;

// { .min_x = min_x, .min_y = min_y, .max_x = max_x, .max_y = max_y }
static inline data_bounds data_bounds_pod(f32 min_x, f32 min_y, f32 max_x, f32 max_y)
{
    return (data_bounds){ .min_x = min_x, .min_y = min_y, .max_x = max_x, .max_y = max_y };
}

#endif // DATA_BOUNDS_H
