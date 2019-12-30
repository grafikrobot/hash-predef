/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_OS_IRIX_H
#define HASH_PREDEF_OS_IRIX_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_OS_IRIX`

http://en.wikipedia.org/wiki/Irix[IRIX] operating system.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `sgi` | {predef_detection}
| `+__sgi+` | {predef_detection}
|===
*/ // end::reference[]

#define HASH_PREDEF_OS_IRIX HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(HASH_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(sgi) || defined(__sgi) \
    )
#   undef HASH_PREDEF_OS_IRIX
#   define HASH_PREDEF_OS_IRIX HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#if HASH_PREDEF_OS_IRIX
#   define HASH_PREDEF_OS_IRIX_AVAILABLE
#   include <predef/detail/os_detected.h>
#endif

#define HASH_PREDEF_OS_IRIX_NAME "IRIX"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_OS_IRIX,HASH_PREDEF_OS_IRIX_NAME)
