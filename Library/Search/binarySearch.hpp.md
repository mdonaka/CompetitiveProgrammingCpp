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
  bundledCode: "#line 1 \"Library/Search/binarySearch.hpp\"\ntemplate <class Lambda>\r\
    \nauto binarySearch(double mn, double mx, int rep, const Lambda& judge,\r\n\t\t\
    \  bool rev = false) {\r\n  auto ok = mx;\r\n  auto ng = mn;\r\n  for (int _ =\
    \ 0; _ < rep; ++_) {\r\n    auto mid = (ok + ng) / 2;\r\n    auto isOk = judge(mid);\r\
    \n    if ((isOk && !rev) || (!isOk && rev)) {\r\n      ok = mid;\r\n    } else\
    \ {\r\n      ng = mid;\r\n    }\r\n  }\r\n  return ok;\r\n}\r\n\r\ntemplate <class\
    \ Lambda>\r\nauto binarySearch(ll mn, ll mx, const Lambda& judge, bool rev = false)\
    \ {\r\n  auto ok = mx;\r\n  auto ng = mn - 1;\r\n  while (ok - ng > 1) {\r\n \
    \   auto mid = (ok + ng) / 2;\r\n    auto isOk = judge(mid);\r\n    if ((isOk\
    \ && !rev) || (!isOk && rev)) {\r\n      ok = mid;\r\n    } else {\r\n      ng\
    \ = mid;\r\n    }\r\n  }\r\n  return ok;\r\n}\r\n"
  code: "template <class Lambda>\r\nauto binarySearch(double mn, double mx, int rep,\
    \ const Lambda& judge,\r\n\t\t  bool rev = false) {\r\n  auto ok = mx;\r\n  auto\
    \ ng = mn;\r\n  for (int _ = 0; _ < rep; ++_) {\r\n    auto mid = (ok + ng) /\
    \ 2;\r\n    auto isOk = judge(mid);\r\n    if ((isOk && !rev) || (!isOk && rev))\
    \ {\r\n      ok = mid;\r\n    } else {\r\n      ng = mid;\r\n    }\r\n  }\r\n\
    \  return ok;\r\n}\r\n\r\ntemplate <class Lambda>\r\nauto binarySearch(ll mn,\
    \ ll mx, const Lambda& judge, bool rev = false) {\r\n  auto ok = mx;\r\n  auto\
    \ ng = mn - 1;\r\n  while (ok - ng > 1) {\r\n    auto mid = (ok + ng) / 2;\r\n\
    \    auto isOk = judge(mid);\r\n    if ((isOk && !rev) || (!isOk && rev)) {\r\n\
    \      ok = mid;\r\n    } else {\r\n      ng = mid;\r\n    }\r\n  }\r\n  return\
    \ ok;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Search/binarySearch.hpp
  requiredBy: []
  timestamp: '2021-02-09 14:06:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Search/binarySearch.hpp
layout: document
redirect_from:
- /library/Library/Search/binarySearch.hpp
- /library/Library/Search/binarySearch.hpp.html
title: Library/Search/binarySearch.hpp
---
