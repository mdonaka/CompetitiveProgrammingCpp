---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Flow/SuccessiveShortestPath.hpp
    title: Library/Graph/Flow/SuccessiveShortestPath.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Graph.hpp
    title: Library/Graph/Graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B
  bundledCode: "#line 1 \"Test/Graph/Flow/SuccessiveShortestPath.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B\"\
    \r\n\r\n#include <iostream>\r\n#line 2 \"Library/Graph/Graph.hpp\"\n#include <vector>\r\
    \n#include <deque>\r\n#include <tuple>\r\n\r\ntemplate<class Node = int, class\
    \ Cost = long long>\r\nclass Graph {\r\n    //using Node = int;\r\n    //using\
    \ Cost = long long;\r\n\r\n    using Edge = std::pair<Node, Cost>;\r\n    using\
    \ Edges = std::vector<Edge>;\r\n\r\n    const int m_n;\r\n    std::vector<Edges>\
    \ m_graph;\r\n\r\npublic:\r\n    Graph(int n) :m_n(n), m_graph(n) {}\r\n\r\n \
    \   auto addEdge(const Node& f, const Node& t, const Cost& c = 1) {\r\n      \
    \  m_graph[f].emplace_back(t, c);\r\n    }\r\n    auto addEdgeUndirected(const\
    \ Node& f, const Node& t, const Cost& c = 1) {\r\n        addEdge(f, t, c); addEdge(t,\
    \ f, c);\r\n    }\r\n    auto getEdges(const Node& from)const {\r\n        class\
    \ EdgesRange {\r\n            const typename Edges::const_iterator b, e;\r\n \
    \       public:\r\n            EdgesRange(const Edges& edges) :b(edges.begin()),\
    \ e(edges.end()) {}\r\n            auto begin()const { return b; }\r\n       \
    \     auto end()const { return e; }\r\n        };\r\n        return EdgesRange(m_graph[from]);\r\
    \n    }\r\n    auto getEdges()const {\r\n        std::deque<std::tuple<Node, Node,\
    \ Cost>> edges;\r\n        for(Node from = 0; from < m_n; ++from) for(const auto&\
    \ [to, c] : getEdges(from)) {\r\n            edges.emplace_back(from, to, c);\r\
    \n        }\r\n        return edges;\r\n    }\r\n    auto getEdgesExcludeCost()const\
    \ {\r\n        std::deque<std::pair<Node, Node>> edges;\r\n        for(Node from\
    \ = 0; from < m_n; ++from) for(const auto& [to, _] : getEdges(from)) {\r\n   \
    \         edges.emplace_back(from, to);\r\n        }\r\n        return edges;\r\
    \n    }\r\n    auto reverse()const {\r\n        auto rev = Graph<Node, Cost>(m_n);\r\
    \n        for(const auto& [from, to, c] : getEdges()) {\r\n            rev.addEdge(to,\
    \ from, c);\r\n        }\r\n        return rev;\r\n    }\r\n    auto size()const\
    \ { return m_n; };\r\n    auto debug(bool directed = false)const {\r\n       \
    \ for(const auto& [f, t, c] : getEdges())if(f < t || directed) {\r\n         \
    \   std::cout << f << \" -> \" << t << \": \" << c << std::endl;\r\n        }\r\
    \n    }\r\n};\n#line 2 \"Library/Graph/Flow/SuccessiveShortestPath.hpp\"\n\r\n\
    #line 6 \"Library/Graph/Flow/SuccessiveShortestPath.hpp\"\n#include <queue>\r\n\
    #include <unordered_map>\r\n#include <unordered_set>\r\n#include <map>\r\n\r\n\
    #line 12 \"Library/Graph/Flow/SuccessiveShortestPath.hpp\"\n\r\ntemplate<class\
    \ Node, class Cap, class Cost>\r\nclass SuccessiveShortestPath {\r\n    //using\
    \ Node = int;\r\n    //using Cap = int;\r\n    //using Cost = int;\r\n\r\n   \
    \ using GraphCap = std::vector<std::vector<Cap>>;\r\n    using GraphCost = std::vector<std::vector<Cost>>;\r\
    \n\r\n    const Graph<Node, std::pair<Cap, Cost>> m_graph;\r\n    const Graph<Node,\
    \ bool> m_graph_undirected;\r\n\r\n\r\n    auto construct_graph_undirected()const\
    \ {\r\n        auto graph_undirected = Graph<Node, bool>(m_graph.size());\r\n\
    \        for(const auto& [f, t] : m_graph.getEdgesExcludeCost()) {\r\n       \
    \     graph_undirected.addEdgeUndirected(f, t);\r\n        }\r\n        return\
    \ graph_undirected;\r\n    }\r\n\r\n    auto construct_graph_cap()const {\r\n\
    \        auto n = m_graph.size();\r\n        GraphCap graph_cap(n, std::vector<Cap>(n));\r\
    \n        for(const auto& [f, t, cc] : m_graph.getEdges()) {\r\n            auto\
    \ [cap, _] = cc;\r\n            graph_cap[f][t] += cap;\r\n        }\r\n     \
    \   return graph_cap;\r\n    }\r\n    auto construct_graph_cost() const {\r\n\
    \        auto n = m_graph.size();\r\n        GraphCost graph_cost(n, std::vector<Cost>(n));\r\
    \n        for(const auto& [f, t, cc] : m_graph.getEdges()) {\r\n            auto\
    \ [_, cost] = cc;\r\n            graph_cost[f][t] = cost;\r\n            graph_cost[t][f]\
    \ = -cost;\r\n        }\r\n        return graph_cost;\r\n    }\r\n\r\n    auto\
    \ update_residual(Node s, Cap rem,\r\n                         GraphCap& residual_cap,\
    \ GraphCost& residual_cost,\r\n                         const std::deque<Node>&\
    \ route)const {\r\n        Cost mn = rem;\r\n        auto from = s;\r\n      \
    \  for(const auto& to : route)if(from != to) {\r\n            mn = std::min(mn,\
    \ residual_cap[from][to]);\r\n            from = to;\r\n        }\r\n\r\n    \
    \    Cost cost_all = 0;\r\n        from = s;\r\n        for(const auto& to : route)if(from\
    \ != to) {\r\n            residual_cap[from][to] -= mn;\r\n            residual_cap[to][from]\
    \ += mn;\r\n            cost_all += mn * residual_cost[from][to];\r\n        \
    \    from = to;\r\n        }\r\n        return std::pair<Cap, Cost>{mn, cost_all};\r\
    \n    }\r\n\r\n    auto shortest_path_allow_minus(Node s,\r\n                \
    \                   const GraphCap& residual_cap,\r\n                        \
    \           const GraphCost& residual_cost) const {\r\n        auto n = m_graph.size();\r\
    \n        std::vector<Cost> cost(n, 1e18);\r\n        cost[s] = 0;\r\n       \
    \ for(int _ = 0; _ < n; ++_) {\r\n            for(int from = 0; from < n; ++from)\
    \ {\r\n                for(const auto& [to, _] : m_graph_undirected.getEdges(from))\
    \ {\r\n                    if(residual_cap[from][to] > 0) {\r\n              \
    \          cost[to] = std::min(cost[to], cost[from] + residual_cost[from][to]);\r\
    \n                    }\r\n                }\r\n            }\r\n        }\r\n\
    \        return cost;\r\n    }\r\n\r\n    auto shortest_path(Node s,\r\n     \
    \                  const GraphCap& residual_cap,\r\n                       const\
    \ GraphCost& residual_cost,\r\n                       const std::vector<Cost>&\
    \ p) const {\r\n        using P = std::pair<Cost, Node>;\r\n        std::priority_queue<P,\
    \ std::vector<P>, std::greater<P>> q;\r\n        std::vector<std::pair<Cost, Node>>\
    \ min(m_graph.size(), {1e18,-1});\r\n        auto add = [&](Node node, Cost cst,\
    \ Node from) {\r\n            if(cst >= min[node].first) { return; }\r\n     \
    \       min[node].first = cst;\r\n            min[node].second = from;\r\n   \
    \         q.emplace(cst, node);\r\n        };\r\n        add(s, 0, -1);\r\n  \
    \      while(!q.empty()) {\r\n            auto [nowCost, from] = q.top();\r\n\
    \            q.pop();\r\n            if(min[from].first < nowCost) { continue;\
    \ }\r\n            for(const auto& [to, _] : m_graph_undirected.getEdges(from))\
    \ {\r\n                if(residual_cap[from][to] == 0) { continue; }\r\n     \
    \           auto potential = residual_cost[from][to] + p[from] - p[to];\r\n  \
    \              add(to, nowCost + potential, from);\r\n            }\r\n      \
    \  }\r\n        return min;\r\n    }\r\n\r\n    static auto restore_route(int\
    \ t, const std::vector<std::pair<Cost, Node>>& sp) {\r\n        std::deque<Node>\
    \ route;\r\n        auto now = t;\r\n        while(now > -1) {\r\n           \
    \ route.emplace_front(now);\r\n            now = sp[now].second;\r\n        }\r\
    \n        return route;\r\n    }\r\npublic:\r\n    /* \u5358\u7D14\u30B0\u30E9\
    \u30D5\u3092\u4EEE\u5B9A */\r\n    SuccessiveShortestPath(const Graph<Node, std::pair<Cost,\
    \ Cap>>& graph) :\r\n        m_graph(graph),\r\n        m_graph_undirected(construct_graph_undirected())\
    \ {\r\n    }\r\n\r\n    auto slope(Node s, Node t, Cap c = 1e18)const {\r\n  \
    \      auto residual_cap = construct_graph_cap();\r\n        auto residual_cost\
    \ = construct_graph_cost();\r\n        auto default_cost = residual_cost;\r\n\
    \        std::deque<std::pair<Cost, Cap>> sl;\r\n        auto p = shortest_path_allow_minus(s,\
    \ residual_cap, residual_cost);\r\n        auto rem = c;\r\n        while(rem\
    \ > 0) {\r\n            auto sp = shortest_path(s, residual_cap, default_cost,\
    \ p);\r\n            auto route = restore_route(t, sp);\r\n            auto [use,\
    \ cst] = update_residual(s, rem, residual_cap, residual_cost, route);\r\n    \
    \        if(use == 0) { break; }\r\n            sl.emplace_back(use, cst);\r\n\
    \            rem -= use;\r\n            for(int i = 0; i < m_graph.size(); ++i)\
    \ { p[i] += sp[i].first; }\r\n        }\r\n        return sl;\r\n    }\r\n\r\n\
    \    auto min_cost_max_flow(Node s, Node t, Cap c = 1e18)const {\r\n        Cap\
    \ use_all = 0;\r\n        Cost cost_all = 0;\r\n        for(const auto& [u, c]\
    \ : slope(s, t, c)) {\r\n            use_all += u; cost_all += c;\r\n        }\r\
    \n        return std::pair<Cap, Cost>{use_all, cost_all};\r\n    }\r\n};\r\n#line\
    \ 6 \"Test/Graph/Flow/SuccessiveShortestPath.test.cpp\"\n\r\nusing ll = long long;\r\
    \nusing std::cout;\r\nusing std::cin;\r\nconstexpr char endl = '\\n';\r\n\r\n\r\
    \nsigned main() {\r\n    int n, m, f;\r\n    cin >> n >> m >> f;\r\n    auto graph\
    \ = Graph<int, std::pair<ll, ll>>(n);\r\n    for(int i = 0; i < m; ++i) {\r\n\
    \        int u, v, c, d;\r\n        cin >> u >> v >> c >> d;\r\n        graph.addEdge(u,\
    \ v, std::make_pair(c, d));\r\n    }\r\n\r\n    auto mcf = SuccessiveShortestPath(graph);\r\
    \n\r\n    auto [u, c] = mcf.min_cost_max_flow(0, n - 1, f);\r\n    cout << ((u\
    \ == f) ? c : -1) << endl;\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B\"\
    \r\n\r\n#include <iostream>\r\n#include \"./../../../Library/Graph/Graph.hpp\"\
    \r\n#include \"./../../../Library/Graph/Flow/SuccessiveShortestPath.hpp\"\r\n\r\
    \nusing ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr char\
    \ endl = '\\n';\r\n\r\n\r\nsigned main() {\r\n    int n, m, f;\r\n    cin >> n\
    \ >> m >> f;\r\n    auto graph = Graph<int, std::pair<ll, ll>>(n);\r\n    for(int\
    \ i = 0; i < m; ++i) {\r\n        int u, v, c, d;\r\n        cin >> u >> v >>\
    \ c >> d;\r\n        graph.addEdge(u, v, std::make_pair(c, d));\r\n    }\r\n\r\
    \n    auto mcf = SuccessiveShortestPath(graph);\r\n\r\n    auto [u, c] = mcf.min_cost_max_flow(0,\
    \ n - 1, f);\r\n    cout << ((u == f) ? c : -1) << endl;\r\n}"
  dependsOn:
  - Library/Graph/Graph.hpp
  - Library/Graph/Flow/SuccessiveShortestPath.hpp
  isVerificationFile: true
  path: Test/Graph/Flow/SuccessiveShortestPath.test.cpp
  requiredBy: []
  timestamp: '2024-07-18 23:59:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Graph/Flow/SuccessiveShortestPath.test.cpp
layout: document
redirect_from:
- /verify/Test/Graph/Flow/SuccessiveShortestPath.test.cpp
- /verify/Test/Graph/Flow/SuccessiveShortestPath.test.cpp.html
title: Test/Graph/Flow/SuccessiveShortestPath.test.cpp
---
