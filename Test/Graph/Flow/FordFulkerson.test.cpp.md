---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Flow/FordFulkerson.hpp
    title: Library/Graph/Flow/FordFulkerson.hpp
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
  bundledCode: "#line 1 \"Test/Graph/Flow/FordFulkerson.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\r\n\r\n\
    #include <iostream>\r\n#line 2 \"Library/Graph/Graph.hpp\"\n#include <vector>\r\
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
    \n    }\r\n};\n#line 2 \"Library/Graph/Flow/FordFulkerson.hpp\"\n\r\n#line 4 \"\
    Library/Graph/Flow/FordFulkerson.hpp\"\n#include <queue>\r\n#include <list>\r\n\
    #include <unordered_map>\r\n#include <unordered_set>\r\n#include <map>\r\n\r\n\
    #line 11 \"Library/Graph/Flow/FordFulkerson.hpp\"\n\r\ntemplate<class Node, class\
    \ Cost>\r\nclass FordFulkerson {\r\n    //using Node = int;\r\n    //using Cost\
    \ = int;\r\n\r\n    struct HashPair {\r\n        template<class T1, class T2>\r\
    \n        size_t operator()(const std::pair<T1, T2>& p) const {\r\n          \
    \  auto hash1 = std::hash<T1>{}(p.first);\r\n            auto hash2 = std::hash<T2>{}(p.second);\r\
    \n            size_t seed = 0;\r\n            seed ^= hash1 + 0x9e3779b9 + (seed\
    \ << 6) + (seed >> 2);\r\n            seed ^= hash2 + 0x9e3779b9 + (seed << 6)\
    \ + (seed >> 2);\r\n            return seed;\r\n        }\r\n    };\r\n\r\n  \
    \  using PairGraph = std::unordered_map<std::pair<Node, Node>, Cost, HashPair>;\r\
    \n\r\n    const Node m_n;\r\n    const PairGraph m_graph;\r\n    const std::vector<std::unordered_set<Node>>\
    \ m_to_list;\r\n\r\n    static auto construct_to_list(const Graph<Node, Cost>&\
    \ graph) {\r\n        std::vector<std::unordered_set<Node>> to_list(graph.size());\r\
    \n        for(const auto& [f, t, c] : graph.getEdges()) {\r\n            to_list[f].emplace(t);\r\
    \n            to_list[t].emplace(f);\r\n        }\r\n        return to_list;\r\
    \n    }\r\n    static auto construct_graph(const Graph<Node, Cost>& graph) {\r\
    \n        PairGraph pair_graph;\r\n        for(const auto& [f, t, c] : graph.getEdges())\
    \ {\r\n            pair_graph[std::pair<Node, Node>{f, t}] += c;\r\n        }\r\
    \n        return pair_graph;\r\n    }\r\n\r\n    auto get_route(Node s, Node t,\
    \ const PairGraph& graph) const {\r\n        std::unordered_set<Node> visited;\r\
    \n        auto f = [&](auto&& f, Node now, std::list<Node>& route)->bool {\r\n\
    \            route.emplace_back(now);\r\n            for(const auto& to : m_to_list[now])\
    \ {\r\n                if(graph.find({now, to}) == graph.end()) { continue; }\r\
    \n                if(to == t) { route.emplace_back(t); return true; }\r\n    \
    \            if(visited.find(to) == visited.end()) {\r\n                    visited.emplace(to);\r\
    \n                    if(f(f, to, route)) { return true; }\r\n               \
    \ }\r\n            }\r\n            route.pop_back();\r\n            return false;\r\
    \n        };\r\n        std::list<Node> route;\r\n        visited.emplace(s);\r\
    \n        auto ok = f(f, s, route);\r\n        if(ok) { return route; } else {\
    \ return std::list<Node>{}; }\r\n    }\r\n\r\n\r\n    auto construct_residual(Node\
    \ s, Node t)const {\r\n        auto residual = m_graph;\r\n        while(true)\
    \ {\r\n            auto route = get_route(s, t, residual);\r\n            if(route.empty())\
    \ { break; }\r\n\r\n            Cost mn = 1e9;\r\n            Node from = s;\r\
    \n            for(const auto& to : route)if(from != to) {\r\n                mn\
    \ = std::min(mn, residual[{from, to}]);\r\n                from = to;\r\n    \
    \        }\r\n\r\n            from = s;\r\n            for(const auto& to : route)if(from\
    \ != to) {\r\n                auto& ft = residual[{from, to}];\r\n           \
    \     ft -= mn;\r\n                if(ft == 0) { residual.erase({from,to}); }\r\
    \n                residual[{to, from}] += mn;\r\n                from = to;\r\n\
    \            }\r\n        }\r\n        return residual;\r\n    }\r\npublic:\r\n\
    \    FordFulkerson(const Graph<Node, Cost>& graph) :\r\n        m_n(graph.size()),\r\
    \n        m_graph(construct_graph(graph)),\r\n        m_to_list(construct_to_list(graph))\
    \ {\r\n    }\r\n\r\n    auto max_flow(Node s, Node t)const {\r\n        auto residual\
    \ = construct_residual(s, t);\r\n\r\n        Cost val = 0;\r\n        for(const\
    \ auto& to : m_to_list[s]) {\r\n            if(m_graph.find({s,to}) == m_graph.end())\
    \ { continue; }\r\n            val += m_graph.at({s, to}) - residual[{s, to}];\r\
    \n        }\r\n        return val;\r\n    }\r\n\r\n\r\n    auto get_cut_list(Node\
    \ s, Node t) const {\r\n        // \u6B8B\u4F59\u30B0\u30E9\u30D5\u3067\u59CB\u70B9\
    \u304B\u3089\u5230\u9054\u3067\u304D\u308B\u96C6\u5408\r\n        std::unordered_set<Node>\
    \ st;\r\n\r\n        auto residual = construct_residual(s, t);\r\n        std::queue<Node>\
    \ q;\r\n        auto add = [&](Node t) {\r\n            if(st.find(t) != st.end())\
    \ { return; }\r\n            q.emplace(t);\r\n            st.emplace(t);\r\n \
    \       };\r\n        add(s);\r\n        std::deque<Node> ans;\r\n        while(!q.empty())\
    \ {\r\n            auto f = q.front();\r\n            q.pop();\r\n           \
    \ for(const auto& t : m_to_list[f]) {\r\n                if(residual.find({f,t})\
    \ == residual.end()) { continue; }\r\n                add(t);\r\n            }\r\
    \n        }\r\n\r\n        std::deque<std::pair<Node, Node>> cut;\r\n        for(const\
    \ auto& f : st) for(const auto& t : m_to_list[f]) {\r\n            if(st.find(t)\
    \ == st.end() &&\r\n               m_graph.find({f,t}) != m_graph.end()) {\r\n\
    \                cut.emplace_back(f, t);\r\n            }\r\n        }\r\n\r\n\
    \        return cut;\r\n    }\r\n\r\n\r\n    auto get_edge(Node s, Node t)const\
    \ {\r\n        auto residual = construct_residual(s, t);\r\n\r\n        auto edge\
    \ = Graph<Node, Cost>(m_n);\r\n        for(Node from = 0; from < m_n; ++from)\
    \ {\r\n            for(const auto& to : m_to_list[from]) {\r\n               \
    \ if(m_graph.find({from,to}) == m_graph.end()) { continue; }\r\n             \
    \   auto val = m_graph.at({from, to}) - residual[{from, to}];\r\n            \
    \    if(val > 0) { edge.addEdge(from, to, val); }\r\n            }\r\n       \
    \ }\r\n        return edge;\r\n\r\n    }\r\n};\n#line 6 \"Test/Graph/Flow/FordFulkerson.test.cpp\"\
    \n\r\nusing ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr\
    \ char endl = '\\n';\r\n\r\n\r\nsigned main() {\r\n    int n, m;\r\n    cin >>\
    \ n >> m;\r\n    auto graph = Graph(n);\r\n    for(int i = 0; i < m; ++i) {\r\n\
    \        int u, v, c;\r\n        cin >> u >> v >> c;\r\n        graph.addEdge(u,\
    \ v, c);\r\n    }\r\n\r\n    auto mf = FordFulkerson(graph);\r\n\r\n    cout <<\
    \ mf.max_flow(0, n - 1) << endl;\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\
    \r\n\r\n#include <iostream>\r\n#include \"./../../../Library/Graph/Graph.hpp\"\
    \r\n#include \"./../../../Library/Graph/Flow/FordFulkerson.hpp\"\r\n\r\nusing\
    \ ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr char endl\
    \ = '\\n';\r\n\r\n\r\nsigned main() {\r\n    int n, m;\r\n    cin >> n >> m;\r\
    \n    auto graph = Graph(n);\r\n    for(int i = 0; i < m; ++i) {\r\n        int\
    \ u, v, c;\r\n        cin >> u >> v >> c;\r\n        graph.addEdge(u, v, c);\r\
    \n    }\r\n\r\n    auto mf = FordFulkerson(graph);\r\n\r\n    cout << mf.max_flow(0,\
    \ n - 1) << endl;\r\n}"
  dependsOn:
  - Library/Graph/Graph.hpp
  - Library/Graph/Flow/FordFulkerson.hpp
  isVerificationFile: true
  path: Test/Graph/Flow/FordFulkerson.test.cpp
  requiredBy: []
  timestamp: '2024-07-18 23:59:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Graph/Flow/FordFulkerson.test.cpp
layout: document
redirect_from:
- /verify/Test/Graph/Flow/FordFulkerson.test.cpp
- /verify/Test/Graph/Flow/FordFulkerson.test.cpp.html
title: Test/Graph/Flow/FordFulkerson.test.cpp
---
