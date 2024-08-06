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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ Library/Main/main.cpp: line 26: unable to process #include in #if / #ifdef /\
    \ #ifndef other than include guards\n"
  code: "#include <algorithm>\r\n#include <bitset>\r\n#include <cassert>\r\n#include\
    \ <cmath>\r\n#include <complex>\r\n#include <functional>\r\n#include <iomanip>\r\
    \n#include <iostream>\r\n#include <list>\r\n#include <map>\r\n#include <memory>\r\
    \n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\n#include <ranges>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <stdexcept>\r\n#include <string>\r\
    \n#include <unordered_map>\r\n#include <unordered_set>\r\n#include <vector>\r\n\
    \r\n// clang-format off\r\n#ifdef DEBUG\r\n#include \"./Library/Debug/debug.hpp\"\
    \r\n#include \"./Library/Debug/Timer.hpp\"\r\n#include \"./Library/Debug/sample.hpp\"\
    \r\n#else\r\n#define dump(...)\r\ntemplate<class T>constexpr inline auto d_val(T\
    \ a, T b) { return a; }\r\n#endif\r\n\r\n/* macro func */\r\ntemplate<class T,\
    \ class S>\r\ninline auto chmax(T& t, const S& s) { if(s > t) { t = s; return\
    \ true; } return false; }\r\ntemplate<class T, class S>\r\ninline auto chmin(T&\
    \ t, const S& s) { if(s < t) { t = s; return true; } return false; }\r\ntemplate<class\
    \ S> constexpr auto vec(S x) { return x; }\r\ntemplate<class S, class... T> constexpr\
    \ auto vec(S x, int n, T... ns) { return std::vector(n, vec(x, ns...)); }\r\n\r\
    \n/* Initial processing  */\r\nstruct Preprocessing { Preprocessing() { std::cin.tie(0);\
    \ std::ios::sync_with_stdio(0); }; }_Preprocessing;\r\n\r\n/* input */\r\ntemplate<class\
    \ T> std::istream& operator >> (std::istream& is, std::vector<T>& vec) { for(T&\
    \ x : vec) is >> x; return is; }\r\n\r\n// clang-format on\r\n//=============================================================================================\r\
    \n// tag:includes begin\r\n\r\n// tag:includes end\r\n//=============================================================================================\r\
    \n\r\nusing ll = long long;\r\n\r\nsigned main() {}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Main/main.cpp
  requiredBy: []
  timestamp: '2024-08-07 01:06:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Main/main.cpp
layout: document
redirect_from:
- /library/Library/Main/main.cpp
- /library/Library/Main/main.cpp.html
title: Library/Main/main.cpp
---
