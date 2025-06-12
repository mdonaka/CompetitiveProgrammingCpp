---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Graph/Graph.hpp
    title: Library/Graph/Graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/Graph/Normal/StronglyConnectedComponents.test.cpp
    title: Test/Graph/Normal/StronglyConnectedComponents.test.cpp
  - icon: ':x:'
    path: Test/Graph/Normal/Topological.test.cpp
    title: Test/Graph/Normal/Topological.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Graph/Normal/StronglyConnectedComponents.hpp\"\n\
    \r\n#include <algorithm>\r\n#include <ranges>\r\n#include <set>\r\n#include <unordered_set>\r\
    \n#include <vector>\r\n\r\n#line 2 \"Library/Graph/Graph.hpp\"\n#include <deque>\r\
    \n#include <iostream>\r\n#line 5 \"Library/Graph/Graph.hpp\"\n#include <tuple>\r\
    \n#line 7 \"Library/Graph/Graph.hpp\"\n\r\nnamespace mtd {\r\n  template <class\
    \ Node = long long, class Cost = long long>\r\n  class Graph {\r\n    using Edge\
    \ = std::pair<Node, Cost>;\r\n    using Edges = std::vector<Edge>;\r\n\r\n   \
    \ const int m_n;\r\n    std::vector<Edges> m_graph;\r\n\r\n  public:\r\n    Graph(int\
    \ n) : m_n(n), m_graph(n) {}\r\n    Graph(const std::vector<Edges>& edges)\r\n\
    \        : m_n(edges.size()), m_graph(edges) {}\r\n    Graph(int n, const std::vector<std::tuple<Node,\
    \ Node>>& edges,\r\n          bool is_arc = false, bool is_index1 = true)\r\n\
    \        : Graph<Node, Cost>(n) {\r\n      for (auto [u, v] : edges) {\r\n   \
    \     u -= is_index1;\r\n        v -= is_index1;\r\n        if (is_arc) {\r\n\
    \          addArc(u, v);\r\n        } else {\r\n          addEdge(u, v);\r\n \
    \       }\r\n      }\r\n    }\r\n    Graph(int n, const std::vector<std::tuple<Node,\
    \ Node, Cost>>& edges,\r\n          bool is_arc = false, bool is_index1 = true)\r\
    \n        : Graph<Node, Cost>(n) {\r\n      for (auto [u, v, c] : edges) {\r\n\
    \        u -= is_index1;\r\n        v -= is_index1;\r\n        if (is_arc) {\r\
    \n          addArc(u, v, c);\r\n        } else {\r\n          addEdge(u, v, c);\r\
    \n        }\r\n      }\r\n    }\r\n\r\n    auto addEdge(const Node& f, const Node&\
    \ t, const Cost& c = 1) {\r\n      addArc(f, t, c);\r\n      addArc(t, f, c);\r\
    \n    }\r\n    auto addArc(const Node& f, const Node& t, const Cost& c = 1) {\r\
    \n      m_graph[f].emplace_back(t, c);\r\n    }\r\n    auto getEdges(const Node&\
    \ from) const {\r\n      class EdgesRange {\r\n        const typename Edges::const_iterator\
    \ b, e;\r\n\r\n      public:\r\n        EdgesRange(const Edges& edges) : b(edges.begin()),\
    \ e(edges.end()) {}\r\n        auto begin() const { return b; }\r\n        auto\
    \ end() const { return e; }\r\n      };\r\n      return EdgesRange(m_graph[from]);\r\
    \n    }\r\n    auto getEdges() const {\r\n      std::deque<std::tuple<Node, Node,\
    \ Cost>> edges;\r\n      for (Node from : std::views::iota(0, m_n)) {\r\n    \
    \    for (const auto& [to, c] : getEdges(from)) {\r\n          edges.emplace_back(from,\
    \ to, c);\r\n        }\r\n      }\r\n      return edges;\r\n    }\r\n    auto\
    \ getEdgesExcludeCost() const {\r\n      std::deque<std::pair<Node, Node>> edges;\r\
    \n      for (Node from : std::views::iota(0, m_n)) {\r\n        for (const auto&\
    \ [to, _] : getEdges(from)) {\r\n          edges.emplace_back(from, to);\r\n \
    \       }\r\n      }\r\n      return edges;\r\n    }\r\n    auto reverse() const\
    \ {\r\n      auto rev = Graph<Node, Cost>(m_n);\r\n      for (const auto& [from,\
    \ to, c] : getEdges()) { rev.addArc(to, from, c); }\r\n      return rev;\r\n \
    \   }\r\n    auto size() const { return m_n; };\r\n    auto debug(bool directed\
    \ = false) const {\r\n      for (const auto& [f, t, c] : getEdges()) {\r\n   \
    \     if (f < t || directed) {\r\n          std::cout << f << \" -> \" << t <<\
    \ \": \" << c << std::endl;\r\n        }\r\n      }\r\n    }\r\n  };\r\n}  //\
    \ namespace mtd\r\n#line 10 \"Library/Graph/Normal/StronglyConnectedComponents.hpp\"\
    \n\r\nnamespace mtd {\r\n  template <class Node, class Cost>\r\n  class StronglyConnectedComponents\
    \ {\r\n    struct HashPair {\r\n      template <class T1, class T2>\r\n      size_t\
    \ operator()(const std::pair<T1, T2>& p) const {\r\n        auto hash1 = std::hash<T1>{}(p.first);\r\
    \n        auto hash2 = std::hash<T2>{}(p.second);\r\n        size_t seed = 0;\r\
    \n        seed ^= hash1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);\r\n        seed\
    \ ^= hash2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);\r\n        return seed;\r\
    \n      }\r\n    };\r\n\r\n    const Graph<Node, Cost> m_graph;\r\n    const std::vector<int>\
    \ m_group;\r\n\r\n    template <class F>\r\n    constexpr static inline auto dfs(const\
    \ Graph<Node, Cost>& graph, int from,\r\n                                    \
    \ std::vector<bool>& is_used, const F& f)\r\n        -> void {\r\n      is_used[from]\
    \ = true;\r\n      for (const auto& [to, _] : graph.getEdges(from)) {\r\n    \
    \    if (is_used[to]) { continue; }\r\n        dfs(graph, to, is_used, f);\r\n\
    \      }\r\n      f(from);\r\n    }\r\n\r\n    constexpr static auto constructGroup(const\
    \ Graph<Node, Cost>& graph) {\r\n      int n = graph.size();\r\n      std::vector<Node>\
    \ order;\r\n      std::vector<bool> is_used(n);\r\n      for (auto from : std::views::iota(0,\
    \ n)) {\r\n        if (is_used[from]) { continue; }\r\n        dfs(graph, from,\
    \ is_used, [&](int f) { order.emplace_back(f); });\r\n      }\r\n\r\n      int\
    \ g = 0;\r\n      std::vector<Node> group(n);\r\n      std::vector<bool> is_used2(n);\r\
    \n      auto rev = graph.reverse();\r\n      for (auto from : order | std::views::reverse)\
    \ {\r\n        if (is_used2[from]) { continue; }\r\n        dfs(rev, from, is_used2,\
    \ [&](int f) { group[f] = g; });\r\n        ++g;\r\n      }\r\n      return group;\r\
    \n    }\r\n\r\n  public:\r\n    [[deprecated]] constexpr StronglyConnectedComponents(\r\
    \n        const Graph<Node, Cost>& graph)\r\n        : m_graph(graph), m_group(constructGroup(m_graph))\
    \ {}\r\n    // graph\u306E\u30B3\u30D4\u30FC\u30B3\u30B9\u30C8\u304C\u5927\u304D\
    \u3044\u306E\u3067\u3053\u3063\u3061\u63A8\u5968\r\n    constexpr StronglyConnectedComponents(Graph<Node,\
    \ Cost>&& graph)\r\n        : m_graph(std::move(graph)), m_group(constructGroup(m_graph))\
    \ {}\r\n\r\n    constexpr auto size() const {\r\n      return *std::max_element(m_group.begin(),\
    \ m_group.end()) + 1;\r\n    }\r\n    constexpr auto group(int a) const { return\
    \ m_group[a]; }\r\n    constexpr auto isSameGroup(int a, int b) const {\r\n  \
    \    return m_group[a] == m_group[b];\r\n    }\r\n    constexpr auto getGroupNodes()\
    \ const {\r\n      std::vector<std::vector<int>> groupNodes(size());\r\n     \
    \ for (int gi = 0; gi < m_graph.size(); ++gi) {\r\n        groupNodes[m_group[gi]].emplace_back(gi);\r\
    \n      }\r\n      return groupNodes;\r\n    }\r\n    constexpr auto getGroupGraph()\
    \ const {\r\n      std::unordered_set<std::pair<int, int>, HashPair> st;\r\n \
    \     st.reserve(m_graph.size());\r\n      for (int f = 0; f < m_graph.size();\
    \ ++f) {\r\n        for (const auto& [t, _] : m_graph.getEdges(f)) {\r\n     \
    \     if (!isSameGroup(f, t)) { st.emplace(m_group[f], m_group[t]); }\r\n    \
    \    }\r\n      }\r\n      Graph<Node, Cost> ret(size());\r\n      for (const\
    \ auto& [f, t] : st) { ret.addEdge(f, t); }\r\n      return ret;\r\n    }\r\n\
    \  };\r\n}  // namespace mtd\r\n"
  code: "#pragma once\r\n\r\n#include <algorithm>\r\n#include <ranges>\r\n#include\
    \ <set>\r\n#include <unordered_set>\r\n#include <vector>\r\n\r\n#include \"./../Graph.hpp\"\
    \r\n\r\nnamespace mtd {\r\n  template <class Node, class Cost>\r\n  class StronglyConnectedComponents\
    \ {\r\n    struct HashPair {\r\n      template <class T1, class T2>\r\n      size_t\
    \ operator()(const std::pair<T1, T2>& p) const {\r\n        auto hash1 = std::hash<T1>{}(p.first);\r\
    \n        auto hash2 = std::hash<T2>{}(p.second);\r\n        size_t seed = 0;\r\
    \n        seed ^= hash1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);\r\n        seed\
    \ ^= hash2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);\r\n        return seed;\r\
    \n      }\r\n    };\r\n\r\n    const Graph<Node, Cost> m_graph;\r\n    const std::vector<int>\
    \ m_group;\r\n\r\n    template <class F>\r\n    constexpr static inline auto dfs(const\
    \ Graph<Node, Cost>& graph, int from,\r\n                                    \
    \ std::vector<bool>& is_used, const F& f)\r\n        -> void {\r\n      is_used[from]\
    \ = true;\r\n      for (const auto& [to, _] : graph.getEdges(from)) {\r\n    \
    \    if (is_used[to]) { continue; }\r\n        dfs(graph, to, is_used, f);\r\n\
    \      }\r\n      f(from);\r\n    }\r\n\r\n    constexpr static auto constructGroup(const\
    \ Graph<Node, Cost>& graph) {\r\n      int n = graph.size();\r\n      std::vector<Node>\
    \ order;\r\n      std::vector<bool> is_used(n);\r\n      for (auto from : std::views::iota(0,\
    \ n)) {\r\n        if (is_used[from]) { continue; }\r\n        dfs(graph, from,\
    \ is_used, [&](int f) { order.emplace_back(f); });\r\n      }\r\n\r\n      int\
    \ g = 0;\r\n      std::vector<Node> group(n);\r\n      std::vector<bool> is_used2(n);\r\
    \n      auto rev = graph.reverse();\r\n      for (auto from : order | std::views::reverse)\
    \ {\r\n        if (is_used2[from]) { continue; }\r\n        dfs(rev, from, is_used2,\
    \ [&](int f) { group[f] = g; });\r\n        ++g;\r\n      }\r\n      return group;\r\
    \n    }\r\n\r\n  public:\r\n    [[deprecated]] constexpr StronglyConnectedComponents(\r\
    \n        const Graph<Node, Cost>& graph)\r\n        : m_graph(graph), m_group(constructGroup(m_graph))\
    \ {}\r\n    // graph\u306E\u30B3\u30D4\u30FC\u30B3\u30B9\u30C8\u304C\u5927\u304D\
    \u3044\u306E\u3067\u3053\u3063\u3061\u63A8\u5968\r\n    constexpr StronglyConnectedComponents(Graph<Node,\
    \ Cost>&& graph)\r\n        : m_graph(std::move(graph)), m_group(constructGroup(m_graph))\
    \ {}\r\n\r\n    constexpr auto size() const {\r\n      return *std::max_element(m_group.begin(),\
    \ m_group.end()) + 1;\r\n    }\r\n    constexpr auto group(int a) const { return\
    \ m_group[a]; }\r\n    constexpr auto isSameGroup(int a, int b) const {\r\n  \
    \    return m_group[a] == m_group[b];\r\n    }\r\n    constexpr auto getGroupNodes()\
    \ const {\r\n      std::vector<std::vector<int>> groupNodes(size());\r\n     \
    \ for (int gi = 0; gi < m_graph.size(); ++gi) {\r\n        groupNodes[m_group[gi]].emplace_back(gi);\r\
    \n      }\r\n      return groupNodes;\r\n    }\r\n    constexpr auto getGroupGraph()\
    \ const {\r\n      std::unordered_set<std::pair<int, int>, HashPair> st;\r\n \
    \     st.reserve(m_graph.size());\r\n      for (int f = 0; f < m_graph.size();\
    \ ++f) {\r\n        for (const auto& [t, _] : m_graph.getEdges(f)) {\r\n     \
    \     if (!isSameGroup(f, t)) { st.emplace(m_group[f], m_group[t]); }\r\n    \
    \    }\r\n      }\r\n      Graph<Node, Cost> ret(size());\r\n      for (const\
    \ auto& [f, t] : st) { ret.addEdge(f, t); }\r\n      return ret;\r\n    }\r\n\
    \  };\r\n}  // namespace mtd\r\n"
  dependsOn:
  - Library/Graph/Graph.hpp
  isVerificationFile: false
  path: Library/Graph/Normal/StronglyConnectedComponents.hpp
  requiredBy: []
  timestamp: '2025-06-09 16:27:38+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Test/Graph/Normal/Topological.test.cpp
  - Test/Graph/Normal/StronglyConnectedComponents.test.cpp
documentation_of: Library/Graph/Normal/StronglyConnectedComponents.hpp
layout: document
redirect_from:
- /library/Library/Graph/Normal/StronglyConnectedComponents.hpp
- /library/Library/Graph/Normal/StronglyConnectedComponents.hpp.html
title: Library/Graph/Normal/StronglyConnectedComponents.hpp
---
