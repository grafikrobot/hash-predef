/*
Copyright Rene Rivera 2008-2021
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_ARCHITECTURE_X86_64_H
#define HASH_PREDEF_ARCHITECTURE_X86_64_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_ARCH_X86_64`

https://en.wikipedia.org/wiki/X86-64[X86-64] architecture.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__x86_64+` | {predef_detection}
| `+__x86_64__+` | {predef_detection}
| `+__amd64__+` | {predef_detection}
| `+__amd64+` | {predef_detection}
| `+_M_X64+` | {predef_detection}
|===
*/ // end::reference[]

#define HASH_PREDEF_ARCH_X86_64 HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__x86_64) || defined(__x86_64__) || \
    defined(__amd64__) || defined(__amd64) || \
    defined(_M_X64)
#   undef HASH_PREDEF_ARCH_X86_64
#   define HASH_PREDEF_ARCH_X86_64 HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#if HASH_PREDEF_ARCH_X86_64
#   define HASH_PREDEF_ARCH_X86_64_AVAILABLE
#endif

#if HASH_PREDEF_ARCH_X86_64
#   undef HASH_PREDEF_ARCH_WORD_BITS_64
#   define HASH_PREDEF_ARCH_WORD_BITS_64 HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#define HASH_PREDEF_ARCH_X86_64_NAME "Intel x86-64"

#include <predef/architecture/x86.h>

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_ARCH_X86_64,HASH_PREDEF_ARCH_X86_64_NAME)
