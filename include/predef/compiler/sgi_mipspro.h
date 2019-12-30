/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_COMPILER_SGI_MIPSPRO_H
#define HASH_PREDEF_COMPILER_SGI_MIPSPRO_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_COMP_SGI`

http://en.wikipedia.org/wiki/MIPSpro[SGI MIPSpro] compiler.
Version number available as major, minor, and patch.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__sgi+` | {predef_detection}
| `sgi` | {predef_detection}

| `+_SGI_COMPILER_VERSION+` | V.R.P
| `+_COMPILER_VERSION+` | V.R.P
|===
*/ // end::reference[]

#define HASH_PREDEF_COMP_SGI HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__sgi) || defined(sgi)
#   if !defined(HASH_PREDEF_COMP_SGI_DETECTION) && defined(_SGI_COMPILER_VERSION)
#       define HASH_PREDEF_COMP_SGI_DETECTION HASH_PREDEF_MAKE_10_VRP(_SGI_COMPILER_VERSION)
#   endif
#   if !defined(HASH_PREDEF_COMP_SGI_DETECTION) && defined(_COMPILER_VERSION)
#       define HASH_PREDEF_COMP_SGI_DETECTION HASH_PREDEF_MAKE_10_VRP(_COMPILER_VERSION)
#   endif
#   if !defined(HASH_PREDEF_COMP_SGI_DETECTION)
#       define HASH_PREDEF_COMP_SGI_DETECTION HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef HASH_PREDEF_COMP_SGI_DETECTION
#   if defined(HASH_PREDEF_DETAIL_COMP_DETECTED)
#       define HASH_PREDEF_COMP_SGI_EMULATED HASH_PREDEF_COMP_SGI_DETECTION
#   else
#       undef HASH_PREDEF_COMP_SGI
#       define HASH_PREDEF_COMP_SGI HASH_PREDEF_COMP_SGI_DETECTION
#   endif
#   define HASH_PREDEF_COMP_SGI_AVAILABLE
#   include <predef/detail/comp_detected.h>
#endif

#define HASH_PREDEF_COMP_SGI_NAME "SGI MIPSpro"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_SGI,HASH_PREDEF_COMP_SGI_NAME)

#ifdef HASH_PREDEF_COMP_SGI_EMULATED
#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_SGI_EMULATED,HASH_PREDEF_COMP_SGI_NAME)
#endif
