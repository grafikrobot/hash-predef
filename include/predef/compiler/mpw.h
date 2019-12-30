/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_COMPILER_MPW_H
#define HASH_PREDEF_COMPILER_MPW_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_COMP_MPW`

http://en.wikipedia.org/wiki/Macintosh_Programmer%27s_Workshop[MPW {CPP}] compiler.
Version number available as major, and minor.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__MRC__+` | {predef_detection}
| `MPW_C` | {predef_detection}
| `MPW_CPLUS` | {predef_detection}

| `+__MRC__+` | V.R.0
|===
*/ // end::reference[]

#define HASH_PREDEF_COMP_MPW HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__MRC__) || defined(MPW_C) || defined(MPW_CPLUS)
#   if !defined(HASH_PREDEF_COMP_MPW_DETECTION) && defined(__MRC__)
#       define HASH_PREDEF_COMP_MPW_DETECTION HASH_PREDEF_MAKE_0X_VVRR(__MRC__)
#   endif
#   if !defined(HASH_PREDEF_COMP_MPW_DETECTION)
#       define HASH_PREDEF_COMP_MPW_DETECTION HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef HASH_PREDEF_COMP_MPW_DETECTION
#   if defined(HASH_PREDEF_DETAIL_COMP_DETECTED)
#       define HASH_PREDEF_COMP_MPW_EMULATED HASH_PREDEF_COMP_MPW_DETECTION
#   else
#       undef HASH_PREDEF_COMP_MPW
#       define HASH_PREDEF_COMP_MPW HASH_PREDEF_COMP_MPW_DETECTION
#   endif
#   define HASH_PREDEF_COMP_MPW_AVAILABLE
#   include <predef/detail/comp_detected.h>
#endif

#define HASH_PREDEF_COMP_MPW_NAME "MPW C++"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_MPW,HASH_PREDEF_COMP_MPW_NAME)

#ifdef HASH_PREDEF_COMP_MPW_EMULATED
#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_MPW_EMULATED,HASH_PREDEF_COMP_MPW_NAME)
#endif
