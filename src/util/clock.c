// clock_gettime is POSIX, hidden by -std=c11 unless asked for before any system header
#if !defined(_WIN32)
#define _POSIX_C_SOURCE 200809L
#endif

#include "util/clock.h"

#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#else
#include <time.h>
#endif

#if defined(_WIN32)

u64 util_clock_ns(void)
{
    LARGE_INTEGER frequency = { 0 };
    LARGE_INTEGER counter = { 0 };
    (void)QueryPerformanceFrequency(&frequency);
    (void)QueryPerformanceCounter(&counter);
    u64 ticks = cast_i64_to_u64(counter.QuadPart);
    u64 per_second = cast_i64_to_u64(frequency.QuadPart);
    if (per_second == 0)
    {
        return 0;
    }
    // Split, so ticks * 1e9 can't overflow
    return ticks / per_second * 1000000000ULL + ticks % per_second * 1000000000ULL / per_second;
}

#else

u64 util_clock_ns(void)
{
    struct timespec now = { 0 };
    (void)clock_gettime(CLOCK_MONOTONIC, &now);
    return cast_i64_to_u64((i64)now.tv_sec) * 1000000000ULL + cast_i64_to_u64((i64)now.tv_nsec);
}

#endif
