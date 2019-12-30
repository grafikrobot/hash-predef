/*
  Copyright 2017 James E. King, III
  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE_1_0.txt or copy at
    http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_PLAT_CLOUDABI_H
#define HASH_PREDEF_PLAT_CLOUDABI_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_PLAT_CLOUDABI`

https://github.com/NuxiNL/cloudabi[CloudABI] platform.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__CloudABI__+` | {predef_detection}
|===
*/ // end::reference[]

#define HASH_PREDEF_PLAT_CLOUDABI HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__CloudABI__)
#   undef HASH_PREDEF_PLAT_CLOUDABI
#   define HASH_PREDEF_PLAT_CLOUDABI HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#if HASH_PREDEF_PLAT_CLOUDABI
#   define HASH_PREDEF_PLAT_CLOUDABI_AVAILABLE
#   include <predef/detail/platform_detected.h>
#endif

#define HASH_PREDEF_PLAT_CLOUDABI_NAME "CloudABI"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_PLAT_CLOUDABI,HASH_PREDEF_PLAT_CLOUDABI_NAME)
