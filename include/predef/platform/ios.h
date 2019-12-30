/*
Copyright Ruslan Baratov 2017
Copyright Rene Rivera 2017
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_PLAT_IOS_H
#define HASH_PREDEF_PLAT_IOS_H

#include <predef/os/ios.h> // HASH_PREDEF_OS_IOS
#include <predef/version_number.h> // HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

/* tag::reference[]
= `HASH_PREDEF_PLAT_IOS_DEVICE`
= `HASH_PREDEF_PLAT_IOS_SIMULATOR`

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `TARGET_IPHONE_SIMULATOR` | {predef_detection}
| `TARGET_OS_SIMULATOR` | {predef_detection}
|===
*/ // end::reference[]

#define HASH_PREDEF_PLAT_IOS_DEVICE HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE
#define HASH_PREDEF_PLAT_IOS_SIMULATOR HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

// https://opensource.apple.com/source/CarbonHeaders/CarbonHeaders-18.1/TargetConditionals.h
#if HASH_PREDEF_OS_IOS
#    include <TargetConditionals.h>
#    if defined(TARGET_OS_SIMULATOR) && (TARGET_OS_SIMULATOR == 1)
#        undef HASH_PREDEF_PLAT_IOS_SIMULATOR
#        define HASH_PREDEF_PLAT_IOS_SIMULATOR HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#    elif defined(TARGET_IPHONE_SIMULATOR) && (TARGET_IPHONE_SIMULATOR == 1)
#        undef HASH_PREDEF_PLAT_IOS_SIMULATOR
#        define HASH_PREDEF_PLAT_IOS_SIMULATOR HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#    else
#        undef HASH_PREDEF_PLAT_IOS_DEVICE
#        define HASH_PREDEF_PLAT_IOS_DEVICE HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#    endif
#endif

#if HASH_PREDEF_PLAT_IOS_SIMULATOR
#    define HASH_PREDEF_PLAT_IOS_SIMULATOR_AVAILABLE
#    include <predef/detail/platform_detected.h>
#endif

#if HASH_PREDEF_PLAT_IOS_DEVICE
#    define HASH_PREDEF_PLAT_IOS_DEVICE_AVAILABLE
#    include <predef/detail/platform_detected.h>
#endif

#define HASH_PREDEF_PLAT_IOS_SIMULATOR_NAME "iOS Simulator"
#define HASH_PREDEF_PLAT_IOS_DEVICE_NAME "iOS Device"

#endif // HASH_PREDEF_PLAT_IOS_H

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_PLAT_IOS_SIMULATOR,HASH_PREDEF_PLAT_IOS_SIMULATOR_NAME)
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_PLAT_IOS_DEVICE,HASH_PREDEF_PLAT_IOS_DEVICE_NAME)
