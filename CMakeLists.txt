# Copyright Mike Dev 2018
# Copyright René Ferdinand Rivera Morell 2018-2023
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
# http://www.boost.org/LICENSE_1_0.txt

# This file provides minimal cmake support (no unit-tests,
# no installation) for integration into a "host" cmake project
# via the "add_subdirectory( <path-to-hash-predef> )" command.
#
# Other cmake targets can then use the public target name
# "Hash::predef" in order to express their dependency
# on this library. I.e:
#
# target_link_libraries( <my-exe/lib> PUBLIC Hash::predef )

# Only need the basic minimum of project, add_library, and
# target_include_directories commands.
cmake_minimum_required( VERSION 3.5...3.999 )

# Don't set LANGUAGES as we are multi-language and header only, so it's
# irrelevant.
set( HASH_PREDEF_VERSION "1.15" )
project( hash_predef VERSION "${HASH_PREDEF_VERSION}" LANGUAGES NONE )

# Simple INTERFACE, and header only, library target.
add_library( hash_predef INTERFACE )

# The only usage requirement is include dir for consumers.
target_include_directories( hash_predef INTERFACE include )

# Add an alias to be compatible with consumers that may have used the
# FindBoost script.
add_library( Hash::predef ALIAS hash_predef )
