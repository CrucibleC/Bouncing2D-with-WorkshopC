// stat, mkdir, rmdir and readlink are POSIX, hidden by -std=c11 unless asked for before any system header
#if !defined(_WIN32)
#define _POSIX_C_SOURCE 200809L
#endif

#include "util/fs.h"

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <direct.h>
#include <windows.h>
#else
#include <unistd.h>
#endif

#include "memory_block.h"
#include "span.h"
#include "workshopc_tags.h"

typedef enum fs_kind
{
    FS_KIND_NOTHING,
    FS_KIND_FILE,
    FS_KIND_FOLDER,
    FS_KIND_OTHER
} fs_kind;

static const size_t READ_CHUNK_SIZE = 4096;
// Longest executable path plus its '\0' (Linux's PATH_MAX)
#define UTIL_FS_PATH_SIZE 4096

// The status for the errno a failed C library or OS call left
static status util_fs_errno_status(void)
{
    status result = STATUS_IO_ERROR;
    switch (errno)
    {
        case ENOENT:
            result = STATUS_NOT_FOUND;
            break;
        case EEXIST:
            result = STATUS_ALREADY_EXISTS;
            break;
        default:
            break;
    }
    return result;
}

static fs_kind util_fs_kind_of(const char* path)
{
    if (path == NULL)
    {
        return FS_KIND_NOTHING;
    }
#if defined(_WIN32)
    struct _stat info = { 0 };
    if (_stat(path, &info) != 0)
    {
        return FS_KIND_NOTHING;
    }
    if ((info.st_mode & _S_IFMT) == _S_IFDIR)
    {
        return FS_KIND_FOLDER;
    }
    if ((info.st_mode & _S_IFMT) == _S_IFREG)
    {
        return FS_KIND_FILE;
    }
#else
    struct stat info = { 0 };
    if (stat(path, &info) != 0)
    {
        return FS_KIND_NOTHING;
    }
    if (S_ISDIR(info.st_mode))
    {
        return FS_KIND_FOLDER;
    }
    if (S_ISREG(info.st_mode))
    {
        return FS_KIND_FILE;
    }
#endif
    return FS_KIND_OTHER;
}

static bool util_fs_is_separator(char c)
{
#if defined(_WIN32)
    return c == '/' || c == '\\';
#else
    return c == '/';
#endif
}

// Creates one folder whose parent exists
static status util_fs_make_folder(const char* path)
{
#if defined(_WIN32)
    bool made = _mkdir(path) == 0;
#else
    bool made = mkdir(path, 0777) == 0;
#endif
    return made ? STATUS_OK : util_fs_errno_status();
}

// Writes text to the file opened with mode ("wb" or "ab")
static status util_fs_put(const char* path, const char* text, const char* mode)
{
    if (path == NULL || text == NULL)
    {
        return STATUS_INVALID_ARGUMENT;
    }
    FILE* file = fopen(path, mode);
    if (file == NULL)
    {
        return util_fs_errno_status();
    }
    size_t length = strlen(text);
    status result = fwrite(text, 1, length, file) == length ? STATUS_OK : STATUS_IO_ERROR;
    if (fclose(file) != 0 && result == STATUS_OK)
    {
        result = STATUS_IO_ERROR;
    }
    return result;
}

bool util_fs_file_exists(const char* path)
{
    return util_fs_kind_of(path) == FS_KIND_FILE;
}

bool util_fs_folder_exists(const char* path)
{
    return util_fs_kind_of(path) == FS_KIND_FOLDER;
}

status util_fs_create_file(const char* path)
{
    if (path == NULL)
    {
        return STATUS_INVALID_ARGUMENT;
    }
    if (util_fs_kind_of(path) != FS_KIND_NOTHING)
    {
        return STATUS_ALREADY_EXISTS;
    }
    // "x": fails instead of truncating when the file appeared since the check
    FILE* file = fopen(path, "wbx");
    if (file == NULL)
    {
        return util_fs_errno_status();
    }
    return fclose(file) == 0 ? STATUS_OK : STATUS_IO_ERROR;
}

status util_fs_create_folder(const char* path)
{
    if (path == NULL || path[0] == '\0')
    {
        return STATUS_INVALID_ARGUMENT;
    }
    if (util_fs_kind_of(path) != FS_KIND_NOTHING)
    {
        return STATUS_ALREADY_EXISTS;
    }
    util_string parent = util_string_make(path);
    status result = util_string_status(&parent);
    size_t length = strlen(path);
    // Each separator ends a parent folder; a leading one (root) or "C:" (a drive) is not one to create
    for (size_t i = 1; i < length && result == STATUS_OK; i++)
    {
        if (util_fs_is_separator(path[i]) && !util_fs_is_separator(path[i - 1]) && path[i - 1] != ':')
        {
            util_string_clear(&parent);
            result = util_string_append(&parent, path);
            util_string_truncate(&parent, i);
            if (result == STATUS_OK && !util_fs_folder_exists(util_string_c_str(&parent)))
            {
                result = util_fs_make_folder(util_string_c_str(&parent));
            }
        }
    }
    // With a trailing separator the loop already made the folder itself
    if (result == STATUS_OK && !util_fs_folder_exists(path))
    {
        result = util_fs_make_folder(path);
    }
    util_string_destroy(&parent);
    return result;
}

status util_fs_write_file(const char* path, const char* text)
{
    return util_fs_put(path, text, "wb");
}

status util_fs_append_file(const char* path, const char* text)
{
    return util_fs_put(path, text, "ab");
}

status util_fs_read_file(const char* path, MUTABLE REF util_string* into)
{
    if (path == NULL)
    {
        return STATUS_INVALID_ARGUMENT;
    }
    FILE* file = fopen(path, "rb");
    if (file == NULL)
    {
        return util_fs_errno_status();
    }
    util_string text = util_string_make("");
    memory_block buffer = memory_block_make(READ_CHUNK_SIZE, sizeof(char));
    char_span chunk = char_span_pod(memory_block_data(&buffer), memory_block_count(&buffer));
    status result = util_string_status(&text);
    if (result == STATUS_OK)
    {
        result = memory_block_status(&buffer);
    }
    size_t count = chunk.size;
    while (result == STATUS_OK && count == chunk.size)
    {
        count = fread(chunk.data, 1, chunk.size, file);
        char_const_span read = char_const_span_pod(chunk);
        read.size = count;
        result = util_string_append_span(&text, read);
    }
    if (result == STATUS_OK && ferror(file) != 0)
    {
        result = STATUS_IO_ERROR;
    }
    (void)fclose(file);
    if (result == STATUS_OK)
    {
        util_string_clear(into);
        result = util_string_append_string(into, &text);
    }
    memory_block_destroy(&buffer);
    util_string_destroy(&text);
    return result;
}

status util_fs_remove_file(const char* path)
{
    if (path == NULL)
    {
        return STATUS_INVALID_ARGUMENT;
    }
    if (util_fs_kind_of(path) != FS_KIND_FILE)
    {
        return STATUS_NOT_FOUND;
    }
    return remove(path) == 0 ? STATUS_OK : util_fs_errno_status();
}

status util_fs_remove_folder(const char* path)
{
    if (path == NULL)
    {
        return STATUS_INVALID_ARGUMENT;
    }
    if (util_fs_kind_of(path) != FS_KIND_FOLDER)
    {
        return STATUS_NOT_FOUND;
    }
#if defined(_WIN32)
    bool removed = _rmdir(path) == 0;
#else
    bool removed = rmdir(path) == 0;
#endif
    return removed ? STATUS_OK : util_fs_errno_status();
}

status util_fs_executable_path(MUTABLE REF util_string* into)
{
    char path[UTIL_FS_PATH_SIZE] = { 0 };
    char_span path_span = char_span_pod(path, sizeof path);
#if defined(_WIN32)
    // DWORD is 32-bit unsigned on Windows
    size_t length = cast_u32_to_size_t(GetModuleFileNameA(NULL, path_span.data, cast_size_t_to_u32(path_span.size)));
    // A full buffer means the path was cut
    bool found = length > 0 && length < path_span.size;
#else
    // readlink adds no '\0', so one char is kept for it
    // ssize_t is 64-bit here; a failure (-1) clamps to 0
    size_t length = cast_i64_to_size_t(readlink("/proc/self/exe", path_span.data, path_span.size - 1));
    bool found = length > 0 && length < path_span.size - 1;
#endif
    if (!found)
    {
        return STATUS_IO_ERROR;
    }
    char_const_span full_path = char_const_span_pod(path_span);
    full_path.size = length;
    util_string_clear(into);
    return util_string_append_span(into, full_path);
}

status util_fs_executable_folder(MUTABLE REF util_string* into)
{
    util_string path = util_string_make("");
    status result = util_fs_executable_path(&path);
    if (result == STATUS_OK)
    {
        // The folder is everything before the last separator
        const char* chars = util_string_c_str(&path);
        size_t folder_length = 0;
        for (size_t i = 0; i < util_string_length(&path); i++)
        {
            if (util_fs_is_separator(chars[i]))
            {
                folder_length = i;
            }
        }
        util_string_truncate(&path, folder_length);
        util_string_clear(into);
        result = util_string_append_string(into, &path);
    }
    util_string_destroy(&path);
    return result;
}
