#ifndef COMPILER_H
#define COMPILER_H

// Compiler-specific attributes, named once here; they expand to nothing on compilers without them

// Lets GCC and Clang check a printf-style function's format string against its arguments.
// format_index is the format parameter's position (from 1), first_arg the position of the "...".
// On MinGW, "printf" means the old Microsoft rules (no %zu, and every later argument is then
// checked against the wrong conversion); UCRT implements C99 formats, so check those instead.
#if defined(__MINGW32__)
#define PRINTF_FORMAT(format_index, first_arg) __attribute__((format(gnu_printf, format_index, first_arg)))
#elif defined(__GNUC__) || defined(__clang__)
#define PRINTF_FORMAT(format_index, first_arg) __attribute__((format(printf, format_index, first_arg)))
#else
#define PRINTF_FORMAT(format_index, first_arg)
#endif

#endif // COMPILER_H
