#include "util/dynamic_array.h"

#include <stdint.h>

static const size_t MIN_CAPACITY = 8;

size_t util_dynamic_array_resize(size_t size, size_t capacity)
{
    if (size <= capacity)
    {
        return capacity;
    }
    size_t grown = capacity > SIZE_MAX / 2 ? SIZE_MAX : capacity * 2;
    if (grown < MIN_CAPACITY)
    {
        grown = MIN_CAPACITY;
    }
    return grown < size ? size : grown;
}
