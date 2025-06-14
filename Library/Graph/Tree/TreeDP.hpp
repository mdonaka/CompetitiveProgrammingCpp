#pragma once

#include <concepts>
#include <queue>
#include <vector>

#include "./../Graph.hpp"

namespace mtd {
  template <class Node, class Cost, class Lambda,
            std::convertible_to<Node> _Node>
  auto treeDP(const Graph<Node, Cost>& tree, _Node root, const Lambda& lambda) {
    auto n = tree.size();
    std::vector<Node> in(n);
    for (const auto& [f, t] : tree.getEdgesExcludeCost())
      if (f < t) {
        ++in[f];
        ++in[t];
      }
    std::queue<Node> q;
    std::vector<bool> used(n);
    for (Node i = 0; i < n; ++i)
      if (i != root && in[i] == 1) { q.emplace(i); }
    while (!q.empty()) {
      auto from = q.front();
      q.pop();
      used[from] = true;

      for (const auto& [to, cost] : tree.getEdges(from)) {
        if (used[to]) { continue; }
        lambda(from, to, cost);
        --in[to];
        if (to != root && in[to] == 1) { q.emplace(to); }
      }
    }
  }
}  // namespace mtd
