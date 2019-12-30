/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_COMPILER_IBM_H
#define HASH_PREDEF_COMPILER_IBM_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_COMP_IBM`

http://en.wikipedia.org/wiki/VisualAge[IBM XL C/{CPP}] compiler.
Version number available as major, minor, and patch.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__IBMCPP__+` | {predef_detection}
| `+__xlC__+` | {predef_detection}
| `+__xlc__+` | {predef_detection}

| `+__COMPILER_VER__+` | V.R.P
| `+__xlC__+` | V.R.P
| `+__xlc__+` | V.R.P
| `+__IBMCPP__+` | V.R.P
|===
*/ // end::reference[]

#define HASH_PREDEF_COMP_IBM HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__IBMCPP__) || defined(__xlC__) || defined(__xlc__)
#   if !defined(HASH_PREDEF_COMP_IBM_DETECTION) && defined(__COMPILER_VER__)
#       define HASH_PREDEF_COMP_IBM_DETECTION HASH_PREDEF_MAKE_0X_VRRPPPP(__COMPILER_VER__)
#   endif
#   if !defined(HASH_PREDEF_COMP_IBM_DETECTION) && defined(__xlC__)
#       define HASH_PREDEF_COMP_IBM_DETECTION HASH_PREDEF_MAKE_0X_VVRR(__xlC__)
#   endif
#   if !defined(HASH_PREDEF_COMP_IBM_DETECTION) && defined(__xlc__)
#       define HASH_PREDEF_COMP_IBM_DETECTION HASH_PREDEF_MAKE_0X_VVRR(__xlc__)
#   endif
#   if !defined(HASH_PREDEF_COMP_IBM_DETECTION)
#       define HASH_PREDEF_COMP_IBM_DETECTION HASH_PREDEF_MAKE_10_VRP(__IBMCPP__)
#   endif
#endif

#ifdef HASH_PREDEF_COMP_IBM_DETECTION
#   if defined(HASH_PREDEF_DETAIL_COMP_DETECTED)
#       define HASH_PREDEF_COMP_IBM_EMULATED HASH_PREDEF_COMP_IBM_DETECTION
#   else
#       undef HASH_PREDEF_COMP_IBM
#       define HASH_PREDEF_COMP_IBM HASH_PREDEF_COMP_IBM_DETECTION
#   endif
#   define HASH_PREDEF_COMP_IBM_AVAILABLE
#   include <predef/detail/comp_detected.h>
#endif

#define HASH_PREDEF_COMP_IBM_NAME "IBM XL C/C++"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_IBM,HASH_PREDEF_COMP_IBM_NAME)

#ifdef HASH_PREDEF_COMP_IBM_EMULATED
#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_IBM_EMULATED,HASH_PREDEF_COMP_IBM_NAME)
#endif
