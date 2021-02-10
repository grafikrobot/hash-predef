/*
Copyright Konstantin Ivlev 2021
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_ARCHITECTURE_E2K_H
#define HASH_PREDEF_ARCHITECTURE_E2K_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_ARCH_E2K`

https://en.wikipedia.org/wiki/Elbrus_2000[E2K] architecture.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__e2k__+` | {predef_detection}

| `+__e2k__+` | V.0.0
|===
*/ // end::reference[]

#define HASH_PREDEF_ARCH_E2K HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__e2k__)
#   undef HASH_PREDEF_ARCH_E2K
#   if !defined(HASH_PREDEF_ARCH_E2K) && defined(__iset__)
#       define HASH_PREDEF_ARCH_E2K HASH_PREDEF_VERSION_NUMBER(__iset__,0,0)
#   endif
#   if !defined(HASH_PREDEF_ARCH_E2K)
#       define HASH_PREDEF_ARCH_E2K HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if HASH_PREDEF_ARCH_E2K
#   define HASH_PREDEF_ARCH_E2K_AVAILABLE
#endif

#if HASH_PREDEF_ARCH_E2K
#   define HASH_PREDEF_ARCH_WORD_BITS_64 HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#define HASH_PREDEF_ARCH_E2K_NAME "E2K"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_ARCH_E2K,HASH_PREDEF_ARCH_E2K_NAME)
