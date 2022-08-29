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
  bundledCode: "#line 2 \"Library/Graph/Normal/StronglyConnectedComponents.hpp\"\n\
    \r\n#include <unordered_map>\r\n#include <stack>\r\n#include <vector>\r\n#include\
    \ <list>\r\n\r\nclass SCC {\r\n\r\n    struct HashPair {\r\n        template<class\
    \ T1, class T2>\r\n        size_t operator()(const std::pair<T1, T2>& p) const\
    \ {\r\n            auto hash1 = std::hash<T1>{}(p.first);\r\n            auto\
    \ hash2 = std::hash<T2>{}(p.second);\r\n            size_t seed = 0;\r\n     \
    \       seed ^= hash1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);\r\n          \
    \  seed ^= hash2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);\r\n            return\
    \ seed;\r\n        }\r\n    };\r\n\r\n    const int m_n;\r\n    const std::unordered_multimap<int,\
    \ int> m_graph;\r\n    const std::unordered_multimap<int, int> m_revGraph;\r\n\
    \    const std::vector<int> m_group;\r\n    const std::vector<std::deque<int>>\
    \ m_groupNodes;\r\n\r\n    auto reverse()const {\r\n        std::unordered_multimap<int,\
    \ int> graph;\r\n        for(const auto& [f, t] : m_graph) { graph.emplace(t,\
    \ f); }\r\n        return graph;\r\n    }\r\n\r\n    auto dfs(const std::unordered_multimap<int,\
    \ int>& graph,\r\n             int from,\r\n             std::vector<int>& isUsed,\r\
    \n             std::list<int>& visit)->void {\r\n\r\n        auto range = graph.equal_range(from);\r\
    \n        for(auto itr = range.first; itr != range.second; ++itr) {\r\n      \
    \      auto to = itr->second;\r\n            if(!isUsed[to]) {\r\n           \
    \     isUsed[to] = true;\r\n                dfs(graph, to, isUsed, visit);\r\n\
    \            }\r\n        }\r\n        visit.emplace_back(from);\r\n    }\r\n\r\
    \n    auto constructGroup() {\r\n        std::list<int> order;\r\n        {\r\n\
    \            std::vector<int> used(m_n);\r\n            for(int from = 0; from\
    \ < m_n; ++from) if(!used[from]) {\r\n                std::list<int> localOrder;\r\
    \n                used[from] = true;\r\n                dfs(m_graph, from, used,\
    \ localOrder);\r\n                for(const auto& x : localOrder) {\r\n      \
    \              order.emplace_front(x);\r\n                }\r\n            }\r\
    \n        }\r\n        std::vector<int> group(m_n);\r\n        {\r\n         \
    \   std::vector<int> used(m_n);\r\n\r\n            int g = 0;\r\n            for(const\
    \ auto& from : order) if(!used[from]) {\r\n                used[from] = true;\r\
    \n                std::list<int> visit;\r\n                dfs(m_revGraph, from,\
    \ used, visit);\r\n                for(const auto& f : visit) { group[f] = g;\
    \ };\r\n                ++g;\r\n            }\r\n        }\r\n        return group;\r\
    \n    }\r\n    auto constructGroupNodes() const {\r\n        auto size = *std::max_element(m_group.begin(),\
    \ m_group.end()) + 1;\r\n        std::vector<std::deque<int>> groupNodes(size);\r\
    \n        for(int gi = 0; gi < m_n; ++gi) {\r\n            groupNodes[m_group[gi]].emplace_back(gi);\r\
    \n        }\r\n        return groupNodes;\r\n    }\r\npublic:\r\n    SCC(int n,\
    \ const std::unordered_multimap<int, int>& graph) :\r\n        m_n(n),\r\n   \
    \     m_graph(graph),\r\n        m_revGraph(reverse()),\r\n        m_group(constructGroup()),\r\
    \n        m_groupNodes(constructGroupNodes()) {\r\n    }\r\n\r\n    auto isSameGroup(int\
    \ a, int b)const {\r\n        return m_group[a] == m_group[b];\r\n    }\r\n  \
    \  auto getGroupNodes(int gi)const {\r\n        if(gi < 0 || gi >= static_cast<int>(m_groupNodes.size()))\
    \ {\r\n            return std::deque<int>();\r\n        }\r\n        return m_groupNodes[gi];\r\
    \n    }\r\n    auto getGroupGraph()const {\r\n        std::unordered_multimap<int,\
    \ int> graph;\r\n        std::unordered_set<std::pair<int, int>, HashPair> st;\r\
    \n        for(const auto& [f, t] : m_graph) {\r\n            if(isSameGroup(f,\
    \ t)) { continue; }\r\n            auto gf = m_group[f];\r\n            auto gt\
    \ = m_group[t];\r\n            if(st.find({gf,gt}) != st.end()) { continue; }\r\
    \n            graph.emplace(gf, gt);\r\n            st.emplace(gf, gt);\r\n  \
    \      }\r\n        return graph;\r\n    }\r\n};\n"
  code: "#pragma once\r\n\r\n#include <unordered_map>\r\n#include <stack>\r\n#include\
    \ <vector>\r\n#include <list>\r\n\r\nclass SCC {\r\n\r\n    struct HashPair {\r\
    \n        template<class T1, class T2>\r\n        size_t operator()(const std::pair<T1,\
    \ T2>& p) const {\r\n            auto hash1 = std::hash<T1>{}(p.first);\r\n  \
    \          auto hash2 = std::hash<T2>{}(p.second);\r\n            size_t seed\
    \ = 0;\r\n            seed ^= hash1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);\r\
    \n            seed ^= hash2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);\r\n    \
    \        return seed;\r\n        }\r\n    };\r\n\r\n    const int m_n;\r\n   \
    \ const std::unordered_multimap<int, int> m_graph;\r\n    const std::unordered_multimap<int,\
    \ int> m_revGraph;\r\n    const std::vector<int> m_group;\r\n    const std::vector<std::deque<int>>\
    \ m_groupNodes;\r\n\r\n    auto reverse()const {\r\n        std::unordered_multimap<int,\
    \ int> graph;\r\n        for(const auto& [f, t] : m_graph) { graph.emplace(t,\
    \ f); }\r\n        return graph;\r\n    }\r\n\r\n    auto dfs(const std::unordered_multimap<int,\
    \ int>& graph,\r\n             int from,\r\n             std::vector<int>& isUsed,\r\
    \n             std::list<int>& visit)->void {\r\n\r\n        auto range = graph.equal_range(from);\r\
    \n        for(auto itr = range.first; itr != range.second; ++itr) {\r\n      \
    \      auto to = itr->second;\r\n            if(!isUsed[to]) {\r\n           \
    \     isUsed[to] = true;\r\n                dfs(graph, to, isUsed, visit);\r\n\
    \            }\r\n        }\r\n        visit.emplace_back(from);\r\n    }\r\n\r\
    \n    auto constructGroup() {\r\n        std::list<int> order;\r\n        {\r\n\
    \            std::vector<int> used(m_n);\r\n            for(int from = 0; from\
    \ < m_n; ++from) if(!used[from]) {\r\n                std::list<int> localOrder;\r\
    \n                used[from] = true;\r\n                dfs(m_graph, from, used,\
    \ localOrder);\r\n                for(const auto& x : localOrder) {\r\n      \
    \              order.emplace_front(x);\r\n                }\r\n            }\r\
    \n        }\r\n        std::vector<int> group(m_n);\r\n        {\r\n         \
    \   std::vector<int> used(m_n);\r\n\r\n            int g = 0;\r\n            for(const\
    \ auto& from : order) if(!used[from]) {\r\n                used[from] = true;\r\
    \n                std::list<int> visit;\r\n                dfs(m_revGraph, from,\
    \ used, visit);\r\n                for(const auto& f : visit) { group[f] = g;\
    \ };\r\n                ++g;\r\n            }\r\n        }\r\n        return group;\r\
    \n    }\r\n    auto constructGroupNodes() const {\r\n        auto size = *std::max_element(m_group.begin(),\
    \ m_group.end()) + 1;\r\n        std::vector<std::deque<int>> groupNodes(size);\r\
    \n        for(int gi = 0; gi < m_n; ++gi) {\r\n            groupNodes[m_group[gi]].emplace_back(gi);\r\
    \n        }\r\n        return groupNodes;\r\n    }\r\npublic:\r\n    SCC(int n,\
    \ const std::unordered_multimap<int, int>& graph) :\r\n        m_n(n),\r\n   \
    \     m_graph(graph),\r\n        m_revGraph(reverse()),\r\n        m_group(constructGroup()),\r\
    \n        m_groupNodes(constructGroupNodes()) {\r\n    }\r\n\r\n    auto isSameGroup(int\
    \ a, int b)const {\r\n        return m_group[a] == m_group[b];\r\n    }\r\n  \
    \  auto getGroupNodes(int gi)const {\r\n        if(gi < 0 || gi >= static_cast<int>(m_groupNodes.size()))\
    \ {\r\n            return std::deque<int>();\r\n        }\r\n        return m_groupNodes[gi];\r\
    \n    }\r\n    auto getGroupGraph()const {\r\n        std::unordered_multimap<int,\
    \ int> graph;\r\n        std::unordered_set<std::pair<int, int>, HashPair> st;\r\
    \n        for(const auto& [f, t] : m_graph) {\r\n            if(isSameGroup(f,\
    \ t)) { continue; }\r\n            auto gf = m_group[f];\r\n            auto gt\
    \ = m_group[t];\r\n            if(st.find({gf,gt}) != st.end()) { continue; }\r\
    \n            graph.emplace(gf, gt);\r\n            st.emplace(gf, gt);\r\n  \
    \      }\r\n        return graph;\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: Library/Graph/Normal/StronglyConnectedComponents.hpp
  requiredBy: []
  timestamp: '2022-07-29 18:42:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Graph/Normal/StronglyConnectedComponents.hpp
layout: document
redirect_from:
- /library/Library/Graph/Normal/StronglyConnectedComponents.hpp
- /library/Library/Graph/Normal/StronglyConnectedComponents.hpp.html
title: Library/Graph/Normal/StronglyConnectedComponents.hpp
---
