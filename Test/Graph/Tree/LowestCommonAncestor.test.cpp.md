---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Graph/Graph.hpp
    title: Library/Graph/Graph.hpp
  - icon: ':question:'
    path: Library/Graph/Normal/BFS.hpp
    title: Library/Graph/Normal/BFS.hpp
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
    \ PROBLEM \\\r\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C\"\
    \r\n\r\n#line 2 \"Library/Graph/Tree/LowestCommonAncestor.hpp\"\n#include <cmath>\r\
    \n#include <vector>\r\n\r\n#line 2 \"Library/Graph/Graph.hpp\"\n#include <deque>\r\
    \n#include <iostream>\r\n#include <ranges>\r\n#include <tuple>\r\n#line 7 \"Library/Graph/Graph.hpp\"\
    \n\r\nnamespace mtd {\r\n  template <class Node = int, class Cost = long long>\r\
    \n  class Graph {\r\n    // using Node = int;\r\n    // using Cost = long long;\r\
    \n\r\n    using Edge = std::pair<Node, Cost>;\r\n    using Edges = std::vector<Edge>;\r\
    \n\r\n    const int m_n;\r\n    std::vector<Edges> m_graph;\r\n\r\n  public:\r\
    \n    Graph(int n) : m_n(n), m_graph(n) {}\r\n    Graph(const std::vector<Edges>&\
    \ edges)\r\n        : m_n(edges.size()), m_graph(edges) {}\r\n\r\n    auto addEdge(const\
    \ Node& f, const Node& t, const Cost& c = 1) {\r\n      m_graph[f].emplace_back(t,\
    \ c);\r\n    }\r\n    auto addEdgeUndirected(const Node& f, const Node& t, const\
    \ Cost& c = 1) {\r\n      addEdge(f, t, c);\r\n      addEdge(t, f, c);\r\n   \
    \ }\r\n    auto getEdges(const Node& from) const {\r\n      class EdgesRange {\r\
    \n        const typename Edges::const_iterator b, e;\r\n\r\n      public:\r\n\
    \        EdgesRange(const Edges& edges) : b(edges.begin()), e(edges.end()) {}\r\
    \n        auto begin() const { return b; }\r\n        auto end() const { return\
    \ e; }\r\n      };\r\n      return EdgesRange(m_graph[from]);\r\n    }\r\n   \
    \ auto getEdges() const {\r\n      std::deque<std::tuple<Node, Node, Cost>> edges;\r\
    \n      for (Node from : std::views::iota(0, m_n)) {\r\n        for (const auto&\
    \ [to, c] : getEdges(from)) {\r\n          edges.emplace_back(from, to, c);\r\n\
    \        }\r\n      }\r\n      return edges;\r\n    }\r\n    auto getEdgesExcludeCost()\
    \ const {\r\n      std::deque<std::pair<Node, Node>> edges;\r\n      for (Node\
    \ from : std::views::iota(0, m_n)) {\r\n        for (const auto& [to, _] : getEdges(from))\
    \ {\r\n          edges.emplace_back(from, to);\r\n        }\r\n      }\r\n   \
    \   return edges;\r\n    }\r\n    auto reverse() const {\r\n      auto rev = Graph<Node,\
    \ Cost>(m_n);\r\n      for (const auto& [from, to, c] : getEdges()) { rev.addEdge(to,\
    \ from, c); }\r\n      return rev;\r\n    }\r\n    auto size() const { return\
    \ m_n; };\r\n    auto debug(bool directed = false) const {\r\n      for (const\
    \ auto& [f, t, c] : getEdges()) {\r\n        if (f < t || directed) {\r\n    \
    \      std::cout << f << \" -> \" << t << \": \" << c << std::endl;\r\n      \
    \  }\r\n      }\r\n    }\r\n  };\r\n}  // namespace mtd\r\n#line 2 \"Library/Graph/Normal/BFS.hpp\"\
    \n\r\n#include <queue>\r\n#line 5 \"Library/Graph/Normal/BFS.hpp\"\n\r\n#line\
    \ 7 \"Library/Graph/Normal/BFS.hpp\"\n\r\nnamespace mtd {\r\n  template <class\
    \ Node, class Cost, class Lambda>\r\n  auto bfs(const Graph<Node, Cost>& graph,\
    \ const Node& root,\r\n           const Lambda& lambda) {\r\n    auto n = graph.size();\r\
    \n    std::vector<bool> used(n);\r\n    used[root] = true;\r\n    std::queue<Node>\
    \ q;\r\n    q.emplace(root);\r\n    while (!q.empty()) {\r\n      auto from =\
    \ q.front();\r\n      q.pop();\r\n      for (const auto& [to, cost] : graph.getEdges(from))\
    \ {\r\n        if (used[to]) { continue; }\r\n        q.emplace(to);\r\n     \
    \   used[to] = true;\r\n        lambda(from, to, cost);\r\n      }\r\n    }\r\n\
    \  }\r\n}  // namespace mtd\r\n#line 7 \"Library/Graph/Tree/LowestCommonAncestor.hpp\"\
    \n\r\nnamespace mtd {\r\n  template <class Node, class Cost>\r\n  class LowestCommonAncestor\
    \ {\r\n    const std::vector<std::vector<Node>> m_parent;\r\n    const std::vector<Node>\
    \ m_depth;\r\n\r\n    static inline auto constructParent(const Graph<Node, Cost>&\
    \ tree,\r\n                                       const Node& root) {\r\n    \
    \  auto n = tree.size();\r\n      auto size = static_cast<int>(std::log2(n) +\
    \ 1);\r\n      std::vector<std::vector<Node>> parent(n, std::vector<Node>(size,\
    \ root));\r\n      bfs(tree, root, [&](const Node& from, const Node& to, const\
    \ Cost& _) {\r\n        parent[to][0] = from;\r\n      });\r\n      for (int p2\
    \ = 1; p2 < size; ++p2)\r\n        for (int f = 0; f < n; ++f) {\r\n         \
    \ parent[f][p2] = parent[parent[f][p2 - 1]][p2 - 1];\r\n        }\r\n      return\
    \ parent;\r\n    }\r\n    static inline auto constructDepth(const Graph<Node,\
    \ Cost>& tree,\r\n                                      const Node& root) {\r\n\
    \      auto n = tree.size();\r\n      std::vector<Node> depth(n);\r\n      bfs(tree,\
    \ root, [&](const Node& from, const Node& to, const Cost& _) {\r\n        depth[to]\
    \ = depth[from] + 1;\r\n      });\r\n      return depth;\r\n    }\r\n\r\n  public:\r\
    \n    LowestCommonAncestor(const Graph<Node, Cost>& tree, const Node& root)\r\n\
    \        : m_parent(constructParent(tree, root)),\r\n          m_depth(constructDepth(tree,\
    \ root)) {}\r\n\r\n    auto lca(Node l, Node r) const {\r\n      int size = m_parent[0].size();\r\
    \n      if (m_depth[l] < m_depth[r]) { std::swap(l, r); }\r\n      for (int k\
    \ = 0; k < size; ++k) {\r\n        if (((m_depth[l] - m_depth[r]) >> k) & 1) {\
    \ l = m_parent[l][k]; }\r\n      }\r\n      if (l == r) { return l; }\r\n    \
    \  for (int k = size - 1; k >= 0; k--) {\r\n        if (m_parent[l][k] != m_parent[r][k])\
    \ {\r\n          l = m_parent[l][k];\r\n          r = m_parent[r][k];\r\n    \
    \    }\r\n      }\r\n      return m_parent[l][0];\r\n    }\r\n  };\r\n}  // namespace\
    \ mtd\r\n#line 5 \"Test/Graph/Tree/LowestCommonAncestor.test.cpp\"\n\r\n#line\
    \ 7 \"Test/Graph/Tree/LowestCommonAncestor.test.cpp\"\n\r\n#line 9 \"Test/Graph/Tree/LowestCommonAncestor.test.cpp\"\
    \n\r\nusing ll = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr\
    \ char endl = '\\n';\r\n\r\nsigned main() {\r\n  ll n;\r\n  cin >> n;\r\n  mtd::Graph\
    \ tree(n);\r\n  for (int f = 0; f < n; ++f) {\r\n    ll k;\r\n    cin >> k;\r\n\
    \    for (int _ = 0; _ < k; ++_) {\r\n      int t;\r\n      cin >> t;\r\n    \
    \  tree.addEdgeUndirected(f, t);\r\n    }\r\n  }\r\n\r\n  auto lca = mtd::LowestCommonAncestor(tree,\
    \ 0);\r\n\r\n  int q;\r\n  cin >> q;\r\n  for (int _ = 0; _ < q; ++_) {\r\n  \
    \  int u, v;\r\n    cin >> u >> v;\r\n    cout << lca.lca(u, v) << endl;\r\n \
    \ }\r\n}\r\n"
  code: "#define PROBLEM \\\r\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C\"\
    \r\n\r\n#include \"./../../../Library/Graph/Tree/LowestCommonAncestor.hpp\"\r\n\
    \r\n#include <iostream>\r\n\r\n#include \"./../../../Library/Graph/Graph.hpp\"\
    \r\n\r\nusing ll = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr\
    \ char endl = '\\n';\r\n\r\nsigned main() {\r\n  ll n;\r\n  cin >> n;\r\n  mtd::Graph\
    \ tree(n);\r\n  for (int f = 0; f < n; ++f) {\r\n    ll k;\r\n    cin >> k;\r\n\
    \    for (int _ = 0; _ < k; ++_) {\r\n      int t;\r\n      cin >> t;\r\n    \
    \  tree.addEdgeUndirected(f, t);\r\n    }\r\n  }\r\n\r\n  auto lca = mtd::LowestCommonAncestor(tree,\
    \ 0);\r\n\r\n  int q;\r\n  cin >> q;\r\n  for (int _ = 0; _ < q; ++_) {\r\n  \
    \  int u, v;\r\n    cin >> u >> v;\r\n    cout << lca.lca(u, v) << endl;\r\n \
    \ }\r\n}\r\n"
  dependsOn:
  - Library/Graph/Tree/LowestCommonAncestor.hpp
  - Library/Graph/Graph.hpp
  - Library/Graph/Normal/BFS.hpp
  isVerificationFile: true
  path: Test/Graph/Tree/LowestCommonAncestor.test.cpp
  requiredBy: []
  timestamp: '2024-12-19 18:06:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Graph/Tree/LowestCommonAncestor.test.cpp
layout: document
redirect_from:
- /verify/Test/Graph/Tree/LowestCommonAncestor.test.cpp
- /verify/Test/Graph/Tree/LowestCommonAncestor.test.cpp.html
title: Test/Graph/Tree/LowestCommonAncestor.test.cpp
---
