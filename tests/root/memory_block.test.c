#include <stdint.h>

#include "hammerc.h"

#include "memory_block.h"
#include "numbers.h"

static int count_nonzero(const u32 *values, size_t from, size_t to)
{
    int nonzero = 0;
    for (size_t i = from; i < to; i++) {
        nonzero += values[i] != 0;
    }
    return nonzero;
}

void test_memory_block_make_is_zeroed(HammerCtx *t)
{
    memory_block block = memory_block_make(64, sizeof(u32));
    REQUIRE(memory_block_valid(&block));
    CHECK_EQ_INT(memory_block_status(&block), STATUS_OK);
    CHECK_EQ_UINT(memory_block_count(&block), 64);
    CHECK_EQ_UINT(memory_block_element_size(&block), sizeof(u32));
    CHECK_EQ_INT(count_nonzero(memory_block_const_data(&block), 0, 64), 0);
    memory_block_destroy(&block);
}

void test_memory_block_make_rejects_zero_and_overflow(HammerCtx *t)
{
    memory_block empty = memory_block_make(0, sizeof(u32));
    CHECK(!memory_block_valid(&empty));
    CHECK_EQ_INT(memory_block_status(&empty), STATUS_INVALID_ARGUMENT);
    memory_block huge = memory_block_make(SIZE_MAX, sizeof(u32));
    CHECK(!memory_block_valid(&huge));
    CHECK_EQ_INT(memory_block_status(&huge), STATUS_INVALID_ARGUMENT);
    memory_block_destroy(&huge);
    memory_block_destroy(&empty);
}

void test_memory_block_grow_keeps_old_and_zeroes_new(HammerCtx *t)
{
    memory_block block = memory_block_make(8, sizeof(u32));
    REQUIRE(memory_block_valid(&block));
    u32 *values = memory_block_data(&block);
    for (size_t i = 0; i < 8; i++) {
        values[i] = 0xA0000000u + (u32)i;
    }
    REQUIRE(memory_block_resize(&block, 4096));
    values = memory_block_data(&block);
    int kept = 0;
    for (size_t i = 0; i < 8; i++) {
        kept += values[i] == 0xA0000000u + (u32)i;
    }
    CHECK_EQ_INT(kept, 8);
    CHECK_EQ_INT(count_nonzero(values, 8, 4096), 0);
    CHECK_EQ_UINT(memory_block_count(&block), 4096);
    memory_block_destroy(&block);
}

void test_memory_block_shrink_then_grow_zeroes_the_regrown_part(HammerCtx *t)
{
    memory_block block = memory_block_make(16, sizeof(u32));
    REQUIRE(memory_block_valid(&block));
    u32 *values = memory_block_data(&block);
    for (size_t i = 0; i < 16; i++) {
        values[i] = 7;
    }
    REQUIRE(memory_block_resize(&block, 4));
    values = memory_block_data(&block);
    CHECK(values[0] == 7 && values[3] == 7);
    REQUIRE(memory_block_resize(&block, 16));
    values = memory_block_data(&block);
    CHECK(values[0] == 7 && values[3] == 7);
    CHECK_EQ_INT(count_nonzero(values, 4, 16), 0);
    memory_block_destroy(&block);
}

void test_memory_block_failed_resize_keeps_contents(HammerCtx *t)
{
    memory_block block = memory_block_make(4, sizeof(u32));
    REQUIRE(memory_block_valid(&block));
    u32 *values = memory_block_data(&block);
    values[2] = 99;
    CHECK(!memory_block_resize(&block, 0));
    CHECK_EQ_INT(memory_block_status(&block), STATUS_INVALID_ARGUMENT);
    CHECK_EQ_UINT(memory_block_count(&block), 4);
    CHECK(((u32 *)memory_block_data(&block))[2] == 99);
    memory_block_destroy(&block);
}

void test_memory_block_grow_after_move_is_zeroed(HammerCtx *t)
{
    memory_block block = memory_block_make(4, sizeof(u32));
    REQUIRE(memory_block_valid(&block));
    ((u32 *)memory_block_data(&block))[0] = 5;
    memory_block moved = memory_block_move(&block);
    CHECK(!memory_block_valid(&block));
    REQUIRE(memory_block_resize(&block, 32));
    CHECK_EQ_INT(count_nonzero(memory_block_const_data(&block), 0, 32), 0);
    memory_block_destroy(&moved);
    memory_block_destroy(&block);
}

void test_memory_block_copy_is_equal_and_independent(HammerCtx *t)
{
    memory_block block = memory_block_make(4, sizeof(u32));
    REQUIRE(memory_block_valid(&block));
    u32 *values = memory_block_data(&block);
    values[1] = 11;
    memory_block copy = memory_block_copy(&block);
    REQUIRE(memory_block_valid(&copy));
    CHECK_EQ_UINT(memory_block_count(&copy), 4);
    CHECK(((const u32 *)memory_block_const_data(&copy))[1] == 11);
    values[1] = 22;
    CHECK(((const u32 *)memory_block_const_data(&copy))[1] == 11);
    memory_block_destroy(&copy);
    memory_block_destroy(&block);
}
