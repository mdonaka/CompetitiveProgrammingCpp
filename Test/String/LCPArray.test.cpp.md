---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../Library/Container/SegmentTree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/599\"\r\n\r\n#include\
    \ <iostream>\r\n\r\n#include \"./../../Library/String/LCPArray.hpp\"\r\n#include\
    \ \"./../../Library/Container/SegmentTree.hpp\"\r\n\r\nusing ll = long long;\r\
    \nusing std::cout;\r\nusing std::cin;\r\nconstexpr char endl = '\\n';\r\nstruct\
    \ Preprocessing { Preprocessing() { std::cin.tie(0); std::ios::sync_with_stdio(0);\
    \ }; }_Preprocessing;\r\n\r\nstruct F { auto operator()(int a, int b)const { return\
    \ std::min(a, b); }; };\r\nusing M = Monoid<int, static_cast<int>(1e9), F>;\r\n\
    \r\nconstexpr ll MOD = 1000000007;\r\n\r\nsigned main() {\r\n    std::string s;\r\
    \n    cin >> s;\r\n\r\n    ll size = s.size();\r\n    auto lcparray = LCPArray(s);\r\
    \n    auto segtree = SegmentTree<M>(size, lcparray.getLCPArray());\r\n    auto\
    \ sai = lcparray.getSuffixArrayIndexList();\r\n\r\n    ll half = (size >> 1);\r\
    \n    std::vector<ll> dp(half + 1);\r\n    dp[0] = 1;\r\n    for(int l = 0; l\
    \ < half; ++l) {\r\n        for(int r = l; r < half; ++r) {\r\n\r\n          \
    \  auto idx1 = sai[l];\r\n            auto idx2 = sai[size - r - 1];\r\n     \
    \       if(idx2 < idx1) { std::swap(idx1, idx2); }\r\n            auto lcp = segtree.query(idx1,\
    \ idx2 - 1);\r\n\r\n            int len = r - l + 1;\r\n            if(lcp >=\
    \ len) {\r\n                dp[r + 1] += dp[l];\r\n                if(dp[r + 1]\
    \ >= MOD) { dp[r + 1] -= MOD; }\r\n            }\r\n        }\r\n    }\r\n\r\n\
    \    ll ans = 0;\r\n    for(const auto& x : dp) { ans += x; if(ans >= MOD) { ans\
    \ -= MOD; } }\r\n    cout << ans;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: Test/String/LCPArray.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/String/LCPArray.test.cpp
layout: document
redirect_from:
- /verify/Test/String/LCPArray.test.cpp
- /verify/Test/String/LCPArray.test.cpp.html
title: Test/String/LCPArray.test.cpp
---
