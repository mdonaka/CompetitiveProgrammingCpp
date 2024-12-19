---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Graph/Graph.hpp
    title: Library/Graph/Graph.hpp
  - icon: ':x:'
    path: Library/Graph/Tree/EulerTour.hpp
    title: Library/Graph/Tree/EulerTour.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_B
  bundledCode: "#line 1 \"Test/Graph/Tree/EulerTour.test.cpp\"\n#define PROBLEM \\\
    \r\n  \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_B\"\
    \r\n\r\n#include <iostream>\r\n\r\n// begin:tag includes\r\n#line 2 \"Library/Graph/Tree/EulerTour.hpp\"\
    \n\r\n#include <stack>\r\n#include <vector>\r\n\r\n#line 2 \"Library/Graph/Graph.hpp\"\
    \n#include <deque>\r\n#line 4 \"Library/Graph/Graph.hpp\"\n#include <ranges>\r\
    \n#include <tuple>\r\n#line 7 \"Library/Graph/Graph.hpp\"\n\r\nnamespace mtd {\r\
    \n  template <class Node = int, class Cost = long long>\r\n  class Graph {\r\n\
    \    // using Node = int;\r\n    // using Cost = long long;\r\n\r\n    using Edge\
    \ = std::pair<Node, Cost>;\r\n    using Edges = std::vector<Edge>;\r\n\r\n   \
    \ const int m_n;\r\n    std::vector<Edges> m_graph;\r\n\r\n  public:\r\n    Graph(int\
    \ n) : m_n(n), m_graph(n) {}\r\n    Graph(const std::vector<Edges>& edges)\r\n\
    \        : m_n(edges.size()), m_graph(edges) {}\r\n\r\n    auto addEdge(const\
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
    \  }\r\n      }\r\n    }\r\n  };\r\n}  // namespace mtd\r\n#line 7 \"Library/Graph/Tree/EulerTour.hpp\"\
    \n\r\nnamespace mtd {\r\n\r\n  template <class Node, class Cost>\r\n  class EulerTour\
    \ {\r\n    const std::vector<Node> m_tour;\r\n    const std::vector<std::pair<int,\
    \ int>> m_appear;\r\n\r\n    auto constructTour(const Graph<Node, Cost>& tree,\
    \ Node root) const {\r\n      auto n = tree.size();\r\n      std::vector<Node>\
    \ tour;\r\n      std::stack<Node> stk;\r\n      std::vector<int> used(n);\r\n\
    \      stk.emplace(root);\r\n      while (!stk.empty()) {\r\n        auto from\
    \ = stk.top();\r\n        tour.emplace_back(from);\r\n        stk.pop();\r\n \
    \       if (used[from]) { continue; }\r\n        stk.emplace(from);\r\n      \
    \  used[from] = true;\r\n\r\n        for (auto [to, _] : tree.getEdges(from))\
    \ {\r\n          if (!used[to]) { stk.emplace(to); }\r\n        }\r\n      }\r\
    \n      return tour;\r\n    }\r\n    auto constructAppear(int n) const {\r\n \
    \     std::vector<std::pair<int, int>> appear(n, {-1, -1});\r\n      for (int\
    \ i = 0; i < 2 * n; ++i) {\r\n        if (appear[m_tour[i]].first == -1) {\r\n\
    \          appear[m_tour[i]].first = i;\r\n        } else {\r\n          appear[m_tour[i]].second\
    \ = i;\r\n        }\r\n      }\r\n      return appear;\r\n    }\r\n\r\n  public:\r\
    \n    EulerTour(const Graph<Node, Cost>& tree, Node root = 0)\r\n        : m_tour(constructTour(tree,\
    \ root)),\r\n          m_appear(constructAppear(tree.size())) {}\r\n\r\n    auto\
    \ lessOrder(int li, int ri) const {\r\n      return m_appear[li].first < m_appear[ri].first;\r\
    \n    }\r\n    auto isSon(Node son, Node parent) {\r\n      return m_appear[parent].first\
    \ < m_appear[son].first &&\r\n             m_appear[son].second < m_appear[parent].second;\r\
    \n    }\r\n    auto range(Node u) const { return m_appear[u]; }\r\n  };\r\n} \
    \ // namespace mtd\r\n#line 8 \"Test/Graph/Tree/EulerTour.test.cpp\"\n// end:tag\
    \ includes\r\n\r\nsigned main() {\r\n  std::cin.tie(0);\r\n  std::ios::sync_with_stdio(0);\r\
    \n\r\n  int n;\r\n  std::cin >> n;\r\n  auto tree = mtd::Graph<>(n);\r\n  for\
    \ ([[maybe_unused]] auto _ : std::views::iota(0, n)) {\r\n    int u, k;\r\n  \
    \  std::cin >> u >> k;\r\n    for ([[maybe_unused]] auto __ : std::views::iota(0,\
    \ k)) {\r\n      int v;\r\n      std::cin >> v;\r\n      tree.addEdgeUndirected(u\
    \ - 1, v - 1);\r\n    }\r\n  }\r\n\r\n  auto et = mtd::EulerTour(tree);\r\n  for\
    \ (auto i : std::views::iota(0, n)) {\r\n    auto [d, f] = et.range(i);\r\n  \
    \  std::cout << i + 1 << \" \" << d + 1 << \" \" << f + 1 << std::endl;\r\n  }\r\
    \n}\r\n"
  code: "#define PROBLEM \\\r\n  \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_B\"\
    \r\n\r\n#include <iostream>\r\n\r\n// begin:tag includes\r\n#include \"./../../../Library/Graph/Tree/EulerTour.hpp\"\
    \r\n// end:tag includes\r\n\r\nsigned main() {\r\n  std::cin.tie(0);\r\n  std::ios::sync_with_stdio(0);\r\
    \n\r\n  int n;\r\n  std::cin >> n;\r\n  auto tree = mtd::Graph<>(n);\r\n  for\
    \ ([[maybe_unused]] auto _ : std::views::iota(0, n)) {\r\n    int u, k;\r\n  \
    \  std::cin >> u >> k;\r\n    for ([[maybe_unused]] auto __ : std::views::iota(0,\
    \ k)) {\r\n      int v;\r\n      std::cin >> v;\r\n      tree.addEdgeUndirected(u\
    \ - 1, v - 1);\r\n    }\r\n  }\r\n\r\n  auto et = mtd::EulerTour(tree);\r\n  for\
    \ (auto i : std::views::iota(0, n)) {\r\n    auto [d, f] = et.range(i);\r\n  \
    \  std::cout << i + 1 << \" \" << d + 1 << \" \" << f + 1 << std::endl;\r\n  }\r\
    \n}\r\n"
  dependsOn:
  - Library/Graph/Tree/EulerTour.hpp
  - Library/Graph/Graph.hpp
  isVerificationFile: true
  path: Test/Graph/Tree/EulerTour.test.cpp
  requiredBy: []
  timestamp: '2024-12-20 01:44:46+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/Graph/Tree/EulerTour.test.cpp
layout: document
redirect_from:
- /verify/Test/Graph/Tree/EulerTour.test.cpp
- /verify/Test/Graph/Tree/EulerTour.test.cpp.html
title: Test/Graph/Tree/EulerTour.test.cpp
---
