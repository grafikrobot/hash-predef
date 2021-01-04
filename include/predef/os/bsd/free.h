/*
Copyright Rene Rivera 2012-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_OS_BSD_FREE_H
#define HASH_PREDEF_OS_BSD_FREE_H

#include <predef/os/bsd.h>

/* tag::reference[]
= `HASH_PREDEF_OS_BSD_FREE`

http://en.wikipedia.org/wiki/Freebsd[FreeBSD] operating system.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__FreeBSD__+` | {predef_detection}

| `+__FreeBSD_version+` | V.R.P
|===
*/ // end::reference[]

#define HASH_PREDEF_OS_BSD_FREE HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(HASH_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(__FreeBSD__) \
    )
#   ifndef HASH_PREDEF_OS_BSD_AVAILABLE
#       undef HASH_PREDEF_OS_BSD
#       define HASH_PREDEF_OS_BSD HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#       define HASH_PREDEF_OS_BSD_AVAILABLE
#   endif
#   undef HASH_PREDEF_OS_BSD_FREE
#   include <sys/param.h>
#   if defined(__FreeBSD_version)
#       if __FreeBSD_version == 491000
#           define HASH_PREDEF_OS_BSD_FREE \
                HASH_PREDEF_VERSION_NUMBER(4, 10, 0)
#       elif __FreeBSD_version == 492000
#           define HASH_PREDEF_OS_BSD_FREE \
                HASH_PREDEF_VERSION_NUMBER(4, 11, 0)
#       elif __FreeBSD_version < 500000
#           define HASH_PREDEF_OS_BSD_FREE \
                HASH_PREDEF_MAKE_10_VRPPPP(__FreeBSD_version)
#       else
#           define HASH_PREDEF_OS_BSD_FREE \
                HASH_PREDEF_MAKE_10_VVRRPPP(__FreeBSD_version)
#       endif
#   else
#       define HASH_PREDEF_OS_BSD_FREE HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if HASH_PREDEF_OS_BSD_FREE
#   define HASH_PREDEF_OS_BSD_FREE_AVAILABLE
#   include <predef/detail/os_detected.h>
#endif

#define HASH_PREDEF_OS_BSD_FREE_NAME "Free BSD"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_OS_BSD_FREE,HASH_PREDEF_OS_BSD_FREE_NAME)
