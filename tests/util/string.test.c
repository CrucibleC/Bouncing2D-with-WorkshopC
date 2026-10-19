#include <string.h>

#include "hammerc.h"

#include "util/string.h"

void test_string_make_copies_text(HammerCtx *t)
{
    util_string s = util_string_make("abc");
    REQUIRE(util_string_valid(&s));
    CHECK_EQ_STR(util_string_c_str(&s), "abc");
    CHECK_EQ_UINT(util_string_length(&s), 3);
    CHECK_EQ_UINT(util_string_capacity(&s), 8);
    CHECK_EQ_INT(util_string_status(&s), STATUS_OK);
    util_string_destroy(&s);
}

void test_string_make_null_gives_empty_string(HammerCtx *t)
{
    util_string s = util_string_make(NULL);
    REQUIRE(util_string_valid(&s));
    CHECK_EQ_STR(util_string_c_str(&s), "");
    CHECK_EQ_UINT(util_string_length(&s), 0);
    util_string_destroy(&s);
}

void test_string_make_sizes_capacity_from_text(HammerCtx *t)
{
    util_string s = util_string_make("0123456789abcdefghij");
    REQUIRE(util_string_valid(&s));
    CHECK_EQ_UINT(util_string_length(&s), 20);
    CHECK_EQ_UINT(util_string_capacity(&s), 21);
    util_string_destroy(&s);
}

void test_string_append_grows_capacity(HammerCtx *t)
{
    util_string s = util_string_make("");
    REQUIRE(util_string_valid(&s));
    CHECK_EQ_INT(util_string_append(&s, "Hello"), STATUS_OK);
    CHECK_EQ_UINT(util_string_capacity(&s), 8);
    CHECK_EQ_INT(util_string_append(&s, ", world!"), STATUS_OK);
    CHECK_EQ_STR(util_string_c_str(&s), "Hello, world!");
    CHECK_EQ_UINT(util_string_length(&s), 13);
    CHECK_EQ_UINT(util_string_capacity(&s), 16);
    util_string_destroy(&s);
}

void test_string_append_many_times(HammerCtx *t)
{
    util_string s = util_string_make("");
    REQUIRE(util_string_valid(&s));
    for (int i = 0; i < 100; i++) {
        REQUIRE_EQ_INT(util_string_append(&s, "x"), STATUS_OK);
    }
    CHECK_EQ_UINT(util_string_length(&s), 100);
    CHECK_EQ_UINT(strlen(util_string_c_str(&s)), 100);
    CHECK(util_string_capacity(&s) >= 101);
    util_string_destroy(&s);
}

void test_string_append_null_is_invalid_argument(HammerCtx *t)
{
    util_string s = util_string_make("abc");
    REQUIRE(util_string_valid(&s));
    CHECK_EQ_INT(util_string_append(&s, NULL), STATUS_INVALID_ARGUMENT);
    CHECK_EQ_STR(util_string_c_str(&s), "abc");
    util_string_destroy(&s);
}

void test_string_append_string_appends_other(HammerCtx *t)
{
    util_string s = util_string_make("abc");
    util_string other = util_string_make("0123456789abcdefghij");
    util_string empty = util_string_make("");
    REQUIRE(util_string_valid(&s) && util_string_valid(&other) && util_string_valid(&empty));
    CHECK_EQ_INT(util_string_append_string(&s, &other), STATUS_OK);
    CHECK_EQ_STR(util_string_c_str(&s), "abc0123456789abcdefghij");
    CHECK_EQ_INT(util_string_append_string(&s, &empty), STATUS_OK);
    CHECK_EQ_UINT(util_string_length(&s), 23);
    CHECK_EQ_STR(util_string_c_str(&other), "0123456789abcdefghij");
    util_string_destroy(&empty);
    util_string_destroy(&other);
    util_string_destroy(&s);
}

void test_string_append_string_to_itself(HammerCtx *t)
{
    util_string s = util_string_make("xyz");
    REQUIRE(util_string_valid(&s));
    for (int i = 0; i < 4; i++) {
        REQUIRE_EQ_INT(util_string_append_string(&s, &s), STATUS_OK);
    }
    CHECK_EQ_UINT(util_string_length(&s), 48);
    CHECK_EQ_STR(util_string_c_str(&s), "xyzxyzxyzxyzxyzxyzxyzxyzxyzxyzxyzxyzxyzxyzxyzxyz");
    util_string_destroy(&s);
}

void test_string_copy_is_independent(HammerCtx *t)
{
    util_string s = util_string_make("abc");
    util_string copy = util_string_copy(&s);
    REQUIRE(util_string_valid(&copy));
    CHECK_EQ_STR(util_string_c_str(&copy), "abc");
    CHECK(util_string_c_str(&copy) != util_string_c_str(&s));
    CHECK_EQ_INT(util_string_append(&copy, "def"), STATUS_OK);
    CHECK_EQ_STR(util_string_c_str(&s), "abc");
    util_string_destroy(&copy);
    util_string_destroy(&s);
}

void test_string_move_empties_the_source(HammerCtx *t)
{
    util_string s = util_string_make("abc");
    util_string moved = util_string_move(&s);
    REQUIRE(util_string_valid(&moved));
    CHECK_EQ_STR(util_string_c_str(&moved), "abc");
    CHECK(!util_string_valid(&s));
    CHECK_EQ_STR(util_string_c_str(&s), "");
    CHECK_EQ_UINT(util_string_length(&s), 0);
    CHECK_EQ_INT(util_string_append(&s, "a"), STATUS_INVALID_STATE);
    util_string_destroy(&moved);
    util_string_destroy(&s);
}

void test_string_destroyed_string_is_invalid(HammerCtx *t)
{
    util_string s = util_string_make("q");
    util_string other = util_string_make("abc");
    util_string_destroy(&s);
    CHECK(!util_string_valid(&s));
    CHECK_EQ_UINT(util_string_length(&s), 0);
    CHECK_EQ_INT(util_string_append_string(&s, &other), STATUS_INVALID_STATE);
    CHECK_EQ_INT(util_string_append_string(&other, &s), STATUS_OK);
    CHECK_EQ_STR(util_string_c_str(&other), "abc");
    util_string_destroy(&other);
}

void test_string_append_span_appends_exact_size(HammerCtx *t)
{
    char chars[5] = { 'a', 'b', '\0', 'c', 'd' };
    char_span span = char_span_pod(chars, 5);
    util_string s = util_string_make("<");
    REQUIRE(util_string_valid(&s));
    CHECK_EQ_INT(util_string_append_span(&s, char_const_span_pod(span)), STATUS_OK);
    CHECK_EQ_UINT(util_string_length(&s), 6);
    CHECK(memcmp(util_string_c_str(&s), "<ab\0cd", 7) == 0);
    util_string_destroy(&s);
}

void test_string_append_span_of_size_zero_changes_nothing(HammerCtx *t)
{
    util_string s = util_string_make("abc");
    REQUIRE(util_string_valid(&s));
    CHECK_EQ_INT(util_string_append_span(&s, char_const_span_pod(char_span_pod(NULL, 0))), STATUS_OK);
    CHECK_EQ_STR(util_string_c_str(&s), "abc");
    util_string_destroy(&s);
}

void test_string_append_span_null_with_size_is_invalid_argument(HammerCtx *t)
{
    util_string s = util_string_make("abc");
    REQUIRE(util_string_valid(&s));
    CHECK_EQ_INT(util_string_append_span(&s, char_const_span_pod(char_span_pod(NULL, 3))), STATUS_INVALID_ARGUMENT);
    CHECK_EQ_STR(util_string_c_str(&s), "abc");
    util_string_destroy(&s);
}

void test_string_truncate_shortens_and_keeps_capacity(HammerCtx *t)
{
    util_string s = util_string_make("0123456789abcdefghij");
    REQUIRE(util_string_valid(&s));
    util_string_truncate(&s, 4);
    CHECK_EQ_STR(util_string_c_str(&s), "0123");
    CHECK_EQ_UINT(util_string_length(&s), 4);
    CHECK_EQ_UINT(util_string_capacity(&s), 21);
    util_string_truncate(&s, 10);
    CHECK_EQ_STR(util_string_c_str(&s), "0123");
    util_string_truncate(&s, 0);
    CHECK_EQ_STR(util_string_c_str(&s), "");
    util_string_destroy(&s);
}

void test_string_clear_keeps_capacity(HammerCtx *t)
{
    util_string s = util_string_make("0123456789abcdefghij");
    REQUIRE(util_string_valid(&s));
    util_string_clear(&s);
    CHECK_EQ_UINT(util_string_length(&s), 0);
    CHECK_EQ_STR(util_string_c_str(&s), "");
    CHECK_EQ_UINT(util_string_capacity(&s), 21);
    util_string_destroy(&s);
}
