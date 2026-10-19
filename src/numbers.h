#ifndef NUMBERS_H
#define NUMBERS_H

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

// The project's number types: use them instead of int, long, float and double

typedef uint8_t u8;
typedef int8_t i8;
typedef uint16_t u16;
typedef int16_t i16;
typedef uint32_t u32;
typedef int32_t i32;
typedef uint64_t u64;
typedef int64_t i64;
typedef float f32;
typedef double f64;

static_assert(sizeof(f32) == 4, "f32 must be 32 bits");
static_assert(sizeof(f64) == 8, "f64 must be 64 bits");
static_assert(SIZE_MAX <= UINT64_MAX, "size_t must fit in 64 bits");

// Casts between every pair of u8, i8, u16, i16, u32, i32, u64, i64, size_t, f32 and f64,
// named cast_<from>_to_<to>. A value the target can hold is returned as a plain C cast would
// return it; anything else is clamped, never wrapped:
// - integers out of range become the target's minimum or maximum;
// - floats to integers truncate toward zero (2.9 -> 2, -2.9 -> -2), then clamp; +infinity
//   becomes the maximum, -infinity the minimum, and NaN becomes 0;
// - f64 to f32: finite values beyond FLT_MAX become +-FLT_MAX; infinity and NaN stay as they are;
// - integers to floats always fit and may round, e.g. cast_u64_to_f32(UINT64_MAX) is 2^64.

// From u8
u8 cast_u8_to_u8(u8 value);
i8 cast_u8_to_i8(u8 value);
u16 cast_u8_to_u16(u8 value);
i16 cast_u8_to_i16(u8 value);
u32 cast_u8_to_u32(u8 value);
i32 cast_u8_to_i32(u8 value);
u64 cast_u8_to_u64(u8 value);
i64 cast_u8_to_i64(u8 value);
size_t cast_u8_to_size_t(u8 value);
f32 cast_u8_to_f32(u8 value);
f64 cast_u8_to_f64(u8 value);

// From i8
u8 cast_i8_to_u8(i8 value);
i8 cast_i8_to_i8(i8 value);
u16 cast_i8_to_u16(i8 value);
i16 cast_i8_to_i16(i8 value);
u32 cast_i8_to_u32(i8 value);
i32 cast_i8_to_i32(i8 value);
u64 cast_i8_to_u64(i8 value);
i64 cast_i8_to_i64(i8 value);
size_t cast_i8_to_size_t(i8 value);
f32 cast_i8_to_f32(i8 value);
f64 cast_i8_to_f64(i8 value);

// From u16
u8 cast_u16_to_u8(u16 value);
i8 cast_u16_to_i8(u16 value);
u16 cast_u16_to_u16(u16 value);
i16 cast_u16_to_i16(u16 value);
u32 cast_u16_to_u32(u16 value);
i32 cast_u16_to_i32(u16 value);
u64 cast_u16_to_u64(u16 value);
i64 cast_u16_to_i64(u16 value);
size_t cast_u16_to_size_t(u16 value);
f32 cast_u16_to_f32(u16 value);
f64 cast_u16_to_f64(u16 value);

// From i16
u8 cast_i16_to_u8(i16 value);
i8 cast_i16_to_i8(i16 value);
u16 cast_i16_to_u16(i16 value);
i16 cast_i16_to_i16(i16 value);
u32 cast_i16_to_u32(i16 value);
i32 cast_i16_to_i32(i16 value);
u64 cast_i16_to_u64(i16 value);
i64 cast_i16_to_i64(i16 value);
size_t cast_i16_to_size_t(i16 value);
f32 cast_i16_to_f32(i16 value);
f64 cast_i16_to_f64(i16 value);

// From u32
u8 cast_u32_to_u8(u32 value);
i8 cast_u32_to_i8(u32 value);
u16 cast_u32_to_u16(u32 value);
i16 cast_u32_to_i16(u32 value);
u32 cast_u32_to_u32(u32 value);
i32 cast_u32_to_i32(u32 value);
u64 cast_u32_to_u64(u32 value);
i64 cast_u32_to_i64(u32 value);
size_t cast_u32_to_size_t(u32 value);
f32 cast_u32_to_f32(u32 value);
f64 cast_u32_to_f64(u32 value);

// From i32
u8 cast_i32_to_u8(i32 value);
i8 cast_i32_to_i8(i32 value);
u16 cast_i32_to_u16(i32 value);
i16 cast_i32_to_i16(i32 value);
u32 cast_i32_to_u32(i32 value);
i32 cast_i32_to_i32(i32 value);
u64 cast_i32_to_u64(i32 value);
i64 cast_i32_to_i64(i32 value);
size_t cast_i32_to_size_t(i32 value);
f32 cast_i32_to_f32(i32 value);
f64 cast_i32_to_f64(i32 value);

// From u64
u8 cast_u64_to_u8(u64 value);
i8 cast_u64_to_i8(u64 value);
u16 cast_u64_to_u16(u64 value);
i16 cast_u64_to_i16(u64 value);
u32 cast_u64_to_u32(u64 value);
i32 cast_u64_to_i32(u64 value);
u64 cast_u64_to_u64(u64 value);
i64 cast_u64_to_i64(u64 value);
size_t cast_u64_to_size_t(u64 value);
f32 cast_u64_to_f32(u64 value);
f64 cast_u64_to_f64(u64 value);

// From i64
u8 cast_i64_to_u8(i64 value);
i8 cast_i64_to_i8(i64 value);
u16 cast_i64_to_u16(i64 value);
i16 cast_i64_to_i16(i64 value);
u32 cast_i64_to_u32(i64 value);
i32 cast_i64_to_i32(i64 value);
u64 cast_i64_to_u64(i64 value);
i64 cast_i64_to_i64(i64 value);
size_t cast_i64_to_size_t(i64 value);
f32 cast_i64_to_f32(i64 value);
f64 cast_i64_to_f64(i64 value);

// From size_t
u8 cast_size_t_to_u8(size_t value);
i8 cast_size_t_to_i8(size_t value);
u16 cast_size_t_to_u16(size_t value);
i16 cast_size_t_to_i16(size_t value);
u32 cast_size_t_to_u32(size_t value);
i32 cast_size_t_to_i32(size_t value);
u64 cast_size_t_to_u64(size_t value);
i64 cast_size_t_to_i64(size_t value);
size_t cast_size_t_to_size_t(size_t value);
f32 cast_size_t_to_f32(size_t value);
f64 cast_size_t_to_f64(size_t value);

// From f32
u8 cast_f32_to_u8(f32 value);
i8 cast_f32_to_i8(f32 value);
u16 cast_f32_to_u16(f32 value);
i16 cast_f32_to_i16(f32 value);
u32 cast_f32_to_u32(f32 value);
i32 cast_f32_to_i32(f32 value);
u64 cast_f32_to_u64(f32 value);
i64 cast_f32_to_i64(f32 value);
size_t cast_f32_to_size_t(f32 value);
f32 cast_f32_to_f32(f32 value);
f64 cast_f32_to_f64(f32 value);

// From f64
u8 cast_f64_to_u8(f64 value);
i8 cast_f64_to_i8(f64 value);
u16 cast_f64_to_u16(f64 value);
i16 cast_f64_to_i16(f64 value);
u32 cast_f64_to_u32(f64 value);
i32 cast_f64_to_i32(f64 value);
u64 cast_f64_to_u64(f64 value);
i64 cast_f64_to_i64(f64 value);
size_t cast_f64_to_size_t(f64 value);
f32 cast_f64_to_f32(f64 value);
f64 cast_f64_to_f64(f64 value);

#endif // NUMBERS_H
