'''
@author: Rene Rivera
@copyright: Copyright Rene Rivera 2018
@license:
    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE_1_0.txt or copy at
    http://www.boost.org/LICENSE_1_0.txt)
'''

import sys
import argparse
import os.path
import shutil
import re
import os

class convert():
    
    def __init__(self, **kargs):
        pass

    def main(self):
        args = argparse.ArgumentParser()
        args.add_argument('--kind', default='hash2boost', choices=['hash2boost','boost2hash'])
        args.add_argument('source_dir')
        args.add_argument('target_dir')
        args.parse_args(None, self)
        kind_m = getattr(self, self.kind, None)
        if kind_m:
            kind_m()

    def hash2boost(self):
        print('### hash2boost')
        self.do_conversion([
        ])

    def boost2hash(self):
        print('### boost2hash')
        source_transform_prog = [
            [self.replace_,r'BOOST_PREDEF([_`])','HASH_PREDEF\\1'],
            [self.replace_,r'BOOST_ARCH([_`])','HASH_PREDEF_ARCH\\1'],
            [self.replace_,r'BOOST_COMP([_`])','HASH_PREDEF_COMP\\1'],
            [self.replace_,r'BOOST_COM_','HASH_PREDEF_COMP_'],
            [self.replace_,r'BOOST_HW([_`])','HASH_PREDEF_HW\\1'],
            [self.replace_,r'BOOST_LANG([_`])','HASH_PREDEF_LANG\\1'],
            [self.replace_,r'BOOST_LIB([_`])','HASH_PREDEF_LIB\\1'],
            [self.replace_,r'BOOST_OS([_`])','HASH_PREDEF_OS\\1'],
            [self.replace_,r'BOOST_PLAT([_`])','HASH_PREDEF_PLAT\\1'],
            [self.replace_,r'BOOST_ENDIAN([_`])','HASH_PREDEF_ENDIAN\\1'],
            [self.replace_,r'BOOST_VERSION([_`])','HASH_PREDEF_VERSION\\1'],
            [self.replace_,r'BOOST_STRICT_CONFIG','HASH_PREDEF_STRICT_CONFIG'],
            [self.replace_,r'BOOST_DETECT_OUTDATED_WORKAROUNDS','HASH_PREDEF_DETECT_OUTDATED_WORKAROUNDS'],
            [self.replace_,r'include <boost/predef','include <predef'],
            [self.replace_,r'Boost Predef','Hash Predef']
            ]
        self.do_conversion([
            [r'^include/boost/predef(.*)[.]h', [
                [self.rename_,r'^(include/)boost/(.*)','\\1\\2']
                ]+source_transform_prog
            ],
            [r'^doc/(.*)[.]qbk', source_transform_prog+[
                [self.replace_,r'Boost[.]Predef','Hash Predef'],
                [self.replace_,r'BOOST_cat.gory_tag','HASH_PREDEF_category_tag'],
                [self.replace_,r'BOOST_CCOMP_','HASH_PREDEF_COMP_'],
                [self.replace_,r'include [.][.]/include/boost/predef','include ../include/predef'],
            ]],
            [r'^test/(.*)[.](cpp|c|m|mm|h)', source_transform_prog],
            [r'^tools/check/(.*)[.](cpp|c|m|mm|h)', source_transform_prog],
            [r'^tools/check/predef.jam', source_transform_prog],
            [r'^tools/ci/(.*)[.]py', []],
            [r'^(.*)[.]git(ignore|attributes)', []],
        ])

    def do_conversion(self, program):
        source_names = self.scandir_(self.source_dir)
        source_dir_relative = os.path.relpath(os.path.abspath(self.source_dir))+'/'
        for name_source in source_names:
            entry_info = {
                'transfer': False,
                'name_source': name_source,
                'name': name_source.replace(source_dir_relative, "") }
            if os.path.isfile(entry_info['name_source']):
                with open(entry_info['name_source'], 'rb') as f:
                    entry_info['content'] = f.read()
            for action in program:
                if re.match(action[0], entry_info['name']):
                    entry_info['transfer'] = True
                    for step in action[1]:
                        entry_info = step[0](entry_info, *step[1:])
            entry_info['name_target'] = os.path.join(self.target_dir, entry_info['name'])
            if entry_info['transfer']:
                print('#### '+entry_info['name_target'])
                dir_target = os.path.abspath(os.path.dirname(entry_info['name_target']))
                if not os.path.isdir(dir_target):
                    os.makedirs(dir_target)
                if isinstance(entry_info['content'],str):
                    with open(entry_info['name_target'],'w') as f:
                        f.write(entry_info['content'])
                else:
                    with open(entry_info['name_target'],'wb') as f:
                        f.write(entry_info['content'])
                # print(entry_info['content'])

    def scandir_(self, dir):
        result = []
        with os.scandir(os.path.abspath(dir)) as paths:
            for path in paths:
                if path.name == '.git':
                    continue
                result.append(os.path.relpath(path.path))
                if not path.is_file():
                    result.extend(self.scandir_(path.path))
        return sorted(result)

    def rename_(self, entry, pattern, repl):
        entry['name'] = re.sub(pattern, repl, entry['name'])
        return entry
    
    def replace_(self, entry, pattern, repl):
        if hasattr(entry['content'], 'decode'):
            entry['content'] = re.sub(pattern, repl, entry['content'].decode('utf-8'))
        else:
            entry['content'] = re.sub(pattern, repl, entry['content'])
        return entry

convert().main()
