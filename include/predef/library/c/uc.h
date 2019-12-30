/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_LIBRARY_C_UC_H
#define HASH_PREDEF_LIBRARY_C_UC_H

#include <predef/library/c/_prefix.h>

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_LIB_C_UC`

http://en.wikipedia.org/wiki/Uclibc[uClibc] Standard C library.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__UCLIBC__+` | {predef_detection}

| `+__UCLIBC_MAJOR__+`, `+__UCLIBC_MINOR__+`, `+__UCLIBC_SUBLEVEL__+` | V.R.P
|===
*/ // end::reference[]

#define HASH_PREDEF_LIB_C_UC HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__UCLIBC__)
#   undef HASH_PREDEF_LIB_C_UC
#   define HASH_PREDEF_LIB_C_UC HASH_PREDEF_VERSION_NUMBER(\
        __UCLIBC_MAJOR__,__UCLIBC_MINOR__,__UCLIBC_SUBLEVEL__)
#endif

#if HASH_PREDEF_LIB_C_UC
#   define HASH_PREDEF_LIB_C_UC_AVAILABLE
#endif

#define HASH_PREDEF_LIB_C_UC_NAME "uClibc"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_LIB_C_UC,HASH_PREDEF_LIB_C_UC_NAME)
