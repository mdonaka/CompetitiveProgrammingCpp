---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/LiChaoTree.test.cpp
    title: Test/DataStructure/LiChaoTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/DataStructure/LiChaoTree.hpp\"\n\r\n#include <vector>\r\
    \n#include <algorithm>\r\n#include <unordered_map>\r\n\r\nclass LiChaoTree {\r\
    \n    using T = long long;\r\n    using Line = std::pair<T, T>;\r\n    constexpr\
    \ static T mul_mx = 1e9;\r\n    constexpr static T add_mx = 1e18;\r\n\r\n    int\
    \ m_size;\r\n    std::vector<T> m_x;\r\n    std::vector<Line> m_node;\r\n    std::unordered_map<T,\
    \ T> m_xtoi;\r\n\r\n    static inline int calcSize(int n) { int size = 1; while(size\
    \ < n) { size <<= 1; }return size; }\r\n    auto f(const Line& line, const T&\
    \ x)const { return line.first * x + line.second; }\r\n\r\n    auto add(const Line&\
    \ line_, int k, int l, int r) {\r\n        auto line = line_;\r\n\r\n        auto\
    \ m = (l + r) / 2;\r\n        if(f(line, m_x[m]) < f(m_node[k], m_x[m])) { std::swap(line,\
    \ m_node[k]); }\r\n        if(l + 1 == r) { return; }\r\n        if(line.first\
    \ > m_node[k].first) {\r\n            add(line, (k << 1) + 1, l, m);\r\n     \
    \   } else if(line.first < m_node[k].first) {\r\n            add(line, (k << 1)\
    \ + 2, m, r);\r\n        }\r\n    }\r\n\r\npublic:\r\n    LiChaoTree(const std::vector<T>&\
    \ x_) {\r\n        auto x = x_;\r\n        std::sort(x.begin(), x.end());\r\n\
    \        x.erase(std::unique(x.begin(), x.end()), x.end());\r\n\r\n        m_size\
    \ = calcSize(x.size());\r\n        m_x = decltype(m_x)(m_size, mul_mx);\r\n  \
    \      m_node = decltype(m_node)((m_size << 1) - 1, {0,add_mx});\r\n        for(size_t\
    \ i = 0; i < x.size(); ++i) {\r\n            m_x[i] = x[i];\r\n            m_xtoi.emplace(x[i],\
    \ i);\r\n        }\r\n    }\r\n\r\n    auto add(const Line& line) { add(line,\
    \ 0, 0, m_size); }\r\n    auto add(const T& a, const T& b) { add({a,b}); }\r\n\
    \r\n    auto query(const T& x) {\r\n        auto k = m_xtoi[x] + m_size - 1;\r\
    \n        auto ret = add_mx << 1;\r\n        while(k >= 0) {\r\n            ret\
    \ = std::min(ret, f(m_node[k], x));\r\n            k = (k - 1) >> 1;\r\n     \
    \   }\r\n        return ret;\r\n    }\r\n};\r\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n#include <algorithm>\r\n#include\
    \ <unordered_map>\r\n\r\nclass LiChaoTree {\r\n    using T = long long;\r\n  \
    \  using Line = std::pair<T, T>;\r\n    constexpr static T mul_mx = 1e9;\r\n \
    \   constexpr static T add_mx = 1e18;\r\n\r\n    int m_size;\r\n    std::vector<T>\
    \ m_x;\r\n    std::vector<Line> m_node;\r\n    std::unordered_map<T, T> m_xtoi;\r\
    \n\r\n    static inline int calcSize(int n) { int size = 1; while(size < n) {\
    \ size <<= 1; }return size; }\r\n    auto f(const Line& line, const T& x)const\
    \ { return line.first * x + line.second; }\r\n\r\n    auto add(const Line& line_,\
    \ int k, int l, int r) {\r\n        auto line = line_;\r\n\r\n        auto m =\
    \ (l + r) / 2;\r\n        if(f(line, m_x[m]) < f(m_node[k], m_x[m])) { std::swap(line,\
    \ m_node[k]); }\r\n        if(l + 1 == r) { return; }\r\n        if(line.first\
    \ > m_node[k].first) {\r\n            add(line, (k << 1) + 1, l, m);\r\n     \
    \   } else if(line.first < m_node[k].first) {\r\n            add(line, (k << 1)\
    \ + 2, m, r);\r\n        }\r\n    }\r\n\r\npublic:\r\n    LiChaoTree(const std::vector<T>&\
    \ x_) {\r\n        auto x = x_;\r\n        std::sort(x.begin(), x.end());\r\n\
    \        x.erase(std::unique(x.begin(), x.end()), x.end());\r\n\r\n        m_size\
    \ = calcSize(x.size());\r\n        m_x = decltype(m_x)(m_size, mul_mx);\r\n  \
    \      m_node = decltype(m_node)((m_size << 1) - 1, {0,add_mx});\r\n        for(size_t\
    \ i = 0; i < x.size(); ++i) {\r\n            m_x[i] = x[i];\r\n            m_xtoi.emplace(x[i],\
    \ i);\r\n        }\r\n    }\r\n\r\n    auto add(const Line& line) { add(line,\
    \ 0, 0, m_size); }\r\n    auto add(const T& a, const T& b) { add({a,b}); }\r\n\
    \r\n    auto query(const T& x) {\r\n        auto k = m_xtoi[x] + m_size - 1;\r\
    \n        auto ret = add_mx << 1;\r\n        while(k >= 0) {\r\n            ret\
    \ = std::min(ret, f(m_node[k], x));\r\n            k = (k - 1) >> 1;\r\n     \
    \   }\r\n        return ret;\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/DataStructure/LiChaoTree.hpp
  requiredBy: []
  timestamp: '2023-03-07 04:44:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/DataStructure/LiChaoTree.test.cpp
documentation_of: Library/DataStructure/LiChaoTree.hpp
layout: document
redirect_from:
- /library/Library/DataStructure/LiChaoTree.hpp
- /library/Library/DataStructure/LiChaoTree.hpp.html
title: Library/DataStructure/LiChaoTree.hpp
---
