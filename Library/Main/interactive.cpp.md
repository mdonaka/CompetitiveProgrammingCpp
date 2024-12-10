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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ Library/Main/interactive.cpp: line 29: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "//#pragma GCC target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,avx512f\"\
    )\r\n#pragma GCC target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx\")\r\n#pragma\
    \ GCC optimize(\"O3\")\r\n#pragma GCC optimize(\"unroll-loops\")\r\n#include <immintrin.h>\r\
    \n\r\n#include <algorithm>\r\n#include <bitset>\r\n#include <cassert>\r\n#include\
    \ <cmath>\r\n#include <complex>\r\n#include <functional>\r\n#include <iomanip>\r\
    \n#include <iostream>\r\n#include <list>\r\n#include <map>\r\n#include <memory>\r\
    \n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\n#include <set>\r\
    \n#include <stack>\r\n#include <stdexcept>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <unordered_set>\r\n#include <vector>\r\n#ifdef DEBUG\r\n#include \"\
    ./CompetitiveProgrammingCpp/Utils/Timer.hpp\"\r\n#include \"./CompetitiveProgrammingCpp/Utils/debug.hpp\"\
    \r\n#include \"./CompetitiveProgrammingCpp/Utils/sample.hpp\"\r\n#else\r\n#define\
    \ dump(...)\r\ntemplate <class T>\r\nconstexpr inline auto d_val(T a, T b) {\r\
    \n  return a;\r\n}\r\n#endif\r\n\r\n/* macro */\r\n#define FOR(i, b, e) for (ll\
    \ i = (ll)(b); i < (ll)(e); ++i)\r\n#define RFOR(i, b, e) for (ll i = (ll)((e)-1);\
    \ i >= (ll)(b); --i)\r\n#define REP(i, n) FOR(i, 0, (n))\r\n#define RREP(i, n)\
    \ RFOR(i, 0, (n))\r\n#define REPC(x, c) for (const auto& x : (c))\r\n#define REPI2(it,\
    \ b, e) for (auto it = (b); it != (e); ++it)\r\n#define REPI(it, c) REPI2(it,\
    \ (c).begin(), (c).end())\r\n#define RREPI(it, c) REPI2(it, (c).rbegin(), (c).rend())\r\
    \n#define REPI_ERACE2(it, b, e) for (auto it = (b); it != (e);)\r\n#define REPI_ERACE(it,\
    \ c) REPI_ERACE2(it, (c).begin(), (c).end())\r\n#define ALL(x) (x).begin(), (x).end()\r\
    \n/* macro func */\r\ntemplate <class T>\r\ninline auto sort(T& t) {\r\n  std::sort(ALL(t));\r\
    \n}\r\ntemplate <class T>\r\ninline auto rsort(T& t) {\r\n  std::sort((t).rbegin(),\
    \ (t).rend());\r\n}\r\ntemplate <class T, class S>\r\ninline auto chmax(T& t,\
    \ const S& s) {\r\n  if (s > t) {\r\n    t = s;\r\n    return true;\r\n  }\r\n\
    \  return false;\r\n}\r\ntemplate <class T, class S>\r\ninline auto chmin(T& t,\
    \ const S& s) {\r\n  if (s < t) {\r\n    t = s;\r\n    return true;\r\n  }\r\n\
    \  return false;\r\n}\r\ninline auto BR() { std::cout << \"\\n\"; }\r\n\r\n/*\
    \ type define */\r\nusing ll = long long;\r\ntemplate <class T>\r\nusing V = std::vector<T>;\r\
    \nusing VS = V<std::string>;\r\nusing VL = V<ll>;\r\nusing VVL = V<VL>;\r\ntemplate\
    \ <class T = ll, class U = T>\r\nusing P = std::pair<T, U>;\r\nusing PAIR = P<ll>;\r\
    \n\r\n/* using std */\r\nusing std::cerr;\r\nusing std::cin;\r\nusing std::cout;\r\
    \nconstexpr char endl = '\\n';\r\n\r\n/* define hash */\r\nnamespace std {\r\n\
    \  template <>\r\n  class hash<std::pair<ll, ll>> {\r\n  public:\r\n    size_t\
    \ operator()(const std::pair<ll, ll>& x) const {\r\n      return std::hash<ll>()(x.first\
    \ << 31 | x.second);\r\n    }\r\n  };\r\n}  // namespace std\r\n\r\n/* input */\r\
    \ntemplate <class T>\r\nstd::istream& operator>>(std::istream& is, std::vector<T>&\
    \ vec) {\r\n  for (T& x : vec) is >> x;\r\n  return is;\r\n}\r\n\r\n/* constant\
    \ value */\r\n// constexpr ll MOD = 1000000007;\r\nconstexpr ll MOD = 998244353;\r\
    \n\r\n//=============================================================================================\r\
    \n\r\nauto interactive(ll x) {\r\n  constexpr ll QUERY_LIMIT = 26;\r\n  REP(_,\
    \ QUERY_LIMIT) {}\r\n  return false;\r\n}\r\n\r\n#ifdef _WIN32\r\nauto _main()\r\
    \n#else\r\nsigned main()\r\n#endif\r\n{\r\n  // seed settings\r\n  auto seed =\
    \ std::random_device()();\r\n  auto gen = Sample::SampleGenerator(seed);\r\n\r\
    \n  // paramete settings\r\n  constexpr ll MAX = 1e6;\r\n  auto [x] = gen.generate(PAIR{1,\
    \ MAX});\r\n\r\n  // run\r\n  if (!interactive(x)) {\r\n    cerr << \"-- internal\
    \ data --\" << endl;\r\n    cerr << x << endl;\r\n    cerr << \"-------------------\"\
    \ << endl;\r\n    cerr << \"seed: \" << seed << endl;\r\n    cerr << \"-------------------\"\
    \ << endl;\r\n    throw std::runtime_error(\"Failed\");\r\n  }\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: Library/Main/interactive.cpp
  requiredBy: []
  timestamp: '2024-08-05 00:48:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Main/interactive.cpp
layout: document
redirect_from:
- /library/Library/Main/interactive.cpp
- /library/Library/Main/interactive.cpp.html
title: Library/Main/interactive.cpp
---
