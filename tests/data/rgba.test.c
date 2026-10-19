#include "hammerc.h"

#include "data/rgba.h"

void test_rgba_pod_keeps_every_channel(HammerCtx *t)
{
    data_rgba color = data_rgba_pod(12, 34, 56, 78);
    CHECK_EQ_UINT(color.r, 12);
    CHECK_EQ_UINT(color.g, 34);
    CHECK_EQ_UINT(color.b, 56);
    CHECK_EQ_UINT(color.a, 78);
}

void test_rgba_pod_keeps_channel_limits(HammerCtx *t)
{
    data_rgba black = data_rgba_pod(0, 0, 0, 0);
    data_rgba white = data_rgba_pod(255, 255, 255, 255);
    CHECK(black.r == 0 && black.g == 0 && black.b == 0 && black.a == 0);
    CHECK(white.r == 255 && white.g == 255 && white.b == 255 && white.a == 255);
}
