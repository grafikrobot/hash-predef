/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_LIBRARY_STD_MODENA_H
#define HASH_PREDEF_LIBRARY_STD_MODENA_H

#include <predef/library/std/_prefix.h>

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_LIB_STD_MSIPL`

http://modena.us/[Modena Software Lib++] Standard {CPP} Library.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `MSIPL_COMPILE_H` | {predef_detection}
| `+__MSIPL_COMPILE_H+` | {predef_detection}
|===
*/ // end::reference[]

#define HASH_PREDEF_LIB_STD_MSIPL HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(MSIPL_COMPILE_H) || defined(__MSIPL_COMPILE_H)
#   undef HASH_PREDEF_LIB_STD_MSIPL
#   define HASH_PREDEF_LIB_STD_MSIPL HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#if HASH_PREDEF_LIB_STD_MSIPL
#   define HASH_PREDEF_LIB_STD_MSIPL_AVAILABLE
#endif

#define HASH_PREDEF_LIB_STD_MSIPL_NAME "Modena Software Lib++"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_LIB_STD_MSIPL,HASH_PREDEF_LIB_STD_MSIPL_NAME)
