/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_COMPILER_SUNPRO_H
#define HASH_PREDEF_COMPILER_SUNPRO_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_COMP_SUNPRO`

http://en.wikipedia.org/wiki/Oracle_Solaris_Studio[Oracle Solaris Studio] compiler.
Version number available as major, minor, and patch.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__SUNPRO_CC+` | {predef_detection}
| `+__SUNPRO_C+` | {predef_detection}

| `+__SUNPRO_CC+` | V.R.P
| `+__SUNPRO_C+` | V.R.P
| `+__SUNPRO_CC+` | VV.RR.P
| `+__SUNPRO_C+` | VV.RR.P
|===
*/ // end::reference[]

#define HASH_PREDEF_COMP_SUNPRO HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__SUNPRO_CC) || defined(__SUNPRO_C)
#   if !defined(HASH_PREDEF_COMP_SUNPRO_DETECTION) && defined(__SUNPRO_CC)
#       if (__SUNPRO_CC < 0x5100)
#           define HASH_PREDEF_COMP_SUNPRO_DETECTION HASH_PREDEF_MAKE_0X_VRP(__SUNPRO_CC)
#       else
#           define HASH_PREDEF_COMP_SUNPRO_DETECTION HASH_PREDEF_MAKE_0X_VVRRP(__SUNPRO_CC)
#       endif
#   endif
#   if !defined(HASH_PREDEF_COMP_SUNPRO_DETECTION) && defined(__SUNPRO_C)
#       if (__SUNPRO_C < 0x5100)
#           define HASH_PREDEF_COMP_SUNPRO_DETECTION HASH_PREDEF_MAKE_0X_VRP(__SUNPRO_C)
#       else
#           define HASH_PREDEF_COMP_SUNPRO_DETECTION HASH_PREDEF_MAKE_0X_VVRRP(__SUNPRO_C)
#       endif
#   endif
#   if !defined(HASH_PREDEF_COMP_SUNPRO_DETECTION)
#       define HASH_PREDEF_COMP_SUNPRO_DETECTION HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef HASH_PREDEF_COMP_SUNPRO_DETECTION
#   if defined(HASH_PREDEF_DETAIL_COMP_DETECTED)
#       define HASH_PREDEF_COMP_SUNPRO_EMULATED HASH_PREDEF_COMP_SUNPRO_DETECTION
#   else
#       undef HASH_PREDEF_COMP_SUNPRO
#       define HASH_PREDEF_COMP_SUNPRO HASH_PREDEF_COMP_SUNPRO_DETECTION
#   endif
#   define HASH_PREDEF_COMP_SUNPRO_AVAILABLE
#   include <predef/detail/comp_detected.h>
#endif

#define HASH_PREDEF_COMP_SUNPRO_NAME "Oracle Solaris Studio"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_SUNPRO,HASH_PREDEF_COMP_SUNPRO_NAME)

#ifdef HASH_PREDEF_COMP_SUNPRO_EMULATED
#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_SUNPRO_EMULATED,HASH_PREDEF_COMP_SUNPRO_NAME)
#endif
