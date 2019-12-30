/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_OS_LINUX_H
#define HASH_PREDEF_OS_LINUX_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_OS_LINUX`

http://en.wikipedia.org/wiki/Linux[Linux] operating system.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `linux` | {predef_detection}
| `+__linux+` | {predef_detection}
| `+__linux__+` | {predef_detection}
| `+__gnu_linux__+` | {predef_detection}
|===
*/ // end::reference[]

#define HASH_PREDEF_OS_LINUX HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(HASH_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(linux) || defined(__linux) || \
    defined(__linux__) || defined(__gnu_linux__) \
    )
#   undef HASH_PREDEF_OS_LINUX
#   define HASH_PREDEF_OS_LINUX HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#if HASH_PREDEF_OS_LINUX
#   define HASH_PREDEF_OS_LINUX_AVAILABLE
#   include <predef/detail/os_detected.h>
#endif

#define HASH_PREDEF_OS_LINUX_NAME "Linux"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_OS_LINUX,HASH_PREDEF_OS_LINUX_NAME)
