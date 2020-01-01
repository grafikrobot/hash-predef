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
import pprint
import glob


class convert():

    def __init__(self, **kargs):
        pass

    def main(self):
        args = argparse.ArgumentParser()
        self.kind = None
        args.add_argument('--kind', default='hash2boost',
                          choices=['hash2boost', 'boost2hash', 'qbk2adoc'])
        self.source_dir = None
        args.add_argument('source_dir')
        self.target_dir = None
        args.add_argument('target_dir')
        args.parse_args(None, self)
        kind_m = getattr(self, self.kind, None)
        if kind_m:
            kind_m()

    def hash2boost(self):
        print('### hash2boost')
        source_transform_prog = [
            [self.replace_,
                r'HASH_PREDEF([_`].*_H[^A-Z_])', 'BOOST_PREDEF\\1'],
            [self.replace_, r'HASH_PREDEF_ARCH([_`])', 'BOOST_ARCH\\1'],
            [self.replace_, r'HASH_PREDEF_COMP([_`])', 'BOOST_COMP\\1'],
            [self.replace_, r'HASH_PREDEF_HW([_`])', 'BOOST_HW\\1'],
            [self.replace_, r'HASH_PREDEF_LANG([_`])', 'BOOST_LANG\\1'],
            [self.replace_, r'HASH_PREDEF_LIB([_`])', 'BOOST_LIB\\1'],
            [self.replace_, r'HASH_PREDEF_OS([_`])', 'BOOST_OS\\1'],
            [self.replace_, r'HASH_PREDEF_PLAT([_`])', 'BOOST_PLAT\\1'],
            [self.replace_, r'HASH_PREDEF_ENDIAN([_`])', 'BOOST_ENDIAN\\1'],
            [self.replace_, r'HASH_PREDEF_VERSION([_`])', 'BOOST_VERSION\\1'],
            [self.replace_, r'HASH_PREDEF_STRICT_CONFIG',
                'BOOST_STRICT_CONFIG'],
            [self.replace_, r'HASH_PREDEF_DETECT_OUTDATED_WORKAROUNDS',
                'BOOST_DETECT_OUTDATED_WORKAROUNDS'],
            [self.replace_, r'HASH_PREDEF([_`])', 'BOOST_PREDEF\\1'],
            [self.replace_, r'include <predef', 'include <boost/predef'],
            [self.replace_, r'Hash Predef', 'Boost Predef']
        ]
        self.do_conversion([
            [r'^include/predef(.*)[.]h', [
                [self.rename_, r'^(include/)(.*)', '\\1boost/\\2']
            ]+source_transform_prog
            ],
            [r'^doc/(.*)[.]adoc', [
                [self.replace_, r'Hash Predef', 'Boost.Predef'],
                [self.replace_, r'HASH_PREDEF_category_tag_H',
                    'BOOST_PREDEF_category_tag_H'],
                [self.replace_, r'HASH_PREDEF_category_tag',
                    'BOOST_category_tag'],
                [self.replace_, r'include::[.][.]/include/predef',
                    'include::../include/boost/predef'],
            ]+source_transform_prog
            ],
            [r'^test/(.*)[.](cpp|c|m|mm|h)', source_transform_prog],
            [r'^tools/check/(.*)[.](cpp|c|m|mm|h)', source_transform_prog],
            [r'^tools/check/predef.jam', [
                [self.replace_, r'HASH_PREDEF_INCLUDE', 'BOOST_ROOT'],
            ]+source_transform_prog],
            [r'^tools/ci/(.*)[.]py$', []],
            [r'^(.*)[.]git(ignore|attributes)', []],
            [r'^(.*)CMakeLists.txt$', [
                [self.replace_, r'Hash Predef', 'Boost.Predef'],
                [self.replace_, r'Hash::predef', 'Boost::predef'],
                [self.replace_, r'hash-predef', 'boost-predef'],
                [self.replace_, r'HashPredef', 'BoostPredef'],
                [self.replace_, r'hash_predef', 'boost_predef'],
            ]],
            [r'^test/build[.]jam', [
                [self.replace_, r'"HASH_PREDEF_', '"BOOST_'],
                [self.replace_, r'HASH_PREDEF', 'BOOST_PREDEF'],
                [self.replace_, r'/predef[.]h', '/boost/predef.h'],
            ]],
            [r'^build[.]jam', [
                [self.replace_, r'HASH_PREDEF', 'BOOST_PREDEF'],
                [self.replace_, r'/hash_predef', '/boost/predef'],
                [self.replace_, r'PREDEF_DIST : hash ', 'PREDEF_DIST : boost '],
            ]]
        ])

    def boost2hash(self):
        print('### boost2hash')
        source_transform_prog = [
            [self.replace_, r'BOOST_PREDEF([_`])', 'HASH_PREDEF\\1'],
            [self.replace_, r'BOOST_ARCH([_`])', 'HASH_PREDEF_ARCH\\1'],
            [self.replace_, r'BOOST_COMP([_`])', 'HASH_PREDEF_COMP\\1'],
            [self.replace_, r'BOOST_COM_', 'HASH_PREDEF_COMP_'],
            [self.replace_, r'BOOST_HW([_`])', 'HASH_PREDEF_HW\\1'],
            [self.replace_, r'BOOST_LANG([_`])', 'HASH_PREDEF_LANG\\1'],
            [self.replace_, r'BOOST_LIB([_`])', 'HASH_PREDEF_LIB\\1'],
            [self.replace_, r'BOOST_OS([_`])', 'HASH_PREDEF_OS\\1'],
            [self.replace_, r'BOOST_PLAT([_`])', 'HASH_PREDEF_PLAT\\1'],
            [self.replace_, r'BOOST_ENDIAN([_`])', 'HASH_PREDEF_ENDIAN\\1'],
            [self.replace_, r'BOOST_VERSION([_`])', 'HASH_PREDEF_VERSION\\1'],
            [self.replace_, r'BOOST_STRICT_CONFIG',
                'HASH_PREDEF_STRICT_CONFIG'],
            [self.replace_, r'BOOST_DETECT_OUTDATED_WORKAROUNDS',
                'HASH_PREDEF_DETECT_OUTDATED_WORKAROUNDS'],
            [self.replace_, r'include <boost/predef', 'include <predef'],
            [self.replace_, r'Boost Predef', 'Hash Predef']
        ]
        self.do_conversion([
            [r'^include/boost/predef/detail/endian_compat[.]h', [
                [self.remove_]
            ]],
            [r'^include/boost/predef(.*)[.]h', [
                [self.rename_, r'^(include/)boost/(.*)', '\\1\\2']
            ]+source_transform_prog
            ],
            [r'^doc/(.*)[.]adoc', source_transform_prog+[
                [self.replace_, r'Boost[.]Predef', 'Hash Predef'],
                [self.replace_, r'BOOST_cat.gory_tag',
                    'HASH_PREDEF_category_tag'],
                [self.replace_, r'BOOST_CCOMP_', 'HASH_PREDEF_COMP_'],
                [self.replace_, r'include::[.][.]/include/boost/predef',
                    'include::../include/predef'],
            ]],
            [r'^test/(.*)[.](cpp|c|m|mm|h)', source_transform_prog],
            [r'^tools/check/(.*)[.](cpp|c|m|mm|h)', source_transform_prog],
            [r'^tools/check/predef.jam', [
                [self.replace_, r'BOOST_ROOT', 'HASH_PREDEF_INCLUDE'],
            ]+source_transform_prog],
            [r'^tools/ci/(.*)[.]py$', []],
            [r'^(.*)[.]git(ignore|attributes)', []],
            [r'^(.*)CMakeLists.txt$', [
                [self.replace_, r'Boost[.]Predef', 'Hash Predef'],
                [self.replace_, r'Boost::predef', 'Hash::predef'],
                [self.replace_, r'boost-predef', 'hash-predef'],
                [self.replace_, r'BoostPredef', 'HashPredef'],
                [self.replace_, r'boost_predef', 'hash_predef'],
            ]],
            [r'^build[.]jam', [
                [self.replace_, r'BOOST_PREDEF', 'HASH_PREDEF'],
                [self.replace_, r'/boost/predef', '/hash_predef'],
                [self.replace_, r'PREDEF_DIST : boost ', 'PREDEF_DIST : hash '],
            ]]
        ])

    def do_conversion(self, program):
        source_names = self.scandir_(self.source_dir)
        source_dir_relative = os.path.relpath(
            os.path.abspath(self.source_dir))+'/'
        for name_source in source_names:
            entry_info = {
                'transfer': False,
                'name_source': name_source,
                'name': name_source.replace(source_dir_relative, "")}
            if os.path.isfile(entry_info['name_source']):
                with open(entry_info['name_source'], 'rb') as f:
                    entry_info['content'] = f.read()
            for action in program:
                if re.match(action[0], entry_info['name']):
                    entry_info['transfer'] = True
                    for step in action[1]:
                        entry_info = step[0](entry_info, *step[1:])
                        if not entry_info['transfer']:
                            break
                    if not entry_info['transfer']:
                        break
            entry_info['name_target'] = os.path.join(
                self.target_dir, entry_info['name'])
            if entry_info['transfer']:
                print('#### '+entry_info['name_target'])
                dir_target = os.path.abspath(
                    os.path.dirname(entry_info['name_target']))
                if not os.path.isdir(dir_target):
                    os.makedirs(dir_target)
                if isinstance(entry_info['content'], str):
                    with open(entry_info['name_target'], 'w') as f:
                        f.write(entry_info['content'])
                else:
                    with open(entry_info['name_target'], 'wb') as f:
                        f.write(entry_info['content'])
                # print(entry_info['content'])

    def qbk2adoc(self):
        print('### qbk2adoc')
        self.do_conversion([
            [r'^doc/(.*)[.]qbk', [
                [self.do_qbk2adoc_conversion]]],
            [r'^include/predef(.*)[.]h', [
                [self.do_qbk2adoc_code_conversion]]]
        ])

    def do_qbk2adoc_conversion(self, entry):
        entry['name'] = os.path.splitext(entry['name'])[0] + '.adoc'
        adoc_info = {}
        adoc = []
        qbk = None
        qbk_i = 0
        colophon = []
        if hasattr(entry['content'], 'decode'):
            qbk = entry['content'].decode('utf-8').splitlines()
        else:
            qbk = entry['content'].splitlines()
        if qbk[0].startswith('[article '):
            adoc_info['title'] = re.fullmatch(r'\[article (.*)', qbk[0]).group(1)
            adoc_info['copyright'] = []
            adoc_info['author'] = []
            qbk_i += 1
            while qbk[qbk_i] != "]":
                line = qbk[qbk_i]
                copyright = re.fullmatch(r'\s+\[copyright\s+([^]]+)\]', line)
                if copyright:
                    adoc_info['copyright'].append('Copyright '+copyright.group(1))
                    qbk_i += 1
                    continue
                purpose = re.fullmatch(r'[^[]+.purpose\s+([^]]+)', line)
                if purpose:
                    adoc_info['purpose'].append(purpose.group(1))
                    qbk_i += 1
                    continue
                authors = re.fullmatch(r'[^[]+.authors\s+\[([^]]+)\]\]', line)
                if authors:
                    author = authors.group(1).split(',')
                    adoc_info['author'].append(author[1].strip()+' '+author[0].strip())
                    qbk_i += 1
                    continue
                qbk_i += 1
            qbk_i += 1
            adoc.append('= {title}'.format(**adoc_info))
            for author in adoc_info['author']:
                adoc.append(':author: '+author)
            adoc.extend([
                ':toc: left',
                ':toclevels: 3',
                ':sectanchors:',
                ':sectnums:',
                ':nofooter:',
                ':source-highlighter: pygments',
                ':source-language: cpp',
                ':caution-caption: ⚑',
                ':important-caption: ‼',
                ':note-caption: ℹ',
                ':tip-caption: ☀',
                ':warning-caption: ⚠',
                ':CPP: C++',
                ':predef_symbol: Symbol',
                ':predef_version: Version',
                ':predef_detection: pass:q[*detection*]',
                '',
                'ifdef::backend-html5[]',
                '++++',
                '<style>',
                'include::predef.css[]',
                '</style>',
                '++++',
                'endif::[]'
                ])
            colophon.extend([
                '[colophon]',
                '== Colophon',
                '',
                'Distributed under the Boost Software License, Version 1.0.',
                '(See accompanying file LICENSE_1_0.txt or copy at',
                'https://www.boost.org/LICENSE_1_0.txt)',
                '',
                ])
            if 'copyright' in adoc_info and len(adoc_info['copyright']) > 0:
                colophon.append('; '.join(adoc_info['copyright']))
        adoc.extend(self.qbk_to_adoc_(qbk[qbk_i:-1], entry['name_source']))
        adoc.extend(colophon)
        entry['content'] = '\n'.join(adoc)
        return entry

    def do_qbk2adoc_code_conversion(self, entry):
        content = None
        if hasattr(entry['content'], 'decode'):
            content = entry['content'].decode('utf-8')
        else:
            content = entry['content']
        doc_comments = re.findall(r'\/\*\`\n.+?\ ?\*\/\n', content, re.S)
        for doc_comment in doc_comments:
            doc = doc_comment.splitlines()[1:-1]
            doc = self.qbk_to_adoc_(doc, entry['name_source'], section_level=1)
            doc = '/* tag::reference[]\n'+'\n'.join(doc)+'\n*/ // end::reference[]\n'
            content = content.replace(doc_comment, doc)
        entry['content'] = content
        return entry

    def qbk_to_adoc_(self, lines, name_source, section_level=2):
        line_i = 0
        result = []
        while line_i < len(lines):
            line = lines[line_i]
            # line_i += 1
            line = re.sub(r'C\+\+', '{CPP}', line)
            line = re.sub(r'__predef_symbol__', '{predef_symbol}', line)
            line = re.sub(r'__predef_version__', '{predef_version}', line)
            line = re.sub(r'__predef_detection__', '{predef_detection}', line)
            line = re.sub(r'\[\^([^]]+)\]', r'`\1`', line)
            line = re.sub(r'\[\~([^]]+)\]', r'_\1_', line)
            line = re.sub(r'\[\@([^ ]+) ([^]]+)\]', r'\1[\2]', line)
            line = re.sub(r'\[\@([^ ]+)\]', r'\1', line)
            line = re.sub(r'\s*\[\/[^\]]+\]', '', line)
            line = re.sub(r'(__\S+?__)', r'+\1+', line)
            line = re.sub(r'\`(_\S+?)\`', r'`+\1+`', line)
            line = re.sub(r' \/(\S+?)\/ ', r'`_\1_`', line)
            line = re.sub(r'\\([\[\]])', r'\1', line)
            if re.match(r'\s*\[section\s+', line):
                match = re.fullmatch(r'\s*\[section\s+(.*)\]', line)
                result.append(''.ljust(section_level, '=')+' '+match.group(1))
                section_level += 1
            elif re.match(r'\s*\[endsect\]', line):
                section_level -= 1
            elif re.match(r'\s*\[heading\s+', line):
                match = re.fullmatch(r'\s*\[heading\s+(.*)\]', line)
                result.append(''.ljust(section_level, '=')+' '+match.group(1))
            elif line.startswith('# '):
                result.append('. '+line[2:])
            elif re.match(r'\s*\[note\s+', line):
                note = []
                line = re.sub(r'\s*\[note\s+', 'NOTE: ', line)
                while not line.endswith(']'):
                    note.append(line)
                    line_i += 1
                    line = lines[line_i]
                note.append(line[0:-1])
                result.extend(note)
            elif re.match(r'\s*\[warning\s+', line):
                note = []
                line = re.sub(r'\s*\[warning\s+', 'WARNING: ', line)
                while not line.endswith(']'):
                    note.append(line)
                    line_i += 1
                    line = lines[line_i]
                note.append(line[0:-1])
                result.extend(note)
            elif line == '[/':
                result.append('////')
                line_i += 1
                line = lines[line_i]
                while line != ']':
                    result.append(line)
                    line_i += 1
                    line = lines[line_i]
                result.append('////')
            elif line == "``":
                result.extend(['[source]', '----'])
                dedent = None
                line_i += 1
                while lines[line_i] != "``":
                    if dedent == None:
                        dedent = lines[line_i].startswith('  ')
                    if dedent:
                        result.append(lines[line_i][2:])
                    else:
                        result.append(lines[line_i])
                    line_i += 1
                result.append('----')
            elif re.match(r'\s*\[include\s+', line):
                match = re.fullmatch(r'\s*\[include\s+(.*)\]', line)
                if match.group(1).endswith('.qbk'):
                    result.append('include::%s[]'%(match.group(1).replace('.qbk','.adoc')))
                elif '*' in match.group(1):
                    name_dir = os.path.dirname(name_source)
                    files = list(glob.glob(os.path.join(name_dir, match.group(1))))
                    for f in sorted(files):
                        result.append('include::%s[leveloffset=%s,tag=reference]'%(f.replace(name_dir+os.sep, ''), section_level-1))
                else:
                    result.append('include::%s[leveloffset=%s,tag=reference]'%(match.group(1), section_level-1))
            elif line.startswith('[def '):
                pass
            elif line == '[teletype]':
                pass
            elif line == '[c++]':
                pass
            elif re.match(r'\s*\[table', line):
                match = re.match(r'\s*\[table\s+(.*)', line)
                if match:
                    result.append('.'+match.group(1))
                result.extend(['[options="header"]', '|==='])
                rows = []
                line_i += 1
                while lines[line_i].strip() != "]":
                    rows.append(lines[line_i])
                    line_i += 1
                rows = self.qbk_to_adoc_(rows, name_source)
                for row in rows:
                    sub_row = re.match(r'^\[(.+)\]$', row.strip())
                    if sub_row:
                        cols = re.findall(r'\[([^\]]*)\]', sub_row.group(1))
                        result.append('| '+' | '.join(cols))
                    else:
                        result.append(row)
                result.append('|===')
            else:
                result.append(line)
            line_i += 1
        return result

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
            entry['content'] = re.sub(
                pattern, repl, entry['content'].decode('utf-8'))
        else:
            entry['content'] = re.sub(pattern, repl, entry['content'])
        return entry

    def remove_(self, entry):
        entry['transfer'] = False
        return entry


convert().main()
