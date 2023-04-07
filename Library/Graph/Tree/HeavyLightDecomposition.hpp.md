---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Graph/Tree/HeavyLightDecomposition_LCA.test.cpp
    title: Test/Graph/Tree/HeavyLightDecomposition_LCA.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Graph/Tree/HeavyLightDecomposition.hpp\"\n\r\n#include\
    \ <unordered_map>\r\n#include <queue>\r\n#include <stack>\r\n\r\nclass HeavyLightDecomposition\
    \ {\r\n\r\n    using node_t = int;\r\n    using Graph_f = std::unordered_multimap<node_t,\
    \ node_t>;\r\n    using Graph = std::unordered_map<node_t, std::deque<node_t>>;\r\
    \n\r\n    const node_t m_n;\r\n    const std::vector<node_t> m_size;\r\n    const\
    \ Graph m_tree;\r\n    const std::vector<node_t> m_height;\r\n    const std::vector<std::pair<node_t,\
    \ node_t>> m_root_par;\r\n    const std::vector<node_t> m_ids;\r\n    const std::vector<node_t>\
    \ m_order;\r\n    const std::vector<node_t> m_edge_ids;\r\n\r\n    static auto\
    \ constructGraph(node_t n, const Graph_f& tree) {\r\n        std::deque<std::pair<node_t,\
    \ node_t>> order;\r\n        std::vector<node_t> used(n);\r\n        std::stack<std::pair<node_t,\
    \ node_t>> stk;\r\n        stk.emplace(0, -1); used[0] = true;\r\n        while(!stk.empty())\
    \ {\r\n            auto [f, p] = stk.top();\r\n            order.emplace_front(f,\
    \ p);\r\n            stk.pop();\r\n            auto range = tree.equal_range(f);\r\
    \n            for(auto itr = range.first; itr != range.second; ++itr) {\r\n  \
    \              auto t = itr->second;\r\n                if(!used[t]) {\r\n   \
    \                 used[t] = true;\r\n                    stk.emplace(t, f);\r\n\
    \                }\r\n            }\r\n        }\r\n\r\n        std::vector<node_t>\
    \ size(n, 1);\r\n        Graph hld_tree;\r\n        for(const auto& [f, p] : order)\
    \ {\r\n            auto range = tree.equal_range(f);\r\n            node_t size_sum\
    \ = 1;\r\n            node_t size_max = 0;\r\n            std::deque<node_t> to_list;\r\
    \n            for(auto itr = range.first; itr != range.second; ++itr) {\r\n  \
    \              auto t = itr->second;\r\n                if(t == p) { continue;\
    \ }\r\n                if(size[t] > size_max) {\r\n                    size_max\
    \ = size[t];\r\n                    to_list.emplace_back(t);\r\n             \
    \   } else {\r\n                    to_list.emplace_front(t);\r\n            \
    \    }\r\n                size_sum += size[t];\r\n            }\r\n          \
    \  if(!to_list.empty()) {\r\n                hld_tree.emplace(f, to_list);\r\n\
    \            }\r\n            size[f] = size_sum;\r\n        }\r\n        return\
    \ hld_tree;\r\n    }\r\n\r\n    static auto constructSize(node_t n, const Graph_f&\
    \ tree) {\r\n        std::deque<std::pair<node_t, node_t>> order;\r\n        std::vector<node_t>\
    \ used(n);\r\n        std::stack<std::pair<node_t, node_t>> stk;\r\n        stk.emplace(0,\
    \ -1); used[0] = true;\r\n        while(!stk.empty()) {\r\n            auto [f,\
    \ p] = stk.top();\r\n            order.emplace_front(f, p);\r\n            stk.pop();\r\
    \n            auto range = tree.equal_range(f);\r\n            for(auto itr =\
    \ range.first; itr != range.second; ++itr) {\r\n                auto t = itr->second;\r\
    \n                if(!used[t]) {\r\n                    used[t] = true;\r\n  \
    \                  stk.emplace(t, f);\r\n                }\r\n            }\r\n\
    \        }\r\n\r\n        std::vector<node_t> size(n, 1);\r\n        for(const\
    \ auto& [f, p] : order) {\r\n            auto range = tree.equal_range(f);\r\n\
    \            node_t size_sum = 1;\r\n            for(auto itr = range.first; itr\
    \ != range.second; ++itr) {\r\n                auto t = itr->second;\r\n     \
    \           if(t == p) { continue; }\r\n                size_sum += size[t];\r\
    \n            }\r\n            size[f] = size_sum;\r\n        }\r\n        return\
    \ size;\r\n\r\n    }\r\n\r\n    static auto constructRootPar(node_t n, const Graph&\
    \ tree) {\r\n        std::vector<std::pair<node_t, node_t>> root_par(n);\r\n \
    \       std::stack<std::tuple<node_t, node_t, node_t>> stk;\r\n        stk.emplace(0,\
    \ 0, -1);\r\n        while(!stk.empty()) {\r\n            auto [f, root, par]\
    \ = stk.top();\r\n            stk.pop();\r\n\r\n            if(tree.find(f) ==\
    \ tree.end()) { root_par[f] = {root,par}; continue; }\r\n            auto itr\
    \ = tree.at(f).rbegin();\r\n            stk.emplace(*itr, root, par);\r\n    \
    \        root_par[f] = {root,par};\r\n            for(++itr; itr != tree.at(f).rend();\
    \ ++itr) {\r\n                stk.emplace(*itr, *itr, f);\r\n            }\r\n\
    \        }\r\n        return root_par;\r\n    }\r\n    static auto constructHeight(node_t\
    \ n, const Graph& tree) {\r\n        std::vector<node_t> height(n);\r\n      \
    \  std::queue<node_t> q;\r\n        q.emplace(0);\r\n        while(!q.empty())\
    \ {\r\n            auto f = q.front();\r\n            q.pop();\r\n           \
    \ if(tree.find(f) == tree.end()) { continue; }\r\n            for(const auto&\
    \ t : tree.at(f)) {\r\n                height[t] = height[f] + 1;\r\n        \
    \        q.emplace(t);\r\n            }\r\n        }\r\n        return height;\r\
    \n    }\r\n\r\n    auto constructIds() const {\r\n        std::vector<node_t>\
    \ ids(m_n);\r\n        node_t val = 0;\r\n        std::stack<node_t> stk;\r\n\
    \        stk.emplace(0);\r\n        while(!stk.empty()) {\r\n            auto\
    \ f = stk.top();\r\n            stk.pop();\r\n            ids[f] = val; ++val;\r\
    \n            if(m_tree.find(f) == m_tree.end()) { continue; }\r\n           \
    \ for(const auto& t : m_tree.at(f)) { stk.emplace(t); }\r\n        }\r\n     \
    \   return ids;\r\n    }\r\n\r\n    auto constructOrder()const {\r\n        std::vector<node_t>\
    \ order(m_n);\r\n        for(int i = 0; i < m_n; ++i) { order[m_ids[i]] = i; }\r\
    \n        return order;\r\n    }\r\n    /*\r\n     * \u8FBA\u3092node\u3068\u3057\
    \u3066\u62E1\u5F35\u3057\u305F\u5834\u5408\u306E\u8FBAnode\u3060\u3051ID\u3092\
    \u632F\u308B\r\n     * (1) - (2)\r\n     * (1) - (e) - (2)\r\n     * [-1, -1,\
    \ 0]\r\n     */\r\n    auto constructEdgeIds() const {\r\n        node_t edge_size\
    \ = (m_n >> 1);\r\n        std::vector<node_t> edge_ids(m_n, -1);\r\n        node_t\
    \ val = 0;\r\n        std::stack<node_t> stk;\r\n        stk.emplace(0);\r\n \
    \       while(!stk.empty()) {\r\n            auto f = stk.top();\r\n         \
    \   stk.pop();\r\n            if(f > edge_size) { edge_ids[f] = val; ++val; }\r\
    \n            if(m_tree.find(f) == m_tree.end()) { continue; }\r\n           \
    \ for(const auto& t : m_tree.at(f)) { stk.emplace(t); }\r\n        }\r\n     \
    \   return edge_ids;\r\n    }\r\n\r\npublic:\r\n\r\n    HeavyLightDecomposition(node_t\
    \ n, const Graph_f& tree) :\r\n        m_n(n),\r\n        m_size(constructSize(n,\
    \ tree)),\r\n        m_tree(constructGraph(n, tree)),\r\n        m_root_par(constructRootPar(n,\
    \ m_tree)),\r\n        m_height(constructHeight(n, m_tree)),\r\n        m_ids(constructIds()),\r\
    \n        m_order(constructOrder()),\r\n        m_edge_ids(constructEdgeIds())\
    \ {\r\n    }\r\n\r\n    auto getId(node_t i)const { return m_ids[i]; }\r\n   \
    \ auto getEdgeId(node_t i)const { return m_edge_ids[i]; }\r\n    auto getOrder(node_t\
    \ i)const { return m_order[i]; }\r\n\r\n    auto lca(node_t f, node_t t)const\
    \ {\r\n        do {\r\n            auto [fr, fp] = m_root_par[f];\r\n        \
    \    auto [tr, tp] = m_root_par[t];\r\n            if(fr == tr) { break; }\r\n\
    \            auto fph = (fp > -1) ? m_height[fp] : -1;\r\n            auto tph\
    \ = (tp > -1) ? m_height[tp] : -1;\r\n            if(fph < tph) { t = tp; } else\
    \ { f = fp; }\r\n        } while(true);\r\n        return (m_height[f] < m_height[t])\
    \ ? f : t;\r\n    }\r\n\r\n    auto range(node_t f, node_t t)const {\r\n     \
    \   std::deque<std::pair<node_t, node_t>> ret;\r\n        auto add = [&](node_t\
    \ f, node_t t) {\r\n            auto l = std::min(m_ids[f], m_ids[t]);\r\n   \
    \         auto r = std::max(m_ids[f], m_ids[t]);\r\n            ret.emplace_back(l,\
    \ r);\r\n        };\r\n        do {\r\n            auto [fr, fp] = m_root_par[f];\r\
    \n            auto [tr, tp] = m_root_par[t];\r\n            if(fr == tr) { add(f,\
    \ t); break; }\r\n            auto fph = (fp > -1) ? m_height[fp] : -1;\r\n  \
    \          auto tph = (tp > -1) ? m_height[tp] : -1;\r\n            if(fph < tph)\
    \ { add(t, tr); t = tp; } else { add(f, fr); f = fp; }\r\n        } while(true);\r\
    \n        return ret;\r\n    }\r\n\r\n    auto rangeEdge(node_t f, node_t t)const\
    \ {\r\n        node_t edge_size = (m_n >> 1);\r\n        std::deque<std::pair<node_t,\
    \ node_t>> ret;\r\n        auto add = [&](node_t f, node_t t) {\r\n          \
    \  auto l = std::min(m_ids[f], m_ids[t]);\r\n            auto r = std::max(m_ids[f],\
    \ m_ids[t]);\r\n            if(m_order[l] <= edge_size) { ++l; }\r\n         \
    \   if(m_order[r] <= edge_size) { --r; }\r\n            if(l > r) { return; }\r\
    \n            auto edge_l = m_edge_ids[m_order[l]];\r\n            auto edge_r\
    \ = m_edge_ids[m_order[r]];\r\n            ret.emplace_back(edge_l, edge_r);\r\
    \n        };\r\n        do {\r\n            auto [fr, fp] = m_root_par[f];\r\n\
    \            auto [tr, tp] = m_root_par[t];\r\n            if(fr == tr) { add(f,\
    \ t); break; }\r\n            auto fph = (fp > -1) ? m_height[fp] : -1;\r\n  \
    \          auto tph = (tp > -1) ? m_height[tp] : -1;\r\n            if(fph < tph)\
    \ { add(t, tr); t = tp; } else { add(f, fr); f = fp; }\r\n        } while(true);\r\
    \n        return ret;\r\n    }\r\n\r\n    auto rangeSubTree(node_t f)const {\r\
    \n        return std::pair<node_t, node_t>{\r\n            m_ids[f], m_ids[f]\
    \ + m_size[f] - 1\r\n        };\r\n    }\r\n};\r\n"
  code: "#pragma once\r\n\r\n#include <unordered_map>\r\n#include <queue>\r\n#include\
    \ <stack>\r\n\r\nclass HeavyLightDecomposition {\r\n\r\n    using node_t = int;\r\
    \n    using Graph_f = std::unordered_multimap<node_t, node_t>;\r\n    using Graph\
    \ = std::unordered_map<node_t, std::deque<node_t>>;\r\n\r\n    const node_t m_n;\r\
    \n    const std::vector<node_t> m_size;\r\n    const Graph m_tree;\r\n    const\
    \ std::vector<node_t> m_height;\r\n    const std::vector<std::pair<node_t, node_t>>\
    \ m_root_par;\r\n    const std::vector<node_t> m_ids;\r\n    const std::vector<node_t>\
    \ m_order;\r\n    const std::vector<node_t> m_edge_ids;\r\n\r\n    static auto\
    \ constructGraph(node_t n, const Graph_f& tree) {\r\n        std::deque<std::pair<node_t,\
    \ node_t>> order;\r\n        std::vector<node_t> used(n);\r\n        std::stack<std::pair<node_t,\
    \ node_t>> stk;\r\n        stk.emplace(0, -1); used[0] = true;\r\n        while(!stk.empty())\
    \ {\r\n            auto [f, p] = stk.top();\r\n            order.emplace_front(f,\
    \ p);\r\n            stk.pop();\r\n            auto range = tree.equal_range(f);\r\
    \n            for(auto itr = range.first; itr != range.second; ++itr) {\r\n  \
    \              auto t = itr->second;\r\n                if(!used[t]) {\r\n   \
    \                 used[t] = true;\r\n                    stk.emplace(t, f);\r\n\
    \                }\r\n            }\r\n        }\r\n\r\n        std::vector<node_t>\
    \ size(n, 1);\r\n        Graph hld_tree;\r\n        for(const auto& [f, p] : order)\
    \ {\r\n            auto range = tree.equal_range(f);\r\n            node_t size_sum\
    \ = 1;\r\n            node_t size_max = 0;\r\n            std::deque<node_t> to_list;\r\
    \n            for(auto itr = range.first; itr != range.second; ++itr) {\r\n  \
    \              auto t = itr->second;\r\n                if(t == p) { continue;\
    \ }\r\n                if(size[t] > size_max) {\r\n                    size_max\
    \ = size[t];\r\n                    to_list.emplace_back(t);\r\n             \
    \   } else {\r\n                    to_list.emplace_front(t);\r\n            \
    \    }\r\n                size_sum += size[t];\r\n            }\r\n          \
    \  if(!to_list.empty()) {\r\n                hld_tree.emplace(f, to_list);\r\n\
    \            }\r\n            size[f] = size_sum;\r\n        }\r\n        return\
    \ hld_tree;\r\n    }\r\n\r\n    static auto constructSize(node_t n, const Graph_f&\
    \ tree) {\r\n        std::deque<std::pair<node_t, node_t>> order;\r\n        std::vector<node_t>\
    \ used(n);\r\n        std::stack<std::pair<node_t, node_t>> stk;\r\n        stk.emplace(0,\
    \ -1); used[0] = true;\r\n        while(!stk.empty()) {\r\n            auto [f,\
    \ p] = stk.top();\r\n            order.emplace_front(f, p);\r\n            stk.pop();\r\
    \n            auto range = tree.equal_range(f);\r\n            for(auto itr =\
    \ range.first; itr != range.second; ++itr) {\r\n                auto t = itr->second;\r\
    \n                if(!used[t]) {\r\n                    used[t] = true;\r\n  \
    \                  stk.emplace(t, f);\r\n                }\r\n            }\r\n\
    \        }\r\n\r\n        std::vector<node_t> size(n, 1);\r\n        for(const\
    \ auto& [f, p] : order) {\r\n            auto range = tree.equal_range(f);\r\n\
    \            node_t size_sum = 1;\r\n            for(auto itr = range.first; itr\
    \ != range.second; ++itr) {\r\n                auto t = itr->second;\r\n     \
    \           if(t == p) { continue; }\r\n                size_sum += size[t];\r\
    \n            }\r\n            size[f] = size_sum;\r\n        }\r\n        return\
    \ size;\r\n\r\n    }\r\n\r\n    static auto constructRootPar(node_t n, const Graph&\
    \ tree) {\r\n        std::vector<std::pair<node_t, node_t>> root_par(n);\r\n \
    \       std::stack<std::tuple<node_t, node_t, node_t>> stk;\r\n        stk.emplace(0,\
    \ 0, -1);\r\n        while(!stk.empty()) {\r\n            auto [f, root, par]\
    \ = stk.top();\r\n            stk.pop();\r\n\r\n            if(tree.find(f) ==\
    \ tree.end()) { root_par[f] = {root,par}; continue; }\r\n            auto itr\
    \ = tree.at(f).rbegin();\r\n            stk.emplace(*itr, root, par);\r\n    \
    \        root_par[f] = {root,par};\r\n            for(++itr; itr != tree.at(f).rend();\
    \ ++itr) {\r\n                stk.emplace(*itr, *itr, f);\r\n            }\r\n\
    \        }\r\n        return root_par;\r\n    }\r\n    static auto constructHeight(node_t\
    \ n, const Graph& tree) {\r\n        std::vector<node_t> height(n);\r\n      \
    \  std::queue<node_t> q;\r\n        q.emplace(0);\r\n        while(!q.empty())\
    \ {\r\n            auto f = q.front();\r\n            q.pop();\r\n           \
    \ if(tree.find(f) == tree.end()) { continue; }\r\n            for(const auto&\
    \ t : tree.at(f)) {\r\n                height[t] = height[f] + 1;\r\n        \
    \        q.emplace(t);\r\n            }\r\n        }\r\n        return height;\r\
    \n    }\r\n\r\n    auto constructIds() const {\r\n        std::vector<node_t>\
    \ ids(m_n);\r\n        node_t val = 0;\r\n        std::stack<node_t> stk;\r\n\
    \        stk.emplace(0);\r\n        while(!stk.empty()) {\r\n            auto\
    \ f = stk.top();\r\n            stk.pop();\r\n            ids[f] = val; ++val;\r\
    \n            if(m_tree.find(f) == m_tree.end()) { continue; }\r\n           \
    \ for(const auto& t : m_tree.at(f)) { stk.emplace(t); }\r\n        }\r\n     \
    \   return ids;\r\n    }\r\n\r\n    auto constructOrder()const {\r\n        std::vector<node_t>\
    \ order(m_n);\r\n        for(int i = 0; i < m_n; ++i) { order[m_ids[i]] = i; }\r\
    \n        return order;\r\n    }\r\n    /*\r\n     * \u8FBA\u3092node\u3068\u3057\
    \u3066\u62E1\u5F35\u3057\u305F\u5834\u5408\u306E\u8FBAnode\u3060\u3051ID\u3092\
    \u632F\u308B\r\n     * (1) - (2)\r\n     * (1) - (e) - (2)\r\n     * [-1, -1,\
    \ 0]\r\n     */\r\n    auto constructEdgeIds() const {\r\n        node_t edge_size\
    \ = (m_n >> 1);\r\n        std::vector<node_t> edge_ids(m_n, -1);\r\n        node_t\
    \ val = 0;\r\n        std::stack<node_t> stk;\r\n        stk.emplace(0);\r\n \
    \       while(!stk.empty()) {\r\n            auto f = stk.top();\r\n         \
    \   stk.pop();\r\n            if(f > edge_size) { edge_ids[f] = val; ++val; }\r\
    \n            if(m_tree.find(f) == m_tree.end()) { continue; }\r\n           \
    \ for(const auto& t : m_tree.at(f)) { stk.emplace(t); }\r\n        }\r\n     \
    \   return edge_ids;\r\n    }\r\n\r\npublic:\r\n\r\n    HeavyLightDecomposition(node_t\
    \ n, const Graph_f& tree) :\r\n        m_n(n),\r\n        m_size(constructSize(n,\
    \ tree)),\r\n        m_tree(constructGraph(n, tree)),\r\n        m_root_par(constructRootPar(n,\
    \ m_tree)),\r\n        m_height(constructHeight(n, m_tree)),\r\n        m_ids(constructIds()),\r\
    \n        m_order(constructOrder()),\r\n        m_edge_ids(constructEdgeIds())\
    \ {\r\n    }\r\n\r\n    auto getId(node_t i)const { return m_ids[i]; }\r\n   \
    \ auto getEdgeId(node_t i)const { return m_edge_ids[i]; }\r\n    auto getOrder(node_t\
    \ i)const { return m_order[i]; }\r\n\r\n    auto lca(node_t f, node_t t)const\
    \ {\r\n        do {\r\n            auto [fr, fp] = m_root_par[f];\r\n        \
    \    auto [tr, tp] = m_root_par[t];\r\n            if(fr == tr) { break; }\r\n\
    \            auto fph = (fp > -1) ? m_height[fp] : -1;\r\n            auto tph\
    \ = (tp > -1) ? m_height[tp] : -1;\r\n            if(fph < tph) { t = tp; } else\
    \ { f = fp; }\r\n        } while(true);\r\n        return (m_height[f] < m_height[t])\
    \ ? f : t;\r\n    }\r\n\r\n    auto range(node_t f, node_t t)const {\r\n     \
    \   std::deque<std::pair<node_t, node_t>> ret;\r\n        auto add = [&](node_t\
    \ f, node_t t) {\r\n            auto l = std::min(m_ids[f], m_ids[t]);\r\n   \
    \         auto r = std::max(m_ids[f], m_ids[t]);\r\n            ret.emplace_back(l,\
    \ r);\r\n        };\r\n        do {\r\n            auto [fr, fp] = m_root_par[f];\r\
    \n            auto [tr, tp] = m_root_par[t];\r\n            if(fr == tr) { add(f,\
    \ t); break; }\r\n            auto fph = (fp > -1) ? m_height[fp] : -1;\r\n  \
    \          auto tph = (tp > -1) ? m_height[tp] : -1;\r\n            if(fph < tph)\
    \ { add(t, tr); t = tp; } else { add(f, fr); f = fp; }\r\n        } while(true);\r\
    \n        return ret;\r\n    }\r\n\r\n    auto rangeEdge(node_t f, node_t t)const\
    \ {\r\n        node_t edge_size = (m_n >> 1);\r\n        std::deque<std::pair<node_t,\
    \ node_t>> ret;\r\n        auto add = [&](node_t f, node_t t) {\r\n          \
    \  auto l = std::min(m_ids[f], m_ids[t]);\r\n            auto r = std::max(m_ids[f],\
    \ m_ids[t]);\r\n            if(m_order[l] <= edge_size) { ++l; }\r\n         \
    \   if(m_order[r] <= edge_size) { --r; }\r\n            if(l > r) { return; }\r\
    \n            auto edge_l = m_edge_ids[m_order[l]];\r\n            auto edge_r\
    \ = m_edge_ids[m_order[r]];\r\n            ret.emplace_back(edge_l, edge_r);\r\
    \n        };\r\n        do {\r\n            auto [fr, fp] = m_root_par[f];\r\n\
    \            auto [tr, tp] = m_root_par[t];\r\n            if(fr == tr) { add(f,\
    \ t); break; }\r\n            auto fph = (fp > -1) ? m_height[fp] : -1;\r\n  \
    \          auto tph = (tp > -1) ? m_height[tp] : -1;\r\n            if(fph < tph)\
    \ { add(t, tr); t = tp; } else { add(f, fr); f = fp; }\r\n        } while(true);\r\
    \n        return ret;\r\n    }\r\n\r\n    auto rangeSubTree(node_t f)const {\r\
    \n        return std::pair<node_t, node_t>{\r\n            m_ids[f], m_ids[f]\
    \ + m_size[f] - 1\r\n        };\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Graph/Tree/HeavyLightDecomposition.hpp
  requiredBy: []
  timestamp: '2023-04-08 04:07:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Graph/Tree/HeavyLightDecomposition_LCA.test.cpp
documentation_of: Library/Graph/Tree/HeavyLightDecomposition.hpp
layout: document
redirect_from:
- /library/Library/Graph/Tree/HeavyLightDecomposition.hpp
- /library/Library/Graph/Tree/HeavyLightDecomposition.hpp.html
title: Library/Graph/Tree/HeavyLightDecomposition.hpp
---
