#ifndef MEMORY_BLOCK_H
#define MEMORY_BLOCK_H

#include <stdbool.h>
#include <stddef.h>

#include "status.h"
#include "workshopc_tags.h"

// The only owner of heap memory: count elements of element_size bytes each
typedef struct memory_block
{
    PRIVATE void* data;
    PRIVATE size_t count;
    PRIVATE size_t element_size;
    PRIVATE status status;   // of the last make, copy or resize
} memory_block;

// Zeroed memory; invalid when count is 0, the size overflows or the allocation fails
memory_block memory_block_make(size_t count, size_t element_size);
memory_block memory_block_copy(REF const memory_block* self);
memory_block memory_block_move(MUTABLE REF memory_block* self);
void memory_block_destroy(MUTABLE REF memory_block* self);
memory_block memory_block_return(MUTABLE REF memory_block* self);
bool memory_block_valid(REF const memory_block* self);
status memory_block_status(REF const memory_block* self);

// Changes the element count; added elements are zeroed, like make's. On failure the block keeps
// its old contents
bool memory_block_resize(MUTABLE REF memory_block* self, size_t count);
void* memory_block_data(MUTABLE REF memory_block* self);
const void* memory_block_const_data(REF const memory_block* self);
size_t memory_block_count(REF const memory_block* self);
size_t memory_block_element_size(REF const memory_block* self);

#endif // MEMORY_BLOCK_H
