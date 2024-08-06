---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/SegmentMap.test.cpp
    title: Test/DataStructure/SegmentMap.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/DataStructure/SegmentMap.hpp\"\n#include <deque>\r\
    \n#include <iostream>\r\n#include <map>\r\n#include <stdexcept>\r\n\r\ntemplate\
    \ <class ValType = long long, class SizeType = long long>\r\nclass SegmentMap\
    \ {\r\n  const SizeType n;\r\n  std::map<SizeType, ValType> mp;\r\n\r\n  auto\
    \ add(SizeType i, ValType val, bool left = true, bool right = true) {\r\n    auto\
    \ it = std::prev(mp.upper_bound(i));\r\n    if (right && std::next(it)->second\
    \ == val) { mp.erase(std::next(it)); }\r\n    if (left && it->second == val) {\
    \ return; }\r\n    mp.emplace(i, val);\r\n  }\r\n\r\n  template <class Iterator>\r\
    \n  auto remove(SizeType l, SizeType r, Iterator& it) {\r\n    auto nx = std::next(it)->first;\r\
    \n    auto val = it->second;\r\n    auto ret = std::next(it);\r\n    if (l <=\
    \ it->first) { ret = mp.erase(it); }\r\n    if (r < nx - 1) { add(r + 1, val,\
    \ false, true); }\r\n    return ret;\r\n  }\r\n\r\n  auto remove(SizeType l, SizeType\
    \ r) {\r\n    auto it = std::prev(mp.upper_bound(l));\r\n    while (it->first\
    \ <= r) { it = remove(l, r, it); }\r\n  }\r\n\r\npublic:\r\n  SegmentMap(SizeType\
    \ n) : n(n) {\r\n    mp.emplace(-1, -1);\r\n    mp.emplace(0, -2);\r\n    mp.emplace(n,\
    \ -1);\r\n  }\r\n\r\n  auto output() const {\r\n    for (auto it = std::next(mp.begin());\
    \ it != std::prev(mp.end()); ++it) {\r\n      std::cout << \"[\" << it->first\
    \ << \", \" << std::next(it)->first - 1\r\n                << \"] :\" << it->second\
    \ << std::endl;\r\n    }\r\n  }\r\n\r\n  auto update(SizeType l, SizeType r, ValType\
    \ val) {\r\n    if (l < 0 || r >= n) { throw std::runtime_error(\"\"); }\r\n \
    \   if (l > r) { throw std::runtime_error(\"\"); }\r\n    remove(l, r);\r\n  \
    \  add(l, val);\r\n  }\r\n\r\n  auto query(SizeType l, SizeType r) {\r\n    if\
    \ (l < 0 || r >= n) { throw std::runtime_error(\"\"); }\r\n    if (l > r) { throw\
    \ std::runtime_error(\"\"); }\r\n    auto it = std::prev(mp.upper_bound(l));\r\
    \n    std::deque<std::pair<ValType, std::pair<SizeType, SizeType>>> dq;\r\n  \
    \  while (it->first <= r) {\r\n      auto nx = std::next(it)->first;\r\n     \
    \ auto nr = std::min(nx - 1, r);\r\n      auto nl = std::max(l, it->first);\r\n\
    \      dq.emplace_back(it->second, std::pair{nl, nr});\r\n      ++it;\r\n    }\r\
    \n    return dq;\r\n  }\r\n\r\n  auto get(SizeType i) const {\r\n    auto it =\
    \ std::prev(mp.upper_bound(i));\r\n    auto nx = std::next(it)->first;\r\n   \
    \ auto nr = nx - 1;\r\n    auto nl = it->first;\r\n    return std::pair{it->second,\
    \ std::pair{nl, nr}};\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n#include <deque>\r\n#include <iostream>\r\n#include <map>\r\
    \n#include <stdexcept>\r\n\r\ntemplate <class ValType = long long, class SizeType\
    \ = long long>\r\nclass SegmentMap {\r\n  const SizeType n;\r\n  std::map<SizeType,\
    \ ValType> mp;\r\n\r\n  auto add(SizeType i, ValType val, bool left = true, bool\
    \ right = true) {\r\n    auto it = std::prev(mp.upper_bound(i));\r\n    if (right\
    \ && std::next(it)->second == val) { mp.erase(std::next(it)); }\r\n    if (left\
    \ && it->second == val) { return; }\r\n    mp.emplace(i, val);\r\n  }\r\n\r\n\
    \  template <class Iterator>\r\n  auto remove(SizeType l, SizeType r, Iterator&\
    \ it) {\r\n    auto nx = std::next(it)->first;\r\n    auto val = it->second;\r\
    \n    auto ret = std::next(it);\r\n    if (l <= it->first) { ret = mp.erase(it);\
    \ }\r\n    if (r < nx - 1) { add(r + 1, val, false, true); }\r\n    return ret;\r\
    \n  }\r\n\r\n  auto remove(SizeType l, SizeType r) {\r\n    auto it = std::prev(mp.upper_bound(l));\r\
    \n    while (it->first <= r) { it = remove(l, r, it); }\r\n  }\r\n\r\npublic:\r\
    \n  SegmentMap(SizeType n) : n(n) {\r\n    mp.emplace(-1, -1);\r\n    mp.emplace(0,\
    \ -2);\r\n    mp.emplace(n, -1);\r\n  }\r\n\r\n  auto output() const {\r\n   \
    \ for (auto it = std::next(mp.begin()); it != std::prev(mp.end()); ++it) {\r\n\
    \      std::cout << \"[\" << it->first << \", \" << std::next(it)->first - 1\r\
    \n                << \"] :\" << it->second << std::endl;\r\n    }\r\n  }\r\n\r\
    \n  auto update(SizeType l, SizeType r, ValType val) {\r\n    if (l < 0 || r >=\
    \ n) { throw std::runtime_error(\"\"); }\r\n    if (l > r) { throw std::runtime_error(\"\
    \"); }\r\n    remove(l, r);\r\n    add(l, val);\r\n  }\r\n\r\n  auto query(SizeType\
    \ l, SizeType r) {\r\n    if (l < 0 || r >= n) { throw std::runtime_error(\"\"\
    ); }\r\n    if (l > r) { throw std::runtime_error(\"\"); }\r\n    auto it = std::prev(mp.upper_bound(l));\r\
    \n    std::deque<std::pair<ValType, std::pair<SizeType, SizeType>>> dq;\r\n  \
    \  while (it->first <= r) {\r\n      auto nx = std::next(it)->first;\r\n     \
    \ auto nr = std::min(nx - 1, r);\r\n      auto nl = std::max(l, it->first);\r\n\
    \      dq.emplace_back(it->second, std::pair{nl, nr});\r\n      ++it;\r\n    }\r\
    \n    return dq;\r\n  }\r\n\r\n  auto get(SizeType i) const {\r\n    auto it =\
    \ std::prev(mp.upper_bound(i));\r\n    auto nx = std::next(it)->first;\r\n   \
    \ auto nr = nx - 1;\r\n    auto nl = it->first;\r\n    return std::pair{it->second,\
    \ std::pair{nl, nr}};\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/DataStructure/SegmentMap.hpp
  requiredBy: []
  timestamp: '2024-08-06 04:18:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/DataStructure/SegmentMap.test.cpp
documentation_of: Library/DataStructure/SegmentMap.hpp
layout: document
redirect_from:
- /library/Library/DataStructure/SegmentMap.hpp
- /library/Library/DataStructure/SegmentMap.hpp.html
title: Library/DataStructure/SegmentMap.hpp
---
