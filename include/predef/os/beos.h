/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_OS_BEOS_H
#define HASH_PREDEF_OS_BEOS_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_OS_BEOS`

http://en.wikipedia.org/wiki/BeOS[BeOS] operating system.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__BEOS__+` | {predef_detection}
|===
*/ // end::reference[]

#define HASH_PREDEF_OS_BEOS HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(HASH_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(__BEOS__) \
    )
#   undef HASH_PREDEF_OS_BEOS
#   define HASH_PREDEF_OS_BEOS HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#if HASH_PREDEF_OS_BEOS
#   define HASH_PREDEF_OS_BEOS_AVAILABLE
#   include <predef/detail/os_detected.h>
#endif

#define HASH_PREDEF_OS_BEOS_NAME "BeOS"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_OS_BEOS,HASH_PREDEF_OS_BEOS_NAME)
