#include "hammerc.h"

#include "data/sphere.h"

void test_sphere_pod_keeps_every_field(HammerCtx *t)
{
    data_sphere sphere = data_sphere_pod(1.5f, -2.25f, 3.0f, -4.5f, 0.75f, data_rgba_pod(10, 20, 30, 40));
    CHECK(sphere.x == 1.5f);
    CHECK(sphere.y == -2.25f);
    CHECK(sphere.vx == 3.0f);
    CHECK(sphere.vy == -4.5f);
    CHECK(sphere.radius == 0.75f);
    CHECK_EQ_UINT(sphere.rgba.r, 10);
    CHECK_EQ_UINT(sphere.rgba.g, 20);
    CHECK_EQ_UINT(sphere.rgba.b, 30);
    CHECK_EQ_UINT(sphere.rgba.a, 40);
}

void test_sphere_pod_is_copied_by_value(HammerCtx *t)
{
    data_sphere original = data_sphere_pod(1.0f, 2.0f, 0.0f, 0.0f, 1.0f, data_rgba_pod(1, 2, 3, 4));
    data_sphere copy = original;
    copy.x = 9.0f;
    copy.rgba.r = 99;
    CHECK(original.x == 1.0f);
    CHECK_EQ_UINT(original.rgba.r, 1);
    CHECK(&copy.x != &original.x);
}
