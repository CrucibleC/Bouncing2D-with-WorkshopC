#ifndef STATUS_H
#define STATUS_H

// The app's result codes for exceptional failures. A function that can fail
// returns one. A raii struct keeps one in a private field, read with T_status.
typedef enum status
{
    STATUS_OK = 0,
    STATUS_INVALID_ARGUMENT,
    STATUS_OUT_OF_MEMORY,
    STATUS_OUT_OF_RANGE,
    STATUS_NOT_FOUND,
    STATUS_ALREADY_EXISTS,
    STATUS_IO_ERROR,
    STATUS_TIMEOUT,
    STATUS_UNSUPPORTED,
    STATUS_INVALID_STATE,
    STATUS_UNKNOWN_ERROR
} status;

// The code's name, e.g. "STATUS_OK"; a string literal, never NULL
const char* status_to_string(status value);

#endif // STATUS_H
