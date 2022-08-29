---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Library/Container/CumulativeSum.cpp\"\n/**\r\n *  \u7D2F\
    \u7A4D\u548C\u3092\u751F\u6210\r\n *  \u9589\u533A\u9593([l,r])\u306B\u304A\u3051\
    \u308B\u5024\u3092\u53D6\u5F97\r\n */\r\nclass CumulativeSum {\r\n\tconst ll size;\r\
    \n\tstd::vector<ll> sumList;\r\npublic:\r\n\r\n\tCumulativeSum() = delete;\r\n\
    \tCumulativeSum(const std::vector<ll>& v) :size(v.size()), sumList(size + 1) {\r\
    \n\t\tfor (ll i = 0; i < size; ++i) {\r\n\t\t\tsumList[i + 1] = sumList[i] + v[i];\r\
    \n\t\t}\r\n\t}\r\n\tll get(ll n) {\r\n\t\treturn sumList[n + 1];\r\n\t}\r\n\t\
    ll get(ll l, ll r) {\r\n\t\tif (r < l) { return 0LL; }\r\n\t\tl = std::max(l,\
    \ 0LL); r = std::min(r, size - 1);\r\n\t\treturn sumList[r + 1] - sumList[l];\r\
    \n\t}\r\n};\r\n"
  code: "/**\r\n *  \u7D2F\u7A4D\u548C\u3092\u751F\u6210\r\n *  \u9589\u533A\u9593\
    ([l,r])\u306B\u304A\u3051\u308B\u5024\u3092\u53D6\u5F97\r\n */\r\nclass CumulativeSum\
    \ {\r\n\tconst ll size;\r\n\tstd::vector<ll> sumList;\r\npublic:\r\n\r\n\tCumulativeSum()\
    \ = delete;\r\n\tCumulativeSum(const std::vector<ll>& v) :size(v.size()), sumList(size\
    \ + 1) {\r\n\t\tfor (ll i = 0; i < size; ++i) {\r\n\t\t\tsumList[i + 1] = sumList[i]\
    \ + v[i];\r\n\t\t}\r\n\t}\r\n\tll get(ll n) {\r\n\t\treturn sumList[n + 1];\r\n\
    \t}\r\n\tll get(ll l, ll r) {\r\n\t\tif (r < l) { return 0LL; }\r\n\t\tl = std::max(l,\
    \ 0LL); r = std::min(r, size - 1);\r\n\t\treturn sumList[r + 1] - sumList[l];\r\
    \n\t}\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Container/CumulativeSum.cpp
  requiredBy: []
  timestamp: '2019-06-01 18:40:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Container/CumulativeSum.cpp
layout: document
redirect_from:
- /library/Library/Container/CumulativeSum.cpp
- /library/Library/Container/CumulativeSum.cpp.html
title: Library/Container/CumulativeSum.cpp
---
