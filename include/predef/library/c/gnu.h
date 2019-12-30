/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_LIBRARY_C_GNU_H
#define HASH_PREDEF_LIBRARY_C_GNU_H

#include <predef/version_number.h>
#include <predef/make.h>

#include <predef/library/c/_prefix.h>

#if defined(__STDC__)
#include <stddef.h>
#elif defined(__cplusplus)
#include <cstddef>
#endif

/* tag::reference[]
= `HASH_PREDEF_LIB_C_GNU`

http://en.wikipedia.org/wiki/Glibc[GNU glibc] Standard C library.
Version number available as major, and minor.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__GLIBC__+` | {predef_detection}
| `+__GNU_LIBRARY__+` | {predef_detection}

| `+__GLIBC__+`, `+__GLIBC_MINOR__+` | V.R.0
| `+__GNU_LIBRARY__+`, `+__GNU_LIBRARY_MINOR__+` | V.R.0
|===
*/ // end::reference[]

#define HASH_PREDEF_LIB_C_GNU HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__GLIBC__) || defined(__GNU_LIBRARY__)
#   undef HASH_PREDEF_LIB_C_GNU
#   if defined(__GLIBC__)
#       define HASH_PREDEF_LIB_C_GNU \
            HASH_PREDEF_VERSION_NUMBER(__GLIBC__,__GLIBC_MINOR__,0)
#   else
#       define HASH_PREDEF_LIB_C_GNU \
            HASH_PREDEF_VERSION_NUMBER(__GNU_LIBRARY__,__GNU_LIBRARY_MINOR__,0)
#   endif
#endif

#if HASH_PREDEF_LIB_C_GNU
#   define HASH_PREDEF_LIB_C_GNU_AVAILABLE
#endif

#define HASH_PREDEF_LIB_C_GNU_NAME "GNU"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_LIB_C_GNU,HASH_PREDEF_LIB_C_GNU_NAME)
