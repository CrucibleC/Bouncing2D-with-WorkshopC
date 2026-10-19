#include "status.h"

const char* status_to_string(status value)
{
    const char* result = "STATUS_UNKNOWN";
    switch (value)
    {
        case STATUS_OK:
            result = "STATUS_OK";
            break;
        case STATUS_INVALID_ARGUMENT:
            result = "STATUS_INVALID_ARGUMENT";
            break;
        case STATUS_OUT_OF_MEMORY:
            result = "STATUS_OUT_OF_MEMORY";
            break;
        case STATUS_OUT_OF_RANGE:
            result = "STATUS_OUT_OF_RANGE";
            break;
        case STATUS_NOT_FOUND:
            result = "STATUS_NOT_FOUND";
            break;
        case STATUS_ALREADY_EXISTS:
            result = "STATUS_ALREADY_EXISTS";
            break;
        case STATUS_IO_ERROR:
            result = "STATUS_IO_ERROR";
            break;
        case STATUS_TIMEOUT:
            result = "STATUS_TIMEOUT";
            break;
        case STATUS_UNSUPPORTED:
            result = "STATUS_UNSUPPORTED";
            break;
        case STATUS_INVALID_STATE:
            result = "STATUS_INVALID_STATE";
            break;
        case STATUS_UNKNOWN_ERROR:
            result = "STATUS_UNKNOWN_ERROR";
            break;
        default:
            break;
    }
    return result;
}
