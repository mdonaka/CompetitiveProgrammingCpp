#pragma once

#include <deque>
#include <vector>

#include "../../Range/util.hpp"
#include "../Graph.hpp"

namespace mtd {
  template <class Node, class Cost>
  auto topological_order(const mtd::Graph<Node, Cost>& graph) {
    std::vector<Node> cnt(graph.size());
    for (auto [_, v] : graph.getEdgesExcludeCost()) { ++cnt[v]; }

    std::deque<Node> q;
    for (auto [nd, c] : cnt | mtd::views::enumerate) {
      if (c == 0) { q.emplace_back(nd); }
    }

    std::vector<Node> order;
    while (!q.empty()) {
      auto nd = q.front();
      q.pop_front();
      order.emplace_back(nd);
      for (auto [v, _] : graph.getEdges(nd)) {
        --cnt[v];
        if (cnt[v] == 0) { q.emplace_back(v); }
      }
    }
    return order;
  }
}  // namespace mtd
