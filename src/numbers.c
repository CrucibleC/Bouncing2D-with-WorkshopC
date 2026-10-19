#include "numbers.h"

#include <float.h>
#include <math.h>

// 2^63 and 2^64 are exact as f64, unlike INT64_MAX and UINT64_MAX, which round up to them.
// A float inside [-2^63, 2^63) or [0, 2^64) truncates to a value that fits in i64 or u64.
static const f64 TWO_POW_63 = 9223372036854775808.0;
static const f64 TWO_POW_64 = 18446744073709551616.0;

static i64 numbers_signed_to_signed(i64 value, i64 min, i64 max)
{
    if (value < min)
    {
        return min;
    }
    if (value > max)
    {
        return max;
    }
    return value;
}

static u64 numbers_signed_to_unsigned(i64 value, u64 max)
{
    if (value <= 0)
    {
        return 0;
    }
    if ((u64)value > max)
    {
        return max;
    }
    return (u64)value;
}

static u64 numbers_unsigned_to_unsigned(u64 value, u64 max)
{
    return value > max ? max : value;
}

// max is never negative: every signed type's maximum is positive
static i64 numbers_unsigned_to_signed(u64 value, i64 max)
{
    return value > (u64)max ? max : (i64)value;
}

static i64 numbers_float_to_signed(f64 value, i64 min, i64 max)
{
    if (isnan(value))
    {
        return 0;
    }
    if (value >= TWO_POW_63)
    {
        return max;
    }
    if (value < -TWO_POW_63)
    {
        return min;
    }
    return numbers_signed_to_signed((i64)value, min, max);
}

static u64 numbers_float_to_unsigned(f64 value, u64 max)
{
    if (isnan(value) || value <= 0.0)
    {
        return 0;
    }
    if (value >= TWO_POW_64)
    {
        return max;
    }
    return numbers_unsigned_to_unsigned((u64)value, max);
}

static f32 numbers_f64_to_f32(f64 value)
{
    if (value > FLT_MAX && !isinf(value))
    {
        return FLT_MAX;
    }
    if (value < -FLT_MAX && !isinf(value))
    {
        return -FLT_MAX;
    }
    return (f32)value;
}

// From u8

u8 cast_u8_to_u8(u8 value)
{
    return value;
}

i8 cast_u8_to_i8(u8 value)
{
    return (i8)numbers_unsigned_to_signed(value, INT8_MAX);
}

u16 cast_u8_to_u16(u8 value)
{
    return (u16)value;
}

i16 cast_u8_to_i16(u8 value)
{
    return (i16)value;
}

u32 cast_u8_to_u32(u8 value)
{
    return (u32)value;
}

i32 cast_u8_to_i32(u8 value)
{
    return (i32)value;
}

u64 cast_u8_to_u64(u8 value)
{
    return (u64)value;
}

i64 cast_u8_to_i64(u8 value)
{
    return (i64)value;
}

size_t cast_u8_to_size_t(u8 value)
{
    return (size_t)value;
}

f32 cast_u8_to_f32(u8 value)
{
    return (f32)value;
}

f64 cast_u8_to_f64(u8 value)
{
    return (f64)value;
}

// From i8

u8 cast_i8_to_u8(i8 value)
{
    return (u8)numbers_signed_to_unsigned(value, UINT8_MAX);
}

i8 cast_i8_to_i8(i8 value)
{
    return value;
}

u16 cast_i8_to_u16(i8 value)
{
    return (u16)numbers_signed_to_unsigned(value, UINT16_MAX);
}

i16 cast_i8_to_i16(i8 value)
{
    return (i16)value;
}

u32 cast_i8_to_u32(i8 value)
{
    return (u32)numbers_signed_to_unsigned(value, UINT32_MAX);
}

i32 cast_i8_to_i32(i8 value)
{
    return (i32)value;
}

u64 cast_i8_to_u64(i8 value)
{
    return (u64)numbers_signed_to_unsigned(value, UINT64_MAX);
}

i64 cast_i8_to_i64(i8 value)
{
    return (i64)value;
}

size_t cast_i8_to_size_t(i8 value)
{
    return (size_t)numbers_signed_to_unsigned(value, SIZE_MAX);
}

f32 cast_i8_to_f32(i8 value)
{
    return (f32)value;
}

f64 cast_i8_to_f64(i8 value)
{
    return (f64)value;
}

// From u16

u8 cast_u16_to_u8(u16 value)
{
    return (u8)numbers_unsigned_to_unsigned(value, UINT8_MAX);
}

i8 cast_u16_to_i8(u16 value)
{
    return (i8)numbers_unsigned_to_signed(value, INT8_MAX);
}

u16 cast_u16_to_u16(u16 value)
{
    return value;
}

i16 cast_u16_to_i16(u16 value)
{
    return (i16)numbers_unsigned_to_signed(value, INT16_MAX);
}

u32 cast_u16_to_u32(u16 value)
{
    return (u32)value;
}

i32 cast_u16_to_i32(u16 value)
{
    return (i32)value;
}

u64 cast_u16_to_u64(u16 value)
{
    return (u64)value;
}

i64 cast_u16_to_i64(u16 value)
{
    return (i64)value;
}

size_t cast_u16_to_size_t(u16 value)
{
    return (size_t)value;
}

f32 cast_u16_to_f32(u16 value)
{
    return (f32)value;
}

f64 cast_u16_to_f64(u16 value)
{
    return (f64)value;
}

// From i16

u8 cast_i16_to_u8(i16 value)
{
    return (u8)numbers_signed_to_unsigned(value, UINT8_MAX);
}

i8 cast_i16_to_i8(i16 value)
{
    return (i8)numbers_signed_to_signed(value, INT8_MIN, INT8_MAX);
}

u16 cast_i16_to_u16(i16 value)
{
    return (u16)numbers_signed_to_unsigned(value, UINT16_MAX);
}

i16 cast_i16_to_i16(i16 value)
{
    return value;
}

u32 cast_i16_to_u32(i16 value)
{
    return (u32)numbers_signed_to_unsigned(value, UINT32_MAX);
}

i32 cast_i16_to_i32(i16 value)
{
    return (i32)value;
}

u64 cast_i16_to_u64(i16 value)
{
    return (u64)numbers_signed_to_unsigned(value, UINT64_MAX);
}

i64 cast_i16_to_i64(i16 value)
{
    return (i64)value;
}

size_t cast_i16_to_size_t(i16 value)
{
    return (size_t)numbers_signed_to_unsigned(value, SIZE_MAX);
}

f32 cast_i16_to_f32(i16 value)
{
    return (f32)value;
}

f64 cast_i16_to_f64(i16 value)
{
    return (f64)value;
}

// From u32

u8 cast_u32_to_u8(u32 value)
{
    return (u8)numbers_unsigned_to_unsigned(value, UINT8_MAX);
}

i8 cast_u32_to_i8(u32 value)
{
    return (i8)numbers_unsigned_to_signed(value, INT8_MAX);
}

u16 cast_u32_to_u16(u32 value)
{
    return (u16)numbers_unsigned_to_unsigned(value, UINT16_MAX);
}

i16 cast_u32_to_i16(u32 value)
{
    return (i16)numbers_unsigned_to_signed(value, INT16_MAX);
}

u32 cast_u32_to_u32(u32 value)
{
    return value;
}

i32 cast_u32_to_i32(u32 value)
{
    return (i32)numbers_unsigned_to_signed(value, INT32_MAX);
}

u64 cast_u32_to_u64(u32 value)
{
    return (u64)value;
}

i64 cast_u32_to_i64(u32 value)
{
    return (i64)value;
}

size_t cast_u32_to_size_t(u32 value)
{
    return (size_t)numbers_unsigned_to_unsigned(value, SIZE_MAX);
}

f32 cast_u32_to_f32(u32 value)
{
    return (f32)value;
}

f64 cast_u32_to_f64(u32 value)
{
    return (f64)value;
}

// From i32

u8 cast_i32_to_u8(i32 value)
{
    return (u8)numbers_signed_to_unsigned(value, UINT8_MAX);
}

i8 cast_i32_to_i8(i32 value)
{
    return (i8)numbers_signed_to_signed(value, INT8_MIN, INT8_MAX);
}

u16 cast_i32_to_u16(i32 value)
{
    return (u16)numbers_signed_to_unsigned(value, UINT16_MAX);
}

i16 cast_i32_to_i16(i32 value)
{
    return (i16)numbers_signed_to_signed(value, INT16_MIN, INT16_MAX);
}

u32 cast_i32_to_u32(i32 value)
{
    return (u32)numbers_signed_to_unsigned(value, UINT32_MAX);
}

i32 cast_i32_to_i32(i32 value)
{
    return value;
}

u64 cast_i32_to_u64(i32 value)
{
    return (u64)numbers_signed_to_unsigned(value, UINT64_MAX);
}

i64 cast_i32_to_i64(i32 value)
{
    return (i64)value;
}

size_t cast_i32_to_size_t(i32 value)
{
    return (size_t)numbers_signed_to_unsigned(value, SIZE_MAX);
}

f32 cast_i32_to_f32(i32 value)
{
    return (f32)value;
}

f64 cast_i32_to_f64(i32 value)
{
    return (f64)value;
}

// From u64

u8 cast_u64_to_u8(u64 value)
{
    return (u8)numbers_unsigned_to_unsigned(value, UINT8_MAX);
}

i8 cast_u64_to_i8(u64 value)
{
    return (i8)numbers_unsigned_to_signed(value, INT8_MAX);
}

u16 cast_u64_to_u16(u64 value)
{
    return (u16)numbers_unsigned_to_unsigned(value, UINT16_MAX);
}

i16 cast_u64_to_i16(u64 value)
{
    return (i16)numbers_unsigned_to_signed(value, INT16_MAX);
}

u32 cast_u64_to_u32(u64 value)
{
    return (u32)numbers_unsigned_to_unsigned(value, UINT32_MAX);
}

i32 cast_u64_to_i32(u64 value)
{
    return (i32)numbers_unsigned_to_signed(value, INT32_MAX);
}

u64 cast_u64_to_u64(u64 value)
{
    return value;
}

i64 cast_u64_to_i64(u64 value)
{
    return (i64)numbers_unsigned_to_signed(value, INT64_MAX);
}

size_t cast_u64_to_size_t(u64 value)
{
    return (size_t)numbers_unsigned_to_unsigned(value, SIZE_MAX);
}

f32 cast_u64_to_f32(u64 value)
{
    return (f32)value;
}

f64 cast_u64_to_f64(u64 value)
{
    return (f64)value;
}

// From i64

u8 cast_i64_to_u8(i64 value)
{
    return (u8)numbers_signed_to_unsigned(value, UINT8_MAX);
}

i8 cast_i64_to_i8(i64 value)
{
    return (i8)numbers_signed_to_signed(value, INT8_MIN, INT8_MAX);
}

u16 cast_i64_to_u16(i64 value)
{
    return (u16)numbers_signed_to_unsigned(value, UINT16_MAX);
}

i16 cast_i64_to_i16(i64 value)
{
    return (i16)numbers_signed_to_signed(value, INT16_MIN, INT16_MAX);
}

u32 cast_i64_to_u32(i64 value)
{
    return (u32)numbers_signed_to_unsigned(value, UINT32_MAX);
}

i32 cast_i64_to_i32(i64 value)
{
    return (i32)numbers_signed_to_signed(value, INT32_MIN, INT32_MAX);
}

u64 cast_i64_to_u64(i64 value)
{
    return (u64)numbers_signed_to_unsigned(value, UINT64_MAX);
}

i64 cast_i64_to_i64(i64 value)
{
    return value;
}

size_t cast_i64_to_size_t(i64 value)
{
    return (size_t)numbers_signed_to_unsigned(value, SIZE_MAX);
}

f32 cast_i64_to_f32(i64 value)
{
    return (f32)value;
}

f64 cast_i64_to_f64(i64 value)
{
    return (f64)value;
}

// From size_t

u8 cast_size_t_to_u8(size_t value)
{
    return (u8)numbers_unsigned_to_unsigned((u64)value, UINT8_MAX);
}

i8 cast_size_t_to_i8(size_t value)
{
    return (i8)numbers_unsigned_to_signed((u64)value, INT8_MAX);
}

u16 cast_size_t_to_u16(size_t value)
{
    return (u16)numbers_unsigned_to_unsigned((u64)value, UINT16_MAX);
}

i16 cast_size_t_to_i16(size_t value)
{
    return (i16)numbers_unsigned_to_signed((u64)value, INT16_MAX);
}

u32 cast_size_t_to_u32(size_t value)
{
    return (u32)numbers_unsigned_to_unsigned((u64)value, UINT32_MAX);
}

i32 cast_size_t_to_i32(size_t value)
{
    return (i32)numbers_unsigned_to_signed((u64)value, INT32_MAX);
}

u64 cast_size_t_to_u64(size_t value)
{
    return (u64)value;
}

i64 cast_size_t_to_i64(size_t value)
{
    return (i64)numbers_unsigned_to_signed((u64)value, INT64_MAX);
}

size_t cast_size_t_to_size_t(size_t value)
{
    return value;
}

f32 cast_size_t_to_f32(size_t value)
{
    return (f32)value;
}

f64 cast_size_t_to_f64(size_t value)
{
    return (f64)value;
}

// From f32

u8 cast_f32_to_u8(f32 value)
{
    return (u8)numbers_float_to_unsigned(value, UINT8_MAX);
}

i8 cast_f32_to_i8(f32 value)
{
    return (i8)numbers_float_to_signed(value, INT8_MIN, INT8_MAX);
}

u16 cast_f32_to_u16(f32 value)
{
    return (u16)numbers_float_to_unsigned(value, UINT16_MAX);
}

i16 cast_f32_to_i16(f32 value)
{
    return (i16)numbers_float_to_signed(value, INT16_MIN, INT16_MAX);
}

u32 cast_f32_to_u32(f32 value)
{
    return (u32)numbers_float_to_unsigned(value, UINT32_MAX);
}

i32 cast_f32_to_i32(f32 value)
{
    return (i32)numbers_float_to_signed(value, INT32_MIN, INT32_MAX);
}

u64 cast_f32_to_u64(f32 value)
{
    return (u64)numbers_float_to_unsigned(value, UINT64_MAX);
}

i64 cast_f32_to_i64(f32 value)
{
    return (i64)numbers_float_to_signed(value, INT64_MIN, INT64_MAX);
}

size_t cast_f32_to_size_t(f32 value)
{
    return (size_t)numbers_float_to_unsigned(value, SIZE_MAX);
}

f32 cast_f32_to_f32(f32 value)
{
    return value;
}

f64 cast_f32_to_f64(f32 value)
{
    return (f64)value;
}

// From f64

u8 cast_f64_to_u8(f64 value)
{
    return (u8)numbers_float_to_unsigned(value, UINT8_MAX);
}

i8 cast_f64_to_i8(f64 value)
{
    return (i8)numbers_float_to_signed(value, INT8_MIN, INT8_MAX);
}

u16 cast_f64_to_u16(f64 value)
{
    return (u16)numbers_float_to_unsigned(value, UINT16_MAX);
}

i16 cast_f64_to_i16(f64 value)
{
    return (i16)numbers_float_to_signed(value, INT16_MIN, INT16_MAX);
}

u32 cast_f64_to_u32(f64 value)
{
    return (u32)numbers_float_to_unsigned(value, UINT32_MAX);
}

i32 cast_f64_to_i32(f64 value)
{
    return (i32)numbers_float_to_signed(value, INT32_MIN, INT32_MAX);
}

u64 cast_f64_to_u64(f64 value)
{
    return (u64)numbers_float_to_unsigned(value, UINT64_MAX);
}

i64 cast_f64_to_i64(f64 value)
{
    return (i64)numbers_float_to_signed(value, INT64_MIN, INT64_MAX);
}

size_t cast_f64_to_size_t(f64 value)
{
    return (size_t)numbers_float_to_unsigned(value, SIZE_MAX);
}

f32 cast_f64_to_f32(f64 value)
{
    return numbers_f64_to_f32(value);
}

f64 cast_f64_to_f64(f64 value)
{
    return value;
}
