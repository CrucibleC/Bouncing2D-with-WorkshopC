#ifndef CORE_WINDOW_MOCK_H
#define CORE_WINDOW_MOCK_H

#include <stdbool.h>
#include <stddef.h>

#include "core/window.h"
#include "data/input_event.h"
#include "numbers.h"
#include "workshopc_tags.h"

// Extra functions of the headless window (window_mock.c), for tests and the local benchmark.
// Only builds without SDL have them.
//
// The mock's clock advances one 60 Hz frame per present. It sends a quit event on its own after
// its frame limit (CORE_WINDOW_MOCK_DEFAULT_FRAMES by default), so the headless app ends.

// What the last presented frame drew
typedef struct core_window_mock_stats
{
    u64 frames;         // frames presented so far
    size_t sprites;     // sprites in the last presented frame
    size_t triangles;   // triangles in the last presented frame
    size_t texts;       // text strings in the last presented frame
    u64 clears;         // clears so far
} core_window_mock_stats;

// { frames, sprites, triangles, texts, clears }
core_window_mock_stats core_window_mock_stats_pod(u64 frames, size_t sprites, size_t triangles, size_t texts,
                                                  u64 clears);

// Queues an event for core_window_poll_event; false when the queue (64 events) is full
bool core_window_mock_push_event(MUTABLE REF core_window* self, data_input_event event);
core_window_mock_stats core_window_mock_get_stats(REF const core_window* self);
// After this many presented frames the mock sends a quit event; 0 never does
void core_window_mock_set_frame_limit(MUTABLE REF core_window* self, u64 frames);
// The frame limit a new mock window starts with
u64 core_window_mock_default_frames(void);

#endif // CORE_WINDOW_MOCK_H
