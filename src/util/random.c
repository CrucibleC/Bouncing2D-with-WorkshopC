#include "util/random.h"

#include <inttypes.h>
#include <stdint.h>
#include <time.h>

#include "util/log.h"

// PCG32 (XSH-RR) by M. E. O'Neill, pcg-random.org: a 64-bit state, 32-bit outputs
static const u64 PCG_MULTIPLIER = 6364136223846793005ULL;
static const u64 PCG_INCREMENT = 1442695040888963407ULL;   // any odd number; fixes the stream
static const u64 LOW_32_BITS = 0xFFFFFFFFULL;

// PCG's documented default state, used until util_random_seed is called
static u64 g_random_state = 0x853C49E6748FEA9BULL;

static u32 util_random_next(void)
{
    u64 old = g_random_state;
    g_random_state = old * PCG_MULTIPLIER + PCG_INCREMENT;
    // Truncating to the low 32 bits is the algorithm, so mask before casting
    u32 xorshifted = cast_u64_to_u32((((old >> 18U) ^ old) >> 27U) & LOW_32_BITS);
    u32 rotation = cast_u64_to_u32(old >> 59U);
    return (xorshifted >> rotation) | (xorshifted << ((0U - rotation) & 31U));
}

void util_random_seed(u64 seed)
{
    g_random_state = 0;
    (void)util_random_next();
    g_random_state += seed;
    (void)util_random_next();
}

static status util_random_init(void)
{
    u64 seed = cast_i64_to_u64((i64)time(NULL));
    util_random_seed(seed);
    UTIL_LOG_INFO("random seed %" PRIu64, seed);
    return STATUS_OK;
}

util_singleton_subsystem util_random_subsystem(void)
{
    return util_singleton_subsystem_pod(util_random_init, NULL);
}

i32 util_random_int(i32 low, i32 high)
{
    i32 min = low < high ? low : high;
    i32 max = low < high ? high : low;
    // At most 2^32 values: fits u64, and is exact in i64
    u64 range = cast_i64_to_u64(cast_i32_to_i64(max) - cast_i32_to_i64(min)) + 1;
    u32 drawn = util_random_next();
    if (range > UINT32_MAX)
    {
        return cast_i64_to_i32(cast_i32_to_i64(min) + cast_u32_to_i64(drawn));
    }
    // Rejecting the lowest (2^32 mod range) draws leaves a multiple of range: no value is favored
    u32 range32 = cast_u64_to_u32(range);
    u32 threshold = (0U - range32) % range32;
    while (drawn < threshold)
    {
        drawn = util_random_next();
    }
    return cast_i64_to_i32(cast_i32_to_i64(min) + cast_u32_to_i64(drawn % range32));
}

f32 util_random_float(f32 low, f32 high)
{
    f32 min = low < high ? low : high;
    f32 max = low < high ? high : low;
    // 24 random bits, exactly representable: a uniform t in [0, 1)
    f32 t = cast_u32_to_f32(util_random_next() >> 8U) * 0x1p-24f;
    // Weighted sum instead of min + (max - min) * t, so max - min can't overflow
    f32 value = min * (1.0f - t) + max * t;
    if (value < min)
    {
        return min;
    }
    if (value > max)
    {
        return max;
    }
    return value;
}
