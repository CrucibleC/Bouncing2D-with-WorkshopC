#ifndef UTIL_FS_H
#define UTIL_FS_H

#include <stdbool.h>

#include "status.h"
#include "util/string.h"
#include "workshopc_tags.h"

// Files and folders, one whole operation per call: every function opens and closes what it uses.
// Paths are byte strings. On Windows they use the ANSI code page, so non-ASCII (UTF-8) paths are
// not supported. Files are read and written as bytes, without newline translation.
// A NULL path or text gives STATUS_INVALID_ARGUMENT; errors from the OS give STATUS_NOT_FOUND,
// STATUS_ALREADY_EXISTS or STATUS_IO_ERROR.

// Whether path is a regular file; false for NULL, a folder or nothing
bool util_fs_file_exists(const char* path);
// Whether path is a folder; false for NULL, a file or nothing
bool util_fs_folder_exists(const char* path);

// Creates an empty file; STATUS_ALREADY_EXISTS when anything is at path (it is left untouched),
// STATUS_NOT_FOUND when its folder is missing
status util_fs_create_file(const char* path);
// Creates the folder and any missing parent folders; STATUS_ALREADY_EXISTS when anything is at path
status util_fs_create_folder(const char* path);

// Creates the file, or replaces its contents, with text
status util_fs_write_file(const char* path, const char* text);
// Adds text to the end of the file, creating it when missing
status util_fs_append_file(const char* path, const char* text);
// Replaces into's text with the file's contents. On failure into is unchanged, except when
// running out of memory while copying the result, which leaves it empty
status util_fs_read_file(const char* path, MUTABLE REF util_string* into);

// Replaces into's text with the running executable's full path, e.g. "C:\games\bouncing2d.exe".
// STATUS_IO_ERROR when the OS can't tell; into is then unchanged
status util_fs_executable_path(MUTABLE REF util_string* into);
// Replaces into's text with the folder holding the running executable, without a trailing
// separator, e.g. "C:\games\bouncing2d". STATUS_IO_ERROR when the OS can't tell; into is then
// unchanged
status util_fs_executable_folder(MUTABLE REF util_string* into);

// Removes a file; STATUS_NOT_FOUND when there is no file at path (also when it is a folder)
status util_fs_remove_file(const char* path);
// Removes an empty folder; STATUS_NOT_FOUND when there is no folder at path, STATUS_IO_ERROR when
// it is not empty
status util_fs_remove_folder(const char* path);

#endif // UTIL_FS_H
