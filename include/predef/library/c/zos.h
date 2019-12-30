/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_LIBRARY_C_ZOS_H
#define HASH_PREDEF_LIBRARY_C_ZOS_H

#include <predef/library/c/_prefix.h>

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_LIB_C_ZOS`

z/OS libc Standard C library.
Version number available as major, minor, and patch.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__LIBREL__+` | {predef_detection}

| `+__LIBREL__+` | V.R.P
| `+__TARGET_LIB__+` | V.R.P
|===
*/ // end::reference[]

#define HASH_PREDEF_LIB_C_ZOS HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__LIBREL__)
#   undef HASH_PREDEF_LIB_C_ZOS
#   if !defined(HASH_PREDEF_LIB_C_ZOS) && defined(__LIBREL__)
#       define HASH_PREDEF_LIB_C_ZOS HASH_PREDEF_MAKE_0X_VRRPPPP(__LIBREL__)
#   endif
#   if !defined(HASH_PREDEF_LIB_C_ZOS) && defined(__TARGET_LIB__)
#       define HASH_PREDEF_LIB_C_ZOS HASH_PREDEF_MAKE_0X_VRRPPPP(__TARGET_LIB__)
#   endif
#   if !defined(HASH_PREDEF_LIB_C_ZOS)
#       define HASH_PREDEF_LIB_C_ZOS HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if HASH_PREDEF_LIB_C_ZOS
#   define HASH_PREDEF_LIB_C_ZOS_AVAILABLE
#endif

#define HASH_PREDEF_LIB_C_ZOS_NAME "z/OS"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_LIB_C_ZOS,HASH_PREDEF_LIB_C_ZOS_NAME)
