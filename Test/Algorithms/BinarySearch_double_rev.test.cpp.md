---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../Library/Algorithms/binarySearch.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/67\"\r\n#define ERROR\
    \ \"1e-9\"\r\n\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <vector>\r\
    \n#include \"./../../Library/Algorithms/binarySearch.hpp\"\r\n\r\nusing ll = long\
    \ long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr char endl = '\\n';\r\
    \nstruct Preprocessing { Preprocessing() { std::cin.tie(0); std::ios::sync_with_stdio(0);\
    \ }; }_Preprocessing;\r\n\r\nsigned main() {\r\n    ll n;\r\n    cin >> n;\r\n\
    \    std::vector<ll> a(n);\r\n    for(int i = 0; i < n; ++i) { cin >> a[i]; }\r\
    \n    ll k;\r\n    cin >> k;\r\n\r\n    auto ans = binarySearch(1e-9, 1e9, 100,\
    \ [&](double mid) {\r\n        ll count = 0;\r\n        for(const auto& x : a)\
    \ {\r\n            count += (1.0 * x / mid);\r\n        }\r\n        return count\
    \ >= k;\r\n    }, true);\r\n\r\n    cout << std::fixed << std::setprecision(12)\
    \ << ans << endl;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: Test/Algorithms/BinarySearch_double_rev.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/Algorithms/BinarySearch_double_rev.test.cpp
layout: document
redirect_from:
- /verify/Test/Algorithms/BinarySearch_double_rev.test.cpp
- /verify/Test/Algorithms/BinarySearch_double_rev.test.cpp.html
title: Test/Algorithms/BinarySearch_double_rev.test.cpp
---
