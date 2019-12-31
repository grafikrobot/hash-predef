/*
Copyright Rene Rivera 2017
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_WORKAROUND_H
#define HASH_PREDEF_WORKAROUND_H

/* tag::reference[]

= `HASH_PREDEF_WORKAROUND`

[source]
----
HASH_PREDEF_WORKAROUND(symbol,comp,major,minor,patch)
----

Usage:

[source]
----
#if HASH_PREDEF_WORKAROUND(HASH_PREDEF_COMP_CLANG,<,3,0,0)
    // Workaround for old clang compilers..
#endif
----

Defines a comparison against two version numbers that depends on the definion
of `HASH_PREDEF_STRICT_CONFIG`. When `HASH_PREDEF_STRICT_CONFIG` is defined this will expand
to a value convertible to `false`. Which has the effect of disabling all code
conditionally guarded by `HASH_PREDEF_WORKAROUND`. When `HASH_PREDEF_STRICT_CONFIG`
is undefine this expand to test the given `symbol` version value with the
`comp` comparison against `HASH_PREDEF_VERSION_NUMBER(major,minor,patch)`.

*/ // end::reference[]
#ifdef HASH_PREDEF_STRICT_CONFIG
#   define HASH_PREDEF_WORKAROUND(symbol, comp, major, minor, patch) (0)
#else
#   include <predef/version_number.h>
#   define HASH_PREDEF_WORKAROUND(symbol, comp, major, minor, patch) \
        ( (symbol) != (0) ) && \
        ( (symbol) comp (HASH_PREDEF_VERSION_NUMBER( (major) , (minor) , (patch) )) )
#endif

/* tag::reference[]

= `HASH_PREDEF_TESTED_AT`

[source]
----
HASH_PREDEF_TESTED_AT(symbol,major,minor,patch)
----

Usage:

[source]
----
#if HASH_PREDEF_TESTED_AT(HASH_PREDEF_COMP_CLANG,3,5,0)
    // Needed for clang, and last checked for 3.5.0.
#endif
----

Defines a comparison against two version numbers that depends on the definion
of `HASH_PREDEF_STRICT_CONFIG` and `HASH_PREDEF_DETECT_OUTDATED_WORKAROUNDS`.
When `HASH_PREDEF_STRICT_CONFIG` is defined this will expand to a value convertible
to `false`. Which has the effect of disabling all code
conditionally guarded by `HASH_PREDEF_TESTED_AT`. When `HASH_PREDEF_STRICT_CONFIG`
is undefined this expand to either:

* A value convertible to `true` when `HASH_PREDEF_DETECT_OUTDATED_WORKAROUNDS` is not
  defined.
* A value convertible `true` when the expansion of
  `HASH_PREDEF_WORKAROUND(symbol, <=, major, minor, patch)` is `true` and
  `HASH_PREDEF_DETECT_OUTDATED_WORKAROUNDS` is defined.
* A compile error when the expansion of
  `HASH_PREDEF_WORKAROUND(symbol, >, major, minor, patch)` is true and
  `HASH_PREDEF_DETECT_OUTDATED_WORKAROUNDS` is defined.

*/ // end::reference[]
#ifdef HASH_PREDEF_STRICT_CONFIG
#   define HASH_PREDEF_TESTED_AT(symbol, major, minor, patch) (0)
#else
#   ifdef HASH_PREDEF_DETECT_OUTDATED_WORKAROUNDS
#       define HASH_PREDEF_TESTED_AT(symbol, major, minor, patch) ( \
            HASH_PREDEF_WORKAROUND(symbol, <=, major, minor, patch) \
            ? 1 \
            : (1%0) )
#   else
#       define HASH_PREDEF_TESTED_AT(symbol, major, minor, patch) \
            ( (symbol) >= HASH_PREDEF_VERSION_NUMBER_AVAILABLE )
#   endif
#endif

#endif
