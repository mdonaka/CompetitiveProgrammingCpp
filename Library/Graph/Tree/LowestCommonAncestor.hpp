#pragma once
#include <cmath>
#include <vector>

#include "../Graph.hpp"
#include "../Normal/BFS.hpp"

namespace mtd {
  template <class Node, class Cost>
  class LowestCommonAncestor {
    const std::vector<std::vector<Node>> m_parent;
    const std::vector<Node> m_depth;

    static inline auto constructParent(const Graph<Node, Cost>& tree,
                                       const Node& root) {
      auto n = tree.size();
      auto size = static_cast<int>(std::log2(n) + 1);
      std::vector<std::vector<Node>> parent(n, std::vector<Node>(size, root));
      bfs(tree, root, [&](const Node& from, const Node& to, const Cost& _) {
        parent[to][0] = from;
      });
      for (int p2 = 1; p2 < size; ++p2)
        for (int f = 0; f < n; ++f) {
          parent[f][p2] = parent[parent[f][p2 - 1]][p2 - 1];
        }
      return parent;
    }
    static inline auto constructDepth(const Graph<Node, Cost>& tree,
                                      const Node& root) {
      auto n = tree.size();
      std::vector<Node> depth(n);
      bfs(tree, root, [&](const Node& from, const Node& to, const Cost& _) {
        depth[to] = depth[from] + 1;
      });
      return depth;
    }

  public:
    LowestCommonAncestor(const Graph<Node, Cost>& tree, const Node& root)
        : m_parent(constructParent(tree, root)),
          m_depth(constructDepth(tree, root)) {}

    auto lca(Node l, Node r) const {
      int size = m_parent[0].size();
      if (m_depth[l] < m_depth[r]) { std::swap(l, r); }
      for (int k = 0; k < size; ++k) {
        if (((m_depth[l] - m_depth[r]) >> k) & 1) { l = m_parent[l][k]; }
      }
      if (l == r) { return l; }
      for (int k = size - 1; k >= 0; k--) {
        if (m_parent[l][k] != m_parent[r][k]) {
          l = m_parent[l][k];
          r = m_parent[r][k];
        }
      }
      return m_parent[l][0];
    }
  };
}  // namespace mtd
