/* Every cast_<from>_to_<to>, at the edges of every target type.
   GENERATED expectations: computed with exact arithmetic, independently of numbers.c. */
#include <float.h>
#include <math.h>
#include <stdint.h>

#include "hammerc.h"

#include "numbers.h"

void test_numbers_cast_from_u8(HammerCtx *t)
{
    CHECK_EQ_UINT(cast_u8_to_u8((u8)0ULL), 0ULL);
    CHECK_EQ_INT(cast_u8_to_i8((u8)0ULL), 0LL);
    CHECK_EQ_UINT(cast_u8_to_u16((u8)0ULL), 0ULL);
    CHECK_EQ_INT(cast_u8_to_i16((u8)0ULL), 0LL);
    CHECK_EQ_UINT(cast_u8_to_u32((u8)0ULL), 0ULL);
    CHECK_EQ_INT(cast_u8_to_i32((u8)0ULL), 0LL);
    CHECK_EQ_UINT(cast_u8_to_u64((u8)0ULL), 0ULL);
    CHECK_EQ_INT(cast_u8_to_i64((u8)0ULL), 0LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u8_to_size_t((u8)0ULL), 0ULL);
#endif
    CHECK(cast_u8_to_f32((u8)0ULL) == 0.0f);
    CHECK(cast_u8_to_f64((u8)0ULL) == 0.0);
    CHECK_EQ_UINT(cast_u8_to_u8((u8)1ULL), 1ULL);
    CHECK_EQ_INT(cast_u8_to_i8((u8)1ULL), 1LL);
    CHECK_EQ_UINT(cast_u8_to_u16((u8)1ULL), 1ULL);
    CHECK_EQ_INT(cast_u8_to_i16((u8)1ULL), 1LL);
    CHECK_EQ_UINT(cast_u8_to_u32((u8)1ULL), 1ULL);
    CHECK_EQ_INT(cast_u8_to_i32((u8)1ULL), 1LL);
    CHECK_EQ_UINT(cast_u8_to_u64((u8)1ULL), 1ULL);
    CHECK_EQ_INT(cast_u8_to_i64((u8)1ULL), 1LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u8_to_size_t((u8)1ULL), 1ULL);
#endif
    CHECK(cast_u8_to_f32((u8)1ULL) == 0x1.0000000000000p+0f);
    CHECK(cast_u8_to_f64((u8)1ULL) == 0x1.0000000000000p+0);
    CHECK_EQ_UINT(cast_u8_to_u8((u8)127ULL), 127ULL);
    CHECK_EQ_INT(cast_u8_to_i8((u8)127ULL), 127LL);
    CHECK_EQ_UINT(cast_u8_to_u16((u8)127ULL), 127ULL);
    CHECK_EQ_INT(cast_u8_to_i16((u8)127ULL), 127LL);
    CHECK_EQ_UINT(cast_u8_to_u32((u8)127ULL), 127ULL);
    CHECK_EQ_INT(cast_u8_to_i32((u8)127ULL), 127LL);
    CHECK_EQ_UINT(cast_u8_to_u64((u8)127ULL), 127ULL);
    CHECK_EQ_INT(cast_u8_to_i64((u8)127ULL), 127LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u8_to_size_t((u8)127ULL), 127ULL);
#endif
    CHECK(cast_u8_to_f32((u8)127ULL) == 0x1.fc00000000000p+6f);
    CHECK(cast_u8_to_f64((u8)127ULL) == 0x1.fc00000000000p+6);
    CHECK_EQ_UINT(cast_u8_to_u8((u8)128ULL), 128ULL);
    CHECK_EQ_INT(cast_u8_to_i8((u8)128ULL), 127LL);
    CHECK_EQ_UINT(cast_u8_to_u16((u8)128ULL), 128ULL);
    CHECK_EQ_INT(cast_u8_to_i16((u8)128ULL), 128LL);
    CHECK_EQ_UINT(cast_u8_to_u32((u8)128ULL), 128ULL);
    CHECK_EQ_INT(cast_u8_to_i32((u8)128ULL), 128LL);
    CHECK_EQ_UINT(cast_u8_to_u64((u8)128ULL), 128ULL);
    CHECK_EQ_INT(cast_u8_to_i64((u8)128ULL), 128LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u8_to_size_t((u8)128ULL), 128ULL);
#endif
    CHECK(cast_u8_to_f32((u8)128ULL) == 0x1.0000000000000p+7f);
    CHECK(cast_u8_to_f64((u8)128ULL) == 0x1.0000000000000p+7);
    CHECK_EQ_UINT(cast_u8_to_u8((u8)254ULL), 254ULL);
    CHECK_EQ_INT(cast_u8_to_i8((u8)254ULL), 127LL);
    CHECK_EQ_UINT(cast_u8_to_u16((u8)254ULL), 254ULL);
    CHECK_EQ_INT(cast_u8_to_i16((u8)254ULL), 254LL);
    CHECK_EQ_UINT(cast_u8_to_u32((u8)254ULL), 254ULL);
    CHECK_EQ_INT(cast_u8_to_i32((u8)254ULL), 254LL);
    CHECK_EQ_UINT(cast_u8_to_u64((u8)254ULL), 254ULL);
    CHECK_EQ_INT(cast_u8_to_i64((u8)254ULL), 254LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u8_to_size_t((u8)254ULL), 254ULL);
#endif
    CHECK(cast_u8_to_f32((u8)254ULL) == 0x1.fc00000000000p+7f);
    CHECK(cast_u8_to_f64((u8)254ULL) == 0x1.fc00000000000p+7);
    CHECK_EQ_UINT(cast_u8_to_u8((u8)255ULL), 255ULL);
    CHECK_EQ_INT(cast_u8_to_i8((u8)255ULL), 127LL);
    CHECK_EQ_UINT(cast_u8_to_u16((u8)255ULL), 255ULL);
    CHECK_EQ_INT(cast_u8_to_i16((u8)255ULL), 255LL);
    CHECK_EQ_UINT(cast_u8_to_u32((u8)255ULL), 255ULL);
    CHECK_EQ_INT(cast_u8_to_i32((u8)255ULL), 255LL);
    CHECK_EQ_UINT(cast_u8_to_u64((u8)255ULL), 255ULL);
    CHECK_EQ_INT(cast_u8_to_i64((u8)255ULL), 255LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u8_to_size_t((u8)255ULL), 255ULL);
#endif
    CHECK(cast_u8_to_f32((u8)255ULL) == 0x1.fe00000000000p+7f);
    CHECK(cast_u8_to_f64((u8)255ULL) == 0x1.fe00000000000p+7);
}

void test_numbers_cast_from_i8(HammerCtx *t)
{
    CHECK_EQ_UINT(cast_i8_to_u8((i8)(-128LL)), 0ULL);
    CHECK_EQ_INT(cast_i8_to_i8((i8)(-128LL)), (-128LL));
    CHECK_EQ_UINT(cast_i8_to_u16((i8)(-128LL)), 0ULL);
    CHECK_EQ_INT(cast_i8_to_i16((i8)(-128LL)), (-128LL));
    CHECK_EQ_UINT(cast_i8_to_u32((i8)(-128LL)), 0ULL);
    CHECK_EQ_INT(cast_i8_to_i32((i8)(-128LL)), (-128LL));
    CHECK_EQ_UINT(cast_i8_to_u64((i8)(-128LL)), 0ULL);
    CHECK_EQ_INT(cast_i8_to_i64((i8)(-128LL)), (-128LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i8_to_size_t((i8)(-128LL)), 0ULL);
#endif
    CHECK(cast_i8_to_f32((i8)(-128LL)) == -0x1.0000000000000p+7f);
    CHECK(cast_i8_to_f64((i8)(-128LL)) == -0x1.0000000000000p+7);
    CHECK_EQ_UINT(cast_i8_to_u8((i8)(-127LL)), 0ULL);
    CHECK_EQ_INT(cast_i8_to_i8((i8)(-127LL)), (-127LL));
    CHECK_EQ_UINT(cast_i8_to_u16((i8)(-127LL)), 0ULL);
    CHECK_EQ_INT(cast_i8_to_i16((i8)(-127LL)), (-127LL));
    CHECK_EQ_UINT(cast_i8_to_u32((i8)(-127LL)), 0ULL);
    CHECK_EQ_INT(cast_i8_to_i32((i8)(-127LL)), (-127LL));
    CHECK_EQ_UINT(cast_i8_to_u64((i8)(-127LL)), 0ULL);
    CHECK_EQ_INT(cast_i8_to_i64((i8)(-127LL)), (-127LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i8_to_size_t((i8)(-127LL)), 0ULL);
#endif
    CHECK(cast_i8_to_f32((i8)(-127LL)) == -0x1.fc00000000000p+6f);
    CHECK(cast_i8_to_f64((i8)(-127LL)) == -0x1.fc00000000000p+6);
    CHECK_EQ_UINT(cast_i8_to_u8((i8)(-1LL)), 0ULL);
    CHECK_EQ_INT(cast_i8_to_i8((i8)(-1LL)), (-1LL));
    CHECK_EQ_UINT(cast_i8_to_u16((i8)(-1LL)), 0ULL);
    CHECK_EQ_INT(cast_i8_to_i16((i8)(-1LL)), (-1LL));
    CHECK_EQ_UINT(cast_i8_to_u32((i8)(-1LL)), 0ULL);
    CHECK_EQ_INT(cast_i8_to_i32((i8)(-1LL)), (-1LL));
    CHECK_EQ_UINT(cast_i8_to_u64((i8)(-1LL)), 0ULL);
    CHECK_EQ_INT(cast_i8_to_i64((i8)(-1LL)), (-1LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i8_to_size_t((i8)(-1LL)), 0ULL);
#endif
    CHECK(cast_i8_to_f32((i8)(-1LL)) == -0x1.0000000000000p+0f);
    CHECK(cast_i8_to_f64((i8)(-1LL)) == -0x1.0000000000000p+0);
    CHECK_EQ_UINT(cast_i8_to_u8((i8)0LL), 0ULL);
    CHECK_EQ_INT(cast_i8_to_i8((i8)0LL), 0LL);
    CHECK_EQ_UINT(cast_i8_to_u16((i8)0LL), 0ULL);
    CHECK_EQ_INT(cast_i8_to_i16((i8)0LL), 0LL);
    CHECK_EQ_UINT(cast_i8_to_u32((i8)0LL), 0ULL);
    CHECK_EQ_INT(cast_i8_to_i32((i8)0LL), 0LL);
    CHECK_EQ_UINT(cast_i8_to_u64((i8)0LL), 0ULL);
    CHECK_EQ_INT(cast_i8_to_i64((i8)0LL), 0LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i8_to_size_t((i8)0LL), 0ULL);
#endif
    CHECK(cast_i8_to_f32((i8)0LL) == 0.0f);
    CHECK(cast_i8_to_f64((i8)0LL) == 0.0);
    CHECK_EQ_UINT(cast_i8_to_u8((i8)1LL), 1ULL);
    CHECK_EQ_INT(cast_i8_to_i8((i8)1LL), 1LL);
    CHECK_EQ_UINT(cast_i8_to_u16((i8)1LL), 1ULL);
    CHECK_EQ_INT(cast_i8_to_i16((i8)1LL), 1LL);
    CHECK_EQ_UINT(cast_i8_to_u32((i8)1LL), 1ULL);
    CHECK_EQ_INT(cast_i8_to_i32((i8)1LL), 1LL);
    CHECK_EQ_UINT(cast_i8_to_u64((i8)1LL), 1ULL);
    CHECK_EQ_INT(cast_i8_to_i64((i8)1LL), 1LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i8_to_size_t((i8)1LL), 1ULL);
#endif
    CHECK(cast_i8_to_f32((i8)1LL) == 0x1.0000000000000p+0f);
    CHECK(cast_i8_to_f64((i8)1LL) == 0x1.0000000000000p+0);
    CHECK_EQ_UINT(cast_i8_to_u8((i8)126LL), 126ULL);
    CHECK_EQ_INT(cast_i8_to_i8((i8)126LL), 126LL);
    CHECK_EQ_UINT(cast_i8_to_u16((i8)126LL), 126ULL);
    CHECK_EQ_INT(cast_i8_to_i16((i8)126LL), 126LL);
    CHECK_EQ_UINT(cast_i8_to_u32((i8)126LL), 126ULL);
    CHECK_EQ_INT(cast_i8_to_i32((i8)126LL), 126LL);
    CHECK_EQ_UINT(cast_i8_to_u64((i8)126LL), 126ULL);
    CHECK_EQ_INT(cast_i8_to_i64((i8)126LL), 126LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i8_to_size_t((i8)126LL), 126ULL);
#endif
    CHECK(cast_i8_to_f32((i8)126LL) == 0x1.f800000000000p+6f);
    CHECK(cast_i8_to_f64((i8)126LL) == 0x1.f800000000000p+6);
    CHECK_EQ_UINT(cast_i8_to_u8((i8)127LL), 127ULL);
    CHECK_EQ_INT(cast_i8_to_i8((i8)127LL), 127LL);
    CHECK_EQ_UINT(cast_i8_to_u16((i8)127LL), 127ULL);
    CHECK_EQ_INT(cast_i8_to_i16((i8)127LL), 127LL);
    CHECK_EQ_UINT(cast_i8_to_u32((i8)127LL), 127ULL);
    CHECK_EQ_INT(cast_i8_to_i32((i8)127LL), 127LL);
    CHECK_EQ_UINT(cast_i8_to_u64((i8)127LL), 127ULL);
    CHECK_EQ_INT(cast_i8_to_i64((i8)127LL), 127LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i8_to_size_t((i8)127LL), 127ULL);
#endif
    CHECK(cast_i8_to_f32((i8)127LL) == 0x1.fc00000000000p+6f);
    CHECK(cast_i8_to_f64((i8)127LL) == 0x1.fc00000000000p+6);
}

void test_numbers_cast_from_u16(HammerCtx *t)
{
    CHECK_EQ_UINT(cast_u16_to_u8((u16)0ULL), 0ULL);
    CHECK_EQ_INT(cast_u16_to_i8((u16)0ULL), 0LL);
    CHECK_EQ_UINT(cast_u16_to_u16((u16)0ULL), 0ULL);
    CHECK_EQ_INT(cast_u16_to_i16((u16)0ULL), 0LL);
    CHECK_EQ_UINT(cast_u16_to_u32((u16)0ULL), 0ULL);
    CHECK_EQ_INT(cast_u16_to_i32((u16)0ULL), 0LL);
    CHECK_EQ_UINT(cast_u16_to_u64((u16)0ULL), 0ULL);
    CHECK_EQ_INT(cast_u16_to_i64((u16)0ULL), 0LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u16_to_size_t((u16)0ULL), 0ULL);
#endif
    CHECK(cast_u16_to_f32((u16)0ULL) == 0.0f);
    CHECK(cast_u16_to_f64((u16)0ULL) == 0.0);
    CHECK_EQ_UINT(cast_u16_to_u8((u16)1ULL), 1ULL);
    CHECK_EQ_INT(cast_u16_to_i8((u16)1ULL), 1LL);
    CHECK_EQ_UINT(cast_u16_to_u16((u16)1ULL), 1ULL);
    CHECK_EQ_INT(cast_u16_to_i16((u16)1ULL), 1LL);
    CHECK_EQ_UINT(cast_u16_to_u32((u16)1ULL), 1ULL);
    CHECK_EQ_INT(cast_u16_to_i32((u16)1ULL), 1LL);
    CHECK_EQ_UINT(cast_u16_to_u64((u16)1ULL), 1ULL);
    CHECK_EQ_INT(cast_u16_to_i64((u16)1ULL), 1LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u16_to_size_t((u16)1ULL), 1ULL);
#endif
    CHECK(cast_u16_to_f32((u16)1ULL) == 0x1.0000000000000p+0f);
    CHECK(cast_u16_to_f64((u16)1ULL) == 0x1.0000000000000p+0);
    CHECK_EQ_UINT(cast_u16_to_u8((u16)127ULL), 127ULL);
    CHECK_EQ_INT(cast_u16_to_i8((u16)127ULL), 127LL);
    CHECK_EQ_UINT(cast_u16_to_u16((u16)127ULL), 127ULL);
    CHECK_EQ_INT(cast_u16_to_i16((u16)127ULL), 127LL);
    CHECK_EQ_UINT(cast_u16_to_u32((u16)127ULL), 127ULL);
    CHECK_EQ_INT(cast_u16_to_i32((u16)127ULL), 127LL);
    CHECK_EQ_UINT(cast_u16_to_u64((u16)127ULL), 127ULL);
    CHECK_EQ_INT(cast_u16_to_i64((u16)127ULL), 127LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u16_to_size_t((u16)127ULL), 127ULL);
#endif
    CHECK(cast_u16_to_f32((u16)127ULL) == 0x1.fc00000000000p+6f);
    CHECK(cast_u16_to_f64((u16)127ULL) == 0x1.fc00000000000p+6);
    CHECK_EQ_UINT(cast_u16_to_u8((u16)128ULL), 128ULL);
    CHECK_EQ_INT(cast_u16_to_i8((u16)128ULL), 127LL);
    CHECK_EQ_UINT(cast_u16_to_u16((u16)128ULL), 128ULL);
    CHECK_EQ_INT(cast_u16_to_i16((u16)128ULL), 128LL);
    CHECK_EQ_UINT(cast_u16_to_u32((u16)128ULL), 128ULL);
    CHECK_EQ_INT(cast_u16_to_i32((u16)128ULL), 128LL);
    CHECK_EQ_UINT(cast_u16_to_u64((u16)128ULL), 128ULL);
    CHECK_EQ_INT(cast_u16_to_i64((u16)128ULL), 128LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u16_to_size_t((u16)128ULL), 128ULL);
#endif
    CHECK(cast_u16_to_f32((u16)128ULL) == 0x1.0000000000000p+7f);
    CHECK(cast_u16_to_f64((u16)128ULL) == 0x1.0000000000000p+7);
    CHECK_EQ_UINT(cast_u16_to_u8((u16)255ULL), 255ULL);
    CHECK_EQ_INT(cast_u16_to_i8((u16)255ULL), 127LL);
    CHECK_EQ_UINT(cast_u16_to_u16((u16)255ULL), 255ULL);
    CHECK_EQ_INT(cast_u16_to_i16((u16)255ULL), 255LL);
    CHECK_EQ_UINT(cast_u16_to_u32((u16)255ULL), 255ULL);
    CHECK_EQ_INT(cast_u16_to_i32((u16)255ULL), 255LL);
    CHECK_EQ_UINT(cast_u16_to_u64((u16)255ULL), 255ULL);
    CHECK_EQ_INT(cast_u16_to_i64((u16)255ULL), 255LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u16_to_size_t((u16)255ULL), 255ULL);
#endif
    CHECK(cast_u16_to_f32((u16)255ULL) == 0x1.fe00000000000p+7f);
    CHECK(cast_u16_to_f64((u16)255ULL) == 0x1.fe00000000000p+7);
    CHECK_EQ_UINT(cast_u16_to_u8((u16)256ULL), 255ULL);
    CHECK_EQ_INT(cast_u16_to_i8((u16)256ULL), 127LL);
    CHECK_EQ_UINT(cast_u16_to_u16((u16)256ULL), 256ULL);
    CHECK_EQ_INT(cast_u16_to_i16((u16)256ULL), 256LL);
    CHECK_EQ_UINT(cast_u16_to_u32((u16)256ULL), 256ULL);
    CHECK_EQ_INT(cast_u16_to_i32((u16)256ULL), 256LL);
    CHECK_EQ_UINT(cast_u16_to_u64((u16)256ULL), 256ULL);
    CHECK_EQ_INT(cast_u16_to_i64((u16)256ULL), 256LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u16_to_size_t((u16)256ULL), 256ULL);
#endif
    CHECK(cast_u16_to_f32((u16)256ULL) == 0x1.0000000000000p+8f);
    CHECK(cast_u16_to_f64((u16)256ULL) == 0x1.0000000000000p+8);
    CHECK_EQ_UINT(cast_u16_to_u8((u16)32767ULL), 255ULL);
    CHECK_EQ_INT(cast_u16_to_i8((u16)32767ULL), 127LL);
    CHECK_EQ_UINT(cast_u16_to_u16((u16)32767ULL), 32767ULL);
    CHECK_EQ_INT(cast_u16_to_i16((u16)32767ULL), 32767LL);
    CHECK_EQ_UINT(cast_u16_to_u32((u16)32767ULL), 32767ULL);
    CHECK_EQ_INT(cast_u16_to_i32((u16)32767ULL), 32767LL);
    CHECK_EQ_UINT(cast_u16_to_u64((u16)32767ULL), 32767ULL);
    CHECK_EQ_INT(cast_u16_to_i64((u16)32767ULL), 32767LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u16_to_size_t((u16)32767ULL), 32767ULL);
#endif
    CHECK(cast_u16_to_f32((u16)32767ULL) == 0x1.fffc000000000p+14f);
    CHECK(cast_u16_to_f64((u16)32767ULL) == 0x1.fffc000000000p+14);
    CHECK_EQ_UINT(cast_u16_to_u8((u16)32768ULL), 255ULL);
    CHECK_EQ_INT(cast_u16_to_i8((u16)32768ULL), 127LL);
    CHECK_EQ_UINT(cast_u16_to_u16((u16)32768ULL), 32768ULL);
    CHECK_EQ_INT(cast_u16_to_i16((u16)32768ULL), 32767LL);
    CHECK_EQ_UINT(cast_u16_to_u32((u16)32768ULL), 32768ULL);
    CHECK_EQ_INT(cast_u16_to_i32((u16)32768ULL), 32768LL);
    CHECK_EQ_UINT(cast_u16_to_u64((u16)32768ULL), 32768ULL);
    CHECK_EQ_INT(cast_u16_to_i64((u16)32768ULL), 32768LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u16_to_size_t((u16)32768ULL), 32768ULL);
#endif
    CHECK(cast_u16_to_f32((u16)32768ULL) == 0x1.0000000000000p+15f);
    CHECK(cast_u16_to_f64((u16)32768ULL) == 0x1.0000000000000p+15);
    CHECK_EQ_UINT(cast_u16_to_u8((u16)65534ULL), 255ULL);
    CHECK_EQ_INT(cast_u16_to_i8((u16)65534ULL), 127LL);
    CHECK_EQ_UINT(cast_u16_to_u16((u16)65534ULL), 65534ULL);
    CHECK_EQ_INT(cast_u16_to_i16((u16)65534ULL), 32767LL);
    CHECK_EQ_UINT(cast_u16_to_u32((u16)65534ULL), 65534ULL);
    CHECK_EQ_INT(cast_u16_to_i32((u16)65534ULL), 65534LL);
    CHECK_EQ_UINT(cast_u16_to_u64((u16)65534ULL), 65534ULL);
    CHECK_EQ_INT(cast_u16_to_i64((u16)65534ULL), 65534LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u16_to_size_t((u16)65534ULL), 65534ULL);
#endif
    CHECK(cast_u16_to_f32((u16)65534ULL) == 0x1.fffc000000000p+15f);
    CHECK(cast_u16_to_f64((u16)65534ULL) == 0x1.fffc000000000p+15);
    CHECK_EQ_UINT(cast_u16_to_u8((u16)65535ULL), 255ULL);
    CHECK_EQ_INT(cast_u16_to_i8((u16)65535ULL), 127LL);
    CHECK_EQ_UINT(cast_u16_to_u16((u16)65535ULL), 65535ULL);
    CHECK_EQ_INT(cast_u16_to_i16((u16)65535ULL), 32767LL);
    CHECK_EQ_UINT(cast_u16_to_u32((u16)65535ULL), 65535ULL);
    CHECK_EQ_INT(cast_u16_to_i32((u16)65535ULL), 65535LL);
    CHECK_EQ_UINT(cast_u16_to_u64((u16)65535ULL), 65535ULL);
    CHECK_EQ_INT(cast_u16_to_i64((u16)65535ULL), 65535LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u16_to_size_t((u16)65535ULL), 65535ULL);
#endif
    CHECK(cast_u16_to_f32((u16)65535ULL) == 0x1.fffe000000000p+15f);
    CHECK(cast_u16_to_f64((u16)65535ULL) == 0x1.fffe000000000p+15);
}

void test_numbers_cast_from_i16(HammerCtx *t)
{
    CHECK_EQ_UINT(cast_i16_to_u8((i16)(-32768LL)), 0ULL);
    CHECK_EQ_INT(cast_i16_to_i8((i16)(-32768LL)), (-128LL));
    CHECK_EQ_UINT(cast_i16_to_u16((i16)(-32768LL)), 0ULL);
    CHECK_EQ_INT(cast_i16_to_i16((i16)(-32768LL)), (-32768LL));
    CHECK_EQ_UINT(cast_i16_to_u32((i16)(-32768LL)), 0ULL);
    CHECK_EQ_INT(cast_i16_to_i32((i16)(-32768LL)), (-32768LL));
    CHECK_EQ_UINT(cast_i16_to_u64((i16)(-32768LL)), 0ULL);
    CHECK_EQ_INT(cast_i16_to_i64((i16)(-32768LL)), (-32768LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i16_to_size_t((i16)(-32768LL)), 0ULL);
#endif
    CHECK(cast_i16_to_f32((i16)(-32768LL)) == -0x1.0000000000000p+15f);
    CHECK(cast_i16_to_f64((i16)(-32768LL)) == -0x1.0000000000000p+15);
    CHECK_EQ_UINT(cast_i16_to_u8((i16)(-32767LL)), 0ULL);
    CHECK_EQ_INT(cast_i16_to_i8((i16)(-32767LL)), (-128LL));
    CHECK_EQ_UINT(cast_i16_to_u16((i16)(-32767LL)), 0ULL);
    CHECK_EQ_INT(cast_i16_to_i16((i16)(-32767LL)), (-32767LL));
    CHECK_EQ_UINT(cast_i16_to_u32((i16)(-32767LL)), 0ULL);
    CHECK_EQ_INT(cast_i16_to_i32((i16)(-32767LL)), (-32767LL));
    CHECK_EQ_UINT(cast_i16_to_u64((i16)(-32767LL)), 0ULL);
    CHECK_EQ_INT(cast_i16_to_i64((i16)(-32767LL)), (-32767LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i16_to_size_t((i16)(-32767LL)), 0ULL);
#endif
    CHECK(cast_i16_to_f32((i16)(-32767LL)) == -0x1.fffc000000000p+14f);
    CHECK(cast_i16_to_f64((i16)(-32767LL)) == -0x1.fffc000000000p+14);
    CHECK_EQ_UINT(cast_i16_to_u8((i16)(-129LL)), 0ULL);
    CHECK_EQ_INT(cast_i16_to_i8((i16)(-129LL)), (-128LL));
    CHECK_EQ_UINT(cast_i16_to_u16((i16)(-129LL)), 0ULL);
    CHECK_EQ_INT(cast_i16_to_i16((i16)(-129LL)), (-129LL));
    CHECK_EQ_UINT(cast_i16_to_u32((i16)(-129LL)), 0ULL);
    CHECK_EQ_INT(cast_i16_to_i32((i16)(-129LL)), (-129LL));
    CHECK_EQ_UINT(cast_i16_to_u64((i16)(-129LL)), 0ULL);
    CHECK_EQ_INT(cast_i16_to_i64((i16)(-129LL)), (-129LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i16_to_size_t((i16)(-129LL)), 0ULL);
#endif
    CHECK(cast_i16_to_f32((i16)(-129LL)) == -0x1.0200000000000p+7f);
    CHECK(cast_i16_to_f64((i16)(-129LL)) == -0x1.0200000000000p+7);
    CHECK_EQ_UINT(cast_i16_to_u8((i16)(-128LL)), 0ULL);
    CHECK_EQ_INT(cast_i16_to_i8((i16)(-128LL)), (-128LL));
    CHECK_EQ_UINT(cast_i16_to_u16((i16)(-128LL)), 0ULL);
    CHECK_EQ_INT(cast_i16_to_i16((i16)(-128LL)), (-128LL));
    CHECK_EQ_UINT(cast_i16_to_u32((i16)(-128LL)), 0ULL);
    CHECK_EQ_INT(cast_i16_to_i32((i16)(-128LL)), (-128LL));
    CHECK_EQ_UINT(cast_i16_to_u64((i16)(-128LL)), 0ULL);
    CHECK_EQ_INT(cast_i16_to_i64((i16)(-128LL)), (-128LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i16_to_size_t((i16)(-128LL)), 0ULL);
#endif
    CHECK(cast_i16_to_f32((i16)(-128LL)) == -0x1.0000000000000p+7f);
    CHECK(cast_i16_to_f64((i16)(-128LL)) == -0x1.0000000000000p+7);
    CHECK_EQ_UINT(cast_i16_to_u8((i16)(-1LL)), 0ULL);
    CHECK_EQ_INT(cast_i16_to_i8((i16)(-1LL)), (-1LL));
    CHECK_EQ_UINT(cast_i16_to_u16((i16)(-1LL)), 0ULL);
    CHECK_EQ_INT(cast_i16_to_i16((i16)(-1LL)), (-1LL));
    CHECK_EQ_UINT(cast_i16_to_u32((i16)(-1LL)), 0ULL);
    CHECK_EQ_INT(cast_i16_to_i32((i16)(-1LL)), (-1LL));
    CHECK_EQ_UINT(cast_i16_to_u64((i16)(-1LL)), 0ULL);
    CHECK_EQ_INT(cast_i16_to_i64((i16)(-1LL)), (-1LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i16_to_size_t((i16)(-1LL)), 0ULL);
#endif
    CHECK(cast_i16_to_f32((i16)(-1LL)) == -0x1.0000000000000p+0f);
    CHECK(cast_i16_to_f64((i16)(-1LL)) == -0x1.0000000000000p+0);
    CHECK_EQ_UINT(cast_i16_to_u8((i16)0LL), 0ULL);
    CHECK_EQ_INT(cast_i16_to_i8((i16)0LL), 0LL);
    CHECK_EQ_UINT(cast_i16_to_u16((i16)0LL), 0ULL);
    CHECK_EQ_INT(cast_i16_to_i16((i16)0LL), 0LL);
    CHECK_EQ_UINT(cast_i16_to_u32((i16)0LL), 0ULL);
    CHECK_EQ_INT(cast_i16_to_i32((i16)0LL), 0LL);
    CHECK_EQ_UINT(cast_i16_to_u64((i16)0LL), 0ULL);
    CHECK_EQ_INT(cast_i16_to_i64((i16)0LL), 0LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i16_to_size_t((i16)0LL), 0ULL);
#endif
    CHECK(cast_i16_to_f32((i16)0LL) == 0.0f);
    CHECK(cast_i16_to_f64((i16)0LL) == 0.0);
    CHECK_EQ_UINT(cast_i16_to_u8((i16)1LL), 1ULL);
    CHECK_EQ_INT(cast_i16_to_i8((i16)1LL), 1LL);
    CHECK_EQ_UINT(cast_i16_to_u16((i16)1LL), 1ULL);
    CHECK_EQ_INT(cast_i16_to_i16((i16)1LL), 1LL);
    CHECK_EQ_UINT(cast_i16_to_u32((i16)1LL), 1ULL);
    CHECK_EQ_INT(cast_i16_to_i32((i16)1LL), 1LL);
    CHECK_EQ_UINT(cast_i16_to_u64((i16)1LL), 1ULL);
    CHECK_EQ_INT(cast_i16_to_i64((i16)1LL), 1LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i16_to_size_t((i16)1LL), 1ULL);
#endif
    CHECK(cast_i16_to_f32((i16)1LL) == 0x1.0000000000000p+0f);
    CHECK(cast_i16_to_f64((i16)1LL) == 0x1.0000000000000p+0);
    CHECK_EQ_UINT(cast_i16_to_u8((i16)127LL), 127ULL);
    CHECK_EQ_INT(cast_i16_to_i8((i16)127LL), 127LL);
    CHECK_EQ_UINT(cast_i16_to_u16((i16)127LL), 127ULL);
    CHECK_EQ_INT(cast_i16_to_i16((i16)127LL), 127LL);
    CHECK_EQ_UINT(cast_i16_to_u32((i16)127LL), 127ULL);
    CHECK_EQ_INT(cast_i16_to_i32((i16)127LL), 127LL);
    CHECK_EQ_UINT(cast_i16_to_u64((i16)127LL), 127ULL);
    CHECK_EQ_INT(cast_i16_to_i64((i16)127LL), 127LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i16_to_size_t((i16)127LL), 127ULL);
#endif
    CHECK(cast_i16_to_f32((i16)127LL) == 0x1.fc00000000000p+6f);
    CHECK(cast_i16_to_f64((i16)127LL) == 0x1.fc00000000000p+6);
    CHECK_EQ_UINT(cast_i16_to_u8((i16)128LL), 128ULL);
    CHECK_EQ_INT(cast_i16_to_i8((i16)128LL), 127LL);
    CHECK_EQ_UINT(cast_i16_to_u16((i16)128LL), 128ULL);
    CHECK_EQ_INT(cast_i16_to_i16((i16)128LL), 128LL);
    CHECK_EQ_UINT(cast_i16_to_u32((i16)128LL), 128ULL);
    CHECK_EQ_INT(cast_i16_to_i32((i16)128LL), 128LL);
    CHECK_EQ_UINT(cast_i16_to_u64((i16)128LL), 128ULL);
    CHECK_EQ_INT(cast_i16_to_i64((i16)128LL), 128LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i16_to_size_t((i16)128LL), 128ULL);
#endif
    CHECK(cast_i16_to_f32((i16)128LL) == 0x1.0000000000000p+7f);
    CHECK(cast_i16_to_f64((i16)128LL) == 0x1.0000000000000p+7);
    CHECK_EQ_UINT(cast_i16_to_u8((i16)255LL), 255ULL);
    CHECK_EQ_INT(cast_i16_to_i8((i16)255LL), 127LL);
    CHECK_EQ_UINT(cast_i16_to_u16((i16)255LL), 255ULL);
    CHECK_EQ_INT(cast_i16_to_i16((i16)255LL), 255LL);
    CHECK_EQ_UINT(cast_i16_to_u32((i16)255LL), 255ULL);
    CHECK_EQ_INT(cast_i16_to_i32((i16)255LL), 255LL);
    CHECK_EQ_UINT(cast_i16_to_u64((i16)255LL), 255ULL);
    CHECK_EQ_INT(cast_i16_to_i64((i16)255LL), 255LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i16_to_size_t((i16)255LL), 255ULL);
#endif
    CHECK(cast_i16_to_f32((i16)255LL) == 0x1.fe00000000000p+7f);
    CHECK(cast_i16_to_f64((i16)255LL) == 0x1.fe00000000000p+7);
    CHECK_EQ_UINT(cast_i16_to_u8((i16)256LL), 255ULL);
    CHECK_EQ_INT(cast_i16_to_i8((i16)256LL), 127LL);
    CHECK_EQ_UINT(cast_i16_to_u16((i16)256LL), 256ULL);
    CHECK_EQ_INT(cast_i16_to_i16((i16)256LL), 256LL);
    CHECK_EQ_UINT(cast_i16_to_u32((i16)256LL), 256ULL);
    CHECK_EQ_INT(cast_i16_to_i32((i16)256LL), 256LL);
    CHECK_EQ_UINT(cast_i16_to_u64((i16)256LL), 256ULL);
    CHECK_EQ_INT(cast_i16_to_i64((i16)256LL), 256LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i16_to_size_t((i16)256LL), 256ULL);
#endif
    CHECK(cast_i16_to_f32((i16)256LL) == 0x1.0000000000000p+8f);
    CHECK(cast_i16_to_f64((i16)256LL) == 0x1.0000000000000p+8);
    CHECK_EQ_UINT(cast_i16_to_u8((i16)32766LL), 255ULL);
    CHECK_EQ_INT(cast_i16_to_i8((i16)32766LL), 127LL);
    CHECK_EQ_UINT(cast_i16_to_u16((i16)32766LL), 32766ULL);
    CHECK_EQ_INT(cast_i16_to_i16((i16)32766LL), 32766LL);
    CHECK_EQ_UINT(cast_i16_to_u32((i16)32766LL), 32766ULL);
    CHECK_EQ_INT(cast_i16_to_i32((i16)32766LL), 32766LL);
    CHECK_EQ_UINT(cast_i16_to_u64((i16)32766LL), 32766ULL);
    CHECK_EQ_INT(cast_i16_to_i64((i16)32766LL), 32766LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i16_to_size_t((i16)32766LL), 32766ULL);
#endif
    CHECK(cast_i16_to_f32((i16)32766LL) == 0x1.fff8000000000p+14f);
    CHECK(cast_i16_to_f64((i16)32766LL) == 0x1.fff8000000000p+14);
    CHECK_EQ_UINT(cast_i16_to_u8((i16)32767LL), 255ULL);
    CHECK_EQ_INT(cast_i16_to_i8((i16)32767LL), 127LL);
    CHECK_EQ_UINT(cast_i16_to_u16((i16)32767LL), 32767ULL);
    CHECK_EQ_INT(cast_i16_to_i16((i16)32767LL), 32767LL);
    CHECK_EQ_UINT(cast_i16_to_u32((i16)32767LL), 32767ULL);
    CHECK_EQ_INT(cast_i16_to_i32((i16)32767LL), 32767LL);
    CHECK_EQ_UINT(cast_i16_to_u64((i16)32767LL), 32767ULL);
    CHECK_EQ_INT(cast_i16_to_i64((i16)32767LL), 32767LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i16_to_size_t((i16)32767LL), 32767ULL);
#endif
    CHECK(cast_i16_to_f32((i16)32767LL) == 0x1.fffc000000000p+14f);
    CHECK(cast_i16_to_f64((i16)32767LL) == 0x1.fffc000000000p+14);
}

void test_numbers_cast_from_u32(HammerCtx *t)
{
    CHECK_EQ_UINT(cast_u32_to_u8((u32)0ULL), 0ULL);
    CHECK_EQ_INT(cast_u32_to_i8((u32)0ULL), 0LL);
    CHECK_EQ_UINT(cast_u32_to_u16((u32)0ULL), 0ULL);
    CHECK_EQ_INT(cast_u32_to_i16((u32)0ULL), 0LL);
    CHECK_EQ_UINT(cast_u32_to_u32((u32)0ULL), 0ULL);
    CHECK_EQ_INT(cast_u32_to_i32((u32)0ULL), 0LL);
    CHECK_EQ_UINT(cast_u32_to_u64((u32)0ULL), 0ULL);
    CHECK_EQ_INT(cast_u32_to_i64((u32)0ULL), 0LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u32_to_size_t((u32)0ULL), 0ULL);
#endif
    CHECK(cast_u32_to_f32((u32)0ULL) == 0.0f);
    CHECK(cast_u32_to_f64((u32)0ULL) == 0.0);
    CHECK_EQ_UINT(cast_u32_to_u8((u32)1ULL), 1ULL);
    CHECK_EQ_INT(cast_u32_to_i8((u32)1ULL), 1LL);
    CHECK_EQ_UINT(cast_u32_to_u16((u32)1ULL), 1ULL);
    CHECK_EQ_INT(cast_u32_to_i16((u32)1ULL), 1LL);
    CHECK_EQ_UINT(cast_u32_to_u32((u32)1ULL), 1ULL);
    CHECK_EQ_INT(cast_u32_to_i32((u32)1ULL), 1LL);
    CHECK_EQ_UINT(cast_u32_to_u64((u32)1ULL), 1ULL);
    CHECK_EQ_INT(cast_u32_to_i64((u32)1ULL), 1LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u32_to_size_t((u32)1ULL), 1ULL);
#endif
    CHECK(cast_u32_to_f32((u32)1ULL) == 0x1.0000000000000p+0f);
    CHECK(cast_u32_to_f64((u32)1ULL) == 0x1.0000000000000p+0);
    CHECK_EQ_UINT(cast_u32_to_u8((u32)127ULL), 127ULL);
    CHECK_EQ_INT(cast_u32_to_i8((u32)127ULL), 127LL);
    CHECK_EQ_UINT(cast_u32_to_u16((u32)127ULL), 127ULL);
    CHECK_EQ_INT(cast_u32_to_i16((u32)127ULL), 127LL);
    CHECK_EQ_UINT(cast_u32_to_u32((u32)127ULL), 127ULL);
    CHECK_EQ_INT(cast_u32_to_i32((u32)127ULL), 127LL);
    CHECK_EQ_UINT(cast_u32_to_u64((u32)127ULL), 127ULL);
    CHECK_EQ_INT(cast_u32_to_i64((u32)127ULL), 127LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u32_to_size_t((u32)127ULL), 127ULL);
#endif
    CHECK(cast_u32_to_f32((u32)127ULL) == 0x1.fc00000000000p+6f);
    CHECK(cast_u32_to_f64((u32)127ULL) == 0x1.fc00000000000p+6);
    CHECK_EQ_UINT(cast_u32_to_u8((u32)128ULL), 128ULL);
    CHECK_EQ_INT(cast_u32_to_i8((u32)128ULL), 127LL);
    CHECK_EQ_UINT(cast_u32_to_u16((u32)128ULL), 128ULL);
    CHECK_EQ_INT(cast_u32_to_i16((u32)128ULL), 128LL);
    CHECK_EQ_UINT(cast_u32_to_u32((u32)128ULL), 128ULL);
    CHECK_EQ_INT(cast_u32_to_i32((u32)128ULL), 128LL);
    CHECK_EQ_UINT(cast_u32_to_u64((u32)128ULL), 128ULL);
    CHECK_EQ_INT(cast_u32_to_i64((u32)128ULL), 128LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u32_to_size_t((u32)128ULL), 128ULL);
#endif
    CHECK(cast_u32_to_f32((u32)128ULL) == 0x1.0000000000000p+7f);
    CHECK(cast_u32_to_f64((u32)128ULL) == 0x1.0000000000000p+7);
    CHECK_EQ_UINT(cast_u32_to_u8((u32)255ULL), 255ULL);
    CHECK_EQ_INT(cast_u32_to_i8((u32)255ULL), 127LL);
    CHECK_EQ_UINT(cast_u32_to_u16((u32)255ULL), 255ULL);
    CHECK_EQ_INT(cast_u32_to_i16((u32)255ULL), 255LL);
    CHECK_EQ_UINT(cast_u32_to_u32((u32)255ULL), 255ULL);
    CHECK_EQ_INT(cast_u32_to_i32((u32)255ULL), 255LL);
    CHECK_EQ_UINT(cast_u32_to_u64((u32)255ULL), 255ULL);
    CHECK_EQ_INT(cast_u32_to_i64((u32)255ULL), 255LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u32_to_size_t((u32)255ULL), 255ULL);
#endif
    CHECK(cast_u32_to_f32((u32)255ULL) == 0x1.fe00000000000p+7f);
    CHECK(cast_u32_to_f64((u32)255ULL) == 0x1.fe00000000000p+7);
    CHECK_EQ_UINT(cast_u32_to_u8((u32)256ULL), 255ULL);
    CHECK_EQ_INT(cast_u32_to_i8((u32)256ULL), 127LL);
    CHECK_EQ_UINT(cast_u32_to_u16((u32)256ULL), 256ULL);
    CHECK_EQ_INT(cast_u32_to_i16((u32)256ULL), 256LL);
    CHECK_EQ_UINT(cast_u32_to_u32((u32)256ULL), 256ULL);
    CHECK_EQ_INT(cast_u32_to_i32((u32)256ULL), 256LL);
    CHECK_EQ_UINT(cast_u32_to_u64((u32)256ULL), 256ULL);
    CHECK_EQ_INT(cast_u32_to_i64((u32)256ULL), 256LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u32_to_size_t((u32)256ULL), 256ULL);
#endif
    CHECK(cast_u32_to_f32((u32)256ULL) == 0x1.0000000000000p+8f);
    CHECK(cast_u32_to_f64((u32)256ULL) == 0x1.0000000000000p+8);
    CHECK_EQ_UINT(cast_u32_to_u8((u32)32767ULL), 255ULL);
    CHECK_EQ_INT(cast_u32_to_i8((u32)32767ULL), 127LL);
    CHECK_EQ_UINT(cast_u32_to_u16((u32)32767ULL), 32767ULL);
    CHECK_EQ_INT(cast_u32_to_i16((u32)32767ULL), 32767LL);
    CHECK_EQ_UINT(cast_u32_to_u32((u32)32767ULL), 32767ULL);
    CHECK_EQ_INT(cast_u32_to_i32((u32)32767ULL), 32767LL);
    CHECK_EQ_UINT(cast_u32_to_u64((u32)32767ULL), 32767ULL);
    CHECK_EQ_INT(cast_u32_to_i64((u32)32767ULL), 32767LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u32_to_size_t((u32)32767ULL), 32767ULL);
#endif
    CHECK(cast_u32_to_f32((u32)32767ULL) == 0x1.fffc000000000p+14f);
    CHECK(cast_u32_to_f64((u32)32767ULL) == 0x1.fffc000000000p+14);
    CHECK_EQ_UINT(cast_u32_to_u8((u32)32768ULL), 255ULL);
    CHECK_EQ_INT(cast_u32_to_i8((u32)32768ULL), 127LL);
    CHECK_EQ_UINT(cast_u32_to_u16((u32)32768ULL), 32768ULL);
    CHECK_EQ_INT(cast_u32_to_i16((u32)32768ULL), 32767LL);
    CHECK_EQ_UINT(cast_u32_to_u32((u32)32768ULL), 32768ULL);
    CHECK_EQ_INT(cast_u32_to_i32((u32)32768ULL), 32768LL);
    CHECK_EQ_UINT(cast_u32_to_u64((u32)32768ULL), 32768ULL);
    CHECK_EQ_INT(cast_u32_to_i64((u32)32768ULL), 32768LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u32_to_size_t((u32)32768ULL), 32768ULL);
#endif
    CHECK(cast_u32_to_f32((u32)32768ULL) == 0x1.0000000000000p+15f);
    CHECK(cast_u32_to_f64((u32)32768ULL) == 0x1.0000000000000p+15);
    CHECK_EQ_UINT(cast_u32_to_u8((u32)65535ULL), 255ULL);
    CHECK_EQ_INT(cast_u32_to_i8((u32)65535ULL), 127LL);
    CHECK_EQ_UINT(cast_u32_to_u16((u32)65535ULL), 65535ULL);
    CHECK_EQ_INT(cast_u32_to_i16((u32)65535ULL), 32767LL);
    CHECK_EQ_UINT(cast_u32_to_u32((u32)65535ULL), 65535ULL);
    CHECK_EQ_INT(cast_u32_to_i32((u32)65535ULL), 65535LL);
    CHECK_EQ_UINT(cast_u32_to_u64((u32)65535ULL), 65535ULL);
    CHECK_EQ_INT(cast_u32_to_i64((u32)65535ULL), 65535LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u32_to_size_t((u32)65535ULL), 65535ULL);
#endif
    CHECK(cast_u32_to_f32((u32)65535ULL) == 0x1.fffe000000000p+15f);
    CHECK(cast_u32_to_f64((u32)65535ULL) == 0x1.fffe000000000p+15);
    CHECK_EQ_UINT(cast_u32_to_u8((u32)65536ULL), 255ULL);
    CHECK_EQ_INT(cast_u32_to_i8((u32)65536ULL), 127LL);
    CHECK_EQ_UINT(cast_u32_to_u16((u32)65536ULL), 65535ULL);
    CHECK_EQ_INT(cast_u32_to_i16((u32)65536ULL), 32767LL);
    CHECK_EQ_UINT(cast_u32_to_u32((u32)65536ULL), 65536ULL);
    CHECK_EQ_INT(cast_u32_to_i32((u32)65536ULL), 65536LL);
    CHECK_EQ_UINT(cast_u32_to_u64((u32)65536ULL), 65536ULL);
    CHECK_EQ_INT(cast_u32_to_i64((u32)65536ULL), 65536LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u32_to_size_t((u32)65536ULL), 65536ULL);
#endif
    CHECK(cast_u32_to_f32((u32)65536ULL) == 0x1.0000000000000p+16f);
    CHECK(cast_u32_to_f64((u32)65536ULL) == 0x1.0000000000000p+16);
    CHECK_EQ_UINT(cast_u32_to_u8((u32)2147483647ULL), 255ULL);
    CHECK_EQ_INT(cast_u32_to_i8((u32)2147483647ULL), 127LL);
    CHECK_EQ_UINT(cast_u32_to_u16((u32)2147483647ULL), 65535ULL);
    CHECK_EQ_INT(cast_u32_to_i16((u32)2147483647ULL), 32767LL);
    CHECK_EQ_UINT(cast_u32_to_u32((u32)2147483647ULL), 2147483647ULL);
    CHECK_EQ_INT(cast_u32_to_i32((u32)2147483647ULL), 2147483647LL);
    CHECK_EQ_UINT(cast_u32_to_u64((u32)2147483647ULL), 2147483647ULL);
    CHECK_EQ_INT(cast_u32_to_i64((u32)2147483647ULL), 2147483647LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u32_to_size_t((u32)2147483647ULL), 2147483647ULL);
#endif
    CHECK(cast_u32_to_f64((u32)2147483647ULL) == 0x1.fffffffc00000p+30);
    CHECK_EQ_UINT(cast_u32_to_u8((u32)2147483648ULL), 255ULL);
    CHECK_EQ_INT(cast_u32_to_i8((u32)2147483648ULL), 127LL);
    CHECK_EQ_UINT(cast_u32_to_u16((u32)2147483648ULL), 65535ULL);
    CHECK_EQ_INT(cast_u32_to_i16((u32)2147483648ULL), 32767LL);
    CHECK_EQ_UINT(cast_u32_to_u32((u32)2147483648ULL), 2147483648ULL);
    CHECK_EQ_INT(cast_u32_to_i32((u32)2147483648ULL), 2147483647LL);
    CHECK_EQ_UINT(cast_u32_to_u64((u32)2147483648ULL), 2147483648ULL);
    CHECK_EQ_INT(cast_u32_to_i64((u32)2147483648ULL), 2147483648LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u32_to_size_t((u32)2147483648ULL), 2147483648ULL);
#endif
    CHECK(cast_u32_to_f32((u32)2147483648ULL) == 0x1.0000000000000p+31f);
    CHECK(cast_u32_to_f64((u32)2147483648ULL) == 0x1.0000000000000p+31);
    CHECK_EQ_UINT(cast_u32_to_u8((u32)4294967294ULL), 255ULL);
    CHECK_EQ_INT(cast_u32_to_i8((u32)4294967294ULL), 127LL);
    CHECK_EQ_UINT(cast_u32_to_u16((u32)4294967294ULL), 65535ULL);
    CHECK_EQ_INT(cast_u32_to_i16((u32)4294967294ULL), 32767LL);
    CHECK_EQ_UINT(cast_u32_to_u32((u32)4294967294ULL), 4294967294ULL);
    CHECK_EQ_INT(cast_u32_to_i32((u32)4294967294ULL), 2147483647LL);
    CHECK_EQ_UINT(cast_u32_to_u64((u32)4294967294ULL), 4294967294ULL);
    CHECK_EQ_INT(cast_u32_to_i64((u32)4294967294ULL), 4294967294LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u32_to_size_t((u32)4294967294ULL), 4294967294ULL);
#endif
    CHECK(cast_u32_to_f64((u32)4294967294ULL) == 0x1.fffffffc00000p+31);
    CHECK_EQ_UINT(cast_u32_to_u8((u32)4294967295ULL), 255ULL);
    CHECK_EQ_INT(cast_u32_to_i8((u32)4294967295ULL), 127LL);
    CHECK_EQ_UINT(cast_u32_to_u16((u32)4294967295ULL), 65535ULL);
    CHECK_EQ_INT(cast_u32_to_i16((u32)4294967295ULL), 32767LL);
    CHECK_EQ_UINT(cast_u32_to_u32((u32)4294967295ULL), 4294967295ULL);
    CHECK_EQ_INT(cast_u32_to_i32((u32)4294967295ULL), 2147483647LL);
    CHECK_EQ_UINT(cast_u32_to_u64((u32)4294967295ULL), 4294967295ULL);
    CHECK_EQ_INT(cast_u32_to_i64((u32)4294967295ULL), 4294967295LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u32_to_size_t((u32)4294967295ULL), 4294967295ULL);
#endif
    CHECK(cast_u32_to_f64((u32)4294967295ULL) == 0x1.fffffffe00000p+31);
}

void test_numbers_cast_from_i32(HammerCtx *t)
{
    CHECK_EQ_UINT(cast_i32_to_u8((i32)(-2147483648LL)), 0ULL);
    CHECK_EQ_INT(cast_i32_to_i8((i32)(-2147483648LL)), (-128LL));
    CHECK_EQ_UINT(cast_i32_to_u16((i32)(-2147483648LL)), 0ULL);
    CHECK_EQ_INT(cast_i32_to_i16((i32)(-2147483648LL)), (-32768LL));
    CHECK_EQ_UINT(cast_i32_to_u32((i32)(-2147483648LL)), 0ULL);
    CHECK_EQ_INT(cast_i32_to_i32((i32)(-2147483648LL)), (-2147483648LL));
    CHECK_EQ_UINT(cast_i32_to_u64((i32)(-2147483648LL)), 0ULL);
    CHECK_EQ_INT(cast_i32_to_i64((i32)(-2147483648LL)), (-2147483648LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i32_to_size_t((i32)(-2147483648LL)), 0ULL);
#endif
    CHECK(cast_i32_to_f32((i32)(-2147483648LL)) == -0x1.0000000000000p+31f);
    CHECK(cast_i32_to_f64((i32)(-2147483648LL)) == -0x1.0000000000000p+31);
    CHECK_EQ_UINT(cast_i32_to_u8((i32)(-2147483647LL)), 0ULL);
    CHECK_EQ_INT(cast_i32_to_i8((i32)(-2147483647LL)), (-128LL));
    CHECK_EQ_UINT(cast_i32_to_u16((i32)(-2147483647LL)), 0ULL);
    CHECK_EQ_INT(cast_i32_to_i16((i32)(-2147483647LL)), (-32768LL));
    CHECK_EQ_UINT(cast_i32_to_u32((i32)(-2147483647LL)), 0ULL);
    CHECK_EQ_INT(cast_i32_to_i32((i32)(-2147483647LL)), (-2147483647LL));
    CHECK_EQ_UINT(cast_i32_to_u64((i32)(-2147483647LL)), 0ULL);
    CHECK_EQ_INT(cast_i32_to_i64((i32)(-2147483647LL)), (-2147483647LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i32_to_size_t((i32)(-2147483647LL)), 0ULL);
#endif
    CHECK(cast_i32_to_f64((i32)(-2147483647LL)) == -0x1.fffffffc00000p+30);
    CHECK_EQ_UINT(cast_i32_to_u8((i32)(-32769LL)), 0ULL);
    CHECK_EQ_INT(cast_i32_to_i8((i32)(-32769LL)), (-128LL));
    CHECK_EQ_UINT(cast_i32_to_u16((i32)(-32769LL)), 0ULL);
    CHECK_EQ_INT(cast_i32_to_i16((i32)(-32769LL)), (-32768LL));
    CHECK_EQ_UINT(cast_i32_to_u32((i32)(-32769LL)), 0ULL);
    CHECK_EQ_INT(cast_i32_to_i32((i32)(-32769LL)), (-32769LL));
    CHECK_EQ_UINT(cast_i32_to_u64((i32)(-32769LL)), 0ULL);
    CHECK_EQ_INT(cast_i32_to_i64((i32)(-32769LL)), (-32769LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i32_to_size_t((i32)(-32769LL)), 0ULL);
#endif
    CHECK(cast_i32_to_f32((i32)(-32769LL)) == -0x1.0002000000000p+15f);
    CHECK(cast_i32_to_f64((i32)(-32769LL)) == -0x1.0002000000000p+15);
    CHECK_EQ_UINT(cast_i32_to_u8((i32)(-32768LL)), 0ULL);
    CHECK_EQ_INT(cast_i32_to_i8((i32)(-32768LL)), (-128LL));
    CHECK_EQ_UINT(cast_i32_to_u16((i32)(-32768LL)), 0ULL);
    CHECK_EQ_INT(cast_i32_to_i16((i32)(-32768LL)), (-32768LL));
    CHECK_EQ_UINT(cast_i32_to_u32((i32)(-32768LL)), 0ULL);
    CHECK_EQ_INT(cast_i32_to_i32((i32)(-32768LL)), (-32768LL));
    CHECK_EQ_UINT(cast_i32_to_u64((i32)(-32768LL)), 0ULL);
    CHECK_EQ_INT(cast_i32_to_i64((i32)(-32768LL)), (-32768LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i32_to_size_t((i32)(-32768LL)), 0ULL);
#endif
    CHECK(cast_i32_to_f32((i32)(-32768LL)) == -0x1.0000000000000p+15f);
    CHECK(cast_i32_to_f64((i32)(-32768LL)) == -0x1.0000000000000p+15);
    CHECK_EQ_UINT(cast_i32_to_u8((i32)(-129LL)), 0ULL);
    CHECK_EQ_INT(cast_i32_to_i8((i32)(-129LL)), (-128LL));
    CHECK_EQ_UINT(cast_i32_to_u16((i32)(-129LL)), 0ULL);
    CHECK_EQ_INT(cast_i32_to_i16((i32)(-129LL)), (-129LL));
    CHECK_EQ_UINT(cast_i32_to_u32((i32)(-129LL)), 0ULL);
    CHECK_EQ_INT(cast_i32_to_i32((i32)(-129LL)), (-129LL));
    CHECK_EQ_UINT(cast_i32_to_u64((i32)(-129LL)), 0ULL);
    CHECK_EQ_INT(cast_i32_to_i64((i32)(-129LL)), (-129LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i32_to_size_t((i32)(-129LL)), 0ULL);
#endif
    CHECK(cast_i32_to_f32((i32)(-129LL)) == -0x1.0200000000000p+7f);
    CHECK(cast_i32_to_f64((i32)(-129LL)) == -0x1.0200000000000p+7);
    CHECK_EQ_UINT(cast_i32_to_u8((i32)(-128LL)), 0ULL);
    CHECK_EQ_INT(cast_i32_to_i8((i32)(-128LL)), (-128LL));
    CHECK_EQ_UINT(cast_i32_to_u16((i32)(-128LL)), 0ULL);
    CHECK_EQ_INT(cast_i32_to_i16((i32)(-128LL)), (-128LL));
    CHECK_EQ_UINT(cast_i32_to_u32((i32)(-128LL)), 0ULL);
    CHECK_EQ_INT(cast_i32_to_i32((i32)(-128LL)), (-128LL));
    CHECK_EQ_UINT(cast_i32_to_u64((i32)(-128LL)), 0ULL);
    CHECK_EQ_INT(cast_i32_to_i64((i32)(-128LL)), (-128LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i32_to_size_t((i32)(-128LL)), 0ULL);
#endif
    CHECK(cast_i32_to_f32((i32)(-128LL)) == -0x1.0000000000000p+7f);
    CHECK(cast_i32_to_f64((i32)(-128LL)) == -0x1.0000000000000p+7);
    CHECK_EQ_UINT(cast_i32_to_u8((i32)(-1LL)), 0ULL);
    CHECK_EQ_INT(cast_i32_to_i8((i32)(-1LL)), (-1LL));
    CHECK_EQ_UINT(cast_i32_to_u16((i32)(-1LL)), 0ULL);
    CHECK_EQ_INT(cast_i32_to_i16((i32)(-1LL)), (-1LL));
    CHECK_EQ_UINT(cast_i32_to_u32((i32)(-1LL)), 0ULL);
    CHECK_EQ_INT(cast_i32_to_i32((i32)(-1LL)), (-1LL));
    CHECK_EQ_UINT(cast_i32_to_u64((i32)(-1LL)), 0ULL);
    CHECK_EQ_INT(cast_i32_to_i64((i32)(-1LL)), (-1LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i32_to_size_t((i32)(-1LL)), 0ULL);
#endif
    CHECK(cast_i32_to_f32((i32)(-1LL)) == -0x1.0000000000000p+0f);
    CHECK(cast_i32_to_f64((i32)(-1LL)) == -0x1.0000000000000p+0);
    CHECK_EQ_UINT(cast_i32_to_u8((i32)0LL), 0ULL);
    CHECK_EQ_INT(cast_i32_to_i8((i32)0LL), 0LL);
    CHECK_EQ_UINT(cast_i32_to_u16((i32)0LL), 0ULL);
    CHECK_EQ_INT(cast_i32_to_i16((i32)0LL), 0LL);
    CHECK_EQ_UINT(cast_i32_to_u32((i32)0LL), 0ULL);
    CHECK_EQ_INT(cast_i32_to_i32((i32)0LL), 0LL);
    CHECK_EQ_UINT(cast_i32_to_u64((i32)0LL), 0ULL);
    CHECK_EQ_INT(cast_i32_to_i64((i32)0LL), 0LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i32_to_size_t((i32)0LL), 0ULL);
#endif
    CHECK(cast_i32_to_f32((i32)0LL) == 0.0f);
    CHECK(cast_i32_to_f64((i32)0LL) == 0.0);
    CHECK_EQ_UINT(cast_i32_to_u8((i32)1LL), 1ULL);
    CHECK_EQ_INT(cast_i32_to_i8((i32)1LL), 1LL);
    CHECK_EQ_UINT(cast_i32_to_u16((i32)1LL), 1ULL);
    CHECK_EQ_INT(cast_i32_to_i16((i32)1LL), 1LL);
    CHECK_EQ_UINT(cast_i32_to_u32((i32)1LL), 1ULL);
    CHECK_EQ_INT(cast_i32_to_i32((i32)1LL), 1LL);
    CHECK_EQ_UINT(cast_i32_to_u64((i32)1LL), 1ULL);
    CHECK_EQ_INT(cast_i32_to_i64((i32)1LL), 1LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i32_to_size_t((i32)1LL), 1ULL);
#endif
    CHECK(cast_i32_to_f32((i32)1LL) == 0x1.0000000000000p+0f);
    CHECK(cast_i32_to_f64((i32)1LL) == 0x1.0000000000000p+0);
    CHECK_EQ_UINT(cast_i32_to_u8((i32)127LL), 127ULL);
    CHECK_EQ_INT(cast_i32_to_i8((i32)127LL), 127LL);
    CHECK_EQ_UINT(cast_i32_to_u16((i32)127LL), 127ULL);
    CHECK_EQ_INT(cast_i32_to_i16((i32)127LL), 127LL);
    CHECK_EQ_UINT(cast_i32_to_u32((i32)127LL), 127ULL);
    CHECK_EQ_INT(cast_i32_to_i32((i32)127LL), 127LL);
    CHECK_EQ_UINT(cast_i32_to_u64((i32)127LL), 127ULL);
    CHECK_EQ_INT(cast_i32_to_i64((i32)127LL), 127LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i32_to_size_t((i32)127LL), 127ULL);
#endif
    CHECK(cast_i32_to_f32((i32)127LL) == 0x1.fc00000000000p+6f);
    CHECK(cast_i32_to_f64((i32)127LL) == 0x1.fc00000000000p+6);
    CHECK_EQ_UINT(cast_i32_to_u8((i32)128LL), 128ULL);
    CHECK_EQ_INT(cast_i32_to_i8((i32)128LL), 127LL);
    CHECK_EQ_UINT(cast_i32_to_u16((i32)128LL), 128ULL);
    CHECK_EQ_INT(cast_i32_to_i16((i32)128LL), 128LL);
    CHECK_EQ_UINT(cast_i32_to_u32((i32)128LL), 128ULL);
    CHECK_EQ_INT(cast_i32_to_i32((i32)128LL), 128LL);
    CHECK_EQ_UINT(cast_i32_to_u64((i32)128LL), 128ULL);
    CHECK_EQ_INT(cast_i32_to_i64((i32)128LL), 128LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i32_to_size_t((i32)128LL), 128ULL);
#endif
    CHECK(cast_i32_to_f32((i32)128LL) == 0x1.0000000000000p+7f);
    CHECK(cast_i32_to_f64((i32)128LL) == 0x1.0000000000000p+7);
    CHECK_EQ_UINT(cast_i32_to_u8((i32)255LL), 255ULL);
    CHECK_EQ_INT(cast_i32_to_i8((i32)255LL), 127LL);
    CHECK_EQ_UINT(cast_i32_to_u16((i32)255LL), 255ULL);
    CHECK_EQ_INT(cast_i32_to_i16((i32)255LL), 255LL);
    CHECK_EQ_UINT(cast_i32_to_u32((i32)255LL), 255ULL);
    CHECK_EQ_INT(cast_i32_to_i32((i32)255LL), 255LL);
    CHECK_EQ_UINT(cast_i32_to_u64((i32)255LL), 255ULL);
    CHECK_EQ_INT(cast_i32_to_i64((i32)255LL), 255LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i32_to_size_t((i32)255LL), 255ULL);
#endif
    CHECK(cast_i32_to_f32((i32)255LL) == 0x1.fe00000000000p+7f);
    CHECK(cast_i32_to_f64((i32)255LL) == 0x1.fe00000000000p+7);
    CHECK_EQ_UINT(cast_i32_to_u8((i32)256LL), 255ULL);
    CHECK_EQ_INT(cast_i32_to_i8((i32)256LL), 127LL);
    CHECK_EQ_UINT(cast_i32_to_u16((i32)256LL), 256ULL);
    CHECK_EQ_INT(cast_i32_to_i16((i32)256LL), 256LL);
    CHECK_EQ_UINT(cast_i32_to_u32((i32)256LL), 256ULL);
    CHECK_EQ_INT(cast_i32_to_i32((i32)256LL), 256LL);
    CHECK_EQ_UINT(cast_i32_to_u64((i32)256LL), 256ULL);
    CHECK_EQ_INT(cast_i32_to_i64((i32)256LL), 256LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i32_to_size_t((i32)256LL), 256ULL);
#endif
    CHECK(cast_i32_to_f32((i32)256LL) == 0x1.0000000000000p+8f);
    CHECK(cast_i32_to_f64((i32)256LL) == 0x1.0000000000000p+8);
    CHECK_EQ_UINT(cast_i32_to_u8((i32)32767LL), 255ULL);
    CHECK_EQ_INT(cast_i32_to_i8((i32)32767LL), 127LL);
    CHECK_EQ_UINT(cast_i32_to_u16((i32)32767LL), 32767ULL);
    CHECK_EQ_INT(cast_i32_to_i16((i32)32767LL), 32767LL);
    CHECK_EQ_UINT(cast_i32_to_u32((i32)32767LL), 32767ULL);
    CHECK_EQ_INT(cast_i32_to_i32((i32)32767LL), 32767LL);
    CHECK_EQ_UINT(cast_i32_to_u64((i32)32767LL), 32767ULL);
    CHECK_EQ_INT(cast_i32_to_i64((i32)32767LL), 32767LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i32_to_size_t((i32)32767LL), 32767ULL);
#endif
    CHECK(cast_i32_to_f32((i32)32767LL) == 0x1.fffc000000000p+14f);
    CHECK(cast_i32_to_f64((i32)32767LL) == 0x1.fffc000000000p+14);
    CHECK_EQ_UINT(cast_i32_to_u8((i32)32768LL), 255ULL);
    CHECK_EQ_INT(cast_i32_to_i8((i32)32768LL), 127LL);
    CHECK_EQ_UINT(cast_i32_to_u16((i32)32768LL), 32768ULL);
    CHECK_EQ_INT(cast_i32_to_i16((i32)32768LL), 32767LL);
    CHECK_EQ_UINT(cast_i32_to_u32((i32)32768LL), 32768ULL);
    CHECK_EQ_INT(cast_i32_to_i32((i32)32768LL), 32768LL);
    CHECK_EQ_UINT(cast_i32_to_u64((i32)32768LL), 32768ULL);
    CHECK_EQ_INT(cast_i32_to_i64((i32)32768LL), 32768LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i32_to_size_t((i32)32768LL), 32768ULL);
#endif
    CHECK(cast_i32_to_f32((i32)32768LL) == 0x1.0000000000000p+15f);
    CHECK(cast_i32_to_f64((i32)32768LL) == 0x1.0000000000000p+15);
    CHECK_EQ_UINT(cast_i32_to_u8((i32)65535LL), 255ULL);
    CHECK_EQ_INT(cast_i32_to_i8((i32)65535LL), 127LL);
    CHECK_EQ_UINT(cast_i32_to_u16((i32)65535LL), 65535ULL);
    CHECK_EQ_INT(cast_i32_to_i16((i32)65535LL), 32767LL);
    CHECK_EQ_UINT(cast_i32_to_u32((i32)65535LL), 65535ULL);
    CHECK_EQ_INT(cast_i32_to_i32((i32)65535LL), 65535LL);
    CHECK_EQ_UINT(cast_i32_to_u64((i32)65535LL), 65535ULL);
    CHECK_EQ_INT(cast_i32_to_i64((i32)65535LL), 65535LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i32_to_size_t((i32)65535LL), 65535ULL);
#endif
    CHECK(cast_i32_to_f32((i32)65535LL) == 0x1.fffe000000000p+15f);
    CHECK(cast_i32_to_f64((i32)65535LL) == 0x1.fffe000000000p+15);
    CHECK_EQ_UINT(cast_i32_to_u8((i32)65536LL), 255ULL);
    CHECK_EQ_INT(cast_i32_to_i8((i32)65536LL), 127LL);
    CHECK_EQ_UINT(cast_i32_to_u16((i32)65536LL), 65535ULL);
    CHECK_EQ_INT(cast_i32_to_i16((i32)65536LL), 32767LL);
    CHECK_EQ_UINT(cast_i32_to_u32((i32)65536LL), 65536ULL);
    CHECK_EQ_INT(cast_i32_to_i32((i32)65536LL), 65536LL);
    CHECK_EQ_UINT(cast_i32_to_u64((i32)65536LL), 65536ULL);
    CHECK_EQ_INT(cast_i32_to_i64((i32)65536LL), 65536LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i32_to_size_t((i32)65536LL), 65536ULL);
#endif
    CHECK(cast_i32_to_f32((i32)65536LL) == 0x1.0000000000000p+16f);
    CHECK(cast_i32_to_f64((i32)65536LL) == 0x1.0000000000000p+16);
    CHECK_EQ_UINT(cast_i32_to_u8((i32)2147483646LL), 255ULL);
    CHECK_EQ_INT(cast_i32_to_i8((i32)2147483646LL), 127LL);
    CHECK_EQ_UINT(cast_i32_to_u16((i32)2147483646LL), 65535ULL);
    CHECK_EQ_INT(cast_i32_to_i16((i32)2147483646LL), 32767LL);
    CHECK_EQ_UINT(cast_i32_to_u32((i32)2147483646LL), 2147483646ULL);
    CHECK_EQ_INT(cast_i32_to_i32((i32)2147483646LL), 2147483646LL);
    CHECK_EQ_UINT(cast_i32_to_u64((i32)2147483646LL), 2147483646ULL);
    CHECK_EQ_INT(cast_i32_to_i64((i32)2147483646LL), 2147483646LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i32_to_size_t((i32)2147483646LL), 2147483646ULL);
#endif
    CHECK(cast_i32_to_f64((i32)2147483646LL) == 0x1.fffffff800000p+30);
    CHECK_EQ_UINT(cast_i32_to_u8((i32)2147483647LL), 255ULL);
    CHECK_EQ_INT(cast_i32_to_i8((i32)2147483647LL), 127LL);
    CHECK_EQ_UINT(cast_i32_to_u16((i32)2147483647LL), 65535ULL);
    CHECK_EQ_INT(cast_i32_to_i16((i32)2147483647LL), 32767LL);
    CHECK_EQ_UINT(cast_i32_to_u32((i32)2147483647LL), 2147483647ULL);
    CHECK_EQ_INT(cast_i32_to_i32((i32)2147483647LL), 2147483647LL);
    CHECK_EQ_UINT(cast_i32_to_u64((i32)2147483647LL), 2147483647ULL);
    CHECK_EQ_INT(cast_i32_to_i64((i32)2147483647LL), 2147483647LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i32_to_size_t((i32)2147483647LL), 2147483647ULL);
#endif
    CHECK(cast_i32_to_f64((i32)2147483647LL) == 0x1.fffffffc00000p+30);
}

void test_numbers_cast_from_u64(HammerCtx *t)
{
    CHECK_EQ_UINT(cast_u64_to_u8((u64)0ULL), 0ULL);
    CHECK_EQ_INT(cast_u64_to_i8((u64)0ULL), 0LL);
    CHECK_EQ_UINT(cast_u64_to_u16((u64)0ULL), 0ULL);
    CHECK_EQ_INT(cast_u64_to_i16((u64)0ULL), 0LL);
    CHECK_EQ_UINT(cast_u64_to_u32((u64)0ULL), 0ULL);
    CHECK_EQ_INT(cast_u64_to_i32((u64)0ULL), 0LL);
    CHECK_EQ_UINT(cast_u64_to_u64((u64)0ULL), 0ULL);
    CHECK_EQ_INT(cast_u64_to_i64((u64)0ULL), 0LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u64_to_size_t((u64)0ULL), 0ULL);
#endif
    CHECK(cast_u64_to_f32((u64)0ULL) == 0.0f);
    CHECK(cast_u64_to_f64((u64)0ULL) == 0.0);
    CHECK_EQ_UINT(cast_u64_to_u8((u64)1ULL), 1ULL);
    CHECK_EQ_INT(cast_u64_to_i8((u64)1ULL), 1LL);
    CHECK_EQ_UINT(cast_u64_to_u16((u64)1ULL), 1ULL);
    CHECK_EQ_INT(cast_u64_to_i16((u64)1ULL), 1LL);
    CHECK_EQ_UINT(cast_u64_to_u32((u64)1ULL), 1ULL);
    CHECK_EQ_INT(cast_u64_to_i32((u64)1ULL), 1LL);
    CHECK_EQ_UINT(cast_u64_to_u64((u64)1ULL), 1ULL);
    CHECK_EQ_INT(cast_u64_to_i64((u64)1ULL), 1LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u64_to_size_t((u64)1ULL), 1ULL);
#endif
    CHECK(cast_u64_to_f32((u64)1ULL) == 0x1.0000000000000p+0f);
    CHECK(cast_u64_to_f64((u64)1ULL) == 0x1.0000000000000p+0);
    CHECK_EQ_UINT(cast_u64_to_u8((u64)127ULL), 127ULL);
    CHECK_EQ_INT(cast_u64_to_i8((u64)127ULL), 127LL);
    CHECK_EQ_UINT(cast_u64_to_u16((u64)127ULL), 127ULL);
    CHECK_EQ_INT(cast_u64_to_i16((u64)127ULL), 127LL);
    CHECK_EQ_UINT(cast_u64_to_u32((u64)127ULL), 127ULL);
    CHECK_EQ_INT(cast_u64_to_i32((u64)127ULL), 127LL);
    CHECK_EQ_UINT(cast_u64_to_u64((u64)127ULL), 127ULL);
    CHECK_EQ_INT(cast_u64_to_i64((u64)127ULL), 127LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u64_to_size_t((u64)127ULL), 127ULL);
#endif
    CHECK(cast_u64_to_f32((u64)127ULL) == 0x1.fc00000000000p+6f);
    CHECK(cast_u64_to_f64((u64)127ULL) == 0x1.fc00000000000p+6);
    CHECK_EQ_UINT(cast_u64_to_u8((u64)128ULL), 128ULL);
    CHECK_EQ_INT(cast_u64_to_i8((u64)128ULL), 127LL);
    CHECK_EQ_UINT(cast_u64_to_u16((u64)128ULL), 128ULL);
    CHECK_EQ_INT(cast_u64_to_i16((u64)128ULL), 128LL);
    CHECK_EQ_UINT(cast_u64_to_u32((u64)128ULL), 128ULL);
    CHECK_EQ_INT(cast_u64_to_i32((u64)128ULL), 128LL);
    CHECK_EQ_UINT(cast_u64_to_u64((u64)128ULL), 128ULL);
    CHECK_EQ_INT(cast_u64_to_i64((u64)128ULL), 128LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u64_to_size_t((u64)128ULL), 128ULL);
#endif
    CHECK(cast_u64_to_f32((u64)128ULL) == 0x1.0000000000000p+7f);
    CHECK(cast_u64_to_f64((u64)128ULL) == 0x1.0000000000000p+7);
    CHECK_EQ_UINT(cast_u64_to_u8((u64)255ULL), 255ULL);
    CHECK_EQ_INT(cast_u64_to_i8((u64)255ULL), 127LL);
    CHECK_EQ_UINT(cast_u64_to_u16((u64)255ULL), 255ULL);
    CHECK_EQ_INT(cast_u64_to_i16((u64)255ULL), 255LL);
    CHECK_EQ_UINT(cast_u64_to_u32((u64)255ULL), 255ULL);
    CHECK_EQ_INT(cast_u64_to_i32((u64)255ULL), 255LL);
    CHECK_EQ_UINT(cast_u64_to_u64((u64)255ULL), 255ULL);
    CHECK_EQ_INT(cast_u64_to_i64((u64)255ULL), 255LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u64_to_size_t((u64)255ULL), 255ULL);
#endif
    CHECK(cast_u64_to_f32((u64)255ULL) == 0x1.fe00000000000p+7f);
    CHECK(cast_u64_to_f64((u64)255ULL) == 0x1.fe00000000000p+7);
    CHECK_EQ_UINT(cast_u64_to_u8((u64)256ULL), 255ULL);
    CHECK_EQ_INT(cast_u64_to_i8((u64)256ULL), 127LL);
    CHECK_EQ_UINT(cast_u64_to_u16((u64)256ULL), 256ULL);
    CHECK_EQ_INT(cast_u64_to_i16((u64)256ULL), 256LL);
    CHECK_EQ_UINT(cast_u64_to_u32((u64)256ULL), 256ULL);
    CHECK_EQ_INT(cast_u64_to_i32((u64)256ULL), 256LL);
    CHECK_EQ_UINT(cast_u64_to_u64((u64)256ULL), 256ULL);
    CHECK_EQ_INT(cast_u64_to_i64((u64)256ULL), 256LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u64_to_size_t((u64)256ULL), 256ULL);
#endif
    CHECK(cast_u64_to_f32((u64)256ULL) == 0x1.0000000000000p+8f);
    CHECK(cast_u64_to_f64((u64)256ULL) == 0x1.0000000000000p+8);
    CHECK_EQ_UINT(cast_u64_to_u8((u64)32767ULL), 255ULL);
    CHECK_EQ_INT(cast_u64_to_i8((u64)32767ULL), 127LL);
    CHECK_EQ_UINT(cast_u64_to_u16((u64)32767ULL), 32767ULL);
    CHECK_EQ_INT(cast_u64_to_i16((u64)32767ULL), 32767LL);
    CHECK_EQ_UINT(cast_u64_to_u32((u64)32767ULL), 32767ULL);
    CHECK_EQ_INT(cast_u64_to_i32((u64)32767ULL), 32767LL);
    CHECK_EQ_UINT(cast_u64_to_u64((u64)32767ULL), 32767ULL);
    CHECK_EQ_INT(cast_u64_to_i64((u64)32767ULL), 32767LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u64_to_size_t((u64)32767ULL), 32767ULL);
#endif
    CHECK(cast_u64_to_f32((u64)32767ULL) == 0x1.fffc000000000p+14f);
    CHECK(cast_u64_to_f64((u64)32767ULL) == 0x1.fffc000000000p+14);
    CHECK_EQ_UINT(cast_u64_to_u8((u64)32768ULL), 255ULL);
    CHECK_EQ_INT(cast_u64_to_i8((u64)32768ULL), 127LL);
    CHECK_EQ_UINT(cast_u64_to_u16((u64)32768ULL), 32768ULL);
    CHECK_EQ_INT(cast_u64_to_i16((u64)32768ULL), 32767LL);
    CHECK_EQ_UINT(cast_u64_to_u32((u64)32768ULL), 32768ULL);
    CHECK_EQ_INT(cast_u64_to_i32((u64)32768ULL), 32768LL);
    CHECK_EQ_UINT(cast_u64_to_u64((u64)32768ULL), 32768ULL);
    CHECK_EQ_INT(cast_u64_to_i64((u64)32768ULL), 32768LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u64_to_size_t((u64)32768ULL), 32768ULL);
#endif
    CHECK(cast_u64_to_f32((u64)32768ULL) == 0x1.0000000000000p+15f);
    CHECK(cast_u64_to_f64((u64)32768ULL) == 0x1.0000000000000p+15);
    CHECK_EQ_UINT(cast_u64_to_u8((u64)65535ULL), 255ULL);
    CHECK_EQ_INT(cast_u64_to_i8((u64)65535ULL), 127LL);
    CHECK_EQ_UINT(cast_u64_to_u16((u64)65535ULL), 65535ULL);
    CHECK_EQ_INT(cast_u64_to_i16((u64)65535ULL), 32767LL);
    CHECK_EQ_UINT(cast_u64_to_u32((u64)65535ULL), 65535ULL);
    CHECK_EQ_INT(cast_u64_to_i32((u64)65535ULL), 65535LL);
    CHECK_EQ_UINT(cast_u64_to_u64((u64)65535ULL), 65535ULL);
    CHECK_EQ_INT(cast_u64_to_i64((u64)65535ULL), 65535LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u64_to_size_t((u64)65535ULL), 65535ULL);
#endif
    CHECK(cast_u64_to_f32((u64)65535ULL) == 0x1.fffe000000000p+15f);
    CHECK(cast_u64_to_f64((u64)65535ULL) == 0x1.fffe000000000p+15);
    CHECK_EQ_UINT(cast_u64_to_u8((u64)65536ULL), 255ULL);
    CHECK_EQ_INT(cast_u64_to_i8((u64)65536ULL), 127LL);
    CHECK_EQ_UINT(cast_u64_to_u16((u64)65536ULL), 65535ULL);
    CHECK_EQ_INT(cast_u64_to_i16((u64)65536ULL), 32767LL);
    CHECK_EQ_UINT(cast_u64_to_u32((u64)65536ULL), 65536ULL);
    CHECK_EQ_INT(cast_u64_to_i32((u64)65536ULL), 65536LL);
    CHECK_EQ_UINT(cast_u64_to_u64((u64)65536ULL), 65536ULL);
    CHECK_EQ_INT(cast_u64_to_i64((u64)65536ULL), 65536LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u64_to_size_t((u64)65536ULL), 65536ULL);
#endif
    CHECK(cast_u64_to_f32((u64)65536ULL) == 0x1.0000000000000p+16f);
    CHECK(cast_u64_to_f64((u64)65536ULL) == 0x1.0000000000000p+16);
    CHECK_EQ_UINT(cast_u64_to_u8((u64)2147483647ULL), 255ULL);
    CHECK_EQ_INT(cast_u64_to_i8((u64)2147483647ULL), 127LL);
    CHECK_EQ_UINT(cast_u64_to_u16((u64)2147483647ULL), 65535ULL);
    CHECK_EQ_INT(cast_u64_to_i16((u64)2147483647ULL), 32767LL);
    CHECK_EQ_UINT(cast_u64_to_u32((u64)2147483647ULL), 2147483647ULL);
    CHECK_EQ_INT(cast_u64_to_i32((u64)2147483647ULL), 2147483647LL);
    CHECK_EQ_UINT(cast_u64_to_u64((u64)2147483647ULL), 2147483647ULL);
    CHECK_EQ_INT(cast_u64_to_i64((u64)2147483647ULL), 2147483647LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u64_to_size_t((u64)2147483647ULL), 2147483647ULL);
#endif
    CHECK(cast_u64_to_f64((u64)2147483647ULL) == 0x1.fffffffc00000p+30);
    CHECK_EQ_UINT(cast_u64_to_u8((u64)2147483648ULL), 255ULL);
    CHECK_EQ_INT(cast_u64_to_i8((u64)2147483648ULL), 127LL);
    CHECK_EQ_UINT(cast_u64_to_u16((u64)2147483648ULL), 65535ULL);
    CHECK_EQ_INT(cast_u64_to_i16((u64)2147483648ULL), 32767LL);
    CHECK_EQ_UINT(cast_u64_to_u32((u64)2147483648ULL), 2147483648ULL);
    CHECK_EQ_INT(cast_u64_to_i32((u64)2147483648ULL), 2147483647LL);
    CHECK_EQ_UINT(cast_u64_to_u64((u64)2147483648ULL), 2147483648ULL);
    CHECK_EQ_INT(cast_u64_to_i64((u64)2147483648ULL), 2147483648LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u64_to_size_t((u64)2147483648ULL), 2147483648ULL);
#endif
    CHECK(cast_u64_to_f32((u64)2147483648ULL) == 0x1.0000000000000p+31f);
    CHECK(cast_u64_to_f64((u64)2147483648ULL) == 0x1.0000000000000p+31);
    CHECK_EQ_UINT(cast_u64_to_u8((u64)4294967295ULL), 255ULL);
    CHECK_EQ_INT(cast_u64_to_i8((u64)4294967295ULL), 127LL);
    CHECK_EQ_UINT(cast_u64_to_u16((u64)4294967295ULL), 65535ULL);
    CHECK_EQ_INT(cast_u64_to_i16((u64)4294967295ULL), 32767LL);
    CHECK_EQ_UINT(cast_u64_to_u32((u64)4294967295ULL), 4294967295ULL);
    CHECK_EQ_INT(cast_u64_to_i32((u64)4294967295ULL), 2147483647LL);
    CHECK_EQ_UINT(cast_u64_to_u64((u64)4294967295ULL), 4294967295ULL);
    CHECK_EQ_INT(cast_u64_to_i64((u64)4294967295ULL), 4294967295LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u64_to_size_t((u64)4294967295ULL), 4294967295ULL);
#endif
    CHECK(cast_u64_to_f64((u64)4294967295ULL) == 0x1.fffffffe00000p+31);
    CHECK_EQ_UINT(cast_u64_to_u8((u64)4294967296ULL), 255ULL);
    CHECK_EQ_INT(cast_u64_to_i8((u64)4294967296ULL), 127LL);
    CHECK_EQ_UINT(cast_u64_to_u16((u64)4294967296ULL), 65535ULL);
    CHECK_EQ_INT(cast_u64_to_i16((u64)4294967296ULL), 32767LL);
    CHECK_EQ_UINT(cast_u64_to_u32((u64)4294967296ULL), 4294967295ULL);
    CHECK_EQ_INT(cast_u64_to_i32((u64)4294967296ULL), 2147483647LL);
    CHECK_EQ_UINT(cast_u64_to_u64((u64)4294967296ULL), 4294967296ULL);
    CHECK_EQ_INT(cast_u64_to_i64((u64)4294967296ULL), 4294967296LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u64_to_size_t((u64)4294967296ULL), 4294967296ULL);
#endif
    CHECK(cast_u64_to_f32((u64)4294967296ULL) == 0x1.0000000000000p+32f);
    CHECK(cast_u64_to_f64((u64)4294967296ULL) == 0x1.0000000000000p+32);
    CHECK_EQ_UINT(cast_u64_to_u8((u64)9223372036854775807ULL), 255ULL);
    CHECK_EQ_INT(cast_u64_to_i8((u64)9223372036854775807ULL), 127LL);
    CHECK_EQ_UINT(cast_u64_to_u16((u64)9223372036854775807ULL), 65535ULL);
    CHECK_EQ_INT(cast_u64_to_i16((u64)9223372036854775807ULL), 32767LL);
    CHECK_EQ_UINT(cast_u64_to_u32((u64)9223372036854775807ULL), 4294967295ULL);
    CHECK_EQ_INT(cast_u64_to_i32((u64)9223372036854775807ULL), 2147483647LL);
    CHECK_EQ_UINT(cast_u64_to_u64((u64)9223372036854775807ULL), 9223372036854775807ULL);
    CHECK_EQ_INT(cast_u64_to_i64((u64)9223372036854775807ULL), 9223372036854775807LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u64_to_size_t((u64)9223372036854775807ULL), 9223372036854775807ULL);
#endif
    CHECK_EQ_UINT(cast_u64_to_u8((u64)9223372036854775808ULL), 255ULL);
    CHECK_EQ_INT(cast_u64_to_i8((u64)9223372036854775808ULL), 127LL);
    CHECK_EQ_UINT(cast_u64_to_u16((u64)9223372036854775808ULL), 65535ULL);
    CHECK_EQ_INT(cast_u64_to_i16((u64)9223372036854775808ULL), 32767LL);
    CHECK_EQ_UINT(cast_u64_to_u32((u64)9223372036854775808ULL), 4294967295ULL);
    CHECK_EQ_INT(cast_u64_to_i32((u64)9223372036854775808ULL), 2147483647LL);
    CHECK_EQ_UINT(cast_u64_to_u64((u64)9223372036854775808ULL), 9223372036854775808ULL);
    CHECK_EQ_INT(cast_u64_to_i64((u64)9223372036854775808ULL), 9223372036854775807LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u64_to_size_t((u64)9223372036854775808ULL), 9223372036854775808ULL);
#endif
    CHECK(cast_u64_to_f32((u64)9223372036854775808ULL) == 0x1.0000000000000p+63f);
    CHECK(cast_u64_to_f64((u64)9223372036854775808ULL) == 0x1.0000000000000p+63);
    CHECK_EQ_UINT(cast_u64_to_u8((u64)18446744073709551614ULL), 255ULL);
    CHECK_EQ_INT(cast_u64_to_i8((u64)18446744073709551614ULL), 127LL);
    CHECK_EQ_UINT(cast_u64_to_u16((u64)18446744073709551614ULL), 65535ULL);
    CHECK_EQ_INT(cast_u64_to_i16((u64)18446744073709551614ULL), 32767LL);
    CHECK_EQ_UINT(cast_u64_to_u32((u64)18446744073709551614ULL), 4294967295ULL);
    CHECK_EQ_INT(cast_u64_to_i32((u64)18446744073709551614ULL), 2147483647LL);
    CHECK_EQ_UINT(cast_u64_to_u64((u64)18446744073709551614ULL), 18446744073709551614ULL);
    CHECK_EQ_INT(cast_u64_to_i64((u64)18446744073709551614ULL), 9223372036854775807LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u64_to_size_t((u64)18446744073709551614ULL), 18446744073709551614ULL);
#endif
    CHECK_EQ_UINT(cast_u64_to_u8((u64)18446744073709551615ULL), 255ULL);
    CHECK_EQ_INT(cast_u64_to_i8((u64)18446744073709551615ULL), 127LL);
    CHECK_EQ_UINT(cast_u64_to_u16((u64)18446744073709551615ULL), 65535ULL);
    CHECK_EQ_INT(cast_u64_to_i16((u64)18446744073709551615ULL), 32767LL);
    CHECK_EQ_UINT(cast_u64_to_u32((u64)18446744073709551615ULL), 4294967295ULL);
    CHECK_EQ_INT(cast_u64_to_i32((u64)18446744073709551615ULL), 2147483647LL);
    CHECK_EQ_UINT(cast_u64_to_u64((u64)18446744073709551615ULL), 18446744073709551615ULL);
    CHECK_EQ_INT(cast_u64_to_i64((u64)18446744073709551615ULL), 9223372036854775807LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_u64_to_size_t((u64)18446744073709551615ULL), 18446744073709551615ULL);
#endif
}

void test_numbers_cast_from_i64(HammerCtx *t)
{
    CHECK_EQ_UINT(cast_i64_to_u8((i64)INT64_MIN), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i8((i64)INT64_MIN), (-128LL));
    CHECK_EQ_UINT(cast_i64_to_u16((i64)INT64_MIN), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i16((i64)INT64_MIN), (-32768LL));
    CHECK_EQ_UINT(cast_i64_to_u32((i64)INT64_MIN), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i32((i64)INT64_MIN), (-2147483648LL));
    CHECK_EQ_UINT(cast_i64_to_u64((i64)INT64_MIN), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i64((i64)INT64_MIN), INT64_MIN);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i64_to_size_t((i64)INT64_MIN), 0ULL);
#endif
    CHECK(cast_i64_to_f32((i64)INT64_MIN) == -0x1.0000000000000p+63f);
    CHECK(cast_i64_to_f64((i64)INT64_MIN) == -0x1.0000000000000p+63);
    CHECK_EQ_UINT(cast_i64_to_u8((i64)(-9223372036854775807LL)), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i8((i64)(-9223372036854775807LL)), (-128LL));
    CHECK_EQ_UINT(cast_i64_to_u16((i64)(-9223372036854775807LL)), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i16((i64)(-9223372036854775807LL)), (-32768LL));
    CHECK_EQ_UINT(cast_i64_to_u32((i64)(-9223372036854775807LL)), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i32((i64)(-9223372036854775807LL)), (-2147483648LL));
    CHECK_EQ_UINT(cast_i64_to_u64((i64)(-9223372036854775807LL)), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i64((i64)(-9223372036854775807LL)), (-9223372036854775807LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i64_to_size_t((i64)(-9223372036854775807LL)), 0ULL);
#endif
    CHECK_EQ_UINT(cast_i64_to_u8((i64)(-2147483649LL)), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i8((i64)(-2147483649LL)), (-128LL));
    CHECK_EQ_UINT(cast_i64_to_u16((i64)(-2147483649LL)), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i16((i64)(-2147483649LL)), (-32768LL));
    CHECK_EQ_UINT(cast_i64_to_u32((i64)(-2147483649LL)), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i32((i64)(-2147483649LL)), (-2147483648LL));
    CHECK_EQ_UINT(cast_i64_to_u64((i64)(-2147483649LL)), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i64((i64)(-2147483649LL)), (-2147483649LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i64_to_size_t((i64)(-2147483649LL)), 0ULL);
#endif
    CHECK(cast_i64_to_f64((i64)(-2147483649LL)) == -0x1.0000000200000p+31);
    CHECK_EQ_UINT(cast_i64_to_u8((i64)(-2147483648LL)), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i8((i64)(-2147483648LL)), (-128LL));
    CHECK_EQ_UINT(cast_i64_to_u16((i64)(-2147483648LL)), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i16((i64)(-2147483648LL)), (-32768LL));
    CHECK_EQ_UINT(cast_i64_to_u32((i64)(-2147483648LL)), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i32((i64)(-2147483648LL)), (-2147483648LL));
    CHECK_EQ_UINT(cast_i64_to_u64((i64)(-2147483648LL)), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i64((i64)(-2147483648LL)), (-2147483648LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i64_to_size_t((i64)(-2147483648LL)), 0ULL);
#endif
    CHECK(cast_i64_to_f32((i64)(-2147483648LL)) == -0x1.0000000000000p+31f);
    CHECK(cast_i64_to_f64((i64)(-2147483648LL)) == -0x1.0000000000000p+31);
    CHECK_EQ_UINT(cast_i64_to_u8((i64)(-32769LL)), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i8((i64)(-32769LL)), (-128LL));
    CHECK_EQ_UINT(cast_i64_to_u16((i64)(-32769LL)), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i16((i64)(-32769LL)), (-32768LL));
    CHECK_EQ_UINT(cast_i64_to_u32((i64)(-32769LL)), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i32((i64)(-32769LL)), (-32769LL));
    CHECK_EQ_UINT(cast_i64_to_u64((i64)(-32769LL)), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i64((i64)(-32769LL)), (-32769LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i64_to_size_t((i64)(-32769LL)), 0ULL);
#endif
    CHECK(cast_i64_to_f32((i64)(-32769LL)) == -0x1.0002000000000p+15f);
    CHECK(cast_i64_to_f64((i64)(-32769LL)) == -0x1.0002000000000p+15);
    CHECK_EQ_UINT(cast_i64_to_u8((i64)(-32768LL)), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i8((i64)(-32768LL)), (-128LL));
    CHECK_EQ_UINT(cast_i64_to_u16((i64)(-32768LL)), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i16((i64)(-32768LL)), (-32768LL));
    CHECK_EQ_UINT(cast_i64_to_u32((i64)(-32768LL)), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i32((i64)(-32768LL)), (-32768LL));
    CHECK_EQ_UINT(cast_i64_to_u64((i64)(-32768LL)), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i64((i64)(-32768LL)), (-32768LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i64_to_size_t((i64)(-32768LL)), 0ULL);
#endif
    CHECK(cast_i64_to_f32((i64)(-32768LL)) == -0x1.0000000000000p+15f);
    CHECK(cast_i64_to_f64((i64)(-32768LL)) == -0x1.0000000000000p+15);
    CHECK_EQ_UINT(cast_i64_to_u8((i64)(-129LL)), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i8((i64)(-129LL)), (-128LL));
    CHECK_EQ_UINT(cast_i64_to_u16((i64)(-129LL)), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i16((i64)(-129LL)), (-129LL));
    CHECK_EQ_UINT(cast_i64_to_u32((i64)(-129LL)), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i32((i64)(-129LL)), (-129LL));
    CHECK_EQ_UINT(cast_i64_to_u64((i64)(-129LL)), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i64((i64)(-129LL)), (-129LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i64_to_size_t((i64)(-129LL)), 0ULL);
#endif
    CHECK(cast_i64_to_f32((i64)(-129LL)) == -0x1.0200000000000p+7f);
    CHECK(cast_i64_to_f64((i64)(-129LL)) == -0x1.0200000000000p+7);
    CHECK_EQ_UINT(cast_i64_to_u8((i64)(-128LL)), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i8((i64)(-128LL)), (-128LL));
    CHECK_EQ_UINT(cast_i64_to_u16((i64)(-128LL)), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i16((i64)(-128LL)), (-128LL));
    CHECK_EQ_UINT(cast_i64_to_u32((i64)(-128LL)), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i32((i64)(-128LL)), (-128LL));
    CHECK_EQ_UINT(cast_i64_to_u64((i64)(-128LL)), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i64((i64)(-128LL)), (-128LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i64_to_size_t((i64)(-128LL)), 0ULL);
#endif
    CHECK(cast_i64_to_f32((i64)(-128LL)) == -0x1.0000000000000p+7f);
    CHECK(cast_i64_to_f64((i64)(-128LL)) == -0x1.0000000000000p+7);
    CHECK_EQ_UINT(cast_i64_to_u8((i64)(-1LL)), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i8((i64)(-1LL)), (-1LL));
    CHECK_EQ_UINT(cast_i64_to_u16((i64)(-1LL)), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i16((i64)(-1LL)), (-1LL));
    CHECK_EQ_UINT(cast_i64_to_u32((i64)(-1LL)), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i32((i64)(-1LL)), (-1LL));
    CHECK_EQ_UINT(cast_i64_to_u64((i64)(-1LL)), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i64((i64)(-1LL)), (-1LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i64_to_size_t((i64)(-1LL)), 0ULL);
#endif
    CHECK(cast_i64_to_f32((i64)(-1LL)) == -0x1.0000000000000p+0f);
    CHECK(cast_i64_to_f64((i64)(-1LL)) == -0x1.0000000000000p+0);
    CHECK_EQ_UINT(cast_i64_to_u8((i64)0LL), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i8((i64)0LL), 0LL);
    CHECK_EQ_UINT(cast_i64_to_u16((i64)0LL), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i16((i64)0LL), 0LL);
    CHECK_EQ_UINT(cast_i64_to_u32((i64)0LL), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i32((i64)0LL), 0LL);
    CHECK_EQ_UINT(cast_i64_to_u64((i64)0LL), 0ULL);
    CHECK_EQ_INT(cast_i64_to_i64((i64)0LL), 0LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i64_to_size_t((i64)0LL), 0ULL);
#endif
    CHECK(cast_i64_to_f32((i64)0LL) == 0.0f);
    CHECK(cast_i64_to_f64((i64)0LL) == 0.0);
    CHECK_EQ_UINT(cast_i64_to_u8((i64)1LL), 1ULL);
    CHECK_EQ_INT(cast_i64_to_i8((i64)1LL), 1LL);
    CHECK_EQ_UINT(cast_i64_to_u16((i64)1LL), 1ULL);
    CHECK_EQ_INT(cast_i64_to_i16((i64)1LL), 1LL);
    CHECK_EQ_UINT(cast_i64_to_u32((i64)1LL), 1ULL);
    CHECK_EQ_INT(cast_i64_to_i32((i64)1LL), 1LL);
    CHECK_EQ_UINT(cast_i64_to_u64((i64)1LL), 1ULL);
    CHECK_EQ_INT(cast_i64_to_i64((i64)1LL), 1LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i64_to_size_t((i64)1LL), 1ULL);
#endif
    CHECK(cast_i64_to_f32((i64)1LL) == 0x1.0000000000000p+0f);
    CHECK(cast_i64_to_f64((i64)1LL) == 0x1.0000000000000p+0);
    CHECK_EQ_UINT(cast_i64_to_u8((i64)127LL), 127ULL);
    CHECK_EQ_INT(cast_i64_to_i8((i64)127LL), 127LL);
    CHECK_EQ_UINT(cast_i64_to_u16((i64)127LL), 127ULL);
    CHECK_EQ_INT(cast_i64_to_i16((i64)127LL), 127LL);
    CHECK_EQ_UINT(cast_i64_to_u32((i64)127LL), 127ULL);
    CHECK_EQ_INT(cast_i64_to_i32((i64)127LL), 127LL);
    CHECK_EQ_UINT(cast_i64_to_u64((i64)127LL), 127ULL);
    CHECK_EQ_INT(cast_i64_to_i64((i64)127LL), 127LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i64_to_size_t((i64)127LL), 127ULL);
#endif
    CHECK(cast_i64_to_f32((i64)127LL) == 0x1.fc00000000000p+6f);
    CHECK(cast_i64_to_f64((i64)127LL) == 0x1.fc00000000000p+6);
    CHECK_EQ_UINT(cast_i64_to_u8((i64)128LL), 128ULL);
    CHECK_EQ_INT(cast_i64_to_i8((i64)128LL), 127LL);
    CHECK_EQ_UINT(cast_i64_to_u16((i64)128LL), 128ULL);
    CHECK_EQ_INT(cast_i64_to_i16((i64)128LL), 128LL);
    CHECK_EQ_UINT(cast_i64_to_u32((i64)128LL), 128ULL);
    CHECK_EQ_INT(cast_i64_to_i32((i64)128LL), 128LL);
    CHECK_EQ_UINT(cast_i64_to_u64((i64)128LL), 128ULL);
    CHECK_EQ_INT(cast_i64_to_i64((i64)128LL), 128LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i64_to_size_t((i64)128LL), 128ULL);
#endif
    CHECK(cast_i64_to_f32((i64)128LL) == 0x1.0000000000000p+7f);
    CHECK(cast_i64_to_f64((i64)128LL) == 0x1.0000000000000p+7);
    CHECK_EQ_UINT(cast_i64_to_u8((i64)255LL), 255ULL);
    CHECK_EQ_INT(cast_i64_to_i8((i64)255LL), 127LL);
    CHECK_EQ_UINT(cast_i64_to_u16((i64)255LL), 255ULL);
    CHECK_EQ_INT(cast_i64_to_i16((i64)255LL), 255LL);
    CHECK_EQ_UINT(cast_i64_to_u32((i64)255LL), 255ULL);
    CHECK_EQ_INT(cast_i64_to_i32((i64)255LL), 255LL);
    CHECK_EQ_UINT(cast_i64_to_u64((i64)255LL), 255ULL);
    CHECK_EQ_INT(cast_i64_to_i64((i64)255LL), 255LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i64_to_size_t((i64)255LL), 255ULL);
#endif
    CHECK(cast_i64_to_f32((i64)255LL) == 0x1.fe00000000000p+7f);
    CHECK(cast_i64_to_f64((i64)255LL) == 0x1.fe00000000000p+7);
    CHECK_EQ_UINT(cast_i64_to_u8((i64)256LL), 255ULL);
    CHECK_EQ_INT(cast_i64_to_i8((i64)256LL), 127LL);
    CHECK_EQ_UINT(cast_i64_to_u16((i64)256LL), 256ULL);
    CHECK_EQ_INT(cast_i64_to_i16((i64)256LL), 256LL);
    CHECK_EQ_UINT(cast_i64_to_u32((i64)256LL), 256ULL);
    CHECK_EQ_INT(cast_i64_to_i32((i64)256LL), 256LL);
    CHECK_EQ_UINT(cast_i64_to_u64((i64)256LL), 256ULL);
    CHECK_EQ_INT(cast_i64_to_i64((i64)256LL), 256LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i64_to_size_t((i64)256LL), 256ULL);
#endif
    CHECK(cast_i64_to_f32((i64)256LL) == 0x1.0000000000000p+8f);
    CHECK(cast_i64_to_f64((i64)256LL) == 0x1.0000000000000p+8);
    CHECK_EQ_UINT(cast_i64_to_u8((i64)32767LL), 255ULL);
    CHECK_EQ_INT(cast_i64_to_i8((i64)32767LL), 127LL);
    CHECK_EQ_UINT(cast_i64_to_u16((i64)32767LL), 32767ULL);
    CHECK_EQ_INT(cast_i64_to_i16((i64)32767LL), 32767LL);
    CHECK_EQ_UINT(cast_i64_to_u32((i64)32767LL), 32767ULL);
    CHECK_EQ_INT(cast_i64_to_i32((i64)32767LL), 32767LL);
    CHECK_EQ_UINT(cast_i64_to_u64((i64)32767LL), 32767ULL);
    CHECK_EQ_INT(cast_i64_to_i64((i64)32767LL), 32767LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i64_to_size_t((i64)32767LL), 32767ULL);
#endif
    CHECK(cast_i64_to_f32((i64)32767LL) == 0x1.fffc000000000p+14f);
    CHECK(cast_i64_to_f64((i64)32767LL) == 0x1.fffc000000000p+14);
    CHECK_EQ_UINT(cast_i64_to_u8((i64)32768LL), 255ULL);
    CHECK_EQ_INT(cast_i64_to_i8((i64)32768LL), 127LL);
    CHECK_EQ_UINT(cast_i64_to_u16((i64)32768LL), 32768ULL);
    CHECK_EQ_INT(cast_i64_to_i16((i64)32768LL), 32767LL);
    CHECK_EQ_UINT(cast_i64_to_u32((i64)32768LL), 32768ULL);
    CHECK_EQ_INT(cast_i64_to_i32((i64)32768LL), 32768LL);
    CHECK_EQ_UINT(cast_i64_to_u64((i64)32768LL), 32768ULL);
    CHECK_EQ_INT(cast_i64_to_i64((i64)32768LL), 32768LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i64_to_size_t((i64)32768LL), 32768ULL);
#endif
    CHECK(cast_i64_to_f32((i64)32768LL) == 0x1.0000000000000p+15f);
    CHECK(cast_i64_to_f64((i64)32768LL) == 0x1.0000000000000p+15);
    CHECK_EQ_UINT(cast_i64_to_u8((i64)65535LL), 255ULL);
    CHECK_EQ_INT(cast_i64_to_i8((i64)65535LL), 127LL);
    CHECK_EQ_UINT(cast_i64_to_u16((i64)65535LL), 65535ULL);
    CHECK_EQ_INT(cast_i64_to_i16((i64)65535LL), 32767LL);
    CHECK_EQ_UINT(cast_i64_to_u32((i64)65535LL), 65535ULL);
    CHECK_EQ_INT(cast_i64_to_i32((i64)65535LL), 65535LL);
    CHECK_EQ_UINT(cast_i64_to_u64((i64)65535LL), 65535ULL);
    CHECK_EQ_INT(cast_i64_to_i64((i64)65535LL), 65535LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i64_to_size_t((i64)65535LL), 65535ULL);
#endif
    CHECK(cast_i64_to_f32((i64)65535LL) == 0x1.fffe000000000p+15f);
    CHECK(cast_i64_to_f64((i64)65535LL) == 0x1.fffe000000000p+15);
    CHECK_EQ_UINT(cast_i64_to_u8((i64)65536LL), 255ULL);
    CHECK_EQ_INT(cast_i64_to_i8((i64)65536LL), 127LL);
    CHECK_EQ_UINT(cast_i64_to_u16((i64)65536LL), 65535ULL);
    CHECK_EQ_INT(cast_i64_to_i16((i64)65536LL), 32767LL);
    CHECK_EQ_UINT(cast_i64_to_u32((i64)65536LL), 65536ULL);
    CHECK_EQ_INT(cast_i64_to_i32((i64)65536LL), 65536LL);
    CHECK_EQ_UINT(cast_i64_to_u64((i64)65536LL), 65536ULL);
    CHECK_EQ_INT(cast_i64_to_i64((i64)65536LL), 65536LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i64_to_size_t((i64)65536LL), 65536ULL);
#endif
    CHECK(cast_i64_to_f32((i64)65536LL) == 0x1.0000000000000p+16f);
    CHECK(cast_i64_to_f64((i64)65536LL) == 0x1.0000000000000p+16);
    CHECK_EQ_UINT(cast_i64_to_u8((i64)2147483647LL), 255ULL);
    CHECK_EQ_INT(cast_i64_to_i8((i64)2147483647LL), 127LL);
    CHECK_EQ_UINT(cast_i64_to_u16((i64)2147483647LL), 65535ULL);
    CHECK_EQ_INT(cast_i64_to_i16((i64)2147483647LL), 32767LL);
    CHECK_EQ_UINT(cast_i64_to_u32((i64)2147483647LL), 2147483647ULL);
    CHECK_EQ_INT(cast_i64_to_i32((i64)2147483647LL), 2147483647LL);
    CHECK_EQ_UINT(cast_i64_to_u64((i64)2147483647LL), 2147483647ULL);
    CHECK_EQ_INT(cast_i64_to_i64((i64)2147483647LL), 2147483647LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i64_to_size_t((i64)2147483647LL), 2147483647ULL);
#endif
    CHECK(cast_i64_to_f64((i64)2147483647LL) == 0x1.fffffffc00000p+30);
    CHECK_EQ_UINT(cast_i64_to_u8((i64)2147483648LL), 255ULL);
    CHECK_EQ_INT(cast_i64_to_i8((i64)2147483648LL), 127LL);
    CHECK_EQ_UINT(cast_i64_to_u16((i64)2147483648LL), 65535ULL);
    CHECK_EQ_INT(cast_i64_to_i16((i64)2147483648LL), 32767LL);
    CHECK_EQ_UINT(cast_i64_to_u32((i64)2147483648LL), 2147483648ULL);
    CHECK_EQ_INT(cast_i64_to_i32((i64)2147483648LL), 2147483647LL);
    CHECK_EQ_UINT(cast_i64_to_u64((i64)2147483648LL), 2147483648ULL);
    CHECK_EQ_INT(cast_i64_to_i64((i64)2147483648LL), 2147483648LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i64_to_size_t((i64)2147483648LL), 2147483648ULL);
#endif
    CHECK(cast_i64_to_f32((i64)2147483648LL) == 0x1.0000000000000p+31f);
    CHECK(cast_i64_to_f64((i64)2147483648LL) == 0x1.0000000000000p+31);
    CHECK_EQ_UINT(cast_i64_to_u8((i64)4294967295LL), 255ULL);
    CHECK_EQ_INT(cast_i64_to_i8((i64)4294967295LL), 127LL);
    CHECK_EQ_UINT(cast_i64_to_u16((i64)4294967295LL), 65535ULL);
    CHECK_EQ_INT(cast_i64_to_i16((i64)4294967295LL), 32767LL);
    CHECK_EQ_UINT(cast_i64_to_u32((i64)4294967295LL), 4294967295ULL);
    CHECK_EQ_INT(cast_i64_to_i32((i64)4294967295LL), 2147483647LL);
    CHECK_EQ_UINT(cast_i64_to_u64((i64)4294967295LL), 4294967295ULL);
    CHECK_EQ_INT(cast_i64_to_i64((i64)4294967295LL), 4294967295LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i64_to_size_t((i64)4294967295LL), 4294967295ULL);
#endif
    CHECK(cast_i64_to_f64((i64)4294967295LL) == 0x1.fffffffe00000p+31);
    CHECK_EQ_UINT(cast_i64_to_u8((i64)4294967296LL), 255ULL);
    CHECK_EQ_INT(cast_i64_to_i8((i64)4294967296LL), 127LL);
    CHECK_EQ_UINT(cast_i64_to_u16((i64)4294967296LL), 65535ULL);
    CHECK_EQ_INT(cast_i64_to_i16((i64)4294967296LL), 32767LL);
    CHECK_EQ_UINT(cast_i64_to_u32((i64)4294967296LL), 4294967295ULL);
    CHECK_EQ_INT(cast_i64_to_i32((i64)4294967296LL), 2147483647LL);
    CHECK_EQ_UINT(cast_i64_to_u64((i64)4294967296LL), 4294967296ULL);
    CHECK_EQ_INT(cast_i64_to_i64((i64)4294967296LL), 4294967296LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i64_to_size_t((i64)4294967296LL), 4294967296ULL);
#endif
    CHECK(cast_i64_to_f32((i64)4294967296LL) == 0x1.0000000000000p+32f);
    CHECK(cast_i64_to_f64((i64)4294967296LL) == 0x1.0000000000000p+32);
    CHECK_EQ_UINT(cast_i64_to_u8((i64)9223372036854775806LL), 255ULL);
    CHECK_EQ_INT(cast_i64_to_i8((i64)9223372036854775806LL), 127LL);
    CHECK_EQ_UINT(cast_i64_to_u16((i64)9223372036854775806LL), 65535ULL);
    CHECK_EQ_INT(cast_i64_to_i16((i64)9223372036854775806LL), 32767LL);
    CHECK_EQ_UINT(cast_i64_to_u32((i64)9223372036854775806LL), 4294967295ULL);
    CHECK_EQ_INT(cast_i64_to_i32((i64)9223372036854775806LL), 2147483647LL);
    CHECK_EQ_UINT(cast_i64_to_u64((i64)9223372036854775806LL), 9223372036854775806ULL);
    CHECK_EQ_INT(cast_i64_to_i64((i64)9223372036854775806LL), 9223372036854775806LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i64_to_size_t((i64)9223372036854775806LL), 9223372036854775806ULL);
#endif
    CHECK_EQ_UINT(cast_i64_to_u8((i64)9223372036854775807LL), 255ULL);
    CHECK_EQ_INT(cast_i64_to_i8((i64)9223372036854775807LL), 127LL);
    CHECK_EQ_UINT(cast_i64_to_u16((i64)9223372036854775807LL), 65535ULL);
    CHECK_EQ_INT(cast_i64_to_i16((i64)9223372036854775807LL), 32767LL);
    CHECK_EQ_UINT(cast_i64_to_u32((i64)9223372036854775807LL), 4294967295ULL);
    CHECK_EQ_INT(cast_i64_to_i32((i64)9223372036854775807LL), 2147483647LL);
    CHECK_EQ_UINT(cast_i64_to_u64((i64)9223372036854775807LL), 9223372036854775807ULL);
    CHECK_EQ_INT(cast_i64_to_i64((i64)9223372036854775807LL), 9223372036854775807LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_i64_to_size_t((i64)9223372036854775807LL), 9223372036854775807ULL);
#endif
}

void test_numbers_cast_from_size_t(HammerCtx *t)
{
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_size_t_to_u8((size_t)0ULL), 0ULL);
    CHECK_EQ_INT(cast_size_t_to_i8((size_t)0ULL), 0LL);
    CHECK_EQ_UINT(cast_size_t_to_u16((size_t)0ULL), 0ULL);
    CHECK_EQ_INT(cast_size_t_to_i16((size_t)0ULL), 0LL);
    CHECK_EQ_UINT(cast_size_t_to_u32((size_t)0ULL), 0ULL);
    CHECK_EQ_INT(cast_size_t_to_i32((size_t)0ULL), 0LL);
    CHECK_EQ_UINT(cast_size_t_to_u64((size_t)0ULL), 0ULL);
    CHECK_EQ_INT(cast_size_t_to_i64((size_t)0ULL), 0LL);
    CHECK_EQ_UINT(cast_size_t_to_size_t((size_t)0ULL), 0ULL);
    CHECK(cast_size_t_to_f32((size_t)0ULL) == 0.0f);
    CHECK(cast_size_t_to_f64((size_t)0ULL) == 0.0);
    CHECK_EQ_UINT(cast_size_t_to_u8((size_t)1ULL), 1ULL);
    CHECK_EQ_INT(cast_size_t_to_i8((size_t)1ULL), 1LL);
    CHECK_EQ_UINT(cast_size_t_to_u16((size_t)1ULL), 1ULL);
    CHECK_EQ_INT(cast_size_t_to_i16((size_t)1ULL), 1LL);
    CHECK_EQ_UINT(cast_size_t_to_u32((size_t)1ULL), 1ULL);
    CHECK_EQ_INT(cast_size_t_to_i32((size_t)1ULL), 1LL);
    CHECK_EQ_UINT(cast_size_t_to_u64((size_t)1ULL), 1ULL);
    CHECK_EQ_INT(cast_size_t_to_i64((size_t)1ULL), 1LL);
    CHECK_EQ_UINT(cast_size_t_to_size_t((size_t)1ULL), 1ULL);
    CHECK(cast_size_t_to_f32((size_t)1ULL) == 0x1.0000000000000p+0f);
    CHECK(cast_size_t_to_f64((size_t)1ULL) == 0x1.0000000000000p+0);
    CHECK_EQ_UINT(cast_size_t_to_u8((size_t)127ULL), 127ULL);
    CHECK_EQ_INT(cast_size_t_to_i8((size_t)127ULL), 127LL);
    CHECK_EQ_UINT(cast_size_t_to_u16((size_t)127ULL), 127ULL);
    CHECK_EQ_INT(cast_size_t_to_i16((size_t)127ULL), 127LL);
    CHECK_EQ_UINT(cast_size_t_to_u32((size_t)127ULL), 127ULL);
    CHECK_EQ_INT(cast_size_t_to_i32((size_t)127ULL), 127LL);
    CHECK_EQ_UINT(cast_size_t_to_u64((size_t)127ULL), 127ULL);
    CHECK_EQ_INT(cast_size_t_to_i64((size_t)127ULL), 127LL);
    CHECK_EQ_UINT(cast_size_t_to_size_t((size_t)127ULL), 127ULL);
    CHECK(cast_size_t_to_f32((size_t)127ULL) == 0x1.fc00000000000p+6f);
    CHECK(cast_size_t_to_f64((size_t)127ULL) == 0x1.fc00000000000p+6);
    CHECK_EQ_UINT(cast_size_t_to_u8((size_t)128ULL), 128ULL);
    CHECK_EQ_INT(cast_size_t_to_i8((size_t)128ULL), 127LL);
    CHECK_EQ_UINT(cast_size_t_to_u16((size_t)128ULL), 128ULL);
    CHECK_EQ_INT(cast_size_t_to_i16((size_t)128ULL), 128LL);
    CHECK_EQ_UINT(cast_size_t_to_u32((size_t)128ULL), 128ULL);
    CHECK_EQ_INT(cast_size_t_to_i32((size_t)128ULL), 128LL);
    CHECK_EQ_UINT(cast_size_t_to_u64((size_t)128ULL), 128ULL);
    CHECK_EQ_INT(cast_size_t_to_i64((size_t)128ULL), 128LL);
    CHECK_EQ_UINT(cast_size_t_to_size_t((size_t)128ULL), 128ULL);
    CHECK(cast_size_t_to_f32((size_t)128ULL) == 0x1.0000000000000p+7f);
    CHECK(cast_size_t_to_f64((size_t)128ULL) == 0x1.0000000000000p+7);
    CHECK_EQ_UINT(cast_size_t_to_u8((size_t)255ULL), 255ULL);
    CHECK_EQ_INT(cast_size_t_to_i8((size_t)255ULL), 127LL);
    CHECK_EQ_UINT(cast_size_t_to_u16((size_t)255ULL), 255ULL);
    CHECK_EQ_INT(cast_size_t_to_i16((size_t)255ULL), 255LL);
    CHECK_EQ_UINT(cast_size_t_to_u32((size_t)255ULL), 255ULL);
    CHECK_EQ_INT(cast_size_t_to_i32((size_t)255ULL), 255LL);
    CHECK_EQ_UINT(cast_size_t_to_u64((size_t)255ULL), 255ULL);
    CHECK_EQ_INT(cast_size_t_to_i64((size_t)255ULL), 255LL);
    CHECK_EQ_UINT(cast_size_t_to_size_t((size_t)255ULL), 255ULL);
    CHECK(cast_size_t_to_f32((size_t)255ULL) == 0x1.fe00000000000p+7f);
    CHECK(cast_size_t_to_f64((size_t)255ULL) == 0x1.fe00000000000p+7);
    CHECK_EQ_UINT(cast_size_t_to_u8((size_t)256ULL), 255ULL);
    CHECK_EQ_INT(cast_size_t_to_i8((size_t)256ULL), 127LL);
    CHECK_EQ_UINT(cast_size_t_to_u16((size_t)256ULL), 256ULL);
    CHECK_EQ_INT(cast_size_t_to_i16((size_t)256ULL), 256LL);
    CHECK_EQ_UINT(cast_size_t_to_u32((size_t)256ULL), 256ULL);
    CHECK_EQ_INT(cast_size_t_to_i32((size_t)256ULL), 256LL);
    CHECK_EQ_UINT(cast_size_t_to_u64((size_t)256ULL), 256ULL);
    CHECK_EQ_INT(cast_size_t_to_i64((size_t)256ULL), 256LL);
    CHECK_EQ_UINT(cast_size_t_to_size_t((size_t)256ULL), 256ULL);
    CHECK(cast_size_t_to_f32((size_t)256ULL) == 0x1.0000000000000p+8f);
    CHECK(cast_size_t_to_f64((size_t)256ULL) == 0x1.0000000000000p+8);
    CHECK_EQ_UINT(cast_size_t_to_u8((size_t)32767ULL), 255ULL);
    CHECK_EQ_INT(cast_size_t_to_i8((size_t)32767ULL), 127LL);
    CHECK_EQ_UINT(cast_size_t_to_u16((size_t)32767ULL), 32767ULL);
    CHECK_EQ_INT(cast_size_t_to_i16((size_t)32767ULL), 32767LL);
    CHECK_EQ_UINT(cast_size_t_to_u32((size_t)32767ULL), 32767ULL);
    CHECK_EQ_INT(cast_size_t_to_i32((size_t)32767ULL), 32767LL);
    CHECK_EQ_UINT(cast_size_t_to_u64((size_t)32767ULL), 32767ULL);
    CHECK_EQ_INT(cast_size_t_to_i64((size_t)32767ULL), 32767LL);
    CHECK_EQ_UINT(cast_size_t_to_size_t((size_t)32767ULL), 32767ULL);
    CHECK(cast_size_t_to_f32((size_t)32767ULL) == 0x1.fffc000000000p+14f);
    CHECK(cast_size_t_to_f64((size_t)32767ULL) == 0x1.fffc000000000p+14);
    CHECK_EQ_UINT(cast_size_t_to_u8((size_t)32768ULL), 255ULL);
    CHECK_EQ_INT(cast_size_t_to_i8((size_t)32768ULL), 127LL);
    CHECK_EQ_UINT(cast_size_t_to_u16((size_t)32768ULL), 32768ULL);
    CHECK_EQ_INT(cast_size_t_to_i16((size_t)32768ULL), 32767LL);
    CHECK_EQ_UINT(cast_size_t_to_u32((size_t)32768ULL), 32768ULL);
    CHECK_EQ_INT(cast_size_t_to_i32((size_t)32768ULL), 32768LL);
    CHECK_EQ_UINT(cast_size_t_to_u64((size_t)32768ULL), 32768ULL);
    CHECK_EQ_INT(cast_size_t_to_i64((size_t)32768ULL), 32768LL);
    CHECK_EQ_UINT(cast_size_t_to_size_t((size_t)32768ULL), 32768ULL);
    CHECK(cast_size_t_to_f32((size_t)32768ULL) == 0x1.0000000000000p+15f);
    CHECK(cast_size_t_to_f64((size_t)32768ULL) == 0x1.0000000000000p+15);
    CHECK_EQ_UINT(cast_size_t_to_u8((size_t)65535ULL), 255ULL);
    CHECK_EQ_INT(cast_size_t_to_i8((size_t)65535ULL), 127LL);
    CHECK_EQ_UINT(cast_size_t_to_u16((size_t)65535ULL), 65535ULL);
    CHECK_EQ_INT(cast_size_t_to_i16((size_t)65535ULL), 32767LL);
    CHECK_EQ_UINT(cast_size_t_to_u32((size_t)65535ULL), 65535ULL);
    CHECK_EQ_INT(cast_size_t_to_i32((size_t)65535ULL), 65535LL);
    CHECK_EQ_UINT(cast_size_t_to_u64((size_t)65535ULL), 65535ULL);
    CHECK_EQ_INT(cast_size_t_to_i64((size_t)65535ULL), 65535LL);
    CHECK_EQ_UINT(cast_size_t_to_size_t((size_t)65535ULL), 65535ULL);
    CHECK(cast_size_t_to_f32((size_t)65535ULL) == 0x1.fffe000000000p+15f);
    CHECK(cast_size_t_to_f64((size_t)65535ULL) == 0x1.fffe000000000p+15);
    CHECK_EQ_UINT(cast_size_t_to_u8((size_t)65536ULL), 255ULL);
    CHECK_EQ_INT(cast_size_t_to_i8((size_t)65536ULL), 127LL);
    CHECK_EQ_UINT(cast_size_t_to_u16((size_t)65536ULL), 65535ULL);
    CHECK_EQ_INT(cast_size_t_to_i16((size_t)65536ULL), 32767LL);
    CHECK_EQ_UINT(cast_size_t_to_u32((size_t)65536ULL), 65536ULL);
    CHECK_EQ_INT(cast_size_t_to_i32((size_t)65536ULL), 65536LL);
    CHECK_EQ_UINT(cast_size_t_to_u64((size_t)65536ULL), 65536ULL);
    CHECK_EQ_INT(cast_size_t_to_i64((size_t)65536ULL), 65536LL);
    CHECK_EQ_UINT(cast_size_t_to_size_t((size_t)65536ULL), 65536ULL);
    CHECK(cast_size_t_to_f32((size_t)65536ULL) == 0x1.0000000000000p+16f);
    CHECK(cast_size_t_to_f64((size_t)65536ULL) == 0x1.0000000000000p+16);
    CHECK_EQ_UINT(cast_size_t_to_u8((size_t)2147483647ULL), 255ULL);
    CHECK_EQ_INT(cast_size_t_to_i8((size_t)2147483647ULL), 127LL);
    CHECK_EQ_UINT(cast_size_t_to_u16((size_t)2147483647ULL), 65535ULL);
    CHECK_EQ_INT(cast_size_t_to_i16((size_t)2147483647ULL), 32767LL);
    CHECK_EQ_UINT(cast_size_t_to_u32((size_t)2147483647ULL), 2147483647ULL);
    CHECK_EQ_INT(cast_size_t_to_i32((size_t)2147483647ULL), 2147483647LL);
    CHECK_EQ_UINT(cast_size_t_to_u64((size_t)2147483647ULL), 2147483647ULL);
    CHECK_EQ_INT(cast_size_t_to_i64((size_t)2147483647ULL), 2147483647LL);
    CHECK_EQ_UINT(cast_size_t_to_size_t((size_t)2147483647ULL), 2147483647ULL);
    CHECK(cast_size_t_to_f64((size_t)2147483647ULL) == 0x1.fffffffc00000p+30);
    CHECK_EQ_UINT(cast_size_t_to_u8((size_t)2147483648ULL), 255ULL);
    CHECK_EQ_INT(cast_size_t_to_i8((size_t)2147483648ULL), 127LL);
    CHECK_EQ_UINT(cast_size_t_to_u16((size_t)2147483648ULL), 65535ULL);
    CHECK_EQ_INT(cast_size_t_to_i16((size_t)2147483648ULL), 32767LL);
    CHECK_EQ_UINT(cast_size_t_to_u32((size_t)2147483648ULL), 2147483648ULL);
    CHECK_EQ_INT(cast_size_t_to_i32((size_t)2147483648ULL), 2147483647LL);
    CHECK_EQ_UINT(cast_size_t_to_u64((size_t)2147483648ULL), 2147483648ULL);
    CHECK_EQ_INT(cast_size_t_to_i64((size_t)2147483648ULL), 2147483648LL);
    CHECK_EQ_UINT(cast_size_t_to_size_t((size_t)2147483648ULL), 2147483648ULL);
    CHECK(cast_size_t_to_f32((size_t)2147483648ULL) == 0x1.0000000000000p+31f);
    CHECK(cast_size_t_to_f64((size_t)2147483648ULL) == 0x1.0000000000000p+31);
    CHECK_EQ_UINT(cast_size_t_to_u8((size_t)4294967295ULL), 255ULL);
    CHECK_EQ_INT(cast_size_t_to_i8((size_t)4294967295ULL), 127LL);
    CHECK_EQ_UINT(cast_size_t_to_u16((size_t)4294967295ULL), 65535ULL);
    CHECK_EQ_INT(cast_size_t_to_i16((size_t)4294967295ULL), 32767LL);
    CHECK_EQ_UINT(cast_size_t_to_u32((size_t)4294967295ULL), 4294967295ULL);
    CHECK_EQ_INT(cast_size_t_to_i32((size_t)4294967295ULL), 2147483647LL);
    CHECK_EQ_UINT(cast_size_t_to_u64((size_t)4294967295ULL), 4294967295ULL);
    CHECK_EQ_INT(cast_size_t_to_i64((size_t)4294967295ULL), 4294967295LL);
    CHECK_EQ_UINT(cast_size_t_to_size_t((size_t)4294967295ULL), 4294967295ULL);
    CHECK(cast_size_t_to_f64((size_t)4294967295ULL) == 0x1.fffffffe00000p+31);
    CHECK_EQ_UINT(cast_size_t_to_u8((size_t)4294967296ULL), 255ULL);
    CHECK_EQ_INT(cast_size_t_to_i8((size_t)4294967296ULL), 127LL);
    CHECK_EQ_UINT(cast_size_t_to_u16((size_t)4294967296ULL), 65535ULL);
    CHECK_EQ_INT(cast_size_t_to_i16((size_t)4294967296ULL), 32767LL);
    CHECK_EQ_UINT(cast_size_t_to_u32((size_t)4294967296ULL), 4294967295ULL);
    CHECK_EQ_INT(cast_size_t_to_i32((size_t)4294967296ULL), 2147483647LL);
    CHECK_EQ_UINT(cast_size_t_to_u64((size_t)4294967296ULL), 4294967296ULL);
    CHECK_EQ_INT(cast_size_t_to_i64((size_t)4294967296ULL), 4294967296LL);
    CHECK_EQ_UINT(cast_size_t_to_size_t((size_t)4294967296ULL), 4294967296ULL);
    CHECK(cast_size_t_to_f32((size_t)4294967296ULL) == 0x1.0000000000000p+32f);
    CHECK(cast_size_t_to_f64((size_t)4294967296ULL) == 0x1.0000000000000p+32);
    CHECK_EQ_UINT(cast_size_t_to_u8((size_t)9223372036854775807ULL), 255ULL);
    CHECK_EQ_INT(cast_size_t_to_i8((size_t)9223372036854775807ULL), 127LL);
    CHECK_EQ_UINT(cast_size_t_to_u16((size_t)9223372036854775807ULL), 65535ULL);
    CHECK_EQ_INT(cast_size_t_to_i16((size_t)9223372036854775807ULL), 32767LL);
    CHECK_EQ_UINT(cast_size_t_to_u32((size_t)9223372036854775807ULL), 4294967295ULL);
    CHECK_EQ_INT(cast_size_t_to_i32((size_t)9223372036854775807ULL), 2147483647LL);
    CHECK_EQ_UINT(cast_size_t_to_u64((size_t)9223372036854775807ULL), 9223372036854775807ULL);
    CHECK_EQ_INT(cast_size_t_to_i64((size_t)9223372036854775807ULL), 9223372036854775807LL);
    CHECK_EQ_UINT(cast_size_t_to_size_t((size_t)9223372036854775807ULL), 9223372036854775807ULL);
    CHECK_EQ_UINT(cast_size_t_to_u8((size_t)9223372036854775808ULL), 255ULL);
    CHECK_EQ_INT(cast_size_t_to_i8((size_t)9223372036854775808ULL), 127LL);
    CHECK_EQ_UINT(cast_size_t_to_u16((size_t)9223372036854775808ULL), 65535ULL);
    CHECK_EQ_INT(cast_size_t_to_i16((size_t)9223372036854775808ULL), 32767LL);
    CHECK_EQ_UINT(cast_size_t_to_u32((size_t)9223372036854775808ULL), 4294967295ULL);
    CHECK_EQ_INT(cast_size_t_to_i32((size_t)9223372036854775808ULL), 2147483647LL);
    CHECK_EQ_UINT(cast_size_t_to_u64((size_t)9223372036854775808ULL), 9223372036854775808ULL);
    CHECK_EQ_INT(cast_size_t_to_i64((size_t)9223372036854775808ULL), 9223372036854775807LL);
    CHECK_EQ_UINT(cast_size_t_to_size_t((size_t)9223372036854775808ULL), 9223372036854775808ULL);
    CHECK(cast_size_t_to_f32((size_t)9223372036854775808ULL) == 0x1.0000000000000p+63f);
    CHECK(cast_size_t_to_f64((size_t)9223372036854775808ULL) == 0x1.0000000000000p+63);
    CHECK_EQ_UINT(cast_size_t_to_u8((size_t)18446744073709551614ULL), 255ULL);
    CHECK_EQ_INT(cast_size_t_to_i8((size_t)18446744073709551614ULL), 127LL);
    CHECK_EQ_UINT(cast_size_t_to_u16((size_t)18446744073709551614ULL), 65535ULL);
    CHECK_EQ_INT(cast_size_t_to_i16((size_t)18446744073709551614ULL), 32767LL);
    CHECK_EQ_UINT(cast_size_t_to_u32((size_t)18446744073709551614ULL), 4294967295ULL);
    CHECK_EQ_INT(cast_size_t_to_i32((size_t)18446744073709551614ULL), 2147483647LL);
    CHECK_EQ_UINT(cast_size_t_to_u64((size_t)18446744073709551614ULL), 18446744073709551614ULL);
    CHECK_EQ_INT(cast_size_t_to_i64((size_t)18446744073709551614ULL), 9223372036854775807LL);
    CHECK_EQ_UINT(cast_size_t_to_size_t((size_t)18446744073709551614ULL), 18446744073709551614ULL);
    CHECK_EQ_UINT(cast_size_t_to_u8((size_t)18446744073709551615ULL), 255ULL);
    CHECK_EQ_INT(cast_size_t_to_i8((size_t)18446744073709551615ULL), 127LL);
    CHECK_EQ_UINT(cast_size_t_to_u16((size_t)18446744073709551615ULL), 65535ULL);
    CHECK_EQ_INT(cast_size_t_to_i16((size_t)18446744073709551615ULL), 32767LL);
    CHECK_EQ_UINT(cast_size_t_to_u32((size_t)18446744073709551615ULL), 4294967295ULL);
    CHECK_EQ_INT(cast_size_t_to_i32((size_t)18446744073709551615ULL), 2147483647LL);
    CHECK_EQ_UINT(cast_size_t_to_u64((size_t)18446744073709551615ULL), 18446744073709551615ULL);
    CHECK_EQ_INT(cast_size_t_to_i64((size_t)18446744073709551615ULL), 9223372036854775807LL);
    CHECK_EQ_UINT(cast_size_t_to_size_t((size_t)18446744073709551615ULL), 18446744073709551615ULL);
#else
    CHECK(1);
#endif
}

void test_numbers_cast_from_f32(HammerCtx *t)
{
    CHECK_EQ_UINT(cast_f32_to_u8(NAN), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i8(NAN), 0LL);
    CHECK_EQ_UINT(cast_f32_to_u16(NAN), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i16(NAN), 0LL);
    CHECK_EQ_UINT(cast_f32_to_u32(NAN), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i32(NAN), 0LL);
    CHECK_EQ_UINT(cast_f32_to_u64(NAN), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i64(NAN), 0LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(NAN), 0ULL);
#endif
    CHECK(isnan(cast_f32_to_f32(NAN)));
    CHECK(isnan(cast_f32_to_f64(NAN)));
    CHECK_EQ_UINT(cast_f32_to_u8(INFINITY), 255ULL);
    CHECK_EQ_INT(cast_f32_to_i8(INFINITY), 127LL);
    CHECK_EQ_UINT(cast_f32_to_u16(INFINITY), 65535ULL);
    CHECK_EQ_INT(cast_f32_to_i16(INFINITY), 32767LL);
    CHECK_EQ_UINT(cast_f32_to_u32(INFINITY), 4294967295ULL);
    CHECK_EQ_INT(cast_f32_to_i32(INFINITY), 2147483647LL);
    CHECK_EQ_UINT(cast_f32_to_u64(INFINITY), 18446744073709551615ULL);
    CHECK_EQ_INT(cast_f32_to_i64(INFINITY), 9223372036854775807LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(INFINITY), 18446744073709551615ULL);
#endif
    CHECK(cast_f32_to_f32(INFINITY) == INFINITY);
    CHECK(cast_f32_to_f64(INFINITY) == (f64)INFINITY);
    CHECK_EQ_UINT(cast_f32_to_u8((-INFINITY)), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i8((-INFINITY)), (-128LL));
    CHECK_EQ_UINT(cast_f32_to_u16((-INFINITY)), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i16((-INFINITY)), (-32768LL));
    CHECK_EQ_UINT(cast_f32_to_u32((-INFINITY)), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i32((-INFINITY)), (-2147483648LL));
    CHECK_EQ_UINT(cast_f32_to_u64((-INFINITY)), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i64((-INFINITY)), INT64_MIN);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t((-INFINITY)), 0ULL);
#endif
    CHECK(cast_f32_to_f32((-INFINITY)) == (-INFINITY));
    CHECK(cast_f32_to_f64((-INFINITY)) == (-(f64)INFINITY));
    CHECK_EQ_UINT(cast_f32_to_u8(0.0f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i8(0.0f), 0LL);
    CHECK_EQ_UINT(cast_f32_to_u16(0.0f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i16(0.0f), 0LL);
    CHECK_EQ_UINT(cast_f32_to_u32(0.0f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i32(0.0f), 0LL);
    CHECK_EQ_UINT(cast_f32_to_u64(0.0f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i64(0.0f), 0LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(0.0f), 0ULL);
#endif
    CHECK(cast_f32_to_f32(0.0f) == 0.0f);
    CHECK(!signbit(cast_f32_to_f32(0.0f)));
    CHECK(cast_f32_to_f64(0.0f) == 0.0);
    CHECK(!signbit(cast_f32_to_f64(0.0f)));
    CHECK_EQ_UINT(cast_f32_to_u8((-0.0f)), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i8((-0.0f)), 0LL);
    CHECK_EQ_UINT(cast_f32_to_u16((-0.0f)), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i16((-0.0f)), 0LL);
    CHECK_EQ_UINT(cast_f32_to_u32((-0.0f)), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i32((-0.0f)), 0LL);
    CHECK_EQ_UINT(cast_f32_to_u64((-0.0f)), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i64((-0.0f)), 0LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t((-0.0f)), 0ULL);
#endif
    CHECK(cast_f32_to_f32((-0.0f)) == (-0.0f));
    CHECK(signbit(cast_f32_to_f32((-0.0f))));
    CHECK(cast_f32_to_f64((-0.0f)) == (-0.0));
    CHECK(signbit(cast_f32_to_f64((-0.0f))));
    CHECK_EQ_UINT(cast_f32_to_u8(0x1.0000000000000p-1f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i8(0x1.0000000000000p-1f), 0LL);
    CHECK_EQ_UINT(cast_f32_to_u16(0x1.0000000000000p-1f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i16(0x1.0000000000000p-1f), 0LL);
    CHECK_EQ_UINT(cast_f32_to_u32(0x1.0000000000000p-1f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i32(0x1.0000000000000p-1f), 0LL);
    CHECK_EQ_UINT(cast_f32_to_u64(0x1.0000000000000p-1f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i64(0x1.0000000000000p-1f), 0LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(0x1.0000000000000p-1f), 0ULL);
#endif
    CHECK(cast_f32_to_f32(0x1.0000000000000p-1f) == 0x1.0000000000000p-1f);
    CHECK(cast_f32_to_f64(0x1.0000000000000p-1f) == 0x1.0000000000000p-1);
    CHECK_EQ_UINT(cast_f32_to_u8(-0x1.0000000000000p-1f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i8(-0x1.0000000000000p-1f), 0LL);
    CHECK_EQ_UINT(cast_f32_to_u16(-0x1.0000000000000p-1f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i16(-0x1.0000000000000p-1f), 0LL);
    CHECK_EQ_UINT(cast_f32_to_u32(-0x1.0000000000000p-1f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i32(-0x1.0000000000000p-1f), 0LL);
    CHECK_EQ_UINT(cast_f32_to_u64(-0x1.0000000000000p-1f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i64(-0x1.0000000000000p-1f), 0LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(-0x1.0000000000000p-1f), 0ULL);
#endif
    CHECK(cast_f32_to_f32(-0x1.0000000000000p-1f) == -0x1.0000000000000p-1f);
    CHECK(cast_f32_to_f64(-0x1.0000000000000p-1f) == -0x1.0000000000000p-1);
    CHECK_EQ_UINT(cast_f32_to_u8(0x1.0000000000000p+0f), 1ULL);
    CHECK_EQ_INT(cast_f32_to_i8(0x1.0000000000000p+0f), 1LL);
    CHECK_EQ_UINT(cast_f32_to_u16(0x1.0000000000000p+0f), 1ULL);
    CHECK_EQ_INT(cast_f32_to_i16(0x1.0000000000000p+0f), 1LL);
    CHECK_EQ_UINT(cast_f32_to_u32(0x1.0000000000000p+0f), 1ULL);
    CHECK_EQ_INT(cast_f32_to_i32(0x1.0000000000000p+0f), 1LL);
    CHECK_EQ_UINT(cast_f32_to_u64(0x1.0000000000000p+0f), 1ULL);
    CHECK_EQ_INT(cast_f32_to_i64(0x1.0000000000000p+0f), 1LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(0x1.0000000000000p+0f), 1ULL);
#endif
    CHECK(cast_f32_to_f32(0x1.0000000000000p+0f) == 0x1.0000000000000p+0f);
    CHECK(cast_f32_to_f64(0x1.0000000000000p+0f) == 0x1.0000000000000p+0);
    CHECK_EQ_UINT(cast_f32_to_u8(-0x1.0000000000000p+0f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i8(-0x1.0000000000000p+0f), (-1LL));
    CHECK_EQ_UINT(cast_f32_to_u16(-0x1.0000000000000p+0f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i16(-0x1.0000000000000p+0f), (-1LL));
    CHECK_EQ_UINT(cast_f32_to_u32(-0x1.0000000000000p+0f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i32(-0x1.0000000000000p+0f), (-1LL));
    CHECK_EQ_UINT(cast_f32_to_u64(-0x1.0000000000000p+0f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i64(-0x1.0000000000000p+0f), (-1LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(-0x1.0000000000000p+0f), 0ULL);
#endif
    CHECK(cast_f32_to_f32(-0x1.0000000000000p+0f) == -0x1.0000000000000p+0f);
    CHECK(cast_f32_to_f64(-0x1.0000000000000p+0f) == -0x1.0000000000000p+0);
    CHECK_EQ_UINT(cast_f32_to_u8(0x1.0000000000000p+63f), 255ULL);
    CHECK_EQ_INT(cast_f32_to_i8(0x1.0000000000000p+63f), 127LL);
    CHECK_EQ_UINT(cast_f32_to_u16(0x1.0000000000000p+63f), 65535ULL);
    CHECK_EQ_INT(cast_f32_to_i16(0x1.0000000000000p+63f), 32767LL);
    CHECK_EQ_UINT(cast_f32_to_u32(0x1.0000000000000p+63f), 4294967295ULL);
    CHECK_EQ_INT(cast_f32_to_i32(0x1.0000000000000p+63f), 2147483647LL);
    CHECK_EQ_UINT(cast_f32_to_u64(0x1.0000000000000p+63f), 9223372036854775808ULL);
    CHECK_EQ_INT(cast_f32_to_i64(0x1.0000000000000p+63f), 9223372036854775807LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(0x1.0000000000000p+63f), 9223372036854775808ULL);
#endif
    CHECK(cast_f32_to_f32(0x1.0000000000000p+63f) == 0x1.0000000000000p+63f);
    CHECK(cast_f32_to_f64(0x1.0000000000000p+63f) == 0x1.0000000000000p+63);
    CHECK_EQ_UINT(cast_f32_to_u8(-0x1.0000000000000p+63f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i8(-0x1.0000000000000p+63f), (-128LL));
    CHECK_EQ_UINT(cast_f32_to_u16(-0x1.0000000000000p+63f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i16(-0x1.0000000000000p+63f), (-32768LL));
    CHECK_EQ_UINT(cast_f32_to_u32(-0x1.0000000000000p+63f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i32(-0x1.0000000000000p+63f), (-2147483648LL));
    CHECK_EQ_UINT(cast_f32_to_u64(-0x1.0000000000000p+63f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i64(-0x1.0000000000000p+63f), INT64_MIN);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(-0x1.0000000000000p+63f), 0ULL);
#endif
    CHECK(cast_f32_to_f32(-0x1.0000000000000p+63f) == -0x1.0000000000000p+63f);
    CHECK(cast_f32_to_f64(-0x1.0000000000000p+63f) == -0x1.0000000000000p+63);
    CHECK_EQ_UINT(cast_f32_to_u8(0x1.0000000000000p+64f), 255ULL);
    CHECK_EQ_INT(cast_f32_to_i8(0x1.0000000000000p+64f), 127LL);
    CHECK_EQ_UINT(cast_f32_to_u16(0x1.0000000000000p+64f), 65535ULL);
    CHECK_EQ_INT(cast_f32_to_i16(0x1.0000000000000p+64f), 32767LL);
    CHECK_EQ_UINT(cast_f32_to_u32(0x1.0000000000000p+64f), 4294967295ULL);
    CHECK_EQ_INT(cast_f32_to_i32(0x1.0000000000000p+64f), 2147483647LL);
    CHECK_EQ_UINT(cast_f32_to_u64(0x1.0000000000000p+64f), 18446744073709551615ULL);
    CHECK_EQ_INT(cast_f32_to_i64(0x1.0000000000000p+64f), 9223372036854775807LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(0x1.0000000000000p+64f), 18446744073709551615ULL);
#endif
    CHECK(cast_f32_to_f32(0x1.0000000000000p+64f) == 0x1.0000000000000p+64f);
    CHECK(cast_f32_to_f64(0x1.0000000000000p+64f) == 0x1.0000000000000p+64);
    CHECK_EQ_UINT(cast_f32_to_u8(0x1.8000000000000p+63f), 255ULL);
    CHECK_EQ_INT(cast_f32_to_i8(0x1.8000000000000p+63f), 127LL);
    CHECK_EQ_UINT(cast_f32_to_u16(0x1.8000000000000p+63f), 65535ULL);
    CHECK_EQ_INT(cast_f32_to_i16(0x1.8000000000000p+63f), 32767LL);
    CHECK_EQ_UINT(cast_f32_to_u32(0x1.8000000000000p+63f), 4294967295ULL);
    CHECK_EQ_INT(cast_f32_to_i32(0x1.8000000000000p+63f), 2147483647LL);
    CHECK_EQ_UINT(cast_f32_to_u64(0x1.8000000000000p+63f), 13835058055282163712ULL);
    CHECK_EQ_INT(cast_f32_to_i64(0x1.8000000000000p+63f), 9223372036854775807LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(0x1.8000000000000p+63f), 13835058055282163712ULL);
#endif
    CHECK(cast_f32_to_f32(0x1.8000000000000p+63f) == 0x1.8000000000000p+63f);
    CHECK(cast_f32_to_f64(0x1.8000000000000p+63f) == 0x1.8000000000000p+63);
    CHECK_EQ_UINT(cast_f32_to_u8(-0x1.0000000000000p+64f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i8(-0x1.0000000000000p+64f), (-128LL));
    CHECK_EQ_UINT(cast_f32_to_u16(-0x1.0000000000000p+64f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i16(-0x1.0000000000000p+64f), (-32768LL));
    CHECK_EQ_UINT(cast_f32_to_u32(-0x1.0000000000000p+64f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i32(-0x1.0000000000000p+64f), (-2147483648LL));
    CHECK_EQ_UINT(cast_f32_to_u64(-0x1.0000000000000p+64f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i64(-0x1.0000000000000p+64f), INT64_MIN);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(-0x1.0000000000000p+64f), 0ULL);
#endif
    CHECK(cast_f32_to_f32(-0x1.0000000000000p+64f) == -0x1.0000000000000p+64f);
    CHECK(cast_f32_to_f64(-0x1.0000000000000p+64f) == -0x1.0000000000000p+64);
    CHECK_EQ_UINT(cast_f32_to_u8(0x1.fffffe0000000p+127f), 255ULL);
    CHECK_EQ_INT(cast_f32_to_i8(0x1.fffffe0000000p+127f), 127LL);
    CHECK_EQ_UINT(cast_f32_to_u16(0x1.fffffe0000000p+127f), 65535ULL);
    CHECK_EQ_INT(cast_f32_to_i16(0x1.fffffe0000000p+127f), 32767LL);
    CHECK_EQ_UINT(cast_f32_to_u32(0x1.fffffe0000000p+127f), 4294967295ULL);
    CHECK_EQ_INT(cast_f32_to_i32(0x1.fffffe0000000p+127f), 2147483647LL);
    CHECK_EQ_UINT(cast_f32_to_u64(0x1.fffffe0000000p+127f), 18446744073709551615ULL);
    CHECK_EQ_INT(cast_f32_to_i64(0x1.fffffe0000000p+127f), 9223372036854775807LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(0x1.fffffe0000000p+127f), 18446744073709551615ULL);
#endif
    CHECK(cast_f32_to_f32(0x1.fffffe0000000p+127f) == 0x1.fffffe0000000p+127f);
    CHECK(cast_f32_to_f64(0x1.fffffe0000000p+127f) == 0x1.fffffe0000000p+127);
    CHECK_EQ_UINT(cast_f32_to_u8(-0x1.fffffe0000000p+127f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i8(-0x1.fffffe0000000p+127f), (-128LL));
    CHECK_EQ_UINT(cast_f32_to_u16(-0x1.fffffe0000000p+127f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i16(-0x1.fffffe0000000p+127f), (-32768LL));
    CHECK_EQ_UINT(cast_f32_to_u32(-0x1.fffffe0000000p+127f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i32(-0x1.fffffe0000000p+127f), (-2147483648LL));
    CHECK_EQ_UINT(cast_f32_to_u64(-0x1.fffffe0000000p+127f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i64(-0x1.fffffe0000000p+127f), INT64_MIN);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(-0x1.fffffe0000000p+127f), 0ULL);
#endif
    CHECK(cast_f32_to_f32(-0x1.fffffe0000000p+127f) == -0x1.fffffe0000000p+127f);
    CHECK(cast_f32_to_f64(-0x1.fffffe0000000p+127f) == -0x1.fffffe0000000p+127);
    CHECK_EQ_UINT(cast_f32_to_u8(0x1.fe00000000000p+7f), 255ULL);
    CHECK_EQ_INT(cast_f32_to_i8(0x1.fe00000000000p+7f), 127LL);
    CHECK_EQ_UINT(cast_f32_to_u16(0x1.fe00000000000p+7f), 255ULL);
    CHECK_EQ_INT(cast_f32_to_i16(0x1.fe00000000000p+7f), 255LL);
    CHECK_EQ_UINT(cast_f32_to_u32(0x1.fe00000000000p+7f), 255ULL);
    CHECK_EQ_INT(cast_f32_to_i32(0x1.fe00000000000p+7f), 255LL);
    CHECK_EQ_UINT(cast_f32_to_u64(0x1.fe00000000000p+7f), 255ULL);
    CHECK_EQ_INT(cast_f32_to_i64(0x1.fe00000000000p+7f), 255LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(0x1.fe00000000000p+7f), 255ULL);
#endif
    CHECK(cast_f32_to_f32(0x1.fe00000000000p+7f) == 0x1.fe00000000000p+7f);
    CHECK(cast_f32_to_f64(0x1.fe00000000000p+7f) == 0x1.fe00000000000p+7);
    CHECK_EQ_UINT(cast_f32_to_u8(0x1.ff00000000000p+7f), 255ULL);
    CHECK_EQ_INT(cast_f32_to_i8(0x1.ff00000000000p+7f), 127LL);
    CHECK_EQ_UINT(cast_f32_to_u16(0x1.ff00000000000p+7f), 255ULL);
    CHECK_EQ_INT(cast_f32_to_i16(0x1.ff00000000000p+7f), 255LL);
    CHECK_EQ_UINT(cast_f32_to_u32(0x1.ff00000000000p+7f), 255ULL);
    CHECK_EQ_INT(cast_f32_to_i32(0x1.ff00000000000p+7f), 255LL);
    CHECK_EQ_UINT(cast_f32_to_u64(0x1.ff00000000000p+7f), 255ULL);
    CHECK_EQ_INT(cast_f32_to_i64(0x1.ff00000000000p+7f), 255LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(0x1.ff00000000000p+7f), 255ULL);
#endif
    CHECK(cast_f32_to_f32(0x1.ff00000000000p+7f) == 0x1.ff00000000000p+7f);
    CHECK(cast_f32_to_f64(0x1.ff00000000000p+7f) == 0x1.ff00000000000p+7);
    CHECK_EQ_UINT(cast_f32_to_u8(0x1.fd00000000000p+7f), 254ULL);
    CHECK_EQ_INT(cast_f32_to_i8(0x1.fd00000000000p+7f), 127LL);
    CHECK_EQ_UINT(cast_f32_to_u16(0x1.fd00000000000p+7f), 254ULL);
    CHECK_EQ_INT(cast_f32_to_i16(0x1.fd00000000000p+7f), 254LL);
    CHECK_EQ_UINT(cast_f32_to_u32(0x1.fd00000000000p+7f), 254ULL);
    CHECK_EQ_INT(cast_f32_to_i32(0x1.fd00000000000p+7f), 254LL);
    CHECK_EQ_UINT(cast_f32_to_u64(0x1.fd00000000000p+7f), 254ULL);
    CHECK_EQ_INT(cast_f32_to_i64(0x1.fd00000000000p+7f), 254LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(0x1.fd00000000000p+7f), 254ULL);
#endif
    CHECK(cast_f32_to_f32(0x1.fd00000000000p+7f) == 0x1.fd00000000000p+7f);
    CHECK(cast_f32_to_f64(0x1.fd00000000000p+7f) == 0x1.fd00000000000p+7);
    CHECK_EQ_UINT(cast_f32_to_u8(-0x1.8000000000000p+0f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i8(-0x1.8000000000000p+0f), (-1LL));
    CHECK_EQ_UINT(cast_f32_to_u16(-0x1.8000000000000p+0f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i16(-0x1.8000000000000p+0f), (-1LL));
    CHECK_EQ_UINT(cast_f32_to_u32(-0x1.8000000000000p+0f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i32(-0x1.8000000000000p+0f), (-1LL));
    CHECK_EQ_UINT(cast_f32_to_u64(-0x1.8000000000000p+0f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i64(-0x1.8000000000000p+0f), (-1LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(-0x1.8000000000000p+0f), 0ULL);
#endif
    CHECK(cast_f32_to_f32(-0x1.8000000000000p+0f) == -0x1.8000000000000p+0f);
    CHECK(cast_f32_to_f64(-0x1.8000000000000p+0f) == -0x1.8000000000000p+0);
    CHECK_EQ_UINT(cast_f32_to_u8(0x1.0000000000000p+8f), 255ULL);
    CHECK_EQ_INT(cast_f32_to_i8(0x1.0000000000000p+8f), 127LL);
    CHECK_EQ_UINT(cast_f32_to_u16(0x1.0000000000000p+8f), 256ULL);
    CHECK_EQ_INT(cast_f32_to_i16(0x1.0000000000000p+8f), 256LL);
    CHECK_EQ_UINT(cast_f32_to_u32(0x1.0000000000000p+8f), 256ULL);
    CHECK_EQ_INT(cast_f32_to_i32(0x1.0000000000000p+8f), 256LL);
    CHECK_EQ_UINT(cast_f32_to_u64(0x1.0000000000000p+8f), 256ULL);
    CHECK_EQ_INT(cast_f32_to_i64(0x1.0000000000000p+8f), 256LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(0x1.0000000000000p+8f), 256ULL);
#endif
    CHECK(cast_f32_to_f32(0x1.0000000000000p+8f) == 0x1.0000000000000p+8f);
    CHECK(cast_f32_to_f64(0x1.0000000000000p+8f) == 0x1.0000000000000p+8);
    CHECK_EQ_UINT(cast_f32_to_u8(0x1.0080000000000p+8f), 255ULL);
    CHECK_EQ_INT(cast_f32_to_i8(0x1.0080000000000p+8f), 127LL);
    CHECK_EQ_UINT(cast_f32_to_u16(0x1.0080000000000p+8f), 256ULL);
    CHECK_EQ_INT(cast_f32_to_i16(0x1.0080000000000p+8f), 256LL);
    CHECK_EQ_UINT(cast_f32_to_u32(0x1.0080000000000p+8f), 256ULL);
    CHECK_EQ_INT(cast_f32_to_i32(0x1.0080000000000p+8f), 256LL);
    CHECK_EQ_UINT(cast_f32_to_u64(0x1.0080000000000p+8f), 256ULL);
    CHECK_EQ_INT(cast_f32_to_i64(0x1.0080000000000p+8f), 256LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(0x1.0080000000000p+8f), 256ULL);
#endif
    CHECK(cast_f32_to_f32(0x1.0080000000000p+8f) == 0x1.0080000000000p+8f);
    CHECK(cast_f32_to_f64(0x1.0080000000000p+8f) == 0x1.0080000000000p+8);
    CHECK_EQ_UINT(cast_f32_to_u8(-0x1.0000000000000p+7f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i8(-0x1.0000000000000p+7f), (-128LL));
    CHECK_EQ_UINT(cast_f32_to_u16(-0x1.0000000000000p+7f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i16(-0x1.0000000000000p+7f), (-128LL));
    CHECK_EQ_UINT(cast_f32_to_u32(-0x1.0000000000000p+7f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i32(-0x1.0000000000000p+7f), (-128LL));
    CHECK_EQ_UINT(cast_f32_to_u64(-0x1.0000000000000p+7f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i64(-0x1.0000000000000p+7f), (-128LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(-0x1.0000000000000p+7f), 0ULL);
#endif
    CHECK(cast_f32_to_f32(-0x1.0000000000000p+7f) == -0x1.0000000000000p+7f);
    CHECK(cast_f32_to_f64(-0x1.0000000000000p+7f) == -0x1.0000000000000p+7);
    CHECK_EQ_UINT(cast_f32_to_u8(-0x1.fe00000000000p+6f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i8(-0x1.fe00000000000p+6f), (-127LL));
    CHECK_EQ_UINT(cast_f32_to_u16(-0x1.fe00000000000p+6f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i16(-0x1.fe00000000000p+6f), (-127LL));
    CHECK_EQ_UINT(cast_f32_to_u32(-0x1.fe00000000000p+6f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i32(-0x1.fe00000000000p+6f), (-127LL));
    CHECK_EQ_UINT(cast_f32_to_u64(-0x1.fe00000000000p+6f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i64(-0x1.fe00000000000p+6f), (-127LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(-0x1.fe00000000000p+6f), 0ULL);
#endif
    CHECK(cast_f32_to_f32(-0x1.fe00000000000p+6f) == -0x1.fe00000000000p+6f);
    CHECK(cast_f32_to_f64(-0x1.fe00000000000p+6f) == -0x1.fe00000000000p+6);
    CHECK_EQ_UINT(cast_f32_to_u8(-0x1.0100000000000p+7f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i8(-0x1.0100000000000p+7f), (-128LL));
    CHECK_EQ_UINT(cast_f32_to_u16(-0x1.0100000000000p+7f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i16(-0x1.0100000000000p+7f), (-128LL));
    CHECK_EQ_UINT(cast_f32_to_u32(-0x1.0100000000000p+7f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i32(-0x1.0100000000000p+7f), (-128LL));
    CHECK_EQ_UINT(cast_f32_to_u64(-0x1.0100000000000p+7f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i64(-0x1.0100000000000p+7f), (-128LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(-0x1.0100000000000p+7f), 0ULL);
#endif
    CHECK(cast_f32_to_f32(-0x1.0100000000000p+7f) == -0x1.0100000000000p+7f);
    CHECK(cast_f32_to_f64(-0x1.0100000000000p+7f) == -0x1.0100000000000p+7);
    CHECK_EQ_UINT(cast_f32_to_u8(0x1.fc00000000000p+6f), 127ULL);
    CHECK_EQ_INT(cast_f32_to_i8(0x1.fc00000000000p+6f), 127LL);
    CHECK_EQ_UINT(cast_f32_to_u16(0x1.fc00000000000p+6f), 127ULL);
    CHECK_EQ_INT(cast_f32_to_i16(0x1.fc00000000000p+6f), 127LL);
    CHECK_EQ_UINT(cast_f32_to_u32(0x1.fc00000000000p+6f), 127ULL);
    CHECK_EQ_INT(cast_f32_to_i32(0x1.fc00000000000p+6f), 127LL);
    CHECK_EQ_UINT(cast_f32_to_u64(0x1.fc00000000000p+6f), 127ULL);
    CHECK_EQ_INT(cast_f32_to_i64(0x1.fc00000000000p+6f), 127LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(0x1.fc00000000000p+6f), 127ULL);
#endif
    CHECK(cast_f32_to_f32(0x1.fc00000000000p+6f) == 0x1.fc00000000000p+6f);
    CHECK(cast_f32_to_f64(0x1.fc00000000000p+6f) == 0x1.fc00000000000p+6);
    CHECK_EQ_UINT(cast_f32_to_u8(0x1.fe00000000000p+6f), 127ULL);
    CHECK_EQ_INT(cast_f32_to_i8(0x1.fe00000000000p+6f), 127LL);
    CHECK_EQ_UINT(cast_f32_to_u16(0x1.fe00000000000p+6f), 127ULL);
    CHECK_EQ_INT(cast_f32_to_i16(0x1.fe00000000000p+6f), 127LL);
    CHECK_EQ_UINT(cast_f32_to_u32(0x1.fe00000000000p+6f), 127ULL);
    CHECK_EQ_INT(cast_f32_to_i32(0x1.fe00000000000p+6f), 127LL);
    CHECK_EQ_UINT(cast_f32_to_u64(0x1.fe00000000000p+6f), 127ULL);
    CHECK_EQ_INT(cast_f32_to_i64(0x1.fe00000000000p+6f), 127LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(0x1.fe00000000000p+6f), 127ULL);
#endif
    CHECK(cast_f32_to_f32(0x1.fe00000000000p+6f) == 0x1.fe00000000000p+6f);
    CHECK(cast_f32_to_f64(0x1.fe00000000000p+6f) == 0x1.fe00000000000p+6);
    CHECK_EQ_UINT(cast_f32_to_u8(0x1.fa00000000000p+6f), 126ULL);
    CHECK_EQ_INT(cast_f32_to_i8(0x1.fa00000000000p+6f), 126LL);
    CHECK_EQ_UINT(cast_f32_to_u16(0x1.fa00000000000p+6f), 126ULL);
    CHECK_EQ_INT(cast_f32_to_i16(0x1.fa00000000000p+6f), 126LL);
    CHECK_EQ_UINT(cast_f32_to_u32(0x1.fa00000000000p+6f), 126ULL);
    CHECK_EQ_INT(cast_f32_to_i32(0x1.fa00000000000p+6f), 126LL);
    CHECK_EQ_UINT(cast_f32_to_u64(0x1.fa00000000000p+6f), 126ULL);
    CHECK_EQ_INT(cast_f32_to_i64(0x1.fa00000000000p+6f), 126LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(0x1.fa00000000000p+6f), 126ULL);
#endif
    CHECK(cast_f32_to_f32(0x1.fa00000000000p+6f) == 0x1.fa00000000000p+6f);
    CHECK(cast_f32_to_f64(0x1.fa00000000000p+6f) == 0x1.fa00000000000p+6);
    CHECK_EQ_UINT(cast_f32_to_u8(-0x1.0200000000000p+7f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i8(-0x1.0200000000000p+7f), (-128LL));
    CHECK_EQ_UINT(cast_f32_to_u16(-0x1.0200000000000p+7f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i16(-0x1.0200000000000p+7f), (-129LL));
    CHECK_EQ_UINT(cast_f32_to_u32(-0x1.0200000000000p+7f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i32(-0x1.0200000000000p+7f), (-129LL));
    CHECK_EQ_UINT(cast_f32_to_u64(-0x1.0200000000000p+7f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i64(-0x1.0200000000000p+7f), (-129LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(-0x1.0200000000000p+7f), 0ULL);
#endif
    CHECK(cast_f32_to_f32(-0x1.0200000000000p+7f) == -0x1.0200000000000p+7f);
    CHECK(cast_f32_to_f64(-0x1.0200000000000p+7f) == -0x1.0200000000000p+7);
    CHECK_EQ_UINT(cast_f32_to_u8(-0x1.0300000000000p+7f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i8(-0x1.0300000000000p+7f), (-128LL));
    CHECK_EQ_UINT(cast_f32_to_u16(-0x1.0300000000000p+7f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i16(-0x1.0300000000000p+7f), (-129LL));
    CHECK_EQ_UINT(cast_f32_to_u32(-0x1.0300000000000p+7f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i32(-0x1.0300000000000p+7f), (-129LL));
    CHECK_EQ_UINT(cast_f32_to_u64(-0x1.0300000000000p+7f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i64(-0x1.0300000000000p+7f), (-129LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(-0x1.0300000000000p+7f), 0ULL);
#endif
    CHECK(cast_f32_to_f32(-0x1.0300000000000p+7f) == -0x1.0300000000000p+7f);
    CHECK(cast_f32_to_f64(-0x1.0300000000000p+7f) == -0x1.0300000000000p+7);
    CHECK_EQ_UINT(cast_f32_to_u8(0x1.0000000000000p+7f), 128ULL);
    CHECK_EQ_INT(cast_f32_to_i8(0x1.0000000000000p+7f), 127LL);
    CHECK_EQ_UINT(cast_f32_to_u16(0x1.0000000000000p+7f), 128ULL);
    CHECK_EQ_INT(cast_f32_to_i16(0x1.0000000000000p+7f), 128LL);
    CHECK_EQ_UINT(cast_f32_to_u32(0x1.0000000000000p+7f), 128ULL);
    CHECK_EQ_INT(cast_f32_to_i32(0x1.0000000000000p+7f), 128LL);
    CHECK_EQ_UINT(cast_f32_to_u64(0x1.0000000000000p+7f), 128ULL);
    CHECK_EQ_INT(cast_f32_to_i64(0x1.0000000000000p+7f), 128LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(0x1.0000000000000p+7f), 128ULL);
#endif
    CHECK(cast_f32_to_f32(0x1.0000000000000p+7f) == 0x1.0000000000000p+7f);
    CHECK(cast_f32_to_f64(0x1.0000000000000p+7f) == 0x1.0000000000000p+7);
    CHECK_EQ_UINT(cast_f32_to_u8(0x1.0100000000000p+7f), 128ULL);
    CHECK_EQ_INT(cast_f32_to_i8(0x1.0100000000000p+7f), 127LL);
    CHECK_EQ_UINT(cast_f32_to_u16(0x1.0100000000000p+7f), 128ULL);
    CHECK_EQ_INT(cast_f32_to_i16(0x1.0100000000000p+7f), 128LL);
    CHECK_EQ_UINT(cast_f32_to_u32(0x1.0100000000000p+7f), 128ULL);
    CHECK_EQ_INT(cast_f32_to_i32(0x1.0100000000000p+7f), 128LL);
    CHECK_EQ_UINT(cast_f32_to_u64(0x1.0100000000000p+7f), 128ULL);
    CHECK_EQ_INT(cast_f32_to_i64(0x1.0100000000000p+7f), 128LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(0x1.0100000000000p+7f), 128ULL);
#endif
    CHECK(cast_f32_to_f32(0x1.0100000000000p+7f) == 0x1.0100000000000p+7f);
    CHECK(cast_f32_to_f64(0x1.0100000000000p+7f) == 0x1.0100000000000p+7);
    CHECK_EQ_UINT(cast_f32_to_u8(0x1.fffe000000000p+15f), 255ULL);
    CHECK_EQ_INT(cast_f32_to_i8(0x1.fffe000000000p+15f), 127LL);
    CHECK_EQ_UINT(cast_f32_to_u16(0x1.fffe000000000p+15f), 65535ULL);
    CHECK_EQ_INT(cast_f32_to_i16(0x1.fffe000000000p+15f), 32767LL);
    CHECK_EQ_UINT(cast_f32_to_u32(0x1.fffe000000000p+15f), 65535ULL);
    CHECK_EQ_INT(cast_f32_to_i32(0x1.fffe000000000p+15f), 65535LL);
    CHECK_EQ_UINT(cast_f32_to_u64(0x1.fffe000000000p+15f), 65535ULL);
    CHECK_EQ_INT(cast_f32_to_i64(0x1.fffe000000000p+15f), 65535LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(0x1.fffe000000000p+15f), 65535ULL);
#endif
    CHECK(cast_f32_to_f32(0x1.fffe000000000p+15f) == 0x1.fffe000000000p+15f);
    CHECK(cast_f32_to_f64(0x1.fffe000000000p+15f) == 0x1.fffe000000000p+15);
    CHECK_EQ_UINT(cast_f32_to_u8(0x1.ffff000000000p+15f), 255ULL);
    CHECK_EQ_INT(cast_f32_to_i8(0x1.ffff000000000p+15f), 127LL);
    CHECK_EQ_UINT(cast_f32_to_u16(0x1.ffff000000000p+15f), 65535ULL);
    CHECK_EQ_INT(cast_f32_to_i16(0x1.ffff000000000p+15f), 32767LL);
    CHECK_EQ_UINT(cast_f32_to_u32(0x1.ffff000000000p+15f), 65535ULL);
    CHECK_EQ_INT(cast_f32_to_i32(0x1.ffff000000000p+15f), 65535LL);
    CHECK_EQ_UINT(cast_f32_to_u64(0x1.ffff000000000p+15f), 65535ULL);
    CHECK_EQ_INT(cast_f32_to_i64(0x1.ffff000000000p+15f), 65535LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(0x1.ffff000000000p+15f), 65535ULL);
#endif
    CHECK(cast_f32_to_f32(0x1.ffff000000000p+15f) == 0x1.ffff000000000p+15f);
    CHECK(cast_f32_to_f64(0x1.ffff000000000p+15f) == 0x1.ffff000000000p+15);
    CHECK_EQ_UINT(cast_f32_to_u8(0x1.fffd000000000p+15f), 255ULL);
    CHECK_EQ_INT(cast_f32_to_i8(0x1.fffd000000000p+15f), 127LL);
    CHECK_EQ_UINT(cast_f32_to_u16(0x1.fffd000000000p+15f), 65534ULL);
    CHECK_EQ_INT(cast_f32_to_i16(0x1.fffd000000000p+15f), 32767LL);
    CHECK_EQ_UINT(cast_f32_to_u32(0x1.fffd000000000p+15f), 65534ULL);
    CHECK_EQ_INT(cast_f32_to_i32(0x1.fffd000000000p+15f), 65534LL);
    CHECK_EQ_UINT(cast_f32_to_u64(0x1.fffd000000000p+15f), 65534ULL);
    CHECK_EQ_INT(cast_f32_to_i64(0x1.fffd000000000p+15f), 65534LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(0x1.fffd000000000p+15f), 65534ULL);
#endif
    CHECK(cast_f32_to_f32(0x1.fffd000000000p+15f) == 0x1.fffd000000000p+15f);
    CHECK(cast_f32_to_f64(0x1.fffd000000000p+15f) == 0x1.fffd000000000p+15);
    CHECK_EQ_UINT(cast_f32_to_u8(0x1.0000000000000p+16f), 255ULL);
    CHECK_EQ_INT(cast_f32_to_i8(0x1.0000000000000p+16f), 127LL);
    CHECK_EQ_UINT(cast_f32_to_u16(0x1.0000000000000p+16f), 65535ULL);
    CHECK_EQ_INT(cast_f32_to_i16(0x1.0000000000000p+16f), 32767LL);
    CHECK_EQ_UINT(cast_f32_to_u32(0x1.0000000000000p+16f), 65536ULL);
    CHECK_EQ_INT(cast_f32_to_i32(0x1.0000000000000p+16f), 65536LL);
    CHECK_EQ_UINT(cast_f32_to_u64(0x1.0000000000000p+16f), 65536ULL);
    CHECK_EQ_INT(cast_f32_to_i64(0x1.0000000000000p+16f), 65536LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(0x1.0000000000000p+16f), 65536ULL);
#endif
    CHECK(cast_f32_to_f32(0x1.0000000000000p+16f) == 0x1.0000000000000p+16f);
    CHECK(cast_f32_to_f64(0x1.0000000000000p+16f) == 0x1.0000000000000p+16);
    CHECK_EQ_UINT(cast_f32_to_u8(0x1.0000800000000p+16f), 255ULL);
    CHECK_EQ_INT(cast_f32_to_i8(0x1.0000800000000p+16f), 127LL);
    CHECK_EQ_UINT(cast_f32_to_u16(0x1.0000800000000p+16f), 65535ULL);
    CHECK_EQ_INT(cast_f32_to_i16(0x1.0000800000000p+16f), 32767LL);
    CHECK_EQ_UINT(cast_f32_to_u32(0x1.0000800000000p+16f), 65536ULL);
    CHECK_EQ_INT(cast_f32_to_i32(0x1.0000800000000p+16f), 65536LL);
    CHECK_EQ_UINT(cast_f32_to_u64(0x1.0000800000000p+16f), 65536ULL);
    CHECK_EQ_INT(cast_f32_to_i64(0x1.0000800000000p+16f), 65536LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(0x1.0000800000000p+16f), 65536ULL);
#endif
    CHECK(cast_f32_to_f32(0x1.0000800000000p+16f) == 0x1.0000800000000p+16f);
    CHECK(cast_f32_to_f64(0x1.0000800000000p+16f) == 0x1.0000800000000p+16);
    CHECK_EQ_UINT(cast_f32_to_u8(-0x1.0000000000000p+15f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i8(-0x1.0000000000000p+15f), (-128LL));
    CHECK_EQ_UINT(cast_f32_to_u16(-0x1.0000000000000p+15f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i16(-0x1.0000000000000p+15f), (-32768LL));
    CHECK_EQ_UINT(cast_f32_to_u32(-0x1.0000000000000p+15f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i32(-0x1.0000000000000p+15f), (-32768LL));
    CHECK_EQ_UINT(cast_f32_to_u64(-0x1.0000000000000p+15f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i64(-0x1.0000000000000p+15f), (-32768LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(-0x1.0000000000000p+15f), 0ULL);
#endif
    CHECK(cast_f32_to_f32(-0x1.0000000000000p+15f) == -0x1.0000000000000p+15f);
    CHECK(cast_f32_to_f64(-0x1.0000000000000p+15f) == -0x1.0000000000000p+15);
    CHECK_EQ_UINT(cast_f32_to_u8(-0x1.fffe000000000p+14f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i8(-0x1.fffe000000000p+14f), (-128LL));
    CHECK_EQ_UINT(cast_f32_to_u16(-0x1.fffe000000000p+14f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i16(-0x1.fffe000000000p+14f), (-32767LL));
    CHECK_EQ_UINT(cast_f32_to_u32(-0x1.fffe000000000p+14f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i32(-0x1.fffe000000000p+14f), (-32767LL));
    CHECK_EQ_UINT(cast_f32_to_u64(-0x1.fffe000000000p+14f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i64(-0x1.fffe000000000p+14f), (-32767LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(-0x1.fffe000000000p+14f), 0ULL);
#endif
    CHECK(cast_f32_to_f32(-0x1.fffe000000000p+14f) == -0x1.fffe000000000p+14f);
    CHECK(cast_f32_to_f64(-0x1.fffe000000000p+14f) == -0x1.fffe000000000p+14);
    CHECK_EQ_UINT(cast_f32_to_u8(-0x1.0001000000000p+15f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i8(-0x1.0001000000000p+15f), (-128LL));
    CHECK_EQ_UINT(cast_f32_to_u16(-0x1.0001000000000p+15f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i16(-0x1.0001000000000p+15f), (-32768LL));
    CHECK_EQ_UINT(cast_f32_to_u32(-0x1.0001000000000p+15f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i32(-0x1.0001000000000p+15f), (-32768LL));
    CHECK_EQ_UINT(cast_f32_to_u64(-0x1.0001000000000p+15f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i64(-0x1.0001000000000p+15f), (-32768LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(-0x1.0001000000000p+15f), 0ULL);
#endif
    CHECK(cast_f32_to_f32(-0x1.0001000000000p+15f) == -0x1.0001000000000p+15f);
    CHECK(cast_f32_to_f64(-0x1.0001000000000p+15f) == -0x1.0001000000000p+15);
    CHECK_EQ_UINT(cast_f32_to_u8(0x1.fffc000000000p+14f), 255ULL);
    CHECK_EQ_INT(cast_f32_to_i8(0x1.fffc000000000p+14f), 127LL);
    CHECK_EQ_UINT(cast_f32_to_u16(0x1.fffc000000000p+14f), 32767ULL);
    CHECK_EQ_INT(cast_f32_to_i16(0x1.fffc000000000p+14f), 32767LL);
    CHECK_EQ_UINT(cast_f32_to_u32(0x1.fffc000000000p+14f), 32767ULL);
    CHECK_EQ_INT(cast_f32_to_i32(0x1.fffc000000000p+14f), 32767LL);
    CHECK_EQ_UINT(cast_f32_to_u64(0x1.fffc000000000p+14f), 32767ULL);
    CHECK_EQ_INT(cast_f32_to_i64(0x1.fffc000000000p+14f), 32767LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(0x1.fffc000000000p+14f), 32767ULL);
#endif
    CHECK(cast_f32_to_f32(0x1.fffc000000000p+14f) == 0x1.fffc000000000p+14f);
    CHECK(cast_f32_to_f64(0x1.fffc000000000p+14f) == 0x1.fffc000000000p+14);
    CHECK_EQ_UINT(cast_f32_to_u8(0x1.fffe000000000p+14f), 255ULL);
    CHECK_EQ_INT(cast_f32_to_i8(0x1.fffe000000000p+14f), 127LL);
    CHECK_EQ_UINT(cast_f32_to_u16(0x1.fffe000000000p+14f), 32767ULL);
    CHECK_EQ_INT(cast_f32_to_i16(0x1.fffe000000000p+14f), 32767LL);
    CHECK_EQ_UINT(cast_f32_to_u32(0x1.fffe000000000p+14f), 32767ULL);
    CHECK_EQ_INT(cast_f32_to_i32(0x1.fffe000000000p+14f), 32767LL);
    CHECK_EQ_UINT(cast_f32_to_u64(0x1.fffe000000000p+14f), 32767ULL);
    CHECK_EQ_INT(cast_f32_to_i64(0x1.fffe000000000p+14f), 32767LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(0x1.fffe000000000p+14f), 32767ULL);
#endif
    CHECK(cast_f32_to_f32(0x1.fffe000000000p+14f) == 0x1.fffe000000000p+14f);
    CHECK(cast_f32_to_f64(0x1.fffe000000000p+14f) == 0x1.fffe000000000p+14);
    CHECK_EQ_UINT(cast_f32_to_u8(0x1.fffa000000000p+14f), 255ULL);
    CHECK_EQ_INT(cast_f32_to_i8(0x1.fffa000000000p+14f), 127LL);
    CHECK_EQ_UINT(cast_f32_to_u16(0x1.fffa000000000p+14f), 32766ULL);
    CHECK_EQ_INT(cast_f32_to_i16(0x1.fffa000000000p+14f), 32766LL);
    CHECK_EQ_UINT(cast_f32_to_u32(0x1.fffa000000000p+14f), 32766ULL);
    CHECK_EQ_INT(cast_f32_to_i32(0x1.fffa000000000p+14f), 32766LL);
    CHECK_EQ_UINT(cast_f32_to_u64(0x1.fffa000000000p+14f), 32766ULL);
    CHECK_EQ_INT(cast_f32_to_i64(0x1.fffa000000000p+14f), 32766LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(0x1.fffa000000000p+14f), 32766ULL);
#endif
    CHECK(cast_f32_to_f32(0x1.fffa000000000p+14f) == 0x1.fffa000000000p+14f);
    CHECK(cast_f32_to_f64(0x1.fffa000000000p+14f) == 0x1.fffa000000000p+14);
    CHECK_EQ_UINT(cast_f32_to_u8(-0x1.0002000000000p+15f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i8(-0x1.0002000000000p+15f), (-128LL));
    CHECK_EQ_UINT(cast_f32_to_u16(-0x1.0002000000000p+15f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i16(-0x1.0002000000000p+15f), (-32768LL));
    CHECK_EQ_UINT(cast_f32_to_u32(-0x1.0002000000000p+15f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i32(-0x1.0002000000000p+15f), (-32769LL));
    CHECK_EQ_UINT(cast_f32_to_u64(-0x1.0002000000000p+15f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i64(-0x1.0002000000000p+15f), (-32769LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(-0x1.0002000000000p+15f), 0ULL);
#endif
    CHECK(cast_f32_to_f32(-0x1.0002000000000p+15f) == -0x1.0002000000000p+15f);
    CHECK(cast_f32_to_f64(-0x1.0002000000000p+15f) == -0x1.0002000000000p+15);
    CHECK_EQ_UINT(cast_f32_to_u8(-0x1.0003000000000p+15f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i8(-0x1.0003000000000p+15f), (-128LL));
    CHECK_EQ_UINT(cast_f32_to_u16(-0x1.0003000000000p+15f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i16(-0x1.0003000000000p+15f), (-32768LL));
    CHECK_EQ_UINT(cast_f32_to_u32(-0x1.0003000000000p+15f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i32(-0x1.0003000000000p+15f), (-32769LL));
    CHECK_EQ_UINT(cast_f32_to_u64(-0x1.0003000000000p+15f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i64(-0x1.0003000000000p+15f), (-32769LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(-0x1.0003000000000p+15f), 0ULL);
#endif
    CHECK(cast_f32_to_f32(-0x1.0003000000000p+15f) == -0x1.0003000000000p+15f);
    CHECK(cast_f32_to_f64(-0x1.0003000000000p+15f) == -0x1.0003000000000p+15);
    CHECK_EQ_UINT(cast_f32_to_u8(0x1.0000000000000p+15f), 255ULL);
    CHECK_EQ_INT(cast_f32_to_i8(0x1.0000000000000p+15f), 127LL);
    CHECK_EQ_UINT(cast_f32_to_u16(0x1.0000000000000p+15f), 32768ULL);
    CHECK_EQ_INT(cast_f32_to_i16(0x1.0000000000000p+15f), 32767LL);
    CHECK_EQ_UINT(cast_f32_to_u32(0x1.0000000000000p+15f), 32768ULL);
    CHECK_EQ_INT(cast_f32_to_i32(0x1.0000000000000p+15f), 32768LL);
    CHECK_EQ_UINT(cast_f32_to_u64(0x1.0000000000000p+15f), 32768ULL);
    CHECK_EQ_INT(cast_f32_to_i64(0x1.0000000000000p+15f), 32768LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(0x1.0000000000000p+15f), 32768ULL);
#endif
    CHECK(cast_f32_to_f32(0x1.0000000000000p+15f) == 0x1.0000000000000p+15f);
    CHECK(cast_f32_to_f64(0x1.0000000000000p+15f) == 0x1.0000000000000p+15);
    CHECK_EQ_UINT(cast_f32_to_u8(0x1.0001000000000p+15f), 255ULL);
    CHECK_EQ_INT(cast_f32_to_i8(0x1.0001000000000p+15f), 127LL);
    CHECK_EQ_UINT(cast_f32_to_u16(0x1.0001000000000p+15f), 32768ULL);
    CHECK_EQ_INT(cast_f32_to_i16(0x1.0001000000000p+15f), 32767LL);
    CHECK_EQ_UINT(cast_f32_to_u32(0x1.0001000000000p+15f), 32768ULL);
    CHECK_EQ_INT(cast_f32_to_i32(0x1.0001000000000p+15f), 32768LL);
    CHECK_EQ_UINT(cast_f32_to_u64(0x1.0001000000000p+15f), 32768ULL);
    CHECK_EQ_INT(cast_f32_to_i64(0x1.0001000000000p+15f), 32768LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(0x1.0001000000000p+15f), 32768ULL);
#endif
    CHECK(cast_f32_to_f32(0x1.0001000000000p+15f) == 0x1.0001000000000p+15f);
    CHECK(cast_f32_to_f64(0x1.0001000000000p+15f) == 0x1.0001000000000p+15);
    CHECK_EQ_UINT(cast_f32_to_u8(0x1.0000000000000p+32f), 255ULL);
    CHECK_EQ_INT(cast_f32_to_i8(0x1.0000000000000p+32f), 127LL);
    CHECK_EQ_UINT(cast_f32_to_u16(0x1.0000000000000p+32f), 65535ULL);
    CHECK_EQ_INT(cast_f32_to_i16(0x1.0000000000000p+32f), 32767LL);
    CHECK_EQ_UINT(cast_f32_to_u32(0x1.0000000000000p+32f), 4294967295ULL);
    CHECK_EQ_INT(cast_f32_to_i32(0x1.0000000000000p+32f), 2147483647LL);
    CHECK_EQ_UINT(cast_f32_to_u64(0x1.0000000000000p+32f), 4294967296ULL);
    CHECK_EQ_INT(cast_f32_to_i64(0x1.0000000000000p+32f), 4294967296LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(0x1.0000000000000p+32f), 4294967296ULL);
#endif
    CHECK(cast_f32_to_f32(0x1.0000000000000p+32f) == 0x1.0000000000000p+32f);
    CHECK(cast_f32_to_f64(0x1.0000000000000p+32f) == 0x1.0000000000000p+32);
    CHECK_EQ_UINT(cast_f32_to_u8(-0x1.0000000000000p+31f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i8(-0x1.0000000000000p+31f), (-128LL));
    CHECK_EQ_UINT(cast_f32_to_u16(-0x1.0000000000000p+31f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i16(-0x1.0000000000000p+31f), (-32768LL));
    CHECK_EQ_UINT(cast_f32_to_u32(-0x1.0000000000000p+31f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i32(-0x1.0000000000000p+31f), (-2147483648LL));
    CHECK_EQ_UINT(cast_f32_to_u64(-0x1.0000000000000p+31f), 0ULL);
    CHECK_EQ_INT(cast_f32_to_i64(-0x1.0000000000000p+31f), (-2147483648LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(-0x1.0000000000000p+31f), 0ULL);
#endif
    CHECK(cast_f32_to_f32(-0x1.0000000000000p+31f) == -0x1.0000000000000p+31f);
    CHECK(cast_f32_to_f64(-0x1.0000000000000p+31f) == -0x1.0000000000000p+31);
    CHECK_EQ_UINT(cast_f32_to_u8(0x1.0000000000000p+31f), 255ULL);
    CHECK_EQ_INT(cast_f32_to_i8(0x1.0000000000000p+31f), 127LL);
    CHECK_EQ_UINT(cast_f32_to_u16(0x1.0000000000000p+31f), 65535ULL);
    CHECK_EQ_INT(cast_f32_to_i16(0x1.0000000000000p+31f), 32767LL);
    CHECK_EQ_UINT(cast_f32_to_u32(0x1.0000000000000p+31f), 2147483648ULL);
    CHECK_EQ_INT(cast_f32_to_i32(0x1.0000000000000p+31f), 2147483647LL);
    CHECK_EQ_UINT(cast_f32_to_u64(0x1.0000000000000p+31f), 2147483648ULL);
    CHECK_EQ_INT(cast_f32_to_i64(0x1.0000000000000p+31f), 2147483648LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f32_to_size_t(0x1.0000000000000p+31f), 2147483648ULL);
#endif
    CHECK(cast_f32_to_f32(0x1.0000000000000p+31f) == 0x1.0000000000000p+31f);
    CHECK(cast_f32_to_f64(0x1.0000000000000p+31f) == 0x1.0000000000000p+31);
}

void test_numbers_cast_from_f64(HammerCtx *t)
{
    CHECK_EQ_UINT(cast_f64_to_u8((f64)NAN), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8((f64)NAN), 0LL);
    CHECK_EQ_UINT(cast_f64_to_u16((f64)NAN), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16((f64)NAN), 0LL);
    CHECK_EQ_UINT(cast_f64_to_u32((f64)NAN), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32((f64)NAN), 0LL);
    CHECK_EQ_UINT(cast_f64_to_u64((f64)NAN), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64((f64)NAN), 0LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t((f64)NAN), 0ULL);
#endif
    CHECK(isnan(cast_f64_to_f32((f64)NAN)));
    CHECK(isnan(cast_f64_to_f64((f64)NAN)));
    CHECK_EQ_UINT(cast_f64_to_u8((f64)INFINITY), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8((f64)INFINITY), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16((f64)INFINITY), 65535ULL);
    CHECK_EQ_INT(cast_f64_to_i16((f64)INFINITY), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u32((f64)INFINITY), 4294967295ULL);
    CHECK_EQ_INT(cast_f64_to_i32((f64)INFINITY), 2147483647LL);
    CHECK_EQ_UINT(cast_f64_to_u64((f64)INFINITY), 18446744073709551615ULL);
    CHECK_EQ_INT(cast_f64_to_i64((f64)INFINITY), 9223372036854775807LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t((f64)INFINITY), 18446744073709551615ULL);
#endif
    CHECK(cast_f64_to_f32((f64)INFINITY) == INFINITY);
    CHECK(cast_f64_to_f64((f64)INFINITY) == (f64)INFINITY);
    CHECK_EQ_UINT(cast_f64_to_u8((-(f64)INFINITY)), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8((-(f64)INFINITY)), (-128LL));
    CHECK_EQ_UINT(cast_f64_to_u16((-(f64)INFINITY)), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16((-(f64)INFINITY)), (-32768LL));
    CHECK_EQ_UINT(cast_f64_to_u32((-(f64)INFINITY)), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32((-(f64)INFINITY)), (-2147483648LL));
    CHECK_EQ_UINT(cast_f64_to_u64((-(f64)INFINITY)), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64((-(f64)INFINITY)), INT64_MIN);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t((-(f64)INFINITY)), 0ULL);
#endif
    CHECK(cast_f64_to_f32((-(f64)INFINITY)) == (-INFINITY));
    CHECK(cast_f64_to_f64((-(f64)INFINITY)) == (-(f64)INFINITY));
    CHECK_EQ_UINT(cast_f64_to_u8(0.0), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0.0), 0LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0.0), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0.0), 0LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0.0), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0.0), 0LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0.0), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0.0), 0LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0.0), 0ULL);
#endif
    CHECK(cast_f64_to_f32(0.0) == 0.0f);
    CHECK(!signbit(cast_f64_to_f32(0.0)));
    CHECK(cast_f64_to_f64(0.0) == 0.0);
    CHECK(!signbit(cast_f64_to_f64(0.0)));
    CHECK_EQ_UINT(cast_f64_to_u8((-0.0)), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8((-0.0)), 0LL);
    CHECK_EQ_UINT(cast_f64_to_u16((-0.0)), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16((-0.0)), 0LL);
    CHECK_EQ_UINT(cast_f64_to_u32((-0.0)), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32((-0.0)), 0LL);
    CHECK_EQ_UINT(cast_f64_to_u64((-0.0)), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64((-0.0)), 0LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t((-0.0)), 0ULL);
#endif
    CHECK(cast_f64_to_f32((-0.0)) == (-0.0f));
    CHECK(signbit(cast_f64_to_f32((-0.0))));
    CHECK(cast_f64_to_f64((-0.0)) == (-0.0));
    CHECK(signbit(cast_f64_to_f64((-0.0))));
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.0000000000000p-1), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.0000000000000p-1), 0LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.0000000000000p-1), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.0000000000000p-1), 0LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.0000000000000p-1), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.0000000000000p-1), 0LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.0000000000000p-1), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.0000000000000p-1), 0LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.0000000000000p-1), 0ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.0000000000000p-1) == 0x1.0000000000000p-1f);
    CHECK(cast_f64_to_f64(0x1.0000000000000p-1) == 0x1.0000000000000p-1);
    CHECK_EQ_UINT(cast_f64_to_u8(-0x1.0000000000000p-1), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(-0x1.0000000000000p-1), 0LL);
    CHECK_EQ_UINT(cast_f64_to_u16(-0x1.0000000000000p-1), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(-0x1.0000000000000p-1), 0LL);
    CHECK_EQ_UINT(cast_f64_to_u32(-0x1.0000000000000p-1), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(-0x1.0000000000000p-1), 0LL);
    CHECK_EQ_UINT(cast_f64_to_u64(-0x1.0000000000000p-1), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(-0x1.0000000000000p-1), 0LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(-0x1.0000000000000p-1), 0ULL);
#endif
    CHECK(cast_f64_to_f32(-0x1.0000000000000p-1) == -0x1.0000000000000p-1f);
    CHECK(cast_f64_to_f64(-0x1.0000000000000p-1) == -0x1.0000000000000p-1);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.ccccccccccccdp-1), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.ccccccccccccdp-1), 0LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.ccccccccccccdp-1), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.ccccccccccccdp-1), 0LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.ccccccccccccdp-1), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.ccccccccccccdp-1), 0LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.ccccccccccccdp-1), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.ccccccccccccdp-1), 0LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.ccccccccccccdp-1), 0ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.ccccccccccccdp-1) == 0x1.cccccc0000000p-1f);
    CHECK(cast_f64_to_f64(0x1.ccccccccccccdp-1) == 0x1.ccccccccccccdp-1);
    CHECK_EQ_UINT(cast_f64_to_u8(-0x1.ccccccccccccdp-1), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(-0x1.ccccccccccccdp-1), 0LL);
    CHECK_EQ_UINT(cast_f64_to_u16(-0x1.ccccccccccccdp-1), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(-0x1.ccccccccccccdp-1), 0LL);
    CHECK_EQ_UINT(cast_f64_to_u32(-0x1.ccccccccccccdp-1), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(-0x1.ccccccccccccdp-1), 0LL);
    CHECK_EQ_UINT(cast_f64_to_u64(-0x1.ccccccccccccdp-1), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(-0x1.ccccccccccccdp-1), 0LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(-0x1.ccccccccccccdp-1), 0ULL);
#endif
    CHECK(cast_f64_to_f32(-0x1.ccccccccccccdp-1) == -0x1.cccccc0000000p-1f);
    CHECK(cast_f64_to_f64(-0x1.ccccccccccccdp-1) == -0x1.ccccccccccccdp-1);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.0000000000000p+0), 1ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.0000000000000p+0), 1LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.0000000000000p+0), 1ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.0000000000000p+0), 1LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.0000000000000p+0), 1ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.0000000000000p+0), 1LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.0000000000000p+0), 1ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.0000000000000p+0), 1LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.0000000000000p+0), 1ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.0000000000000p+0) == 0x1.0000000000000p+0f);
    CHECK(cast_f64_to_f64(0x1.0000000000000p+0) == 0x1.0000000000000p+0);
    CHECK_EQ_UINT(cast_f64_to_u8(-0x1.0000000000000p+0), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(-0x1.0000000000000p+0), (-1LL));
    CHECK_EQ_UINT(cast_f64_to_u16(-0x1.0000000000000p+0), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(-0x1.0000000000000p+0), (-1LL));
    CHECK_EQ_UINT(cast_f64_to_u32(-0x1.0000000000000p+0), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(-0x1.0000000000000p+0), (-1LL));
    CHECK_EQ_UINT(cast_f64_to_u64(-0x1.0000000000000p+0), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(-0x1.0000000000000p+0), (-1LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(-0x1.0000000000000p+0), 0ULL);
#endif
    CHECK(cast_f64_to_f32(-0x1.0000000000000p+0) == -0x1.0000000000000p+0f);
    CHECK(cast_f64_to_f64(-0x1.0000000000000p+0) == -0x1.0000000000000p+0);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.7333333333333p+1), 2ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.7333333333333p+1), 2LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.7333333333333p+1), 2ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.7333333333333p+1), 2LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.7333333333333p+1), 2ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.7333333333333p+1), 2LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.7333333333333p+1), 2ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.7333333333333p+1), 2LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.7333333333333p+1), 2ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.7333333333333p+1) == 0x1.7333340000000p+1f);
    CHECK(cast_f64_to_f64(0x1.7333333333333p+1) == 0x1.7333333333333p+1);
    CHECK_EQ_UINT(cast_f64_to_u8(-0x1.7333333333333p+1), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(-0x1.7333333333333p+1), (-2LL));
    CHECK_EQ_UINT(cast_f64_to_u16(-0x1.7333333333333p+1), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(-0x1.7333333333333p+1), (-2LL));
    CHECK_EQ_UINT(cast_f64_to_u32(-0x1.7333333333333p+1), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(-0x1.7333333333333p+1), (-2LL));
    CHECK_EQ_UINT(cast_f64_to_u64(-0x1.7333333333333p+1), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(-0x1.7333333333333p+1), (-2LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(-0x1.7333333333333p+1), 0ULL);
#endif
    CHECK(cast_f64_to_f32(-0x1.7333333333333p+1) == -0x1.7333340000000p+1f);
    CHECK(cast_f64_to_f64(-0x1.7333333333333p+1) == -0x1.7333333333333p+1);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.0000000000000p+63), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.0000000000000p+63), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.0000000000000p+63), 65535ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.0000000000000p+63), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.0000000000000p+63), 4294967295ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.0000000000000p+63), 2147483647LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.0000000000000p+63), 9223372036854775808ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.0000000000000p+63), 9223372036854775807LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.0000000000000p+63), 9223372036854775808ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.0000000000000p+63) == 0x1.0000000000000p+63f);
    CHECK(cast_f64_to_f64(0x1.0000000000000p+63) == 0x1.0000000000000p+63);
    CHECK_EQ_UINT(cast_f64_to_u8(-0x1.0000000000000p+63), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(-0x1.0000000000000p+63), (-128LL));
    CHECK_EQ_UINT(cast_f64_to_u16(-0x1.0000000000000p+63), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(-0x1.0000000000000p+63), (-32768LL));
    CHECK_EQ_UINT(cast_f64_to_u32(-0x1.0000000000000p+63), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(-0x1.0000000000000p+63), (-2147483648LL));
    CHECK_EQ_UINT(cast_f64_to_u64(-0x1.0000000000000p+63), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(-0x1.0000000000000p+63), INT64_MIN);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(-0x1.0000000000000p+63), 0ULL);
#endif
    CHECK(cast_f64_to_f32(-0x1.0000000000000p+63) == -0x1.0000000000000p+63f);
    CHECK(cast_f64_to_f64(-0x1.0000000000000p+63) == -0x1.0000000000000p+63);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.0000000000000p+64), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.0000000000000p+64), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.0000000000000p+64), 65535ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.0000000000000p+64), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.0000000000000p+64), 4294967295ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.0000000000000p+64), 2147483647LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.0000000000000p+64), 18446744073709551615ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.0000000000000p+64), 9223372036854775807LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.0000000000000p+64), 18446744073709551615ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.0000000000000p+64) == 0x1.0000000000000p+64f);
    CHECK(cast_f64_to_f64(0x1.0000000000000p+64) == 0x1.0000000000000p+64);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.8000000000000p+63), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.8000000000000p+63), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.8000000000000p+63), 65535ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.8000000000000p+63), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.8000000000000p+63), 4294967295ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.8000000000000p+63), 2147483647LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.8000000000000p+63), 13835058055282163712ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.8000000000000p+63), 9223372036854775807LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.8000000000000p+63), 13835058055282163712ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.8000000000000p+63) == 0x1.8000000000000p+63f);
    CHECK(cast_f64_to_f64(0x1.8000000000000p+63) == 0x1.8000000000000p+63);
    CHECK_EQ_UINT(cast_f64_to_u8(-0x1.0000000000000p+64), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(-0x1.0000000000000p+64), (-128LL));
    CHECK_EQ_UINT(cast_f64_to_u16(-0x1.0000000000000p+64), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(-0x1.0000000000000p+64), (-32768LL));
    CHECK_EQ_UINT(cast_f64_to_u32(-0x1.0000000000000p+64), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(-0x1.0000000000000p+64), (-2147483648LL));
    CHECK_EQ_UINT(cast_f64_to_u64(-0x1.0000000000000p+64), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(-0x1.0000000000000p+64), INT64_MIN);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(-0x1.0000000000000p+64), 0ULL);
#endif
    CHECK(cast_f64_to_f32(-0x1.0000000000000p+64) == -0x1.0000000000000p+64f);
    CHECK(cast_f64_to_f64(-0x1.0000000000000p+64) == -0x1.0000000000000p+64);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.fffffe0000000p+127), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.fffffe0000000p+127), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.fffffe0000000p+127), 65535ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.fffffe0000000p+127), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.fffffe0000000p+127), 4294967295ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.fffffe0000000p+127), 2147483647LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.fffffe0000000p+127), 18446744073709551615ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.fffffe0000000p+127), 9223372036854775807LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.fffffe0000000p+127), 18446744073709551615ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.fffffe0000000p+127) == 0x1.fffffe0000000p+127f);
    CHECK(cast_f64_to_f64(0x1.fffffe0000000p+127) == 0x1.fffffe0000000p+127);
    CHECK_EQ_UINT(cast_f64_to_u8(-0x1.fffffe0000000p+127), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(-0x1.fffffe0000000p+127), (-128LL));
    CHECK_EQ_UINT(cast_f64_to_u16(-0x1.fffffe0000000p+127), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(-0x1.fffffe0000000p+127), (-32768LL));
    CHECK_EQ_UINT(cast_f64_to_u32(-0x1.fffffe0000000p+127), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(-0x1.fffffe0000000p+127), (-2147483648LL));
    CHECK_EQ_UINT(cast_f64_to_u64(-0x1.fffffe0000000p+127), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(-0x1.fffffe0000000p+127), INT64_MIN);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(-0x1.fffffe0000000p+127), 0ULL);
#endif
    CHECK(cast_f64_to_f32(-0x1.fffffe0000000p+127) == -0x1.fffffe0000000p+127f);
    CHECK(cast_f64_to_f64(-0x1.fffffe0000000p+127) == -0x1.fffffe0000000p+127);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.7e43c8800759cp+996), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.7e43c8800759cp+996), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.7e43c8800759cp+996), 65535ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.7e43c8800759cp+996), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.7e43c8800759cp+996), 4294967295ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.7e43c8800759cp+996), 2147483647LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.7e43c8800759cp+996), 18446744073709551615ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.7e43c8800759cp+996), 9223372036854775807LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.7e43c8800759cp+996), 18446744073709551615ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.7e43c8800759cp+996) == 0x1.fffffe0000000p+127f);
    CHECK(cast_f64_to_f64(0x1.7e43c8800759cp+996) == 0x1.7e43c8800759cp+996);
    CHECK_EQ_UINT(cast_f64_to_u8(-0x1.7e43c8800759cp+996), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(-0x1.7e43c8800759cp+996), (-128LL));
    CHECK_EQ_UINT(cast_f64_to_u16(-0x1.7e43c8800759cp+996), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(-0x1.7e43c8800759cp+996), (-32768LL));
    CHECK_EQ_UINT(cast_f64_to_u32(-0x1.7e43c8800759cp+996), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(-0x1.7e43c8800759cp+996), (-2147483648LL));
    CHECK_EQ_UINT(cast_f64_to_u64(-0x1.7e43c8800759cp+996), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(-0x1.7e43c8800759cp+996), INT64_MIN);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(-0x1.7e43c8800759cp+996), 0ULL);
#endif
    CHECK(cast_f64_to_f32(-0x1.7e43c8800759cp+996) == -0x1.fffffe0000000p+127f);
    CHECK(cast_f64_to_f64(-0x1.7e43c8800759cp+996) == -0x1.7e43c8800759cp+996);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.074f8c4d3cd7bp+128), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.074f8c4d3cd7bp+128), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.074f8c4d3cd7bp+128), 65535ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.074f8c4d3cd7bp+128), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.074f8c4d3cd7bp+128), 4294967295ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.074f8c4d3cd7bp+128), 2147483647LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.074f8c4d3cd7bp+128), 18446744073709551615ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.074f8c4d3cd7bp+128), 9223372036854775807LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.074f8c4d3cd7bp+128), 18446744073709551615ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.074f8c4d3cd7bp+128) == 0x1.fffffe0000000p+127f);
    CHECK(cast_f64_to_f64(0x1.074f8c4d3cd7bp+128) == 0x1.074f8c4d3cd7bp+128);
    CHECK_EQ_UINT(cast_f64_to_u8(-0x1.074f8c4d3cd7bp+128), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(-0x1.074f8c4d3cd7bp+128), (-128LL));
    CHECK_EQ_UINT(cast_f64_to_u16(-0x1.074f8c4d3cd7bp+128), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(-0x1.074f8c4d3cd7bp+128), (-32768LL));
    CHECK_EQ_UINT(cast_f64_to_u32(-0x1.074f8c4d3cd7bp+128), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(-0x1.074f8c4d3cd7bp+128), (-2147483648LL));
    CHECK_EQ_UINT(cast_f64_to_u64(-0x1.074f8c4d3cd7bp+128), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(-0x1.074f8c4d3cd7bp+128), INT64_MIN);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(-0x1.074f8c4d3cd7bp+128), 0ULL);
#endif
    CHECK(cast_f64_to_f32(-0x1.074f8c4d3cd7bp+128) == -0x1.fffffe0000000p+127f);
    CHECK(cast_f64_to_f64(-0x1.074f8c4d3cd7bp+128) == -0x1.074f8c4d3cd7bp+128);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.fffffffffffffp+1023), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.fffffffffffffp+1023), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.fffffffffffffp+1023), 65535ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.fffffffffffffp+1023), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.fffffffffffffp+1023), 4294967295ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.fffffffffffffp+1023), 2147483647LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.fffffffffffffp+1023), 18446744073709551615ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.fffffffffffffp+1023), 9223372036854775807LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.fffffffffffffp+1023), 18446744073709551615ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.fffffffffffffp+1023) == 0x1.fffffe0000000p+127f);
    CHECK(cast_f64_to_f64(0x1.fffffffffffffp+1023) == 0x1.fffffffffffffp+1023);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.6d601ad376ab9p-150), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.6d601ad376ab9p-150), 0LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.6d601ad376ab9p-150), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.6d601ad376ab9p-150), 0LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.6d601ad376ab9p-150), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.6d601ad376ab9p-150), 0LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.6d601ad376ab9p-150), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.6d601ad376ab9p-150), 0LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.6d601ad376ab9p-150), 0ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.6d601ad376ab9p-150) == 0x1.0000000000000p-149f);
    CHECK(cast_f64_to_f64(0x1.6d601ad376ab9p-150) == 0x1.6d601ad376ab9p-150);
    CHECK_EQ_UINT(cast_f64_to_u8(0x0.00000000007e8p-1022), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x0.00000000007e8p-1022), 0LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x0.00000000007e8p-1022), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x0.00000000007e8p-1022), 0LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x0.00000000007e8p-1022), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x0.00000000007e8p-1022), 0LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x0.00000000007e8p-1022), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x0.00000000007e8p-1022), 0LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x0.00000000007e8p-1022), 0ULL);
#endif
    CHECK(cast_f64_to_f32(0x0.00000000007e8p-1022) == 0.0f);
    CHECK(!signbit(cast_f64_to_f32(0x0.00000000007e8p-1022)));
    CHECK(cast_f64_to_f64(0x0.00000000007e8p-1022) == 0x0.00000000007e8p-1022);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.999999999999ap-4), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.999999999999ap-4), 0LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.999999999999ap-4), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.999999999999ap-4), 0LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.999999999999ap-4), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.999999999999ap-4), 0LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.999999999999ap-4), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.999999999999ap-4), 0LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.999999999999ap-4), 0ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.999999999999ap-4) == 0x1.99999a0000000p-4f);
    CHECK(cast_f64_to_f64(0x1.999999999999ap-4) == 0x1.999999999999ap-4);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.fe00000000000p+7), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.fe00000000000p+7), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.fe00000000000p+7), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.fe00000000000p+7), 255LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.fe00000000000p+7), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.fe00000000000p+7), 255LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.fe00000000000p+7), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.fe00000000000p+7), 255LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.fe00000000000p+7), 255ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.fe00000000000p+7) == 0x1.fe00000000000p+7f);
    CHECK(cast_f64_to_f64(0x1.fe00000000000p+7) == 0x1.fe00000000000p+7);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.ff00000000000p+7), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.ff00000000000p+7), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.ff00000000000p+7), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.ff00000000000p+7), 255LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.ff00000000000p+7), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.ff00000000000p+7), 255LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.ff00000000000p+7), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.ff00000000000p+7), 255LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.ff00000000000p+7), 255ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.ff00000000000p+7) == 0x1.ff00000000000p+7f);
    CHECK(cast_f64_to_f64(0x1.ff00000000000p+7) == 0x1.ff00000000000p+7);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.fd00000000000p+7), 254ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.fd00000000000p+7), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.fd00000000000p+7), 254ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.fd00000000000p+7), 254LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.fd00000000000p+7), 254ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.fd00000000000p+7), 254LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.fd00000000000p+7), 254ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.fd00000000000p+7), 254LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.fd00000000000p+7), 254ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.fd00000000000p+7) == 0x1.fd00000000000p+7f);
    CHECK(cast_f64_to_f64(0x1.fd00000000000p+7) == 0x1.fd00000000000p+7);
    CHECK_EQ_UINT(cast_f64_to_u8(-0x1.8000000000000p+0), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(-0x1.8000000000000p+0), (-1LL));
    CHECK_EQ_UINT(cast_f64_to_u16(-0x1.8000000000000p+0), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(-0x1.8000000000000p+0), (-1LL));
    CHECK_EQ_UINT(cast_f64_to_u32(-0x1.8000000000000p+0), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(-0x1.8000000000000p+0), (-1LL));
    CHECK_EQ_UINT(cast_f64_to_u64(-0x1.8000000000000p+0), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(-0x1.8000000000000p+0), (-1LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(-0x1.8000000000000p+0), 0ULL);
#endif
    CHECK(cast_f64_to_f32(-0x1.8000000000000p+0) == -0x1.8000000000000p+0f);
    CHECK(cast_f64_to_f64(-0x1.8000000000000p+0) == -0x1.8000000000000p+0);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.0000000000000p+8), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.0000000000000p+8), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.0000000000000p+8), 256ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.0000000000000p+8), 256LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.0000000000000p+8), 256ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.0000000000000p+8), 256LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.0000000000000p+8), 256ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.0000000000000p+8), 256LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.0000000000000p+8), 256ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.0000000000000p+8) == 0x1.0000000000000p+8f);
    CHECK(cast_f64_to_f64(0x1.0000000000000p+8) == 0x1.0000000000000p+8);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.0080000000000p+8), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.0080000000000p+8), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.0080000000000p+8), 256ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.0080000000000p+8), 256LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.0080000000000p+8), 256ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.0080000000000p+8), 256LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.0080000000000p+8), 256ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.0080000000000p+8), 256LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.0080000000000p+8), 256ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.0080000000000p+8) == 0x1.0080000000000p+8f);
    CHECK(cast_f64_to_f64(0x1.0080000000000p+8) == 0x1.0080000000000p+8);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.fffffffffffffp+7), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.fffffffffffffp+7), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.fffffffffffffp+7), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.fffffffffffffp+7), 255LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.fffffffffffffp+7), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.fffffffffffffp+7), 255LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.fffffffffffffp+7), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.fffffffffffffp+7), 255LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.fffffffffffffp+7), 255ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.fffffffffffffp+7) == 0x1.0000000000000p+8f);
    CHECK(cast_f64_to_f64(0x1.fffffffffffffp+7) == 0x1.fffffffffffffp+7);
    CHECK_EQ_UINT(cast_f64_to_u8(-0x0.0000000000001p-1022), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(-0x0.0000000000001p-1022), 0LL);
    CHECK_EQ_UINT(cast_f64_to_u16(-0x0.0000000000001p-1022), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(-0x0.0000000000001p-1022), 0LL);
    CHECK_EQ_UINT(cast_f64_to_u32(-0x0.0000000000001p-1022), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(-0x0.0000000000001p-1022), 0LL);
    CHECK_EQ_UINT(cast_f64_to_u64(-0x0.0000000000001p-1022), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(-0x0.0000000000001p-1022), 0LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(-0x0.0000000000001p-1022), 0ULL);
#endif
    CHECK(cast_f64_to_f32(-0x0.0000000000001p-1022) == (-0.0f));
    CHECK(signbit(cast_f64_to_f32(-0x0.0000000000001p-1022)));
    CHECK(cast_f64_to_f64(-0x0.0000000000001p-1022) == -0x0.0000000000001p-1022);
    CHECK_EQ_UINT(cast_f64_to_u8(-0x1.0000000000000p+7), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(-0x1.0000000000000p+7), (-128LL));
    CHECK_EQ_UINT(cast_f64_to_u16(-0x1.0000000000000p+7), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(-0x1.0000000000000p+7), (-128LL));
    CHECK_EQ_UINT(cast_f64_to_u32(-0x1.0000000000000p+7), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(-0x1.0000000000000p+7), (-128LL));
    CHECK_EQ_UINT(cast_f64_to_u64(-0x1.0000000000000p+7), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(-0x1.0000000000000p+7), (-128LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(-0x1.0000000000000p+7), 0ULL);
#endif
    CHECK(cast_f64_to_f32(-0x1.0000000000000p+7) == -0x1.0000000000000p+7f);
    CHECK(cast_f64_to_f64(-0x1.0000000000000p+7) == -0x1.0000000000000p+7);
    CHECK_EQ_UINT(cast_f64_to_u8(-0x1.fe00000000000p+6), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(-0x1.fe00000000000p+6), (-127LL));
    CHECK_EQ_UINT(cast_f64_to_u16(-0x1.fe00000000000p+6), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(-0x1.fe00000000000p+6), (-127LL));
    CHECK_EQ_UINT(cast_f64_to_u32(-0x1.fe00000000000p+6), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(-0x1.fe00000000000p+6), (-127LL));
    CHECK_EQ_UINT(cast_f64_to_u64(-0x1.fe00000000000p+6), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(-0x1.fe00000000000p+6), (-127LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(-0x1.fe00000000000p+6), 0ULL);
#endif
    CHECK(cast_f64_to_f32(-0x1.fe00000000000p+6) == -0x1.fe00000000000p+6f);
    CHECK(cast_f64_to_f64(-0x1.fe00000000000p+6) == -0x1.fe00000000000p+6);
    CHECK_EQ_UINT(cast_f64_to_u8(-0x1.0100000000000p+7), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(-0x1.0100000000000p+7), (-128LL));
    CHECK_EQ_UINT(cast_f64_to_u16(-0x1.0100000000000p+7), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(-0x1.0100000000000p+7), (-128LL));
    CHECK_EQ_UINT(cast_f64_to_u32(-0x1.0100000000000p+7), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(-0x1.0100000000000p+7), (-128LL));
    CHECK_EQ_UINT(cast_f64_to_u64(-0x1.0100000000000p+7), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(-0x1.0100000000000p+7), (-128LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(-0x1.0100000000000p+7), 0ULL);
#endif
    CHECK(cast_f64_to_f32(-0x1.0100000000000p+7) == -0x1.0100000000000p+7f);
    CHECK(cast_f64_to_f64(-0x1.0100000000000p+7) == -0x1.0100000000000p+7);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.fc00000000000p+6), 127ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.fc00000000000p+6), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.fc00000000000p+6), 127ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.fc00000000000p+6), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.fc00000000000p+6), 127ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.fc00000000000p+6), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.fc00000000000p+6), 127ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.fc00000000000p+6), 127LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.fc00000000000p+6), 127ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.fc00000000000p+6) == 0x1.fc00000000000p+6f);
    CHECK(cast_f64_to_f64(0x1.fc00000000000p+6) == 0x1.fc00000000000p+6);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.fe00000000000p+6), 127ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.fe00000000000p+6), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.fe00000000000p+6), 127ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.fe00000000000p+6), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.fe00000000000p+6), 127ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.fe00000000000p+6), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.fe00000000000p+6), 127ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.fe00000000000p+6), 127LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.fe00000000000p+6), 127ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.fe00000000000p+6) == 0x1.fe00000000000p+6f);
    CHECK(cast_f64_to_f64(0x1.fe00000000000p+6) == 0x1.fe00000000000p+6);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.fa00000000000p+6), 126ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.fa00000000000p+6), 126LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.fa00000000000p+6), 126ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.fa00000000000p+6), 126LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.fa00000000000p+6), 126ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.fa00000000000p+6), 126LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.fa00000000000p+6), 126ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.fa00000000000p+6), 126LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.fa00000000000p+6), 126ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.fa00000000000p+6) == 0x1.fa00000000000p+6f);
    CHECK(cast_f64_to_f64(0x1.fa00000000000p+6) == 0x1.fa00000000000p+6);
    CHECK_EQ_UINT(cast_f64_to_u8(-0x1.0200000000000p+7), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(-0x1.0200000000000p+7), (-128LL));
    CHECK_EQ_UINT(cast_f64_to_u16(-0x1.0200000000000p+7), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(-0x1.0200000000000p+7), (-129LL));
    CHECK_EQ_UINT(cast_f64_to_u32(-0x1.0200000000000p+7), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(-0x1.0200000000000p+7), (-129LL));
    CHECK_EQ_UINT(cast_f64_to_u64(-0x1.0200000000000p+7), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(-0x1.0200000000000p+7), (-129LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(-0x1.0200000000000p+7), 0ULL);
#endif
    CHECK(cast_f64_to_f32(-0x1.0200000000000p+7) == -0x1.0200000000000p+7f);
    CHECK(cast_f64_to_f64(-0x1.0200000000000p+7) == -0x1.0200000000000p+7);
    CHECK_EQ_UINT(cast_f64_to_u8(-0x1.0300000000000p+7), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(-0x1.0300000000000p+7), (-128LL));
    CHECK_EQ_UINT(cast_f64_to_u16(-0x1.0300000000000p+7), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(-0x1.0300000000000p+7), (-129LL));
    CHECK_EQ_UINT(cast_f64_to_u32(-0x1.0300000000000p+7), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(-0x1.0300000000000p+7), (-129LL));
    CHECK_EQ_UINT(cast_f64_to_u64(-0x1.0300000000000p+7), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(-0x1.0300000000000p+7), (-129LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(-0x1.0300000000000p+7), 0ULL);
#endif
    CHECK(cast_f64_to_f32(-0x1.0300000000000p+7) == -0x1.0300000000000p+7f);
    CHECK(cast_f64_to_f64(-0x1.0300000000000p+7) == -0x1.0300000000000p+7);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.0000000000000p+7), 128ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.0000000000000p+7), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.0000000000000p+7), 128ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.0000000000000p+7), 128LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.0000000000000p+7), 128ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.0000000000000p+7), 128LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.0000000000000p+7), 128ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.0000000000000p+7), 128LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.0000000000000p+7), 128ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.0000000000000p+7) == 0x1.0000000000000p+7f);
    CHECK(cast_f64_to_f64(0x1.0000000000000p+7) == 0x1.0000000000000p+7);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.0100000000000p+7), 128ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.0100000000000p+7), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.0100000000000p+7), 128ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.0100000000000p+7), 128LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.0100000000000p+7), 128ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.0100000000000p+7), 128LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.0100000000000p+7), 128ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.0100000000000p+7), 128LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.0100000000000p+7), 128ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.0100000000000p+7) == 0x1.0100000000000p+7f);
    CHECK(cast_f64_to_f64(0x1.0100000000000p+7) == 0x1.0100000000000p+7);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.fffffffffffffp+6), 127ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.fffffffffffffp+6), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.fffffffffffffp+6), 127ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.fffffffffffffp+6), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.fffffffffffffp+6), 127ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.fffffffffffffp+6), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.fffffffffffffp+6), 127ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.fffffffffffffp+6), 127LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.fffffffffffffp+6), 127ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.fffffffffffffp+6) == 0x1.0000000000000p+7f);
    CHECK(cast_f64_to_f64(0x1.fffffffffffffp+6) == 0x1.fffffffffffffp+6);
    CHECK_EQ_UINT(cast_f64_to_u8(-0x1.0000000000001p+7), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(-0x1.0000000000001p+7), (-128LL));
    CHECK_EQ_UINT(cast_f64_to_u16(-0x1.0000000000001p+7), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(-0x1.0000000000001p+7), (-128LL));
    CHECK_EQ_UINT(cast_f64_to_u32(-0x1.0000000000001p+7), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(-0x1.0000000000001p+7), (-128LL));
    CHECK_EQ_UINT(cast_f64_to_u64(-0x1.0000000000001p+7), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(-0x1.0000000000001p+7), (-128LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(-0x1.0000000000001p+7), 0ULL);
#endif
    CHECK(cast_f64_to_f32(-0x1.0000000000001p+7) == -0x1.0000000000000p+7f);
    CHECK(cast_f64_to_f64(-0x1.0000000000001p+7) == -0x1.0000000000001p+7);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.fffe000000000p+15), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.fffe000000000p+15), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.fffe000000000p+15), 65535ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.fffe000000000p+15), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.fffe000000000p+15), 65535ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.fffe000000000p+15), 65535LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.fffe000000000p+15), 65535ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.fffe000000000p+15), 65535LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.fffe000000000p+15), 65535ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.fffe000000000p+15) == 0x1.fffe000000000p+15f);
    CHECK(cast_f64_to_f64(0x1.fffe000000000p+15) == 0x1.fffe000000000p+15);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.ffff000000000p+15), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.ffff000000000p+15), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.ffff000000000p+15), 65535ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.ffff000000000p+15), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.ffff000000000p+15), 65535ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.ffff000000000p+15), 65535LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.ffff000000000p+15), 65535ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.ffff000000000p+15), 65535LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.ffff000000000p+15), 65535ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.ffff000000000p+15) == 0x1.ffff000000000p+15f);
    CHECK(cast_f64_to_f64(0x1.ffff000000000p+15) == 0x1.ffff000000000p+15);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.fffd000000000p+15), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.fffd000000000p+15), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.fffd000000000p+15), 65534ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.fffd000000000p+15), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.fffd000000000p+15), 65534ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.fffd000000000p+15), 65534LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.fffd000000000p+15), 65534ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.fffd000000000p+15), 65534LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.fffd000000000p+15), 65534ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.fffd000000000p+15) == 0x1.fffd000000000p+15f);
    CHECK(cast_f64_to_f64(0x1.fffd000000000p+15) == 0x1.fffd000000000p+15);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.0000000000000p+16), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.0000000000000p+16), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.0000000000000p+16), 65535ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.0000000000000p+16), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.0000000000000p+16), 65536ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.0000000000000p+16), 65536LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.0000000000000p+16), 65536ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.0000000000000p+16), 65536LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.0000000000000p+16), 65536ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.0000000000000p+16) == 0x1.0000000000000p+16f);
    CHECK(cast_f64_to_f64(0x1.0000000000000p+16) == 0x1.0000000000000p+16);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.0000800000000p+16), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.0000800000000p+16), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.0000800000000p+16), 65535ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.0000800000000p+16), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.0000800000000p+16), 65536ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.0000800000000p+16), 65536LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.0000800000000p+16), 65536ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.0000800000000p+16), 65536LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.0000800000000p+16), 65536ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.0000800000000p+16) == 0x1.0000800000000p+16f);
    CHECK(cast_f64_to_f64(0x1.0000800000000p+16) == 0x1.0000800000000p+16);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.fffffffffffffp+15), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.fffffffffffffp+15), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.fffffffffffffp+15), 65535ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.fffffffffffffp+15), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.fffffffffffffp+15), 65535ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.fffffffffffffp+15), 65535LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.fffffffffffffp+15), 65535ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.fffffffffffffp+15), 65535LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.fffffffffffffp+15), 65535ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.fffffffffffffp+15) == 0x1.0000000000000p+16f);
    CHECK(cast_f64_to_f64(0x1.fffffffffffffp+15) == 0x1.fffffffffffffp+15);
    CHECK_EQ_UINT(cast_f64_to_u8(-0x1.0000000000000p+15), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(-0x1.0000000000000p+15), (-128LL));
    CHECK_EQ_UINT(cast_f64_to_u16(-0x1.0000000000000p+15), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(-0x1.0000000000000p+15), (-32768LL));
    CHECK_EQ_UINT(cast_f64_to_u32(-0x1.0000000000000p+15), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(-0x1.0000000000000p+15), (-32768LL));
    CHECK_EQ_UINT(cast_f64_to_u64(-0x1.0000000000000p+15), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(-0x1.0000000000000p+15), (-32768LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(-0x1.0000000000000p+15), 0ULL);
#endif
    CHECK(cast_f64_to_f32(-0x1.0000000000000p+15) == -0x1.0000000000000p+15f);
    CHECK(cast_f64_to_f64(-0x1.0000000000000p+15) == -0x1.0000000000000p+15);
    CHECK_EQ_UINT(cast_f64_to_u8(-0x1.fffe000000000p+14), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(-0x1.fffe000000000p+14), (-128LL));
    CHECK_EQ_UINT(cast_f64_to_u16(-0x1.fffe000000000p+14), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(-0x1.fffe000000000p+14), (-32767LL));
    CHECK_EQ_UINT(cast_f64_to_u32(-0x1.fffe000000000p+14), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(-0x1.fffe000000000p+14), (-32767LL));
    CHECK_EQ_UINT(cast_f64_to_u64(-0x1.fffe000000000p+14), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(-0x1.fffe000000000p+14), (-32767LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(-0x1.fffe000000000p+14), 0ULL);
#endif
    CHECK(cast_f64_to_f32(-0x1.fffe000000000p+14) == -0x1.fffe000000000p+14f);
    CHECK(cast_f64_to_f64(-0x1.fffe000000000p+14) == -0x1.fffe000000000p+14);
    CHECK_EQ_UINT(cast_f64_to_u8(-0x1.0001000000000p+15), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(-0x1.0001000000000p+15), (-128LL));
    CHECK_EQ_UINT(cast_f64_to_u16(-0x1.0001000000000p+15), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(-0x1.0001000000000p+15), (-32768LL));
    CHECK_EQ_UINT(cast_f64_to_u32(-0x1.0001000000000p+15), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(-0x1.0001000000000p+15), (-32768LL));
    CHECK_EQ_UINT(cast_f64_to_u64(-0x1.0001000000000p+15), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(-0x1.0001000000000p+15), (-32768LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(-0x1.0001000000000p+15), 0ULL);
#endif
    CHECK(cast_f64_to_f32(-0x1.0001000000000p+15) == -0x1.0001000000000p+15f);
    CHECK(cast_f64_to_f64(-0x1.0001000000000p+15) == -0x1.0001000000000p+15);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.fffc000000000p+14), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.fffc000000000p+14), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.fffc000000000p+14), 32767ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.fffc000000000p+14), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.fffc000000000p+14), 32767ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.fffc000000000p+14), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.fffc000000000p+14), 32767ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.fffc000000000p+14), 32767LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.fffc000000000p+14), 32767ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.fffc000000000p+14) == 0x1.fffc000000000p+14f);
    CHECK(cast_f64_to_f64(0x1.fffc000000000p+14) == 0x1.fffc000000000p+14);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.fffe000000000p+14), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.fffe000000000p+14), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.fffe000000000p+14), 32767ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.fffe000000000p+14), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.fffe000000000p+14), 32767ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.fffe000000000p+14), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.fffe000000000p+14), 32767ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.fffe000000000p+14), 32767LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.fffe000000000p+14), 32767ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.fffe000000000p+14) == 0x1.fffe000000000p+14f);
    CHECK(cast_f64_to_f64(0x1.fffe000000000p+14) == 0x1.fffe000000000p+14);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.fffa000000000p+14), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.fffa000000000p+14), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.fffa000000000p+14), 32766ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.fffa000000000p+14), 32766LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.fffa000000000p+14), 32766ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.fffa000000000p+14), 32766LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.fffa000000000p+14), 32766ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.fffa000000000p+14), 32766LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.fffa000000000p+14), 32766ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.fffa000000000p+14) == 0x1.fffa000000000p+14f);
    CHECK(cast_f64_to_f64(0x1.fffa000000000p+14) == 0x1.fffa000000000p+14);
    CHECK_EQ_UINT(cast_f64_to_u8(-0x1.0002000000000p+15), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(-0x1.0002000000000p+15), (-128LL));
    CHECK_EQ_UINT(cast_f64_to_u16(-0x1.0002000000000p+15), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(-0x1.0002000000000p+15), (-32768LL));
    CHECK_EQ_UINT(cast_f64_to_u32(-0x1.0002000000000p+15), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(-0x1.0002000000000p+15), (-32769LL));
    CHECK_EQ_UINT(cast_f64_to_u64(-0x1.0002000000000p+15), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(-0x1.0002000000000p+15), (-32769LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(-0x1.0002000000000p+15), 0ULL);
#endif
    CHECK(cast_f64_to_f32(-0x1.0002000000000p+15) == -0x1.0002000000000p+15f);
    CHECK(cast_f64_to_f64(-0x1.0002000000000p+15) == -0x1.0002000000000p+15);
    CHECK_EQ_UINT(cast_f64_to_u8(-0x1.0003000000000p+15), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(-0x1.0003000000000p+15), (-128LL));
    CHECK_EQ_UINT(cast_f64_to_u16(-0x1.0003000000000p+15), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(-0x1.0003000000000p+15), (-32768LL));
    CHECK_EQ_UINT(cast_f64_to_u32(-0x1.0003000000000p+15), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(-0x1.0003000000000p+15), (-32769LL));
    CHECK_EQ_UINT(cast_f64_to_u64(-0x1.0003000000000p+15), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(-0x1.0003000000000p+15), (-32769LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(-0x1.0003000000000p+15), 0ULL);
#endif
    CHECK(cast_f64_to_f32(-0x1.0003000000000p+15) == -0x1.0003000000000p+15f);
    CHECK(cast_f64_to_f64(-0x1.0003000000000p+15) == -0x1.0003000000000p+15);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.0000000000000p+15), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.0000000000000p+15), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.0000000000000p+15), 32768ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.0000000000000p+15), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.0000000000000p+15), 32768ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.0000000000000p+15), 32768LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.0000000000000p+15), 32768ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.0000000000000p+15), 32768LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.0000000000000p+15), 32768ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.0000000000000p+15) == 0x1.0000000000000p+15f);
    CHECK(cast_f64_to_f64(0x1.0000000000000p+15) == 0x1.0000000000000p+15);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.0001000000000p+15), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.0001000000000p+15), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.0001000000000p+15), 32768ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.0001000000000p+15), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.0001000000000p+15), 32768ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.0001000000000p+15), 32768LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.0001000000000p+15), 32768ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.0001000000000p+15), 32768LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.0001000000000p+15), 32768ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.0001000000000p+15) == 0x1.0001000000000p+15f);
    CHECK(cast_f64_to_f64(0x1.0001000000000p+15) == 0x1.0001000000000p+15);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.fffffffffffffp+14), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.fffffffffffffp+14), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.fffffffffffffp+14), 32767ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.fffffffffffffp+14), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.fffffffffffffp+14), 32767ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.fffffffffffffp+14), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.fffffffffffffp+14), 32767ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.fffffffffffffp+14), 32767LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.fffffffffffffp+14), 32767ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.fffffffffffffp+14) == 0x1.0000000000000p+15f);
    CHECK(cast_f64_to_f64(0x1.fffffffffffffp+14) == 0x1.fffffffffffffp+14);
    CHECK_EQ_UINT(cast_f64_to_u8(-0x1.0000000000001p+15), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(-0x1.0000000000001p+15), (-128LL));
    CHECK_EQ_UINT(cast_f64_to_u16(-0x1.0000000000001p+15), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(-0x1.0000000000001p+15), (-32768LL));
    CHECK_EQ_UINT(cast_f64_to_u32(-0x1.0000000000001p+15), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(-0x1.0000000000001p+15), (-32768LL));
    CHECK_EQ_UINT(cast_f64_to_u64(-0x1.0000000000001p+15), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(-0x1.0000000000001p+15), (-32768LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(-0x1.0000000000001p+15), 0ULL);
#endif
    CHECK(cast_f64_to_f32(-0x1.0000000000001p+15) == -0x1.0000000000000p+15f);
    CHECK(cast_f64_to_f64(-0x1.0000000000001p+15) == -0x1.0000000000001p+15);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.fffffffe00000p+31), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.fffffffe00000p+31), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.fffffffe00000p+31), 65535ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.fffffffe00000p+31), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.fffffffe00000p+31), 4294967295ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.fffffffe00000p+31), 2147483647LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.fffffffe00000p+31), 4294967295ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.fffffffe00000p+31), 4294967295LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.fffffffe00000p+31), 4294967295ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.fffffffe00000p+31) == 0x1.0000000000000p+32f);
    CHECK(cast_f64_to_f64(0x1.fffffffe00000p+31) == 0x1.fffffffe00000p+31);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.ffffffff00000p+31), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.ffffffff00000p+31), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.ffffffff00000p+31), 65535ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.ffffffff00000p+31), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.ffffffff00000p+31), 4294967295ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.ffffffff00000p+31), 2147483647LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.ffffffff00000p+31), 4294967295ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.ffffffff00000p+31), 4294967295LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.ffffffff00000p+31), 4294967295ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.ffffffff00000p+31) == 0x1.0000000000000p+32f);
    CHECK(cast_f64_to_f64(0x1.ffffffff00000p+31) == 0x1.ffffffff00000p+31);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.fffffffd00000p+31), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.fffffffd00000p+31), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.fffffffd00000p+31), 65535ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.fffffffd00000p+31), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.fffffffd00000p+31), 4294967294ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.fffffffd00000p+31), 2147483647LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.fffffffd00000p+31), 4294967294ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.fffffffd00000p+31), 4294967294LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.fffffffd00000p+31), 4294967294ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.fffffffd00000p+31) == 0x1.0000000000000p+32f);
    CHECK(cast_f64_to_f64(0x1.fffffffd00000p+31) == 0x1.fffffffd00000p+31);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.0000000000000p+32), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.0000000000000p+32), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.0000000000000p+32), 65535ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.0000000000000p+32), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.0000000000000p+32), 4294967295ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.0000000000000p+32), 2147483647LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.0000000000000p+32), 4294967296ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.0000000000000p+32), 4294967296LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.0000000000000p+32), 4294967296ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.0000000000000p+32) == 0x1.0000000000000p+32f);
    CHECK(cast_f64_to_f64(0x1.0000000000000p+32) == 0x1.0000000000000p+32);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.0000000080000p+32), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.0000000080000p+32), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.0000000080000p+32), 65535ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.0000000080000p+32), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.0000000080000p+32), 4294967295ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.0000000080000p+32), 2147483647LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.0000000080000p+32), 4294967296ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.0000000080000p+32), 4294967296LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.0000000080000p+32), 4294967296ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.0000000080000p+32) == 0x1.0000000000000p+32f);
    CHECK(cast_f64_to_f64(0x1.0000000080000p+32) == 0x1.0000000080000p+32);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.fffffffffffffp+31), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.fffffffffffffp+31), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.fffffffffffffp+31), 65535ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.fffffffffffffp+31), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.fffffffffffffp+31), 4294967295ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.fffffffffffffp+31), 2147483647LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.fffffffffffffp+31), 4294967295ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.fffffffffffffp+31), 4294967295LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.fffffffffffffp+31), 4294967295ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.fffffffffffffp+31) == 0x1.0000000000000p+32f);
    CHECK(cast_f64_to_f64(0x1.fffffffffffffp+31) == 0x1.fffffffffffffp+31);
    CHECK_EQ_UINT(cast_f64_to_u8(-0x1.0000000000000p+31), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(-0x1.0000000000000p+31), (-128LL));
    CHECK_EQ_UINT(cast_f64_to_u16(-0x1.0000000000000p+31), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(-0x1.0000000000000p+31), (-32768LL));
    CHECK_EQ_UINT(cast_f64_to_u32(-0x1.0000000000000p+31), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(-0x1.0000000000000p+31), (-2147483648LL));
    CHECK_EQ_UINT(cast_f64_to_u64(-0x1.0000000000000p+31), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(-0x1.0000000000000p+31), (-2147483648LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(-0x1.0000000000000p+31), 0ULL);
#endif
    CHECK(cast_f64_to_f32(-0x1.0000000000000p+31) == -0x1.0000000000000p+31f);
    CHECK(cast_f64_to_f64(-0x1.0000000000000p+31) == -0x1.0000000000000p+31);
    CHECK_EQ_UINT(cast_f64_to_u8(-0x1.fffffffe00000p+30), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(-0x1.fffffffe00000p+30), (-128LL));
    CHECK_EQ_UINT(cast_f64_to_u16(-0x1.fffffffe00000p+30), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(-0x1.fffffffe00000p+30), (-32768LL));
    CHECK_EQ_UINT(cast_f64_to_u32(-0x1.fffffffe00000p+30), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(-0x1.fffffffe00000p+30), (-2147483647LL));
    CHECK_EQ_UINT(cast_f64_to_u64(-0x1.fffffffe00000p+30), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(-0x1.fffffffe00000p+30), (-2147483647LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(-0x1.fffffffe00000p+30), 0ULL);
#endif
    CHECK(cast_f64_to_f32(-0x1.fffffffe00000p+30) == -0x1.0000000000000p+31f);
    CHECK(cast_f64_to_f64(-0x1.fffffffe00000p+30) == -0x1.fffffffe00000p+30);
    CHECK_EQ_UINT(cast_f64_to_u8(-0x1.0000000100000p+31), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(-0x1.0000000100000p+31), (-128LL));
    CHECK_EQ_UINT(cast_f64_to_u16(-0x1.0000000100000p+31), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(-0x1.0000000100000p+31), (-32768LL));
    CHECK_EQ_UINT(cast_f64_to_u32(-0x1.0000000100000p+31), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(-0x1.0000000100000p+31), (-2147483648LL));
    CHECK_EQ_UINT(cast_f64_to_u64(-0x1.0000000100000p+31), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(-0x1.0000000100000p+31), (-2147483648LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(-0x1.0000000100000p+31), 0ULL);
#endif
    CHECK(cast_f64_to_f32(-0x1.0000000100000p+31) == -0x1.0000000000000p+31f);
    CHECK(cast_f64_to_f64(-0x1.0000000100000p+31) == -0x1.0000000100000p+31);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.fffffffc00000p+30), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.fffffffc00000p+30), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.fffffffc00000p+30), 65535ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.fffffffc00000p+30), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.fffffffc00000p+30), 2147483647ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.fffffffc00000p+30), 2147483647LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.fffffffc00000p+30), 2147483647ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.fffffffc00000p+30), 2147483647LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.fffffffc00000p+30), 2147483647ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.fffffffc00000p+30) == 0x1.0000000000000p+31f);
    CHECK(cast_f64_to_f64(0x1.fffffffc00000p+30) == 0x1.fffffffc00000p+30);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.fffffffe00000p+30), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.fffffffe00000p+30), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.fffffffe00000p+30), 65535ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.fffffffe00000p+30), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.fffffffe00000p+30), 2147483647ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.fffffffe00000p+30), 2147483647LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.fffffffe00000p+30), 2147483647ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.fffffffe00000p+30), 2147483647LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.fffffffe00000p+30), 2147483647ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.fffffffe00000p+30) == 0x1.0000000000000p+31f);
    CHECK(cast_f64_to_f64(0x1.fffffffe00000p+30) == 0x1.fffffffe00000p+30);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.fffffffa00000p+30), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.fffffffa00000p+30), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.fffffffa00000p+30), 65535ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.fffffffa00000p+30), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.fffffffa00000p+30), 2147483646ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.fffffffa00000p+30), 2147483646LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.fffffffa00000p+30), 2147483646ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.fffffffa00000p+30), 2147483646LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.fffffffa00000p+30), 2147483646ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.fffffffa00000p+30) == 0x1.0000000000000p+31f);
    CHECK(cast_f64_to_f64(0x1.fffffffa00000p+30) == 0x1.fffffffa00000p+30);
    CHECK_EQ_UINT(cast_f64_to_u8(-0x1.0000000200000p+31), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(-0x1.0000000200000p+31), (-128LL));
    CHECK_EQ_UINT(cast_f64_to_u16(-0x1.0000000200000p+31), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(-0x1.0000000200000p+31), (-32768LL));
    CHECK_EQ_UINT(cast_f64_to_u32(-0x1.0000000200000p+31), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(-0x1.0000000200000p+31), (-2147483648LL));
    CHECK_EQ_UINT(cast_f64_to_u64(-0x1.0000000200000p+31), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(-0x1.0000000200000p+31), (-2147483649LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(-0x1.0000000200000p+31), 0ULL);
#endif
    CHECK(cast_f64_to_f32(-0x1.0000000200000p+31) == -0x1.0000000000000p+31f);
    CHECK(cast_f64_to_f64(-0x1.0000000200000p+31) == -0x1.0000000200000p+31);
    CHECK_EQ_UINT(cast_f64_to_u8(-0x1.0000000300000p+31), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(-0x1.0000000300000p+31), (-128LL));
    CHECK_EQ_UINT(cast_f64_to_u16(-0x1.0000000300000p+31), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(-0x1.0000000300000p+31), (-32768LL));
    CHECK_EQ_UINT(cast_f64_to_u32(-0x1.0000000300000p+31), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(-0x1.0000000300000p+31), (-2147483648LL));
    CHECK_EQ_UINT(cast_f64_to_u64(-0x1.0000000300000p+31), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(-0x1.0000000300000p+31), (-2147483649LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(-0x1.0000000300000p+31), 0ULL);
#endif
    CHECK(cast_f64_to_f32(-0x1.0000000300000p+31) == -0x1.0000000000000p+31f);
    CHECK(cast_f64_to_f64(-0x1.0000000300000p+31) == -0x1.0000000300000p+31);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.0000000000000p+31), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.0000000000000p+31), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.0000000000000p+31), 65535ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.0000000000000p+31), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.0000000000000p+31), 2147483648ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.0000000000000p+31), 2147483647LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.0000000000000p+31), 2147483648ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.0000000000000p+31), 2147483648LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.0000000000000p+31), 2147483648ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.0000000000000p+31) == 0x1.0000000000000p+31f);
    CHECK(cast_f64_to_f64(0x1.0000000000000p+31) == 0x1.0000000000000p+31);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.0000000100000p+31), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.0000000100000p+31), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.0000000100000p+31), 65535ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.0000000100000p+31), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.0000000100000p+31), 2147483648ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.0000000100000p+31), 2147483647LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.0000000100000p+31), 2147483648ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.0000000100000p+31), 2147483648LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.0000000100000p+31), 2147483648ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.0000000100000p+31) == 0x1.0000000000000p+31f);
    CHECK(cast_f64_to_f64(0x1.0000000100000p+31) == 0x1.0000000100000p+31);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.fffffffffffffp+30), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.fffffffffffffp+30), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.fffffffffffffp+30), 65535ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.fffffffffffffp+30), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.fffffffffffffp+30), 2147483647ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.fffffffffffffp+30), 2147483647LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.fffffffffffffp+30), 2147483647ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.fffffffffffffp+30), 2147483647LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.fffffffffffffp+30), 2147483647ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.fffffffffffffp+30) == 0x1.0000000000000p+31f);
    CHECK(cast_f64_to_f64(0x1.fffffffffffffp+30) == 0x1.fffffffffffffp+30);
    CHECK_EQ_UINT(cast_f64_to_u8(-0x1.0000000000001p+31), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(-0x1.0000000000001p+31), (-128LL));
    CHECK_EQ_UINT(cast_f64_to_u16(-0x1.0000000000001p+31), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(-0x1.0000000000001p+31), (-32768LL));
    CHECK_EQ_UINT(cast_f64_to_u32(-0x1.0000000000001p+31), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(-0x1.0000000000001p+31), (-2147483648LL));
    CHECK_EQ_UINT(cast_f64_to_u64(-0x1.0000000000001p+31), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(-0x1.0000000000001p+31), (-2147483648LL));
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(-0x1.0000000000001p+31), 0ULL);
#endif
    CHECK(cast_f64_to_f32(-0x1.0000000000001p+31) == -0x1.0000000000000p+31f);
    CHECK(cast_f64_to_f64(-0x1.0000000000001p+31) == -0x1.0000000000001p+31);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.fffffffffffffp+63), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.fffffffffffffp+63), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.fffffffffffffp+63), 65535ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.fffffffffffffp+63), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.fffffffffffffp+63), 4294967295ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.fffffffffffffp+63), 2147483647LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.fffffffffffffp+63), 18446744073709549568ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.fffffffffffffp+63), 9223372036854775807LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.fffffffffffffp+63), 18446744073709549568ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.fffffffffffffp+63) == 0x1.0000000000000p+64f);
    CHECK(cast_f64_to_f64(0x1.fffffffffffffp+63) == 0x1.fffffffffffffp+63);
    CHECK_EQ_UINT(cast_f64_to_u8(0x1.fffffffffffffp+62), 255ULL);
    CHECK_EQ_INT(cast_f64_to_i8(0x1.fffffffffffffp+62), 127LL);
    CHECK_EQ_UINT(cast_f64_to_u16(0x1.fffffffffffffp+62), 65535ULL);
    CHECK_EQ_INT(cast_f64_to_i16(0x1.fffffffffffffp+62), 32767LL);
    CHECK_EQ_UINT(cast_f64_to_u32(0x1.fffffffffffffp+62), 4294967295ULL);
    CHECK_EQ_INT(cast_f64_to_i32(0x1.fffffffffffffp+62), 2147483647LL);
    CHECK_EQ_UINT(cast_f64_to_u64(0x1.fffffffffffffp+62), 9223372036854774784ULL);
    CHECK_EQ_INT(cast_f64_to_i64(0x1.fffffffffffffp+62), 9223372036854774784LL);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(0x1.fffffffffffffp+62), 9223372036854774784ULL);
#endif
    CHECK(cast_f64_to_f32(0x1.fffffffffffffp+62) == 0x1.0000000000000p+63f);
    CHECK(cast_f64_to_f64(0x1.fffffffffffffp+62) == 0x1.fffffffffffffp+62);
    CHECK_EQ_UINT(cast_f64_to_u8(-0x1.0000000000001p+63), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i8(-0x1.0000000000001p+63), (-128LL));
    CHECK_EQ_UINT(cast_f64_to_u16(-0x1.0000000000001p+63), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i16(-0x1.0000000000001p+63), (-32768LL));
    CHECK_EQ_UINT(cast_f64_to_u32(-0x1.0000000000001p+63), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i32(-0x1.0000000000001p+63), (-2147483648LL));
    CHECK_EQ_UINT(cast_f64_to_u64(-0x1.0000000000001p+63), 0ULL);
    CHECK_EQ_INT(cast_f64_to_i64(-0x1.0000000000001p+63), INT64_MIN);
#if SIZE_MAX == UINT64_MAX
    CHECK_EQ_UINT(cast_f64_to_size_t(-0x1.0000000000001p+63), 0ULL);
#endif
    CHECK(cast_f64_to_f32(-0x1.0000000000001p+63) == -0x1.0000000000000p+63f);
    CHECK(cast_f64_to_f64(-0x1.0000000000001p+63) == -0x1.0000000000001p+63);
}

void test_numbers_cast_int_to_float_rounds(HammerCtx *t)
{
    CHECK(cast_u64_to_f32(UINT64_MAX) == 0x1p64f);
    CHECK(cast_u64_to_f64(UINT64_MAX) == 0x1p64);
    CHECK(cast_i64_to_f32(INT64_MAX) == 0x1p63f);
    CHECK(cast_i64_to_f64(INT64_MAX) == 0x1p63);
    CHECK(cast_i64_to_f64(INT64_MIN) == -0x1p63);
    CHECK(cast_u32_to_f32(16777217u) == 16777216.0f);
    CHECK(cast_i32_to_f32(INT32_MAX) == 0x1p31f);
}

void test_numbers_cast_keeps_nan_and_infinity_between_floats(HammerCtx *t)
{
    CHECK(isnan(cast_f64_to_f32((f64)NAN)));
    CHECK(isnan(cast_f32_to_f64(NAN)));
    CHECK(isinf(cast_f64_to_f32((f64)INFINITY)) && cast_f64_to_f32((f64)INFINITY) > 0.0f);
    CHECK(isinf(cast_f64_to_f32(-(f64)INFINITY)) && cast_f64_to_f32(-(f64)INFINITY) < 0.0f);
    CHECK(cast_f64_to_f32(1e300) == FLT_MAX);
    CHECK(cast_f64_to_f32(-1e300) == -FLT_MAX);
    CHECK_EQ_INT(cast_f64_to_i32((f64)NAN), 0);
    CHECK_EQ_UINT(cast_f32_to_u8(NAN), 0);
}
