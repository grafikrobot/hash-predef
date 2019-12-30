/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_COMPILER_IAR_H
#define HASH_PREDEF_COMPILER_IAR_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_COMP_IAR`

IAR C/{CPP} compiler.
Version number available as major, minor, and patch.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__IAR_SYSTEMS_ICC__+` | {predef_detection}

| `+__VER__+` | V.R.P
|===
*/ // end::reference[]

#define HASH_PREDEF_COMP_IAR HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__IAR_SYSTEMS_ICC__)
#   define HASH_PREDEF_COMP_IAR_DETECTION HASH_PREDEF_MAKE_10_VVRR(__VER__)
#endif

#ifdef HASH_PREDEF_COMP_IAR_DETECTION
#   if defined(HASH_PREDEF_DETAIL_COMP_DETECTED)
#       define HASH_PREDEF_COMP_IAR_EMULATED HASH_PREDEF_COMP_IAR_DETECTION
#   else
#       undef HASH_PREDEF_COMP_IAR
#       define HASH_PREDEF_COMP_IAR HASH_PREDEF_COMP_IAR_DETECTION
#   endif
#   define HASH_PREDEF_COMP_IAR_AVAILABLE
#   include <predef/detail/comp_detected.h>
#endif

#define HASH_PREDEF_COMP_IAR_NAME "IAR C/C++"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_IAR,HASH_PREDEF_COMP_IAR_NAME)

#ifdef HASH_PREDEF_COMP_IAR_EMULATED
#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_IAR_EMULATED,HASH_PREDEF_COMP_IAR_NAME)
#endif
