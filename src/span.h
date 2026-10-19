#ifndef SPAN_H
#define SPAN_H

#include <stddef.h>

#include "numbers.h"
#include "workshopc_tags.h"

// Spans of the basic types: a pointer and its element count

typedef struct char_span
{
    char* data;
    size_t size;
} char_span;

typedef struct char_const_span
{
    const char* data;
    size_t size;
} char_const_span;

// { .data = data, .size = size }
char_span char_span_pod(borrows char* data, size_t size);
// The same chars, read-only
char_const_span char_const_span_pod(char_span from);

typedef struct u32_span
{
    u32* data;
    size_t size;
} u32_span;

typedef struct u32_const_span
{
    const u32* data;
    size_t size;
} u32_const_span;

// { .data = data, .size = size }
u32_span u32_span_pod(borrows u32* data, size_t size);
// { .data = data, .size = size }
u32_const_span u32_const_span_pod(const u32* data, size_t size);

#endif // SPAN_H
