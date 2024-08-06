---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/CartesianTree.hpp
    title: Library/DataStructure/CartesianTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/cartesian_tree
    links:
    - https://judge.yosupo.jp/problem/cartesian_tree
  bundledCode: "#line 1 \"Test/DataStructure/CartesianTree.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/cartesian_tree\"\r\n\r\n#line 2 \"Library/DataStructure/CartesianTree.hpp\"\
    \n\r\n#include <numeric>\r\n#include <queue>\r\n#include <stack>\r\n#include <vector>\r\
    \n\r\ntemplate <class T>\r\nclass CartesianTree {\r\n  const int m_n;\r\n  const\
    \ std::vector<int> m_par;\r\n\r\n  static auto constructTree(const std::vector<T>&\
    \ a) {\r\n    int n = (int)a.size();\r\n    std::vector<int> par(n, -1);\r\n \
    \   std::stack<int> stk;\r\n    for (int i = 0; i < n; i++) {\r\n      int prv\
    \ = -1;\r\n      while (!stk.empty() && a[i] < a[stk.top()]) {\r\n        prv\
    \ = stk.top();\r\n        stk.pop();\r\n      }\r\n      if (prv != -1) { par[prv]\
    \ = i; }\r\n      if (!stk.empty()) { par[i] = stk.top(); }\r\n      stk.emplace(i);\r\
    \n    }\r\n    return par;\r\n  }\r\n\r\npublic:\r\n  CartesianTree(const std::vector<T>&\
    \ a)\r\n      : m_n(a.size()), m_par(constructTree(a)) {}\r\n\r\n  auto p(int\
    \ f) const { return m_par[f]; }\r\n\r\n  auto range() const {\r\n    std::vector<int>\
    \ left(m_n), right(m_n);\r\n    std::iota(left.begin(), left.end(), 0);\r\n  \
    \  std::iota(right.begin(), right.end(), 0);\r\n    std::vector<int> in(m_n);\r\
    \n    for (int f = 0; f < m_n; ++f)\r\n      if (m_par[f] > -1) { ++in[m_par[f]];\
    \ }\r\n    std::queue<int> q;\r\n    for (int f = 0; f < m_n; ++f)\r\n      if\
    \ (in[f] == 0) { q.emplace(f); }\r\n    while (!q.empty()) {\r\n      auto f =\
    \ q.front();\r\n      q.pop();\r\n      if (m_par[f] == -1) { continue; }\r\n\
    \      left[m_par[f]] = std::min(left[f], left[m_par[f]]);\r\n      right[m_par[f]]\
    \ = std::max(right[f], right[m_par[f]]);\r\n      --in[m_par[f]];\r\n      if\
    \ (in[m_par[f]] == 0) { q.emplace(m_par[f]); }\r\n    }\r\n    return std::make_pair(left,\
    \ right);\r\n  }\r\n\r\n  auto getEdges() const {\r\n    std::vector<std::pair<int,\
    \ int>> edges;\r\n    edges.reserve(m_n);\r\n    for (int f = 0; f < m_n; ++f)\r\
    \n      if (m_par[f] > -1) { edges.emplace_back(f, m_par[f]); }\r\n    return\
    \ edges;\r\n  }\r\n};\n#line 4 \"Test/DataStructure/CartesianTree.test.cpp\"\n\
    \r\n#include <iostream>\r\n\r\nusing ll = long long;\r\nusing std::cin;\r\nusing\
    \ std::cout;\r\nconstexpr char endl = '\\n';\r\nstruct Preprocessing {\r\n  Preprocessing()\
    \ {\r\n    std::cin.tie(0);\r\n    std::ios::sync_with_stdio(0);\r\n  };\r\n}\
    \ _Preprocessing;\r\n\r\nsigned main() {\r\n  int n;\r\n  cin >> n;\r\n  std::vector<int>\
    \ a(n);\r\n  for (int i = 0; i < n; ++i) { cin >> a[i]; }\r\n\r\n  auto ct = CartesianTree(a);\r\
    \n  for (int f = 0; f < n; ++f) {\r\n    int p = ct.p(f);\r\n    cout << (p ==\
    \ -1 ? f : p) << (f < n - 1 ? \" \" : \"\");\r\n  }\r\n  cout << endl;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\r\n\r\n\
    #include \"./../../Library/DataStructure/CartesianTree.hpp\"\r\n\r\n#include <iostream>\r\
    \n\r\nusing ll = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr\
    \ char endl = '\\n';\r\nstruct Preprocessing {\r\n  Preprocessing() {\r\n    std::cin.tie(0);\r\
    \n    std::ios::sync_with_stdio(0);\r\n  };\r\n} _Preprocessing;\r\n\r\nsigned\
    \ main() {\r\n  int n;\r\n  cin >> n;\r\n  std::vector<int> a(n);\r\n  for (int\
    \ i = 0; i < n; ++i) { cin >> a[i]; }\r\n\r\n  auto ct = CartesianTree(a);\r\n\
    \  for (int f = 0; f < n; ++f) {\r\n    int p = ct.p(f);\r\n    cout << (p ==\
    \ -1 ? f : p) << (f < n - 1 ? \" \" : \"\");\r\n  }\r\n  cout << endl;\r\n}"
  dependsOn:
  - Library/DataStructure/CartesianTree.hpp
  isVerificationFile: true
  path: Test/DataStructure/CartesianTree.test.cpp
  requiredBy: []
  timestamp: '2024-08-06 04:18:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/DataStructure/CartesianTree.test.cpp
layout: document
redirect_from:
- /verify/Test/DataStructure/CartesianTree.test.cpp
- /verify/Test/DataStructure/CartesianTree.test.cpp.html
title: Test/DataStructure/CartesianTree.test.cpp
---
