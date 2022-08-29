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
  bundledCode: "#line 2 \"Library/Algorithms/Mo.hpp\"\n#include <vector>\r\n#include\
    \ <algorithm>\r\n#include <cmath>\r\n#include <numeric>\r\n\r\nclass Mo {\r\n\r\
    \n    const int q;\r\n    const std::vector<int> lq;\r\n    const std::vector<int>\
    \ rq;\r\n    const std::vector<int> order;\r\n    int ni, nl, nr;\r\n\r\n    auto\
    \ sort_query() const {\r\n        std::vector<int> order(q);\r\n        std::iota(order.begin(),\
    \ order.end(), 0);\r\n        int w = std::sqrt(q);\r\n        std::sort(order.begin(),\
    \ order.end(), [&](int a, int b) {\r\n            if(lq[a] / w != lq[b] / w) return\
    \ lq[a] < lq[b];\r\n            if(rq[a] == rq[b]) { return false; }\r\n     \
    \       bool less = (rq[a] < rq[b]);\r\n            bool flg = (lq[a] / w) & 1;\r\
    \n            return static_cast<bool>(less ^ flg);\r\n        });\r\n\r\n   \
    \     return order;\r\n    }\r\n\r\npublic:\r\n    Mo(int q,\r\n       const std::vector<int>&\
    \ lq,\r\n       const std::vector<int>& rq)\r\n        :q(q), lq(lq), rq(rq),\
    \ order(sort_query()),\r\n        ni(0), nl(0), nr(-1) {\r\n    }\r\n\r\n    template<class\
    \ Lambda1, class Lambda2>\r\n    auto process(const Lambda1& add, const Lambda2&\
    \ del) {\r\n        const auto l = lq[order[ni]];\r\n        const auto r = rq[order[ni]];\r\
    \n        while(nl > l) { add(--nl); }\r\n        while(nr < r) { add(++nr); }\r\
    \n        while(nl < l) { del(nl++); }\r\n        while(nr > r) { del(nr--); }\r\
    \n        return order[ni++];\r\n    }\r\n};\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <algorithm>\r\n#include <cmath>\r\
    \n#include <numeric>\r\n\r\nclass Mo {\r\n\r\n    const int q;\r\n    const std::vector<int>\
    \ lq;\r\n    const std::vector<int> rq;\r\n    const std::vector<int> order;\r\
    \n    int ni, nl, nr;\r\n\r\n    auto sort_query() const {\r\n        std::vector<int>\
    \ order(q);\r\n        std::iota(order.begin(), order.end(), 0);\r\n        int\
    \ w = std::sqrt(q);\r\n        std::sort(order.begin(), order.end(), [&](int a,\
    \ int b) {\r\n            if(lq[a] / w != lq[b] / w) return lq[a] < lq[b];\r\n\
    \            if(rq[a] == rq[b]) { return false; }\r\n            bool less = (rq[a]\
    \ < rq[b]);\r\n            bool flg = (lq[a] / w) & 1;\r\n            return static_cast<bool>(less\
    \ ^ flg);\r\n        });\r\n\r\n        return order;\r\n    }\r\n\r\npublic:\r\
    \n    Mo(int q,\r\n       const std::vector<int>& lq,\r\n       const std::vector<int>&\
    \ rq)\r\n        :q(q), lq(lq), rq(rq), order(sort_query()),\r\n        ni(0),\
    \ nl(0), nr(-1) {\r\n    }\r\n\r\n    template<class Lambda1, class Lambda2>\r\
    \n    auto process(const Lambda1& add, const Lambda2& del) {\r\n        const\
    \ auto l = lq[order[ni]];\r\n        const auto r = rq[order[ni]];\r\n       \
    \ while(nl > l) { add(--nl); }\r\n        while(nr < r) { add(++nr); }\r\n   \
    \     while(nl < l) { del(nl++); }\r\n        while(nr > r) { del(nr--); }\r\n\
    \        return order[ni++];\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: Library/Algorithms/Mo.hpp
  requiredBy: []
  timestamp: '2022-02-06 05:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Algorithms/Mo.hpp
layout: document
redirect_from:
- /library/Library/Algorithms/Mo.hpp
- /library/Library/Algorithms/Mo.hpp.html
title: Library/Algorithms/Mo.hpp
---
