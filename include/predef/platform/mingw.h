/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_PLAT_MINGW_H
#define HASH_PREDEF_PLAT_MINGW_H

#include <predef/version_number.h>
#include <predef/make.h>

/*`
[heading `HASH_PREDEF_PLAT_MINGW`]

[@http://en.wikipedia.org/wiki/MinGW MinGW] platform, either variety.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__MINGW32__`] [__predef_detection__]]
    [[`__MINGW64__`] [__predef_detection__]]

    [[`__MINGW64_VERSION_MAJOR`, `__MINGW64_VERSION_MINOR`] [V.R.0]]
    [[`__MINGW32_VERSION_MAJOR`, `__MINGW32_VERSION_MINOR`] [V.R.0]]
    ]
 */

#define HASH_PREDEF_PLAT_MINGW HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__MINGW32__) || defined(__MINGW64__)
#   include <_mingw.h>
#   if !defined(HASH_PREDEF_PLAT_MINGW_DETECTION) && (defined(__MINGW64_VERSION_MAJOR) && defined(__MINGW64_VERSION_MINOR))
#       define HASH_PREDEF_PLAT_MINGW_DETECTION \
            HASH_PREDEF_VERSION_NUMBER(__MINGW64_VERSION_MAJOR,__MINGW64_VERSION_MINOR,0)
#   endif
#   if !defined(HASH_PREDEF_PLAT_MINGW_DETECTION) && (defined(__MINGW32_VERSION_MAJOR) && defined(__MINGW32_VERSION_MINOR))
#       define HASH_PREDEF_PLAT_MINGW_DETECTION \
            HASH_PREDEF_VERSION_NUMBER(__MINGW32_MAJOR_VERSION,__MINGW32_MINOR_VERSION,0)
#   endif
#   if !defined(HASH_PREDEF_PLAT_MINGW_DETECTION)
#       define HASH_PREDEF_PLAT_MINGW_DETECTION HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef HASH_PREDEF_PLAT_MINGW_DETECTION
#   define HASH_PREDEF_PLAT_MINGW_AVAILABLE
#   if defined(HASH_PREDEF_DETAIL_PLAT_DETECTED)
#       define HASH_PREDEF_PLAT_MINGW_EMULATED HASH_PREDEF_PLAT_MINGW_DETECTION
#   else
#       undef HASH_PREDEF_PLAT_MINGW
#       define HASH_PREDEF_PLAT_MINGW HASH_PREDEF_PLAT_MINGW_DETECTION
#   endif
#   include <predef/detail/platform_detected.h>
#endif

#define HASH_PREDEF_PLAT_MINGW_NAME "MinGW (any variety)"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_PLAT_MINGW,HASH_PREDEF_PLAT_MINGW_NAME)

#ifdef HASH_PREDEF_PLAT_MINGW_EMULATED
#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_PLAT_MINGW_EMULATED,HASH_PREDEF_PLAT_MINGW_NAME)
#endif
