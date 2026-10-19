#ifndef UTIL_DYNAMIC_ARRAY_H
#define UTIL_DYNAMIC_ARRAY_H

#include <stddef.h>

// The capacity a dynamic array needs to hold size elements: capacity itself when
// size already fits, otherwise at least double it (with a small minimum), never less than size
size_t util_dynamic_array_resize(size_t size, size_t capacity);

#endif // UTIL_DYNAMIC_ARRAY_H
