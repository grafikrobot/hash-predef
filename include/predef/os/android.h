/*
Copyright Rene Rivera 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_OS_ANDROID_H
#define HASH_PREDEF_OS_ANDROID_H

#include <predef/version_number.h>
#include <predef/make.h>

/*`
[heading `HASH_PREDEF_OS_ANDROID`]

NOTE: `HASH_PREDEF_OS_ANDROID` is deprecated, and will be removed in a following release.
Please use `HASH_PREDEF_PLAT_ANDROID` instead.

[@http://en.wikipedia.org/wiki/Android_%28operating_system%29 Android] operating system.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__ANDROID__`] [__predef_detection__]]
    ]
 */

#define HASH_PREDEF_OS_ANDROID HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(HASH_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(__ANDROID__) \
    )
#   undef HASH_PREDEF_OS_ANDROID
#   define HASH_PREDEF_OS_ANDROID HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#if HASH_PREDEF_OS_ANDROID
#   define HASH_PREDEF_OS_ANDROID_AVAILABLE
#   include <predef/detail/os_detected.h>
#endif

#define HASH_PREDEF_OS_ANDROID_NAME "Android"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_OS_ANDROID,HASH_PREDEF_OS_ANDROID_NAME)
