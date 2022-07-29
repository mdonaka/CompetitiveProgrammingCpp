#pragma once

#include <unordered_map>
#include <stack>
#include <vector>
#include <list>

class SCC {
    const int m_n;
    const std::unordered_multimap<int, int> m_graph;
    const std::unordered_multimap<int, int> m_revGraph;
    const std::vector<int> m_group;

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
public:
    SCC(int n, const std::unordered_multimap<int, int>& graph) :
        m_n(n),
        m_graph(graph),
        m_revGraph(reverse()),
        m_group(constructGroup()) {
    }

    auto isSameGroup(int a, int b)const {
        return m_group[a] == m_group[b];
    }

};