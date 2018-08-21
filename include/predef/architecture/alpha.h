/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_ARCHITECTURE_ALPHA_H
#define HASH_PREDEF_ARCHITECTURE_ALPHA_H

#include <predef/version_number.h>
#include <predef/make.h>

/*`
[heading `HASH_PREDEF_ARCH_ALPHA`]

[@http://en.wikipedia.org/wiki/DEC_Alpha DEC Alpha] architecture.

[table
    [[__predef_symbol__] [__predef_version__]]
    [[`__alpha__`] [__predef_detection__]]
    [[`__alpha`] [__predef_detection__]]
    [[`_M_ALPHA`] [__predef_detection__]]

    [[`__alpha_ev4__`] [4.0.0]]
    [[`__alpha_ev5__`] [5.0.0]]
    [[`__alpha_ev6__`] [6.0.0]]
    ]
 */

#define HASH_PREDEF_ARCH_ALPHA HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__alpha__) || defined(__alpha) || \
    defined(_M_ALPHA)
#   undef HASH_PREDEF_ARCH_ALPHA
#   if !defined(HASH_PREDEF_ARCH_ALPHA) && defined(__alpha_ev4__)
#       define HASH_PREDEF_ARCH_ALPHA HASH_PREDEF_VERSION_NUMBER(4,0,0)
#   endif
#   if !defined(HASH_PREDEF_ARCH_ALPHA) && defined(__alpha_ev5__)
#       define HASH_PREDEF_ARCH_ALPHA HASH_PREDEF_VERSION_NUMBER(5,0,0)
#   endif
#   if !defined(HASH_PREDEF_ARCH_ALPHA) && defined(__alpha_ev6__)
#       define HASH_PREDEF_ARCH_ALPHA HASH_PREDEF_VERSION_NUMBER(6,0,0)
#   endif
#   if !defined(HASH_PREDEF_ARCH_ALPHA)
#       define HASH_PREDEF_ARCH_ALPHA HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if HASH_PREDEF_ARCH_ALPHA
#   define HASH_PREDEF_ARCH_ALPHA_AVAILABLE
#endif

#define HASH_PREDEF_ARCH_ALPHA_NAME "DEC Alpha"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_ARCH_ALPHA,HASH_PREDEF_ARCH_ALPHA_NAME)
