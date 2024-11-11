#pragma once

#include <queue>

#include "./../Graph.hpp"

namespace mtd {
  template <class Node, class Cost>
  auto prim(const Graph<Node, Cost>& graph) {
    auto n = graph.size();

    Node root = 0;
    Graph<Node, Cost> min_spanning_tree(n);
    using Type = std::pair<Cost, std::pair<Node, Node>>;
    std::priority_queue<Type, std::vector<Type>, std::greater<Type>> q;
    q.emplace(0, std::make_pair(-1, 0));
    std::vector<bool> used(n);
    while (!q.empty()) {
      auto [cost, ft] = q.top();
      auto [from, to] = ft;
      q.pop();
      if (used[to]) { continue; }
      used[to] = true;

      if (from >= 0) { min_spanning_tree.addEdgeUndirected(from, to, cost); }
      for (const auto& [nto, ncost] : graph.getEdges(to)) {
        if (used[nto]) { continue; }
        q.emplace(ncost, std::make_pair(to, nto));
      }
    }
    return min_spanning_tree;
  }
}  // namespace mtd
