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
  bundledCode: "#line 2 \"Library/Algorithms/BinarySearch.hpp\"\n#include <numeric>\r\
    \n\r\ntemplate <class Lambda>\r\nauto binarySearch(double mn, double mx, int rep,\
    \ const Lambda& judge,\r\n                  bool rev = false) {\r\n    auto ok\
    \ = mx;\r\n    auto ng = mn;\r\n    for(int _ = 0; _ < rep; ++_) {\r\n       \
    \ auto mid = (ok + ng) / 2;\r\n        auto isOk = judge(mid);\r\n        if((isOk\
    \ && !rev) || (!isOk && rev)) {\r\n            ok = mid;\r\n        } else {\r\
    \n            ng = mid;\r\n        }\r\n    }\r\n    return ok;\r\n}\r\n\r\ntemplate\
    \ <class Lambda>\r\nauto binarySearch(long long ok, long long ng, const Lambda&\
    \ is_ok) {\r\n    while(std::abs(ok - ng) > 1) {\r\n        long long mid = (ok\
    \ + ng) >> 1;\r\n        (is_ok(mid) ? ok : ng) = mid;\r\n    }\r\n    return\
    \ ok;\r\n}\r\n"
  code: "#pragma once\r\n#include <numeric>\r\n\r\ntemplate <class Lambda>\r\nauto\
    \ binarySearch(double mn, double mx, int rep, const Lambda& judge,\r\n       \
    \           bool rev = false) {\r\n    auto ok = mx;\r\n    auto ng = mn;\r\n\
    \    for(int _ = 0; _ < rep; ++_) {\r\n        auto mid = (ok + ng) / 2;\r\n \
    \       auto isOk = judge(mid);\r\n        if((isOk && !rev) || (!isOk && rev))\
    \ {\r\n            ok = mid;\r\n        } else {\r\n            ng = mid;\r\n\
    \        }\r\n    }\r\n    return ok;\r\n}\r\n\r\ntemplate <class Lambda>\r\n\
    auto binarySearch(long long ok, long long ng, const Lambda& is_ok) {\r\n    while(std::abs(ok\
    \ - ng) > 1) {\r\n        long long mid = (ok + ng) >> 1;\r\n        (is_ok(mid)\
    \ ? ok : ng) = mid;\r\n    }\r\n    return ok;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Algorithms/BinarySearch.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Algorithms/BinarySearch.hpp
layout: document
redirect_from:
- /library/Library/Algorithms/BinarySearch.hpp
- /library/Library/Algorithms/BinarySearch.hpp.html
title: Library/Algorithms/BinarySearch.hpp
---
