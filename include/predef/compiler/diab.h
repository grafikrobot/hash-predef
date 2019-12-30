/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_COMPILER_DIAB_H
#define HASH_PREDEF_COMPILER_DIAB_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_COMP_DIAB`

http://www.windriver.com/products/development_suite/wind_river_compiler/[Diab C/{CPP}] compiler.
Version number available as major, minor, and patch.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__DCC__+` | {predef_detection}

| `+__VERSION_NUMBER__+` | V.R.P
|===
*/ // end::reference[]

#define HASH_PREDEF_COMP_DIAB HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__DCC__)
#   define HASH_PREDEF_COMP_DIAB_DETECTION HASH_PREDEF_MAKE_10_VRPP(__VERSION_NUMBER__)
#endif

#ifdef HASH_PREDEF_COMP_DIAB_DETECTION
#   if defined(HASH_PREDEF_DETAIL_COMP_DETECTED)
#       define HASH_PREDEF_COMP_DIAB_EMULATED HASH_PREDEF_COMP_DIAB_DETECTION
#   else
#       undef HASH_PREDEF_COMP_DIAB
#       define HASH_PREDEF_COMP_DIAB HASH_PREDEF_COMP_DIAB_DETECTION
#   endif
#   define HASH_PREDEF_COMP_DIAB_AVAILABLE
#   include <predef/detail/comp_detected.h>
#endif

#define HASH_PREDEF_COMP_DIAB_NAME "Diab C/C++"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_DIAB,HASH_PREDEF_COMP_DIAB_NAME)

#ifdef HASH_PREDEF_COMP_DIAB_EMULATED
#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_DIAB_EMULATED,HASH_PREDEF_COMP_DIAB_NAME)
#endif
