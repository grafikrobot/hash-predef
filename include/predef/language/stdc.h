/*
Copyright Rene Rivera 2011-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_LANGUAGE_STDC_H
#define HASH_PREDEF_LANGUAGE_STDC_H

#include <predef/version_number.h>
#include <predef/make.h>

/* tag::reference[]
= `HASH_PREDEF_LANG_STDC`

http://en.wikipedia.org/wiki/C_(programming_language)[Standard C] language.
If available, the year of the standard is detected as YYYY.MM.1 from the Epoch date.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__STDC__+` | {predef_detection}

| `+__STDC_VERSION__+` | V.R.P
|===
*/ // end::reference[]

#define HASH_PREDEF_LANG_STDC HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__STDC__)
#   undef HASH_PREDEF_LANG_STDC
#   if defined(__STDC_VERSION__)
#       if (__STDC_VERSION__ > 100)
#           define HASH_PREDEF_LANG_STDC HASH_PREDEF_MAKE_YYYYMM(__STDC_VERSION__)
#       else
#           define HASH_PREDEF_LANG_STDC HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#       endif
#   else
#       define HASH_PREDEF_LANG_STDC HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if HASH_PREDEF_LANG_STDC
#   define HASH_PREDEF_LANG_STDC_AVAILABLE
#endif

#define HASH_PREDEF_LANG_STDC_NAME "Standard C"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_LANG_STDC,HASH_PREDEF_LANG_STDC_NAME)
