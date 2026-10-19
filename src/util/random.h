#ifndef UTIL_RANDOM_H
#define UTIL_RANDOM_H

#include "numbers.h"
#include "util/singleton.h"

// Random numbers from one global PCG32 generator: fast, uniform, and the same sequence on every
// platform for the same seed. Before any util_random_seed call it starts from a fixed seed, so
// unseeded runs and tests are reproducible. Not thread-safe.

// The generator as a subsystem for util_singleton_subsystem_init_all. Its init seeds from the
// clock, so every run differs, and logs the seed so a run can be replayed with util_random_seed.
// Never fails; no shutdown
util_singleton_subsystem util_random_subsystem(void);
// Restarts the sequence: the same seed always gives the same numbers
void util_random_seed(u64 seed);
// A uniformly distributed integer in [low, high], both ends included; swapped bounds are put in order
i32 util_random_int(i32 low, i32 high);
// A uniformly distributed float in [low, high]; swapped bounds are put in order
f32 util_random_float(f32 low, f32 high);

#endif // UTIL_RANDOM_H
