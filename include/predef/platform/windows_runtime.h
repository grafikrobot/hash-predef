/*
Copyright (c) Microsoft Corporation 2014
Copyright Rene Rivera 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_PLAT_WINDOWS_RUNTIME_H
#define HASH_PREDEF_PLAT_WINDOWS_RUNTIME_H

#include <predef/make.h>
#include <predef/os/windows.h>
#include <predef/platform/windows_phone.h>
#include <predef/platform/windows_store.h>
#include <predef/version_number.h>

/* tag::reference[]
= `HASH_PREDEF_PLAT_WINDOWS_RUNTIME`

Deprecated.

https://docs.microsoft.com/en-us/windows/uwp/get-started/universal-application-platform-guide[UWP]
for Windows Phone or Store development.  This does not align to the existing development model for
UWP and is deprecated.  Use one of the other `HASH_PREDEF_PLAT_WINDOWS_*`definitions instead.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `HASH_PREDEF_PLAT_WINDOWS_PHONE` | {predef_detection}
| `HASH_PREDEF_PLAT_WINDOWS_STORE` | {predef_detection}
|===
*/ // end::reference[]

#define HASH_PREDEF_PLAT_WINDOWS_RUNTIME HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if HASH_PREDEF_OS_WINDOWS && \
    (HASH_PREDEF_PLAT_WINDOWS_STORE || HASH_PREDEF_PLAT_WINDOWS_PHONE)
#   undef HASH_PREDEF_PLAT_WINDOWS_RUNTIME
#   define HASH_PREDEF_PLAT_WINDOWS_RUNTIME HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif
 
#if HASH_PREDEF_PLAT_WINDOWS_RUNTIME
#   define HASH_PREDEF_PLAT_WINDOWS_RUNTIME_AVAILABLE
#   include <predef/detail/platform_detected.h>
#endif

#define HASH_PREDEF_PLAT_WINDOWS_RUNTIME_NAME "Windows Runtime"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_PLAT_WINDOWS_RUNTIME,HASH_PREDEF_PLAT_WINDOWS_RUNTIME_NAME)
