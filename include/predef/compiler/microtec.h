/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_COMPILER_MICROTEC_H
#define HASH_PREDEF_COMPILER_MICROTEC_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_COMP_MRI`

http://www.mentor.com/microtec/[Microtec C/{CPP}] compiler.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+_MRI+` | {predef_detection}
|===
*/ // end::reference[]

#define HASH_PREDEF_COMP_MRI HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(_MRI)
#   define HASH_PREDEF_COMP_MRI_DETECTION HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#ifdef HASH_PREDEF_COMP_MRI_DETECTION
#   if defined(HASH_PREDEF_DETAIL_COMP_DETECTED)
#       define HASH_PREDEF_COMP_MRI_EMULATED HASH_PREDEF_COMP_MRI_DETECTION
#   else
#       undef HASH_PREDEF_COMP_MRI
#       define HASH_PREDEF_COMP_MRI HASH_PREDEF_COMP_MRI_DETECTION
#   endif
#   define HASH_PREDEF_COMP_MRI_AVAILABLE
#   include <predef/detail/comp_detected.h>
#endif

#define HASH_PREDEF_COMP_MRI_NAME "Microtec C/C++"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_MRI,HASH_PREDEF_COMP_MRI_NAME)

#ifdef HASH_PREDEF_COMP_MRI_EMULATED
#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_MRI_EMULATED,HASH_PREDEF_COMP_MRI_NAME)
#endif
