---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../Library/Math/Modint.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\
    \n#include <iostream>\n\n// begin:tag includes\n#include \"../../Library/Math/Convolution.hpp\"\
    \n#include \"../../Library/Math/Modint.hpp\"\n#include \"../../Library/Range/istream.hpp\"\
    \n// end:tag includes\n\nint main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(0);\n\
    \n  using mint = mtd::ModInt<998244353>;\n\n  auto [n] = mtd::io::in<int>();\n\
    \  auto a = mtd::io::_input<mtd::io::type::vec<mint>>(1LL << n);\n  auto b = mtd::io::_input<mtd::io::type::vec<mint>>(1LL\
    \ << n);\n\n  auto ans = mtd::convolution::bitwise_and(a, b);\n  for (auto x :\
    \ ans) { std::cout << x << \" \"; }\n  std::cout << std::endl;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: Test/Math/convolution_and.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/Math/convolution_and.test.cpp
layout: document
redirect_from:
- /verify/Test/Math/convolution_and.test.cpp
- /verify/Test/Math/convolution_and.test.cpp.html
title: Test/Math/convolution_and.test.cpp
---
