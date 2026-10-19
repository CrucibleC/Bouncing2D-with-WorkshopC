#ifndef UTIL_SINGLETON_H
#define UTIL_SINGLETON_H

#include <stddef.h>

#include "status.h"
#include "workshopc_tags.h"

// Starting and shutting down subsystems: modules with module-level (singleton) state, see the
// static-raii skill. Each such module exposes one function returning its util_singleton_subsystem,
// e.g. util_log_subsystem(), and the app lists them in the order they must start:
//
//     util_singleton_subsystem subsystems[2] = { util_log_subsystem(), util_random_subsystem() };
//     util_singleton_subsystem_span span = util_singleton_subsystem_span_pod(subsystems, 2);
//     status result = util_singleton_subsystem_init_all(span);
//     if (result == STATUS_OK) { ... }
//     util_singleton_subsystem_shutdown_all(span);   // always: undoes exactly what was started

// A subsystem's start: STATUS_OK, or why it failed
typedef status (*util_singleton_subsystem_init_func)(void);
// A subsystem's shutdown; only called when its init succeeded
typedef void (*util_singleton_subsystem_shutdown_func)(void);

// One subsystem's init and shutdown, and what its init returned
typedef struct util_singleton_subsystem
{
    util_singleton_subsystem_init_func init;           // NULL: nothing to start
    util_singleton_subsystem_shutdown_func shutdown;   // NULL: nothing to shut down
    status result;                                     // STATUS_INVALID_STATE while not started
} util_singleton_subsystem;

// { .init = init, .shutdown = shutdown, .result = STATUS_INVALID_STATE }
util_singleton_subsystem util_singleton_subsystem_pod(util_singleton_subsystem_init_func init,
                                                      util_singleton_subsystem_shutdown_func shutdown);

typedef struct util_singleton_subsystem_span
{
    util_singleton_subsystem* data;
    size_t size;
} util_singleton_subsystem_span;

// { .data = data, .size = size }
util_singleton_subsystem_span util_singleton_subsystem_span_pod(borrows util_singleton_subsystem* data, size_t size);

// Starts the subsystems first to last, storing each one's result, and stops at the first that
// fails (later ones may depend on it): those after it stay STATUS_INVALID_STATE. Returns STATUS_OK,
// or the failing one's status
status util_singleton_subsystem_init_all(util_singleton_subsystem_span subsystems);
// Shuts down, last to first, exactly the subsystems whose init succeeded, and marks them
// STATUS_INVALID_STATE again, so calling it twice is harmless. Call it whatever init_all returned
void util_singleton_subsystem_shutdown_all(util_singleton_subsystem_span subsystems);

#endif // UTIL_SINGLETON_H
