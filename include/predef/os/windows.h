/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_OS_WINDOWS_H
#define HASH_PREDEF_OS_WINDOWS_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_OS_WINDOWS`

http://en.wikipedia.org/wiki/Category:Microsoft_Windows[Microsoft Windows] operating system.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+_WIN32+` | {predef_detection}
| `+_WIN64+` | {predef_detection}
| `+__WIN32__+` | {predef_detection}
| `+__TOS_WIN__+` | {predef_detection}
| `+__WINDOWS__+` | {predef_detection}
|===
*/ // end::reference[]

#define HASH_PREDEF_OS_WINDOWS HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(HASH_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(_WIN32) || defined(_WIN64) || \
    defined(__WIN32__) || defined(__TOS_WIN__) || \
    defined(__WINDOWS__) \
    )
#   undef HASH_PREDEF_OS_WINDOWS
#   define HASH_PREDEF_OS_WINDOWS HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#if HASH_PREDEF_OS_WINDOWS
#   define HASH_PREDEF_OS_WINDOWS_AVAILABLE
#   include <predef/detail/os_detected.h>
#endif

#define HASH_PREDEF_OS_WINDOWS_NAME "Microsoft Windows"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_OS_WINDOWS,HASH_PREDEF_OS_WINDOWS_NAME)
