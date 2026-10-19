#include "hammerc.h"

#include "data/input_event.h"

void test_input_event_pod_keeps_kind_and_position(HammerCtx *t)
{
    data_input_event event = data_input_event_pod(DATA_INPUT_MOUSE_DOWN, 12.5f, 40.0f);
    CHECK_EQ_INT(event.kind, DATA_INPUT_MOUSE_DOWN);
    CHECK(event.x == 12.5f && event.y == 40.0f);
}

void test_input_event_resize_carries_the_new_size(HammerCtx *t)
{
    data_input_event event = data_input_event_pod(DATA_INPUT_RESIZE, 1920.0f, 1080.0f);
    CHECK_EQ_INT(event.kind, DATA_INPUT_RESIZE);
    CHECK(event.x == 1920.0f && event.y == 1080.0f);
}

void test_input_event_none_is_zero(HammerCtx *t)
{
    CHECK_EQ_INT(DATA_INPUT_NONE, 0);
}
