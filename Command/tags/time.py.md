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
  code: "import dataclasses\nfrom pathlib import Path\nimport datetime\n\nfrom tags.interface\
    \ import TagsInterface\n\n\n@dataclasses.dataclass(frozen=True)\nclass TagsTime(TagsInterface):\n\
    \    tag = \"time\"\n\n    def replace(self, lst: list[str], filepath: Path) ->\
    \ list[str]:\n        now = datetime.datetime.now(datetime.timezone(datetime.timedelta(hours=9)))\n\
    \        now = now.strftime(\"%Y-%m-%d %H:%M:%S %Z\")\n\n        return [\n  \
    \          \"/*\\n\",\n            \" * Author:  cutmdo\\n\",\n            \"\
    \ * Created: \" + str(now) + \"\\n\",\n            \" */\\n\",\n        ]\n"
  dependsOn: []
  isVerificationFile: false
  path: Command/tags/time.py
  requiredBy: []
  timestamp: '2024-12-11 03:50:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Command/tags/time.py
layout: document
redirect_from:
- /library/Command/tags/time.py
- /library/Command/tags/time.py.html
title: Command/tags/time.py
---
