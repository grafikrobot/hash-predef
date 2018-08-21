/*
Copyright James E. King, III - 2017
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#include <predef/platform.h>

//
// This file is used to verify the HASH_PREDEF_PLAT_WINDOWS_* logic.
//
// To exercise all of the combinations the CI build needs many 
// jobs where it defines all the different possible WINAPI_FAMILY
// values on all supported platforms.
//

//
// UWP is available on Windows SDK 8.0 or later, or on MinGW-w64 major release 3 or later
//
#if (defined(__MINGW64__) && (__MINGW64_VERSION_MAJOR >= 3)) || (HASH_PREDEF_PLAT_WINDOWS_SDK_VERSION >= 9200)
#if !HASH_PREDEF_PLAT_WINDOWS_UWP
#error "HASH_PREDEF_PLAT_WINDOWS_UWP should be available"
#endif
#else
#if HASH_PREDEF_PLAT_WINDOWS_UWP
#error "HASH_PREDEF_PLAT_WINDOWS_UWP should not be available"
#endif
#endif

#if !HASH_PREDEF_PLAT_WINDOWS_UWP

//
// If HASH_PREDEF_PLAT_WINDOWS_UWP is not available, none of the other HASH_PREDEF_PLAT_WINDOWS_* are either
// except for HASH_PREDEF_PLAT_WINDOWS_DESKTOP which is available for backwards compatibility.
//

#if HASH_PREDEF_OS_WINDOWS && !HASH_PREDEF_PLAT_WINDOWS_DESKTOP
#error "HASH_PREDEF_PLAT_WINDOWS_DESKTOP should be available"
#endif
#if HASH_PREDEF_PLAT_WINDOWS_PHONE
#error "HASH_PREDEF_PLAT_WINDOWS_PHONE should not be available"
#endif
#if HASH_PREDEF_PLAT_WINDOWS_RUNTIME /* deprecated */
#error "HASH_PREDEF_PLAT_WINDOWS_RUNTIME should not be available"
#endif
#if HASH_PREDEF_PLAT_WINDOWS_SERVER
#error "HASH_PREDEF_PLAT_WINDOWS_SERVER should not be available"
#endif
#if HASH_PREDEF_PLAT_WINDOWS_STORE
#error "HASH_PREDEF_PLAT_WINDOWS_STORE should not be available"
#endif
#if HASH_PREDEF_PLAT_WINDOWS_SYSTEM
#error "HASH_PREDEF_PLAT_WINDOWS_SYSTEM should not be available"
#endif

#else // !HASH_PREDEF_PLAT_WINDOWS_UWP

//
// If HASH_PREDEF_PLAT_WINDOWS_UWP is available, and the SDK supports a particular family,
// and if WINAPI_FAMILY is set to it, then it and only it should be available.
//

#if !defined(WINAPI_FAMILY)
#error "windows_uwp.h should have included <winapifamily.h> which should have defined supported families"
#endif

#if WINAPI_FAMILY == WINAPI_FAMILY_DESKTOP_APP
#if !HASH_PREDEF_PLAT_WINDOWS_DESKTOP
#error "HASH_PREDEF_PLAT_WINDOWS_DESKTOP should be available"
#endif
#if HASH_PREDEF_PLAT_WINDOWS_PHONE
#error "HASH_PREDEF_PLAT_WINDOWS_PHONE should not be available"
#endif
#if HASH_PREDEF_PLAT_WINDOWS_RUNTIME /* deprecated */
#error "HASH_PREDEF_PLAT_WINDOWS_RUNTIME should not be available"
#endif
#if HASH_PREDEF_PLAT_WINDOWS_SERVER
#error "HASH_PREDEF_PLAT_WINDOWS_SERVER should not be available"
#endif
#if HASH_PREDEF_PLAT_WINDOWS_STORE
#error "HASH_PREDEF_PLAT_WINDOWS_STORE should not be available"
#endif
#if HASH_PREDEF_PLAT_WINDOWS_SYSTEM
#error "HASH_PREDEF_PLAT_WINDOWS_SYSTEM should not be available"
#endif
#endif

#if defined(WINAPI_FAMILY_PHONE_APP) && WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
#if HASH_PREDEF_PLAT_WINDOWS_DESKTOP
#error "HASH_PREDEF_PLAT_WINDOWS_DESKTOP should not be available"
#endif
#if !HASH_PREDEF_PLAT_WINDOWS_PHONE
#error "HASH_PREDEF_PLAT_WINDOWS_PHONE should be available"
#endif
#if !HASH_PREDEF_PLAT_WINDOWS_RUNTIME /* deprecated */
#error "HASH_PREDEF_PLAT_WINDOWS_RUNTIME should be available"
#endif
#if HASH_PREDEF_PLAT_WINDOWS_SERVER
#error "HASH_PREDEF_PLAT_WINDOWS_SERVER should not be available"
#endif
#if HASH_PREDEF_PLAT_WINDOWS_STORE
#error "HASH_PREDEF_PLAT_WINDOWS_STORE should not be available"
#endif
#if HASH_PREDEF_PLAT_WINDOWS_SYSTEM
#error "HASH_PREDEF_PLAT_WINDOWS_SYSTEM should not be available"
#endif
#endif

#if defined(WINAPI_FAMILY_SERVER_APP) && WINAPI_FAMILY == WINAPI_FAMILY_SERVER_APP
#if HASH_PREDEF_PLAT_WINDOWS_DESKTOP
#error "HASH_PREDEF_PLAT_WINDOWS_DESKTOP should not be available"
#endif
#if HASH_PREDEF_PLAT_WINDOWS_PHONE
#error "HASH_PREDEF_PLAT_WINDOWS_PHONE should not be available"
#endif
#if HASH_PREDEF_PLAT_WINDOWS_RUNTIME /* deprecated */
#error "HASH_PREDEF_PLAT_WINDOWS_RUNTIME should not be available"
#endif
#if !HASH_PREDEF_PLAT_WINDOWS_SERVER
#error "HASH_PREDEF_PLAT_WINDOWS_SERVER should be available"
#endif
#if HASH_PREDEF_PLAT_WINDOWS_STORE
#error "HASH_PREDEF_PLAT_WINDOWS_STORE should not be available"
#endif
#if HASH_PREDEF_PLAT_WINDOWS_SYSTEM
#error "HASH_PREDEF_PLAT_WINDOWS_SYSTEM should not be available"
#endif
#endif

// Store is WINAPI_FAMILY_APP in MinGW-w64 and in Windows SDK 8.0
// then in Windows SDK 8.1 it was deprecated in favor of WINAPI_FAMILY_PC_APP

#if ((defined(WINAPI_FAMILY_PC_APP) && WINAPI_FAMILY == WINAPI_FAMILY_PC_APP) || \
     (defined(WINAPI_FAMILY_APP) && WINAPI_FAMILY == WINAPI_FAMILY_APP))
#if HASH_PREDEF_PLAT_WINDOWS_DESKTOP
#error "HASH_PREDEF_PLAT_WINDOWS_DESKTOP should not be available"
#endif
#if HASH_PREDEF_PLAT_WINDOWS_PHONE
#error "HASH_PREDEF_PLAT_WINDOWS_PHONE should not be available"
#endif
#if !HASH_PREDEF_PLAT_WINDOWS_RUNTIME /* deprecated */
#error "HASH_PREDEF_PLAT_WINDOWS_RUNTIME should be available"
#endif
#if HASH_PREDEF_PLAT_WINDOWS_SERVER
#error "HASH_PREDEF_PLAT_WINDOWS_SERVER should not be available"
#endif
#if !HASH_PREDEF_PLAT_WINDOWS_STORE
#error "HASH_PREDEF_PLAT_WINDOWS_STORE should be available"
#endif
#if HASH_PREDEF_PLAT_WINDOWS_SYSTEM
#error "HASH_PREDEF_PLAT_WINDOWS_SYSTEM should not be available"
#endif
#endif

#if defined(WINAPI_FAMILY_SYSTEM_APP) && WINAPI_FAMILY == WINAPI_FAMILY_SYSTEM_APP
#if HASH_PREDEF_PLAT_WINDOWS_DESKTOP
#error "HASH_PREDEF_PLAT_WINDOWS_DESKTOP should not be available"
#endif
#if HASH_PREDEF_PLAT_WINDOWS_PHONE
#error "HASH_PREDEF_PLAT_WINDOWS_PHONE should not be available"
#endif
#if HASH_PREDEF_PLAT_WINDOWS_RUNTIME /* deprecated */
#error "HASH_PREDEF_PLAT_WINDOWS_RUNTIME should not be available"
#endif
#if HASH_PREDEF_PLAT_WINDOWS_SERVER
#error "HASH_PREDEF_PLAT_WINDOWS_SERVER should not be available"
#endif
#if HASH_PREDEF_PLAT_WINDOWS_STORE
#error "HASH_PREDEF_PLAT_WINDOWS_STORE should not be available"
#endif
#if !HASH_PREDEF_PLAT_WINDOWS_SYSTEM
#error "HASH_PREDEF_PLAT_WINDOWS_SYSTEM should be available"
#endif
#endif

#endif // !HASH_PREDEF_PLAT_WINDOWS_UWP
