/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_COMPILER_PALM_H
#define HASH_PREDEF_COMPILER_PALM_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_COMP_PALM`

Palm C/{CPP} compiler.
Version number available as major, minor, and patch.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+_PACC_VER+` | {predef_detection}

| `+_PACC_VER+` | V.R.P
|===
*/ // end::reference[]

#define HASH_PREDEF_COMP_PALM HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(_PACC_VER)
#   define HASH_PREDEF_COMP_PALM_DETECTION HASH_PREDEF_MAKE_0X_VRRPP000(_PACC_VER)
#endif

#ifdef HASH_PREDEF_COMP_PALM_DETECTION
#   if defined(HASH_PREDEF_DETAIL_COMP_DETECTED)
#       define HASH_PREDEF_COMP_PALM_EMULATED HASH_PREDEF_COMP_PALM_DETECTION
#   else
#       undef HASH_PREDEF_COMP_PALM
#       define HASH_PREDEF_COMP_PALM HASH_PREDEF_COMP_PALM_DETECTION
#   endif
#   define HASH_PREDEF_COMP_PALM_AVAILABLE
#   include <predef/detail/comp_detected.h>
#endif

#define HASH_PREDEF_COMP_PALM_NAME "Palm C/C++"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_PALM,HASH_PREDEF_COMP_PALM_NAME)

#ifdef HASH_PREDEF_COMP_PALM_EMULATED
#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_PALM_EMULATED,HASH_PREDEF_COMP_PALM_NAME)
#endif
