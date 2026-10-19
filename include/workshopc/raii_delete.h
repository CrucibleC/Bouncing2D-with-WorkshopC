// SPDX-License-Identifier: MIT-0
// Copyright 2026 CrucibleC. Free to use, copy, modify and share for any purpose,
// without conditions. This does not apply to WorkshopC itself.

#ifndef CRUCIBLEC_WORKSHOPC_RAII_DELETE_LOWER_H
#define CRUCIBLEC_WORKSHOPC_RAII_DELETE_LOWER_H

// Deletes a raii lifecycle function that has no good implementation, or that
// is not needed yet. WorkshopC sees the declaration, and the real build gets
// a static assert instead, so any call to the function fails to compile:
//
//   NO_COPY(mutex);
//
// The names use the default suffixes _copy, _move and _return: change them
// when the WorkshopC config uses others. _make, _destroy and _valid can never
// be deleted.

#include <assert.h>

#include "move_tags.h"

#ifdef WORKSHOPC_PARSING

#define NO_COPY(type)   type type##_copy(const type* self)
#define NO_MOVE(type)   type type##_move(MUTABLE type* self)
#define NO_RETURN(type) type type##_return(MUTABLE type* self)

#else

#define NO_COPY(type)   static_assert(1, #type "_copy is deleted")
#define NO_MOVE(type)   static_assert(1, #type "_move is deleted")
#define NO_RETURN(type) static_assert(1, #type "_return is deleted")

#endif

#endif // CRUCIBLEC_WORKSHOPC_RAII_DELETE_LOWER_H
