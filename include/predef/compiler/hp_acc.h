/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_COMPILER_HP_ACC_H
#define HASH_PREDEF_COMPILER_HP_ACC_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_COMP_HPACC`

HP a{CPP} compiler.
Version number available as major, minor, and patch.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__HP_aCC+` | {predef_detection}

| `+__HP_aCC+` | V.R.P
|===
*/ // end::reference[]

#define HASH_PREDEF_COMP_HPACC HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__HP_aCC)
#   if !defined(HASH_PREDEF_COMP_HPACC_DETECTION) && (__HP_aCC > 1)
#       define HASH_PREDEF_COMP_HPACC_DETECTION HASH_PREDEF_MAKE_10_VVRRPP(__HP_aCC)
#   endif
#   if !defined(HASH_PREDEF_COMP_HPACC_DETECTION)
#       define HASH_PREDEF_COMP_HPACC_DETECTION HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef HASH_PREDEF_COMP_HPACC_DETECTION
#   if defined(HASH_PREDEF_DETAIL_COMP_DETECTED)
#       define HASH_PREDEF_COMP_HPACC_EMULATED HASH_PREDEF_COMP_HPACC_DETECTION
#   else
#       undef HASH_PREDEF_COMP_HPACC
#       define HASH_PREDEF_COMP_HPACC HASH_PREDEF_COMP_HPACC_DETECTION
#   endif
#   define HASH_PREDEF_COMP_HPACC_AVAILABLE
#   include <predef/detail/comp_detected.h>
#endif

#define HASH_PREDEF_COMP_HPACC_NAME "HP aC++"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_HPACC,HASH_PREDEF_COMP_HPACC_NAME)

#ifdef HASH_PREDEF_COMP_HPACC_EMULATED
#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_HPACC_EMULATED,HASH_PREDEF_COMP_HPACC_NAME)
#endif
