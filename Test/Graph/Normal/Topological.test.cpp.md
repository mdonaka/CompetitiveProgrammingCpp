---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Graph.hpp
    title: Library/Graph/Graph.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Normal/StronglyConnectedComponents.hpp
    title: Library/Graph/Normal/StronglyConnectedComponents.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Normal/Topological.hpp
    title: Library/Graph/Normal/Topological.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/2780
    links:
    - https://yukicoder.me/problems/no/2780
  bundledCode: "#line 1 \"Test/Graph/Normal/Topological.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/2780\"\n#include <iostream>\n\n// begin:tag\
    \ includes\n#line 2 \"Library/Graph/Normal/StronglyConnectedComponents.hpp\"\n\
    \r\n#include <algorithm>\r\n#include <concepts>\r\n#include <ranges>\r\n#include\
    \ <set>\r\n#include <unordered_set>\r\n#include <vector>\r\n\r\n#line 2 \"Library/Graph/Graph.hpp\"\
    \n#include <deque>\r\n#line 5 \"Library/Graph/Graph.hpp\"\n#include <tuple>\r\n\
    #line 7 \"Library/Graph/Graph.hpp\"\n\r\nnamespace mtd {\r\n  template <class\
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
    \ namespace mtd\r\n#line 11 \"Library/Graph/Normal/StronglyConnectedComponents.hpp\"\
    \n\r\nnamespace mtd {\r\n  template <class Node, class Cost>\r\n  class StronglyConnectedComponents\
    \ {\r\n    struct HashPair {\r\n      template <class T1, class T2>\r\n      size_t\
    \ operator()(const std::pair<T1, T2>& p) const {\r\n        auto hash1 = std::hash<T1>{}(p.first);\r\
    \n        auto hash2 = std::hash<T2>{}(p.second);\r\n        size_t seed = 0;\r\
    \n        seed ^= hash1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);\r\n        seed\
    \ ^= hash2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);\r\n        return seed;\r\
    \n      }\r\n    };\r\n\r\n    const Graph<Node, Cost> m_graph;\r\n    const std::vector<Node>\
    \ m_group;\r\n\r\n    template <class F>\r\n    constexpr static inline auto dfs(const\
    \ Graph<Node, Cost>& graph, Node from,\r\n                                   \
    \  std::vector<bool>& is_used, const F& f)\r\n        -> void {\r\n      is_used[from]\
    \ = true;\r\n      for (const auto& [to, _] : graph.getEdges(from)) {\r\n    \
    \    if (is_used[to]) { continue; }\r\n        dfs(graph, to, is_used, f);\r\n\
    \      }\r\n      f(from);\r\n    }\r\n\r\n    constexpr static auto constructGroup(const\
    \ Graph<Node, Cost>& graph) {\r\n      int n = graph.size();\r\n      std::vector<Node>\
    \ order;\r\n      std::vector<bool> is_used(n);\r\n      for (auto from : std::views::iota(0,\
    \ n)) {\r\n        if (is_used[from]) { continue; }\r\n        dfs(graph, from,\
    \ is_used, [&](auto f) { order.emplace_back(f); });\r\n      }\r\n\r\n      int\
    \ g = 0;\r\n      std::vector<Node> group(n);\r\n      std::vector<bool> is_used2(n);\r\
    \n      auto rev = graph.reverse();\r\n      for (auto from : order | std::views::reverse)\
    \ {\r\n        if (is_used2[from]) { continue; }\r\n        dfs(rev, from, is_used2,\
    \ [&](auto f) { group[f] = g; });\r\n        ++g;\r\n      }\r\n      return group;\r\
    \n    }\r\n\r\n  public:\r\n    [[deprecated]] constexpr StronglyConnectedComponents(\r\
    \n        const Graph<Node, Cost>& graph)\r\n        : m_graph(graph), m_group(constructGroup(m_graph))\
    \ {}\r\n    // graph\u306E\u30B3\u30D4\u30FC\u30B3\u30B9\u30C8\u304C\u5927\u304D\
    \u3044\u306E\u3067\u3053\u3063\u3061\u63A8\u5968\r\n    constexpr StronglyConnectedComponents(Graph<Node,\
    \ Cost>&& graph)\r\n        : m_graph(std::move(graph)), m_group(constructGroup(m_graph))\
    \ {}\r\n\r\n    constexpr auto size() const {\r\n      return *std::max_element(m_group.begin(),\
    \ m_group.end()) + 1;\r\n    }\r\n    constexpr auto group(Node a) const { return\
    \ m_group[a]; }\r\n    constexpr auto isSameGroup(Node a, Node b) const {\r\n\
    \      return m_group[a] == m_group[b];\r\n    }\r\n    constexpr auto getGroupNodes()\
    \ const {\r\n      std::vector<std::vector<Node>> groupNodes(size());\r\n    \
    \  for (int gi = 0; gi < m_graph.size(); ++gi) {\r\n        groupNodes[m_group[gi]].emplace_back(gi);\r\
    \n      }\r\n      return groupNodes;\r\n    }\r\n    constexpr auto getGroupGraph()\
    \ const {\r\n      std::unordered_set<std::pair<Node, Node>, HashPair> st;\r\n\
    \      st.reserve(m_graph.size());\r\n      for (int f = 0; f < m_graph.size();\
    \ ++f) {\r\n        for (const auto& [t, _] : m_graph.getEdges(f)) {\r\n     \
    \     if (!isSameGroup(f, t)) { st.emplace(m_group[f], m_group[t]); }\r\n    \
    \    }\r\n      }\r\n      Graph<Node, Cost> ret(size());\r\n      for (const\
    \ auto& [f, t] : st) { ret.addArc(f, t); }\r\n      return ret;\r\n    }\r\n \
    \ };\r\n}  // namespace mtd\r\n#line 2 \"Library/Graph/Normal/Topological.hpp\"\
    \n\r\n#line 6 \"Library/Graph/Normal/Topological.hpp\"\n\r\n#line 8 \"Library/Graph/Normal/Topological.hpp\"\
    \n\r\nnamespace mtd {\r\n  template <class Node, class Cost>\r\n  auto topological_order(const\
    \ mtd::Graph<Node, Cost>& graph) {\r\n    std::vector<Node> cnt(graph.size());\r\
    \n    for (auto [_, v] : graph.getEdgesExcludeCost()) { ++cnt[v]; }\r\n\r\n  \
    \  std::deque<Node> q;\r\n    for (auto [nd, c] : cnt | std::views::enumerate)\
    \ {\r\n      if (c == 0) { q.emplace_back(nd); }\r\n    }\r\n\r\n    std::vector<Node>\
    \ order;\r\n    while (!q.empty()) {\r\n      auto nd = q.front();\r\n      q.pop_front();\r\
    \n      order.emplace_back(nd);\r\n      for (auto [v, _] : graph.getEdges(nd))\
    \ {\r\n        --cnt[v];\r\n        if (cnt[v] == 0) { q.emplace_back(v); }\r\n\
    \      }\r\n    }\r\n    return order;\r\n  }\r\n}  // namespace mtd\r\n#line\
    \ 7 \"Test/Graph/Normal/Topological.test.cpp\"\n// end:tag includes\n\nint main()\
    \ {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(0);\n\n  int n;\n  std::cin\
    \ >> n;\n  auto graph = mtd::Graph<>(n);\n  for (auto u : std::views::iota(0,\
    \ n)) {\n    int m;\n    std::cin >> m;\n    for ([[maybe_unused]] auto _ : std::views::iota(0,\
    \ m)) {\n      int v;\n      std::cin >> v;\n      graph.addArc(u, v - 1);\n \
    \   }\n  }\n\n  auto scc = mtd::StronglyConnectedComponents(std::move(graph));\n\
    \  auto scc_graph = scc.getGroupGraph();\n  auto scc_nodes = scc.getGroupNodes();\n\
    \n  int now = -1;\n  bool yes = true;\n  for (auto u : mtd::topological_order(scc_graph))\
    \ {\n    bool ex = (now == -1 ? u == scc.group(0) : false);\n    if (now > -1)\
    \ {\n      for (auto [v, _] : scc_graph.getEdges(now)) { ex |= (u == v); }\n \
    \   }\n    yes &= ex;\n    now = u;\n  }\n\n  std::cout << (yes ? \"Yes\" : \"\
    No\") << std::endl;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/2780\"\n#include <iostream>\n\
    \n// begin:tag includes\n#include \"../../../Library/Graph/Normal/StronglyConnectedComponents.hpp\"\
    \n#include \"../../../Library/Graph/Normal/Topological.hpp\"\n// end:tag includes\n\
    \nint main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(0);\n\n  int n;\n\
    \  std::cin >> n;\n  auto graph = mtd::Graph<>(n);\n  for (auto u : std::views::iota(0,\
    \ n)) {\n    int m;\n    std::cin >> m;\n    for ([[maybe_unused]] auto _ : std::views::iota(0,\
    \ m)) {\n      int v;\n      std::cin >> v;\n      graph.addArc(u, v - 1);\n \
    \   }\n  }\n\n  auto scc = mtd::StronglyConnectedComponents(std::move(graph));\n\
    \  auto scc_graph = scc.getGroupGraph();\n  auto scc_nodes = scc.getGroupNodes();\n\
    \n  int now = -1;\n  bool yes = true;\n  for (auto u : mtd::topological_order(scc_graph))\
    \ {\n    bool ex = (now == -1 ? u == scc.group(0) : false);\n    if (now > -1)\
    \ {\n      for (auto [v, _] : scc_graph.getEdges(now)) { ex |= (u == v); }\n \
    \   }\n    yes &= ex;\n    now = u;\n  }\n\n  std::cout << (yes ? \"Yes\" : \"\
    No\") << std::endl;\n}\n"
  dependsOn:
  - Library/Graph/Normal/StronglyConnectedComponents.hpp
  - Library/Graph/Graph.hpp
  - Library/Graph/Normal/Topological.hpp
  isVerificationFile: true
  path: Test/Graph/Normal/Topological.test.cpp
  requiredBy: []
  timestamp: '2025-12-20 02:07:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Graph/Normal/Topological.test.cpp
layout: document
redirect_from:
- /verify/Test/Graph/Normal/Topological.test.cpp
- /verify/Test/Graph/Normal/Topological.test.cpp.html
title: Test/Graph/Normal/Topological.test.cpp
---
