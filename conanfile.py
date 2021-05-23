'''
@author: René Ferdinand Rivera Morell
@copyright: Copyright René Ferdinand Rivera Morell 2021
@license:
    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE_1_0.txt or copy at
    http://www.boost.org/LICENSE_1_0.txt)
'''
from conans import ConanFile, tools, errors
import os


required_conan_version = ">=1.32.0"


class HashPredefConan(ConanFile):
    name = "hash_predef"
    homepage = "https://github.com/grafikrobot/hash-predef"
    description = '''\
This library defines a set of compiler, architecture, operating system,
library, and other version numbers from the information it can gather of
C, C++, Objective C, and Objective C++ predefined macros or those defined in
generally available headers.

This is an entirely standlone version of the Boost.Predef library.
'''
    topics = ("header", 'header-only', 'preprocessor',
              "#ifdef", "cross-platform")
    license = "BSL-1.0"
    no_copy_source = True
    url = "https://github.com/grafikrobot/hash-predef"

    source_subfolder = "source_subfolder"

    def source(self):
        tools.get(**self.conan_data["sources"][self.version],
                  strip_root=True, destination=self.source_subfolder)

    def package(self):
        self.copy(pattern="*.h", dst="include",
                  src=os.path.join(self.source_subfolder, "include"))
