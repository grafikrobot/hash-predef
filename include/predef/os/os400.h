/*
Copyright Rene Rivera 2011-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_OS_OS400_H
#define HASH_PREDEF_OS_OS400_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_OS_OS400`

http://en.wikipedia.org/wiki/IBM_i[IBM OS/400] operating system.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__OS400__+` | {predef_detection}
|===
*/ // end::reference[]

#define HASH_PREDEF_OS_OS400 HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(HASH_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(__OS400__) \
    )
#   undef HASH_PREDEF_OS_OS400
#   define HASH_PREDEF_OS_OS400 HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#if HASH_PREDEF_OS_OS400
#   define HASH_PREDEF_OS_OS400_AVAILABLE
#   include <predef/detail/os_detected.h>
#endif

#define HASH_PREDEF_OS_OS400_NAME "IBM OS/400"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_OS_OS400,HASH_PREDEF_OS_OS400_NAME)
