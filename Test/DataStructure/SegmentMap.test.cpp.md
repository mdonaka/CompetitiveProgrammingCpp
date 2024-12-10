---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/SegmentMap.hpp
    title: Library/DataStructure/SegmentMap.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/674
    links:
    - https://yukicoder.me/problems/no/674
  bundledCode: "#line 1 \"Test/DataStructure/SegmentMap.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/674\"\r\n\r\n// begin:tag includes\r\n#line\
    \ 2 \"Library/DataStructure/SegmentMap.hpp\"\n#include <deque>\r\n#include <iostream>\r\
    \n#include <map>\r\n#include <stdexcept>\r\n\r\nnamespace mtd {\r\n  template\
    \ <class ValType = long long, class SizeType = long long>\r\n  class SegmentMap\
    \ {\r\n    const SizeType n;\r\n    std::map<SizeType, ValType> mp;\r\n\r\n  \
    \  auto add(SizeType i, ValType val, bool left = true, bool right = true) {\r\n\
    \      auto it = std::prev(mp.upper_bound(i));\r\n      if (right && std::next(it)->second\
    \ == val) { mp.erase(std::next(it)); }\r\n      if (left && it->second == val)\
    \ { return; }\r\n      mp.emplace(i, val);\r\n    }\r\n\r\n    template <class\
    \ Iterator>\r\n    auto remove(SizeType l, SizeType r, Iterator& it) {\r\n   \
    \   auto nx = std::next(it)->first;\r\n      auto val = it->second;\r\n      auto\
    \ ret = std::next(it);\r\n      if (l <= it->first) { ret = mp.erase(it); }\r\n\
    \      if (r < nx - 1) { add(r + 1, val, false, true); }\r\n      return ret;\r\
    \n    }\r\n\r\n    auto remove(SizeType l, SizeType r) {\r\n      auto it = std::prev(mp.upper_bound(l));\r\
    \n      while (it->first <= r) { it = remove(l, r, it); }\r\n    }\r\n\r\n  public:\r\
    \n    SegmentMap(SizeType n) : n(n) {\r\n      mp.emplace(-1, -1);\r\n      mp.emplace(0,\
    \ -2);\r\n      mp.emplace(n, -1);\r\n    }\r\n\r\n    auto output() const {\r\
    \n      for (auto it = std::next(mp.begin()); it != std::prev(mp.end()); ++it)\
    \ {\r\n        std::cout << \"[\" << it->first << \", \" << std::next(it)->first\
    \ - 1\r\n                  << \"] :\" << it->second << std::endl;\r\n      }\r\
    \n    }\r\n\r\n    auto update(SizeType l, SizeType r, ValType val) {\r\n    \
    \  if (l < 0 || r >= n) {\r\n        throw std::runtime_error(\"out of range:\
    \ (\" + std::to_string(l) +\r\n                                 \" < 0) or (\"\
    \ + std::to_string(r) +\r\n                                 \" >= \" + std::to_string(n)\
    \ + \")\");\r\n      }\r\n      if (l > r) { throw std::runtime_error(\"\"); }\r\
    \n      remove(l, r);\r\n      add(l, val);\r\n    }\r\n\r\n    /*\r\n     * return:\
    \ [{left, right, value}, ...]\r\n     * */\r\n    auto query(SizeType l, SizeType\
    \ r) {\r\n      if (l < 0 || r >= n) { throw std::runtime_error(\"\"); }\r\n \
    \     if (l > r) { throw std::runtime_error(\"\"); }\r\n      auto it = std::prev(mp.upper_bound(l));\r\
    \n      std::deque<std::tuple<SizeType, SizeType, ValType>> dq;\r\n      while\
    \ (it->first <= r) {\r\n        auto nx = std::next(it)->first;\r\n        auto\
    \ nr = std::min(nx - 1, r);\r\n        auto nl = std::max(l, it->first);\r\n \
    \       dq.emplace_back(nl, nr, it->second);\r\n        ++it;\r\n      }\r\n \
    \     return dq;\r\n    }\r\n\r\n    /*\r\n     * return: {left, right, value}\r\
    \n     * */\r\n    auto get(SizeType i) const {\r\n      auto it = std::prev(mp.upper_bound(i));\r\
    \n      auto nx = std::next(it)->first;\r\n      auto nr = nx - 1;\r\n      auto\
    \ nl = it->first;\r\n      return std::make_tuple(nl, nr, it->second);\r\n   \
    \ }\r\n  };\r\n}  // namespace mtd\r\n#line 5 \"Test/DataStructure/SegmentMap.test.cpp\"\
    \n// end:tag includes\r\n\r\n#line 8 \"Test/DataStructure/SegmentMap.test.cpp\"\
    \n#include <ranges>\r\n\r\nusing ll = long long;\r\nusing std::cin;\r\nusing std::cout;\r\
    \nconstexpr char endl = '\\n';\r\n\r\nsigned main() {\r\n  ll d, q;\r\n  cin >>\
    \ d >> q;\r\n\r\n  auto segmap = mtd::SegmentMap(d);\r\n\r\n  ll ans = 0;\r\n\
    \  for ([[maybe_unused]] auto _ : std::views::iota(0, q)) {\r\n    ll a, b;\r\n\
    \    cin >> a >> b;\r\n    segmap.update(a, b, 1);\r\n\r\n    auto [l, r, __]\
    \ = segmap.get(a);\r\n    ans = std::max(ans, r - l + 1);\r\n    cout << ans <<\
    \ endl;\r\n  }\r\n}\r\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/674\"\r\n\r\n// begin:tag\
    \ includes\r\n#include \"./../../Library/DataStructure/SegmentMap.hpp\"\r\n//\
    \ end:tag includes\r\n\r\n#include <iostream>\r\n#include <ranges>\r\n\r\nusing\
    \ ll = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr char endl\
    \ = '\\n';\r\n\r\nsigned main() {\r\n  ll d, q;\r\n  cin >> d >> q;\r\n\r\n  auto\
    \ segmap = mtd::SegmentMap(d);\r\n\r\n  ll ans = 0;\r\n  for ([[maybe_unused]]\
    \ auto _ : std::views::iota(0, q)) {\r\n    ll a, b;\r\n    cin >> a >> b;\r\n\
    \    segmap.update(a, b, 1);\r\n\r\n    auto [l, r, __] = segmap.get(a);\r\n \
    \   ans = std::max(ans, r - l + 1);\r\n    cout << ans << endl;\r\n  }\r\n}\r\n"
  dependsOn:
  - Library/DataStructure/SegmentMap.hpp
  isVerificationFile: true
  path: Test/DataStructure/SegmentMap.test.cpp
  requiredBy: []
  timestamp: '2024-11-30 11:22:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/DataStructure/SegmentMap.test.cpp
layout: document
redirect_from:
- /verify/Test/DataStructure/SegmentMap.test.cpp
- /verify/Test/DataStructure/SegmentMap.test.cpp.html
title: Test/DataStructure/SegmentMap.test.cpp
---
