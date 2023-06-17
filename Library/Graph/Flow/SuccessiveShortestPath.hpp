#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>

#include "./../Graph.hpp"

using Node = int;
using Cap = long long;
using Cost = long long;


class SuccessiveShortestPath {

    using GraphInput = Graph<Node, std::pair<Cost, Cap>>;

    using GraphTo = std::vector<std::deque<Node>>;
    using CapV = std::vector<Cost>;
    using GraphCap = std::vector<CapV>;
    using CostV = std::vector<Cost>;
    using GraphCost = std::vector<CostV>;

    const int m_n;
    const GraphTo m_graph_to;
    const GraphCap m_graph_cap;
    const GraphCost m_graph_cost;

    auto construct_graph_to(const GraphInput& graph)const {
        GraphTo graphTo(m_n);
        for(const auto& [f, t] : graph.getEdgesAll2()) {
            graphTo[f].emplace_back(t);
            graphTo[t].emplace_back(f);
        }
        return graphTo;
    }

    auto construct_graph_cap(const GraphInput& graph)const {
        GraphCap graph_cap(m_n, CapV(m_n));
        for(const auto& [f, tcc] : graph.getEdgesAll()) {
            auto [t, cc] = tcc;
            auto [cap, _] = cc;
            graph_cap[f][t] += cap;
        }
        return graph_cap;
    }
    auto construct_graph_cost(const GraphInput& graph) const {
        GraphCost graph_cost(m_n, CostV(m_n));
        for(const auto& [f, tcc] : graph.getEdgesAll()) {
            auto [t, cc] = tcc;
            auto [_, cost] = cc;
            graph_cost[f][t] = cost;
            graph_cost[t][f] = -cost;
        }
        return graph_cost;
    }

    auto update_residual(Node s, Cap rem,
                         GraphCap& residual_cap, GraphCost& residual_cost,
                         const std::deque<Node>& route)const {
        Cost mn = rem;
        auto from = s;
        for(const auto& to : route)if(from != to) {
            mn = std::min(mn, residual_cap[from][to]);
            from = to;
        }

        Cost cost_all = 0;
        from = s;
        for(const auto& to : route)if(from != to) {
            residual_cap[from][to] -= mn;
            residual_cap[to][from] += mn;
            cost_all += mn * residual_cost[from][to];
            from = to;
        }
        return std::pair<Cap, Cost>{mn, cost_all};
    }

    auto shortest_path_allow_minus(Node s,
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

    auto shortest_path(Node s,
                       const GraphCap& residual_cap,
                       const GraphCost& residual_cost,
                       const std::vector<Cost>& p) const {
        using P = std::pair<Cost, Node>;
        std::priority_queue<P, std::vector<P>, std::greater<P>> q;
        std::vector<std::pair<Cost, Node>> min(m_n, {1e18,-1});
        auto add = [&](Node node, Cost cst, Node from) {
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

    static auto restore_route(int t, const std::vector<std::pair<Cost, Node>>& sp) {
        std::deque<Node> route;
        auto now = t;
        while(now > -1) {
            route.emplace_front(now);
            now = sp[now].second;
        }
        return route;
    }
public:
    /* 単純グラフを仮定 */
    SuccessiveShortestPath(const GraphInput& graph) :
        m_n(graph.size()),
        m_graph_to(construct_graph_to(graph)),
        m_graph_cap(construct_graph_cap(graph)),
        m_graph_cost(construct_graph_cost(graph)) {
    }

    auto slope(Node s, Node t, Cap c = 1e18)const {
        auto residual_cap = m_graph_cap;
        auto residual_cost = m_graph_cost;
        std::deque<std::pair<Cost, Cap>> sl;
        CostV p = shortest_path_allow_minus(s, residual_cap, residual_cost);
        Cap rem = c;
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

    auto min_cost_max_flow(Node s, Node t, Cap c = 1e18)const {
        Cap use_all = 0;
        Cost cost_all = 0;
        for(const auto& [u, c] : slope(s, t, c)) {
            use_all += u; cost_all += c;
        }
        return std::pair<Cap, Cost>{use_all, cost_all};
    }
};
