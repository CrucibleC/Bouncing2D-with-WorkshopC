#include "hammerc.h"

#include "data/triangle.h"

void test_triangle_pod_keeps_the_corners(HammerCtx *t)
{
    data_triangle triangle = data_triangle_pod(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f);
    CHECK(triangle.x0 == 1.0f && triangle.y0 == 2.0f);
    CHECK(triangle.x1 == 3.0f && triangle.y1 == 4.0f);
    CHECK(triangle.x2 == 5.0f && triangle.y2 == 6.0f);
}

void test_triangle_edge_sign_tells_the_side(HammerCtx *t)
{
    /* the line (0, 0) -> (10, 0): y down is positive */
    CHECK(data_triangle_edge(0.0f, 0.0f, 10.0f, 0.0f, 5.0f, 3.0f) > 0.0f);
    CHECK(data_triangle_edge(0.0f, 0.0f, 10.0f, 0.0f, 5.0f, -3.0f) < 0.0f);
    CHECK(data_triangle_edge(0.0f, 0.0f, 10.0f, 0.0f, 5.0f, 0.0f) == 0.0f);
}

void test_triangle_contains_for_both_windings(HammerCtx *t)
{
    data_triangle clockwise = data_triangle_pod(0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 10.0f);
    data_triangle counter = data_triangle_pod(0.0f, 0.0f, 0.0f, 10.0f, 10.0f, 0.0f);
    CHECK(data_triangle_contains(clockwise, 2.0f, 2.0f));
    CHECK(data_triangle_contains(counter, 2.0f, 2.0f));
    /* corners and edges count as inside */
    CHECK(data_triangle_contains(clockwise, 0.0f, 0.0f));
    CHECK(data_triangle_contains(clockwise, 5.0f, 5.0f));
    /* past the long edge, or off to a side */
    CHECK(!data_triangle_contains(clockwise, 6.0f, 6.0f));
    CHECK(!data_triangle_contains(counter, 6.0f, 6.0f));
    CHECK(!data_triangle_contains(clockwise, -1.0f, 2.0f));
}
