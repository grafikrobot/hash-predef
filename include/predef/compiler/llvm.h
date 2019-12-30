/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_COMPILER_LLVM_H
#define HASH_PREDEF_COMPILER_LLVM_H

/* Other compilers that emulate this one need to be detected first. */

#include <predef/compiler/clang.h>

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_COMP_LLVM`

http://en.wikipedia.org/wiki/LLVM[LLVM] compiler.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__llvm__+` | {predef_detection}
|===
*/ // end::reference[]

#define HASH_PREDEF_COMP_LLVM HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__llvm__)
#   define HASH_PREDEF_COMP_LLVM_DETECTION HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#ifdef HASH_PREDEF_COMP_LLVM_DETECTION
#   if defined(HASH_PREDEF_DETAIL_COMP_DETECTED)
#       define HASH_PREDEF_COMP_LLVM_EMULATED HASH_PREDEF_COMP_LLVM_DETECTION
#   else
#       undef HASH_PREDEF_COMP_LLVM
#       define HASH_PREDEF_COMP_LLVM HASH_PREDEF_COMP_LLVM_DETECTION
#   endif
#   define HASH_PREDEF_COMP_LLVM_AVAILABLE
#   include <predef/detail/comp_detected.h>
#endif

#define HASH_PREDEF_COMP_LLVM_NAME "LLVM"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_LLVM,HASH_PREDEF_COMP_LLVM_NAME)

#ifdef HASH_PREDEF_COMP_LLVM_EMULATED
#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_LLVM_EMULATED,HASH_PREDEF_COMP_LLVM_NAME)
#endif
