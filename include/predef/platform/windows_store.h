/*
Copyright (c) Microsoft Corporation 2014
Copyright Rene Rivera 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_PLAT_WINDOWS_STORE_H
#define HASH_PREDEF_PLAT_WINDOWS_STORE_H

#include <predef/make.h>
#include <predef/os/windows.h>
#include <predef/platform/windows_uwp.h>
#include <predef/version_number.h>

/* tag::reference[]
= `HASH_PREDEF_PLAT_WINDOWS_STORE`

https://docs.microsoft.com/en-us/windows/uwp/get-started/universal-application-platform-guide[UWP]
for Windows Store development.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `WINAPI_FAMILY == WINAPI_FAMILY_PC_APP` | {predef_detection}
| `WINAPI_FAMILY == WINAPI_FAMILY_APP` (deprecated) | {predef_detection}
|===
*/ // end::reference[]

#define HASH_PREDEF_PLAT_WINDOWS_STORE HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if HASH_PREDEF_OS_WINDOWS && \
    ((defined(WINAPI_FAMILY_PC_APP) && WINAPI_FAMILY == WINAPI_FAMILY_PC_APP) || \
     (defined(WINAPI_FAMILY_APP)    && WINAPI_FAMILY == WINAPI_FAMILY_APP))
#   undef HASH_PREDEF_PLAT_WINDOWS_STORE
#   define HASH_PREDEF_PLAT_WINDOWS_STORE HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif
 
#if HASH_PREDEF_PLAT_WINDOWS_STORE
#   define HASH_PREDEF_PLAT_WINDOWS_STORE_AVAILABLE
#   include <predef/detail/platform_detected.h>
#endif

#define HASH_PREDEF_PLAT_WINDOWS_STORE_NAME "Windows Store"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_PLAT_WINDOWS_STORE,HASH_PREDEF_PLAT_WINDOWS_STORE_NAME)
