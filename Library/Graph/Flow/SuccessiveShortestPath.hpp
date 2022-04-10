#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>

class SuccessiveShortestPath {

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

    using node_t = long long;
    using cap_t = long long;
    using cost_t = long long;


    using Graph_f = std::unordered_multimap<node_t, std::pair<node_t, std::pair<cap_t, cost_t>>>;
    using Graph = std::unordered_map<std::pair<node_t, node_t>, std::pair<cap_t, cost_t>, HashPair>;

    const int m_n;
    const Graph m_graph;
    const std::vector<std::unordered_set<node_t>> m_to_list;

    static auto construct_to_list(int n, const Graph_f& graph_f) {
        std::vector<std::unordered_set<node_t>> to_list(n);
        for(const auto& [f, tcc] : graph_f) {
            auto [t, _] = tcc;
            to_list[f].emplace(t);
            to_list[t].emplace(f);
        }
        return to_list;
    }
    static auto construct_graph(const Graph_f& graph_f) {
        Graph graph;
        for(const auto& [f, tcc] : graph_f) {
            auto [t, cc] = tcc;
            auto [cap, cost] = cc;
            graph[std::pair<node_t, node_t>{f, t}].first += cap;
            // TODO: costは単に加算するのでは良くないので要修正
            graph[std::pair<node_t, node_t>{f, t}].second += cost;
        }
        return graph;
    }

    auto update_residual(node_t s, cap_t rem, Graph& residual, const std::deque<node_t>& route)const {
        cost_t mn = rem;
        auto from = s;
        for(const auto& to : route)if(from != to) {
            mn = std::min(mn, residual[{from, to}].first);
            from = to;
        }

        cost_t cost_all = 0;
        from = s;
        for(const auto& to : route)if(from != to) {
            auto& [ft, cst] = residual[{from, to}];
            ft -= mn;
            cost_all += mn * cst;
            residual[{to, from}].first += mn;
            residual[{to, from}].second = -cst;
            if(ft == 0) { residual.erase({from,to}); }
            from = to;
        }
        return std::pair<cap_t, cost_t>{mn, cost_all};
    }

    auto shortest_path(node_t s, node_t t, const Graph& graph) const {
        std::priority_queue<std::pair<cost_t, node_t>> q;
        std::vector<std::pair<cost_t, node_t>> min(m_n, {1e18,-1});
        auto add = [&](node_t node, cost_t cst, node_t from) {
            if(cst >= min[node].first) { return; }
            if(cst < 0) { return; }
            min[node].first = cst;
            min[node].second = from;
            q.emplace(cst, node);
        };
        add(s, 0, -1);
        while(!q.empty()) {
            auto [nowCost, from] = q.top();
            q.pop();
            if(min[from].first < nowCost) { continue; }
            for(const auto& to : m_to_list[from]) {
                auto find_it = graph.find({from,to});
                if(find_it == graph.end()) { continue; }
                add(to, nowCost + find_it->second.second, from);
            }
        }
        if(min[t].second == -1) { return std::deque<node_t>{}; }
        std::deque<node_t> route;
        auto now = t;
        while(now > -1) {
            route.emplace_front(now);
            now = min[now].second;
        }
        return route;
    }

public:
    SuccessiveShortestPath(int n, const Graph_f& graph) :
        m_n(n),
        m_graph(construct_graph(graph)),
        m_to_list(construct_to_list(n, graph)) {
    }

    auto output(const Graph& graph)const {
        std::cout << "-- graph --" << std::endl;
        for(const auto& [p, c] : graph) {
            std::cout
                << "(" << p.first << " -> " << p.second << "): ("
                << c.first << ", " << c.second << std::endl;
        }
    }

    auto min_cost_max_flow(node_t s, node_t t, cap_t c = 1e18)const {
        auto residual = m_graph;
        cost_t cost_all = 0;
        cap_t rem = c;
        while(rem > 0) {
            auto route = shortest_path(s, t, residual);
            if(route.empty()) { break; }
            auto [use, cst] = update_residual(s, rem, residual, route);
            cost_all += cst;
            rem -= use;
        }
        return std::pair<cap_t, cost_t>{c - rem, cost_all};
    }

};