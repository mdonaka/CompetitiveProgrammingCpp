---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ModCalculator.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\r\n#include <vector>\r\n\r\n#include \"./ModCalculator.hpp\"\
    \r\n\r\n/**\r\n *\tMOD\u306A\u3057combination\r\n *\tn< 51, r<51\r\n */\r\nlong\
    \ long combFast(long long a, long long b) {\r\n  ++a;\r\n  static long long now\
    \ = 1;\r\n  static std::vector<std::vector<long long>> pascalComb(1);\r\n  pascalComb.reserve(51);\r\
    \n  if (a < now) { return pascalComb[a][b]; }\r\n  for (; now < a + 1; ++now)\
    \ {\r\n    std::vector<long long> v(now);\r\n    v[0] = v[now - 1] = 1;\r\n  \
    \  for (long long j = 1; j < now - 1; ++j) {\r\n      v[j] = pascalComb[now -\
    \ 1][j - 1] + pascalComb[now - 1][j];\r\n    }\r\n    pascalComb.emplace_back(v);\r\
    \n  }\r\n  return pascalComb[a][b];\r\n}\r\n\r\n/**\r\n *\t\u30B7\u30F3\u30D7\u30EB\
    combination\r\n *\tO(r)\r\n */\r\nlong long combSimple(long long a, long long\
    \ b, long long MOD) {\r\n  if (b > a - b) { return combSimple(a, a - b, MOD);\
    \ }\r\n  long long ans = 1;\r\n  for (long long i = 0; i < b; ++i) {\r\n    ans\
    \ *= a - i;\r\n    ans %= MOD;\r\n  }\r\n  long long t = 1;\r\n  for (long long\
    \ i = 1; i < b + 1; ++i) {\r\n    t *= i;\r\n    t %= MOD;\r\n  }\r\n  ans *=\
    \ calc.pow(t, MOD - 2);\r\n  ans %= MOD;\r\n  return ans;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: Library/Utility/Combination.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Utility/Combination.hpp
layout: document
redirect_from:
- /library/Library/Utility/Combination.hpp
- /library/Library/Utility/Combination.hpp.html
title: Library/Utility/Combination.hpp
---
