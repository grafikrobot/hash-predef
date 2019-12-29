# Copyright Mike Dev 2018
# Copyright Rene Rivera 2018
# Copyright Peter Dimov 2019
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
# http://www.boost.org/LICENSE_1_0.txt

# NOTE:
#   CMake support for Hash Predef is currently experimental at best and the
#   interface is likely to change in the future
#
# This file provides minimal cmake support (no unit-tests,
# no installation) for integration into a "host" cmake project
# via the "add_subdirectory( <path-to-hash-predef> )" command.
#
# Other cmake targets can then use the public target name
# "Hash::predef" in order to express their dependency
# on this library. I.e:
#
# target_link_libraries( <my-exe/lib> PUBLIC Hash::predef )

# We support 3.5, but prefer 3.16 policies and behavior
cmake_minimum_required( VERSION 3.5...3.16 )

project( HashPredef VERSION "1.11.0" LANGUAGES CXX )

# Simple INTERFACE, and header only, library target.
add_library( hash_predef INTERFACE )

# The only usage requirement is include dir for consumers.
target_include_directories( hash_predef INTERFACE include )

# Add an alias to be compatible with consumers that may have used the
# FindBoost script.
add_library( Hash::predef ALIAS hash_predef )

if( PROJECT_VERSION )

  list( APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" )

  include( HashInstall )
  hash_install( TARGETS hash_predef HEADER_DIRECTORY include/ )

endif()
