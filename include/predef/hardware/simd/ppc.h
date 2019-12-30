/*
Copyright Charly Chevalier 2015
Copyright Joel Falcou 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_HARDWARE_SIMD_PPC_H
#define HASH_PREDEF_HARDWARE_SIMD_PPC_H

#include <predef/version_number.h>
#include <predef/hardware/simd/ppc/versions.h>

/* tag::reference[]
= `HASH_PREDEF_HW_SIMD_PPC`

The SIMD extension for PowerPC (*if detected*).
Version number depends on the most recent detected extension.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__VECTOR4DOUBLE__+` | {predef_detection}

| `+__ALTIVEC__+` | {predef_detection}
| `+__VEC__+` | {predef_detection}

| `+__VSX__+` | {predef_detection}
|===

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__VECTOR4DOUBLE__+` | HASH_PREDEF_HW_SIMD_PPC_QPX_VERSION

| `+__ALTIVEC__+` | HASH_PREDEF_HW_SIMD_PPC_VMX_VERSION
| `+__VEC__+` | HASH_PREDEF_HW_SIMD_PPC_VMX_VERSION

| `+__VSX__+` | HASH_PREDEF_HW_SIMD_PPC_VSX_VERSION
|===

*/ // end::reference[]

#define HASH_PREDEF_HW_SIMD_PPC HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#undef HASH_PREDEF_HW_SIMD_PPC
#if !defined(HASH_PREDEF_HW_SIMD_PPC) && defined(__VECTOR4DOUBLE__)
#   define HASH_PREDEF_HW_SIMD_PPC HASH_PREDEF_HW_SIMD_PPC_QPX_VERSION
#endif
#if !defined(HASH_PREDEF_HW_SIMD_PPC) && defined(__VSX__)
#   define HASH_PREDEF_HW_SIMD_PPC HASH_PREDEF_HW_SIMD_PPC_VSX_VERSION
#endif
#if !defined(HASH_PREDEF_HW_SIMD_PPC) && (defined(__ALTIVEC__) || defined(__VEC__))
#   define HASH_PREDEF_HW_SIMD_PPC HASH_PREDEF_HW_SIMD_PPC_VMX_VERSION
#endif

#if !defined(HASH_PREDEF_HW_SIMD_PPC)
#   define HASH_PREDEF_HW_SIMD_PPC HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE
#else
#   define HASH_PREDEF_HW_SIMD_PPC_AVAILABLE
#endif

#define HASH_PREDEF_HW_SIMD_PPC_NAME "PPC SIMD"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_HW_SIMD_PPC, HASH_PREDEF_HW_SIMD_PPC_NAME)
