#pragma once

#include <list>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "./../Graph.hpp"

namespace mtd {
  template <class Node, class Cost>
  class FordFulkerson {
    // using Node = int;
    // using Cost = int;

    struct HashPair {
      template <class T1, class T2>
      size_t operator()(const std::pair<T1, T2>& p) const {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        size_t seed = 0;
        seed ^= hash1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= hash2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        return seed;
      }
    };

    using PairGraph = std::unordered_map<std::pair<Node, Node>, Cost, HashPair>;

    const Node m_n;
    const PairGraph m_graph;
    const std::vector<std::unordered_set<Node>> m_to_list;

    static auto construct_to_list(const Graph<Node, Cost>& graph) {
      std::vector<std::unordered_set<Node>> to_list(graph.size());
      for (const auto& [f, t, c] : graph.getEdges()) {
        to_list[f].emplace(t);
        to_list[t].emplace(f);
      }
      return to_list;
    }
    static auto construct_graph(const Graph<Node, Cost>& graph) {
      PairGraph pair_graph;
      for (const auto& [f, t, c] : graph.getEdges()) {
        pair_graph[std::pair<Node, Node>{f, t}] += c;
      }
      return pair_graph;
    }

    auto get_route(Node s, Node t, const PairGraph& graph) const {
      std::unordered_set<Node> visited;
      auto f = [&](auto&& self, Node now, std::list<Node>& route) -> bool {
        route.emplace_back(now);
        for (const auto& to : m_to_list[now]) {
          if (graph.find({now, to}) == graph.end()) { continue; }
          if (to == t) {
            route.emplace_back(t);
            return true;
          }
          if (visited.find(to) == visited.end()) {
            visited.emplace(to);
            if (self(self, to, route)) { return true; }
          }
        }
        route.pop_back();
        return false;
      };
      std::list<Node> route;
      visited.emplace(s);
      auto ok = f(f, s, route);
      if (ok) {
        return route;
      } else {
        return std::list<Node>{};
      }
    }

    auto construct_residual(Node s, Node t) const {
      auto residual = m_graph;
      while (true) {
        auto route = get_route(s, t, residual);
        if (route.empty()) { break; }

        Cost mn = 1e9;
        Node from = s;
        for (const auto& to : route)
          if (from != to) {
            mn = std::min(mn, residual[{from, to}]);
            from = to;
          }

        from = s;
        for (const auto& to : route)
          if (from != to) {
            auto& ft = residual[{from, to}];
            ft -= mn;
            if (ft == 0) { residual.erase({from, to}); }
            residual[{to, from}] += mn;
            from = to;
          }
      }
      return residual;
    }

  public:
    FordFulkerson(const Graph<Node, Cost>& graph)
        : m_n(graph.size()),
          m_graph(construct_graph(graph)),
          m_to_list(construct_to_list(graph)) {}

    auto max_flow(Node s, Node t) const {
      auto residual = construct_residual(s, t);

      Cost val = 0;
      for (const auto& to : m_to_list[s]) {
        if (m_graph.find({s, to}) == m_graph.end()) { continue; }
        val += m_graph.at({s, to}) - residual[{s, to}];
      }
      return val;
    }

    auto get_cut_list(Node s, Node t) const {
      // 残余グラフで始点から到達できる集合
      std::unordered_set<Node> st;

      auto residual = construct_residual(s, t);
      std::queue<Node> q;
      auto add = [&](Node to) {
        if (st.find(to) != st.end()) { return; }
        q.emplace(to);
        st.emplace(to);
      };
      add(s);
      std::deque<Node> ans;
      while (!q.empty()) {
        auto from = q.front();
        q.pop();
        for (const auto& to : m_to_list[from]) {
          if (residual.find({from, to}) == residual.end()) { continue; }
          add(to);
        }
      }

      std::deque<std::pair<Node, Node>> cut;
      for (const auto& from : st)
        for (const auto& to : m_to_list[from]) {
          if (st.find(to) == st.end() &&
              m_graph.find({from, to}) != m_graph.end()) {
            cut.emplace_back(from, to);
          }
        }

      return cut;
    }

    auto get_edge(Node s, Node t) const {
      auto residual = construct_residual(s, t);

      auto edge = Graph<Node, Cost>(m_n);
      for (Node from = 0; from < m_n; ++from) {
        for (const auto& to : m_to_list[from]) {
          if (m_graph.find({from, to}) == m_graph.end()) { continue; }
          auto val = m_graph.at({from, to}) - residual[{from, to}];
          if (val > 0) { edge.addEdge(from, to, val); }
        }
      }
      return edge;
    }
  };
}  // namespace mtd
