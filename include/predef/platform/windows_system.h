/*
Copyright James E. King III, 2017
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_PLAT_WINDOWS_SYSTEM_H
#define HASH_PREDEF_PLAT_WINDOWS_SYSTEM_H

#include <predef/make.h>
#include <predef/os/windows.h>
#include <predef/platform/windows_uwp.h>
#include <predef/version_number.h>

/* tag::reference[]
= `HASH_PREDEF_PLAT_WINDOWS_SYSTEM`

https://docs.microsoft.com/en-us/windows/uwp/get-started/universal-application-platform-guide[UWP]
for Windows System development.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `WINAPI_FAMILY == WINAPI_FAMILY_SYSTEM` | {predef_detection}
|===
*/ // end::reference[]

#define HASH_PREDEF_PLAT_WINDOWS_SYSTEM HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if HASH_PREDEF_OS_WINDOWS && \
    defined(WINAPI_FAMILY_SYSTEM) && WINAPI_FAMILY == WINAPI_FAMILY_SYSTEM
#   undef HASH_PREDEF_PLAT_WINDOWS_SYSTEM
#   define HASH_PREDEF_PLAT_WINDOWS_SYSTEM HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif
 
#if HASH_PREDEF_PLAT_WINDOWS_SYSTEM
#   define HASH_PREDEF_PLAT_WINDOWS_SYSTEM_AVAILABLE
#   include <predef/detail/platform_detected.h>
#endif

#define HASH_PREDEF_PLAT_WINDOWS_SYSTEM_NAME "Windows Drivers and Tools"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_PLAT_WINDOWS_SYSTEM,HASH_PREDEF_PLAT_WINDOWS_SYSTEM_NAME)
