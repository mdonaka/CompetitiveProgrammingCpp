---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Graph/Graph.hpp
    title: Library/Graph/Graph.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Normal/StronglyConnectedComponents.hpp
    title: Library/Graph/Normal/StronglyConnectedComponents.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C
  bundledCode: "#line 1 \"Test/Graph/Normal/StronglyConnectedComponents.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C\"\r\n\r\n\
    #line 2 \"Library/Graph/Normal/StronglyConnectedComponents.hpp\"\n\r\n#include\
    \ <algorithm>\r\n#include <unordered_set>\r\n#include <vector>\r\n\r\n#line 2\
    \ \"Library/Graph/Graph.hpp\"\n#include <deque>\r\n#include <iostream>\r\n#include\
    \ <ranges>\r\n#include <tuple>\r\n#line 7 \"Library/Graph/Graph.hpp\"\n\r\nnamespace\
    \ mtd {\r\n  template <class Node = int, class Cost = long long>\r\n  class Graph\
    \ {\r\n    // using Node = int;\r\n    // using Cost = long long;\r\n\r\n    using\
    \ Edge = std::pair<Node, Cost>;\r\n    using Edges = std::vector<Edge>;\r\n\r\n\
    \    const int m_n;\r\n    std::vector<Edges> m_graph;\r\n\r\n  public:\r\n  \
    \  Graph(int n) : m_n(n), m_graph(n) {}\r\n    Graph(const std::vector<Edges>&\
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
    \  }\r\n      }\r\n    }\r\n  };\r\n}  // namespace mtd\r\n#line 8 \"Library/Graph/Normal/StronglyConnectedComponents.hpp\"\
    \n\r\nnamespace mtd {\r\n  template <class Node, class Cost>\r\n  class StronglyConnectedComponents\
    \ {\r\n    struct HashPair {\r\n      template <class T1, class T2>\r\n      size_t\
    \ operator()(const std::pair<T1, T2>& p) const {\r\n        auto hash1 = std::hash<T1>{}(p.first);\r\
    \n        auto hash2 = std::hash<T2>{}(p.second);\r\n        size_t seed = 0;\r\
    \n        seed ^= hash1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);\r\n        seed\
    \ ^= hash2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);\r\n        return seed;\r\
    \n      }\r\n    };\r\n\r\n    const Graph<Node, Cost> m_graph;\r\n    const std::vector<int>\
    \ m_group;\r\n\r\n    template <class F>\r\n    static inline auto dfs(const Graph<Node,\
    \ Cost>& graph, int from,\r\n                           std::vector<bool>& is_used,\
    \ const F& f) -> void {\r\n      is_used[from] = true;\r\n      for (const auto&\
    \ [to, _] : graph.getEdges(from)) {\r\n        if (is_used[to]) { continue; }\r\
    \n        dfs(graph, to, is_used, f);\r\n      }\r\n      f(from);\r\n    }\r\n\
    \r\n    static inline auto constructGroup(const Graph<Node, Cost>& graph) {\r\n\
    \      int n = graph.size();\r\n      std::vector<int> order;\r\n      order.reserve(n);\r\
    \n      std::vector<bool> is_used(n);\r\n      for (int from = 0; from < n; ++from)\r\
    \n        if (!is_used[from]) {\r\n          dfs(graph, from, is_used, [&](int\
    \ f) { order.emplace_back(f); });\r\n        }\r\n\r\n      int g = 0;\r\n   \
    \   std::vector<int> group(n);\r\n      std::vector<bool> is_used2(n);\r\n   \
    \   auto rev = graph.reverse();\r\n      for (int i = n - 1; i >= 0; --i)\r\n\
    \        if (!is_used2[order[i]]) {\r\n          dfs(rev, order[i], is_used2,\
    \ [&](int f) { group[f] = g; });\r\n          ++g;\r\n        }\r\n      return\
    \ group;\r\n    }\r\n    auto constructGroupNodes() const {}\r\n\r\n  public:\r\
    \n    StronglyConnectedComponents(const Graph<Node, Cost>& graph)\r\n        :\
    \ m_graph(graph), m_group(constructGroup(m_graph)) {}\r\n    // graph\u306E\u30B3\
    \u30D4\u30FC\u30B3\u30B9\u30C8\u304C\u5927\u304D\u3044\u306E\u3067\u3053\u3063\
    \u3061\u63A8\u5968\r\n    StronglyConnectedComponents(Graph<Node, Cost>&& graph)\r\
    \n        : m_graph(std::move(graph)), m_group(constructGroup(m_graph)) {}\r\n\
    \r\n    auto isSameGroup(int a, int b) const { return m_group[a] == m_group[b];\
    \ }\r\n    auto getGroupNodes() const {\r\n      auto size = *std::max_element(m_group.begin(),\
    \ m_group.end()) + 1;\r\n      std::vector<std::vector<int>> groupNodes(size);\r\
    \n      for (int gi = 0; gi < m_graph.size(); ++gi) {\r\n        groupNodes[m_group[gi]].emplace_back(gi);\r\
    \n      }\r\n      return groupNodes;\r\n    }\r\n    auto getGroupGraph() const\
    \ {\r\n      std::unordered_set<std::pair<int, int>, HashPair> st;\r\n      st.reserve(m_graph.size());\r\
    \n      for (int f = 0; f < m_graph.size(); ++f)\r\n        for (const auto& [t,\
    \ _] : m_graph.getEdges(f))\r\n          if (!isSameGroup(f, t)) { st.emplace(m_group[f],\
    \ m_group[t]); }\r\n      Graph<Node, Cost> ret(m_graph.size());\r\n      for\
    \ (const auto& [f, t] : st) { ret.addEdge(f, t); }\r\n      return ret;\r\n  \
    \  }\r\n  };\r\n}  // namespace mtd\r\n#line 4 \"Test/Graph/Normal/StronglyConnectedComponents.test.cpp\"\
    \n\r\n#line 6 \"Test/Graph/Normal/StronglyConnectedComponents.test.cpp\"\n\r\n\
    #line 8 \"Test/Graph/Normal/StronglyConnectedComponents.test.cpp\"\nusing ll =\
    \ long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr char endl = '\\\
    n';\r\n\r\nsigned main() {\r\n  int n, m;\r\n  cin >> n >> m;\r\n  auto graph\
    \ = mtd::Graph(n);\r\n  for (int _ = 0; _ < m; ++_) {\r\n    int f, t;\r\n   \
    \ cin >> f >> t;\r\n    graph.addEdge(f, t);\r\n  }\r\n\r\n  auto scc = mtd::StronglyConnectedComponents(std::move(graph));\r\
    \n\r\n  int q;\r\n  cin >> q;\r\n  for (int _ = 0; _ < q; ++_) {\r\n    int u,\
    \ v;\r\n    cin >> u >> v;\r\n    cout << scc.isSameGroup(u, v) << endl;\r\n \
    \ }\r\n}\r\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C\"\r\n\
    \r\n#include \"./../../../Library/Graph/Normal/StronglyConnectedComponents.hpp\"\
    \r\n\r\n#include <iostream>\r\n\r\n#include \"./../../../Library/Graph/Graph.hpp\"\
    \r\nusing ll = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr\
    \ char endl = '\\n';\r\n\r\nsigned main() {\r\n  int n, m;\r\n  cin >> n >> m;\r\
    \n  auto graph = mtd::Graph(n);\r\n  for (int _ = 0; _ < m; ++_) {\r\n    int\
    \ f, t;\r\n    cin >> f >> t;\r\n    graph.addEdge(f, t);\r\n  }\r\n\r\n  auto\
    \ scc = mtd::StronglyConnectedComponents(std::move(graph));\r\n\r\n  int q;\r\n\
    \  cin >> q;\r\n  for (int _ = 0; _ < q; ++_) {\r\n    int u, v;\r\n    cin >>\
    \ u >> v;\r\n    cout << scc.isSameGroup(u, v) << endl;\r\n  }\r\n}\r\n"
  dependsOn:
  - Library/Graph/Normal/StronglyConnectedComponents.hpp
  - Library/Graph/Graph.hpp
  isVerificationFile: true
  path: Test/Graph/Normal/StronglyConnectedComponents.test.cpp
  requiredBy: []
  timestamp: '2024-11-12 00:26:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Graph/Normal/StronglyConnectedComponents.test.cpp
layout: document
redirect_from:
- /verify/Test/Graph/Normal/StronglyConnectedComponents.test.cpp
- /verify/Test/Graph/Normal/StronglyConnectedComponents.test.cpp.html
title: Test/Graph/Normal/StronglyConnectedComponents.test.cpp
---
