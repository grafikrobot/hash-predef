/*
Copyright Rene Rivera 2013-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_ARCHITECTURE_BLACKFIN_H
#define HASH_PREDEF_ARCHITECTURE_BLACKFIN_H

#include <predef/version_number.h>
#include <predef/make.h>

/*`
[heading `HASH_PREDEF_ARCH_BLACKFIN`]

Blackfin Processors from Analog Devices.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__bfin__`] [__predef_detection__]]
    [[`__BFIN__`] [__predef_detection__]]
    [[`bfin`] [__predef_detection__]]
    [[`BFIN`] [__predef_detection__]]
    ]
 */

#define HASH_PREDEF_ARCH_BLACKFIN HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__bfin__) || defined(__BFIN__) || \
    defined(bfin) || defined(BFIN)
#   undef HASH_PREDEF_ARCH_BLACKFIN
#   define HASH_PREDEF_ARCH_BLACKFIN HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#if HASH_PREDEF_ARCH_BLACKFIN
#   define HASH_PREDEF_ARCH_BLACKFIN_AVAILABLE
#endif

#define HASH_PREDEF_ARCH_BLACKFIN_NAME "Blackfin"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_ARCH_BLACKFIN,HASH_PREDEF_ARCH_BLACKFIN_NAME)
