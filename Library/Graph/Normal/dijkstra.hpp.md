---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Graph/Graph.hpp
    title: Library/Graph/Graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/Graph/Normal/Dijkstra.test.cpp
    title: Test/Graph/Normal/Dijkstra.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Graph/Normal/dijkstra.hpp\"\n#include <queue>\n\
    #include <vector>\n\n#line 2 \"Library/Graph/Graph.hpp\"\n#include <deque>\r\n\
    #include <iostream>\r\n#include <ranges>\r\n#include <tuple>\r\n#line 7 \"Library/Graph/Graph.hpp\"\
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
    \  }\r\n      }\r\n    }\r\n  };\r\n}  // namespace mtd\r\n#line 6 \"Library/Graph/Normal/dijkstra.hpp\"\
    \n\nnamespace mtd {\n  template <class Node, class Cost>\n  auto dijkstra(const\
    \ Graph<Node, Cost>& graph, const Node& begin,\n                const Cost& lim\
    \ = 1LL << 62) {\n    std::vector<Cost> cost(graph.size(), lim);\n    cost[begin]\
    \ = 0;\n\n    using P = std::pair<Cost, Node>;\n    std::priority_queue<P, std::vector<P>,\
    \ std::greater<P>> q;\n    q.emplace(cost[begin], begin);\n    while (!q.empty())\
    \ {\n      auto [now_cost, from] = q.top();\n      q.pop();\n      if (cost[from]\
    \ < now_cost) { continue; }\n      for (const auto& [to, c] : graph.getEdges(from))\
    \ {\n        if (now_cost + c < cost[to]) {\n          cost[to] = now_cost + c;\n\
    \          q.emplace(cost[to], to);\n        }\n      }\n    }\n    return cost;\n\
    \  }\n}  // namespace mtd\n"
  code: "#pragma once\n#include <queue>\n#include <vector>\n\n#include \"../Graph.hpp\"\
    \n\nnamespace mtd {\n  template <class Node, class Cost>\n  auto dijkstra(const\
    \ Graph<Node, Cost>& graph, const Node& begin,\n                const Cost& lim\
    \ = 1LL << 62) {\n    std::vector<Cost> cost(graph.size(), lim);\n    cost[begin]\
    \ = 0;\n\n    using P = std::pair<Cost, Node>;\n    std::priority_queue<P, std::vector<P>,\
    \ std::greater<P>> q;\n    q.emplace(cost[begin], begin);\n    while (!q.empty())\
    \ {\n      auto [now_cost, from] = q.top();\n      q.pop();\n      if (cost[from]\
    \ < now_cost) { continue; }\n      for (const auto& [to, c] : graph.getEdges(from))\
    \ {\n        if (now_cost + c < cost[to]) {\n          cost[to] = now_cost + c;\n\
    \          q.emplace(cost[to], to);\n        }\n      }\n    }\n    return cost;\n\
    \  }\n}  // namespace mtd\n"
  dependsOn:
  - Library/Graph/Graph.hpp
  isVerificationFile: false
  path: Library/Graph/Normal/dijkstra.hpp
  requiredBy: []
  timestamp: '2025-06-09 16:27:38+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Test/Graph/Normal/Dijkstra.test.cpp
documentation_of: Library/Graph/Normal/dijkstra.hpp
layout: document
redirect_from:
- /library/Library/Graph/Normal/dijkstra.hpp
- /library/Library/Graph/Normal/dijkstra.hpp.html
title: Library/Graph/Normal/dijkstra.hpp
---
