/*
Copyright Rene Rivera 2013-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_ARCHITECTURE_BLACKFIN_H
#define HASH_PREDEF_ARCHITECTURE_BLACKFIN_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_ARCH_BLACKFIN`

Blackfin Processors from Analog Devices.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__bfin__+` | {predef_detection}
| `+__BFIN__+` | {predef_detection}
| `bfin` | {predef_detection}
| `BFIN` | {predef_detection}
|===
*/ // end::reference[]

#define HASH_PREDEF_ARCH_BLACKFIN HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__bfin__) || defined(__BFIN__) || \
    defined(bfin) || defined(BFIN)
#   undef HASH_PREDEF_ARCH_BLACKFIN
#   define HASH_PREDEF_ARCH_BLACKFIN HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#if HASH_PREDEF_ARCH_BLACKFIN
#   define HASH_PREDEF_ARCH_BLACKFIN_AVAILABLE
#endif

#if HASH_PREDEF_ARCH_BLACKFIN
#   undef HASH_PREDEF_ARCH_WORD_BITS_16
#   define HASH_PREDEF_ARCH_WORD_BITS_16 HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#define HASH_PREDEF_ARCH_BLACKFIN_NAME "Blackfin"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_ARCH_BLACKFIN,HASH_PREDEF_ARCH_BLACKFIN_NAME)
