---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Graph/Graph.hpp
    title: Library/Graph/Graph.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Normal/WarshallFloyd.hpp
    title: Library/Graph/Normal/WarshallFloyd.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
  bundledCode: "#line 1 \"Test/Graph/Normal/WarshallFloyd.test.cpp\"\n#define PROBLEM\
    \ \\\r\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \r\n\r\n#line 2 \"Library/Graph/Normal/WarshallFloyd.hpp\"\n\n#include <vector>\n\
    \n#line 2 \"Library/Graph/Graph.hpp\"\n#include <deque>\r\n#include <iostream>\r\
    \n#include <ranges>\r\n#include <tuple>\r\n#line 7 \"Library/Graph/Graph.hpp\"\
    \n\r\nnamespace mtd {\r\n  template <class Node = long long, class Cost = long\
    \ long>\r\n  class Graph {\r\n    using Edge = std::pair<Node, Cost>;\r\n    using\
    \ Edges = std::vector<Edge>;\r\n\r\n    const int m_n;\r\n    std::vector<Edges>\
    \ m_graph;\r\n\r\n  public:\r\n    Graph(int n) : m_n(n), m_graph(n) {}\r\n  \
    \  Graph(const std::vector<Edges>& edges)\r\n        : m_n(edges.size()), m_graph(edges)\
    \ {}\r\n    Graph(int n, const std::vector<std::tuple<Node, Node>>& edges,\r\n\
    \          bool is_arc = false, bool is_index1 = true)\r\n        : Graph<Node,\
    \ Cost>(n) {\r\n      for (auto [u, v] : edges) {\r\n        u -= is_index1;\r\
    \n        v -= is_index1;\r\n        if (is_arc) {\r\n          addArc(u, v);\r\
    \n        } else {\r\n          addEdge(u, v);\r\n        }\r\n      }\r\n   \
    \ }\r\n    Graph(int n, const std::vector<std::tuple<Node, Node, Cost>>& edges,\r\
    \n          bool is_arc = false, bool is_index1 = true)\r\n        : Graph<Node,\
    \ Cost>(n) {\r\n      for (auto [u, v, c] : edges) {\r\n        u -= is_index1;\r\
    \n        v -= is_index1;\r\n        if (is_arc) {\r\n          addArc(u, v, c);\r\
    \n        } else {\r\n          addEdge(u, v, c);\r\n        }\r\n      }\r\n\
    \    }\r\n\r\n    auto addEdge(const Node& f, const Node& t, const Cost& c = 1)\
    \ {\r\n      addArc(f, t, c);\r\n      addArc(t, f, c);\r\n    }\r\n    auto addArc(const\
    \ Node& f, const Node& t, const Cost& c = 1) {\r\n      m_graph[f].emplace_back(t,\
    \ c);\r\n    }\r\n    auto getEdges(const Node& from) const {\r\n      class EdgesRange\
    \ {\r\n        const typename Edges::const_iterator b, e;\r\n\r\n      public:\r\
    \n        EdgesRange(const Edges& edges) : b(edges.begin()), e(edges.end()) {}\r\
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
    \ Cost>(m_n);\r\n      for (const auto& [from, to, c] : getEdges()) { rev.addArc(to,\
    \ from, c); }\r\n      return rev;\r\n    }\r\n    auto size() const { return\
    \ m_n; };\r\n    auto debug(bool directed = false) const {\r\n      for (const\
    \ auto& [f, t, c] : getEdges()) {\r\n        if (f < t || directed) {\r\n    \
    \      std::cout << f << \" -> \" << t << \": \" << c << std::endl;\r\n      \
    \  }\r\n      }\r\n    }\r\n  };\r\n}  // namespace mtd\r\n#line 6 \"Library/Graph/Normal/WarshallFloyd.hpp\"\
    \n\nnamespace mtd {\n  template <class Node, class Cost>\n  auto warshallFloyd(int\
    \ n, const Graph<Node, Cost>& graph,\n                     const Cost& lim = 1LL\
    \ << 60) {\n    std::vector<std::vector<Cost>> cost(n, std::vector<Cost>(n, lim));\n\
    \    for (const auto& [from, to, c] : graph.getEdges()) { cost[from][to] = c;\
    \ }\n    for (int i = 0; i < n; ++i) { cost[i][i] = 0; }\n    for (int k = 0;\
    \ k < n; ++k) {\n      for (int f = 0; f < n; ++f) {\n        for (int t = 0;\
    \ t < n; ++t) {\n          cost[f][t] = std::min(cost[f][t], cost[f][k] + cost[k][t]);\n\
    \        }\n      }\n    }\n    return cost;\n  }\n}  // namespace mtd\n#line\
    \ 5 \"Test/Graph/Normal/WarshallFloyd.test.cpp\"\n\r\n#line 7 \"Test/Graph/Normal/WarshallFloyd.test.cpp\"\
    \n\r\nusing ll = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr\
    \ char endl = '\\n';\r\ntemplate <class T, class S = T>\r\nusing P = std::pair<T,\
    \ S>;\r\n\r\nsigned main() {\r\n  int n, m;\r\n  cin >> n >> m;\r\n  auto graph\
    \ = mtd::Graph(n);\r\n  for (int i = 0; i < m; ++i) {\r\n    int u, v, c;\r\n\
    \    cin >> u >> v >> c;\r\n    graph.addArc(u, v, c);\r\n  }\r\n\r\n  auto min_cost\
    \ = mtd::warshallFloyd(n, graph);\r\n\r\n  for (int k = 0; k < n; ++k)\r\n   \
    \ for (int f = 0; f < n; ++f)\r\n      for (int t = 0; t < n; ++t) {\r\n     \
    \   if (min_cost[f][t] > min_cost[f][k] + min_cost[k][t]) {\r\n          cout\
    \ << \"NEGATIVE CYCLE\" << endl;\r\n          return 0;\r\n        }\r\n     \
    \ }\r\n\r\n  for (const auto r : min_cost) {\r\n    for (auto itr = r.begin();\
    \ itr != r.end(); ++itr) {\r\n      if (*itr > 1e17) {\r\n        cout << \"INF\"\
    ;\r\n      } else {\r\n        cout << *itr;\r\n      }\r\n      if (itr != std::prev(r.end()))\
    \ { cout << \" \"; }\r\n    }\r\n    cout << endl;\r\n  }\r\n}\r\n"
  code: "#define PROBLEM \\\r\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \r\n\r\n#include \"./../../../Library/Graph/Normal/WarshallFloyd.hpp\"\r\n\r\n\
    #include <iostream>\r\n\r\nusing ll = long long;\r\nusing std::cin;\r\nusing std::cout;\r\
    \nconstexpr char endl = '\\n';\r\ntemplate <class T, class S = T>\r\nusing P =\
    \ std::pair<T, S>;\r\n\r\nsigned main() {\r\n  int n, m;\r\n  cin >> n >> m;\r\
    \n  auto graph = mtd::Graph(n);\r\n  for (int i = 0; i < m; ++i) {\r\n    int\
    \ u, v, c;\r\n    cin >> u >> v >> c;\r\n    graph.addArc(u, v, c);\r\n  }\r\n\
    \r\n  auto min_cost = mtd::warshallFloyd(n, graph);\r\n\r\n  for (int k = 0; k\
    \ < n; ++k)\r\n    for (int f = 0; f < n; ++f)\r\n      for (int t = 0; t < n;\
    \ ++t) {\r\n        if (min_cost[f][t] > min_cost[f][k] + min_cost[k][t]) {\r\n\
    \          cout << \"NEGATIVE CYCLE\" << endl;\r\n          return 0;\r\n    \
    \    }\r\n      }\r\n\r\n  for (const auto r : min_cost) {\r\n    for (auto itr\
    \ = r.begin(); itr != r.end(); ++itr) {\r\n      if (*itr > 1e17) {\r\n      \
    \  cout << \"INF\";\r\n      } else {\r\n        cout << *itr;\r\n      }\r\n\
    \      if (itr != std::prev(r.end())) { cout << \" \"; }\r\n    }\r\n    cout\
    \ << endl;\r\n  }\r\n}\r\n"
  dependsOn:
  - Library/Graph/Normal/WarshallFloyd.hpp
  - Library/Graph/Graph.hpp
  isVerificationFile: true
  path: Test/Graph/Normal/WarshallFloyd.test.cpp
  requiredBy: []
  timestamp: '2025-06-09 16:27:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Graph/Normal/WarshallFloyd.test.cpp
layout: document
redirect_from:
- /verify/Test/Graph/Normal/WarshallFloyd.test.cpp
- /verify/Test/Graph/Normal/WarshallFloyd.test.cpp.html
title: Test/Graph/Normal/WarshallFloyd.test.cpp
---
