/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_ARCHITECTURE_SUPERH_H
#define HASH_PREDEF_ARCHITECTURE_SUPERH_H

#include <predef/version_number.h>
#include <predef/make.h>

/*`
[heading `HASH_PREDEF_ARCH_SH`]

[@http://en.wikipedia.org/wiki/SuperH SuperH] architecture:
If available versions \[1-5\] are specifically detected.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__sh__`] [__predef_detection__]]

    [[`__SH5__`] [5.0.0]]
    [[`__SH4__`] [4.0.0]]
    [[`__sh3__`] [3.0.0]]
    [[`__SH3__`] [3.0.0]]
    [[`__sh2__`] [2.0.0]]
    [[`__sh1__`] [1.0.0]]
    ]
 */

#define HASH_PREDEF_ARCH_SH HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__sh__)
#   undef HASH_PREDEF_ARCH_SH
#   if !defined(HASH_PREDEF_ARCH_SH) && (defined(__SH5__))
#       define HASH_PREDEF_ARCH_SH HASH_PREDEF_VERSION_NUMBER(5,0,0)
#   endif
#   if !defined(HASH_PREDEF_ARCH_SH) && (defined(__SH4__))
#       define HASH_PREDEF_ARCH_SH HASH_PREDEF_VERSION_NUMBER(4,0,0)
#   endif
#   if !defined(HASH_PREDEF_ARCH_SH) && (defined(__sh3__) || defined(__SH3__))
#       define HASH_PREDEF_ARCH_SH HASH_PREDEF_VERSION_NUMBER(3,0,0)
#   endif
#   if !defined(HASH_PREDEF_ARCH_SH) && (defined(__sh2__))
#       define HASH_PREDEF_ARCH_SH HASH_PREDEF_VERSION_NUMBER(2,0,0)
#   endif
#   if !defined(HASH_PREDEF_ARCH_SH) && (defined(__sh1__))
#       define HASH_PREDEF_ARCH_SH HASH_PREDEF_VERSION_NUMBER(1,0,0)
#   endif
#   if !defined(HASH_PREDEF_ARCH_SH)
#       define HASH_PREDEF_ARCH_SH HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if HASH_PREDEF_ARCH_SH
#   define HASH_PREDEF_ARCH_SH_AVAILABLE
#endif

#define HASH_PREDEF_ARCH_SH_NAME "SuperH"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_ARCH_SH,HASH_PREDEF_ARCH_SH_NAME)
