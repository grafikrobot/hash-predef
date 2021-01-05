/*
Copyright Benjamin Worpitz 2018
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_ARCHITECTURE_PTX_H
#define HASH_PREDEF_ARCHITECTURE_PTX_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_ARCH_PTX`

https://en.wikipedia.org/wiki/Parallel_Thread_Execution[PTX] architecture.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__CUDA_ARCH__+` | {predef_detection}

| `+__CUDA_ARCH__+` | V.R.0
|===
*/ // end::reference[]

#define HASH_PREDEF_ARCH_PTX HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__CUDA_ARCH__)
#   undef HASH_PREDEF_ARCH_PTX
#   define HASH_PREDEF_ARCH_PTX HASH_PREDEF_MAKE_10_VR0(__CUDA_ARCH__)
#endif

#if HASH_PREDEF_ARCH_PTX
#   define HASH_PREDEF_ARCH_PTX_AVAILABLE
#endif

#if HASH_PREDEF_ARCH_PTX
#   undef HASH_PREDEF_ARCH_WORD_BITS_64
#   define HASH_PREDEF_ARCH_WORD_BITS_64 HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#define HASH_PREDEF_ARCH_PTX_NAME "PTX"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_ARCH_PTX,HASH_PREDEF_ARCH_PTX_NAME)
