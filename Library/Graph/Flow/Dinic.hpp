#pragma once

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>

class Dinic {

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


    using Graph_f = std::unordered_multimap<long long, std::pair<long long, long long>>;
    using Graph = std::unordered_map<std::pair<long long, long long>, long long, HashPair>;

    const long long m_n;
    const Graph m_graph;
    const std::vector<std::unordered_set<long long>> m_to_list;

    static auto construct_to_list(long long n, const Graph_f& graph_f) {
        std::vector<std::unordered_set<long long>> to_list(n);
        for(const auto& [f, tc] : graph_f) {
            auto [t, c] = tc;
            to_list[f].emplace(t);
            to_list[t].emplace(f);
        }
        return to_list;
    }
    static auto construct_graph(const Graph_f& graph_f) {
        Graph graph;
        for(const auto& [f, tc] : graph_f) {
            auto [t, c] = tc;
            graph[std::pair<long long, long long>{f, t}] += c;
        }
        return graph;
    }

    auto get_depth(long long s, const Graph& graph) const {
        std::vector<long long> depth(m_n, -1);
        std::queue<long long> q;
        q.emplace(s);
        depth[s] = 0;
        while(!q.empty()) {
            long long from = q.front();
            q.pop();
            for(const auto& to : m_to_list[from]) {
                if(graph.find({from, to}) == graph.end()) { continue; }
                if(depth[to] > -1) { continue; }
                depth[to] = depth[from] + 1;
                q.emplace(to);
            }
        }
        return depth;
    }

    auto update_residual(long long s, Graph& residual, const std::list<long long>& route)const {
        long long mn = 1e18;
        long long from = s;
        for(const auto& to : route)if(from != to) {
            mn = std::min(mn, residual[{from, to}]);
            from = to;
        }

        from = s;
        for(const auto& to : route)if(from != to) {
            auto& ft = residual[{from, to}];
            long long use = ft - mn;
            ft -= mn;
            if(ft == 0) { residual.erase({from,to}); }
            residual[{to, from}] += mn;
            from = to;
        }
    }
    auto construct_residual(long long s, long long t)const {
        auto residual = m_graph;
        while(true) {
            // BFS
            auto depth = get_depth(s, residual);

            // DFS
            bool run = false;
            std::vector<long long> visited(m_n);
            auto f = [&](auto&& f, long long now, std::list<long long>& route)->void {
                route.emplace_back(now);

                // tに到達していれば流す
                if(now == t) { update_residual(s, residual, route); run = true; }

                for(const auto& to : m_to_list[now]) {
                    if(residual.find({now, to}) == residual.end()) { continue; }
                    if(depth[to] <= depth[now]) { continue; }
                    if(visited[to]) { continue; }
                    visited[to] = true;;
                    f(f, to, route);
                }
                route.pop_back();
            };
            std::list<long long> route;
            visited[s] = true;
            f(f, s, route);
            if(!run) { break; }
        }
        return residual;
    }

public:
    Dinic(long long n, const Graph_f& graph) :
        m_n(n),
        m_graph(construct_graph(graph)),
        m_to_list(construct_to_list(n, graph)) {
    }

    auto max_flow(long long s, long long t)const {
        auto residual = construct_residual(s, t);

        long long val = 0;
        for(const auto& to : m_to_list[s]) {
            if(m_graph.find({s,to}) == m_graph.end()) { continue; }
            val += m_graph.at({s, to}) - residual[{s, to}];
        }
        return val;
    }

    auto get_cut_list(long long s, long long t) const {
        // 残余グラフで始点から到達できる集合
        std::unordered_set<long long> st;

        auto residual = construct_residual(s, t);
        std::queue<long long> q;
        auto add = [&](long long t) {
            if(st.find(t) != st.end()) { return; }
            q.emplace(t);
            st.emplace(t);
        };
        add(s);
        std::deque<long long> ans;
        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            for(const auto& t : m_to_list[f]) {
                if(residual.find({f,t}) == residual.end()) { continue; }
                add(t);
            }
        }

        std::deque<std::pair<long long, long long>> cut;
        for(const auto& f : st) for(const auto& t : m_to_list[f]) {
            if(st.find(t) == st.end() &&
               m_graph.find({f,t}) != m_graph.end()) {
                cut.emplace_back(f, t);
            }
        }

        return cut;
    }

    auto get_edge(long long s, long long t)const {
        auto residual = construct_residual(s, t);

        Graph_f edge;
        for(long long from = 0; from < m_n; ++from) {
            for(const auto& to : m_to_list[from]) {
                if(m_graph.find({from,to}) == m_graph.end()) { continue; }
                auto val = m_graph.at({from, to}) - residual[{from, to}];
                if(val > 0) { edge.emplace(from, std::pair<long long, long long>{to, val}); }
            }
        }
        return edge;

    }
};