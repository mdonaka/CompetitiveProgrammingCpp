#pragma once

#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <deque>
#include "./../../../Utils/Timer.hpp"

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

    using Graph = std::unordered_multimap<int, int>;

    const int m_n;
    const Graph m_graph;
    const Graph m_revGraph;
    const std::vector<int> m_group;
    const std::vector<std::deque<int>> m_groupNodes;

    auto reverse()const {
        Graph graph;
        for(const auto& [f, t] : m_graph) { graph.emplace(t, f); }
        return graph;
    }

    template <class F>
    auto dfs(const Graph& graph, int from,
             std::vector<bool>& is_used,
             const F& f)->void {
        is_used[from] = true;
        auto range = graph.equal_range(from);
        for(auto itr = range.first; itr != range.second; ++itr) {
            auto to = itr->second;
            if(is_used[to]) { continue; }
            dfs(graph, to, is_used, f);
        }
        f(from);
    }

    auto constructGroup() {
        std::vector<int> order; order.reserve(m_n);
        std::vector<bool> is_used(m_n);
        for(int from = 0; from < m_n; ++from) if(!is_used[from]) {
            dfs(m_graph, from, is_used, [&](int f) {
                order.emplace_back(f);
            });
        }

        int g = 0;
        std::vector<int> group(m_n);
        std::vector<bool> is_used2(m_n);
        for(int i = m_n - 1; i >= 0; --i)if(!is_used2[order[i]]) {
            dfs(m_revGraph, order[i], is_used2, [&](int f) {group[f] = g; });
            ++g;
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
        std::unordered_set<std::pair<int, int>, HashPair> st;
        for(const auto& [f, t] : m_graph) if(!isSameGroup(f, t)) {
            st.emplace(m_group[f], m_group[t]);
        }
        return std::unordered_multimap<int, int>(st.begin(), st.end());
    }
};
