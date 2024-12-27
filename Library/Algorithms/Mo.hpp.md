---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Algorithms/Mo.test.cpp
    title: Test/Algorithms/Mo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Algorithms/Mo.hpp\"\n#include <algorithm>\r\n#include\
    \ <cmath>\r\n#include <numeric>\r\n#include <vector>\r\n\r\nnamespace mtd {\r\n\
    \r\n  class Mo {\r\n    const int q;\r\n    const std::vector<int> lq;\r\n   \
    \ const std::vector<int> rq;\r\n    const std::vector<int> order;\r\n    int ni,\
    \ nl, nr;\r\n\r\n    auto sort_query() const {\r\n      std::vector<int> _order(q);\r\
    \n      std::iota(_order.begin(), _order.end(), 0);\r\n      int w = static_cast<int>(std::sqrt(q));\r\
    \n      std::sort(_order.begin(), _order.end(), [&](int a, int b) {\r\n      \
    \  if (lq[a] / w != lq[b] / w) return lq[a] < lq[b];\r\n        if (rq[a] == rq[b])\
    \ { return false; }\r\n        bool less = (rq[a] < rq[b]);\r\n        bool flg\
    \ = (lq[a] / w) & 1;\r\n        return static_cast<bool>(less ^ flg);\r\n    \
    \  });\r\n      return _order;\r\n    }\r\n\r\n  public:\r\n    Mo(int _q, const\
    \ std::vector<int>& _lq, const std::vector<int>& _rq)\r\n        : q(_q), lq(_lq),\
    \ rq(_rq), order(sort_query()), ni(0), nl(0), nr(-1) {}\r\n\r\n    template <class\
    \ Lambda1, class Lambda2>\r\n    auto process(const Lambda1& add, const Lambda2&\
    \ del) {\r\n      const auto l = lq[order[ni]];\r\n      const auto r = rq[order[ni]];\r\
    \n      while (nl > l) { add(--nl); }\r\n      while (nr < r) { add(++nr); }\r\
    \n      while (nl < l) { del(nl++); }\r\n      while (nr > r) { del(nr--); }\r\
    \n      return order[ni++];\r\n    }\r\n  };\r\n\r\n}  // namespace mtd\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <cmath>\r\n#include <numeric>\r\
    \n#include <vector>\r\n\r\nnamespace mtd {\r\n\r\n  class Mo {\r\n    const int\
    \ q;\r\n    const std::vector<int> lq;\r\n    const std::vector<int> rq;\r\n \
    \   const std::vector<int> order;\r\n    int ni, nl, nr;\r\n\r\n    auto sort_query()\
    \ const {\r\n      std::vector<int> _order(q);\r\n      std::iota(_order.begin(),\
    \ _order.end(), 0);\r\n      int w = static_cast<int>(std::sqrt(q));\r\n     \
    \ std::sort(_order.begin(), _order.end(), [&](int a, int b) {\r\n        if (lq[a]\
    \ / w != lq[b] / w) return lq[a] < lq[b];\r\n        if (rq[a] == rq[b]) { return\
    \ false; }\r\n        bool less = (rq[a] < rq[b]);\r\n        bool flg = (lq[a]\
    \ / w) & 1;\r\n        return static_cast<bool>(less ^ flg);\r\n      });\r\n\
    \      return _order;\r\n    }\r\n\r\n  public:\r\n    Mo(int _q, const std::vector<int>&\
    \ _lq, const std::vector<int>& _rq)\r\n        : q(_q), lq(_lq), rq(_rq), order(sort_query()),\
    \ ni(0), nl(0), nr(-1) {}\r\n\r\n    template <class Lambda1, class Lambda2>\r\
    \n    auto process(const Lambda1& add, const Lambda2& del) {\r\n      const auto\
    \ l = lq[order[ni]];\r\n      const auto r = rq[order[ni]];\r\n      while (nl\
    \ > l) { add(--nl); }\r\n      while (nr < r) { add(++nr); }\r\n      while (nl\
    \ < l) { del(nl++); }\r\n      while (nr > r) { del(nr--); }\r\n      return order[ni++];\r\
    \n    }\r\n  };\r\n\r\n}  // namespace mtd\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Algorithms/Mo.hpp
  requiredBy: []
  timestamp: '2024-12-27 17:07:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Algorithms/Mo.test.cpp
documentation_of: Library/Algorithms/Mo.hpp
layout: document
redirect_from:
- /library/Library/Algorithms/Mo.hpp
- /library/Library/Algorithms/Mo.hpp.html
title: Library/Algorithms/Mo.hpp
---
