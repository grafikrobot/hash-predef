/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_COMPILER_KAI_H
#define HASH_PREDEF_COMPILER_KAI_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_COMP_KCC`

Kai {CPP} compiler.
Version number available as major, minor, and patch.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__KCC+` | {predef_detection}

| `+__KCC_VERSION+` | V.R.P
|===
*/ // end::reference[]

#define HASH_PREDEF_COMP_KCC HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__KCC)
#   define HASH_PREDEF_COMP_KCC_DETECTION HASH_PREDEF_MAKE_0X_VRPP(__KCC_VERSION)
#endif

#ifdef HASH_PREDEF_COMP_KCC_DETECTION
#   if defined(HASH_PREDEF_DETAIL_COMP_DETECTED)
#       define HASH_PREDEF_COMP_KCC_EMULATED HASH_PREDEF_COMP_KCC_DETECTION
#   else
#       undef HASH_PREDEF_COMP_KCC
#       define HASH_PREDEF_COMP_KCC HASH_PREDEF_COMP_KCC_DETECTION
#   endif
#   define HASH_PREDEF_COMP_KCC_AVAILABLE
#   include <predef/detail/comp_detected.h>
#endif

#define HASH_PREDEF_COMP_KCC_NAME "Kai C++"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_KCC,HASH_PREDEF_COMP_KCC_NAME)

#ifdef HASH_PREDEF_COMP_KCC_EMULATED
#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_KCC_EMULATED,HASH_PREDEF_COMP_KCC_NAME)
#endif
