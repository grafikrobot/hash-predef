/*
Copyright Zhang Na 2022
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_ARCHITECTURE_LOONGARCH_H
#define HASH_PREDEF_ARCHITECTURE_LOONGARCH_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_ARCH_LOONGARCH`

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__loongarch__+` | {predef_detection}
|===
*/ // end::reference[]

#define HASH_PREDEF_ARCH_LOONGARCH HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__loongarch__)
#   undef HASH_PREDEF_ARCH_LOONGARCH
#   define HASH_PREDEF_ARCH_LOONGARCH HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#if HASH_PREDEF_ARCH_LOONGARCH
#   define HASH_PREDEF_ARCH_LOONGARCH_AVAILABLE
#endif

#define HASH_PREDEF_ARCH_LOONGARCH_NAME "LoongArch"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_ARCH_LOONGARCH,HASH_PREDEF_ARCH_LOONGARCH_NAME)
