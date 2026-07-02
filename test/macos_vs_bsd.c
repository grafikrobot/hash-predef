/*
Copyright René Ferdinand Rivera Morell
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

/*
 * OSX can masquerade as BSD when sys/param.h is previously included.
 * So we test that we only detect OSX in this combination.
 */
#if defined(__APPLE__)
#include <predef/os/bsd.h>
#include <predef/os/macos.h>
#include <sys/param.h>
#if !HASH_PREDEF_OS_MACOS || HASH_PREDEF_OS_BSD
#error "HASH_PREDEF_OS_MACOS not detected and/or HASH_PREDEF_OS_BSD mis-detected."
#endif
#endif
