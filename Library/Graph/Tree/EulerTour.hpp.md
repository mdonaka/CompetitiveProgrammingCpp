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
  bundledCode: "#line 2 \"Library/Graph/Tree/EulerTour.hpp\"\n#include <stack>\r\n\
    #include <unordered_map>\r\n#include <vector>\r\n\r\nnamespace mtd {\r\n  class\
    \ EulerTour {\r\n    const std::vector<int> m_tour;\r\n    const std::vector<std::pair<int,\
    \ int>> m_appear;\r\n\r\n    auto constructTour(int n, const std::unordered_multimap<int,\
    \ int>& tree,\r\n                       int root) const {\r\n      std::vector<int>\
    \ tour;\r\n      tour.reserve(2 * n);\r\n      std::stack<int> stk;\r\n      std::vector<int>\
    \ used(n);\r\n      stk.emplace(root);\r\n      while (!stk.empty()) {\r\n   \
    \     auto from = stk.top();\r\n        tour.emplace_back(from);\r\n        stk.pop();\r\
    \n        if (used[from]) { continue; }\r\n        stk.emplace(from);\r\n    \
    \    used[from] = true;\r\n\r\n        auto range = tree.equal_range(from);\r\n\
    \        for (auto it = range.first; it != range.second; ++it) {\r\n         \
    \ auto to = it->second;\r\n          if (!used[to]) { stk.emplace(to); }\r\n \
    \       }\r\n      }\r\n      return tour;\r\n    }\r\n    auto constructAppear(int\
    \ n) const {\r\n      std::vector<std::pair<int, int>> appear(n, {-1, -1});\r\n\
    \      for (int i = 0; i < 2 * n; ++i) {\r\n        if (appear[m_tour[i]].first\
    \ == -1) {\r\n          appear[m_tour[i]].first = i;\r\n        } else {\r\n \
    \         appear[m_tour[i]].second = i;\r\n        }\r\n      }\r\n      return\
    \ appear;\r\n    }\r\n\r\n  public:\r\n    EulerTour(int n, const std::unordered_multimap<int,\
    \ int>& tree, int root)\r\n        : m_tour(constructTour(n, tree, root)), m_appear(constructAppear(n))\
    \ {}\r\n\r\n    auto lessOrder(int li, int ri) const {\r\n      return m_appear[li].first\
    \ < m_appear[ri].first;\r\n    }\r\n    auto isSon(int son, int parent) {\r\n\
    \      return m_appear[parent].first < m_appear[son].first &&\r\n            \
    \ m_appear[son].second < m_appear[parent].second;\r\n    }\r\n  };\r\n}  // namespace\
    \ mtd\r\n"
  code: "#pragma once\r\n#include <stack>\r\n#include <unordered_map>\r\n#include\
    \ <vector>\r\n\r\nnamespace mtd {\r\n  class EulerTour {\r\n    const std::vector<int>\
    \ m_tour;\r\n    const std::vector<std::pair<int, int>> m_appear;\r\n\r\n    auto\
    \ constructTour(int n, const std::unordered_multimap<int, int>& tree,\r\n    \
    \                   int root) const {\r\n      std::vector<int> tour;\r\n    \
    \  tour.reserve(2 * n);\r\n      std::stack<int> stk;\r\n      std::vector<int>\
    \ used(n);\r\n      stk.emplace(root);\r\n      while (!stk.empty()) {\r\n   \
    \     auto from = stk.top();\r\n        tour.emplace_back(from);\r\n        stk.pop();\r\
    \n        if (used[from]) { continue; }\r\n        stk.emplace(from);\r\n    \
    \    used[from] = true;\r\n\r\n        auto range = tree.equal_range(from);\r\n\
    \        for (auto it = range.first; it != range.second; ++it) {\r\n         \
    \ auto to = it->second;\r\n          if (!used[to]) { stk.emplace(to); }\r\n \
    \       }\r\n      }\r\n      return tour;\r\n    }\r\n    auto constructAppear(int\
    \ n) const {\r\n      std::vector<std::pair<int, int>> appear(n, {-1, -1});\r\n\
    \      for (int i = 0; i < 2 * n; ++i) {\r\n        if (appear[m_tour[i]].first\
    \ == -1) {\r\n          appear[m_tour[i]].first = i;\r\n        } else {\r\n \
    \         appear[m_tour[i]].second = i;\r\n        }\r\n      }\r\n      return\
    \ appear;\r\n    }\r\n\r\n  public:\r\n    EulerTour(int n, const std::unordered_multimap<int,\
    \ int>& tree, int root)\r\n        : m_tour(constructTour(n, tree, root)), m_appear(constructAppear(n))\
    \ {}\r\n\r\n    auto lessOrder(int li, int ri) const {\r\n      return m_appear[li].first\
    \ < m_appear[ri].first;\r\n    }\r\n    auto isSon(int son, int parent) {\r\n\
    \      return m_appear[parent].first < m_appear[son].first &&\r\n            \
    \ m_appear[son].second < m_appear[parent].second;\r\n    }\r\n  };\r\n}  // namespace\
    \ mtd\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Graph/Tree/EulerTour.hpp
  requiredBy: []
  timestamp: '2024-11-12 00:26:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Graph/Tree/EulerTour.hpp
layout: document
redirect_from:
- /library/Library/Graph/Tree/EulerTour.hpp
- /library/Library/Graph/Tree/EulerTour.hpp.html
title: Library/Graph/Tree/EulerTour.hpp
---
