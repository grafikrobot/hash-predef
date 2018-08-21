/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_LIBRARY_STD_VACPP_H
#define HASH_PREDEF_LIBRARY_STD_VACPP_H

#include <predef/library/std/_prefix.h>

#include <predef/version_number.h>
#include <predef/make.h>

/*`
[heading `HASH_PREDEF_LIB_STD_IBM`]

[@http://www.ibm.com/software/awdtools/xlcpp/ IBM VACPP Standard C++] library.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__IBMCPP__`] [__predef_detection__]]
    ]
 */

#define HASH_PREDEF_LIB_STD_IBM HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__IBMCPP__)
#   undef HASH_PREDEF_LIB_STD_IBM
#   define HASH_PREDEF_LIB_STD_IBM HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#if HASH_PREDEF_LIB_STD_IBM
#   define HASH_PREDEF_LIB_STD_IBM_AVAILABLE
#endif

#define HASH_PREDEF_LIB_STD_IBM_NAME "IBM VACPP"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_LIB_STD_IBM,HASH_PREDEF_LIB_STD_IBM_NAME)
