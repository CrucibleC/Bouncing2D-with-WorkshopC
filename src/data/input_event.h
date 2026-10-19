#ifndef DATA_INPUT_EVENT_H
#define DATA_INPUT_EVENT_H

#include "numbers.h"

// What happened, as the window reports it; independent of SDL
typedef enum data_input_kind
{
    DATA_INPUT_NONE,
    DATA_INPUT_QUIT,         // the window was closed
    DATA_INPUT_MOUSE_DOWN,   // the left mouse button went down at (x, y)
    DATA_INPUT_MOUSE_UP,     // the left mouse button went up at (x, y)
    DATA_INPUT_RESIZE        // the window's drawable size is now x by y
} data_input_kind;

// One input event: mouse events use (x, y) as a position, a resize uses it as the new size
typedef struct data_input_event
{
    data_input_kind kind;
    f32 x;
    f32 y;
} data_input_event;

// { .kind = kind, .x = x, .y = y }
static inline data_input_event data_input_event_pod(data_input_kind kind, f32 x, f32 y)
{
    return (data_input_event){ .kind = kind, .x = x, .y = y };
}

#endif // DATA_INPUT_EVENT_H
