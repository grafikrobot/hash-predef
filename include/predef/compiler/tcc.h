/*
Copyright Kornel Ponikwicki 2025
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_COMPILER_TCC_H
#define HASH_PREDEF_COMPILER_TCC_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_COMP_TCC`

https://en.wikipedia.org/wiki/Tiny_C_Compiler[Tiny C Compiler] (TinyCC or TCC for short).
Version number available as major, minor, and patch.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__TINYC__+` | {predef_detection}

| `+__TINYC__+` | 0.9.P
|===
*/ // end::reference[]

#define HASH_PREDEF_COMP_TCC HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__TINYC__) && !defined(HASH_PREDEF_COMP_TCC_DETECTION)
    /* Helper macros for checking if __TINYC__ expands to any value */
#   define _HASH_PREDEF_COMP_TCC_HAS_VALUE(VALUE) (_HASH_PREDEF_COMP_TCC_EXPAND(VALUE) != 1)
#   define _HASH_PREDEF_COMP_TCC_EXPAND(VALUE) _HASH_PREDEF_COMP_TCC_CONCAT(VALUE)
#   define _HASH_PREDEF_COMP_TCC_CONCAT(VALUE) (VALUE ## 1)
    /*
    TCC version is defined in __TINYC__ as {MINOR}{PATCH},
    meaning that 0.9.27 would be 927 (0 for {MAJOR} is skipped).
    Before 0.9.26 macro was defined but not set to any value.
    Since TCC was always released under versions 0.9.x
    we can assume that said macro either ranges between 926 and 999
    or that the version is at least 0.9.0.
    This will, of course, break if {MAJOR} or {MINOR} changes,
    which has never happened (as of January 2025).
    */
#   if _HASH_PREDEF_COMP_TCC_HAS_VALUE(__TINYC__)
#       if (__TINYC__ < 926 || __TINYC__ > 999)
#           error "Cannot determine TCC version from __TINYC__"
#       endif
#       define HASH_PREDEF_COMP_TCC_DETECTION HASH_PREDEF_VERSION_NUMBER(\
            0,\
            __TINYC__/100,\
            __TINYC__%100)
#   else
#       define HASH_PREDEF_COMP_TCC_DETECTION HASH_PREDEF_VERSION_NUMBER(0,9,0)
#   endif
    /* We will not need these macros anymore */
#   undef _HASH_PREDEF_COMP_TCC_HAS_VALUE
#   undef _HASH_PREDEF_COMP_TCC_EXPAND
#   undef _HASH_PREDEF_COMP_TCC_CONCAT
#endif

#ifdef HASH_PREDEF_COMP_TCC_DETECTION
#   if defined(HASH_PREDEF_DETAIL_COMP_DETECTED)
#       define HASH_PREDEF_COMP_TCC_EMULATED HASH_PREDEF_COMP_TCC_DETECTION
#   else
#       undef HASH_PREDEF_COMP_TCC
#       define HASH_PREDEF_COMP_TCC HASH_PREDEF_COMP_TCC_DETECTION
#   endif
#   define HASH_PREDEF_COMP_TCC_AVAILABLE
#   include <predef/detail/comp_detected.h>
#endif

#define HASH_PREDEF_COMP_TCC_NAME "Tiny C Compiler"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_TCC,HASH_PREDEF_COMP_TCC_NAME)

#ifdef HASH_PREDEF_COMP_TCC_EMULATED
#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_TCC_EMULATED,HASH_PREDEF_COMP_TCC_NAME)
#endif
