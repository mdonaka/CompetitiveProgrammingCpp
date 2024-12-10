---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import sys\nfrom pathlib import Path\n\nfrom tags import select\n\n\ndef\
    \ open_src(filepath: Path) -> list[str]:\n    with open(filepath, \"r\") as f:\n\
    \        return [row for row in f]\n\n\nif __name__ == \"__main__\":\n    args\
    \ = sys.argv\n    if len(args) != 2:\n        raise RuntimeError(\"USAGE: python\
    \ {this file} {src file}\")\n\n    filepath = Path(args[1]).resolve()\n\n    tag\
    \ = \"\"\n    tag_lst: list[str] = []\n    source_lst: list[str] = []\n    for\
    \ line in open_src(filepath):\n        if \"begin:tag\" in line:\n           \
    \ tag = line.split(\"begin:tag \")[1][:-1]\n        elif \"end:tag\" in line:\n\
    \            for rep_line in select(tag).replace(tag_lst, filepath):\n       \
    \         source_lst.append(rep_line)\n            tag = \"\"\n        elif tag:\n\
    \            tag_lst.append(line)\n        else:\n            source_lst.append(line)\n\
    \n    print(\"\".join(source_lst))\n"
  dependsOn: []
  isVerificationFile: false
  path: Command/inline_includes.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Command/inline_includes.py
layout: document
redirect_from:
- /library/Command/inline_includes.py
- /library/Command/inline_includes.py.html
title: Command/inline_includes.py
---
