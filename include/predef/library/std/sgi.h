/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_LIBRARY_STD_SGI_H
#define HASH_PREDEF_LIBRARY_STD_SGI_H

#include <predef/library/std/_prefix.h>

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_LIB_STD_SGI`

http://www.sgi.com/tech/stl/[SGI] Standard {CPP} library.
If available version number as major, minor, and patch.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__STL_CONFIG_H+` | {predef_detection}

| `+__SGI_STL+` | V.R.P
|===
*/ // end::reference[]

#define HASH_PREDEF_LIB_STD_SGI HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__STL_CONFIG_H)
#   undef HASH_PREDEF_LIB_STD_SGI
#   if defined(__SGI_STL)
#       define HASH_PREDEF_LIB_STD_SGI HASH_PREDEF_MAKE_0X_VRP(__SGI_STL)
#   else
#       define HASH_PREDEF_LIB_STD_SGI HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if HASH_PREDEF_LIB_STD_SGI
#   define HASH_PREDEF_LIB_STD_SGI_AVAILABLE
#endif

#define HASH_PREDEF_LIB_STD_SGI_NAME "SGI"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_LIB_STD_SGI,HASH_PREDEF_LIB_STD_SGI_NAME)
