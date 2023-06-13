---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Normal/Kruskal.hpp
    title: Library/Graph/Normal/Kruskal.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/UnionFind.test.cpp
    title: Test/DataStructure/UnionFind.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Graph/Normal/Kruskal.test.cpp
    title: Test/Graph/Normal/Kruskal.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/DataStructure/UnionFind.hpp\"\n#include <vector>\r\
    \n#include <numeric>\r\n/**\r\n *\tUnionFind\u6728\u3092\u69CB\u6210\u3059\u308B\
    \r\n *\tnode\u306E\u6DF1\u3055\uFF0C\u6728\u306E\u30B5\u30A4\u30BA\u3092\u53D6\
    \u5F97\u53EF\u80FD\r\n */\r\nclass UnionFind {\r\n    std::vector<int> m_root;\r\
    \n    std::vector<int> m_depth;\r\n    std::vector<int> m_size;\r\npublic:\r\n\
    \    UnionFind(int size) :\r\n        m_root(size),\r\n        m_depth(size, 0),\r\
    \n        m_size(size, 1) {\r\n        std::iota(m_root.begin(), m_root.end(),\
    \ 0);\r\n    }\r\n    void unite(int x, int y) {\r\n        x = root(x); y = root(y);\r\
    \n        if(x == y) { return; }\r\n        auto t = size(x) + size(y);\r\n  \
    \      m_size[x] = m_size[y] = t;\r\n        if(m_depth[x] < m_depth[y]) { m_root[x]\
    \ = y; } else { m_root[y] = x; }\r\n        if(m_depth[x] == m_depth[y]) { ++m_depth[x];\
    \ }\r\n    }\r\n    bool isSame(int x, int y) {\r\n        return root(x) == root(y);\r\
    \n    }\r\n    int root(int x) {\r\n        if(m_root[x] == x) { return x; }\r\
    \n        return m_root[x] = root(m_root[x]);\r\n    }\r\n    int size(int x)\
    \ {\r\n        if(m_root[x] == x) { return m_size[x]; }\r\n        return size(m_root[x]\
    \ = root(m_root[x]));\r\n    }\r\n};\r\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <numeric>\r\n/**\r\n *\tUnionFind\u6728\
    \u3092\u69CB\u6210\u3059\u308B\r\n *\tnode\u306E\u6DF1\u3055\uFF0C\u6728\u306E\
    \u30B5\u30A4\u30BA\u3092\u53D6\u5F97\u53EF\u80FD\r\n */\r\nclass UnionFind {\r\
    \n    std::vector<int> m_root;\r\n    std::vector<int> m_depth;\r\n    std::vector<int>\
    \ m_size;\r\npublic:\r\n    UnionFind(int size) :\r\n        m_root(size),\r\n\
    \        m_depth(size, 0),\r\n        m_size(size, 1) {\r\n        std::iota(m_root.begin(),\
    \ m_root.end(), 0);\r\n    }\r\n    void unite(int x, int y) {\r\n        x =\
    \ root(x); y = root(y);\r\n        if(x == y) { return; }\r\n        auto t =\
    \ size(x) + size(y);\r\n        m_size[x] = m_size[y] = t;\r\n        if(m_depth[x]\
    \ < m_depth[y]) { m_root[x] = y; } else { m_root[y] = x; }\r\n        if(m_depth[x]\
    \ == m_depth[y]) { ++m_depth[x]; }\r\n    }\r\n    bool isSame(int x, int y) {\r\
    \n        return root(x) == root(y);\r\n    }\r\n    int root(int x) {\r\n   \
    \     if(m_root[x] == x) { return x; }\r\n        return m_root[x] = root(m_root[x]);\r\
    \n    }\r\n    int size(int x) {\r\n        if(m_root[x] == x) { return m_size[x];\
    \ }\r\n        return size(m_root[x] = root(m_root[x]));\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/DataStructure/UnionFind.hpp
  requiredBy:
  - Library/Graph/Normal/Kruskal.hpp
  timestamp: '2023-03-07 04:44:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Graph/Normal/Kruskal.test.cpp
  - Test/DataStructure/UnionFind.test.cpp
documentation_of: Library/DataStructure/UnionFind.hpp
layout: document
redirect_from:
- /library/Library/DataStructure/UnionFind.hpp
- /library/Library/DataStructure/UnionFind.hpp.html
title: Library/DataStructure/UnionFind.hpp
---
