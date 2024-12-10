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
  code: "from tags.debug import TagsDebug\nfrom tags.includes import TagsIncludes\n\
    from tags.interface import TagsInterface\nfrom tags.time import TagsTime\n\n\n\
    def select(tag: str, *args) -> TagsInterface:\n    for tag_replacer in [TagsIncludes,\
    \ TagsDebug, TagsTime]:\n        if tag == tag_replacer.tag:\n            return\
    \ tag_replacer(*args)\n    raise RuntimeError(f\"Tag:{tag} is not found.\")\n"
  dependsOn: []
  isVerificationFile: false
  path: Command/tags/selector.py
  requiredBy: []
  timestamp: '2024-12-11 03:50:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Command/tags/selector.py
layout: document
redirect_from:
- /library/Command/tags/selector.py
- /library/Command/tags/selector.py.html
title: Command/tags/selector.py
---
