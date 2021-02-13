/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_ARCHITECTURE_PPC_H
#define HASH_PREDEF_ARCHITECTURE_PPC_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_ARCH_PPC`

http://en.wikipedia.org/wiki/PowerPC[PowerPC] architecture.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__powerpc+` | {predef_detection}
| `+__powerpc__+` | {predef_detection}
| `+__powerpc64__+` | {predef_detection}
| `+__POWERPC__+` | {predef_detection}
| `+__ppc__+` | {predef_detection}
| `+__ppc64__+` | {predef_detection}
| `+__PPC__+` | {predef_detection}
| `+__PPC64__+` | {predef_detection}
| `+_M_PPC+` | {predef_detection}
| `+_ARCH_PPC+` | {predef_detection}
| `+_ARCH_PPC64+` | {predef_detection}
| `+__PPCGECKO__+` | {predef_detection}
| `+__PPCBROADWAY__+` | {predef_detection}
| `+_XENON+` | {predef_detection}
| `+__ppc+` | {predef_detection}

| `+__ppc601__+` | 6.1.0
| `+_ARCH_601+` | 6.1.0
| `+__ppc603__+` | 6.3.0
| `+_ARCH_603+` | 6.3.0
| `+__ppc604__+` | 6.4.0
| `+__ppc604__+` | 6.4.0
|===
*/ // end::reference[]

#define HASH_PREDEF_ARCH_PPC HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__powerpc) || defined(__powerpc__) || defined(__powerpc64__) || \
    defined(__POWERPC__) || defined(__ppc__) || defined(__ppc64__) || \
    defined(__PPC__) || defined(__PPC64__) || \
    defined(_M_PPC) || defined(_ARCH_PPC) || defined(_ARCH_PPC64) || \
    defined(__PPCGECKO__) || defined(__PPCBROADWAY__) || \
    defined(_XENON) || \
    defined(__ppc)
#   undef HASH_PREDEF_ARCH_PPC
#   if !defined (HASH_PREDEF_ARCH_PPC) && (defined(__ppc601__) || defined(_ARCH_601))
#       define HASH_PREDEF_ARCH_PPC HASH_PREDEF_VERSION_NUMBER(6,1,0)
#   endif
#   if !defined (HASH_PREDEF_ARCH_PPC) && (defined(__ppc603__) || defined(_ARCH_603))
#       define HASH_PREDEF_ARCH_PPC HASH_PREDEF_VERSION_NUMBER(6,3,0)
#   endif
#   if !defined (HASH_PREDEF_ARCH_PPC) && (defined(__ppc604__) || defined(__ppc604__))
#       define HASH_PREDEF_ARCH_PPC HASH_PREDEF_VERSION_NUMBER(6,4,0)
#   endif
#   if !defined (HASH_PREDEF_ARCH_PPC)
#       define HASH_PREDEF_ARCH_PPC HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if HASH_PREDEF_ARCH_PPC
#   define HASH_PREDEF_ARCH_PPC_AVAILABLE
#endif

#define HASH_PREDEF_ARCH_PPC_NAME "PowerPC"


/* tag::reference[]
= `HASH_PREDEF_ARCH_PPC_64`

http://en.wikipedia.org/wiki/PowerPC[PowerPC] 64 bit architecture.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__powerpc64__+` | {predef_detection}
| `+__ppc64__+` | {predef_detection}
| `+__PPC64__+` | {predef_detection}
| `+_ARCH_PPC64+` | {predef_detection}
|===
*/ // end::reference[]

#define HASH_PREDEF_ARCH_PPC_64 HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__powerpc64__) || defined(__ppc64__) || defined(__PPC64__) || \
    defined(_ARCH_PPC64)
#   undef HASH_PREDEF_ARCH_PPC_64
#   define HASH_PREDEF_ARCH_PPC_64 HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#if HASH_PREDEF_ARCH_PPC_64
#   define HASH_PREDEF_ARCH_PPC_64_AVAILABLE
#endif

#define HASH_PREDEF_ARCH_PPC_64_NAME "PowerPC64"


#if HASH_PREDEF_ARCH_PPC_64
#   undef HASH_PREDEF_ARCH_WORD_BITS_64
#   define HASH_PREDEF_ARCH_WORD_BITS_64 HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#else
#   undef HASH_PREDEF_ARCH_WORD_BITS_32
#   define HASH_PREDEF_ARCH_WORD_BITS_32 HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_ARCH_PPC,HASH_PREDEF_ARCH_PPC_NAME)

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_ARCH_PPC_64,HASH_PREDEF_ARCH_PPC_64_NAME)
