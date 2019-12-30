/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_OS_AIX_H
#define HASH_PREDEF_OS_AIX_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_OS_AIX`

http://en.wikipedia.org/wiki/AIX_operating_system[IBM AIX] operating system.
Version number available as major, minor, and patch.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+_AIX+` | {predef_detection}
| `+__TOS_AIX__+` | {predef_detection}

| `+_AIX43+` | 4.3.0
| `+_AIX41+` | 4.1.0
| `+_AIX32+` | 3.2.0
| `+_AIX3+` | 3.0.0
|===
*/ // end::reference[]

#define HASH_PREDEF_OS_AIX HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(HASH_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(_AIX) || defined(__TOS_AIX__) \
    )
#   undef HASH_PREDEF_OS_AIX
#   if !defined(HASH_PREDEF_OS_AIX) && defined(_AIX43)
#       define HASH_PREDEF_OS_AIX HASH_PREDEF_VERSION_NUMBER(4,3,0)
#   endif
#   if !defined(HASH_PREDEF_OS_AIX) && defined(_AIX41)
#       define HASH_PREDEF_OS_AIX HASH_PREDEF_VERSION_NUMBER(4,1,0)
#   endif
#   if !defined(HASH_PREDEF_OS_AIX) && defined(_AIX32)
#       define HASH_PREDEF_OS_AIX HASH_PREDEF_VERSION_NUMBER(3,2,0)
#   endif
#   if !defined(HASH_PREDEF_OS_AIX) && defined(_AIX3)
#       define HASH_PREDEF_OS_AIX HASH_PREDEF_VERSION_NUMBER(3,0,0)
#   endif
#   if !defined(HASH_PREDEF_OS_AIX)
#       define HASH_PREDEF_OS_AIX HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if HASH_PREDEF_OS_AIX
#   define HASH_PREDEF_OS_AIX_AVAILABLE
#   include <predef/detail/os_detected.h>
#endif

#define HASH_PREDEF_OS_AIX_NAME "IBM AIX"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_OS_AIX,HASH_PREDEF_OS_AIX_NAME)
