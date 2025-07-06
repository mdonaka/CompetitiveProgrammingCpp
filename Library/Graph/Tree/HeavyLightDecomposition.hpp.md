---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Graph.hpp
    title: Library/Graph/Graph.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Tree/AuxiliaryTree.hpp
    title: Library/Graph/Tree/AuxiliaryTree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Graph/Tree/AuxiliaryTree.test.cpp
    title: Test/Graph/Tree/AuxiliaryTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Graph/Tree/HeavyLightDecomposition_LCA.test.cpp
    title: Test/Graph/Tree/HeavyLightDecomposition_LCA.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Graph/Tree/HeavyLightDecomposition_edge.test.cpp
    title: Test/Graph/Tree/HeavyLightDecomposition_edge.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Graph/Tree/HeavyLightDecomposition.hpp\"\n\r\n#include\
    \ <queue>\r\n#include <stack>\r\n#include <unordered_map>\r\n\r\n#line 2 \"Library/Graph/Graph.hpp\"\
    \n#include <deque>\r\n#include <iostream>\r\n#include <ranges>\r\n#include <tuple>\r\
    \n#include <vector>\r\n\r\nnamespace mtd {\r\n  template <class Node = long long,\
    \ class Cost = long long>\r\n  class Graph {\r\n    using Edge = std::pair<Node,\
    \ Cost>;\r\n    using Edges = std::vector<Edge>;\r\n\r\n    const int m_n;\r\n\
    \    std::vector<Edges> m_graph;\r\n\r\n  public:\r\n    Graph(int n) : m_n(n),\
    \ m_graph(n) {}\r\n    Graph(const std::vector<Edges>& edges)\r\n        : m_n(edges.size()),\
    \ m_graph(edges) {}\r\n    Graph(int n, const std::vector<std::tuple<Node, Node>>&\
    \ edges,\r\n          bool is_arc = false, bool is_index1 = true)\r\n        :\
    \ Graph<Node, Cost>(n) {\r\n      for (auto [u, v] : edges) {\r\n        u -=\
    \ is_index1;\r\n        v -= is_index1;\r\n        if (is_arc) {\r\n         \
    \ addArc(u, v);\r\n        } else {\r\n          addEdge(u, v);\r\n        }\r\
    \n      }\r\n    }\r\n    Graph(int n, const std::vector<std::tuple<Node, Node,\
    \ Cost>>& edges,\r\n          bool is_arc = false, bool is_index1 = true)\r\n\
    \        : Graph<Node, Cost>(n) {\r\n      for (auto [u, v, c] : edges) {\r\n\
    \        u -= is_index1;\r\n        v -= is_index1;\r\n        if (is_arc) {\r\
    \n          addArc(u, v, c);\r\n        } else {\r\n          addEdge(u, v, c);\r\
    \n        }\r\n      }\r\n    }\r\n\r\n    auto addEdge(const Node& f, const Node&\
    \ t, const Cost& c = 1) {\r\n      addArc(f, t, c);\r\n      addArc(t, f, c);\r\
    \n    }\r\n    auto addArc(const Node& f, const Node& t, const Cost& c = 1) {\r\
    \n      m_graph[f].emplace_back(t, c);\r\n    }\r\n    auto getEdges(const Node&\
    \ from) const {\r\n      class EdgesRange {\r\n        const typename Edges::const_iterator\
    \ b, e;\r\n\r\n      public:\r\n        EdgesRange(const Edges& edges) : b(edges.begin()),\
    \ e(edges.end()) {}\r\n        auto begin() const { return b; }\r\n        auto\
    \ end() const { return e; }\r\n      };\r\n      return EdgesRange(m_graph[from]);\r\
    \n    }\r\n    auto getEdges() const {\r\n      std::deque<std::tuple<Node, Node,\
    \ Cost>> edges;\r\n      for (Node from : std::views::iota(0, m_n)) {\r\n    \
    \    for (const auto& [to, c] : getEdges(from)) {\r\n          edges.emplace_back(from,\
    \ to, c);\r\n        }\r\n      }\r\n      return edges;\r\n    }\r\n    auto\
    \ getEdgesExcludeCost() const {\r\n      std::deque<std::pair<Node, Node>> edges;\r\
    \n      for (Node from : std::views::iota(0, m_n)) {\r\n        for (const auto&\
    \ [to, _] : getEdges(from)) {\r\n          edges.emplace_back(from, to);\r\n \
    \       }\r\n      }\r\n      return edges;\r\n    }\r\n    auto reverse() const\
    \ {\r\n      auto rev = Graph<Node, Cost>(m_n);\r\n      for (const auto& [from,\
    \ to, c] : getEdges()) { rev.addArc(to, from, c); }\r\n      return rev;\r\n \
    \   }\r\n    auto size() const { return m_n; };\r\n    auto debug(bool directed\
    \ = false) const {\r\n      for (const auto& [f, t, c] : getEdges()) {\r\n   \
    \     if (f < t || directed) {\r\n          std::cout << f << \" -> \" << t <<\
    \ \": \" << c << std::endl;\r\n        }\r\n      }\r\n    }\r\n  };\r\n}  //\
    \ namespace mtd\r\n#line 8 \"Library/Graph/Tree/HeavyLightDecomposition.hpp\"\n\
    \r\nnamespace mtd {\r\n  template <class Node, class Cost>\r\n  class HeavyLightDecomposition\
    \ {\r\n    using GraphOrderd = std::unordered_map<Node, std::deque<Node>>;\r\n\
    \r\n    const Node m_n;\r\n    const std::vector<Node> m_size;\r\n    const GraphOrderd\
    \ m_tree;\r\n    const std::vector<Node> m_height;\r\n    const std::vector<std::pair<Node,\
    \ Node>> m_root_par;\r\n    const std::vector<Node> m_ids;\r\n    const std::vector<Node>\
    \ m_order;\r\n    const std::vector<Node> m_edge_ids;\r\n\r\n    static auto constructGraph(const\
    \ Graph<Node, Cost>& tree) {\r\n      auto n = tree.size();\r\n      std::deque<std::pair<Node,\
    \ Node>> order;\r\n      std::vector<Node> used(n);\r\n      std::stack<std::pair<Node,\
    \ Node>> stk;\r\n      stk.emplace(0, -1);\r\n      used[0] = true;\r\n      while\
    \ (!stk.empty()) {\r\n        auto [f, p] = stk.top();\r\n        order.emplace_front(f,\
    \ p);\r\n        stk.pop();\r\n        for (const auto& [t, _] : tree.getEdges(f))\
    \ {\r\n          if (used[t]) {\r\n            continue;\r\n            ;\r\n\
    \          }\r\n          used[t] = true;\r\n          stk.emplace(t, f);\r\n\
    \        }\r\n      }\r\n\r\n      std::vector<Node> size(n, 1);\r\n      GraphOrderd\
    \ hld_tree;\r\n      for (const auto& [f, p] : order) {\r\n        Node size_sum\
    \ = 1;\r\n        Node size_max = 0;\r\n        std::deque<Node> to_list;\r\n\
    \        for (const auto& [t, _] : tree.getEdges(f)) {\r\n          if (t == p)\
    \ { continue; }\r\n          if (size[t] > size_max) {\r\n            size_max\
    \ = size[t];\r\n            to_list.emplace_back(t);\r\n          } else {\r\n\
    \            to_list.emplace_front(t);\r\n          }\r\n          size_sum +=\
    \ size[t];\r\n        }\r\n        if (!to_list.empty()) { hld_tree.emplace(f,\
    \ to_list); }\r\n        size[f] = size_sum;\r\n      }\r\n      return hld_tree;\r\
    \n    }\r\n\r\n    static auto constructSize(const Graph<Node, Cost>& tree) {\r\
    \n      auto n = tree.size();\r\n      std::deque<std::pair<Node, Node>> order;\r\
    \n      std::vector<Node> used(n);\r\n      std::stack<std::pair<Node, Node>>\
    \ stk;\r\n      stk.emplace(0, -1);\r\n      used[0] = true;\r\n      while (!stk.empty())\
    \ {\r\n        auto [f, p] = stk.top();\r\n        order.emplace_front(f, p);\r\
    \n        stk.pop();\r\n        for (const auto& [t, _] : tree.getEdges(f)) {\r\
    \n          if (used[t]) {\r\n            continue;\r\n            ;\r\n     \
    \     }\r\n          used[t] = true;\r\n          stk.emplace(t, f);\r\n     \
    \   }\r\n      }\r\n\r\n      std::vector<Node> size(n, 1);\r\n      for (const\
    \ auto& [f, p] : order) {\r\n        Node size_sum = 1;\r\n        for (const\
    \ auto& [t, _] : tree.getEdges(f)) {\r\n          if (t == p) { continue; }\r\n\
    \          size_sum += size[t];\r\n        }\r\n        size[f] = size_sum;\r\n\
    \      }\r\n      return size;\r\n    }\r\n\r\n    static auto constructRootPar(Node\
    \ n, const GraphOrderd& tree) {\r\n      std::vector<std::pair<Node, Node>> root_par(n);\r\
    \n      std::stack<std::tuple<Node, Node, Node>> stk;\r\n      stk.emplace(0,\
    \ 0, -1);\r\n      while (!stk.empty()) {\r\n        auto [f, root, par] = stk.top();\r\
    \n        stk.pop();\r\n\r\n        if (tree.find(f) == tree.end()) {\r\n    \
    \      root_par[f] = {root, par};\r\n          continue;\r\n        }\r\n    \
    \    auto itr = tree.at(f).rbegin();\r\n        stk.emplace(*itr, root, par);\r\
    \n        root_par[f] = {root, par};\r\n        for (++itr; itr != tree.at(f).rend();\
    \ ++itr) {\r\n          stk.emplace(*itr, *itr, f);\r\n        }\r\n      }\r\n\
    \      return root_par;\r\n    }\r\n    static auto constructHeight(Node n, const\
    \ GraphOrderd& tree) {\r\n      std::vector<Node> height(n);\r\n      std::queue<Node>\
    \ q;\r\n      q.emplace(0);\r\n      while (!q.empty()) {\r\n        auto f =\
    \ q.front();\r\n        q.pop();\r\n        if (tree.find(f) == tree.end()) {\
    \ continue; }\r\n        for (const auto& t : tree.at(f)) {\r\n          height[t]\
    \ = height[f] + 1;\r\n          q.emplace(t);\r\n        }\r\n      }\r\n    \
    \  return height;\r\n    }\r\n\r\n    auto constructIds() const {\r\n      std::vector<Node>\
    \ ids(m_n);\r\n      Node val = 0;\r\n      std::stack<Node> stk;\r\n      stk.emplace(0);\r\
    \n      while (!stk.empty()) {\r\n        auto f = stk.top();\r\n        stk.pop();\r\
    \n        ids[f] = val;\r\n        ++val;\r\n        if (m_tree.find(f) == m_tree.end())\
    \ { continue; }\r\n        for (const auto& t : m_tree.at(f)) { stk.emplace(t);\
    \ }\r\n      }\r\n      return ids;\r\n    }\r\n\r\n    auto constructOrder()\
    \ const {\r\n      std::vector<Node> order(m_n);\r\n      for (int i = 0; i <\
    \ m_n; ++i) { order[m_ids[i]] = i; }\r\n      return order;\r\n    }\r\n    /*\r\
    \n     * \u8FBA\u3092node\u3068\u3057\u3066\u62E1\u5F35\u3057\u305F\u5834\u5408\
    \u306E\u8FBAnode\u3060\u3051ID\u3092\u632F\u308B\r\n     * (1) - (2)\r\n     *\
    \ (1) - (e) - (2)\r\n     * [-1, -1, 0]\r\n     */\r\n    auto constructEdgeIds()\
    \ const {\r\n      Node edge_size = (m_n >> 1);\r\n      std::vector<Node> edge_ids(m_n,\
    \ -1);\r\n      Node val = 0;\r\n      std::stack<Node> stk;\r\n      stk.emplace(0);\r\
    \n      while (!stk.empty()) {\r\n        auto f = stk.top();\r\n        stk.pop();\r\
    \n        if (f > edge_size) {\r\n          edge_ids[f] = val;\r\n          ++val;\r\
    \n        }\r\n        if (m_tree.find(f) == m_tree.end()) { continue; }\r\n \
    \       for (const auto& t : m_tree.at(f)) { stk.emplace(t); }\r\n      }\r\n\
    \      return edge_ids;\r\n    }\r\n\r\n  public:\r\n    HeavyLightDecomposition(const\
    \ Graph<Node, Cost>& tree)\r\n        : m_n(tree.size()),\r\n          m_size(constructSize(tree)),\r\
    \n          m_tree(constructGraph(tree)),\r\n          m_root_par(constructRootPar(m_n,\
    \ m_tree)),\r\n          m_height(constructHeight(m_n, m_tree)),\r\n         \
    \ m_ids(constructIds()),\r\n          m_order(constructOrder()),\r\n         \
    \ m_edge_ids(constructEdgeIds()) {}\r\n\r\n    auto getId(Node i) const { return\
    \ m_ids[i]; }\r\n    auto getEdgeId(Node i) const { return m_edge_ids[i]; }\r\n\
    \    auto getOrder(Node i) const { return m_order[i]; }\r\n\r\n    auto lca(Node\
    \ f, Node t) const {\r\n      do {\r\n        auto [fr, fp] = m_root_par[f];\r\
    \n        auto [tr, tp] = m_root_par[t];\r\n        if (fr == tr) { break; }\r\
    \n        auto fph = (fp > -1) ? m_height[fp] : -1;\r\n        auto tph = (tp\
    \ > -1) ? m_height[tp] : -1;\r\n        if (fph < tph) {\r\n          t = tp;\r\
    \n        } else {\r\n          f = fp;\r\n        }\r\n      } while (true);\r\
    \n      return (m_height[f] < m_height[t]) ? f : t;\r\n    }\r\n\r\n    auto range(Node\
    \ f, Node t) const {\r\n      std::deque<std::pair<Node, Node>> ret;\r\n     \
    \ auto add = [&](Node from, Node to) {\r\n        auto l = std::min(m_ids[from],\
    \ m_ids[to]);\r\n        auto r = std::max(m_ids[from], m_ids[to]);\r\n      \
    \  ret.emplace_back(l, r);\r\n      };\r\n      do {\r\n        auto [fr, fp]\
    \ = m_root_par[f];\r\n        auto [tr, tp] = m_root_par[t];\r\n        if (fr\
    \ == tr) {\r\n          add(f, t);\r\n          break;\r\n        }\r\n      \
    \  auto fph = (fp > -1) ? m_height[fp] : -1;\r\n        auto tph = (tp > -1) ?\
    \ m_height[tp] : -1;\r\n        if (fph < tph) {\r\n          add(t, tr);\r\n\
    \          t = tp;\r\n        } else {\r\n          add(f, fr);\r\n          f\
    \ = fp;\r\n        }\r\n      } while (true);\r\n      return ret;\r\n    }\r\n\
    \r\n    auto rangeEdge(Node f, Node t) const {\r\n      Node edge_size = (m_n\
    \ >> 1);\r\n      std::deque<std::pair<Node, Node>> ret;\r\n      auto add = [&](Node\
    \ from, Node to) {\r\n        auto l = std::min(m_ids[from], m_ids[to]);\r\n \
    \       auto r = std::max(m_ids[from], m_ids[to]);\r\n        if (m_order[l] <=\
    \ edge_size) { ++l; }\r\n        if (m_order[r] <= edge_size) { --r; }\r\n   \
    \     if (l > r) { return; }\r\n        auto edge_l = m_edge_ids[m_order[l]];\r\
    \n        auto edge_r = m_edge_ids[m_order[r]];\r\n        ret.emplace_back(edge_l,\
    \ edge_r);\r\n      };\r\n      do {\r\n        auto [fr, fp] = m_root_par[f];\r\
    \n        auto [tr, tp] = m_root_par[t];\r\n        if (fr == tr) {\r\n      \
    \    add(f, t);\r\n          break;\r\n        }\r\n        auto fph = (fp > -1)\
    \ ? m_height[fp] : -1;\r\n        auto tph = (tp > -1) ? m_height[tp] : -1;\r\n\
    \        if (fph < tph) {\r\n          add(t, tr);\r\n          t = tp;\r\n  \
    \      } else {\r\n          add(f, fr);\r\n          f = fp;\r\n        }\r\n\
    \      } while (true);\r\n      return ret;\r\n    }\r\n\r\n    auto rangeSubTree(Node\
    \ f) const {\r\n      return std::pair<Node, Node>{m_ids[f], m_ids[f] + m_size[f]\
    \ - 1};\r\n    }\r\n  };\r\n}  // namespace mtd\r\n"
  code: "#pragma once\r\n\r\n#include <queue>\r\n#include <stack>\r\n#include <unordered_map>\r\
    \n\r\n#include \"../Graph.hpp\"\r\n\r\nnamespace mtd {\r\n  template <class Node,\
    \ class Cost>\r\n  class HeavyLightDecomposition {\r\n    using GraphOrderd =\
    \ std::unordered_map<Node, std::deque<Node>>;\r\n\r\n    const Node m_n;\r\n \
    \   const std::vector<Node> m_size;\r\n    const GraphOrderd m_tree;\r\n    const\
    \ std::vector<Node> m_height;\r\n    const std::vector<std::pair<Node, Node>>\
    \ m_root_par;\r\n    const std::vector<Node> m_ids;\r\n    const std::vector<Node>\
    \ m_order;\r\n    const std::vector<Node> m_edge_ids;\r\n\r\n    static auto constructGraph(const\
    \ Graph<Node, Cost>& tree) {\r\n      auto n = tree.size();\r\n      std::deque<std::pair<Node,\
    \ Node>> order;\r\n      std::vector<Node> used(n);\r\n      std::stack<std::pair<Node,\
    \ Node>> stk;\r\n      stk.emplace(0, -1);\r\n      used[0] = true;\r\n      while\
    \ (!stk.empty()) {\r\n        auto [f, p] = stk.top();\r\n        order.emplace_front(f,\
    \ p);\r\n        stk.pop();\r\n        for (const auto& [t, _] : tree.getEdges(f))\
    \ {\r\n          if (used[t]) {\r\n            continue;\r\n            ;\r\n\
    \          }\r\n          used[t] = true;\r\n          stk.emplace(t, f);\r\n\
    \        }\r\n      }\r\n\r\n      std::vector<Node> size(n, 1);\r\n      GraphOrderd\
    \ hld_tree;\r\n      for (const auto& [f, p] : order) {\r\n        Node size_sum\
    \ = 1;\r\n        Node size_max = 0;\r\n        std::deque<Node> to_list;\r\n\
    \        for (const auto& [t, _] : tree.getEdges(f)) {\r\n          if (t == p)\
    \ { continue; }\r\n          if (size[t] > size_max) {\r\n            size_max\
    \ = size[t];\r\n            to_list.emplace_back(t);\r\n          } else {\r\n\
    \            to_list.emplace_front(t);\r\n          }\r\n          size_sum +=\
    \ size[t];\r\n        }\r\n        if (!to_list.empty()) { hld_tree.emplace(f,\
    \ to_list); }\r\n        size[f] = size_sum;\r\n      }\r\n      return hld_tree;\r\
    \n    }\r\n\r\n    static auto constructSize(const Graph<Node, Cost>& tree) {\r\
    \n      auto n = tree.size();\r\n      std::deque<std::pair<Node, Node>> order;\r\
    \n      std::vector<Node> used(n);\r\n      std::stack<std::pair<Node, Node>>\
    \ stk;\r\n      stk.emplace(0, -1);\r\n      used[0] = true;\r\n      while (!stk.empty())\
    \ {\r\n        auto [f, p] = stk.top();\r\n        order.emplace_front(f, p);\r\
    \n        stk.pop();\r\n        for (const auto& [t, _] : tree.getEdges(f)) {\r\
    \n          if (used[t]) {\r\n            continue;\r\n            ;\r\n     \
    \     }\r\n          used[t] = true;\r\n          stk.emplace(t, f);\r\n     \
    \   }\r\n      }\r\n\r\n      std::vector<Node> size(n, 1);\r\n      for (const\
    \ auto& [f, p] : order) {\r\n        Node size_sum = 1;\r\n        for (const\
    \ auto& [t, _] : tree.getEdges(f)) {\r\n          if (t == p) { continue; }\r\n\
    \          size_sum += size[t];\r\n        }\r\n        size[f] = size_sum;\r\n\
    \      }\r\n      return size;\r\n    }\r\n\r\n    static auto constructRootPar(Node\
    \ n, const GraphOrderd& tree) {\r\n      std::vector<std::pair<Node, Node>> root_par(n);\r\
    \n      std::stack<std::tuple<Node, Node, Node>> stk;\r\n      stk.emplace(0,\
    \ 0, -1);\r\n      while (!stk.empty()) {\r\n        auto [f, root, par] = stk.top();\r\
    \n        stk.pop();\r\n\r\n        if (tree.find(f) == tree.end()) {\r\n    \
    \      root_par[f] = {root, par};\r\n          continue;\r\n        }\r\n    \
    \    auto itr = tree.at(f).rbegin();\r\n        stk.emplace(*itr, root, par);\r\
    \n        root_par[f] = {root, par};\r\n        for (++itr; itr != tree.at(f).rend();\
    \ ++itr) {\r\n          stk.emplace(*itr, *itr, f);\r\n        }\r\n      }\r\n\
    \      return root_par;\r\n    }\r\n    static auto constructHeight(Node n, const\
    \ GraphOrderd& tree) {\r\n      std::vector<Node> height(n);\r\n      std::queue<Node>\
    \ q;\r\n      q.emplace(0);\r\n      while (!q.empty()) {\r\n        auto f =\
    \ q.front();\r\n        q.pop();\r\n        if (tree.find(f) == tree.end()) {\
    \ continue; }\r\n        for (const auto& t : tree.at(f)) {\r\n          height[t]\
    \ = height[f] + 1;\r\n          q.emplace(t);\r\n        }\r\n      }\r\n    \
    \  return height;\r\n    }\r\n\r\n    auto constructIds() const {\r\n      std::vector<Node>\
    \ ids(m_n);\r\n      Node val = 0;\r\n      std::stack<Node> stk;\r\n      stk.emplace(0);\r\
    \n      while (!stk.empty()) {\r\n        auto f = stk.top();\r\n        stk.pop();\r\
    \n        ids[f] = val;\r\n        ++val;\r\n        if (m_tree.find(f) == m_tree.end())\
    \ { continue; }\r\n        for (const auto& t : m_tree.at(f)) { stk.emplace(t);\
    \ }\r\n      }\r\n      return ids;\r\n    }\r\n\r\n    auto constructOrder()\
    \ const {\r\n      std::vector<Node> order(m_n);\r\n      for (int i = 0; i <\
    \ m_n; ++i) { order[m_ids[i]] = i; }\r\n      return order;\r\n    }\r\n    /*\r\
    \n     * \u8FBA\u3092node\u3068\u3057\u3066\u62E1\u5F35\u3057\u305F\u5834\u5408\
    \u306E\u8FBAnode\u3060\u3051ID\u3092\u632F\u308B\r\n     * (1) - (2)\r\n     *\
    \ (1) - (e) - (2)\r\n     * [-1, -1, 0]\r\n     */\r\n    auto constructEdgeIds()\
    \ const {\r\n      Node edge_size = (m_n >> 1);\r\n      std::vector<Node> edge_ids(m_n,\
    \ -1);\r\n      Node val = 0;\r\n      std::stack<Node> stk;\r\n      stk.emplace(0);\r\
    \n      while (!stk.empty()) {\r\n        auto f = stk.top();\r\n        stk.pop();\r\
    \n        if (f > edge_size) {\r\n          edge_ids[f] = val;\r\n          ++val;\r\
    \n        }\r\n        if (m_tree.find(f) == m_tree.end()) { continue; }\r\n \
    \       for (const auto& t : m_tree.at(f)) { stk.emplace(t); }\r\n      }\r\n\
    \      return edge_ids;\r\n    }\r\n\r\n  public:\r\n    HeavyLightDecomposition(const\
    \ Graph<Node, Cost>& tree)\r\n        : m_n(tree.size()),\r\n          m_size(constructSize(tree)),\r\
    \n          m_tree(constructGraph(tree)),\r\n          m_root_par(constructRootPar(m_n,\
    \ m_tree)),\r\n          m_height(constructHeight(m_n, m_tree)),\r\n         \
    \ m_ids(constructIds()),\r\n          m_order(constructOrder()),\r\n         \
    \ m_edge_ids(constructEdgeIds()) {}\r\n\r\n    auto getId(Node i) const { return\
    \ m_ids[i]; }\r\n    auto getEdgeId(Node i) const { return m_edge_ids[i]; }\r\n\
    \    auto getOrder(Node i) const { return m_order[i]; }\r\n\r\n    auto lca(Node\
    \ f, Node t) const {\r\n      do {\r\n        auto [fr, fp] = m_root_par[f];\r\
    \n        auto [tr, tp] = m_root_par[t];\r\n        if (fr == tr) { break; }\r\
    \n        auto fph = (fp > -1) ? m_height[fp] : -1;\r\n        auto tph = (tp\
    \ > -1) ? m_height[tp] : -1;\r\n        if (fph < tph) {\r\n          t = tp;\r\
    \n        } else {\r\n          f = fp;\r\n        }\r\n      } while (true);\r\
    \n      return (m_height[f] < m_height[t]) ? f : t;\r\n    }\r\n\r\n    auto range(Node\
    \ f, Node t) const {\r\n      std::deque<std::pair<Node, Node>> ret;\r\n     \
    \ auto add = [&](Node from, Node to) {\r\n        auto l = std::min(m_ids[from],\
    \ m_ids[to]);\r\n        auto r = std::max(m_ids[from], m_ids[to]);\r\n      \
    \  ret.emplace_back(l, r);\r\n      };\r\n      do {\r\n        auto [fr, fp]\
    \ = m_root_par[f];\r\n        auto [tr, tp] = m_root_par[t];\r\n        if (fr\
    \ == tr) {\r\n          add(f, t);\r\n          break;\r\n        }\r\n      \
    \  auto fph = (fp > -1) ? m_height[fp] : -1;\r\n        auto tph = (tp > -1) ?\
    \ m_height[tp] : -1;\r\n        if (fph < tph) {\r\n          add(t, tr);\r\n\
    \          t = tp;\r\n        } else {\r\n          add(f, fr);\r\n          f\
    \ = fp;\r\n        }\r\n      } while (true);\r\n      return ret;\r\n    }\r\n\
    \r\n    auto rangeEdge(Node f, Node t) const {\r\n      Node edge_size = (m_n\
    \ >> 1);\r\n      std::deque<std::pair<Node, Node>> ret;\r\n      auto add = [&](Node\
    \ from, Node to) {\r\n        auto l = std::min(m_ids[from], m_ids[to]);\r\n \
    \       auto r = std::max(m_ids[from], m_ids[to]);\r\n        if (m_order[l] <=\
    \ edge_size) { ++l; }\r\n        if (m_order[r] <= edge_size) { --r; }\r\n   \
    \     if (l > r) { return; }\r\n        auto edge_l = m_edge_ids[m_order[l]];\r\
    \n        auto edge_r = m_edge_ids[m_order[r]];\r\n        ret.emplace_back(edge_l,\
    \ edge_r);\r\n      };\r\n      do {\r\n        auto [fr, fp] = m_root_par[f];\r\
    \n        auto [tr, tp] = m_root_par[t];\r\n        if (fr == tr) {\r\n      \
    \    add(f, t);\r\n          break;\r\n        }\r\n        auto fph = (fp > -1)\
    \ ? m_height[fp] : -1;\r\n        auto tph = (tp > -1) ? m_height[tp] : -1;\r\n\
    \        if (fph < tph) {\r\n          add(t, tr);\r\n          t = tp;\r\n  \
    \      } else {\r\n          add(f, fr);\r\n          f = fp;\r\n        }\r\n\
    \      } while (true);\r\n      return ret;\r\n    }\r\n\r\n    auto rangeSubTree(Node\
    \ f) const {\r\n      return std::pair<Node, Node>{m_ids[f], m_ids[f] + m_size[f]\
    \ - 1};\r\n    }\r\n  };\r\n}  // namespace mtd\r\n"
  dependsOn:
  - Library/Graph/Graph.hpp
  isVerificationFile: false
  path: Library/Graph/Tree/HeavyLightDecomposition.hpp
  requiredBy:
  - Library/Graph/Tree/AuxiliaryTree.hpp
  timestamp: '2025-06-09 16:27:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Graph/Tree/AuxiliaryTree.test.cpp
  - Test/Graph/Tree/HeavyLightDecomposition_edge.test.cpp
  - Test/Graph/Tree/HeavyLightDecomposition_LCA.test.cpp
documentation_of: Library/Graph/Tree/HeavyLightDecomposition.hpp
layout: document
redirect_from:
- /library/Library/Graph/Tree/HeavyLightDecomposition.hpp
- /library/Library/Graph/Tree/HeavyLightDecomposition.hpp.html
title: Library/Graph/Tree/HeavyLightDecomposition.hpp
---
