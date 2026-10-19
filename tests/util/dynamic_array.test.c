#include <stdint.h>

#include "hammerc.h"

#include "util/dynamic_array.h"

void test_dynamic_array_keeps_capacity_when_size_fits(HammerCtx *t)
{
    CHECK_EQ_UINT(util_dynamic_array_resize(5, 10), 10);
    CHECK_EQ_UINT(util_dynamic_array_resize(10, 10), 10);
    CHECK_EQ_UINT(util_dynamic_array_resize(0, 0), 0);
}

void test_dynamic_array_grows_to_minimum_of_eight(HammerCtx *t)
{
    CHECK_EQ_UINT(util_dynamic_array_resize(1, 0), 8);
    CHECK_EQ_UINT(util_dynamic_array_resize(3, 2), 8);
}

void test_dynamic_array_doubles_capacity(HammerCtx *t)
{
    CHECK_EQ_UINT(util_dynamic_array_resize(9, 8), 16);
    CHECK_EQ_UINT(util_dynamic_array_resize(17, 16), 32);
}

void test_dynamic_array_jumps_to_size_when_doubling_is_not_enough(HammerCtx *t)
{
    CHECK_EQ_UINT(util_dynamic_array_resize(100, 8), 100);
}

void test_dynamic_array_stops_at_size_max_instead_of_overflowing(HammerCtx *t)
{
    CHECK_EQ_UINT(util_dynamic_array_resize(SIZE_MAX, SIZE_MAX / 2 + 1), SIZE_MAX);
    CHECK_EQ_UINT(util_dynamic_array_resize(SIZE_MAX / 2 + 2, SIZE_MAX / 2 + 1), SIZE_MAX);
}
