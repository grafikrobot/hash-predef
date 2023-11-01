/*
Copyright Rene Rivera 2011-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_OS_VMS_H
#define HASH_PREDEF_OS_VMS_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_OS_VMS`

http://en.wikipedia.org/wiki/OpenVMS[VMS] operating system.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `VMS` | {predef_detection}
| `+__VMS+` | {predef_detection}

| `+__VMS_VER+` | V.R.P
|===
*/ // end::reference[]

#define HASH_PREDEF_OS_VMS HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(HASH_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(VMS) || defined(__VMS) \
    )
#   undef HASH_PREDEF_OS_VMS
#   if defined(__VMS_VER)
#       define HASH_PREDEF_OS_VMS HASH_PREDEF_MAKE_10_VVRR00PP00(__VMS_VER)
#   else
#       define HASH_PREDEF_OS_VMS HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if HASH_PREDEF_OS_VMS
#   define HASH_PREDEF_OS_VMS_AVAILABLE
#   include <predef/detail/os_detected.h>
#endif

#define HASH_PREDEF_OS_VMS_NAME "VMS"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_OS_VMS,HASH_PREDEF_OS_VMS_NAME)
