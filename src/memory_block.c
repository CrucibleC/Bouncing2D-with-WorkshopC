#include "memory_block.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "workshopc_tags.h"

static bool memory_block_fits(size_t count, size_t element_size)
{
    return element_size == 0 || count <= SIZE_MAX / element_size;
}

static status memory_block_result(bool usable, const void* data)
{
    status result = STATUS_OUT_OF_MEMORY;
    if (!usable)
    {
        result = STATUS_INVALID_ARGUMENT;
    }
    else if (data)
    {
        result = STATUS_OK;
    }
    return result;
}

memory_block memory_block_make(size_t count, size_t element_size)
{
    bool usable = count > 0 && memory_block_fits(count, element_size);
    void* data = NULL;
    if (usable)
    {
        data = calloc(count, element_size);
    }
    return (memory_block){
        .data = data,
        .count = data ? count : 0,
        .element_size = element_size,
        .status = memory_block_result(usable, data),
    };
}

memory_block memory_block_copy(massive const memory_block* self)
{
    bool usable = self->data != NULL && self->count > 0;
    void* data = NULL;
    if (usable)
    {
        data = malloc(self->count * self->element_size);
    }
    if (data && self->data)
    {
        (void)memcpy(data, self->data, self->count * self->element_size);
    }
    return (memory_block){
        .data = data,
        .count = data ? self->count : 0,
        .element_size = self->element_size,
        .status = memory_block_result(usable, data),
    };
}

memory_block memory_block_move(borrows massive memory_block* self)
{
    memory_block result = {
        .data = self->data,
        .count = self->count,
        .element_size = self->element_size,
        .status = self->status,
    };
    self->data = NULL;
    self->count = 0;
    self->status = STATUS_INVALID_STATE;
    return result;
}

void memory_block_destroy(borrows massive memory_block* self)
{
    free(self->data);
    self->data = NULL;
    self->count = 0;
    self->status = STATUS_INVALID_STATE;
}

memory_block memory_block_return(borrows massive memory_block* self)
{
    return *self;
}

bool memory_block_valid(massive const memory_block* self)
{
    return self->data != NULL;
}

status memory_block_status(massive const memory_block* self)
{
    return self->status;
}

bool memory_block_resize(borrows massive memory_block* self, size_t count)
{
    bool usable = count > 0 && memory_block_fits(count, self->element_size);
    size_t old_count = self->data != NULL ? self->count : 0;
    void* data = NULL;
    if (usable)
    {
        data = realloc(self->data, count * self->element_size);
    }
    if (data)
    {
        // realloc leaves added bytes uninitialized; zero them, so growing matches make's calloc
        if (count > old_count)
        {
            char* bytes = data;
            (void)memset(&bytes[old_count * self->element_size], 0, (count - old_count) * self->element_size);
        }
        self->data = data;
        self->count = count;
    }
    self->status = memory_block_result(usable, data);
    return data != NULL;
}

void* memory_block_data(borrows massive memory_block* self)
{
    return self->data;
}

const void* memory_block_const_data(massive const memory_block* self)
{
    return self->data;
}

size_t memory_block_count(massive const memory_block* self)
{
    return self->count;
}

size_t memory_block_element_size(massive const memory_block* self)
{
    return self->element_size;
}
