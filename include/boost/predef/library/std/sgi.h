/*
Copyright Redshift Software, Inc. 2008-2012
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef BOOST_PREDEF_LIBRARY_STD_SGI_H
#define BOOST_PREDEF_LIBRARY_STD_SGI_H

#include <boost/predef/version_number.h>
#include <boost/predef/make.h>

/*`
[heading `BOOST_LIB_STD_SGI`]

[@http://www.sgi.com/tech/stl/ SGI] Standard C++ library.
If available version number as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`____`] [__predef_detection__]]

    [[`____`] [V.R.P]]
    ]
 */

#define BOOST_LIB_STD_SGI BOOST_VERSION_NUMBER(0,0,0)

#if defined(__STL_CONFIG_H)
#   undef BOOST_LIB_STD_SGI
#   if defined(__SGI_STL)
#       define BOOST_LIB_STD_SGI BOOST_PREDEF_MAKE_0X_VRP(__SGI_STL)
#   else
#       define BOOST_LIB_STD_SGI BOOST_VERSION_NUMBER(0,0,1)
#   endif
#endif

#define BOOST_LIB_STD_SGI_NAME "SGI"

#include <boost/predef/detail/test.h>
BOOST_PREDEF_DECLARE_TEST(BOOST_LIB_STD_SGI,BOOST_LIB_STD_SGI_NAME)


#endif