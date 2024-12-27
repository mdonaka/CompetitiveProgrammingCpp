---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Graph.hpp
    title: Library/Graph/Graph.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Tree/HeavyLightDecomposition.hpp
    title: Library/Graph/Tree/HeavyLightDecomposition.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Graph/Tree/AuxiliaryTree.test.cpp
    title: Test/Graph/Tree/AuxiliaryTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Graph/Tree/AuxiliaryTree.hpp\"\n\r\n#include <set>\r\
    \n#include <vector>\r\n\r\n#line 2 \"Library/Graph/Tree/HeavyLightDecomposition.hpp\"\
    \n\r\n#include <queue>\r\n#include <stack>\r\n#include <unordered_map>\r\n\r\n\
    #line 2 \"Library/Graph/Graph.hpp\"\n#include <deque>\r\n#include <iostream>\r\
    \n#include <ranges>\r\n#include <tuple>\r\n#line 7 \"Library/Graph/Graph.hpp\"\
    \n\r\nnamespace mtd {\r\n  template <class Node = int, class Cost = long long>\r\
    \n  class Graph {\r\n    // using Node = int;\r\n    // using Cost = long long;\r\
    \n\r\n    using Edge = std::pair<Node, Cost>;\r\n    using Edges = std::vector<Edge>;\r\
    \n\r\n    const int m_n;\r\n    std::vector<Edges> m_graph;\r\n\r\n  public:\r\
    \n    Graph(int n) : m_n(n), m_graph(n) {}\r\n    Graph(const std::vector<Edges>&\
    \ edges)\r\n        : m_n(edges.size()), m_graph(edges) {}\r\n\r\n    auto addEdge(const\
    \ Node& f, const Node& t, const Cost& c = 1) {\r\n      m_graph[f].emplace_back(t,\
    \ c);\r\n    }\r\n    auto addEdgeUndirected(const Node& f, const Node& t, const\
    \ Cost& c = 1) {\r\n      addEdge(f, t, c);\r\n      addEdge(t, f, c);\r\n   \
    \ }\r\n    auto getEdges(const Node& from) const {\r\n      class EdgesRange {\r\
    \n        const typename Edges::const_iterator b, e;\r\n\r\n      public:\r\n\
    \        EdgesRange(const Edges& edges) : b(edges.begin()), e(edges.end()) {}\r\
    \n        auto begin() const { return b; }\r\n        auto end() const { return\
    \ e; }\r\n      };\r\n      return EdgesRange(m_graph[from]);\r\n    }\r\n   \
    \ auto getEdges() const {\r\n      std::deque<std::tuple<Node, Node, Cost>> edges;\r\
    \n      for (Node from : std::views::iota(0, m_n)) {\r\n        for (const auto&\
    \ [to, c] : getEdges(from)) {\r\n          edges.emplace_back(from, to, c);\r\n\
    \        }\r\n      }\r\n      return edges;\r\n    }\r\n    auto getEdgesExcludeCost()\
    \ const {\r\n      std::deque<std::pair<Node, Node>> edges;\r\n      for (Node\
    \ from : std::views::iota(0, m_n)) {\r\n        for (const auto& [to, _] : getEdges(from))\
    \ {\r\n          edges.emplace_back(from, to);\r\n        }\r\n      }\r\n   \
    \   return edges;\r\n    }\r\n    auto reverse() const {\r\n      auto rev = Graph<Node,\
    \ Cost>(m_n);\r\n      for (const auto& [from, to, c] : getEdges()) { rev.addEdge(to,\
    \ from, c); }\r\n      return rev;\r\n    }\r\n    auto size() const { return\
    \ m_n; };\r\n    auto debug(bool directed = false) const {\r\n      for (const\
    \ auto& [f, t, c] : getEdges()) {\r\n        if (f < t || directed) {\r\n    \
    \      std::cout << f << \" -> \" << t << \": \" << c << std::endl;\r\n      \
    \  }\r\n      }\r\n    }\r\n  };\r\n}  // namespace mtd\r\n#line 8 \"Library/Graph/Tree/HeavyLightDecomposition.hpp\"\
    \n\r\nnamespace mtd {\r\n  template <class Node, class Cost>\r\n  class HeavyLightDecomposition\
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
    \ - 1};\r\n    }\r\n  };\r\n}  // namespace mtd\r\n#line 7 \"Library/Graph/Tree/AuxiliaryTree.hpp\"\
    \n\r\nnamespace mtd {\r\n  template <class Node, class Cost>\r\n  class AuxiliaryTree\
    \ {\r\n    // \u5B9A\u6570\u500D\u9AD8\u901F\u5316\u306E\u305F\u3081\u7834\u58CA\
    \u7684\r\n    std::vector<int> compres_map;\r\n\r\n    const std::vector<Cost>\
    \ depth_cost;\r\n    const HeavyLightDecomposition<Node, Cost> hld;\r\n\r\n  \
    \  auto construct_depth(const Graph<Node, Cost>& tree) const {\r\n      std::vector<Cost>\
    \ _depth_cost(tree.size());\r\n      std::vector<int> used(tree.size());\r\n \
    \     auto dfs = [&](auto&& self, Node from) -> void {\r\n        used[from] =\
    \ true;\r\n        for (const auto& [to, c] : tree.getEdges(from))\r\n       \
    \   if (!used[to]) {\r\n            _depth_cost[to] = _depth_cost[from] + c;\r\
    \n            self(self, to);\r\n          }\r\n      };\r\n      dfs(dfs, 0);\r\
    \n      return _depth_cost;\r\n    }\r\n\r\n  public:\r\n    AuxiliaryTree(const\
    \ Graph<Node, Cost>& tree)\r\n        : compres_map(tree.size()),\r\n        \
    \  depth_cost(construct_depth(tree)),\r\n          hld(tree) {}\r\n\r\n    auto\
    \ compression(const std::vector<Node>& nodes) {\r\n      auto compare = [&](int\
    \ a, int b) { return hld.getId(a) < hld.getId(b); };\r\n\r\n      // \u5143\u306E\
    \u9802\u70B9\u96C6\u5408\r\n      auto nodes_set =\r\n          std::set<int,\
    \ decltype(compare)>(nodes.begin(), nodes.end(), compare);\r\n      auto nodes_set_with_lca\
    \ = nodes_set;\r\n\r\n      // pre order\u3067\u306E\u5168\u3066\u306E\u96A3\u63A5\
    node\u306ELCA\u3092\u6C42\u3081\u308B\r\n      for (auto itr = nodes_set_with_lca.begin();\r\
    \n           std::next(itr) != nodes_set_with_lca.end(); ++itr) {\r\n        nodes_set_with_lca.emplace(hld.lca(*itr,\
    \ *std::next(itr)));\r\n      }\r\n\r\n      // \u5EA7\u6A19\u5727\u7E2E\r\n \
    \     int at_size = nodes_set_with_lca.size();\r\n      for (int i = 0; auto x\
    \ : nodes_set_with_lca) {\r\n        compres_map[x] = i;\r\n        ++i;\r\n \
    \     }\r\n\r\n      // LCA\u3092\u542B\u3081\u305F\u5168\u3066\u306Enode\u3067\
    \u5B50\u5B6B\u95A2\u4FC2\u3092\u4FDD\u3063\u3066\u8FBA\u3092\u5F35\u308B\r\n \
    \     std::stack<int> stk;\r\n      Graph<Node, Cost> auxiliary_tree(at_size);\r\
    \n      for (auto nd : nodes_set_with_lca) {\r\n        while (!stk.empty() &&\
    \ hld.lca(stk.top(), nd) != stk.top()) {\r\n          stk.pop();\r\n        }\r\
    \n        if (!stk.empty()) {\r\n          auto f = compres_map[stk.top()];\r\n\
    \          auto t = compres_map[nd];\r\n          auto c = depth_cost[stk.top()]\
    \ + depth_cost[nd] -\r\n                   depth_cost[hld.lca(stk.top(), nd)]\
    \ * 2;\r\n          auxiliary_tree.addEdgeUndirected(f, t, c);\r\n        }\r\n\
    \        stk.emplace(nd);\r\n      }\r\n      return auxiliary_tree;\r\n    }\r\
    \n  };\r\n}  // namespace mtd\r\n"
  code: "#pragma once\r\n\r\n#include <set>\r\n#include <vector>\r\n\r\n#include \"\
    ./HeavyLightDecomposition.hpp\"\r\n\r\nnamespace mtd {\r\n  template <class Node,\
    \ class Cost>\r\n  class AuxiliaryTree {\r\n    // \u5B9A\u6570\u500D\u9AD8\u901F\
    \u5316\u306E\u305F\u3081\u7834\u58CA\u7684\r\n    std::vector<int> compres_map;\r\
    \n\r\n    const std::vector<Cost> depth_cost;\r\n    const HeavyLightDecomposition<Node,\
    \ Cost> hld;\r\n\r\n    auto construct_depth(const Graph<Node, Cost>& tree) const\
    \ {\r\n      std::vector<Cost> _depth_cost(tree.size());\r\n      std::vector<int>\
    \ used(tree.size());\r\n      auto dfs = [&](auto&& self, Node from) -> void {\r\
    \n        used[from] = true;\r\n        for (const auto& [to, c] : tree.getEdges(from))\r\
    \n          if (!used[to]) {\r\n            _depth_cost[to] = _depth_cost[from]\
    \ + c;\r\n            self(self, to);\r\n          }\r\n      };\r\n      dfs(dfs,\
    \ 0);\r\n      return _depth_cost;\r\n    }\r\n\r\n  public:\r\n    AuxiliaryTree(const\
    \ Graph<Node, Cost>& tree)\r\n        : compres_map(tree.size()),\r\n        \
    \  depth_cost(construct_depth(tree)),\r\n          hld(tree) {}\r\n\r\n    auto\
    \ compression(const std::vector<Node>& nodes) {\r\n      auto compare = [&](int\
    \ a, int b) { return hld.getId(a) < hld.getId(b); };\r\n\r\n      // \u5143\u306E\
    \u9802\u70B9\u96C6\u5408\r\n      auto nodes_set =\r\n          std::set<int,\
    \ decltype(compare)>(nodes.begin(), nodes.end(), compare);\r\n      auto nodes_set_with_lca\
    \ = nodes_set;\r\n\r\n      // pre order\u3067\u306E\u5168\u3066\u306E\u96A3\u63A5\
    node\u306ELCA\u3092\u6C42\u3081\u308B\r\n      for (auto itr = nodes_set_with_lca.begin();\r\
    \n           std::next(itr) != nodes_set_with_lca.end(); ++itr) {\r\n        nodes_set_with_lca.emplace(hld.lca(*itr,\
    \ *std::next(itr)));\r\n      }\r\n\r\n      // \u5EA7\u6A19\u5727\u7E2E\r\n \
    \     int at_size = nodes_set_with_lca.size();\r\n      for (int i = 0; auto x\
    \ : nodes_set_with_lca) {\r\n        compres_map[x] = i;\r\n        ++i;\r\n \
    \     }\r\n\r\n      // LCA\u3092\u542B\u3081\u305F\u5168\u3066\u306Enode\u3067\
    \u5B50\u5B6B\u95A2\u4FC2\u3092\u4FDD\u3063\u3066\u8FBA\u3092\u5F35\u308B\r\n \
    \     std::stack<int> stk;\r\n      Graph<Node, Cost> auxiliary_tree(at_size);\r\
    \n      for (auto nd : nodes_set_with_lca) {\r\n        while (!stk.empty() &&\
    \ hld.lca(stk.top(), nd) != stk.top()) {\r\n          stk.pop();\r\n        }\r\
    \n        if (!stk.empty()) {\r\n          auto f = compres_map[stk.top()];\r\n\
    \          auto t = compres_map[nd];\r\n          auto c = depth_cost[stk.top()]\
    \ + depth_cost[nd] -\r\n                   depth_cost[hld.lca(stk.top(), nd)]\
    \ * 2;\r\n          auxiliary_tree.addEdgeUndirected(f, t, c);\r\n        }\r\n\
    \        stk.emplace(nd);\r\n      }\r\n      return auxiliary_tree;\r\n    }\r\
    \n  };\r\n}  // namespace mtd\r\n"
  dependsOn:
  - Library/Graph/Tree/HeavyLightDecomposition.hpp
  - Library/Graph/Graph.hpp
  isVerificationFile: false
  path: Library/Graph/Tree/AuxiliaryTree.hpp
  requiredBy: []
  timestamp: '2024-12-27 17:07:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Graph/Tree/AuxiliaryTree.test.cpp
documentation_of: Library/Graph/Tree/AuxiliaryTree.hpp
layout: document
redirect_from:
- /library/Library/Graph/Tree/AuxiliaryTree.hpp
- /library/Library/Graph/Tree/AuxiliaryTree.hpp.html
title: Library/Graph/Tree/AuxiliaryTree.hpp
---
