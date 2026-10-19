#include "span.h"

#include "workshopc_tags.h"

char_span char_span_pod(MUTABLE char* data, size_t size)
{
    return (char_span){ .data = data, .size = size };
}

char_const_span char_const_span_pod(char_span from)
{
    return (char_const_span){ .data = from.data, .size = from.size };
}

u32_span u32_span_pod(MUTABLE u32* data, size_t size)
{
    return (u32_span){ .data = data, .size = size };
}

u32_const_span u32_const_span_pod(const u32* data, size_t size)
{
    return (u32_const_span){ .data = data, .size = size };
}
