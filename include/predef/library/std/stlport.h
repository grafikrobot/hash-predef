/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_LIBRARY_STD_STLPORT_H
#define HASH_PREDEF_LIBRARY_STD_STLPORT_H

#include <predef/library/std/_prefix.h>

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_LIB_STD_STLPORT`

http://sourceforge.net/projects/stlport/[STLport Standard {CPP}] library.
Version number available as major, minor, and patch.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__SGI_STL_PORT+` | {predef_detection}
| `+_STLPORT_VERSION+` | {predef_detection}

| `+_STLPORT_MAJOR+`, `+_STLPORT_MINOR+`, `+_STLPORT_PATCHLEVEL+` | V.R.P
| `+_STLPORT_VERSION+` | V.R.P
| `+__SGI_STL_PORT+` | V.R.P
|===
*/ // end::reference[]

#define HASH_PREDEF_LIB_STD_STLPORT HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__SGI_STL_PORT) || defined(_STLPORT_VERSION)
#   undef HASH_PREDEF_LIB_STD_STLPORT
#   if !defined(HASH_PREDEF_LIB_STD_STLPORT) && defined(_STLPORT_MAJOR)
#       define HASH_PREDEF_LIB_STD_STLPORT \
            HASH_PREDEF_VERSION_NUMBER(_STLPORT_MAJOR,_STLPORT_MINOR,_STLPORT_PATCHLEVEL)
#   endif
#   if !defined(HASH_PREDEF_LIB_STD_STLPORT) && defined(_STLPORT_VERSION)
#       define HASH_PREDEF_LIB_STD_STLPORT HASH_PREDEF_MAKE_0X_VRP(_STLPORT_VERSION)
#   endif
#   if !defined(HASH_PREDEF_LIB_STD_STLPORT)
#       define HASH_PREDEF_LIB_STD_STLPORT HASH_PREDEF_MAKE_0X_VRP(__SGI_STL_PORT)
#   endif
#endif

#if HASH_PREDEF_LIB_STD_STLPORT
#   define HASH_PREDEF_LIB_STD_STLPORT_AVAILABLE
#endif

#define HASH_PREDEF_LIB_STD_STLPORT_NAME "STLport"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_LIB_STD_STLPORT,HASH_PREDEF_LIB_STD_STLPORT_NAME)
