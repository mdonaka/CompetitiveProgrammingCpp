---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Tree/LowestCommonAncestor.hpp
    title: Library/Graph/Tree/LowestCommonAncestor.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C
  bundledCode: "#line 1 \"Test/Graph/Tree/LowestCommonAncestor.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C\"\
    \r\n\r\n#include <iostream>\r\n#line 2 \"Library/Graph/Tree/LowestCommonAncestor.hpp\"\
    \n#include <vector>\r\n#include <queue>\r\n#include <cmath>\r\n#include <unordered_map>\r\
    \n\r\n\r\nclass LowestCommonAncestor {\r\n\tconst std::vector<std::vector<int>>\
    \ m_parent;\r\n\tconst std::vector<int> m_depth;\r\n\r\n\tauto constructParent(int\
    \ n, const std::unordered_multimap<int, int>& tree, int root) const {\r\n\t\t\
    int toSize = std::log2(n) + 1;\r\n\t\tstd::vector<std::vector<int>> parent(n,\
    \ std::vector<int>(toSize, root));\r\n\t\tstd::queue<int> q;\r\n\t\tq.emplace(root);\r\
    \n\t\tstd::vector<int> used(n);\r\n\t\tused[root] = true;\r\n\t\twhile (!q.empty())\
    \ {\r\n\t\t\tauto from = q.front();\r\n\t\t\tq.pop();\r\n\t\t\tauto range = tree.equal_range(from);\r\
    \n\t\t\tfor (auto it = range.first; it != range.second; ++it) {\r\n\t\t\t\tauto\
    \ to = it->second;\r\n\t\t\t\tif (!used[to]) {\r\n\t\t\t\t\tq.emplace(to);\r\n\
    \t\t\t\t\tused[to] = true;\r\n\t\t\t\t\tparent[to][0] = from;\r\n\t\t\t\t}\r\n\
    \t\t\t}\r\n\t\t}\r\n\t\tfor (int p2 = 1; p2 < toSize; ++p2)for (int f = 0; f <\
    \ n; ++f) {\r\n\t\t\tparent[f][p2] = parent[parent[f][p2 - 1]][p2 - 1];\r\n\t\t\
    }\r\n\t\treturn parent;\r\n\t}\r\n\tauto constructDepth(int n, const std::unordered_multimap<int,\
    \ int>& tree, int root)const {\r\n\t\tstd::vector<int> depth(n);\r\n\t\tstd::queue<int>\
    \ q;\r\n\t\tq.emplace(root);\r\n\t\tstd::vector<int> used(n);\r\n\t\tused[root]\
    \ = true;\r\n\t\twhile (!q.empty()) {\r\n\t\t\tauto from = q.front();\r\n\t\t\t\
    q.pop();\r\n\t\t\tauto range = tree.equal_range(from);\r\n\t\t\tfor (auto it =\
    \ range.first; it != range.second; ++it) {\r\n\t\t\t\tauto to = it->second;\r\n\
    \t\t\t\tif (!used[to]) {\r\n\t\t\t\t\tq.emplace(to);\r\n\t\t\t\t\tused[to] = true;\r\
    \n\t\t\t\t\tdepth[to] = depth[from] + 1;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\
    \treturn depth;\r\n\t}\r\npublic:\r\n\tLowestCommonAncestor(int n, const std::unordered_multimap<int,\
    \ int>& tree, int root) :\r\n\t\tm_parent(constructParent(n, tree, root)),\r\n\
    \t\tm_depth(constructDepth(n, tree, root)) {\r\n\t}\r\n\r\n\tauto lca(int l, int\
    \ r)const {\r\n\t\tconst int toSize = m_parent[0].size();\r\n\t\tif (m_depth[l]\
    \ < m_depth[r]) { std::swap(l, r); }\r\n\t\tfor (int k = 0; k < toSize; ++k) {\r\
    \n\t\t\tif (((m_depth[l] - m_depth[r]) >> k) & 1) {\r\n\t\t\t\tl = m_parent[l][k];\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\tif (l == r) { return l; }\r\n\t\tfor (int k = toSize\
    \ - 1; k >= 0; k--) {\r\n\t\t\tif (m_parent[l][k] != m_parent[r][k]) {\r\n\t\t\
    \t\tl = m_parent[l][k];\r\n\t\t\t\tr = m_parent[r][k];\r\n\t\t\t}\r\n\t\t}\r\n\
    \t\treturn m_parent[l][0];\r\n\t}\r\n};\n#line 5 \"Test/Graph/Tree/LowestCommonAncestor.test.cpp\"\
    \n\r\nusing ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr\
    \ char endl = '\\n';\r\n\r\nsigned main() {\r\n    ll n;\r\n    cin >> n;\r\n\
    \    std::unordered_multimap<int, int> tree;\r\n    for(int f = 0; f < n; ++f)\
    \ {\r\n        ll k;\r\n        cin >> k;\r\n        for(int _ = 0; _ < k; ++_)\
    \ {\r\n            int t;\r\n            cin >> t;\r\n            tree.emplace(f,\
    \ t);\r\n            tree.emplace(t, f);\r\n        }\r\n    }\r\n\r\n    auto\
    \ lca = LowestCommonAncestor(n, tree, 0);\r\n\r\n    int q;\r\n    cin >> q;\r\
    \n    for(int _ = 0; _ < q; ++_) {\r\n        int u, v;\r\n        cin >> u >>\
    \ v;\r\n        cout << lca.lca(u, v) << endl;\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C\"\
    \r\n\r\n#include <iostream>\r\n#include \"./../../../Library/Graph/Tree/LowestCommonAncestor.hpp\"\
    \r\n\r\nusing ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr\
    \ char endl = '\\n';\r\n\r\nsigned main() {\r\n    ll n;\r\n    cin >> n;\r\n\
    \    std::unordered_multimap<int, int> tree;\r\n    for(int f = 0; f < n; ++f)\
    \ {\r\n        ll k;\r\n        cin >> k;\r\n        for(int _ = 0; _ < k; ++_)\
    \ {\r\n            int t;\r\n            cin >> t;\r\n            tree.emplace(f,\
    \ t);\r\n            tree.emplace(t, f);\r\n        }\r\n    }\r\n\r\n    auto\
    \ lca = LowestCommonAncestor(n, tree, 0);\r\n\r\n    int q;\r\n    cin >> q;\r\
    \n    for(int _ = 0; _ < q; ++_) {\r\n        int u, v;\r\n        cin >> u >>\
    \ v;\r\n        cout << lca.lca(u, v) << endl;\r\n    }\r\n}"
  dependsOn:
  - Library/Graph/Tree/LowestCommonAncestor.hpp
  isVerificationFile: true
  path: Test/Graph/Tree/LowestCommonAncestor.test.cpp
  requiredBy: []
  timestamp: '2023-04-08 04:44:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Graph/Tree/LowestCommonAncestor.test.cpp
layout: document
redirect_from:
- /verify/Test/Graph/Tree/LowestCommonAncestor.test.cpp
- /verify/Test/Graph/Tree/LowestCommonAncestor.test.cpp.html
title: Test/Graph/Tree/LowestCommonAncestor.test.cpp
---
