/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_COMPILER_EDG_H
#define HASH_PREDEF_COMPILER_EDG_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_COMP_EDG`

http://en.wikipedia.org/wiki/Edison_Design_Group[EDG {CPP} Frontend] compiler.
Version number available as major, minor, and patch.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__EDG__+` | {predef_detection}

| `+__EDG_VERSION__+` | V.R.0
|===
*/ // end::reference[]

#define HASH_PREDEF_COMP_EDG HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__EDG__)
#   define HASH_PREDEF_COMP_EDG_DETECTION HASH_PREDEF_MAKE_10_VRR(__EDG_VERSION__)
#endif

#ifdef HASH_PREDEF_COMP_EDG_DETECTION
#   if defined(HASH_PREDEF_DETAIL_COMP_DETECTED)
#       define HASH_PREDEF_COMP_EDG_EMULATED HASH_PREDEF_COMP_EDG_DETECTION
#   else
#       undef HASH_PREDEF_COMP_EDG
#       define HASH_PREDEF_COMP_EDG HASH_PREDEF_COMP_EDG_DETECTION
#   endif
#   define HASH_PREDEF_COMP_EDG_AVAILABLE
#   include <predef/detail/comp_detected.h>
#endif

#define HASH_PREDEF_COMP_EDG_NAME "EDG C++ Frontend"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_EDG,HASH_PREDEF_COMP_EDG_NAME)

#ifdef HASH_PREDEF_COMP_EDG_EMULATED
#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_EDG_EMULATED,HASH_PREDEF_COMP_EDG_NAME)
#endif
