/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_LIBRARY_C_VMS_H
#define HASH_PREDEF_LIBRARY_C_VMS_H

#include <predef/library/c/_prefix.h>

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_LIB_C_VMS`

VMS libc Standard C library.
Version number available as major, minor, and patch.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__CRTL_VER+` | {predef_detection}

| `+__CRTL_VER+` | V.R.P
|===
*/ // end::reference[]

#define HASH_PREDEF_LIB_C_VMS HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__CRTL_VER)
#   undef HASH_PREDEF_LIB_C_VMS
#   define HASH_PREDEF_LIB_C_VMS HASH_PREDEF_MAKE_10_VVRR0PP00(__CRTL_VER)
#endif

#if HASH_PREDEF_LIB_C_VMS
#   define HASH_PREDEF_LIB_C_VMS_AVAILABLE
#endif

#define HASH_PREDEF_LIB_C_VMS_NAME "VMS"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_LIB_C_VMS,HASH_PREDEF_LIB_C_VMS_NAME)
