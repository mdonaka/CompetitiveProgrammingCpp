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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ Main/main_srm.cpp: line 28: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "//#pragma GCC target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,avx512f\"\
    )\r\n#pragma GCC target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx\")\r\n#pragma\
    \ GCC optimize(\"O3\")\r\n#pragma GCC optimize(\"unroll-loops\")\r\n#include <iostream>\r\
    \n#include <iomanip>\r\n#include <string>\r\n#include <cmath>\r\n#include <algorithm>\r\
    \n#include <vector>\r\n#include <set>\r\n#include <map>\r\n#include <unordered_map>\r\
    \n#include <unordered_set>\r\n#include <list>\r\n#include <stack>\r\n#include\
    \ <queue>\r\n#include <bitset>\r\n#include <numeric>\r\n#include <cassert>\r\n\
    #include <memory>\r\n#include <random>\r\n#include <functional>\r\n#include <complex>\r\
    \n#include <immintrin.h>\r\n#include <stdexcept>\r\n#ifdef DEBUG\r\n#include \"\
    ./CompetitiveProgrammingCpp/Utils/debug.hpp\"\r\n#include \"./CompetitiveProgrammingCpp/Utils/Timer.hpp\"\
    \r\n#include \"./CompetitiveProgrammingCpp/Utils/sample.hpp\"\r\n#else\r\n#define\
    \ dump(...)\r\n#endif\r\n\r\n/* macro */\r\n#define FOR(i, b, e) for(ll i = (ll)(b);\
    \ i < (ll)(e); ++i)\r\n#define RFOR(i, b, e) for(ll i = (ll)((e)-1); i >= (ll)(b);\
    \ --i)\r\n#define REP(i, n) FOR(i, 0, (n))\r\n#define RREP(i, n) RFOR(i, 0, (n))\r\
    \n#define REPC(x,c) for(const auto& x:(c))\r\n#define REPI2(it,b,e) for(auto it\
    \ = (b); it != (e); ++it)\r\n#define REPI(it,c) REPI2(it, (c).begin(), (c).end())\r\
    \n#define RREPI(it,c) REPI2(it, (c).rbegin(), (c).rend())\r\n#define REPI_ERACE2(it,\
    \ b, e) for(auto it = (b); it != (e);)\r\n#define REPI_ERACE(it, c) REPI_ERACE2(it,\
    \ (c).begin(), (c).end())\r\n#define ALL(x) (x).begin(),(x).end()\r\n#define cauto\
    \ const auto&\r\n/* macro func */\r\ntemplate<class T>\r\nvoid sort(T& t) { std::sort(ALL(t));\
    \ }\r\ntemplate<class T>\r\nvoid rsort(T& t) { std::sort((t).rbegin(), (t).rend());\
    \ }\r\ntemplate<class T>\r\nvoid unique(T& t) { (t).erase(unique((t).begin(),\
    \ (t).end()), (t).end()); }\r\ntemplate<class T, class S>\r\nbool chmax(T& t,\
    \ const S& s) { if(s > t) { t = s; return true; } return false; }\r\ntemplate<class\
    \ T, class S>\r\nbool chmin(T& t, const S& s) { if(s < t) { t = s; return true;\
    \ } return false; }\r\nvoid BR() { std::cout << \"\\n\"; }\r\n\r\n/* type define\
    \ */\r\nusing ll = long long;\r\nusing VS = std::vector<std::string>;\r\nusing\
    \ VL = std::vector<long long>;\r\nusing VVL = std::vector<VL>;\r\nusing VVVL =\
    \ std::vector<VVL>;\r\nusing VVVVL = std::vector<VVVL>;\r\nusing VVVVVL = std::vector<VVVVL>;\r\
    \nusing VD = std::vector<double>;\r\ntemplate<class T>\r\nusing V = std::vector<T>;\r\
    \ntemplate<class T = ll, class U = T>\r\nusing P = std::pair<T, U>;\r\nusing PAIR\
    \ = P<ll>;\r\n\r\n/* using std */\r\nusing std::cout;\r\nconstexpr char endl =\
    \ '\\n';\r\nusing std::cin;\r\nusing std::pair;\r\nusing std::string;\r\nusing\
    \ std::stack;\r\nusing std::queue;\r\nusing std::deque;\r\nusing std::vector;\r\
    \nusing std::list;\r\nusing std::map;\r\nusing std::unordered_map;\r\nusing std::multimap;\r\
    \nusing std::unordered_multimap;\r\nusing std::set;\r\nusing std::unordered_set;\r\
    \nusing std::unordered_multiset;\r\nusing std::multiset;\r\nusing std::bitset;\r\
    \nusing std::priority_queue;\r\n\r\n/* Initial processing  */\r\nstruct Preprocessing\
    \ { Preprocessing() { std::cin.tie(0); std::ios::sync_with_stdio(0); }; }_Preprocessing;\r\
    \n\r\n/* Remove the source of the bug */\r\nvoid pow(signed, signed) { assert(false);\
    \ }\r\n\r\n/* define hash */\r\nnamespace std {\r\ntemplate <>\tclass hash<std::pair<ll,\
    \ ll>> { public:\tsize_t operator()(const std::pair<ll, ll>& x) const { return\
    \ hash<ll>()(1000000000 * x.first + x.second); } };\r\n}\r\n\r\n/* input */\r\n\
    template<class T> std::istream& operator >> (std::istream& is, vector<T>& vec)\
    \ { for(T& x : vec) is >> x; return is; }\r\n\r\n/* constant value */\r\n// constexpr\
    \ ll MOD = 1000000007;\r\nconstexpr ll MOD = 998244353;\r\n\r\n//=============================================================================================\r\
    \n\r\n\r\n/**\r\nsigned main() {\r\n\r\n}\r\n/*//**/"
  dependsOn: []
  isVerificationFile: false
  path: Main/main_srm.cpp
  requiredBy: []
  timestamp: '2022-09-04 03:56:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Main/main_srm.cpp
layout: document
redirect_from:
- /library/Main/main_srm.cpp
- /library/Main/main_srm.cpp.html
title: Main/main_srm.cpp
---