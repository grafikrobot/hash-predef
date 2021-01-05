/*
Copyright Andreas Schwab 2019
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_ARCHITECTURE_RISCV_H
#define HASH_PREDEF_ARCHITECTURE_RISCV_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_ARCH_RISCV`

http://en.wikipedia.org/wiki/RISC-V[RISC-V] architecture.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__riscv+` | {predef_detection}
|===
*/ // end::reference[]

#define HASH_PREDEF_ARCH_RISCV HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__riscv)
#   undef HASH_PREDEF_ARCH_RISCV
#   define HASH_PREDEF_ARCH_RISCV HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#if HASH_PREDEF_ARCH_RISCV
#   define HASH_PREDEF_ARCH_RISCV_AVAILABLE
#endif

#if HASH_PREDEF_ARCH_RISCV
#   undef HASH_PREDEF_ARCH_WORD_BITS_32
#   define HASH_PREDEF_ARCH_WORD_BITS_32 HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#define HASH_PREDEF_ARCH_RISCV_NAME "RISC-V"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_ARCH_RISCV,HASH_PREDEF_ARCH_RISCV_NAME)
