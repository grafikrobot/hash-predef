/*
Copyright Rene Rivera 2008-2017
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_COMPILER_INTEL_H
#define HASH_PREDEF_COMPILER_INTEL_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_COMP_INTEL`

http://en.wikipedia.org/wiki/Intel_C%2B%2B[Intel C/{CPP}] compiler.
Version number available as major, minor, and patch.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__INTEL_COMPILER+` | {predef_detection}
| `+__ICL+` | {predef_detection}
| `+__ICC+` | {predef_detection}
| `+__ECC+` | {predef_detection}

| `+__INTEL_COMPILER+` | V.R
| `+__INTEL_COMPILER+` and `+__INTEL_COMPILER_UPDATE+` | V.R.P
|===
*/ // end::reference[]

#define HASH_PREDEF_COMP_INTEL HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__INTEL_COMPILER) || defined(__ICL) || defined(__ICC) || \
    defined(__ECC)
/* tag::reference[]
NOTE: Because of an Intel mistake in the release version numbering when
`__INTEL_COMPILER` is `9999` it is detected as version 12.1.0.
*/ // end::reference[]
#   if !defined(HASH_PREDEF_COMP_INTEL_DETECTION) && defined(__INTEL_COMPILER) && (__INTEL_COMPILER == 9999)
#       define HASH_PREDEF_COMP_INTEL_DETECTION HASH_PREDEF_VERSION_NUMBER(12,1,0)
#   endif
#   if !defined(HASH_PREDEF_COMP_INTEL_DETECTION) && defined(__INTEL_COMPILER) && defined(__INTEL_COMPILER_UPDATE)
#       define HASH_PREDEF_COMP_INTEL_DETECTION HASH_PREDEF_VERSION_NUMBER( \
            HASH_PREDEF_VERSION_NUMBER_MAJOR(HASH_PREDEF_MAKE_10_VVRR(__INTEL_COMPILER)), \
            HASH_PREDEF_VERSION_NUMBER_MINOR(HASH_PREDEF_MAKE_10_VVRR(__INTEL_COMPILER)), \
            __INTEL_COMPILER_UPDATE)
#   endif
#   if !defined(HASH_PREDEF_COMP_INTEL_DETECTION) && defined(__INTEL_COMPILER)
#       define HASH_PREDEF_COMP_INTEL_DETECTION HASH_PREDEF_MAKE_10_VVRR(__INTEL_COMPILER)
#   endif
#   if !defined(HASH_PREDEF_COMP_INTEL_DETECTION)
#       define HASH_PREDEF_COMP_INTEL_DETECTION HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef HASH_PREDEF_COMP_INTEL_DETECTION
#   if defined(HASH_PREDEF_DETAIL_COMP_DETECTED)
#       define HASH_PREDEF_COMP_INTEL_EMULATED HASH_PREDEF_COMP_INTEL_DETECTION
#   else
#       undef HASH_PREDEF_COMP_INTEL
#       define HASH_PREDEF_COMP_INTEL HASH_PREDEF_COMP_INTEL_DETECTION
#   endif
#   define HASH_PREDEF_COMP_INTEL_AVAILABLE
#   include <predef/detail/comp_detected.h>
#endif

#define HASH_PREDEF_COMP_INTEL_NAME "Intel C/C++"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_INTEL,HASH_PREDEF_COMP_INTEL_NAME)

#ifdef HASH_PREDEF_COMP_INTEL_EMULATED
#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_INTEL_EMULATED,HASH_PREDEF_COMP_INTEL_NAME)
#endif
