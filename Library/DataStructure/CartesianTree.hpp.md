---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/CartesianTree.test.cpp
    title: Test/DataStructure/CartesianTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/DataStructure/CartesianTree.hpp\"\n\r\n#include\
    \ <vector>\r\n#include <stack>\r\n\r\nclass CartesianTree {\r\n    using T = int;\r\
    \n\r\n    const int m_n;\r\n    const std::vector<int> m_par;\r\n\r\n    static\
    \ auto constructTree(const std::vector<T>& a) {\r\n        int n = (int)a.size();\r\
    \n        std::vector<int> par(n, -1);\r\n        std::stack<int> stk;\r\n   \
    \     for(int i = 0; i < n; i++) {\r\n            int prv = -1;\r\n          \
    \  while(!stk.empty() && a[i] < a[stk.top()]) {\r\n                prv = stk.top();\r\
    \n                stk.pop();\r\n            }\r\n            if(prv != -1) { par[prv]\
    \ = i; }\r\n            if(!stk.empty()) { par[i] = stk.top(); }\r\n         \
    \   stk.emplace(i);\r\n        }\r\n        return par;\r\n    }\r\npublic:\r\n\
    \    CartesianTree(const std::vector<T>& a) :m_n(a.size()), m_par(constructTree(a))\
    \ {}\r\n\r\n    auto p(int f)const { return m_par[f]; }\r\n\r\n    auto getEdges()const\
    \ {\r\n        std::vector<std::pair<int, int>> edges;\r\n        edges.reserve(m_n);\r\
    \n        for(int f = 0; f < m_n; ++f) if(m_par[f] > -1) {\r\n            edges.emplace_back(f,\
    \ m_par[f]);\r\n        }\r\n        return edges;\r\n    }\r\n};\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n#include <stack>\r\n\r\nclass CartesianTree\
    \ {\r\n    using T = int;\r\n\r\n    const int m_n;\r\n    const std::vector<int>\
    \ m_par;\r\n\r\n    static auto constructTree(const std::vector<T>& a) {\r\n \
    \       int n = (int)a.size();\r\n        std::vector<int> par(n, -1);\r\n   \
    \     std::stack<int> stk;\r\n        for(int i = 0; i < n; i++) {\r\n       \
    \     int prv = -1;\r\n            while(!stk.empty() && a[i] < a[stk.top()])\
    \ {\r\n                prv = stk.top();\r\n                stk.pop();\r\n    \
    \        }\r\n            if(prv != -1) { par[prv] = i; }\r\n            if(!stk.empty())\
    \ { par[i] = stk.top(); }\r\n            stk.emplace(i);\r\n        }\r\n    \
    \    return par;\r\n    }\r\npublic:\r\n    CartesianTree(const std::vector<T>&\
    \ a) :m_n(a.size()), m_par(constructTree(a)) {}\r\n\r\n    auto p(int f)const\
    \ { return m_par[f]; }\r\n\r\n    auto getEdges()const {\r\n        std::vector<std::pair<int,\
    \ int>> edges;\r\n        edges.reserve(m_n);\r\n        for(int f = 0; f < m_n;\
    \ ++f) if(m_par[f] > -1) {\r\n            edges.emplace_back(f, m_par[f]);\r\n\
    \        }\r\n        return edges;\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: Library/DataStructure/CartesianTree.hpp
  requiredBy: []
  timestamp: '2023-09-12 20:10:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/DataStructure/CartesianTree.test.cpp
documentation_of: Library/DataStructure/CartesianTree.hpp
layout: document
redirect_from:
- /library/Library/DataStructure/CartesianTree.hpp
- /library/Library/DataStructure/CartesianTree.hpp.html
title: Library/DataStructure/CartesianTree.hpp
---
