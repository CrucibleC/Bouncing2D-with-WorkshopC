// SPDX-License-Identifier: MIT-0
// Copyright 2026 CrucibleC. Free to use, copy, modify and share for any purpose,
// without conditions. This does not apply to WorkshopC itself.

#ifndef CRUCIBLEC_WORKSHOPC_REFERENCE_TAG_H
#define CRUCIBLEC_WORKSHOPC_REFERENCE_TAG_H

#ifdef WORKSHOPC_PARSING

#define REF __attribute__((annotate("workshopc_reference_pointer")))

#else

#define REF

#endif

#endif // CRUCIBLEC_WORKSHOPC_REFERENCE_TAG_H