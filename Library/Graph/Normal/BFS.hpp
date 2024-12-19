#pragma once

#include <queue>
#include <vector>

#include "./../Graph.hpp"

namespace mtd {
  template <class Node, class Cost, class Lambda>
  auto bfs(const Graph<Node, Cost>& graph, const Node& root,
           const Lambda& lambda) {
    auto n = graph.size();
    std::vector<bool> used(n);
    used[root] = true;
    std::queue<Node> q;
    q.emplace(root);
    while (!q.empty()) {
      auto from = q.front();
      q.pop();
      for (const auto& [to, cost] : graph.getEdges(from)) {
        if (used[to]) { continue; }
        q.emplace(to);
        used[to] = true;
        lambda(from, to, cost);
      }
    }
  }
}  // namespace mtd
