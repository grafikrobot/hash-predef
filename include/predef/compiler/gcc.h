/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_COMPILER_GCC_H
#define HASH_PREDEF_COMPILER_GCC_H

/* Other compilers that emulate this one need to be detected first. */

#include <predef/compiler/clang.h>

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_COMP_GNUC`

http://en.wikipedia.org/wiki/GNU_Compiler_Collection[Gnu GCC C/{CPP}] compiler.
Version number available as major, minor, and patch (if available).

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__GNUC__+` | {predef_detection}

| `+__GNUC__+`, `+__GNUC_MINOR__+`, `+__GNUC_PATCHLEVEL__+` | V.R.P
| `+__GNUC__+`, `+__GNUC_MINOR__+` | V.R.0
|===
*/ // end::reference[]

#define HASH_PREDEF_COMP_GNUC HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__GNUC__)
#   if !defined(HASH_PREDEF_COMP_GNUC_DETECTION) && defined(__GNUC_PATCHLEVEL__)
#       define HASH_PREDEF_COMP_GNUC_DETECTION \
            HASH_PREDEF_VERSION_NUMBER(__GNUC__,__GNUC_MINOR__,__GNUC_PATCHLEVEL__)
#   endif
#   if !defined(HASH_PREDEF_COMP_GNUC_DETECTION)
#       define HASH_PREDEF_COMP_GNUC_DETECTION \
            HASH_PREDEF_VERSION_NUMBER(__GNUC__,__GNUC_MINOR__,0)
#   endif
#endif

#ifdef HASH_PREDEF_COMP_GNUC_DETECTION
#   if defined(HASH_PREDEF_DETAIL_COMP_DETECTED)
#       define HASH_PREDEF_COMP_GNUC_EMULATED HASH_PREDEF_COMP_GNUC_DETECTION
#   else
#       undef HASH_PREDEF_COMP_GNUC
#       define HASH_PREDEF_COMP_GNUC HASH_PREDEF_COMP_GNUC_DETECTION
#   endif
#   define HASH_PREDEF_COMP_GNUC_AVAILABLE
#   include <predef/detail/comp_detected.h>
#endif

#define HASH_PREDEF_COMP_GNUC_NAME "Gnu GCC C/C++"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_GNUC,HASH_PREDEF_COMP_GNUC_NAME)

#ifdef HASH_PREDEF_COMP_GNUC_EMULATED
#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_GNUC_EMULATED,HASH_PREDEF_COMP_GNUC_NAME)
#endif
