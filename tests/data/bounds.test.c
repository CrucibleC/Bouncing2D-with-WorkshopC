#include "hammerc.h"

#include "data/bounds.h"

void test_bounds_pod_keeps_every_field(HammerCtx *t)
{
    data_bounds box = data_bounds_pod(-1.5f, 2.0f, 640.0f, 480.0f);
    CHECK(box.min_x == -1.5f);
    CHECK(box.min_y == 2.0f);
    CHECK(box.max_x == 640.0f);
    CHECK(box.max_y == 480.0f);
}
