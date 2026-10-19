#ifndef DATA_SPHERE_H
#define DATA_SPHERE_H

#include "data/rgba.h"
#include "numbers.h"

// One sphere's values: position and velocity in the simulation's units, its radius and color.
// core_bodies stores spheres as separate arrays; this is the whole of one sphere, for adding,
// reading back and tests
typedef struct data_sphere
{
    f32 x;
    f32 y;
    f32 vx;
    f32 vy;
    f32 radius;
    data_rgba rgba;
} data_sphere;

// { .x = x, .y = y, .vx = vx, .vy = vy, .radius = radius, .rgba = rgba }
static inline data_sphere data_sphere_pod(f32 x, f32 y, f32 vx, f32 vy, f32 radius, data_rgba rgba)
{
    return (data_sphere){ .x = x, .y = y, .vx = vx, .vy = vy, .radius = radius, .rgba = rgba };
}

#endif // DATA_SPHERE_H
