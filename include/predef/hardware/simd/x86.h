/*
Copyright Charly Chevalier 2015
Copyright Joel Falcou 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_HARDWARE_SIMD_X86_H
#define HASH_PREDEF_HARDWARE_SIMD_X86_H

#include <predef/version_number.h>
#include <predef/hardware/simd/x86/versions.h>

/*`
 [heading `HASH_PREDEF_HW_SIMD_X86`]

 The SIMD extension for x86 (*if detected*).
 Version number depends on the most recent detected extension.

 [table
     [[__predef_symbol__] [__predef_version__]]

     [[`__SSE__`] [__predef_detection__]]
     [[`_M_X64`] [__predef_detection__]]
     [[`_M_IX86_FP >= 1`] [__predef_detection__]]

     [[`__SSE2__`] [__predef_detection__]]
     [[`_M_X64`] [__predef_detection__]]
     [[`_M_IX86_FP >= 2`] [__predef_detection__]]

     [[`__SSE3__`] [__predef_detection__]]

     [[`__SSSE3__`] [__predef_detection__]]

     [[`__SSE4_1__`] [__predef_detection__]]

     [[`__SSE4_2__`] [__predef_detection__]]

     [[`__AVX__`] [__predef_detection__]]

     [[`__FMA__`] [__predef_detection__]]

     [[`__AVX2__`] [__predef_detection__]]
     ]

 [table
     [[__predef_symbol__] [__predef_version__]]

     [[`__SSE__`] [HASH_PREDEF_HW_SIMD_X86_SSE_VERSION]]
     [[`_M_X64`] [HASH_PREDEF_HW_SIMD_X86_SSE_VERSION]]
     [[`_M_IX86_FP >= 1`] [HASH_PREDEF_HW_SIMD_X86_SSE_VERSION]]

     [[`__SSE2__`] [HASH_PREDEF_HW_SIMD_X86_SSE2_VERSION]]
     [[`_M_X64`] [HASH_PREDEF_HW_SIMD_X86_SSE2_VERSION]]
     [[`_M_IX86_FP >= 2`] [HASH_PREDEF_HW_SIMD_X86_SSE2_VERSION]]

     [[`__SSE3__`] [HASH_PREDEF_HW_SIMD_X86_SSE3_VERSION]]

     [[`__SSSE3__`] [HASH_PREDEF_HW_SIMD_X86_SSSE3_VERSION]]

     [[`__SSE4_1__`] [HASH_PREDEF_HW_SIMD_X86_SSE4_1_VERSION]]

     [[`__SSE4_2__`] [HASH_PREDEF_HW_SIMD_X86_SSE4_2_VERSION]]

     [[`__AVX__`] [HASH_PREDEF_HW_SIMD_X86_AVX_VERSION]]

     [[`__FMA__`] [HASH_PREDEF_HW_SIMD_X86_FMA3_VERSION]]

     [[`__AVX2__`] [HASH_PREDEF_HW_SIMD_X86_AVX2_VERSION]]
     ]

 */

#define HASH_PREDEF_HW_SIMD_X86 HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#undef HASH_PREDEF_HW_SIMD_X86
#if !defined(HASH_PREDEF_HW_SIMD_X86) && defined(__MIC__)
#   define HASH_PREDEF_HW_SIMD_X86 HASH_PREDEF_HW_SIMD_X86_MIC_VERSION
#endif
#if !defined(HASH_PREDEF_HW_SIMD_X86) && defined(__AVX2__)
#   define HASH_PREDEF_HW_SIMD_X86 HASH_PREDEF_HW_SIMD_X86_AVX2_VERSION
#endif
#if !defined(HASH_PREDEF_HW_SIMD_X86) && defined(__AVX__)
#   define HASH_PREDEF_HW_SIMD_X86 HASH_PREDEF_HW_SIMD_X86_AVX_VERSION
#endif
#if !defined(HASH_PREDEF_HW_SIMD_X86) && defined(__FMA__)
#   define HASH_PREDEF_HW_SIMD_X86 HASH_PREDEF_HW_SIMD_X86_FMA_VERSION
#endif
#if !defined(HASH_PREDEF_HW_SIMD_X86) && defined(__SSE4_2__)
#   define HASH_PREDEF_HW_SIMD_X86 HASH_PREDEF_HW_SIMD_X86_SSE4_2_VERSION
#endif
#if !defined(HASH_PREDEF_HW_SIMD_X86) && defined(__SSE4_1__)
#   define HASH_PREDEF_HW_SIMD_X86 HASH_PREDEF_HW_SIMD_X86_SSE4_1_VERSION
#endif
#if !defined(HASH_PREDEF_HW_SIMD_X86) && defined(__SSSE3__)
#   define HASH_PREDEF_HW_SIMD_X86 HASH_PREDEF_HW_SIMD_X86_SSSE3_VERSION
#endif
#if !defined(HASH_PREDEF_HW_SIMD_X86) && defined(__SSE3__)
#   define HASH_PREDEF_HW_SIMD_X86 HASH_PREDEF_HW_SIMD_X86_SSE3_VERSION
#endif
#if !defined(HASH_PREDEF_HW_SIMD_X86) && (defined(__SSE2__) || defined(_M_X64) || (defined(_M_IX86_FP) && _M_IX86_FP >= 2))
#   define HASH_PREDEF_HW_SIMD_X86 HASH_PREDEF_HW_SIMD_X86_SSE2_VERSION
#endif
#if !defined(HASH_PREDEF_HW_SIMD_X86) && (defined(__SSE__) || defined(_M_X64) || (defined(_M_IX86_FP) && _M_IX86_FP >= 1))
#   define HASH_PREDEF_HW_SIMD_X86 HASH_PREDEF_HW_SIMD_X86_SSE_VERSION
#endif
#if !defined(HASH_PREDEF_HW_SIMD_X86) && defined(__MMX__)
#   define HASH_PREDEF_HW_SIMD_X86 HASH_PREDEF_HW_SIMD_X86_MMX_VERSION
#endif

#if !defined(HASH_PREDEF_HW_SIMD_X86)
#   define HASH_PREDEF_HW_SIMD_X86 HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE
#else
#   define HASH_PREDEF_HW_SIMD_X86_AVAILABLE
#endif

#define HASH_PREDEF_HW_SIMD_X86_NAME "x86 SIMD"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_HW_SIMD_X86, HASH_PREDEF_HW_SIMD_X86_NAME)
