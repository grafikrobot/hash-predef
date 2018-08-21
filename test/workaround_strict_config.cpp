/*
Copyright Rene Rivera 2011-2017
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/
#include <predef/version_number.h>
#define HASH_PREDEF_STRICT_CONFIG
#include <predef/other/workaround.h>

int main()
{
#if HASH_PREDEF_WORKAROUND(HASH_PREDEF_VERSION_NUMBER_AVAILABLE,==,0,0,1)
    fail();
#endif
    return 0;
}
