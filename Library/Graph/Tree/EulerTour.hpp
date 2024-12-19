#pragma once

#include <stack>
#include <vector>

#include "../Graph.hpp"

namespace mtd {

  template <class Node, class Cost>
  class EulerTour {
    const std::vector<Node> m_tour;
    const std::vector<std::pair<int, int>> m_appear;

    auto constructTour(const Graph<Node, Cost>& tree, Node root) const {
      auto n = tree.size();
      std::vector<Node> tour;
      std::stack<Node> stk;
      std::vector<int> used(n);
      stk.emplace(root);
      while (!stk.empty()) {
        auto from = stk.top();
        tour.emplace_back(from);
        stk.pop();
        if (used[from]) { continue; }
        stk.emplace(from);
        used[from] = true;

        for (auto [to, _] : tree.getEdges(from)) {
          if (!used[to]) { stk.emplace(to); }
        }
      }
      return tour;
    }
    auto constructAppear(int n) const {
      std::vector<std::pair<int, int>> appear(n, {-1, -1});
      for (int i = 0; i < 2 * n; ++i) {
        if (appear[m_tour[i]].first == -1) {
          appear[m_tour[i]].first = i;
        } else {
          appear[m_tour[i]].second = i;
        }
      }
      return appear;
    }

  public:
    EulerTour(const Graph<Node, Cost>& tree, Node root = 0)
        : m_tour(constructTour(tree, root)),
          m_appear(constructAppear(tree.size())) {}

    auto lessOrder(int li, int ri) const {
      return m_appear[li].first < m_appear[ri].first;
    }
    auto isSon(Node son, Node parent) {
      return m_appear[parent].first < m_appear[son].first &&
             m_appear[son].second < m_appear[parent].second;
    }
    auto range(Node u) const { return m_appear[u]; }
  };
}  // namespace mtd
