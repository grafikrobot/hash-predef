/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_COMPILER_WATCOM_H
#define HASH_PREDEF_COMPILER_WATCOM_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_COMP_WATCOM`

http://en.wikipedia.org/wiki/Watcom[Watcom {CPP}] compiler.
Version number available as major, and minor.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__WATCOMC__+` | {predef_detection}

| `+__WATCOMC__+` | V.R.P
|===
*/ // end::reference[]

#define HASH_PREDEF_COMP_WATCOM HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__WATCOMC__)
#   define HASH_PREDEF_COMP_WATCOM_DETECTION HASH_PREDEF_MAKE_10_VVRR(__WATCOMC__)
#endif

#ifdef HASH_PREDEF_COMP_WATCOM_DETECTION
#   if defined(HASH_PREDEF_DETAIL_COMP_DETECTED)
#       define HASH_PREDEF_COMP_WATCOM_EMULATED HASH_PREDEF_COMP_WATCOM_DETECTION
#   else
#       undef HASH_PREDEF_COMP_WATCOM
#       define HASH_PREDEF_COMP_WATCOM HASH_PREDEF_COMP_WATCOM_DETECTION
#   endif
#   define HASH_PREDEF_COMP_WATCOM_AVAILABLE
#   include <predef/detail/comp_detected.h>
#endif

#define HASH_PREDEF_COMP_WATCOM_NAME "Watcom C++"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_WATCOM,HASH_PREDEF_COMP_WATCOM_NAME)

#ifdef HASH_PREDEF_COMP_WATCOM_EMULATED
#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_WATCOM_EMULATED,HASH_PREDEF_COMP_WATCOM_NAME)
#endif
