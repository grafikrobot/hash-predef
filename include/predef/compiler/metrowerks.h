/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_COMPILER_METROWERKS_H
#define HASH_PREDEF_COMPILER_METROWERKS_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_COMP_MWERKS`

http://en.wikipedia.org/wiki/CodeWarrior[Metrowerks CodeWarrior] compiler.
Version number available as major, minor, and patch.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__MWERKS__+` | {predef_detection}
| `+__CWCC__+` | {predef_detection}

| `+__CWCC__+` | V.R.P
| `+__MWERKS__+` | V.R.P >= 4.2.0
| `+__MWERKS__+` | 9.R.0
| `+__MWERKS__+` | 8.R.0
|===
*/ // end::reference[]

#define HASH_PREDEF_COMP_MWERKS HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__MWERKS__) || defined(__CWCC__)
#   if !defined(HASH_PREDEF_COMP_MWERKS_DETECTION) && defined(__CWCC__)
#       define HASH_PREDEF_COMP_MWERKS_DETECTION HASH_PREDEF_MAKE_0X_VRPP(__CWCC__)
#   endif
#   if !defined(HASH_PREDEF_COMP_MWERKS_DETECTION) && (__MWERKS__ >= 0x4200)
#       define HASH_PREDEF_COMP_MWERKS_DETECTION HASH_PREDEF_MAKE_0X_VRPP(__MWERKS__)
#   endif
#   if !defined(HASH_PREDEF_COMP_MWERKS_DETECTION) && (__MWERKS__ >= 0x3204) // note the "skip": 04->9.3
#       define HASH_PREDEF_COMP_MWERKS_DETECTION HASH_PREDEF_VERSION_NUMBER(9,(__MWERKS__)%100-1,0)
#   endif
#   if !defined(HASH_PREDEF_COMP_MWERKS_DETECTION) && (__MWERKS__ >= 0x3200)
#       define HASH_PREDEF_COMP_MWERKS_DETECTION HASH_PREDEF_VERSION_NUMBER(9,(__MWERKS__)%100,0)
#   endif
#   if !defined(HASH_PREDEF_COMP_MWERKS_DETECTION) && (__MWERKS__ >= 0x3000)
#       define HASH_PREDEF_COMP_MWERKS_DETECTION HASH_PREDEF_VERSION_NUMBER(8,(__MWERKS__)%100,0)
#   endif
#   if !defined(HASH_PREDEF_COMP_MWERKS_DETECTION)
#       define HASH_PREDEF_COMP_MWERKS_DETECTION HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef HASH_PREDEF_COMP_MWERKS_DETECTION
#   if defined(HASH_PREDEF_DETAIL_COMP_DETECTED)
#       define HASH_PREDEF_COMP_MWERKS_EMULATED HASH_PREDEF_COMP_MWERKS_DETECTION
#   else
#       undef HASH_PREDEF_COMP_MWERKS
#       define HASH_PREDEF_COMP_MWERKS HASH_PREDEF_COMP_MWERKS_DETECTION
#   endif
#   define HASH_PREDEF_COMP_MWERKS_AVAILABLE
#   include <predef/detail/comp_detected.h>
#endif

#define HASH_PREDEF_COMP_MWERKS_NAME "Metrowerks CodeWarrior"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_MWERKS,HASH_PREDEF_COMP_MWERKS_NAME)

#ifdef HASH_PREDEF_COMP_MWERKS_EMULATED
#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_MWERKS_EMULATED,HASH_PREDEF_COMP_MWERKS_NAME)
#endif
