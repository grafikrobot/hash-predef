/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#include <predef/architecture/x86/32.h>
#include <predef/architecture/x86/64.h>

#ifndef HASH_PREDEF_ARCHITECTURE_X86_H
#define HASH_PREDEF_ARCHITECTURE_X86_H

/* tag::reference[]
= `HASH_PREDEF_ARCH_X86`

http://en.wikipedia.org/wiki/X86[Intel x86] architecture. This is
a category to indicate that either `HASH_PREDEF_ARCH_X86_32` or
`HASH_PREDEF_ARCH_X86_64` is detected.
*/ // end::reference[]

#define HASH_PREDEF_ARCH_X86 HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if HASH_PREDEF_ARCH_X86_32 || HASH_PREDEF_ARCH_X86_64
#   undef HASH_PREDEF_ARCH_X86
#   define HASH_PREDEF_ARCH_X86 HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#if HASH_PREDEF_ARCH_X86
#   define HASH_PREDEF_ARCH_X86_AVAILABLE
#endif

#define HASH_PREDEF_ARCH_X86_NAME "Intel x86"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_ARCH_X86,HASH_PREDEF_ARCH_X86_NAME)
