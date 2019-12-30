/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_OS_AMIGAOS_H
#define HASH_PREDEF_OS_AMIGAOS_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_OS_AMIGAOS`

http://en.wikipedia.org/wiki/AmigaOS[AmigaOS] operating system.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `AMIGA` | {predef_detection}
| `+__amigaos__+` | {predef_detection}
|===
*/ // end::reference[]

#define HASH_PREDEF_OS_AMIGAOS HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(HASH_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(AMIGA) || defined(__amigaos__) \
    )
#   undef HASH_PREDEF_OS_AMIGAOS
#   define HASH_PREDEF_OS_AMIGAOS HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#if HASH_PREDEF_OS_AMIGAOS
#   define HASH_PREDEF_OS_AMIGAOS_AVAILABLE
#   include <predef/detail/os_detected.h>
#endif

#define HASH_PREDEF_OS_AMIGAOS_NAME "AmigaOS"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_OS_AMIGAOS,HASH_PREDEF_OS_AMIGAOS_NAME)
