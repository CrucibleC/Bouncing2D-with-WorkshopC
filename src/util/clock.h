#ifndef UTIL_CLOCK_H
#define UTIL_CLOCK_H

#include "numbers.h"

// Nanoseconds from a monotonic clock: only differences mean anything, and it never goes back.
// For measuring how long work takes, e.g. the headless benchmark
u64 util_clock_ns(void);

#endif // UTIL_CLOCK_H
