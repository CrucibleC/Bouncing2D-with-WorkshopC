#include "util/string.h"

#include <stdint.h>
#include <string.h>

#include "util/dynamic_array.h"
#include "workshopc_tags.h"

// Makes room for added more chars plus the '\0', growing through util_dynamic_array_resize
static status util_string_grow(borrows massive util_string* self, size_t added)
{
    if (!memory_block_valid(&self->chars))
    {
        return STATUS_INVALID_STATE;
    }
    if (added > SIZE_MAX - 1 - self->length)
    {
        return STATUS_OUT_OF_RANGE;
    }
    size_t capacity = memory_block_count(&self->chars);
    size_t needed = util_dynamic_array_resize(self->length + added + 1, capacity);
    if (needed != capacity && !memory_block_resize(&self->chars, needed))
    {
        return memory_block_status(&self->chars);
    }
    return STATUS_OK;
}

// Copies count chars to the end and terminates; call only after util_string_grow succeeded
static void util_string_put(borrows massive util_string* self, const char* source, size_t count)
{
    char* chars = memory_block_data(&self->chars);
    if (chars == NULL || source == NULL)
    {
        return;
    }
    (void)memcpy(&chars[self->length], source, count);
    self->length += count;
    chars[self->length] = '\0';
}

util_string util_string_make(const char* text)
{
    size_t length = text ? strlen(text) : 0;
    // Zeroed, so an empty string already ends in its '\0'
    util_string result = {
        .chars = memory_block_make(util_dynamic_array_resize(length + 1, 0), sizeof(char)),
        .length = 0,
    };
    util_string_put(&result, text, length);
    return util_string_return(&result);
}

util_string util_string_copy(massive const util_string* self)
{
    util_string result = {
        .chars = memory_block_copy(&self->chars),
        .length = 0,
    };
    if (memory_block_valid(&result.chars))
    {
        result.length = self->length;
    }
    return util_string_return(&result);
}

util_string util_string_move(borrows massive util_string* self)
{
    util_string result = {
        .chars = memory_block_move(&self->chars),
        .length = self->length,
    };
    self->length = 0;
    return result;
}

void util_string_destroy(borrows massive util_string* self)
{
    memory_block_destroy(&self->chars);
    self->length = 0;
}

util_string util_string_return(borrows massive util_string* self)
{
    return *self;
}

bool util_string_valid(massive const util_string* self)
{
    return memory_block_valid(&self->chars);
}

status util_string_status(massive const util_string* self)
{
    return memory_block_status(&self->chars);
}

status util_string_append(borrows massive util_string* self, const char* text)
{
    if (text == NULL)
    {
        return STATUS_INVALID_ARGUMENT;
    }
    size_t added = strlen(text);
    status result = util_string_grow(self, added);
    if (result == STATUS_OK)
    {
        util_string_put(self, text, added);
    }
    return result;
}

status util_string_append_string(borrows massive util_string* self, massive const util_string* other)
{
    size_t added = other->length;
    status result = util_string_grow(self, added);
    if (result == STATUS_OK)
    {
        // Read other's chars only after growing: when other is self, the resize may have moved them
        util_string_put(self, memory_block_const_data(&other->chars), added);
    }
    return result;
}

status util_string_append_span(borrows massive util_string* self, char_const_span chars)
{
    if (chars.data == NULL && chars.size > 0)
    {
        return STATUS_INVALID_ARGUMENT;
    }
    status result = util_string_grow(self, chars.size);
    char* dest = memory_block_data(&self->chars);
    if (result == STATUS_OK && dest != NULL && chars.size > 0)
    {
        (void)memcpy(&dest[self->length], chars.data, chars.size);
        self->length += chars.size;
        dest[self->length] = '\0';
    }
    return result;
}

void util_string_truncate(borrows massive util_string* self, size_t length)
{
    char* chars = memory_block_data(&self->chars);
    if (chars == NULL || length >= self->length)
    {
        return;
    }
    chars[length] = '\0';
    self->length = length;
}

void util_string_clear(borrows massive util_string* self)
{
    char* chars = memory_block_data(&self->chars);
    if (chars)
    {
        chars[0] = '\0';
    }
    self->length = 0;
}

size_t util_string_length(massive const util_string* self)
{
    return self->length;
}

size_t util_string_capacity(massive const util_string* self)
{
    return memory_block_count(&self->chars);
}

const char* util_string_c_str(massive const util_string* self)
{
    const char* chars = memory_block_const_data(&self->chars);
    return chars ? chars : "";
}
