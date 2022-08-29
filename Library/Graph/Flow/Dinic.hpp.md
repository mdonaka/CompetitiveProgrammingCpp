---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Graph/Flow/Dinic.hpp\"\n\r\n#include <vector>\r\n\
    #include <queue>\r\n#include <unordered_map>\r\n#include <unordered_set>\r\n#include\
    \ <map>\r\n\r\nclass Dinic {\r\n\r\n    struct HashPair {\r\n        template<class\
    \ T1, class T2>\r\n        size_t operator()(const std::pair<T1, T2>& p) const\
    \ {\r\n            auto hash1 = std::hash<T1>{}(p.first);\r\n            auto\
    \ hash2 = std::hash<T2>{}(p.second);\r\n            size_t seed = 0;\r\n     \
    \       seed ^= hash1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);\r\n          \
    \  seed ^= hash2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);\r\n            return\
    \ seed;\r\n        }\r\n    };\r\n\r\n\r\n    using node_t = int;\r\n    using\
    \ cost_t = long long;\r\n    using Graph_f = std::unordered_multimap<node_t, std::pair<node_t,\
    \ cost_t>>;\r\n    using Graph = std::unordered_map<std::pair<node_t, node_t>,\
    \ cost_t, HashPair>;\r\n\r\n    const node_t m_n;\r\n    const Graph m_graph;\r\
    \n    const std::vector<std::unordered_set<node_t>> m_to_list;\r\n\r\n    static\
    \ auto construct_to_list(node_t n, const Graph_f& graph_f) {\r\n        std::vector<std::unordered_set<node_t>>\
    \ to_list(n);\r\n        for(const auto& [f, tc] : graph_f) {\r\n            auto\
    \ [t, c] = tc;\r\n            to_list[f].emplace(t);\r\n            to_list[t].emplace(f);\r\
    \n        }\r\n        return to_list;\r\n    }\r\n    static auto construct_graph(const\
    \ Graph_f& graph_f) {\r\n        Graph graph;\r\n        for(const auto& [f, tc]\
    \ : graph_f) {\r\n            auto [t, c] = tc;\r\n            graph[std::pair<node_t,\
    \ node_t>{f, t}] += c;\r\n        }\r\n        return graph;\r\n    }\r\n\r\n\
    \    auto get_depth(node_t s, const Graph& graph) const {\r\n        std::vector<node_t>\
    \ depth(m_n, -1);\r\n        std::queue<node_t> q;\r\n        q.emplace(s);\r\n\
    \        depth[s] = 0;\r\n        while(!q.empty()) {\r\n            auto from\
    \ = q.front();\r\n            q.pop();\r\n            for(const auto& to : m_to_list[from])\
    \ {\r\n                if(graph.find({from, to}) == graph.end()) { continue; }\r\
    \n                if(depth[to] > -1) { continue; }\r\n                depth[to]\
    \ = depth[from] + 1;\r\n                q.emplace(to);\r\n            }\r\n  \
    \      }\r\n        return depth;\r\n    }\r\n\r\n    auto update_residual(node_t\
    \ s, Graph& residual, const std::list<node_t>& route)const {\r\n        cost_t\
    \ mn = 1e18;\r\n        auto from = s;\r\n        for(const auto& to : route)if(from\
    \ != to) {\r\n            mn = std::min(mn, residual[{from, to}]);\r\n       \
    \     from = to;\r\n        }\r\n\r\n        from = s;\r\n        for(const auto&\
    \ to : route)if(from != to) {\r\n            auto& ft = residual[{from, to}];\r\
    \n            auto use = ft - mn;\r\n            ft -= mn;\r\n            if(ft\
    \ == 0) { residual.erase({from,to}); }\r\n            residual[{to, from}] +=\
    \ mn;\r\n            from = to;\r\n        }\r\n    }\r\n    auto construct_residual(node_t\
    \ s, node_t t)const {\r\n        auto residual = m_graph;\r\n        while(true)\
    \ {\r\n            // BFS\r\n            auto depth = get_depth(s, residual);\r\
    \n\r\n            // DFS\r\n            bool run = false;\r\n            std::vector<node_t>\
    \ visited(m_n);\r\n            auto f = [&](auto&& f, node_t now, std::list<node_t>&\
    \ route)->void {\r\n                route.emplace_back(now);\r\n\r\n         \
    \       // t\u306B\u5230\u9054\u3057\u3066\u3044\u308C\u3070\u6D41\u3059\r\n \
    \               if(now == t) { update_residual(s, residual, route); run = true;\
    \ }\r\n\r\n                for(const auto& to : m_to_list[now]) {\r\n        \
    \            if(residual.find({now, to}) == residual.end()) { continue; }\r\n\
    \                    if(depth[to] <= depth[now]) { continue; }\r\n           \
    \         if(visited[to]) { continue; }\r\n                    visited[to] = true;;\r\
    \n                    f(f, to, route);\r\n                }\r\n              \
    \  route.pop_back();\r\n            };\r\n            std::list<node_t> route;\r\
    \n            visited[s] = true;\r\n            f(f, s, route);\r\n          \
    \  if(!run) { break; }\r\n        }\r\n        return residual;\r\n    }\r\n\r\
    \npublic:\r\n    Dinic(node_t n, const Graph_f& graph) :\r\n        m_n(n),\r\n\
    \        m_graph(construct_graph(graph)),\r\n        m_to_list(construct_to_list(n,\
    \ graph)) {\r\n    }\r\n\r\n    auto max_flow(node_t s, node_t t)const {\r\n \
    \       auto residual = construct_residual(s, t);\r\n\r\n        cost_t val =\
    \ 0;\r\n        for(const auto& to : m_to_list[s]) {\r\n            if(m_graph.find({s,to})\
    \ == m_graph.end()) { continue; }\r\n            val += m_graph.at({s, to}) -\
    \ residual[{s, to}];\r\n        }\r\n        return val;\r\n    }\r\n\r\n    auto\
    \ get_cut_list(node_t s, node_t t) const {\r\n        // \u6B8B\u4F59\u30B0\u30E9\
    \u30D5\u3067\u59CB\u70B9\u304B\u3089\u5230\u9054\u3067\u304D\u308B\u96C6\u5408\
    \r\n        std::unordered_set<node_t> st;\r\n\r\n        auto residual = construct_residual(s,\
    \ t);\r\n        std::queue<node_t> q;\r\n        auto add = [&](node_t t) {\r\
    \n            if(st.find(t) != st.end()) { return; }\r\n            q.emplace(t);\r\
    \n            st.emplace(t);\r\n        };\r\n        add(s);\r\n        std::deque<node_t>\
    \ ans;\r\n        while(!q.empty()) {\r\n            auto f = q.front();\r\n \
    \           q.pop();\r\n            for(const auto& t : m_to_list[f]) {\r\n  \
    \              if(residual.find({f,t}) == residual.end()) { continue; }\r\n  \
    \              add(t);\r\n            }\r\n        }\r\n\r\n        std::deque<std::pair<node_t,\
    \ node_t>> cut;\r\n        for(const auto& f : st) for(const auto& t : m_to_list[f])\
    \ {\r\n            if(st.find(t) == st.end() &&\r\n               m_graph.find({f,t})\
    \ != m_graph.end()) {\r\n                cut.emplace_back(f, t);\r\n         \
    \   }\r\n        }\r\n\r\n        return cut;\r\n    }\r\n\r\n    auto get_edge(node_t\
    \ s, node_t t)const {\r\n        auto residual = construct_residual(s, t);\r\n\
    \r\n        Graph_f edge;\r\n        for(node_t from = 0; from < m_n; ++from)\
    \ {\r\n            for(const auto& to : m_to_list[from]) {\r\n               \
    \ if(m_graph.find({from,to}) == m_graph.end()) { continue; }\r\n             \
    \   auto val = m_graph.at({from, to}) - residual[{from, to}];\r\n            \
    \    if(val > 0) { edge.emplace(from, std::pair<node_t, cost_t>{to, val}); }\r\
    \n            }\r\n        }\r\n        return edge;\r\n\r\n    }\r\n};\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n#include <queue>\r\n#include <unordered_map>\r\
    \n#include <unordered_set>\r\n#include <map>\r\n\r\nclass Dinic {\r\n\r\n    struct\
    \ HashPair {\r\n        template<class T1, class T2>\r\n        size_t operator()(const\
    \ std::pair<T1, T2>& p) const {\r\n            auto hash1 = std::hash<T1>{}(p.first);\r\
    \n            auto hash2 = std::hash<T2>{}(p.second);\r\n            size_t seed\
    \ = 0;\r\n            seed ^= hash1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);\r\
    \n            seed ^= hash2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);\r\n    \
    \        return seed;\r\n        }\r\n    };\r\n\r\n\r\n    using node_t = int;\r\
    \n    using cost_t = long long;\r\n    using Graph_f = std::unordered_multimap<node_t,\
    \ std::pair<node_t, cost_t>>;\r\n    using Graph = std::unordered_map<std::pair<node_t,\
    \ node_t>, cost_t, HashPair>;\r\n\r\n    const node_t m_n;\r\n    const Graph\
    \ m_graph;\r\n    const std::vector<std::unordered_set<node_t>> m_to_list;\r\n\
    \r\n    static auto construct_to_list(node_t n, const Graph_f& graph_f) {\r\n\
    \        std::vector<std::unordered_set<node_t>> to_list(n);\r\n        for(const\
    \ auto& [f, tc] : graph_f) {\r\n            auto [t, c] = tc;\r\n            to_list[f].emplace(t);\r\
    \n            to_list[t].emplace(f);\r\n        }\r\n        return to_list;\r\
    \n    }\r\n    static auto construct_graph(const Graph_f& graph_f) {\r\n     \
    \   Graph graph;\r\n        for(const auto& [f, tc] : graph_f) {\r\n         \
    \   auto [t, c] = tc;\r\n            graph[std::pair<node_t, node_t>{f, t}] +=\
    \ c;\r\n        }\r\n        return graph;\r\n    }\r\n\r\n    auto get_depth(node_t\
    \ s, const Graph& graph) const {\r\n        std::vector<node_t> depth(m_n, -1);\r\
    \n        std::queue<node_t> q;\r\n        q.emplace(s);\r\n        depth[s] =\
    \ 0;\r\n        while(!q.empty()) {\r\n            auto from = q.front();\r\n\
    \            q.pop();\r\n            for(const auto& to : m_to_list[from]) {\r\
    \n                if(graph.find({from, to}) == graph.end()) { continue; }\r\n\
    \                if(depth[to] > -1) { continue; }\r\n                depth[to]\
    \ = depth[from] + 1;\r\n                q.emplace(to);\r\n            }\r\n  \
    \      }\r\n        return depth;\r\n    }\r\n\r\n    auto update_residual(node_t\
    \ s, Graph& residual, const std::list<node_t>& route)const {\r\n        cost_t\
    \ mn = 1e18;\r\n        auto from = s;\r\n        for(const auto& to : route)if(from\
    \ != to) {\r\n            mn = std::min(mn, residual[{from, to}]);\r\n       \
    \     from = to;\r\n        }\r\n\r\n        from = s;\r\n        for(const auto&\
    \ to : route)if(from != to) {\r\n            auto& ft = residual[{from, to}];\r\
    \n            auto use = ft - mn;\r\n            ft -= mn;\r\n            if(ft\
    \ == 0) { residual.erase({from,to}); }\r\n            residual[{to, from}] +=\
    \ mn;\r\n            from = to;\r\n        }\r\n    }\r\n    auto construct_residual(node_t\
    \ s, node_t t)const {\r\n        auto residual = m_graph;\r\n        while(true)\
    \ {\r\n            // BFS\r\n            auto depth = get_depth(s, residual);\r\
    \n\r\n            // DFS\r\n            bool run = false;\r\n            std::vector<node_t>\
    \ visited(m_n);\r\n            auto f = [&](auto&& f, node_t now, std::list<node_t>&\
    \ route)->void {\r\n                route.emplace_back(now);\r\n\r\n         \
    \       // t\u306B\u5230\u9054\u3057\u3066\u3044\u308C\u3070\u6D41\u3059\r\n \
    \               if(now == t) { update_residual(s, residual, route); run = true;\
    \ }\r\n\r\n                for(const auto& to : m_to_list[now]) {\r\n        \
    \            if(residual.find({now, to}) == residual.end()) { continue; }\r\n\
    \                    if(depth[to] <= depth[now]) { continue; }\r\n           \
    \         if(visited[to]) { continue; }\r\n                    visited[to] = true;;\r\
    \n                    f(f, to, route);\r\n                }\r\n              \
    \  route.pop_back();\r\n            };\r\n            std::list<node_t> route;\r\
    \n            visited[s] = true;\r\n            f(f, s, route);\r\n          \
    \  if(!run) { break; }\r\n        }\r\n        return residual;\r\n    }\r\n\r\
    \npublic:\r\n    Dinic(node_t n, const Graph_f& graph) :\r\n        m_n(n),\r\n\
    \        m_graph(construct_graph(graph)),\r\n        m_to_list(construct_to_list(n,\
    \ graph)) {\r\n    }\r\n\r\n    auto max_flow(node_t s, node_t t)const {\r\n \
    \       auto residual = construct_residual(s, t);\r\n\r\n        cost_t val =\
    \ 0;\r\n        for(const auto& to : m_to_list[s]) {\r\n            if(m_graph.find({s,to})\
    \ == m_graph.end()) { continue; }\r\n            val += m_graph.at({s, to}) -\
    \ residual[{s, to}];\r\n        }\r\n        return val;\r\n    }\r\n\r\n    auto\
    \ get_cut_list(node_t s, node_t t) const {\r\n        // \u6B8B\u4F59\u30B0\u30E9\
    \u30D5\u3067\u59CB\u70B9\u304B\u3089\u5230\u9054\u3067\u304D\u308B\u96C6\u5408\
    \r\n        std::unordered_set<node_t> st;\r\n\r\n        auto residual = construct_residual(s,\
    \ t);\r\n        std::queue<node_t> q;\r\n        auto add = [&](node_t t) {\r\
    \n            if(st.find(t) != st.end()) { return; }\r\n            q.emplace(t);\r\
    \n            st.emplace(t);\r\n        };\r\n        add(s);\r\n        std::deque<node_t>\
    \ ans;\r\n        while(!q.empty()) {\r\n            auto f = q.front();\r\n \
    \           q.pop();\r\n            for(const auto& t : m_to_list[f]) {\r\n  \
    \              if(residual.find({f,t}) == residual.end()) { continue; }\r\n  \
    \              add(t);\r\n            }\r\n        }\r\n\r\n        std::deque<std::pair<node_t,\
    \ node_t>> cut;\r\n        for(const auto& f : st) for(const auto& t : m_to_list[f])\
    \ {\r\n            if(st.find(t) == st.end() &&\r\n               m_graph.find({f,t})\
    \ != m_graph.end()) {\r\n                cut.emplace_back(f, t);\r\n         \
    \   }\r\n        }\r\n\r\n        return cut;\r\n    }\r\n\r\n    auto get_edge(node_t\
    \ s, node_t t)const {\r\n        auto residual = construct_residual(s, t);\r\n\
    \r\n        Graph_f edge;\r\n        for(node_t from = 0; from < m_n; ++from)\
    \ {\r\n            for(const auto& to : m_to_list[from]) {\r\n               \
    \ if(m_graph.find({from,to}) == m_graph.end()) { continue; }\r\n             \
    \   auto val = m_graph.at({from, to}) - residual[{from, to}];\r\n            \
    \    if(val > 0) { edge.emplace(from, std::pair<node_t, cost_t>{to, val}); }\r\
    \n            }\r\n        }\r\n        return edge;\r\n\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: Library/Graph/Flow/Dinic.hpp
  requiredBy: []
  timestamp: '2022-08-30 04:52:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Graph/Flow/Dinic.hpp
layout: document
redirect_from:
- /library/Library/Graph/Flow/Dinic.hpp
- /library/Library/Graph/Flow/Dinic.hpp.html
title: Library/Graph/Flow/Dinic.hpp
---
