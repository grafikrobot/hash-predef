/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_COMPILER_COMEAU_H
#define HASH_PREDEF_COMPILER_COMEAU_H

#include <predef/version_number.h>
#include <predef/make.h>

#define HASH_PREDEF_COMP_COMO HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

/* tag::reference[]
= `HASH_PREDEF_COMP_COMO`

http://en.wikipedia.org/wiki/Comeau_C/C%2B%2B[Comeau {CPP}] compiler.
Version number available as major, minor, and patch.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__COMO__+` | {predef_detection}

| `+__COMO_VERSION__+` | V.R.P
|===
*/ // end::reference[]

#if defined(__COMO__)
#   if !defined(HASH_PREDEF_COMP_COMO_DETECTION) && defined(__COMO_VERSION__)
#       define HASH_PREDEF_COMP_COMO_DETECTION HASH_PREDEF_MAKE_0X_VRP(__COMO_VERSION__)
#   endif
#   if !defined(HASH_PREDEF_COMP_COMO_DETECTION)
#       define HASH_PREDEF_COMP_COMO_DETECTION HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef HASH_PREDEF_COMP_COMO_DETECTION
#   if defined(HASH_PREDEF_DETAIL_COMP_DETECTED)
#       define HASH_PREDEF_COMP_COMO_EMULATED HASH_PREDEF_COMP_COMO_DETECTION
#   else
#       undef HASH_PREDEF_COMP_COMO
#       define HASH_PREDEF_COMP_COMO HASH_PREDEF_COMP_COMO_DETECTION
#   endif
#   define HASH_PREDEF_COMP_COMO_AVAILABLE
#   include <predef/detail/comp_detected.h>
#endif

#define HASH_PREDEF_COMP_COMO_NAME "Comeau C++"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_COMO,HASH_PREDEF_COMP_COMO_NAME)

#ifdef HASH_PREDEF_COMP_COMO_EMULATED
#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_COMO_EMULATED,HASH_PREDEF_COMP_COMO_NAME)
#endif
