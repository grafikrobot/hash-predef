/*
Copyright Charly Chevalier 2015
Copyright Joel Falcou 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_HARDWARE_SIMD_ARM_H
#define HASH_PREDEF_HARDWARE_SIMD_ARM_H

#include <predef/version_number.h>
#include <predef/hardware/simd/arm/versions.h>

/*`
[heading `HASH_PREDEF_HW_SIMD_ARM`]

The SIMD extension for ARM (*if detected*).
Version number depends on the most recent detected extension.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__ARM_NEON__`] [__predef_detection__]]
    [[`__aarch64__`] [__predef_detection__]]
    [[`_M_ARM`] [__predef_detection__]]
    [[`_M_ARM64`] [__predef_detection__]]
    ]

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__ARM_NEON__`] [HASH_PREDEF_HW_SIMD_ARM_NEON_VERSION]]
    [[`__aarch64__`] [HASH_PREDEF_HW_SIMD_ARM_NEON_VERSION]]
    [[`_M_ARM`] [HASH_PREDEF_HW_SIMD_ARM_NEON_VERSION]]
    [[`_M_ARM64`] [HASH_PREDEF_HW_SIMD_ARM_NEON_VERSION]]
    ]

*/

#define HASH_PREDEF_HW_SIMD_ARM HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#undef HASH_PREDEF_HW_SIMD_ARM
#if !defined(HASH_PREDEF_HW_SIMD_ARM) && (defined(__ARM_NEON__) || defined(__aarch64__) || defined (_M_ARM) || defined (_M_ARM64))
#   define HASH_PREDEF_HW_SIMD_ARM HASH_PREDEF_HW_SIMD_ARM_NEON_VERSION
#endif

#if !defined(HASH_PREDEF_HW_SIMD_ARM)
#   define HASH_PREDEF_HW_SIMD_ARM HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE
#else
#   define HASH_PREDEF_HW_SIMD_ARM_AVAILABLE
#endif

#define HASH_PREDEF_HW_SIMD_ARM_NAME "ARM SIMD"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_HW_SIMD_ARM, HASH_PREDEF_HW_SIMD_ARM_NAME)
