/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_COMPILER_DIGITALMARS_H
#define HASH_PREDEF_COMPILER_DIGITALMARS_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_COMP_DMC`

http://en.wikipedia.org/wiki/Digital_Mars[Digital Mars] compiler.
Version number available as major, minor, and patch.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__DMC__+` | {predef_detection}

| `+__DMC__+` | V.R.P
|===
*/ // end::reference[]

#define HASH_PREDEF_COMP_DMC HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__DMC__)
#   define HASH_PREDEF_COMP_DMC_DETECTION HASH_PREDEF_MAKE_0X_VRP(__DMC__)
#endif

#ifdef HASH_PREDEF_COMP_DMC_DETECTION
#   if defined(HASH_PREDEF_DETAIL_COMP_DETECTED)
#       define HASH_PREDEF_COMP_DMC_EMULATED HASH_PREDEF_COMP_DMC_DETECTION
#   else
#       undef HASH_PREDEF_COMP_DMC
#       define HASH_PREDEF_COMP_DMC HASH_PREDEF_COMP_DMC_DETECTION
#   endif
#   define HASH_PREDEF_COMP_DMC_AVAILABLE
#   include <predef/detail/comp_detected.h>
#endif

#define HASH_PREDEF_COMP_DMC_NAME "Digital Mars"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_DMC,HASH_PREDEF_COMP_DMC_NAME)

#ifdef HASH_PREDEF_COMP_DMC_EMULATED
#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_DMC_EMULATED,HASH_PREDEF_COMP_DMC_NAME)
#endif
