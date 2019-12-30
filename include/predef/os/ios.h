/*
Copyright Franz Detro 2014
Copyright Rene Rivera 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_OS_IOS_H
#define HASH_PREDEF_OS_IOS_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_OS_IOS`

http://en.wikipedia.org/wiki/iOS[iOS] operating system.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__APPLE__+` | {predef_detection}
| `+__MACH__+` | {predef_detection}
| `+__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__+` | {predef_detection}

| `+__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__+` | +__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__+*1000
|===
*/ // end::reference[]

#define HASH_PREDEF_OS_IOS HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(HASH_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(__APPLE__) && defined(__MACH__) && \
    defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__) \
    )
#   undef HASH_PREDEF_OS_IOS
#   define HASH_PREDEF_OS_IOS (__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__*1000)
#endif

#if HASH_PREDEF_OS_IOS
#   define HASH_PREDEF_OS_IOS_AVAILABLE
#   include <predef/detail/os_detected.h>
#endif

#define HASH_PREDEF_OS_IOS_NAME "iOS"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_OS_IOS,HASH_PREDEF_OS_IOS_NAME)
