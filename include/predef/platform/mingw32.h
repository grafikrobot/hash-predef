/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_PLAT_MINGW32_H
#define HASH_PREDEF_PLAT_MINGW32_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_PLAT_MINGW32`

http://www.mingw.org/[MinGW] platform.
Version number available as major, minor, and patch.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__MINGW32__+` | {predef_detection}

| `+__MINGW32_VERSION_MAJOR+`, `+__MINGW32_VERSION_MINOR+` | V.R.0
|===
*/ // end::reference[]

#define HASH_PREDEF_PLAT_MINGW32 HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__MINGW32__)
#   include <_mingw.h>
#   if !defined(HASH_PREDEF_PLAT_MINGW32_DETECTION) && (defined(__MINGW32_VERSION_MAJOR) && defined(__MINGW32_VERSION_MINOR))
#       define HASH_PREDEF_PLAT_MINGW32_DETECTION \
            HASH_PREDEF_VERSION_NUMBER(__MINGW32_VERSION_MAJOR,__MINGW32_VERSION_MINOR,0)
#   endif
#   if !defined(HASH_PREDEF_PLAT_MINGW32_DETECTION)
#       define HASH_PREDEF_PLAT_MINGW32_DETECTION HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef HASH_PREDEF_PLAT_MINGW32_DETECTION
#   define HASH_PREDEF_PLAT_MINGW32_AVAILABLE
#   if defined(HASH_PREDEF_DETAIL_PLAT_DETECTED)
#       define HASH_PREDEF_PLAT_MINGW32_EMULATED HASH_PREDEF_PLAT_MINGW32_DETECTION
#   else
#       undef HASH_PREDEF_PLAT_MINGW32
#       define HASH_PREDEF_PLAT_MINGW32 HASH_PREDEF_PLAT_MINGW32_DETECTION
#   endif
#   include <predef/detail/platform_detected.h>
#endif

#define HASH_PREDEF_PLAT_MINGW32_NAME "MinGW"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_PLAT_MINGW32,HASH_PREDEF_PLAT_MINGW32_NAME)

#ifdef HASH_PREDEF_PLAT_MINGW32_EMULATED
#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_PLAT_MINGW32_EMULATED,HASH_PREDEF_PLAT_MINGW32_NAME)
#endif
