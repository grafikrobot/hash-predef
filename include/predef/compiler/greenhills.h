/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_COMPILER_GREENHILLS_H
#define HASH_PREDEF_COMPILER_GREENHILLS_H

#include <predef/version_number.h>
#include <predef/make.h>

/*`
[heading `HASH_PREDEF_COMP_GHS`]

[@http://en.wikipedia.org/wiki/Green_Hills_Software Green Hills C/C++] compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__ghs`] [__predef_detection__]]
    [[`__ghs__`] [__predef_detection__]]

    [[`__GHS_VERSION_NUMBER__`] [V.R.P]]
    [[`__ghs`] [V.R.P]]
    ]
 */

#define HASH_PREDEF_COMP_GHS HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__ghs) || defined(__ghs__)
#   if !defined(HASH_PREDEF_COMP_GHS_DETECTION) && defined(__GHS_VERSION_NUMBER__)
#       define HASH_PREDEF_COMP_GHS_DETECTION HASH_PREDEF_MAKE_10_VRP(__GHS_VERSION_NUMBER__)
#   endif
#   if !defined(HASH_PREDEF_COMP_GHS_DETECTION) && defined(__ghs)
#       define HASH_PREDEF_COMP_GHS_DETECTION HASH_PREDEF_MAKE_10_VRP(__ghs)
#   endif
#   if !defined(HASH_PREDEF_COMP_GHS_DETECTION)
#       define HASH_PREDEF_COMP_GHS_DETECTION HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef HASH_PREDEF_COMP_GHS_DETECTION
#   if defined(HASH_PREDEF_DETAIL_COMP_DETECTED)
#       define HASH_PREDEF_COMP_GHS_EMULATED HASH_PREDEF_COMP_GHS_DETECTION
#   else
#       undef HASH_PREDEF_COMP_GHS
#       define HASH_PREDEF_COMP_GHS HASH_PREDEF_COMP_GHS_DETECTION
#   endif
#   define HASH_PREDEF_COMP_GHS_AVAILABLE
#   include <predef/detail/comp_detected.h>
#endif

#define HASH_PREDEF_COMP_GHS_NAME "Green Hills C/C++"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_GHS,HASH_PREDEF_COMP_GHS_NAME)

#ifdef HASH_PREDEF_COMP_GHS_EMULATED
#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_GHS_EMULATED,HASH_PREDEF_COMP_GHS_NAME)
#endif
