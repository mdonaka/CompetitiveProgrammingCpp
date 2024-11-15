---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Algorithms/BinarySearch.hpp
    title: Library/Algorithms/BinarySearch.hpp
  - icon: ':question:'
    path: Library/Graph/Graph.hpp
    title: Library/Graph/Graph.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Normal/BFS.hpp
    title: Library/Graph/Normal/BFS.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1473
    links:
    - https://yukicoder.me/problems/no/1473
  bundledCode: "#line 1 \"Test/Graph/Normal/BFS.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/1473\"\
    \r\n\r\n#line 2 \"Library/Graph/Normal/BFS.hpp\"\n\r\n#include <queue>\r\n#include\
    \ <vector>\r\n\r\n#line 2 \"Library/Graph/Graph.hpp\"\n#include <deque>\r\n#include\
    \ <iostream>\r\n#include <ranges>\r\n#include <tuple>\r\n#line 7 \"Library/Graph/Graph.hpp\"\
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
    \  }\r\n      }\r\n    }\r\n  };\r\n}  // namespace mtd\r\n#line 7 \"Library/Graph/Normal/BFS.hpp\"\
    \n\r\nnamespace mtd {\r\n  template <class Node, class Cost, class Lambda>\r\n\
    \  auto bfs(const Graph<Node, Cost>& graph, const Node& root,\r\n           const\
    \ Lambda& lambda) {\r\n    auto n = graph.size();\r\n    std::vector<bool> used(n);\r\
    \n    used[root] = true;\r\n    std::queue<Node> q;\r\n    q.emplace(root);\r\n\
    \    while (!q.empty()) {\r\n      auto from = q.front();\r\n      q.pop();\r\n\
    \      for (const auto& [to, _] : graph.getEdges(from)) {\r\n        if (used[to])\
    \ { continue; }\r\n        q.emplace(to);\r\n        used[to] = true;\r\n    \
    \    lambda(from, to);\r\n      }\r\n    }\r\n  }\r\n}  // namespace mtd\r\n#line\
    \ 4 \"Test/Graph/Normal/BFS.test.cpp\"\n\r\n#line 7 \"Test/Graph/Normal/BFS.test.cpp\"\
    \n\r\n#line 2 \"Library/Algorithms/BinarySearch.hpp\"\n\r\n#include <numeric>\r\
    \n#line 5 \"Library/Algorithms/BinarySearch.hpp\"\n\r\nnamespace mtd {\r\n\r\n\
    \  template <class Lambda>\r\n  auto binarySearch(double ok, double ng, int rep,\
    \ const Lambda& is_ok) {\r\n    for ([[maybe_unused]] auto _ : std::views::iota(0,\
    \ rep)) {\r\n      double mid = (ok + ng) / 2.0;\r\n      (is_ok(mid) ? ok : ng)\
    \ = mid;\r\n    }\r\n    return ok;\r\n  }\r\n\r\n  template <class Lambda>\r\n\
    \  auto binarySearch(long long ok, long long ng, const Lambda& is_ok) {\r\n  \
    \  while (std::abs(ok - ng) > 1) {\r\n      long long mid = (ok + ng) >> 1;\r\n\
    \      (is_ok(mid) ? ok : ng) = mid;\r\n    }\r\n    return ok;\r\n  }\r\n\r\n\
    }  // namespace mtd\r\n#line 10 \"Test/Graph/Normal/BFS.test.cpp\"\n\r\nusing\
    \ ll = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr char endl\
    \ = '\\n';\r\n\r\nsigned main() {\r\n  ll n, m;\r\n  cin >> n >> m;\r\n  auto\
    \ graph_all = mtd::Graph(n);\r\n  for (int i = 0; i < m; ++i) {\r\n    ll s, t,\
    \ d;\r\n    cin >> s >> t >> d;\r\n    graph_all.addEdgeUndirected(s - 1, t -\
    \ 1, d);\r\n  }\r\n\r\n  auto solve = [&](ll w) {\r\n    auto graph = mtd::Graph(n);\r\
    \n    for (const auto& [s, t, d] : graph_all.getEdges()) {\r\n      if (w <= d)\
    \ { graph.addEdge(s, t); }\r\n    }\r\n\r\n    std::vector<int> dv(n);\r\n   \
    \ bfs(graph, 0, [&](ll f, ll t) { dv[t] = dv[f] + 1; });\r\n    return dv[n -\
    \ 1];\r\n  };\r\n\r\n  auto w_max = mtd::binarySearch(0, 1e9 + 1, [&](ll w) {\r\
    \n    auto d = solve(w);\r\n    return d > 0;\r\n  });\r\n\r\n  auto ans = solve(w_max);\r\
    \n  cout << w_max << \" \" << ans << endl;\r\n}\r\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1473\"\r\n\r\n#include\
    \ \"./../../../Library/Graph/Normal/BFS.hpp\"\r\n\r\n#include <iostream>\r\n#include\
    \ <vector>\r\n\r\n#include \"./../../../Library/Algorithms/BinarySearch.hpp\"\r\
    \n#include \"./../../../Library/Graph/Graph.hpp\"\r\n\r\nusing ll = long long;\r\
    \nusing std::cin;\r\nusing std::cout;\r\nconstexpr char endl = '\\n';\r\n\r\n\
    signed main() {\r\n  ll n, m;\r\n  cin >> n >> m;\r\n  auto graph_all = mtd::Graph(n);\r\
    \n  for (int i = 0; i < m; ++i) {\r\n    ll s, t, d;\r\n    cin >> s >> t >> d;\r\
    \n    graph_all.addEdgeUndirected(s - 1, t - 1, d);\r\n  }\r\n\r\n  auto solve\
    \ = [&](ll w) {\r\n    auto graph = mtd::Graph(n);\r\n    for (const auto& [s,\
    \ t, d] : graph_all.getEdges()) {\r\n      if (w <= d) { graph.addEdge(s, t);\
    \ }\r\n    }\r\n\r\n    std::vector<int> dv(n);\r\n    bfs(graph, 0, [&](ll f,\
    \ ll t) { dv[t] = dv[f] + 1; });\r\n    return dv[n - 1];\r\n  };\r\n\r\n  auto\
    \ w_max = mtd::binarySearch(0, 1e9 + 1, [&](ll w) {\r\n    auto d = solve(w);\r\
    \n    return d > 0;\r\n  });\r\n\r\n  auto ans = solve(w_max);\r\n  cout << w_max\
    \ << \" \" << ans << endl;\r\n}\r\n"
  dependsOn:
  - Library/Graph/Normal/BFS.hpp
  - Library/Graph/Graph.hpp
  - Library/Algorithms/BinarySearch.hpp
  isVerificationFile: true
  path: Test/Graph/Normal/BFS.test.cpp
  requiredBy: []
  timestamp: '2024-11-12 00:26:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Graph/Normal/BFS.test.cpp
layout: document
redirect_from:
- /verify/Test/Graph/Normal/BFS.test.cpp
- /verify/Test/Graph/Normal/BFS.test.cpp.html
title: Test/Graph/Normal/BFS.test.cpp
---
