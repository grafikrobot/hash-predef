/*
Copyright Rene Rivera 2011-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_LANGUAGE_OBJC_H
#define HASH_PREDEF_LANGUAGE_OBJC_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_LANG_OBJC`

http://en.wikipedia.org/wiki/Objective-C[Objective-C] language.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__OBJC__+` | {predef_detection}
|===
*/ // end::reference[]

#define HASH_PREDEF_LANG_OBJC HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__OBJC__)
#   undef HASH_PREDEF_LANG_OBJC
#   define HASH_PREDEF_LANG_OBJC HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#endif

#if HASH_PREDEF_LANG_OBJC
#   define HASH_PREDEF_LANG_OBJC_AVAILABLE
#endif

#define HASH_PREDEF_LANG_OBJC_NAME "Objective-C"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_LANG_OBJC,HASH_PREDEF_LANG_OBJC_NAME)
