#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>

class SuccessiveShortestPath {

    using node_t = long long;
    using cap_t = long long;
    using cost_t = long long;

    using GraphInput = std::unordered_multimap<node_t, std::pair<node_t, std::pair<cap_t, cost_t>>>;
    using GraphTo = std::vector<std::deque<node_t>>;
    using CapV = std::vector<cost_t>;
    using GraphCap = std::vector<CapV>;
    using CostV = std::vector<cost_t>;
    using GraphCost = std::vector<CostV>;

    const int m_n;
    const GraphTo m_graph_to;
    const GraphCap m_graph_cap;
    const GraphCost m_graph_cost;

    auto construct_graph_to(const GraphInput& graph_f)const {
        GraphTo graphTo(m_n);
        for(const auto& [f, tcc] : graph_f) {
            auto [t, _] = tcc;
            graphTo[f].emplace_back(t);
            graphTo[t].emplace_back(f);
        }
        return graphTo;
    }

    auto construct_graph_cap(const GraphInput& graph_f)const {
        GraphCap graph_cap(m_n, CapV(m_n));
        for(const auto& [f, tcc] : graph_f) {
            auto [t, cc] = tcc;
            auto [cap, _] = cc;
            graph_cap[f][t] += cap;
        }
        return graph_cap;
    }
    auto construct_graph_cost(const GraphInput& graph_f) const {
        GraphCost graph_cost(m_n, CostV(m_n));
        for(const auto& [f, tcc] : graph_f) {
            auto [t, cc] = tcc;
            auto [_, cost] = cc;
            graph_cost[f][t] = cost;
            graph_cost[t][f] = -cost;
        }
        return graph_cost;
    }

    auto update_residual(node_t s, cap_t rem,
                         GraphCap& residual_cap, GraphCost& residual_cost,
                         const std::deque<node_t>& route)const {
        cost_t mn = rem;
        auto from = s;
        for(const auto& to : route)if(from != to) {
            mn = std::min(mn, residual_cap[from][to]);
            from = to;
        }

        cost_t cost_all = 0;
        from = s;
        for(const auto& to : route)if(from != to) {
            residual_cap[from][to] -= mn;
            residual_cap[to][from] += mn;
            cost_all += mn * residual_cost[from][to];
            from = to;
        }
        return std::pair<cap_t, cost_t>{mn, cost_all};
    }

    auto shortest_path_allow_minus(node_t s,
                                   const GraphCap& residual_cap,
                                   const GraphCost& residual_cost) const {
        CostV cost(m_n, 1e18);
        cost[s] = 0;
        for(int _ = 0; _ < m_n; ++_) {
            for(int from = 0; from < m_n; ++from) {
                for(const auto& to : m_graph_to[from]) {
                    if(residual_cap[from][to] > 0) {
                        cost[to] = std::min(cost[to], cost[from] + residual_cost[from][to]);
                    }
                }
            }
        }
        return cost;
    }

    auto shortest_path(node_t s,
                       const GraphCap& residual_cap,
                       const GraphCost& residual_cost,
                       const std::vector<cost_t>& p) const {
        using P = std::pair<cost_t, node_t>;
        std::priority_queue<P, std::vector<P>, std::greater<P>> q;
        std::vector<std::pair<cost_t, node_t>> min(m_n, {1e18,-1});
        auto add = [&](node_t node, cost_t cst, node_t from) {
            if(cst >= min[node].first) { return; }
            min[node].first = cst;
            min[node].second = from;
            q.emplace(cst, node);
        };
        add(s, 0, -1);
        while(!q.empty()) {
            auto [nowCost, from] = q.top();
            q.pop();
            if(min[from].first < nowCost) { continue; }
            for(const auto& to : m_graph_to[from]) {
                if(residual_cap[from][to] == 0) { continue; }
                auto potential = residual_cost[from][to] + p[from] - p[to];
                add(to, nowCost + potential, from);
            }
        }
        return min;
    }

    static auto restore_route(int t, const std::vector<std::pair<cost_t, node_t>>& sp) {
        std::deque<node_t> route;
        auto now = t;
        while(now > -1) {
            route.emplace_front(now);
            now = sp[now].second;
        }
        return route;
    }
public:
    /* 単純グラフを仮定 */
    SuccessiveShortestPath(int n, const GraphInput& graph) :
        m_n(n),
        m_graph_to(construct_graph_to(graph)),
        m_graph_cap(construct_graph_cap(graph)),
        m_graph_cost(construct_graph_cost(graph)) {
    }

    auto slope(node_t s, node_t t, cap_t c = 1e18)const {
        auto residual_cap = m_graph_cap;
        auto residual_cost = m_graph_cost;
        std::deque<std::pair<cost_t, cap_t>> sl;
        CostV p = shortest_path_allow_minus(s, residual_cap, residual_cost);
        cap_t rem = c;
        while(rem > 0) {
            auto sp = shortest_path(s, residual_cap, m_graph_cost, p);
            auto route = restore_route(t, sp);
            auto [use, cst] = update_residual(s, rem, residual_cap, residual_cost, route);
            if(use == 0) { break; }
            sl.emplace_back(use, cst);
            rem -= use;
            for(int i = 0; i < m_n; ++i) { p[i] += sp[i].first; }
        }
        return sl;
    }

    auto min_cost_max_flow(node_t s, node_t t, cap_t c = 1e18)const {
        cap_t use_all = 0;
        cost_t cost_all = 0;
        for(const auto& [u, c] : slope(s, t, c)) {
            use_all += u; cost_all += c;
        }
        return std::pair<cap_t, cost_t>{use_all, cost_all};
    }
};
