/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_OS_CYGWIN_H
#define HASH_PREDEF_OS_CYGWIN_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_OS_CYGWIN`

http://en.wikipedia.org/wiki/Cygwin[Cygwin] evironment.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__CYGWIN__+` | {predef_detection}

| `CYGWIN_VERSION_API_MAJOR`, `CYGWIN_VERSION_API_MINOR` | V.R.0
|===
*/ // end::reference[]

#define HASH_PREDEF_OS_CYGWIN HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(HASH_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(__CYGWIN__) \
    )
#   include <cygwin/version.h>
#   undef HASH_PREDEF_OS_CYGWIN
#   define HASH_PREDEF_OS_CYGWIN \
        HASH_PREDEF_VERSION_NUMBER(CYGWIN_VERSION_API_MAJOR,\
                             CYGWIN_VERSION_API_MINOR, 0)
#endif

#if HASH_PREDEF_OS_CYGWIN
#   define HASH_PREDEF_OS_CYGWIN_AVAILABLE
#   include <predef/detail/os_detected.h>
#endif

#define HASH_PREDEF_OS_CYGWIN_NAME "Cygwin"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_OS_CYGWIN,HASH_PREDEF_OS_CYGWIN_NAME)
