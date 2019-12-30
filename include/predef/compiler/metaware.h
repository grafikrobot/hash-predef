/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_COMPILER_METAWARE_H
#define HASH_PREDEF_COMPILER_METAWARE_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_COMP_HIGHC`

MetaWare High C/{CPP} compiler.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__HIGHC__+` | {predef_detection}
|===
*/ // end::reference[]

#define HASH_PREDEF_COMP_HIGHC HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__HIGHC__)
#   define HASH_PREDEF_COMP_HIGHC_DETECTION HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#ifdef HASH_PREDEF_COMP_HIGHC_DETECTION
#   if defined(HASH_PREDEF_DETAIL_COMP_DETECTED)
#       define HASH_PREDEF_COMP_HIGHC_EMULATED HASH_PREDEF_COMP_HIGHC_DETECTION
#   else
#       undef HASH_PREDEF_COMP_HIGHC
#       define HASH_PREDEF_COMP_HIGHC HASH_PREDEF_COMP_HIGHC_DETECTION
#   endif
#   define HASH_PREDEF_COMP_HIGHC_AVAILABLE
#   include <predef/detail/comp_detected.h>
#endif

#define HASH_PREDEF_COMP_HIGHC_NAME "MetaWare High C/C++"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_HIGHC,HASH_PREDEF_COMP_HIGHC_NAME)

#ifdef HASH_PREDEF_COMP_HIGHC_EMULATED
#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_HIGHC_EMULATED,HASH_PREDEF_COMP_HIGHC_NAME)
#endif
