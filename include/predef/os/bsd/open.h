/*
Copyright Rene Rivera 2012-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_OS_BSD_OPEN_H
#define HASH_PREDEF_OS_BSD_OPEN_H

#include <predef/os/bsd.h>

/* tag::reference[]
= `HASH_PREDEF_OS_BSD_OPEN`

http://en.wikipedia.org/wiki/Openbsd[OpenBSD] operating system.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__OpenBSD__+` | {predef_detection}

| `OpenBSD2_0` | 2.0.0
| `OpenBSD2_1` | 2.1.0
| `OpenBSD2_2` | 2.2.0
| `OpenBSD2_3` | 2.3.0
| `OpenBSD2_4` | 2.4.0
| `OpenBSD2_5` | 2.5.0
| `OpenBSD2_6` | 2.6.0
| `OpenBSD2_7` | 2.7.0
| `OpenBSD2_8` | 2.8.0
| `OpenBSD2_9` | 2.9.0
| `OpenBSD3_0` | 3.0.0
| `OpenBSD3_1` | 3.1.0
| `OpenBSD3_2` | 3.2.0
| `OpenBSD3_3` | 3.3.0
| `OpenBSD3_4` | 3.4.0
| `OpenBSD3_5` | 3.5.0
| `OpenBSD3_6` | 3.6.0
| `OpenBSD3_7` | 3.7.0
| `OpenBSD3_8` | 3.8.0
| `OpenBSD3_9` | 3.9.0
| `OpenBSD4_0` | 4.0.0
| `OpenBSD4_1` | 4.1.0
| `OpenBSD4_2` | 4.2.0
| `OpenBSD4_3` | 4.3.0
| `OpenBSD4_4` | 4.4.0
| `OpenBSD4_5` | 4.5.0
| `OpenBSD4_6` | 4.6.0
| `OpenBSD4_7` | 4.7.0
| `OpenBSD4_8` | 4.8.0
| `OpenBSD4_9` | 4.9.0
| `OpenBSD5_0` | 5.0.0
| `OpenBSD5_1` | 5.1.0
| `OpenBSD5_2` | 5.2.0
| `OpenBSD5_3` | 5.3.0
| `OpenBSD5_4` | 5.4.0
| `OpenBSD5_5` | 5.5.0
| `OpenBSD5_6` | 5.6.0
| `OpenBSD5_7` | 5.7.0
| `OpenBSD5_8` | 5.8.0
| `OpenBSD5_9` | 5.9.0
| `OpenBSD6_0` | 6.0.0
| `OpenBSD6_1` | 6.1.0
| `OpenBSD6_2` | 6.2.0
| `OpenBSD6_3` | 6.3.0
| `OpenBSD6_4` | 6.4.0
| `OpenBSD6_5` | 6.5.0
| `OpenBSD6_6` | 6.6.0
| `OpenBSD6_7` | 6.7.0
| `OpenBSD6_8` | 6.8.0
| `OpenBSD6_9` | 6.9.0
|===
*/ // end::reference[]

#define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(HASH_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(__OpenBSD__) \
    )
#   ifndef HASH_PREDEF_OS_BSD_AVAILABLE
#       define HASH_PREDEF_OS_BSD HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#       define HASH_PREDEF_OS_BSD_AVAILABLE
#   endif
#   undef HASH_PREDEF_OS_BSD_OPEN
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD2_0)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(2,0,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD2_1)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(2,1,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD2_2)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(2,2,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD2_3)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(2,3,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD2_4)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(2,4,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD2_5)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(2,5,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD2_6)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(2,6,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD2_7)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(2,7,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD2_8)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(2,8,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD2_9)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(2,9,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD3_0)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(3,0,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD3_1)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(3,1,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD3_2)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(3,2,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD3_3)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(3,3,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD3_4)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(3,4,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD3_5)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(3,5,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD3_6)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(3,6,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD3_7)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(3,7,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD3_8)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(3,8,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD3_9)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(3,9,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD4_0)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(4,0,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD4_1)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(4,1,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD4_2)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(4,2,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD4_3)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(4,3,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD4_4)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(4,4,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD4_5)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(4,5,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD4_6)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(4,6,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD4_7)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(4,7,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD4_8)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(4,8,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD4_9)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(4,9,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD5_0)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(5,0,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD5_1)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(5,1,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD5_2)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(5,2,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD5_3)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(5,3,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD5_4)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(5,4,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD5_5)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(5,5,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD5_6)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(5,6,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD5_7)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(5,7,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD5_8)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(5,8,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD5_9)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(5,9,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD6_0)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(6,0,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD6_1)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(6,1,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD6_2)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(6,2,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD6_3)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(6,3,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD6_4)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(6,4,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD6_5)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(6,5,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD6_6)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(6,6,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD6_7)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(6,7,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD6_8)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(6,8,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN) && defined(OpenBSD6_9)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER(6,9,0)
#   endif
#   if !defined(HASH_PREDEF_OS_BSD_OPEN)
#       define HASH_PREDEF_OS_BSD_OPEN HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if HASH_PREDEF_OS_BSD_OPEN
#   define HASH_PREDEF_OS_BSD_OPEN_AVAILABLE
#   include <predef/detail/os_detected.h>
#endif

#define HASH_PREDEF_OS_BSD_OPEN_NAME "OpenBSD"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_OS_BSD_OPEN,HASH_PREDEF_OS_BSD_OPEN_NAME)
