/*
Copyright Redshift Software, Inc. 2008-2012
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef BOOST_PREDEF_OS_IRIX_H
#define BOOST_PREDEF_OS_IRIX_H

#include <boost/predef/version_number.h>
#include <boost/predef/make.h>

/*`
[heading `BOOST_OS_IRIX`]

[@http://en.wikipedia.org/wiki/Irix IRIX] operating system.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`____`] [__predef_detection__]]

    [[`____`] [V.R.P]]
    ]
 */

#define BOOST_OS_IRIX BOOST_VERSION_NUMBER(0,0,0)

#if defined(sgi) || defined(__sgi)
#   undef BOOST_OS_IRIX
#   define BOOST_OS_IRIX BOOST_VERSION_NUMBER(0,0,1)
#endif

#define BOOST_OS_IRIX_NAME "IRIX"

#include <boost/predef/detail/test.h>
BOOST_PREDEF_DECLARE_TEST(BOOST_OS_IRIX,BOOST_OS_IRIX_NAME)


#endif