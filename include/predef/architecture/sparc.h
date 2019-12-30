/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_ARCHITECTURE_SPARC_H
#define HASH_PREDEF_ARCHITECTURE_SPARC_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_ARCH_SPARC`

http://en.wikipedia.org/wiki/SPARC[SPARC] architecture.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__sparc__+` | {predef_detection}
| `+__sparc+` | {predef_detection}

| `+__sparcv9+` | 9.0.0
| `+__sparcv8+` | 8.0.0
|===
*/ // end::reference[]

#define HASH_PREDEF_ARCH_SPARC HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__sparc__) || defined(__sparc)
#   undef HASH_PREDEF_ARCH_SPARC
#   if !defined(HASH_PREDEF_ARCH_SPARC) && defined(__sparcv9)
#       define HASH_PREDEF_ARCH_SPARC HASH_PREDEF_VERSION_NUMBER(9,0,0)
#   endif
#   if !defined(HASH_PREDEF_ARCH_SPARC) && defined(__sparcv8)
#       define HASH_PREDEF_ARCH_SPARC HASH_PREDEF_VERSION_NUMBER(8,0,0)
#   endif
#   if !defined(HASH_PREDEF_ARCH_SPARC)
#       define HASH_PREDEF_ARCH_SPARC HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if HASH_PREDEF_ARCH_SPARC
#   define HASH_PREDEF_ARCH_SPARC_AVAILABLE
#endif

#define HASH_PREDEF_ARCH_SPARC_NAME "SPARC"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_ARCH_SPARC,HASH_PREDEF_ARCH_SPARC_NAME)
