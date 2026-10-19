#ifndef DATA_RGBA_H
#define DATA_RGBA_H

#include "numbers.h"

// A color with alpha, one byte per channel
typedef struct data_rgba
{
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} data_rgba;

// { .r = r, .g = g, .b = b, .a = a }
static inline data_rgba data_rgba_pod(u8 r, u8 g, u8 b, u8 a)
{
    return (data_rgba){ .r = r, .g = g, .b = b, .a = a };
}

#endif // DATA_RGBA_H
