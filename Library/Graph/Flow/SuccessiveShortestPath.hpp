#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>

#include "./../Graph.hpp"

template<class Node, class Cap, class Cost>
class SuccessiveShortestPath {

    using GraphCap = std::vector<std::vector<Cap>>;
    using GraphCost = std::vector<std::vector<Cost>>;

    const Graph<Node, std::pair<Cap, Cost>> m_graph;

    auto construct_graph_cap()const {
        auto n = m_graph.size();
        GraphCap graph_cap(n, std::vector<Cap>(n));
        for(const auto& [f, tcc] : m_graph.getEdgesAll()) {
            auto [t, cc] = tcc;
            auto [cap, _] = cc;
            graph_cap[f][t] += cap;
        }
        return graph_cap;
    }
    auto construct_graph_cost() const {
        auto n = m_graph.size();
        GraphCost graph_cost(n, std::vector<Cost>(n));
        for(const auto& [f, tcc] : m_graph.getEdgesAll()) {
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
        auto n = m_graph.size();
        std::vector<Cost> cost(n, 1e18);
        cost[s] = 0;
        for(int _ = 0; _ < n; ++_) {
            for(int from = 0; from < n; ++from) {
                for(const auto& [to, _] : m_graph.getEdges(from)) {
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
        std::vector<std::pair<Cost, Node>> min(m_graph.size(), {1e18,-1});
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
            for(const auto& [to, _] : m_graph.getEdges(from)) {
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
    SuccessiveShortestPath(const Graph<Node, std::pair<Cost, Cap>>& graph) :
        m_graph(graph) {
    }

    auto slope(Node s, Node t, Cap c = 1e18)const {
        auto residual_cap = construct_graph_cap();
        auto residual_cost = construct_graph_cost();
        auto default_cost = residual_cost;
        std::deque<std::pair<Cost, Cap>> sl;
        auto p = shortest_path_allow_minus(s, residual_cap, residual_cost);
        auto rem = c;
        while(rem > 0) {
            auto sp = shortest_path(s, residual_cap, default_cost, p);
            auto route = restore_route(t, sp);
            auto [use, cst] = update_residual(s, rem, residual_cap, residual_cost, route);
            if(use == 0) { break; }
            sl.emplace_back(use, cst);
            rem -= use;
            for(int i = 0; i < m_graph.size(); ++i) { p[i] += sp[i].first; }
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
