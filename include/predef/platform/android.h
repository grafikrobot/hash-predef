/*
Copyright Rene Rivera 2015-2019
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_PLAT_ANDROID_H
#define HASH_PREDEF_PLAT_ANDROID_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_PLAT_ANDROID`

http://en.wikipedia.org/wiki/Android_%28operating_system%29[Android] platform.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__ANDROID__+` | {predef_detection}
|===
*/ // end::reference[]

#define HASH_PREDEF_PLAT_ANDROID HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__ANDROID__)
#   undef HASH_PREDEF_PLAT_ANDROID
#   define HASH_PREDEF_PLAT_ANDROID HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#if HASH_PREDEF_PLAT_ANDROID
#   define HASH_PREDEF_PLAT_ANDROID_AVAILABLE
#   include <predef/detail/platform_detected.h>
#endif

#define HASH_PREDEF_PLAT_ANDROID_NAME "Android"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_PLAT_ANDROID,HASH_PREDEF_PLAT_ANDROID_NAME)
