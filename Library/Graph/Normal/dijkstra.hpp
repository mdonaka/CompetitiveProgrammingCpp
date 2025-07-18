#pragma once

#include <concepts>
#include <queue>
#include <vector>

#include "../Graph.hpp"

namespace mtd {
  template <class Node, class Cost, std::convertible_to<Node> _Node>
  auto dijkstra(const Graph<Node, Cost>& graph, const _Node& begin,
                const Cost& lim = 1LL << 62) {
    std::vector<Cost> cost(graph.size(), lim);
    cost[begin] = 0;

    using P = std::pair<Cost, Node>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> q;
    q.emplace(cost[begin], begin);
    while (!q.empty()) {
      auto [now_cost, from] = q.top();
      q.pop();
      if (cost[from] < now_cost) { continue; }
      for (const auto& [to, c] : graph.getEdges(from)) {
        if (now_cost + c < cost[to]) {
          cost[to] = now_cost + c;
          q.emplace(cost[to], to);
        }
      }
    }
    return cost;
  }
}  // namespace mtd
