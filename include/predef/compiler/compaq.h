/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_COMPILER_COMPAQ_H
#define HASH_PREDEF_COMPILER_COMPAQ_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_COMP_DEC`

http://www.openvms.compaq.com/openvms/brochures/deccplus/[Compaq C/{CPP}] compiler.
Version number available as major, minor, and patch.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__DECCXX+` | {predef_detection}
| `+__DECC+` | {predef_detection}

| `+__DECCXX_VER+` | V.R.P
| `+__DECC_VER+` | V.R.P
|===
*/ // end::reference[]

#define HASH_PREDEF_COMP_DEC HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__DECC) || defined(__DECCXX)
#   if !defined(HASH_PREDEF_COMP_DEC_DETECTION) && defined(__DECCXX_VER)
#       define HASH_PREDEF_COMP_DEC_DETECTION HASH_PREDEF_MAKE_10_VVRR0PP00(__DECCXX_VER)
#   endif
#   if !defined(HASH_PREDEF_COMP_DEC_DETECTION) && defined(__DECC_VER)
#       define HASH_PREDEF_COMP_DEC_DETECTION HASH_PREDEF_MAKE_10_VVRR0PP00(__DECC_VER)
#   endif
#   if !defined(HASH_PREDEF_COMP_DEC_DETECTION)
#       define HASH_PREDEF_COMP_DEC_DETECTION HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef HASH_PREDEF_COMP_DEC_DETECTION
#   if defined(HASH_PREDEF_DETAIL_COMP_DETECTED)
#       define HASH_PREDEF_COMP_DEC_EMULATED HASH_PREDEF_COMP_DEC_DETECTION
#   else
#       undef HASH_PREDEF_COMP_DEC
#       define HASH_PREDEF_COMP_DEC HASH_PREDEF_COMP_DEC_DETECTION
#   endif
#   define HASH_PREDEF_COMP_DEC_AVAILABLE
#   include <predef/detail/comp_detected.h>
#endif

#define HASH_PREDEF_COMP_DEC_NAME "Compaq C/C++"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_DEC,HASH_PREDEF_COMP_DEC_NAME)

#ifdef HASH_PREDEF_COMP_DEC_EMULATED
#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_DEC_EMULATED,HASH_PREDEF_COMP_DEC_NAME)
#endif
