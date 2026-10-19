#include "hammerc.h"

#include "util/clock.h"

void test_clock_never_goes_back(HammerCtx *t)
{
    u64 previous = util_clock_ns();
    int backwards = 0;
    for (int i = 0; i < 1000; i++) {
        u64 now = util_clock_ns();
        backwards += now < previous;
        previous = now;
    }
    CHECK_EQ_INT(backwards, 0);
}

void test_clock_moves_forward(HammerCtx *t)
{
    u64 start = util_clock_ns();
    u64 now = start;
    /* spins until the clock ticks; any real clock does within far fewer reads than this */
    for (long i = 0; i < 100000000L && now == start; i++) {
        now = util_clock_ns();
    }
    CHECK(now > start);
}
