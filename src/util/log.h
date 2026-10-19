#ifndef UTIL_LOG_H
#define UTIL_LOG_H

#include <stdbool.h>

#include "compiler.h"
#include "numbers.h"
#include "status.h"
#include "util/singleton.h"

// A logger with levels, source locations and printf-style messages. Log through the macros:
//     UTIL_LOG_WARN("slow frame: %.1f ms", ms);
// Each line looks like
//     2026-10-15 14:03:07 [WARN ] core/world.c:88: slow frame: 20.5 ms
// (the file is shortened to the part after the last "src/") and goes to the terminal (WARN and
// ERROR to stderr, the rest to stdout), to a file, or both.
// Defaults (set in log.c): terminal on, no file, every level. Nothing touches the disk until
// util_log_set_file is called or util_log_subsystem() is started. A log call never allocates and
// never fails (errors are ignored). Not thread-safe.

typedef enum util_log_level
{
    UTIL_LOG_LEVEL_DEBUG,
    UTIL_LOG_LEVEL_INFO,
    UTIL_LOG_LEVEL_WARN,
    UTIL_LOG_LEVEL_ERROR
} util_log_level;

// Log with the caller's file and line. The format is part of the "...", so a call without
// arguments, UTIL_LOG_INFO("text"), is standard C as well
#define UTIL_LOG_DEBUG(...) util_log_write(UTIL_LOG_LEVEL_DEBUG, __FILE__, __LINE__, __VA_ARGS__)
#define UTIL_LOG_INFO(...) util_log_write(UTIL_LOG_LEVEL_INFO, __FILE__, __LINE__, __VA_ARGS__)
#define UTIL_LOG_WARN(...) util_log_write(UTIL_LOG_LEVEL_WARN, __FILE__, __LINE__, __VA_ARGS__)
#define UTIL_LOG_ERROR(...) util_log_write(UTIL_LOG_LEVEL_ERROR, __FILE__, __LINE__, __VA_ARGS__)

// The one logging function, normally called through the macros above. source_file and source_line
// say where the call is; a NULL source_file leaves the location out
void util_log_write(util_log_level level, const char* source_file, i32 source_line, const char* format, ...)
    PRINTF_FORMAT(4, 5);

// The logger as a subsystem for util_singleton_subsystem_init_all. Its init logs to a file next to
// the executable, named after it (bouncing2d.exe -> bouncing2d.log); it never fails: when the file
// can't be set up it warns on the terminal and succeeds anyway, since terminal logging keeps
// working. Its shutdown turns file output off
util_singleton_subsystem util_log_subsystem(void);

// Turns terminal output on or off
void util_log_set_terminal(bool enabled);
// Appends every following line to the file at path, creating it if missing; NULL turns file output
// off. STATUS_NOT_FOUND when the folder is missing, STATUS_OUT_OF_RANGE for paths of 4096 chars or
// more; on failure the previous setting stays. Each line opens and closes the file, so it is on disk
// right away, even if the program crashes
status util_log_set_file(const char* path);
// Drops lines below level
void util_log_set_min_level(util_log_level level);

#endif // UTIL_LOG_H
