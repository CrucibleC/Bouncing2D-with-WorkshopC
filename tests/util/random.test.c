#include <float.h>
#include <stdint.h>

#include "hammerc.h"

#include "util/log.h"
#include "util/random.h"

/* Every test seeds first, so the generator's global state never depends on test order.
   Fixed seeds make every check deterministic: these tests can't fail at random. */

#define DRAWS 10000

void test_random_same_seed_gives_same_sequence(HammerCtx *t)
{
    i32 first[16];
    util_random_seed(1234);
    for (int i = 0; i < 16; i++) {
        first[i] = util_random_int(INT32_MIN, INT32_MAX);
    }
    util_random_seed(1234);
    int same = 0;
    for (int i = 0; i < 16; i++) {
        same += util_random_int(INT32_MIN, INT32_MAX) == first[i];
    }
    CHECK_EQ_INT(same, 16);

    util_random_seed(1235);
    int also_same = 0;
    for (int i = 0; i < 16; i++) {
        also_same += util_random_int(INT32_MIN, INT32_MAX) == first[i];
    }
    CHECK(also_same < 16);
}

static void check_int_range(HammerCtx *t, i32 low, i32 high)
{
    i32 min = low < high ? low : high;
    i32 max = low < high ? high : low;
    int outside = 0;
    for (int i = 0; i < DRAWS; i++) {
        i32 value = util_random_int(low, high);
        outside += value < min || value > max;
    }
    CHECK_EQ_INT(outside, 0);
}

void test_random_int_stays_in_range(HammerCtx *t)
{
    util_random_seed(7);
    check_int_range(t, 1, 6);
    check_int_range(t, -10, -3);
    check_int_range(t, -1000, 1000);
    check_int_range(t, 6, 1);                       /* swapped */
    check_int_range(t, INT32_MIN, INT32_MIN + 2);
    check_int_range(t, INT32_MAX - 2, INT32_MAX);
    check_int_range(t, INT32_MIN, INT32_MAX);       /* the full range */
}

void test_random_int_single_value(HammerCtx *t)
{
    util_random_seed(7);
    CHECK_EQ_INT(util_random_int(5, 5), 5);
    CHECK_EQ_INT(util_random_int(INT32_MIN, INT32_MIN), INT32_MIN);
    CHECK_EQ_INT(util_random_int(INT32_MAX, INT32_MAX), INT32_MAX);
}

void test_random_int_hits_every_value_evenly(HammerCtx *t)
{
    int counts[6] = { 0 };
    util_random_seed(99);
    for (int i = 0; i < 6 * DRAWS; i++) {
        counts[util_random_int(1, 6) - 1]++;
    }
    for (int value = 0; value < 6; value++) {
        /* DRAWS expected each; a fair generator stays well within 15% */
        CHECK(counts[value] > DRAWS * 85 / 100 && counts[value] < DRAWS * 115 / 100);
    }
}

void test_random_int_reaches_both_ends_of_wide_ranges(HammerCtx *t)
{
    util_random_seed(3);
    int below_zero = 0;
    int above_zero = 0;
    for (int i = 0; i < DRAWS; i++) {
        i32 value = util_random_int(INT32_MIN, INT32_MAX);
        below_zero += value < 0;
        above_zero += value > 0;
    }
    CHECK(below_zero > DRAWS / 3);
    CHECK(above_zero > DRAWS / 3);
}

static void check_float_range(HammerCtx *t, f32 low, f32 high)
{
    f32 min = low < high ? low : high;
    f32 max = low < high ? high : low;
    int outside = 0;
    for (int i = 0; i < DRAWS; i++) {
        f32 value = util_random_float(low, high);
        outside += !(value >= min && value <= max);
    }
    CHECK_EQ_INT(outside, 0);
}

void test_random_float_stays_in_range(HammerCtx *t)
{
    util_random_seed(11);
    check_float_range(t, 0.0f, 1.0f);
    check_float_range(t, -5.5f, 2.25f);
    check_float_range(t, 10.0f, -10.0f);            /* swapped */
    check_float_range(t, -FLT_MAX, FLT_MAX);
    check_float_range(t, FLT_MAX / 2.0f, FLT_MAX);
    CHECK(util_random_float(3.5f, 3.5f) == 3.5f);
}

void test_random_float_spreads_over_the_range(HammerCtx *t)
{
    int counts[4] = { 0 };
    util_random_seed(5);
    for (int i = 0; i < 4 * DRAWS; i++) {
        f32 value = util_random_float(0.0f, 4.0f);
        int bucket = value >= 4.0f ? 3 : (int)value;
        counts[bucket]++;
    }
    for (int bucket = 0; bucket < 4; bucket++) {
        CHECK(counts[bucket] > DRAWS * 85 / 100 && counts[bucket] < DRAWS * 115 / 100);
    }
}

void test_random_subsystem_init_succeeds_and_reseeds(HammerCtx *t)
{
    util_singleton_subsystem random = util_random_subsystem();
    REQUIRE(random.init != NULL);
    CHECK(random.shutdown == NULL);
    util_log_set_terminal(false);   /* the setup logs its seed */
    CHECK_EQ_INT(random.init(), STATUS_OK);
    util_log_set_terminal(true);
    i32 value = util_random_int(1, 6);
    CHECK(value >= 1 && value <= 6);
}
