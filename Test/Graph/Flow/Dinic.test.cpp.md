---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Flow/Dinic.hpp
    title: Library/Graph/Flow/Dinic.hpp
  - icon: ':question:'
    path: Library/Graph/Graph.hpp
    title: Library/Graph/Graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
  bundledCode: "#line 1 \"Test/Graph/Flow/Dinic.test.cpp\"\n#define PROBLEM \\\r\n\
    \  \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\r\n\r\n\
    #line 2 \"Library/Graph/Flow/Dinic.hpp\"\n\r\n#include <list>\r\n#include <map>\r\
    \n#include <queue>\r\n#include <unordered_map>\r\n#include <unordered_set>\r\n\
    #include <vector>\r\n\r\n#line 2 \"Library/Graph/Graph.hpp\"\n#include <deque>\r\
    \n#include <iostream>\r\n#include <ranges>\r\n#include <tuple>\r\n#line 7 \"Library/Graph/Graph.hpp\"\
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
    \  }\r\n      }\r\n    }\r\n  };\r\n}  // namespace mtd\r\n#line 11 \"Library/Graph/Flow/Dinic.hpp\"\
    \nnamespace mtd {\r\n\r\n  template <class Node, class Cost>\r\n  class Dinic\
    \ {\r\n    // using Node = int;\r\n    // using Cost = int;\r\n\r\n    struct\
    \ HashPair {\r\n      template <class T1, class T2>\r\n      size_t operator()(const\
    \ std::pair<T1, T2>& p) const {\r\n        auto hash1 = std::hash<T1>{}(p.first);\r\
    \n        auto hash2 = std::hash<T2>{}(p.second);\r\n        size_t seed = 0;\r\
    \n        seed ^= hash1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);\r\n        seed\
    \ ^= hash2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);\r\n        return seed;\r\
    \n      }\r\n    };\r\n\r\n    using PairGraph = std::unordered_map<std::pair<Node,\
    \ Node>, Cost, HashPair>;\r\n\r\n    const Node m_n;\r\n    const PairGraph m_graph;\r\
    \n    const std::vector<std::unordered_set<Node>> m_to_list;\r\n\r\n    static\
    \ auto construct_to_list(const Graph<Node, Cost>& graph) {\r\n      std::vector<std::unordered_set<Node>>\
    \ to_list(graph.size());\r\n      for (const auto& [f, t, c] : graph.getEdges())\
    \ {\r\n        to_list[f].emplace(t);\r\n        to_list[t].emplace(f);\r\n  \
    \    }\r\n      return to_list;\r\n    }\r\n    static auto construct_graph(const\
    \ Graph<Node, Cost>& graph) {\r\n      PairGraph pair_graph;\r\n      for (const\
    \ auto& [f, t, c] : graph.getEdges()) {\r\n        pair_graph[std::pair<Node,\
    \ Node>{f, t}] += c;\r\n      }\r\n      return pair_graph;\r\n    }\r\n\r\n \
    \   auto get_depth(Node s, const PairGraph& graph) const {\r\n      std::vector<Node>\
    \ depth(m_n, -1);\r\n      std::queue<Node> q;\r\n      q.emplace(s);\r\n    \
    \  depth[s] = 0;\r\n      while (!q.empty()) {\r\n        auto from = q.front();\r\
    \n        q.pop();\r\n        for (const auto& to : m_to_list[from]) {\r\n   \
    \       if (graph.find({from, to}) == graph.end()) { continue; }\r\n         \
    \ if (depth[to] > -1) { continue; }\r\n          depth[to] = depth[from] + 1;\r\
    \n          q.emplace(to);\r\n        }\r\n      }\r\n      return depth;\r\n\
    \    }\r\n\r\n    auto update_residual(Node s, PairGraph& residual,\r\n      \
    \                   const std::list<Node>& route) const {\r\n      Cost mn = 1e18;\r\
    \n      auto from = s;\r\n      for (const auto& to : route)\r\n        if (from\
    \ != to) {\r\n          mn = std::min(mn, residual[{from, to}]);\r\n         \
    \ from = to;\r\n        }\r\n\r\n      from = s;\r\n      for (const auto& to\
    \ : route)\r\n        if (from != to) {\r\n          auto& ft = residual[{from,\
    \ to}];\r\n          ft -= mn;\r\n          if (ft == 0) { residual.erase({from,\
    \ to}); }\r\n          residual[{to, from}] += mn;\r\n          from = to;\r\n\
    \        }\r\n    }\r\n    auto construct_residual(Node s, Node t) const {\r\n\
    \      auto residual = m_graph;\r\n      while (true) {\r\n        // BFS\r\n\
    \        auto depth = get_depth(s, residual);\r\n\r\n        // DFS\r\n      \
    \  bool run = false;\r\n        std::vector<Node> visited(m_n);\r\n        auto\
    \ f = [&](auto&& self, Node now, std::list<Node>& route) -> void {\r\n       \
    \   route.emplace_back(now);\r\n\r\n          // t\u306B\u5230\u9054\u3057\u3066\
    \u3044\u308C\u3070\u6D41\u3059\r\n          if (now == t) {\r\n            update_residual(s,\
    \ residual, route);\r\n            run = true;\r\n          }\r\n\r\n        \
    \  for (const auto& to : m_to_list[now]) {\r\n            if (residual.find({now,\
    \ to}) == residual.end()) { continue; }\r\n            if (depth[to] <= depth[now])\
    \ { continue; }\r\n            if (visited[to]) { continue; }\r\n            visited[to]\
    \ = true;\r\n            ;\r\n            self(self, to, route);\r\n         \
    \ }\r\n          route.pop_back();\r\n        };\r\n        std::list<Node> route;\r\
    \n        visited[s] = true;\r\n        f(f, s, route);\r\n        if (!run) {\
    \ break; }\r\n      }\r\n      return residual;\r\n    }\r\n\r\n  public:\r\n\
    \    Dinic(const Graph<Node, Cost>& graph)\r\n        : m_n(graph.size()),\r\n\
    \          m_graph(construct_graph(graph)),\r\n          m_to_list(construct_to_list(graph))\
    \ {}\r\n\r\n    auto max_flow(Node s, Node t) const {\r\n      auto residual =\
    \ construct_residual(s, t);\r\n\r\n      Cost val = 0;\r\n      for (const auto&\
    \ to : m_to_list[s]) {\r\n        if (m_graph.find({s, to}) == m_graph.end())\
    \ { continue; }\r\n        val += m_graph.at({s, to}) - residual[{s, to}];\r\n\
    \      }\r\n      return val;\r\n    }\r\n\r\n    auto get_cut_list(Node s, Node\
    \ t) const {\r\n      // \u6B8B\u4F59\u30B0\u30E9\u30D5\u3067\u59CB\u70B9\u304B\
    \u3089\u5230\u9054\u3067\u304D\u308B\u96C6\u5408\r\n      std::unordered_set<Node>\
    \ st;\r\n\r\n      auto residual = construct_residual(s, t);\r\n      std::queue<Node>\
    \ q;\r\n      auto add = [&](Node to) {\r\n        if (st.find(to) != st.end())\
    \ { return; }\r\n        q.emplace(to);\r\n        st.emplace(to);\r\n      };\r\
    \n      add(s);\r\n      std::deque<Node> ans;\r\n      while (!q.empty()) {\r\
    \n        auto from = q.front();\r\n        q.pop();\r\n        for (const auto&\
    \ to : m_to_list[from]) {\r\n          if (residual.find({from, to}) == residual.end())\
    \ { continue; }\r\n          add(to);\r\n        }\r\n      }\r\n\r\n      std::deque<std::pair<Node,\
    \ Node>> cut;\r\n      for (const auto& from : st)\r\n        for (const auto&\
    \ to : m_to_list[from]) {\r\n          if (st.find(to) == st.end() &&\r\n    \
    \          m_graph.find({from, to}) != m_graph.end()) {\r\n            cut.emplace_back(from,\
    \ to);\r\n          }\r\n        }\r\n\r\n      return cut;\r\n    }\r\n\r\n \
    \   auto get_edge(Node s, Node t) const {\r\n      auto residual = construct_residual(s,\
    \ t);\r\n\r\n      auto edge = Graph<Node, Cost>(m_n);\r\n      for (Node from\
    \ = 0; from < m_n; ++from) {\r\n        for (const auto& to : m_to_list[from])\
    \ {\r\n          if (m_graph.find({from, to}) == m_graph.end()) { continue; }\r\
    \n          auto val = m_graph.at({from, to}) - residual[{from, to}];\r\n    \
    \      if (val > 0) { edge.addEdge(from, to, val); }\r\n        }\r\n      }\r\
    \n      return edge;\r\n    }\r\n  };\r\n}  // namespace mtd\r\n#line 5 \"Test/Graph/Flow/Dinic.test.cpp\"\
    \n\r\n#line 7 \"Test/Graph/Flow/Dinic.test.cpp\"\n\r\n#line 9 \"Test/Graph/Flow/Dinic.test.cpp\"\
    \n\r\nusing ll = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr\
    \ char endl = '\\n';\r\n\r\nsigned main() {\r\n  int n, m;\r\n  cin >> n >> m;\r\
    \n  auto graph = mtd::Graph(n);\r\n  for (int i = 0; i < m; ++i) {\r\n    int\
    \ u, v, c;\r\n    cin >> u >> v >> c;\r\n    graph.addArc(u, v, c);\r\n  }\r\n\
    \r\n  auto mf = mtd::Dinic(graph);\r\n\r\n  cout << mf.max_flow(0, n - 1) << endl;\r\
    \n}\r\n"
  code: "#define PROBLEM \\\r\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\
    \r\n\r\n#include \"./../../../Library/Graph/Flow/Dinic.hpp\"\r\n\r\n#include <iostream>\r\
    \n\r\n#include \"./../../../Library/Graph/Graph.hpp\"\r\n\r\nusing ll = long long;\r\
    \nusing std::cin;\r\nusing std::cout;\r\nconstexpr char endl = '\\n';\r\n\r\n\
    signed main() {\r\n  int n, m;\r\n  cin >> n >> m;\r\n  auto graph = mtd::Graph(n);\r\
    \n  for (int i = 0; i < m; ++i) {\r\n    int u, v, c;\r\n    cin >> u >> v >>\
    \ c;\r\n    graph.addArc(u, v, c);\r\n  }\r\n\r\n  auto mf = mtd::Dinic(graph);\r\
    \n\r\n  cout << mf.max_flow(0, n - 1) << endl;\r\n}\r\n"
  dependsOn:
  - Library/Graph/Flow/Dinic.hpp
  - Library/Graph/Graph.hpp
  isVerificationFile: true
  path: Test/Graph/Flow/Dinic.test.cpp
  requiredBy: []
  timestamp: '2025-06-09 16:27:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Graph/Flow/Dinic.test.cpp
layout: document
redirect_from:
- /verify/Test/Graph/Flow/Dinic.test.cpp
- /verify/Test/Graph/Flow/Dinic.test.cpp.html
title: Test/Graph/Flow/Dinic.test.cpp
---
