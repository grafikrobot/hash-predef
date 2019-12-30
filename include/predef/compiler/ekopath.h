/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_COMPILER_EKOPATH_H
#define HASH_PREDEF_COMPILER_EKOPATH_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_COMP_PATH`

http://en.wikipedia.org/wiki/PathScale[EKOpath] compiler.
Version number available as major, minor, and patch.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__PATHCC__+` | {predef_detection}

| `+__PATHCC__+`, `+__PATHCC_MINOR__+`, `+__PATHCC_PATCHLEVEL__+` | V.R.P
|===
*/ // end::reference[]

#define HASH_PREDEF_COMP_PATH HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__PATHCC__)
#   define HASH_PREDEF_COMP_PATH_DETECTION \
        HASH_PREDEF_VERSION_NUMBER(__PATHCC__,__PATHCC_MINOR__,__PATHCC_PATCHLEVEL__)
#endif

#ifdef HASH_PREDEF_COMP_PATH_DETECTION
#   if defined(HASH_PREDEF_DETAIL_COMP_DETECTED)
#       define HASH_PREDEF_COMP_PATH_EMULATED HASH_PREDEF_COMP_PATH_DETECTION
#   else
#       undef HASH_PREDEF_COMP_PATH
#       define HASH_PREDEF_COMP_PATH HASH_PREDEF_COMP_PATH_DETECTION
#   endif
#   define HASH_PREDEF_COMP_PATH_AVAILABLE
#   include <predef/detail/comp_detected.h>
#endif

#define HASH_PREDEF_COMP_PATH_NAME "EKOpath"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_PATH,HASH_PREDEF_COMP_PATH_NAME)

#ifdef HASH_PREDEF_COMP_PATH_EMULATED
#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_PATH_EMULATED,HASH_PREDEF_COMP_PATH_NAME)
#endif
