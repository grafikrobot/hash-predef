/*
Copyright Benjamin Worpitz 2018
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_COMPILER_NVCC_H
#define HASH_PREDEF_COMPILER_NVCC_H

#include <predef/version_number.h>
#include <predef/make.h>

/*`
[heading `HASH_PREDEF_COMP_NVCC`]

[@https://en.wikipedia.org/wiki/NVIDIA_CUDA_Compiler NVCC] compiler.
Version number available as major, minor, and patch beginning with version 7.5.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__NVCC__`] [__predef_detection__]]

    [[`__CUDACC_VER_MAJOR__`, `__CUDACC_VER_MINOR__`, `__CUDACC_VER_BUILD__`] [V.R.P]]
    ]
 */

#define HASH_PREDEF_COMP_NVCC HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__NVCC__)
#   if !defined(__CUDACC_VER_MAJOR__) || !defined(__CUDACC_VER_MINOR__) || !defined(__CUDACC_VER_BUILD__)
#       define HASH_PREDEF_COMP_NVCC_DETECTION HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#   else
#       define HASH_PREDEF_COMP_NVCC_DETECTION HASH_PREDEF_VERSION_NUMBER(__CUDACC_VER_MAJOR__, __CUDACC_VER_MINOR__, __CUDACC_VER_BUILD__)
#   endif
#endif

#ifdef HASH_PREDEF_COMP_NVCC_DETECTION
#   if defined(HASH_PREDEF_DETAIL_COMP_DETECTED)
#       define HASH_PREDEF_COMP_NVCC_EMULATED HASH_PREDEF_COMP_NVCC_DETECTION
#   else
#       undef HASH_PREDEF_COMP_NVCC
#       define HASH_PREDEF_COMP_NVCC HASH_PREDEF_COMP_NVCC_DETECTION
#   endif
#   define HASH_PREDEF_COMP_NVCC_AVAILABLE
#   include <predef/detail/comp_detected.h>
#endif

#define HASH_PREDEF_COMP_NVCC_NAME "NVCC"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_NVCC,HASH_PREDEF_COMP_NVCC_NAME)

#ifdef HASH_PREDEF_COMP_NVCC_EMULATED
#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_COMP_NVCC_EMULATED,HASH_PREDEF_COMP_NVCC_NAME)
#endif
