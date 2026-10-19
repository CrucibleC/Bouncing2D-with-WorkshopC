#include "util/log.h"

#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "numbers.h"
#include "span.h"
#include "util/fs.h"
#include "util/string.h"
#include "workshopc_tags.h"

// Logging never allocates, so it works before setup, after shutdown and when memory runs out:
// lines are built in a stack buffer and the file path lives in a fixed array.

// "2026-10-15 14:03:07 " plus its '\0'
#define UTIL_LOG_STAMP_SIZE 32
// Longest message plus its '\0', without the timestamp and level; longer ones are cut and end in "..."
#define UTIL_LOG_MESSAGE_SIZE 1024
// Longest "file:line: " plus its '\0'; a longer one is cut
#define UTIL_LOG_LOCATION_SIZE 256
// A whole line: timestamp, "[LEVEL] ", location, message, "...", "\n" and '\0'
#define UTIL_LOG_LINE_SIZE (UTIL_LOG_STAMP_SIZE + 8 + UTIL_LOG_LOCATION_SIZE + UTIL_LOG_MESSAGE_SIZE + 5)
// Longest log file path plus its '\0' (Linux's PATH_MAX)
#define UTIL_LOG_PATH_SIZE 4096

// The settings, changed only through the setters. The defaults: terminal on, every level, no file
static bool g_log_terminal = true;
static util_log_level g_log_min_level = UTIL_LOG_LEVEL_DEBUG;
// The log file's path, "" for none. A fixed array: a global can't own heap memory (a raii value)
static char g_log_file_path[UTIL_LOG_PATH_SIZE] = { 0 };
static char_span g_log_file_path_span = { .data = g_log_file_path, .size = UTIL_LOG_PATH_SIZE };

static const char* util_log_tag(util_log_level level)
{
    const char* tag = "?????";
    switch (level)
    {
        case UTIL_LOG_LEVEL_DEBUG:
            tag = "DEBUG";
            break;
        case UTIL_LOG_LEVEL_INFO:
            tag = "INFO ";
            break;
        case UTIL_LOG_LEVEL_WARN:
            tag = "WARN ";
            break;
        case UTIL_LOG_LEVEL_ERROR:
            tag = "ERROR";
            break;
        default:
            break;
    }
    return tag;
}

// The part of file after the last "src/" (or "src\"), e.g. "util/fs.c"; all of file when it has none
static const char* util_log_short_file(const char* file)
{
    if (file == NULL)
    {
        return NULL;
    }
    const char* result = file;
    size_t length = strlen(file);
    for (size_t i = 0; i + 4 <= length; i++)
    {
        bool folder_start = i == 0 || file[i - 1] == '/' || file[i - 1] == '\\';
        bool src_folder = strncmp(&file[i], "src", 3) == 0 && (file[i + 3] == '/' || file[i + 3] == '\\');
        if (folder_start && src_folder)
        {
            result = &file[i + 4];
        }
    }
    return result;
}

static void util_log_vwrite(util_log_level level, const char* source_file, i32 source_line, const char* format,
                            borrows va_list args)
{
    bool to_file = g_log_file_path_span.data[0] != '\0';
    if (format == NULL || level < g_log_min_level || (!g_log_terminal && !to_file))
    {
        return;
    }
    char line[UTIL_LOG_LINE_SIZE] = { 0 };
    char_span line_span = char_span_pod(line, sizeof line);
    size_t used = 0;

    // "YYYY-MM-DD hh:mm:ss ", or nothing when the local time is unknown
    time_t now = time(NULL);
    const struct tm* local = localtime(&now);
    if (local != NULL)
    {
        used = strftime(line_span.data, UTIL_LOG_STAMP_SIZE, "%Y-%m-%d %H:%M:%S ", local);
    }

    i32 tag_length = snprintf(&line_span.data[used], line_span.size - used, "[%s] ", util_log_tag(level));
    used += tag_length > 0 ? cast_i32_to_size_t(tag_length) : 0;

    if (source_file != NULL)
    {
        i32 location_length = snprintf(&line_span.data[used], UTIL_LOG_LOCATION_SIZE, "%s:%" PRId32 ": ",
                                       util_log_short_file(source_file), source_line);
        used += location_length <= 0 ? 0
              : cast_i32_to_size_t(location_length) < UTIL_LOG_LOCATION_SIZE ? cast_i32_to_size_t(location_length)
              : UTIL_LOG_LOCATION_SIZE - 1;
    }

    // The message, cut to UTIL_LOG_MESSAGE_SIZE - 1 chars plus "..." when longer
    i32 length = vsnprintf(&line_span.data[used], UTIL_LOG_MESSAGE_SIZE, format, args);
    if (length < 0)
    {
        length = snprintf(&line_span.data[used], UTIL_LOG_MESSAGE_SIZE, "(invalid log format)");
    }
    bool cut = length >= 0 && cast_i32_to_size_t(length) >= UTIL_LOG_MESSAGE_SIZE;
    used += cut ? UTIL_LOG_MESSAGE_SIZE - 1 : (length > 0 ? cast_i32_to_size_t(length) : 0);
    (void)snprintf(&line_span.data[used], line_span.size - used, "%s\n", cut ? "..." : "");

    if (g_log_terminal)
    {
        (void)fputs(line_span.data, level >= UTIL_LOG_LEVEL_WARN ? stderr : stdout);
    }
    // Opened and closed per line, so every line is on disk even if the program crashes
    FILE* file = to_file ? fopen(g_log_file_path_span.data, "ab") : NULL;
    if (file != NULL)
    {
        (void)fputs(line_span.data, file);
        (void)fclose(file);
    }
}

void util_log_set_terminal(bool enabled)
{
    g_log_terminal = enabled;
}

status util_log_set_file(const char* path)
{
    if (path == NULL)
    {
        g_log_file_path_span.data[0] = '\0';
        return STATUS_OK;
    }
    if (strlen(path) >= g_log_file_path_span.size)
    {
        return STATUS_OUT_OF_RANGE;
    }
    // Appending nothing creates the file, and fails now rather than on every line
    status result = util_fs_append_file(path, "");
    if (result == STATUS_OK)
    {
        (void)snprintf(g_log_file_path_span.data, g_log_file_path_span.size, "%s", path);
    }
    return result;
}

// path without its extension: "C:\games\bouncing2d.exe" -> "C:\games\bouncing2d"
static void util_log_drop_extension(borrows massive util_string* path)
{
    const char* chars = util_string_c_str(path);
    size_t length = util_string_length(path);
    size_t dot = length;
    for (size_t i = 0; i < length; i++)
    {
        if (chars[i] == '.')
        {
            dot = i;
        }
        else if (chars[i] == '/' || chars[i] == '\\')
        {
            dot = length;   // a dot in a folder name is not an extension
        }
    }
    util_string_truncate(path, dot);
}

static status util_log_init(void)
{
    util_string path = util_string_make("");
    status result = util_fs_executable_path(&path);
    if (result == STATUS_OK)
    {
        util_log_drop_extension(&path);
        result = util_string_append(&path, ".log");
    }
    if (result == STATUS_OK)
    {
        result = util_log_set_file(util_string_c_str(&path));
    }
    if (result != STATUS_OK)
    {
        UTIL_LOG_WARN("no log file next to the executable: %s", status_to_string(result));
    }
    util_string_destroy(&path);
    return STATUS_OK;
}

static void util_log_shutdown(void)
{
    (void)util_log_set_file(NULL);
}

util_singleton_subsystem util_log_subsystem(void)
{
    return util_singleton_subsystem_pod(util_log_init, util_log_shutdown);
}

void util_log_set_min_level(util_log_level level)
{
    g_log_min_level = level;
}

void util_log_write(util_log_level level, const char* source_file, i32 source_line, const char* format, ...)
{
    va_list args = { 0 };
    va_start(args, format);
    util_log_vwrite(level, source_file, source_line, format, args);
    va_end(args);
}
