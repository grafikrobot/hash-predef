/*
Copyright Jessica Hamilton 2014
Copyright Rene Rivera 2014-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_OS_HAIKU_H
#define HASH_PREDEF_OS_HAIKU_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_OS_HAIKU`

http://en.wikipedia.org/wiki/Haiku_(operating_system)[Haiku] operating system.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__HAIKU__+` | {predef_detection}
|===
*/ // end::reference[]

#define HASH_PREDEF_OS_HAIKU HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(HASH_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(__HAIKU__) \
    )
#   undef HASH_PREDEF_OS_HAIKU
#   define HASH_PREDEF_OS_HAIKU HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#if HASH_PREDEF_OS_HAIKU
#   define HASH_PREDEF_OS_HAIKU_AVAILABLE
#   include <predef/detail/os_detected.h>
#endif

#define HASH_PREDEF_OS_HAIKU_NAME "Haiku"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_OS_HAIKU,HASH_PREDEF_OS_HAIKU_NAME)
