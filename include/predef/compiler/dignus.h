/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_COMPILER_DIGNUS_H
#define HASH_PREDEF_COMPILER_DIGNUS_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_COMP_SYSC`

http://www.dignus.com/dcxx/[Dignus Systems/{CPP}] compiler.
Version number available as major, minor, and patch.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__SYSC__+` | {predef_detection}

| `+__SYSC_VER__+` | V.R.P
|===
*/ // end::reference[]

#define HASH_PREDEF_COMP_SYSC HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__SYSC__)
#   define HASH_PREDEF_COMP_SYSC_DETECTION HASH_PREDEF_MAKE_10_VRRPP(__SYSC_VER__)
#endif

#ifdef HASH_PREDEF_COMP_SYSC_DETECTION
#   if defined(HASH_PREDEF_DETAIL_COMP_DETECTED)
#       define HASH_PREDEF_COMP_SYSC_EMULATED HASH_PREDEF_COMP_SYSC_DETECTION
#   else
#       undef HASH_PREDEF_COMP_SYSC
#       define HASH_PREDEF_COMP_SYSC HASH_PREDEF_COMP_SYSC_DETECTION
#   endif
#   define HASH_PREDEF_COMP_SYSC_AVAILABLE
#   include <predef/detail/comp_detected.h>
#endif

#define HASH_PREDEF_COMP_SYSC_NAME "Dignus Systems/C++"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_SYSC,HASH_PREDEF_COMP_SYSC_NAME)

#ifdef HASH_PREDEF_COMP_SYSC_EMULATED
#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_SYSC_EMULATED,HASH_PREDEF_COMP_SYSC_NAME)
#endif
