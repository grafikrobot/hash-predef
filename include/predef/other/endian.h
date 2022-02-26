/*
Copyright Rene Rivera 2013-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef HASH_PREDEF_ENDIAN_H
#define HASH_PREDEF_ENDIAN_H

#include <predef/version_number.h>
#include <predef/make.h>
#include <predef/library/c/gnu.h>
#include <predef/os/macos.h>
#include <predef/os/bsd.h>
#include <predef/platform/android.h>

/* tag::reference[]
= `HASH_PREDEF_ENDIAN_*`

Detection of endian memory ordering. There are four defined macros
in this header that define the various generally possible endian
memory orderings:

* `HASH_PREDEF_ENDIAN_BIG_BYTE`, byte-swapped big-endian.
* `HASH_PREDEF_ENDIAN_BIG_WORD`, word-swapped big-endian.
* `HASH_PREDEF_ENDIAN_LITTLE_BYTE`, byte-swapped little-endian.
* `HASH_PREDEF_ENDIAN_LITTLE_WORD`, word-swapped little-endian.

The detection is conservative in that it only identifies endianness
that it knows for certain. In particular bi-endianness is not
indicated as is it not practically possible to determine the
endianness from anything but an operating system provided
header. And the currently known headers do not define that
programatic bi-endianness is available.

This implementation is a compilation of various publicly available
information and acquired knowledge:

. The indispensable documentation of "Pre-defined Compiler Macros"
  http://sourceforge.net/p/predef/wiki/Endianness[Endianness].
. The various endian specifications available in the
  http://wikipedia.org/[Wikipedia] computer architecture pages.
. Generally available searches for headers that define endianness.
*/ // end::reference[]

#define HASH_PREDEF_ENDIAN_BIG_BYTE HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE
#define HASH_PREDEF_ENDIAN_BIG_WORD HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE
#define HASH_PREDEF_ENDIAN_LITTLE_BYTE HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE
#define HASH_PREDEF_ENDIAN_LITTLE_WORD HASH_PREDEF_VERSION_NUMBER_NOT_AVAILABLE

/* GNU libc provides a header defining __BYTE_ORDER, or _BYTE_ORDER.
 * And some OSs provide some for of endian header also.
 */
#if !HASH_PREDEF_ENDIAN_BIG_BYTE && !HASH_PREDEF_ENDIAN_BIG_WORD && \
    !HASH_PREDEF_ENDIAN_LITTLE_BYTE && !HASH_PREDEF_ENDIAN_LITTLE_WORD
#   if HASH_PREDEF_LIB_C_GNU || HASH_PREDEF_PLAT_ANDROID || HASH_PREDEF_OS_BSD_OPEN
#       include <endian.h>
#   else
#       if HASH_PREDEF_OS_MACOS
#           include <machine/endian.h>
#       else
#           if HASH_PREDEF_OS_BSD
#               include <sys/endian.h>
#           endif
#       endif
#   endif
#   if defined(__BYTE_ORDER)
#       if defined(__BIG_ENDIAN) && (__BYTE_ORDER == __BIG_ENDIAN)
#           undef HASH_PREDEF_ENDIAN_BIG_BYTE
#           define HASH_PREDEF_ENDIAN_BIG_BYTE HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#       endif
#       if defined(__LITTLE_ENDIAN) && (__BYTE_ORDER == __LITTLE_ENDIAN)
#           undef HASH_PREDEF_ENDIAN_LITTLE_BYTE
#           define HASH_PREDEF_ENDIAN_LITTLE_BYTE HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#       endif
#       if defined(__PDP_ENDIAN) && (__BYTE_ORDER == __PDP_ENDIAN)
#           undef HASH_PREDEF_ENDIAN_LITTLE_WORD
#           define HASH_PREDEF_ENDIAN_LITTLE_WORD HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#       endif
#   endif
#   if !defined(__BYTE_ORDER) && defined(_BYTE_ORDER)
#       if defined(_BIG_ENDIAN) && (_BYTE_ORDER == _BIG_ENDIAN)
#           undef HASH_PREDEF_ENDIAN_BIG_BYTE
#           define HASH_PREDEF_ENDIAN_BIG_BYTE HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#       endif
#       if defined(_LITTLE_ENDIAN) && (_BYTE_ORDER == _LITTLE_ENDIAN)
#           undef HASH_PREDEF_ENDIAN_LITTLE_BYTE
#           define HASH_PREDEF_ENDIAN_LITTLE_BYTE HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#       endif
#       if defined(_PDP_ENDIAN) && (_BYTE_ORDER == _PDP_ENDIAN)
#           undef HASH_PREDEF_ENDIAN_LITTLE_WORD
#           define HASH_PREDEF_ENDIAN_LITTLE_WORD HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#       endif
#   endif
#endif

/* Built-in byte-swapped big-endian macros.
 */
#if !HASH_PREDEF_ENDIAN_BIG_BYTE && !HASH_PREDEF_ENDIAN_BIG_WORD && \
    !HASH_PREDEF_ENDIAN_LITTLE_BYTE && !HASH_PREDEF_ENDIAN_LITTLE_WORD
#   if (defined(__BIG_ENDIAN__) && !defined(__LITTLE_ENDIAN__)) || \
       (defined(_BIG_ENDIAN) && !defined(_LITTLE_ENDIAN)) || \
        defined(__ARMEB__) || \
        defined(__THUMBEB__) || \
        defined(__AARCH64EB__) || \
        defined(_MIPSEB) || \
        defined(__MIPSEB) || \
        defined(__MIPSEB__)
#       undef HASH_PREDEF_ENDIAN_BIG_BYTE
#       define HASH_PREDEF_ENDIAN_BIG_BYTE HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#   endif
#endif

/* Built-in byte-swapped little-endian macros.
 */
#if !HASH_PREDEF_ENDIAN_BIG_BYTE && !HASH_PREDEF_ENDIAN_BIG_WORD && \
    !HASH_PREDEF_ENDIAN_LITTLE_BYTE && !HASH_PREDEF_ENDIAN_LITTLE_WORD
#   if (defined(__LITTLE_ENDIAN__) && !defined(__BIG_ENDIAN__)) || \
       (defined(_LITTLE_ENDIAN) && !defined(_BIG_ENDIAN)) || \
        defined(__ARMEL__) || \
        defined(__THUMBEL__) || \
        defined(__AARCH64EL__) || \
        defined(__loongarch__) || \
        defined(_MIPSEL) || \
        defined(__MIPSEL) || \
        defined(__MIPSEL__) || \
        defined(__riscv) || \
        defined(__e2k__)
#       undef HASH_PREDEF_ENDIAN_LITTLE_BYTE
#       define HASH_PREDEF_ENDIAN_LITTLE_BYTE HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#   endif
#endif

/* Some architectures are strictly one endianess (as opposed
 * the current common bi-endianess).
 */
#if !HASH_PREDEF_ENDIAN_BIG_BYTE && !HASH_PREDEF_ENDIAN_BIG_WORD && \
    !HASH_PREDEF_ENDIAN_LITTLE_BYTE && !HASH_PREDEF_ENDIAN_LITTLE_WORD
#   include <predef/architecture.h>
#   if HASH_PREDEF_ARCH_M68K || \
        HASH_PREDEF_ARCH_PARISC || \
        HASH_PREDEF_ARCH_SPARC || \
        HASH_PREDEF_ARCH_SYS370 || \
        HASH_PREDEF_ARCH_SYS390 || \
        HASH_PREDEF_ARCH_Z
#       undef HASH_PREDEF_ENDIAN_BIG_BYTE
#       define HASH_PREDEF_ENDIAN_BIG_BYTE HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#   endif
#   if HASH_PREDEF_ARCH_IA64 || \
        HASH_PREDEF_ARCH_X86 || \
        HASH_PREDEF_ARCH_BLACKFIN
#       undef HASH_PREDEF_ENDIAN_LITTLE_BYTE
#       define HASH_PREDEF_ENDIAN_LITTLE_BYTE HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#   endif
#endif

/* Windows on ARM, if not otherwise detected/specified, is always
 * byte-swapped little-endian.
 */
#if !HASH_PREDEF_ENDIAN_BIG_BYTE && !HASH_PREDEF_ENDIAN_BIG_WORD && \
    !HASH_PREDEF_ENDIAN_LITTLE_BYTE && !HASH_PREDEF_ENDIAN_LITTLE_WORD
#   if HASH_PREDEF_ARCH_ARM
#       include <predef/os/windows.h>
#       if HASH_PREDEF_OS_WINDOWS
#           undef HASH_PREDEF_ENDIAN_LITTLE_BYTE
#           define HASH_PREDEF_ENDIAN_LITTLE_BYTE HASH_PREDEF_VERSION_NUMBER_AVAILABLE
#       endif
#   endif
#endif

#if HASH_PREDEF_ENDIAN_BIG_BYTE
#   define HASH_PREDEF_ENDIAN_BIG_BYTE_AVAILABLE
#endif
#if HASH_PREDEF_ENDIAN_BIG_WORD
#   define HASH_PREDEF_ENDIAN_BIG_WORD_BYTE_AVAILABLE
#endif
#if HASH_PREDEF_ENDIAN_LITTLE_BYTE
#   define HASH_PREDEF_ENDIAN_LITTLE_BYTE_AVAILABLE
#endif
#if HASH_PREDEF_ENDIAN_LITTLE_WORD
#   define HASH_PREDEF_ENDIAN_LITTLE_WORD_BYTE_AVAILABLE
#endif

#define HASH_PREDEF_ENDIAN_BIG_BYTE_NAME "Byte-Swapped Big-Endian"
#define HASH_PREDEF_ENDIAN_BIG_WORD_NAME "Word-Swapped Big-Endian"
#define HASH_PREDEF_ENDIAN_LITTLE_BYTE_NAME "Byte-Swapped Little-Endian"
#define HASH_PREDEF_ENDIAN_LITTLE_WORD_NAME "Word-Swapped Little-Endian"

#endif

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_ENDIAN_BIG_BYTE,HASH_PREDEF_ENDIAN_BIG_BYTE_NAME)

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_ENDIAN_BIG_WORD,HASH_PREDEF_ENDIAN_BIG_WORD_NAME)

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_ENDIAN_LITTLE_BYTE,HASH_PREDEF_ENDIAN_LITTLE_BYTE_NAME)

#include <predef/detail/test.h>
HASH_PREDEF_DECLARE_TEST(HASH_PREDEF_ENDIAN_LITTLE_WORD,HASH_PREDEF_ENDIAN_LITTLE_WORD_NAME)
