/*
Copyright Rene Rivera 2011-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_ARCHITECTURE_PYRAMID_H
#define HASH_PREDEF_ARCHITECTURE_PYRAMID_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_ARCH_PYRAMID`

Pyramid 9810 architecture.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `pyr` | {predef_detection}
|===
*/ // end::reference[]

#define HASH_PREDEF_ARCH_PYRAMID HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(pyr)
#   undef HASH_PREDEF_ARCH_PYRAMID
#   define HASH_PREDEF_ARCH_PYRAMID HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#if HASH_PREDEF_ARCH_PYRAMID
#   define HASH_PREDEF_ARCH_PYRAMID_AVAILABLE
#endif

#if HASH_PREDEF_ARCH_PYRAMID
#   undef HASH_PREDEF_ARCH_WORD_BITS_32
#   define HASH_PREDEF_ARCH_WORD_BITS_32 HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#define HASH_PREDEF_ARCH_PYRAMID_NAME "Pyramid 9810"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_ARCH_PYRAMID,HASH_PREDEF_ARCH_PYRAMID_NAME)
