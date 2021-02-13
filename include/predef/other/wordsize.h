/*
Copyright Rene Ferdinand Rivera Morell 2020-2021
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_OTHER_WORD_SIZE_H
#define HASH_PREDEF_OTHER_WORD_SIZE_H

#include <predef/architecture.h>
#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_ARCH_WORD_BITS`

Detects the native word size, in bits, for the current architecture. There are
two types of macros for this detection:

* `HASH_PREDEF_ARCH_WORD_BITS`, gives the number of word size bits
  (16, 32, 64).
* `HASH_PREDEF_ARCH_WORD_BITS_16`, `HASH_PREDEF_ARCH_WORD_BITS_32`, and
  `HASH_PREDEF_ARCH_WORD_BITS_64`, indicate when the given word size is
  detected.

They allow for both single checks and direct use of the size in code.

NOTE: The word size is determined manually on each architecture. Hence use of
the `wordsize.h` header will also include all the architecture headers.

*/ // end::reference[]

#if !defined(HASH_PREDEF_ARCH_WORD_BITS_64)
#   define HASH_PREDEF_ARCH_WORD_BITS_64 HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE
#elif !defined(HASH_PREDEF_ARCH_WORD_BITS)
#   define HASH_PREDEF_ARCH_WORD_BITS 64
#endif

#if !defined(HASH_PREDEF_ARCH_WORD_BITS_32)
#   define HASH_PREDEF_ARCH_WORD_BITS_32 HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE
#elif !defined(HASH_PREDEF_ARCH_WORD_BITS)
#	  define HASH_PREDEF_ARCH_WORD_BITS 32
#endif

#if !defined(HASH_PREDEF_ARCH_WORD_BITS_16)
#   define HASH_PREDEF_ARCH_WORD_BITS_16 HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE
#elif !defined(HASH_PREDEF_ARCH_WORD_BITS)
#   define HASH_PREDEF_ARCH_WORD_BITS 16
#endif

#if !defined(HASH_PREDEF_ARCH_WORD_BITS)
#   define HASH_PREDEF_ARCH_WORD_BITS 0
#endif

#define HASH_PREDEF_ARCH_WORD_BITS_NAME "Word Bits"
#define HASH_PREDEF_ARCH_WORD_BITS_16_NAME "16-bit Word Size"
#define HASH_PREDEF_ARCH_WORD_BITS_32_NAME "32-bit Word Size"
#define HASH_PREDEF_ARCH_WORD_BITS_64_NAME "64-bit Word Size"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_ARCH_WORD_BITS,HASH_PREDEF_ARCH_WORD_BITS_NAME)

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_ARCH_WORD_BITS_16,HASH_PREDEF_ARCH_WORD_BITS_16_NAME)

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_ARCH_WORD_BITS_32,HASH_PREDEF_ARCH_WORD_BITS_32_NAME)

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_ARCH_WORD_BITS_64,HASH_PREDEF_ARCH_WORD_BITS_64_NAME)
