/*
Copyright Rene Rivera 2011-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_ARCHITECTURE_CONVEX_H
#define HASH_PREDEF_ARCHITECTURE_CONVEX_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_ARCH_CONVEX`

http://en.wikipedia.org/wiki/Convex_Computer[Convex Computer] architecture.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__convex__+` | {predef_detection}

| `+__convex_c1__+` | 1.0.0
| `+__convex_c2__+` | 2.0.0
| `+__convex_c32__+` | 3.2.0
| `+__convex_c34__+` | 3.4.0
| `+__convex_c38__+` | 3.8.0
|===
*/ // end::reference[]

#define HASH_PREDEF_ARCH_CONVEX HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__convex__)
#   undef HASH_PREDEF_ARCH_CONVEX
#   if !defined(HASH_PREDEF_ARCH_CONVEX) && defined(__convex_c1__)
#       define HASH_PREDEF_ARCH_CONVEX HASH_PREDEF_VERSION_NUMBER(1,0,0)
#   endif
#   if !defined(HASH_PREDEF_ARCH_CONVEX) && defined(__convex_c2__)
#       define HASH_PREDEF_ARCH_CONVEX HASH_PREDEF_VERSION_NUMBER(2,0,0)
#   endif
#   if !defined(HASH_PREDEF_ARCH_CONVEX) && defined(__convex_c32__)
#       define HASH_PREDEF_ARCH_CONVEX HASH_PREDEF_VERSION_NUMBER(3,2,0)
#   endif
#   if !defined(HASH_PREDEF_ARCH_CONVEX) && defined(__convex_c34__)
#       define HASH_PREDEF_ARCH_CONVEX HASH_PREDEF_VERSION_NUMBER(3,4,0)
#   endif
#   if !defined(HASH_PREDEF_ARCH_CONVEX) && defined(__convex_c38__)
#       define HASH_PREDEF_ARCH_CONVEX HASH_PREDEF_VERSION_NUMBER(3,8,0)
#   endif
#   if !defined(HASH_PREDEF_ARCH_CONVEX)
#       define HASH_PREDEF_ARCH_CONVEX HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if HASH_PREDEF_ARCH_CONVEX
#   define HASH_PREDEF_ARCH_CONVEX_AVAILABLE
#endif

#if HASH_PREDEF_ARCH_CONVEX
#   undef HASH_PREDEF_ARCH_WORD_BITS_32
#   define HASH_PREDEF_ARCH_WORD_BITS_32 HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#define HASH_PREDEF_ARCH_CONVEX_NAME "Convex Computer"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_ARCH_CONVEX,HASH_PREDEF_ARCH_CONVEX_NAME)
