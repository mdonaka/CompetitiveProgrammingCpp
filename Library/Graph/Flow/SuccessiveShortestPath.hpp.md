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
  bundledCode: "#line 2 \"Library/Graph/Flow/SuccessiveShortestPath.hpp\"\n\r\n#include\
    \ <iostream>\r\n#include <vector>\r\n#include <deque>\r\n#include <queue>\r\n\
    #include <unordered_map>\r\n#include <unordered_set>\r\n#include <map>\r\n\r\n\
    class SuccessiveShortestPath {\r\n\r\n    using node_t = long long;\r\n    using\
    \ cap_t = long long;\r\n    using cost_t = long long;\r\n\r\n    using GraphInput\
    \ = std::unordered_multimap<node_t, std::pair<node_t, std::pair<cap_t, cost_t>>>;\r\
    \n    using GraphTo = std::vector<std::deque<node_t>>;\r\n    using CapV = std::vector<cost_t>;\r\
    \n    using GraphCap = std::vector<CapV>;\r\n    using CostV = std::vector<cost_t>;\r\
    \n    using GraphCost = std::vector<CostV>;\r\n\r\n    const int m_n;\r\n    const\
    \ GraphTo m_graph_to;\r\n    const GraphCap m_graph_cap;\r\n    const GraphCost\
    \ m_graph_cost;\r\n\r\n    auto construct_graph_to(const GraphInput& graph_f)const\
    \ {\r\n        GraphTo graphTo(m_n);\r\n        for(const auto& [f, tcc] : graph_f)\
    \ {\r\n            auto [t, _] = tcc;\r\n            graphTo[f].emplace_back(t);\r\
    \n            graphTo[t].emplace_back(f);\r\n        }\r\n        return graphTo;\r\
    \n    }\r\n\r\n    auto construct_graph_cap(const GraphInput& graph_f)const {\r\
    \n        GraphCap graph_cap(m_n, CapV(m_n));\r\n        for(const auto& [f, tcc]\
    \ : graph_f) {\r\n            auto [t, cc] = tcc;\r\n            auto [cap, _]\
    \ = cc;\r\n            graph_cap[f][t] += cap;\r\n        }\r\n        return\
    \ graph_cap;\r\n    }\r\n    auto construct_graph_cost(const GraphInput& graph_f)\
    \ const {\r\n        GraphCost graph_cost(m_n, CostV(m_n));\r\n        for(const\
    \ auto& [f, tcc] : graph_f) {\r\n            auto [t, cc] = tcc;\r\n         \
    \   auto [_, cost] = cc;\r\n            graph_cost[f][t] = cost;\r\n         \
    \   graph_cost[t][f] = -cost;\r\n        }\r\n        return graph_cost;\r\n \
    \   }\r\n\r\n    auto update_residual(node_t s, cap_t rem,\r\n               \
    \          GraphCap& residual_cap, GraphCost& residual_cost,\r\n             \
    \            const std::deque<node_t>& route)const {\r\n        cost_t mn = rem;\r\
    \n        auto from = s;\r\n        for(const auto& to : route)if(from != to)\
    \ {\r\n            mn = std::min(mn, residual_cap[from][to]);\r\n            from\
    \ = to;\r\n        }\r\n\r\n        cost_t cost_all = 0;\r\n        from = s;\r\
    \n        for(const auto& to : route)if(from != to) {\r\n            residual_cap[from][to]\
    \ -= mn;\r\n            residual_cap[to][from] += mn;\r\n            cost_all\
    \ += mn * residual_cost[from][to];\r\n            from = to;\r\n        }\r\n\
    \        return std::pair<cap_t, cost_t>{mn, cost_all};\r\n    }\r\n\r\n    auto\
    \ shortest_path_allow_minus(node_t s,\r\n                                   const\
    \ GraphCap& residual_cap,\r\n                                   const GraphCost&\
    \ residual_cost) const {\r\n        CostV cost(m_n, 1e18);\r\n        cost[s]\
    \ = 0;\r\n        for(int _ = 0; _ < m_n; ++_) {\r\n            for(int from =\
    \ 0; from < m_n; ++from) {\r\n                for(const auto& to : m_graph_to[from])\
    \ {\r\n                    if(residual_cap[from][to] > 0) {\r\n              \
    \          cost[to] = std::min(cost[to], cost[from] + residual_cost[from][to]);\r\
    \n                    }\r\n                }\r\n            }\r\n        }\r\n\
    \        return cost;\r\n    }\r\n\r\n    auto shortest_path(node_t s,\r\n   \
    \                    const GraphCap& residual_cap,\r\n                       const\
    \ GraphCost& residual_cost,\r\n                       const std::vector<cost_t>&\
    \ p) const {\r\n        using P = std::pair<cost_t, node_t>;\r\n        std::priority_queue<P,\
    \ std::vector<P>, std::greater<P>> q;\r\n        std::vector<std::pair<cost_t,\
    \ node_t>> min(m_n, {1e18,-1});\r\n        auto add = [&](node_t node, cost_t\
    \ cst, node_t from) {\r\n            if(cst >= min[node].first) { return; }\r\n\
    \            min[node].first = cst;\r\n            min[node].second = from;\r\n\
    \            q.emplace(cst, node);\r\n        };\r\n        add(s, 0, -1);\r\n\
    \        while(!q.empty()) {\r\n            auto [nowCost, from] = q.top();\r\n\
    \            q.pop();\r\n            if(min[from].first < nowCost) { continue;\
    \ }\r\n            for(const auto& to : m_graph_to[from]) {\r\n              \
    \  if(residual_cap[from][to] == 0) { continue; }\r\n                auto potential\
    \ = residual_cost[from][to] + p[from] - p[to];\r\n                add(to, nowCost\
    \ + potential, from);\r\n            }\r\n        }\r\n        return min;\r\n\
    \    }\r\n\r\n    static auto restore_route(int t, const std::vector<std::pair<cost_t,\
    \ node_t>>& sp) {\r\n        std::deque<node_t> route;\r\n        auto now = t;\r\
    \n        while(now > -1) {\r\n            route.emplace_front(now);\r\n     \
    \       now = sp[now].second;\r\n        }\r\n        return route;\r\n    }\r\
    \npublic:\r\n    /* \u5358\u7D14\u30B0\u30E9\u30D5\u3092\u4EEE\u5B9A */\r\n  \
    \  SuccessiveShortestPath(int n, const GraphInput& graph) :\r\n        m_n(n),\r\
    \n        m_graph_to(construct_graph_to(graph)),\r\n        m_graph_cap(construct_graph_cap(graph)),\r\
    \n        m_graph_cost(construct_graph_cost(graph)) {\r\n    }\r\n\r\n    auto\
    \ slope(node_t s, node_t t, cap_t c = 1e18)const {\r\n        auto residual_cap\
    \ = m_graph_cap;\r\n        auto residual_cost = m_graph_cost;\r\n        std::deque<std::pair<cost_t,\
    \ cap_t>> sl;\r\n        CostV p = shortest_path_allow_minus(s, residual_cap,\
    \ residual_cost);\r\n        cap_t rem = c;\r\n        while(rem > 0) {\r\n  \
    \          auto sp = shortest_path(s, residual_cap, m_graph_cost, p);\r\n    \
    \        auto route = restore_route(t, sp);\r\n            auto [use, cst] = update_residual(s,\
    \ rem, residual_cap, residual_cost, route);\r\n            if(use == 0) { break;\
    \ }\r\n            sl.emplace_back(use, cst);\r\n            rem -= use;\r\n \
    \           for(int i = 0; i < m_n; ++i) { p[i] += sp[i].first; }\r\n        }\r\
    \n        return sl;\r\n    }\r\n\r\n    auto min_cost_max_flow(node_t s, node_t\
    \ t, cap_t c = 1e18)const {\r\n        cap_t use_all = 0;\r\n        cost_t cost_all\
    \ = 0;\r\n        for(const auto& [u, c] : slope(s, t, c)) {\r\n            use_all\
    \ += u; cost_all += c;\r\n        }\r\n        return std::pair<cap_t, cost_t>{use_all,\
    \ cost_all};\r\n    }\r\n};\r\n"
  code: "#pragma once\r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include\
    \ <deque>\r\n#include <queue>\r\n#include <unordered_map>\r\n#include <unordered_set>\r\
    \n#include <map>\r\n\r\nclass SuccessiveShortestPath {\r\n\r\n    using node_t\
    \ = long long;\r\n    using cap_t = long long;\r\n    using cost_t = long long;\r\
    \n\r\n    using GraphInput = std::unordered_multimap<node_t, std::pair<node_t,\
    \ std::pair<cap_t, cost_t>>>;\r\n    using GraphTo = std::vector<std::deque<node_t>>;\r\
    \n    using CapV = std::vector<cost_t>;\r\n    using GraphCap = std::vector<CapV>;\r\
    \n    using CostV = std::vector<cost_t>;\r\n    using GraphCost = std::vector<CostV>;\r\
    \n\r\n    const int m_n;\r\n    const GraphTo m_graph_to;\r\n    const GraphCap\
    \ m_graph_cap;\r\n    const GraphCost m_graph_cost;\r\n\r\n    auto construct_graph_to(const\
    \ GraphInput& graph_f)const {\r\n        GraphTo graphTo(m_n);\r\n        for(const\
    \ auto& [f, tcc] : graph_f) {\r\n            auto [t, _] = tcc;\r\n          \
    \  graphTo[f].emplace_back(t);\r\n            graphTo[t].emplace_back(f);\r\n\
    \        }\r\n        return graphTo;\r\n    }\r\n\r\n    auto construct_graph_cap(const\
    \ GraphInput& graph_f)const {\r\n        GraphCap graph_cap(m_n, CapV(m_n));\r\
    \n        for(const auto& [f, tcc] : graph_f) {\r\n            auto [t, cc] =\
    \ tcc;\r\n            auto [cap, _] = cc;\r\n            graph_cap[f][t] += cap;\r\
    \n        }\r\n        return graph_cap;\r\n    }\r\n    auto construct_graph_cost(const\
    \ GraphInput& graph_f) const {\r\n        GraphCost graph_cost(m_n, CostV(m_n));\r\
    \n        for(const auto& [f, tcc] : graph_f) {\r\n            auto [t, cc] =\
    \ tcc;\r\n            auto [_, cost] = cc;\r\n            graph_cost[f][t] = cost;\r\
    \n            graph_cost[t][f] = -cost;\r\n        }\r\n        return graph_cost;\r\
    \n    }\r\n\r\n    auto update_residual(node_t s, cap_t rem,\r\n             \
    \            GraphCap& residual_cap, GraphCost& residual_cost,\r\n           \
    \              const std::deque<node_t>& route)const {\r\n        cost_t mn =\
    \ rem;\r\n        auto from = s;\r\n        for(const auto& to : route)if(from\
    \ != to) {\r\n            mn = std::min(mn, residual_cap[from][to]);\r\n     \
    \       from = to;\r\n        }\r\n\r\n        cost_t cost_all = 0;\r\n      \
    \  from = s;\r\n        for(const auto& to : route)if(from != to) {\r\n      \
    \      residual_cap[from][to] -= mn;\r\n            residual_cap[to][from] +=\
    \ mn;\r\n            cost_all += mn * residual_cost[from][to];\r\n           \
    \ from = to;\r\n        }\r\n        return std::pair<cap_t, cost_t>{mn, cost_all};\r\
    \n    }\r\n\r\n    auto shortest_path_allow_minus(node_t s,\r\n              \
    \                     const GraphCap& residual_cap,\r\n                      \
    \             const GraphCost& residual_cost) const {\r\n        CostV cost(m_n,\
    \ 1e18);\r\n        cost[s] = 0;\r\n        for(int _ = 0; _ < m_n; ++_) {\r\n\
    \            for(int from = 0; from < m_n; ++from) {\r\n                for(const\
    \ auto& to : m_graph_to[from]) {\r\n                    if(residual_cap[from][to]\
    \ > 0) {\r\n                        cost[to] = std::min(cost[to], cost[from] +\
    \ residual_cost[from][to]);\r\n                    }\r\n                }\r\n\
    \            }\r\n        }\r\n        return cost;\r\n    }\r\n\r\n    auto shortest_path(node_t\
    \ s,\r\n                       const GraphCap& residual_cap,\r\n             \
    \          const GraphCost& residual_cost,\r\n                       const std::vector<cost_t>&\
    \ p) const {\r\n        using P = std::pair<cost_t, node_t>;\r\n        std::priority_queue<P,\
    \ std::vector<P>, std::greater<P>> q;\r\n        std::vector<std::pair<cost_t,\
    \ node_t>> min(m_n, {1e18,-1});\r\n        auto add = [&](node_t node, cost_t\
    \ cst, node_t from) {\r\n            if(cst >= min[node].first) { return; }\r\n\
    \            min[node].first = cst;\r\n            min[node].second = from;\r\n\
    \            q.emplace(cst, node);\r\n        };\r\n        add(s, 0, -1);\r\n\
    \        while(!q.empty()) {\r\n            auto [nowCost, from] = q.top();\r\n\
    \            q.pop();\r\n            if(min[from].first < nowCost) { continue;\
    \ }\r\n            for(const auto& to : m_graph_to[from]) {\r\n              \
    \  if(residual_cap[from][to] == 0) { continue; }\r\n                auto potential\
    \ = residual_cost[from][to] + p[from] - p[to];\r\n                add(to, nowCost\
    \ + potential, from);\r\n            }\r\n        }\r\n        return min;\r\n\
    \    }\r\n\r\n    static auto restore_route(int t, const std::vector<std::pair<cost_t,\
    \ node_t>>& sp) {\r\n        std::deque<node_t> route;\r\n        auto now = t;\r\
    \n        while(now > -1) {\r\n            route.emplace_front(now);\r\n     \
    \       now = sp[now].second;\r\n        }\r\n        return route;\r\n    }\r\
    \npublic:\r\n    /* \u5358\u7D14\u30B0\u30E9\u30D5\u3092\u4EEE\u5B9A */\r\n  \
    \  SuccessiveShortestPath(int n, const GraphInput& graph) :\r\n        m_n(n),\r\
    \n        m_graph_to(construct_graph_to(graph)),\r\n        m_graph_cap(construct_graph_cap(graph)),\r\
    \n        m_graph_cost(construct_graph_cost(graph)) {\r\n    }\r\n\r\n    auto\
    \ slope(node_t s, node_t t, cap_t c = 1e18)const {\r\n        auto residual_cap\
    \ = m_graph_cap;\r\n        auto residual_cost = m_graph_cost;\r\n        std::deque<std::pair<cost_t,\
    \ cap_t>> sl;\r\n        CostV p = shortest_path_allow_minus(s, residual_cap,\
    \ residual_cost);\r\n        cap_t rem = c;\r\n        while(rem > 0) {\r\n  \
    \          auto sp = shortest_path(s, residual_cap, m_graph_cost, p);\r\n    \
    \        auto route = restore_route(t, sp);\r\n            auto [use, cst] = update_residual(s,\
    \ rem, residual_cap, residual_cost, route);\r\n            if(use == 0) { break;\
    \ }\r\n            sl.emplace_back(use, cst);\r\n            rem -= use;\r\n \
    \           for(int i = 0; i < m_n; ++i) { p[i] += sp[i].first; }\r\n        }\r\
    \n        return sl;\r\n    }\r\n\r\n    auto min_cost_max_flow(node_t s, node_t\
    \ t, cap_t c = 1e18)const {\r\n        cap_t use_all = 0;\r\n        cost_t cost_all\
    \ = 0;\r\n        for(const auto& [u, c] : slope(s, t, c)) {\r\n            use_all\
    \ += u; cost_all += c;\r\n        }\r\n        return std::pair<cap_t, cost_t>{use_all,\
    \ cost_all};\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Graph/Flow/SuccessiveShortestPath.hpp
  requiredBy: []
  timestamp: '2022-08-30 04:52:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Graph/Flow/SuccessiveShortestPath.hpp
layout: document
redirect_from:
- /library/Library/Graph/Flow/SuccessiveShortestPath.hpp
- /library/Library/Graph/Flow/SuccessiveShortestPath.hpp.html
title: Library/Graph/Flow/SuccessiveShortestPath.hpp
---
