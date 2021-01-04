/*
Copyright Rene Rivera 2012-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_OS_BSD_DRAGONFLY_H
#define HASH_PREDEF_OS_BSD_DRAGONFLY_H

#include <predef/os/bsd.h>

/* tag::reference[]
= `HASH_PREDEF_OS_BSD_DRAGONFLY`

http://en.wikipedia.org/wiki/DragonFly_BSD[DragonFly BSD] operating system.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__DragonFly__+` | {predef_detection}
|===
*/ // end::reference[]

#define HASH_PREDEF_OS_BSD_DRAGONFLY HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(HASH_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(__DragonFly__) \
    )
#   ifndef HASH_PREDEF_OS_BSD_AVAILABLE
#       undef HASH_PREDEF_OS_BSD
#       define HASH_PREDEF_OS_BSD HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#       define HASH_PREDEF_OS_BSD_AVAILABLE
#   endif
#   undef HASH_PREDEF_OS_BSD_DRAGONFLY
#   if defined(__DragonFly__)
#       define HASH_PREDEF_OS_DRAGONFLY_BSD HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if HASH_PREDEF_OS_BSD_DRAGONFLY
#   define HASH_PREDEF_OS_BSD_DRAGONFLY_AVAILABLE
#   include <predef/detail/os_detected.h>
#endif

#define HASH_PREDEF_OS_BSD_DRAGONFLY_NAME "DragonFly BSD"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_OS_BSD_DRAGONFLY,HASH_PREDEF_OS_BSD_DRAGONFLY_NAME)
