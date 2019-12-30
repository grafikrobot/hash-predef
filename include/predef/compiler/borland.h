/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_COMPILER_BORLAND_H
#define HASH_PREDEF_COMPILER_BORLAND_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_COMP_BORLAND`

http://en.wikipedia.org/wiki/C_plus_plus_builder[Borland {CPP}] compiler.
Version number available as major, minor, and patch.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__BORLANDC__+` | {predef_detection}
| `+__CODEGEARC__+` | {predef_detection}

| `+__BORLANDC__+` | V.R.P
| `+__CODEGEARC__+` | V.R.P
|===
*/ // end::reference[]

#define HASH_PREDEF_COMP_BORLAND HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__BORLANDC__) || defined(__CODEGEARC__)
#   if !defined(HASH_PREDEF_COMP_BORLAND_DETECTION) && (defined(__CODEGEARC__))
#       define HASH_PREDEF_COMP_BORLAND_DETECTION HASH_PREDEF_MAKE_0X_VVRP(__CODEGEARC__)
#   endif
#   if !defined(HASH_PREDEF_COMP_BORLAND_DETECTION)
#       define HASH_PREDEF_COMP_BORLAND_DETECTION HASH_PREDEF_MAKE_0X_VVRP(__BORLANDC__)
#   endif
#endif

#ifdef HASH_PREDEF_COMP_BORLAND_DETECTION
#   define HASH_PREDEF_COMP_BORLAND_AVAILABLE
#   if defined(HASH_PREDEF_DETAIL_COMP_DETECTED)
#       define HASH_PREDEF_COMP_BORLAND_EMULATED HASH_PREDEF_COMP_BORLAND_DETECTION
#   else
#       undef HASH_PREDEF_COMP_BORLAND
#       define HASH_PREDEF_COMP_BORLAND HASH_PREDEF_COMP_BORLAND_DETECTION
#   endif
#   include <predef/detail/comp_detected.h>
#endif

#define HASH_PREDEF_COMP_BORLAND_NAME "Borland C++"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_BORLAND,HASH_PREDEF_COMP_BORLAND_NAME)

#ifdef HASH_PREDEF_COMP_BORLAND_EMULATED
#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_BORLAND_EMULATED,HASH_PREDEF_COMP_BORLAND_NAME)
#endif
