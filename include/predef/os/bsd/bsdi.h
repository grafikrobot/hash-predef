/*
Copyright Rene Rivera 2012-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_OS_BSD_BSDI_H
#define HASH_PREDEF_OS_BSD_BSDI_H

#include <predef/os/bsd.h>

/*`
[heading `HASH_PREDEF_OS_BSD_BSDI`]

[@http://en.wikipedia.org/wiki/BSD/OS BSDi BSD/OS] operating system.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__bsdi__`] [__predef_detection__]]
    ]
 */

#define HASH_PREDEF_OS_BSD_BSDI HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(HASH_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(__bsdi__) \
    )
#   ifndef HASH_PREDEF_OS_BSD_AVAILABLE
#       define HASH_PREDEF_OS_BSD HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#       define HASH_PREDEF_OS_BSD_AVAILABLE
#   endif
#   undef HASH_PREDEF_OS_BSD_BSDI
#   define HASH_PREDEF_OS_BSD_BSDI HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#if HASH_PREDEF_OS_BSD_BSDI
#   define HASH_PREDEF_OS_BSD_BSDI_AVAILABLE
#   include <predef/detail/os_detected.h>
#endif

#define HASH_PREDEF_OS_BSD_BSDI_NAME "BSDi BSD/OS"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_OS_BSD_BSDI,HASH_PREDEF_OS_BSD_BSDI_NAME)
