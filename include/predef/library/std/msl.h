/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_LIBRARY_STD_MSL_H
#define HASH_PREDEF_LIBRARY_STD_MSL_H

#include <predef/library/std/_prefix.h>

#include <predef/version_number.h>
#include <predef/make.h>

/*`
[heading `HASH_PREDEF_LIB_STD_MSL`]

[@http://www.freescale.com/ Metrowerks] Standard C++ Library.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__MSL_CPP__`] [__predef_detection__]]
    [[`__MSL__`] [__predef_detection__]]

    [[`__MSL_CPP__`] [V.R.P]]
    [[`__MSL__`] [V.R.P]]
    ]
 */

#define HASH_PREDEF_LIB_STD_MSL HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__MSL_CPP__) || defined(__MSL__)
#   undef HASH_PREDEF_LIB_STD_MSL
#   if defined(__MSL_CPP__)
#       define HASH_PREDEF_LIB_STD_MSL HASH_PREDEF_MAKE_0X_VRPP(__MSL_CPP__)
#   else
#       define HASH_PREDEF_LIB_STD_MSL HASH_PREDEF_MAKE_0X_VRPP(__MSL__)
#   endif
#endif

#if HASH_PREDEF_LIB_STD_MSL
#   define HASH_PREDEF_LIB_STD_MSL_AVAILABLE
#endif

#define HASH_PREDEF_LIB_STD_MSL_NAME "Metrowerks"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_LIB_STD_MSL,HASH_PREDEF_LIB_STD_MSL_NAME)
