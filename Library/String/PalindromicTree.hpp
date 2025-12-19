#pragma once
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>

namespace mtd {
  class PalindromicTree {
    struct Node {
      int size;
      int suffix_link;
      int first_itr = -1;
      std::vector<std::pair<char, int>> edges;
      std::vector<int> rest_itrs;

      Node(int s, int sl) : size(s), suffix_link(sl) {}

      auto find_edge(char c) const -> int {
        for (const auto& [ch, idx] : edges) {
          if (ch == c) { return idx; }
        }
        return -1;
      }

      auto add_edge(char c, int idx) -> void { edges.emplace_back(c, idx); }

      auto add_itr(int itr) -> void {
        if (first_itr == -1) {
          first_itr = itr;
        } else {
          rest_itrs.push_back(itr);
        }
      }

      auto get_itrs() const -> std::vector<int> {
        if (first_itr == -1) { return {}; }
        std::vector<int> result;
        result.reserve(1 + rest_itrs.size());
        result.push_back(first_itr);
        result.insert(result.end(), rest_itrs.begin(), rest_itrs.end());
        return result;
      }
    };

    const std::string m_s;
    std::vector<Node> m_nodes;
    static constexpr int ROOT_ODD = 0;
    static constexpr int ROOT_EVEN = 1;

    auto find(int node_idx, int itr) const -> int {
      while (true) {
        int size = m_nodes[node_idx].size;
        if (size == -1) { return node_idx; }
        if (itr - size - 1 >= 0 && m_s[itr] == m_s[itr - size - 1]) {
          return node_idx;
        }
        node_idx = m_nodes[node_idx].suffix_link;
      }
    }

    auto add(int node_idx, int itr) -> int {
      int add_root = find(node_idx, itr);
      char c = m_s[itr];

      int existing = m_nodes[add_root].find_edge(c);
      if (existing != -1) {
        m_nodes[existing].add_itr(itr);
        return existing;
      }

      int new_size = m_nodes[add_root].size + 2;
      int suffix_link_from = find(m_nodes[add_root].suffix_link, itr);

      int new_suffix_link = m_nodes[suffix_link_from].find_edge(c);
      if (new_suffix_link == -1) { new_suffix_link = ROOT_EVEN; }

      int new_idx = static_cast<int>(m_nodes.size());
      m_nodes.emplace_back(new_size, new_suffix_link);
      m_nodes[new_idx].add_itr(itr);
      m_nodes[add_root].add_edge(c, new_idx);

      return new_idx;
    }

  public:
    PalindromicTree(const std::string& s) : m_s(s) {
      m_nodes.reserve(s.size() + 2);
      m_nodes.emplace_back(-1, ROOT_ODD);
      m_nodes.emplace_back(0, ROOT_ODD);

      int cur = ROOT_ODD;
      for (int i = 0; i < static_cast<int>(s.size()); ++i) { cur = add(cur, i); }

      m_nodes.shrink_to_fit();
      for (auto& node : m_nodes) {
        node.edges.shrink_to_fit();
        node.rest_itrs.shrink_to_fit();
      }
    }

    template <class Lambda>
    auto dfs_edges(const Lambda& lambda) const -> void {
      std::stack<int, std::vector<int>> stk;
      stk.push(ROOT_ODD);
      stk.push(ROOT_EVEN);

      while (!stk.empty()) {
        int idx = stk.top();
        stk.pop();

        const auto& node = m_nodes[idx];
        if (node.size > 0) { lambda(node.size, node.get_itrs()); }

        for (const auto& [_, next_idx] : node.edges) { stk.push(next_idx); }
      }
    }

    template <class Lambda>
    auto dp_suffixLink(const Lambda& lambda) const -> void {
      std::vector<int> order_count(m_s.size(), 0);
      std::vector<std::vector<int>> graph(m_s.size());

      for (int idx = 2; idx < static_cast<int>(m_nodes.size()); ++idx) {
        const auto& node = m_nodes[idx];
        if (node.first_itr == -1) { continue; }

        int from = node.first_itr;
        int sl_idx = node.suffix_link;
        if (sl_idx >= 2 && m_nodes[sl_idx].first_itr != -1) {
          int to = m_nodes[sl_idx].first_itr;
          graph[from].push_back(to);
          ++order_count[to];
        }
      }

      std::queue<int> q;
      for (int i = 0; i < static_cast<int>(m_s.size()); ++i) {
        if (order_count[i] == 0) { q.push(i); }
      }

      while (!q.empty()) {
        int f = q.front();
        q.pop();
        for (int t : graph[f]) {
          --order_count[t];
          lambda(f, t);
          if (order_count[t] == 0) { q.push(t); }
        }
      }
    }
  };
}  // namespace mtd
