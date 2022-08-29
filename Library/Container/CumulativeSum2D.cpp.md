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
  bundledCode: "#line 1 \"Library/Container/CumulativeSum2D.cpp\"\n/**\r\n *  2\u6B21\
    \u5143\u7D2F\u7A4D\u548C\u3092\u751F\u6210\r\n *  \u9589\u533A\u9593([l1,r1],[l2,r2])\u306B\
    \u304A\u3051\u308B\u5024\u3092\u53D6\u5F97\r\n */\r\nclass CumulativeSum2D {\r\
    \nprivate:\r\n\tconst ll h;\r\n\tconst ll w;\r\n\tstd::vector<std::vector<ll>>\
    \ sumList;\r\npublic:\r\n\r\n\tCumulativeSum2D() = delete;\r\n\tCumulativeSum2D(const\
    \ std::vector<std::vector<ll>>& v) :\r\n\t\th(v.size()),\r\n\t\tw(v[0].size()),\r\
    \n\t\tsumList(h + 1, std::vector<ll>(w + 1)) {\r\n\t\tfor (ll i = 0; i < h; ++i)\
    \ for (ll j = 0; j < w; ++j) {\r\n\t\t\tsumList[i + 1][j + 1] = v[i][j];\r\n\t\
    \t}\r\n\t\tfor (ll i = 0; i < h; ++i) for (ll j = 0; j < w + 1; ++j) {\r\n\t\t\
    \tsumList[i + 1][j] += sumList[i][j];\r\n\t\t}\r\n\t\tfor (ll i = 0; i < h + 1;\
    \ ++i) for (ll j = 0; j < w; ++j) {\r\n\t\t\tsumList[i][j + 1] += sumList[i][j];\r\
    \n\t\t}\r\n\t}\r\n\tll get(ll y, ll x) {\r\n\t\treturn sumList[y + 1][x + 1];\r\
    \n\t}\r\n\tll get(ll y1, ll x1, ll y2, ll x2) {\r\n\t\tif (y2 < y1 || x2 < x1)\
    \ { return 0LL; }\r\n\t\tx1 = std::max(x1, 0LL); y1 = std::max(y1, 0LL);\r\n\t\
    \ty2 = std::min(y2, h - 1); x2 = std::min(x2, w - 1);\r\n\t\treturn sumList[y2\
    \ + 1][x2 + 1] + sumList[y1][x1] -\r\n\t\t\tsumList[y2 + 1][x1] - sumList[y1][x2\
    \ + 1];\r\n\t}\r\n};\r\n"
  code: "/**\r\n *  2\u6B21\u5143\u7D2F\u7A4D\u548C\u3092\u751F\u6210\r\n *  \u9589\
    \u533A\u9593([l1,r1],[l2,r2])\u306B\u304A\u3051\u308B\u5024\u3092\u53D6\u5F97\r\
    \n */\r\nclass CumulativeSum2D {\r\nprivate:\r\n\tconst ll h;\r\n\tconst ll w;\r\
    \n\tstd::vector<std::vector<ll>> sumList;\r\npublic:\r\n\r\n\tCumulativeSum2D()\
    \ = delete;\r\n\tCumulativeSum2D(const std::vector<std::vector<ll>>& v) :\r\n\t\
    \th(v.size()),\r\n\t\tw(v[0].size()),\r\n\t\tsumList(h + 1, std::vector<ll>(w\
    \ + 1)) {\r\n\t\tfor (ll i = 0; i < h; ++i) for (ll j = 0; j < w; ++j) {\r\n\t\
    \t\tsumList[i + 1][j + 1] = v[i][j];\r\n\t\t}\r\n\t\tfor (ll i = 0; i < h; ++i)\
    \ for (ll j = 0; j < w + 1; ++j) {\r\n\t\t\tsumList[i + 1][j] += sumList[i][j];\r\
    \n\t\t}\r\n\t\tfor (ll i = 0; i < h + 1; ++i) for (ll j = 0; j < w; ++j) {\r\n\
    \t\t\tsumList[i][j + 1] += sumList[i][j];\r\n\t\t}\r\n\t}\r\n\tll get(ll y, ll\
    \ x) {\r\n\t\treturn sumList[y + 1][x + 1];\r\n\t}\r\n\tll get(ll y1, ll x1, ll\
    \ y2, ll x2) {\r\n\t\tif (y2 < y1 || x2 < x1) { return 0LL; }\r\n\t\tx1 = std::max(x1,\
    \ 0LL); y1 = std::max(y1, 0LL);\r\n\t\ty2 = std::min(y2, h - 1); x2 = std::min(x2,\
    \ w - 1);\r\n\t\treturn sumList[y2 + 1][x2 + 1] + sumList[y1][x1] -\r\n\t\t\t\
    sumList[y2 + 1][x1] - sumList[y1][x2 + 1];\r\n\t}\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Container/CumulativeSum2D.cpp
  requiredBy: []
  timestamp: '2019-06-01 18:40:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Container/CumulativeSum2D.cpp
layout: document
redirect_from:
- /library/Library/Container/CumulativeSum2D.cpp
- /library/Library/Container/CumulativeSum2D.cpp.html
title: Library/Container/CumulativeSum2D.cpp
---
