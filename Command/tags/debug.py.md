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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import dataclasses\nfrom pathlib import Path\n\nfrom tags.interface import\
    \ TagsInterface\n\n\n@dataclasses.dataclass(frozen=True)\nclass TagsDebug(TagsInterface):\n\
    \    tag = \"debug\"\n\n    def replace(self, lst: list[str], filepath: Path)\
    \ -> list[str]:\n        # TODO: \u3061\u3083\u3093\u3068\u5206\u5C90\u3059\u308B\
    \n        return [\"#define dump(...)\"]\n"
  dependsOn: []
  isVerificationFile: false
  path: Command/tags/debug.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Command/tags/debug.py
layout: document
redirect_from:
- /library/Command/tags/debug.py
- /library/Command/tags/debug.py.html
title: Command/tags/debug.py
---
