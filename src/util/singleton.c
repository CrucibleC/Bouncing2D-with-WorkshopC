#include "util/singleton.h"

#include "workshopc_tags.h"

util_singleton_subsystem util_singleton_subsystem_pod(util_singleton_subsystem_init_func init,
                                                      util_singleton_subsystem_shutdown_func shutdown)
{
    return (util_singleton_subsystem){ .init = init, .shutdown = shutdown, .result = STATUS_INVALID_STATE };
}

util_singleton_subsystem_span util_singleton_subsystem_span_pod(MUTABLE util_singleton_subsystem* data, size_t size)
{
    return (util_singleton_subsystem_span){ .data = data, .size = size };
}

status util_singleton_subsystem_init_all(util_singleton_subsystem_span subsystems)
{
    status result = STATUS_OK;
    if (subsystems.data == NULL)
    {
        return result;
    }
    for (size_t i = 0; i < subsystems.size; i++)
    {
        subsystems.data[i].result = STATUS_INVALID_STATE;
    }
    for (size_t i = 0; i < subsystems.size && result == STATUS_OK; i++)
    {
        util_singleton_subsystem_init_func init = subsystems.data[i].init;
        result = init != NULL ? init() : STATUS_OK;
        subsystems.data[i].result = result;
    }
    return result;
}

void util_singleton_subsystem_shutdown_all(util_singleton_subsystem_span subsystems)
{
    if (subsystems.data == NULL)
    {
        return;
    }
    for (size_t i = subsystems.size; i > 0; i--)
    {
        util_singleton_subsystem_shutdown_func shutdown = subsystems.data[i - 1].shutdown;
        if (subsystems.data[i - 1].result == STATUS_OK && shutdown != NULL)
        {
            shutdown();
        }
        subsystems.data[i - 1].result = STATUS_INVALID_STATE;
    }
}
