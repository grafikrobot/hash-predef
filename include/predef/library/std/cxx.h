/*
Copyright Rene Rivera 2011-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_LIBRARY_STD_CXX_H
#define HASH_PREDEF_LIBRARY_STD_CXX_H

#include <predef/library/std/_prefix.h>

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_LIB_STD_CXX`

http://libcxx.llvm.org/[libc++] {CPP} Standard Library.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+_LIBCPP_VERSION+` | {predef_detection}

| `+_LIBCPP_VERSION+` | V.0.P
|===
*/ // end::reference[]

#define HASH_PREDEF_LIB_STD_CXX HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(_LIBCPP_VERSION)
#   undef HASH_PREDEF_LIB_STD_CXX
#   define HASH_PREDEF_LIB_STD_CXX HASH_PREDEF_MAKE_10_VVPPP(_LIBCPP_VERSION)
#endif

#if HASH_PREDEF_LIB_STD_CXX
#   define HASH_PREDEF_LIB_STD_CXX_AVAILABLE
#endif

#define HASH_PREDEF_LIB_STD_CXX_NAME "libc++"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_LIB_STD_CXX,HASH_PREDEF_LIB_STD_CXX_NAME)
