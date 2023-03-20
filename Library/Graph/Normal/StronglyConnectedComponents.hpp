#pragma once

#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <vector>
#include <list>

class StronglyConnectedComponents {

    struct HashPair {
        template<class T1, class T2>
        size_t operator()(const std::pair<T1, T2>& p) const {
            auto hash1 = std::hash<T1>{}(p.first);
            auto hash2 = std::hash<T2>{}(p.second);
            size_t seed = 0;
            seed ^= hash1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            seed ^= hash2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            return seed;
        }
    };

    const int m_n;
    const std::unordered_multimap<int, int> m_graph;
    const std::unordered_multimap<int, int> m_revGraph;
    const std::vector<int> m_group;
    const std::vector<std::deque<int>> m_groupNodes;

    auto reverse()const {
        std::unordered_multimap<int, int> graph;
        for(const auto& [f, t] : m_graph) { graph.emplace(t, f); }
        return graph;
    }

    auto dfs(const std::unordered_multimap<int, int>& graph,
             int from,
             std::vector<int>& isUsed,
             std::list<int>& visit)->void {

        auto range = graph.equal_range(from);
        for(auto itr = range.first; itr != range.second; ++itr) {
            auto to = itr->second;
            if(!isUsed[to]) {
                isUsed[to] = true;
                dfs(graph, to, isUsed, visit);
            }
        }
        visit.emplace_back(from);
    }

    auto constructGroup() {
        std::list<int> order;
        {
            std::vector<int> used(m_n);
            for(int from = 0; from < m_n; ++from) if(!used[from]) {
                std::list<int> localOrder;
                used[from] = true;
                dfs(m_graph, from, used, localOrder);
                for(const auto& x : localOrder) {
                    order.emplace_front(x);
                }
            }
        }
        std::vector<int> group(m_n);
        {
            std::vector<int> used(m_n);

            int g = 0;
            for(const auto& from : order) if(!used[from]) {
                used[from] = true;
                std::list<int> visit;
                dfs(m_revGraph, from, used, visit);
                for(const auto& f : visit) { group[f] = g; };
                ++g;
            }
        }
        return group;
    }
    auto constructGroupNodes() const {
        auto size = *std::max_element(m_group.begin(), m_group.end()) + 1;
        std::vector<std::deque<int>> groupNodes(size);
        for(int gi = 0; gi < m_n; ++gi) {
            groupNodes[m_group[gi]].emplace_back(gi);
        }
        return groupNodes;
    }
public:
    StronglyConnectedComponents(int n, const std::unordered_multimap<int, int>& graph) :
        m_n(n),
        m_graph(graph),
        m_revGraph(reverse()),
        m_group(constructGroup()),
        m_groupNodes(constructGroupNodes()) {
    }

    auto isSameGroup(int a, int b)const {
        return m_group[a] == m_group[b];
    }
    auto getGroupNodes(int gi)const {
        if(gi < 0 || gi >= static_cast<int>(m_groupNodes.size())) {
            return std::deque<int>();
        }
        return m_groupNodes[gi];
    }
    auto getGroupGraph()const {
        std::unordered_multimap<int, int> graph;
        std::unordered_set<std::pair<int, int>, HashPair> st;
        for(const auto& [f, t] : m_graph) {
            if(isSameGroup(f, t)) { continue; }
            auto gf = m_group[f];
            auto gt = m_group[t];
            if(st.find({gf,gt}) != st.end()) { continue; }
            graph.emplace(gf, gt);
            st.emplace(gf, gt);
        }
        return graph;
    }
};
