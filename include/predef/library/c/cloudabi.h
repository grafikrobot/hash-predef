/*
 * Copyright (C) 2017 James E. King III
 *
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef HASH_PREDEF_LIBRARY_C_CLOUDABI_H
#define HASH_PREDEF_LIBRARY_C_CLOUDABI_H

#include <predef/version_number.h>
#include <predef/make.h>

#include <predef/library/c/_prefix.h>

#if defined(__CloudABI__)
#include <stddef.h>
#endif

/* tag::reference[]
= `HASH_PREDEF_LIB_C_CLOUDABI`

https://github.com/NuxiNL/cloudlibc[cloudlibc] - CloudABI's standard C library.
Version number available as major, and minor.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__cloudlibc__+` | {predef_detection}

| `+__cloudlibc_major__+`, `+__cloudlibc_minor__+` | V.R.0
|===
*/ // end::reference[]

#define HASH_PREDEF_LIB_C_CLOUDABI HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__cloudlibc__)
#   undef HASH_PREDEF_LIB_C_CLOUDABI
#   define HASH_PREDEF_LIB_C_CLOUDABI \
            HASH_PREDEF_VERSION_NUMBER(__cloudlibc_major__,__cloudlibc_minor__,0)
#endif

#if HASH_PREDEF_LIB_C_CLOUDABI
#   define HASH_PREDEF_LIB_C_CLOUDABI_AVAILABLE
#endif

#define HASH_PREDEF_LIB_C_CLOUDABI_NAME "cloudlibc"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_LIB_C_CLOUDABI,HASH_PREDEF_LIB_C_CLOUDABI_NAME)
