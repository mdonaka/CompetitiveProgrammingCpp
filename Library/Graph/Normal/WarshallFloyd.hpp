#pragma once

#include <vector>

#include "./../Graph.hpp"

template <class Node, class Cost>
auto warshallFloyd(int n, const Graph<Node, Cost>& graph,
                   const Cost& lim = 1LL << 60) {
  std::vector<std::vector<Cost>> cost(n, std::vector<Cost>(n, lim));
  for (const auto& [from, to, c] : graph.getEdges()) { cost[from][to] = c; }
  for (int i = 0; i < n; ++i) { cost[i][i] = 0; }
  for (int k = 0; k < n; ++k) {
    for (int f = 0; f < n; ++f) {
      for (int t = 0; t < n; ++t) {
        cost[f][t] = std::min(cost[f][t], cost[f][k] + cost[k][t]);
      }
    }
  }
  return cost;
}
