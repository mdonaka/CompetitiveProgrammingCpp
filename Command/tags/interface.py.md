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
  code: "import abc\nimport dataclasses\nfrom pathlib import Path\n\n\n@dataclasses.dataclass(frozen=True)\n\
    class TagsInterface(metaclass=abc.ABCMeta):\n    tag = \"\"\n\n    @abc.abstractmethod\n\
    \    def replace(self, lst: list[str], filepath: Path) -> list[str]:\n       \
    \ ...\n"
  dependsOn: []
  isVerificationFile: false
  path: Command/tags/interface.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Command/tags/interface.py
layout: document
redirect_from:
- /library/Command/tags/interface.py
- /library/Command/tags/interface.py.html
title: Command/tags/interface.py
---
