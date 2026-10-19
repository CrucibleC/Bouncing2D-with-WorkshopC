// SPDX-License-Identifier: MIT-0
// Copyright 2026 CrucibleC. Free to use, copy, modify and share for any purpose,
// without conditions. This does not apply to WorkshopC itself.

#ifndef CRUCIBLEC_WORKSHOPC_PRIVATE_TAG_LOWER_H
#define CRUCIBLEC_WORKSHOPC_PRIVATE_TAG_LOWER_H

// A field confined to the functions of its own struct:
//
//   struct item { confined int secret; };
//
// A macro replaces its name everywhere after this header, so include it
// after system and third party headers.

#ifdef WORKSHOPC_PARSING

#define confined __attribute__((annotate("workshopc_private_field")))

#else

#define confined

#endif

#endif // CRUCIBLEC_WORKSHOPC_PRIVATE_TAG_LOWER_H
