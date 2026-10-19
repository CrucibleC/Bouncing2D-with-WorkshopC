#include "hammerc.h"

#include "span.h"

void test_span_char_span_pod_keeps_pointer_and_size(HammerCtx *t)
{
    char chars[4] = { 'a', 'b', 'c', 'd' };
    char_span span = char_span_pod(chars, 4);
    CHECK_EQ_PTR(span.data, chars);
    CHECK_EQ_UINT(span.size, 4);
    span.data[0] = 'z';
    CHECK(chars[0] == 'z');
}

void test_span_char_const_span_pod_views_the_same_chars(HammerCtx *t)
{
    char chars[3] = { 'x', 'y', 'z' };
    char_span span = char_span_pod(chars, 3);
    char_const_span view = char_const_span_pod(span);
    CHECK_EQ_PTR(view.data, chars);
    CHECK_EQ_UINT(view.size, 3);
}

void test_span_allows_empty_span(HammerCtx *t)
{
    char_span span = char_span_pod(NULL, 0);
    CHECK_EQ_PTR(span.data, NULL);
    CHECK_EQ_UINT(char_const_span_pod(span).size, 0);
}
