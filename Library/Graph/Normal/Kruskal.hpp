#pragma once

#include <queue>

#include "./../../DataStructure/DisjointSetUnion.hpp"
#include "./../Graph.hpp"

namespace mtd {
  template <class Node, class Cost>
  auto kruskal(const Graph<Node, Cost>& graph) {
    auto n = graph.size();
    auto min_spanning_tree = Graph<Node, Cost>(n);

    auto dsu = PotentialDisjointSetUnion(n);
    using Type = std::pair<Cost, std::pair<Node, Node>>;
    std::priority_queue<Type, std::vector<Type>, std::greater<Type>> q;
    for (const auto& [f, t, c] : graph.getEdges()) {
      q.emplace(c, std::make_pair(f, t));
    }

    while (!q.empty()) {
      auto [cost, ft] = q.top();
      auto [from, to] = ft;
      q.pop();
      if (dsu.isSame(from, to)) { continue; }
      dsu.unite(from, to);
      min_spanning_tree.addEdge(from, to, cost);
    }

    return min_spanning_tree;
  }
}  // namespace mtd
