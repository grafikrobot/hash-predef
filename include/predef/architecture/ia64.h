/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_ARCHITECTURE_IA64_H
#define HASH_PREDEF_ARCHITECTURE_IA64_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_ARCH_IA64`

http://en.wikipedia.org/wiki/Ia64[Intel Itanium 64] architecture.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__ia64__+` | {predef_detection}
| `+_IA64+` | {predef_detection}
| `+__IA64__+` | {predef_detection}
| `+__ia64+` | {predef_detection}
| `+_M_IA64+` | {predef_detection}
| `+__itanium__+` | {predef_detection}
|===
*/ // end::reference[]

#define HASH_PREDEF_ARCH_IA64 HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__ia64__) || defined(_IA64) || \
    defined(__IA64__) || defined(__ia64) || \
    defined(_M_IA64) || defined(__itanium__)
#   undef HASH_PREDEF_ARCH_IA64
#   define HASH_PREDEF_ARCH_IA64 HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#if HASH_PREDEF_ARCH_IA64
#   define HASH_PREDEF_ARCH_IA64_AVAILABLE
#endif

#if HASH_PREDEF_ARCH_IA64
#   undef HASH_PREDEF_ARCH_WORD_BITS_64
#   define HASH_PREDEF_ARCH_WORD_BITS_64 HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#define HASH_PREDEF_ARCH_IA64_NAME "Intel Itanium 64"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_ARCH_IA64,HASH_PREDEF_ARCH_IA64_NAME)
