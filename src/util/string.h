#ifndef UTIL_STRING_H
#define UTIL_STRING_H

#include <stdbool.h>
#include <stddef.h>

#include "memory_block.h"
#include "span.h"
#include "status.h"
#include "workshopc_tags.h"

// A growable, always '\0'-terminated string on the heap
typedef struct util_string
{
    PRIVATE memory_block chars;   // one char each; count is the capacity, including the '\0'
    PRIVATE size_t length;        // chars before the '\0'
} util_string;

// A copy of text (NULL gives ""); invalid when the allocation fails
util_string util_string_make(const char* text);
util_string util_string_copy(REF const util_string* self);
util_string util_string_move(MUTABLE REF util_string* self);
void util_string_destroy(MUTABLE REF util_string* self);
util_string util_string_return(MUTABLE REF util_string* self);
bool util_string_valid(REF const util_string* self);
status util_string_status(REF const util_string* self);

// Appends text, growing the capacity through util_dynamic_array_resize; on failure the string is unchanged.
// text must not point into self; to append a string to itself, use util_string_append_string
status util_string_append(MUTABLE REF util_string* self, const char* text);
// Appends other's text; other may be self
status util_string_append_string(MUTABLE REF util_string* self, REF const util_string* other);
// Appends exactly chars.size chars, even '\0's among them; chars must not point into self
status util_string_append_span(MUTABLE REF util_string* self, char_const_span chars);
// Empties the string and keeps its capacity
void util_string_clear(MUTABLE REF util_string* self);
// Keeps the first length chars and the capacity; does nothing when the string is not longer
void util_string_truncate(MUTABLE REF util_string* self, size_t length);
size_t util_string_length(REF const util_string* self);
size_t util_string_capacity(REF const util_string* self);
// The text, '\0'-terminated and owned by the string; "" when the string is invalid
const char* util_string_c_str(REF const util_string* self);

#endif // UTIL_STRING_H
