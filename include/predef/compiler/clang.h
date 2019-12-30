/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_COMPILER_CLANG_H
#define HASH_PREDEF_COMPILER_CLANG_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_COMP_CLANG`

http://en.wikipedia.org/wiki/Clang[Clang] compiler.
Version number available as major, minor, and patch.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__clang__+` | {predef_detection}

| `+__clang_major__+`, `+__clang_minor__+`, `+__clang_patchlevel__+` | V.R.P
|===
*/ // end::reference[]

#define HASH_PREDEF_COMP_CLANG HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__clang__)
#   define HASH_PREDEF_COMP_CLANG_DETECTION HASH_PREDEF_VERSION_NUMBER(__clang_major__,__clang_minor__,__clang_patchlevel__)
#endif

#ifdef HASH_PREDEF_COMP_CLANG_DETECTION
#   if defined(HASH_PREDEF_DETAIL_COMP_DETECTED)
#       define HASH_PREDEF_COMP_CLANG_EMULATED HASH_PREDEF_COMP_CLANG_DETECTION
#   else
#       undef HASH_PREDEF_COMP_CLANG
#       define HASH_PREDEF_COMP_CLANG HASH_PREDEF_COMP_CLANG_DETECTION
#   endif
#   define HASH_PREDEF_COMP_CLANG_AVAILABLE
#   include <predef/detail/comp_detected.h>
#endif

#define HASH_PREDEF_COMP_CLANG_NAME "Clang"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_CLANG,HASH_PREDEF_COMP_CLANG_NAME)

#ifdef HASH_PREDEF_COMP_CLANG_EMULATED
#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_CLANG_EMULATED,HASH_PREDEF_COMP_CLANG_NAME)
#endif
