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
    const std::vector<int> m_group;

    static inline auto reverse(const Graph& graph) {
        Graph ret; ret.reserve(graph.size());
        for(const auto& [f, t] : graph) { ret.emplace(t, f); }
        return ret;
    }

    template <class F>
    static inline auto dfs(const Graph& graph, int from,
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

    static inline auto constructGroup(int n, const Graph& graph) {
        std::vector<int> order; order.reserve(n);
        std::vector<bool> is_used(n);
        for(int from = 0; from < n; ++from) if(!is_used[from]) {
            dfs(graph, from, is_used, [&](int f) {
                order.emplace_back(f);
            });
        }

        int g = 0;
        std::vector<int> group(n);
        std::vector<bool> is_used2(n);
        auto rev = reverse(graph);
        for(int i = n - 1; i >= 0; --i)if(!is_used2[order[i]]) {
            dfs(rev, order[i], is_used2, [&](int f) {group[f] = g; });
            ++g;
        }
        return group;
    }
    auto constructGroupNodes() const {
    }
public:
    StronglyConnectedComponents(int n, const Graph& graph) :
        m_n(n),
        m_graph(graph),
        m_group(constructGroup(n, m_graph)) {
    }
    // graphのコピーコストが大きいのでこっち推奨
    StronglyConnectedComponents(int n, Graph&& graph) :
        m_n(n),
        m_graph(std::move(graph)),
        m_group(constructGroup(n, m_graph)) {
    }

    auto isSameGroup(int a, int b)const {
        return m_group[a] == m_group[b];
    }
    auto getGroupNodes()const {
        auto size = *std::max_element(m_group.begin(), m_group.end()) + 1;
        std::vector<std::deque<int>> groupNodes(size);
        for(int gi = 0; gi < m_n; ++gi) {
            groupNodes[m_group[gi]].emplace_back(gi);
        }
        return groupNodes;
    }
    auto getGroupGraph()const {
        std::unordered_set<std::pair<int, int>, HashPair> st;
        st.reserve(m_graph.size());
        for(const auto& [f, t] : m_graph) if(!isSameGroup(f, t)) {
            st.emplace(m_group[f], m_group[t]);
        }
        return Graph(st.begin(), st.end());
    }
};
