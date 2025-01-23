---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Algebraic/Monoid.hpp
    title: Library/Algebraic/Monoid.hpp
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/LazySegmentTree.hpp
    title: Library/DataStructure/LazySegmentTree.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Graph.hpp
    title: Library/Graph/Graph.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Tree/HeavyLightDecomposition.hpp
    title: Library/Graph/Tree/HeavyLightDecomposition.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E
  bundledCode: "#line 1 \"Test/Graph/Tree/HeavyLightDecomposition_edge.test.cpp\"\n\
    #define PROBLEM \\\r\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E\"\
    \r\n\r\n#include <iostream>\r\n\r\n// begin:tag includes\r\n#line 2 \"Library/DataStructure/LazySegmentTree.hpp\"\
    \n\r\n#include <deque>\r\n#line 5 \"Library/DataStructure/LazySegmentTree.hpp\"\
    \n#include <utility>\r\n#include <vector>\r\n\r\n#line 2 \"Library/Algebraic/Monoid.hpp\"\
    \n\n#line 4 \"Library/Algebraic/Monoid.hpp\"\n\nnamespace mtd {\n\n  template\
    \ <class S,    // set\n            S element,  // identity element\n         \
    \   class op    // binary operation\n            >\n  requires std::is_invocable_r_v<S,\
    \ op, S, S>\n  struct Monoid {\n    using value_type = S;\n    constexpr static\
    \ S _element = element;\n    using op_type = op;\n\n    S m_val;\n    constexpr\
    \ Monoid(S val) : m_val(val) {}\n    constexpr Monoid() : Monoid(element) {}\n\
    \    constexpr Monoid binaryOperation(const Monoid& m2) const {\n      return\
    \ op()(m_val, m2.m_val);\n    }\n    friend std::ostream& operator<<(std::ostream&\
    \ os,\n                                    const Monoid<S, element, op>& m) {\n\
    \      return os << m.m_val;\n    }\n  };\n\n  namespace __detail {\n    template\
    \ <typename T, template <typename, auto, typename> typename S>\n    concept is_monoid_specialization_of\
    \ = requires {\n      typename std::enable_if_t<std::is_same_v<\n          T,\
    \ S<typename T::value_type, T::_element, typename T::op_type>>>;\n    };\n  }\
    \  // namespace __detail\n\n  template <typename M>\n  concept monoid = __detail::is_monoid_specialization_of<M,\
    \ Monoid>;\n\n}  // namespace mtd\n#line 9 \"Library/DataStructure/LazySegmentTree.hpp\"\
    \n\r\nnamespace mtd {\r\n  template <monoid Monoid, monoid MonoidOp, class op>\r\
    \n  class LazySegmentTree {\r\n  private:\r\n    const int m_size;\r\n    std::vector<Monoid>\
    \ m_node;\r\n    std::vector<MonoidOp> m_lazy;\r\n    using S = decltype(Monoid().m_val);\r\
    \n\r\n    constexpr int calcSize(int n) const {\r\n      int size = 1;\r\n   \
    \   while (size < n) { size <<= 1; }\r\n      return size;\r\n    }\r\n\r\n  \
    \  constexpr auto _lazy_update(int i, const MonoidOp& val) {\r\n      if (i >=\
    \ (m_size << 1) - 1) { return; }\r\n      m_lazy[i] = m_lazy[i].binaryOperation(val);\r\
    \n    }\r\n\r\n    constexpr auto _propagate(int i) {\r\n      m_node[i] = op()(m_node[i],\
    \ m_lazy[i]);\r\n      _lazy_update((i << 1) + 1, m_lazy[i]);\r\n      _lazy_update((i\
    \ << 1) + 2, m_lazy[i]);\r\n      m_lazy[i] = MonoidOp();\r\n    }\r\n\r\n   \
    \ constexpr auto _update(int l, int r, int k, int nl, int nr,\r\n            \
    \               const MonoidOp& m) {\r\n      _propagate(k);\r\n      if (nr <\
    \ l || r < nl) { return; }\r\n      if (l <= nl && nr <= r) {\r\n        _lazy_update(k,\
    \ m);\r\n        _propagate(k);\r\n        return;\r\n      }\r\n      _update(l,\
    \ r, (k << 1) + 1, nl, (nl + nr) >> 1, m);\r\n      _update(l, r, (k << 1) + 2,\
    \ ((nl + nr) >> 1) + 1, nr, m);\r\n      m_node[k] = m_node[(k << 1) + 1].binaryOperation(m_node[(k\
    \ << 1) + 2]);\r\n    }\r\n\r\n    constexpr auto _query(int l, int r, int k,\
    \ int nl, int nr) {\r\n      _propagate(k);\r\n      if (nr < l || r < nl) { return\
    \ Monoid(); }\r\n      if (l <= nl && nr <= r) { return m_node[k]; }\r\n     \
    \ auto l_val = _query(l, r, (k << 1) + 1, nl, (nl + nr) >> 1);\r\n      auto r_val\
    \ = _query(l, r, (k << 1) + 2, ((nl + nr) >> 1) + 1, nr);\r\n      return l_val.binaryOperation(r_val);\r\
    \n    }\r\n\r\n    constexpr auto _construct(const std::vector<S>& vec) {\r\n\
    \      for (unsigned int i = 0; i < vec.size(); ++i) {\r\n        m_node[i + m_size\
    \ - 1] = Monoid(vec[i]);\r\n      }\r\n      for (int i = m_size - 2; i >= 0;\
    \ --i) {\r\n        m_node[i] =\r\n            m_node[(i << 1) | 1].binaryOperation(m_node[(i\
    \ + 1) << 1LL]);\r\n      }\r\n    }\r\n\r\n  public:\r\n    constexpr LazySegmentTree(int\
    \ n)\r\n        : m_size(calcSize(n)),\r\n          m_node((m_size << 1) - 1),\r\
    \n          m_lazy((m_size << 1) - 1) {}\r\n    constexpr LazySegmentTree(int\
    \ n, const std::vector<S>& vec)\r\n        : LazySegmentTree(n) {\r\n      _construct(vec);\r\
    \n    }\r\n\r\n    constexpr auto update(int l, int r, const MonoidOp& val) {\r\
    \n      _update(l, r, 0, 0, m_size - 1, val);\r\n    }\r\n\r\n    constexpr auto\
    \ query(int l, int r) {\r\n      return _query(l, r, 0, 0, m_size - 1).m_val;\r\
    \n    }\r\n\r\n    /*\r\n     * f([l, r]) = true \u3068\u306A\u308B\u6700\u5927\
    \u306Er\r\n     * judge: (Monoid) -> bool\r\n     **/\r\n    template <class F>\r\
    \n    constexpr auto max_right(int _l, const F& judge) {\r\n      if (!judge(Monoid()))\
    \ {\r\n        throw std::runtime_error(\"SegmentTree.max_right.judge(e) must\
    \ be true\");\r\n      }\r\n      query(_l, m_size - 1);\r\n      auto l = std::max(_l,\
    \ 0) + m_size;\r\n      auto r = 2 * m_size - 1;\r\n      auto lm = Monoid();\r\
    \n      while (l <= r) {\r\n        if (l & 1) {\r\n          auto next = lm.binaryOperation(m_node[l\
    \ - 1]);\r\n          if (!judge(next)) {\r\n            auto itr = l;\r\n   \
    \         while (itr < m_size) {\r\n              _propagate(itr - 1);\r\n   \
    \           auto litr = 2 * itr;\r\n              auto ritr = 2 * itr + 1;\r\n\
    \              _propagate(litr - 1);\r\n              auto lval = lm.binaryOperation(m_node[litr\
    \ - 1]);\r\n              if (!judge(lval)) {\r\n                itr = litr;\r\
    \n              } else {\r\n                itr = ritr;\r\n                std::swap(lm,\
    \ lval);\r\n              }\r\n            }\r\n            return itr - m_size\
    \ - 1;\r\n          }\r\n          std::swap(lm, next);\r\n          ++l;\r\n\
    \        }\r\n        l >>= 1, r >>= 1;\r\n      }\r\n      return m_size - 1;\r\
    \n    }\r\n\r\n    /*\r\n     * f([l, r]) = true \u3068\u306A\u308B\u6700\u5C0F\
    \u306El\r\n     * judge: (Monoid) -> bool\r\n     **/\r\n    template <class F>\r\
    \n    constexpr auto min_left(int _r, const F& judge) {\r\n      if (!judge(Monoid()))\
    \ {\r\n        throw std::runtime_error(\"SegmentTree.min_left.judge(e) must be\
    \ true\");\r\n      }\r\n      query(0, _r);\r\n      auto l = m_size;\r\n   \
    \   auto r = std::min(_r, m_size - 1) + m_size;\r\n      auto rm = Monoid();\r\
    \n      while (l <= r) {\r\n        if (l & 1) { ++l; }\r\n        if (!(r & 1)\
    \ || (_r == m_size - 1 && r == 1)) {\r\n          auto next = m_node[r - 1].binaryOperation(rm);\r\
    \n          if (!judge(next)) {\r\n            auto itr = r;\r\n            while\
    \ (itr < m_size) {\r\n              _propagate(itr);\r\n              auto litr\
    \ = 2 * itr;\r\n              auto ritr = 2 * itr + 1;\r\n              _propagate(ritr\
    \ - 1);\r\n              auto rval = m_node[ritr - 1].binaryOperation(rm);\r\n\
    \              if (!judge(rval)) {\r\n                itr = ritr;\r\n        \
    \      } else {\r\n                itr = litr;\r\n                std::swap(rm,\
    \ rval);\r\n              }\r\n            }\r\n            return itr - m_size\
    \ + 1;\r\n          }\r\n          std::swap(rm, next);\r\n          --r;\r\n\
    \        }\r\n        l >>= 1, r >>= 1;\r\n      }\r\n      return 0;\r\n    }\r\
    \n\r\n    constexpr auto debug() {\r\n      for (int i = 0; i < (m_size << 1)\
    \ - 1; ++i) { _propagate(i); }\r\n      for (int i = 0; i < m_size; ++i) {\r\n\
    \        std::cout << m_node[m_size + i - 1] << \" \";\r\n      }\r\n      std::cout\
    \ << std::endl;\r\n    }\r\n  };\r\n\r\n  namespace type {\r\n    /* \u5404\u7A2E\
    \u983B\u51FA\u30B5\u30F3\u30D7\u30EB */\r\n    using P = std::pair<long long,\
    \ long long>;\r\n    constexpr long long update_element = -1e18;\r\n\r\n    /*----\
    \ \u8981\u7D20 ----*/\r\n    using M_SUM = Monoid<P, P{0, 0}, decltype([](const\
    \ P& a, const P& b) {\r\n                           return P{a.first + b.first,\
    \ a.second + b.second};\r\n                         })>;\r\n    using M_MIN =\
    \ Monoid<long long, static_cast<long long>(1e18),\r\n                        \
    \ decltype([](long long a, long long b) {\r\n                           return\
    \ std::min(a, b);\r\n                         })>;\r\n    using M_MAX = Monoid<long\
    \ long, static_cast<long long>(-1e18),\r\n                         decltype([](long\
    \ long a, long long b) {\r\n                           return std::max(a, b);\r\
    \n                         })>;\r\n    /*---- \u4F5C\u7528\u7D20 ----*/\r\n  \
    \  using M_UP = Monoid<long long, update_element,\r\n                        decltype([](long\
    \ long a, long long b) {\r\n                          if (b == update_element)\
    \ { return a; }\r\n                          return b;\r\n                   \
    \     })>;\r\n    using M_ADD =\r\n        Monoid<long long, static_cast<long\
    \ long>(0),\r\n               decltype([](long long a, long long b) { return a\
    \ + b; })>;\r\n\r\n    /*---- \u4F5C\u7528 ----*/\r\n    using OP_SUM_UP = decltype([](const\
    \ M_SUM& m, const M_UP& m2) {\r\n      if (m2.m_val == update_element) { return\
    \ m; }\r\n      return M_SUM(P{m.m_val.second * m2.m_val, m.m_val.second});\r\n\
    \    });\r\n    using OP_MIN_UP = decltype([](const M_MIN& m, const M_UP& m2)\
    \ {\r\n      if (m2.m_val == update_element) { return m; }\r\n      return M_MIN(m2.m_val);\r\
    \n    });\r\n    using OP_MAX_UP = decltype([](const M_MAX& m, const M_UP& m2)\
    \ {\r\n      if (m2.m_val == update_element) { return m; }\r\n      return M_MAX(m2.m_val);\r\
    \n    });\r\n    using OP_SUM_ADD = decltype([](const M_SUM& m, const M_ADD& m2)\
    \ {\r\n      return M_SUM(\r\n          P{m.m_val.first + m.m_val.second * m2.m_val,\
    \ m.m_val.second});\r\n    });\r\n    using OP_MIN_ADD = decltype([](const M_MIN&\
    \ m, const M_ADD& m2) {\r\n      return M_MIN{m.m_val + m2.m_val};\r\n    });\r\
    \n    using OP_MAX_ADD = decltype([](const M_MAX& m, const M_ADD& m2) {\r\n  \
    \    return M_MAX{m.m_val + m2.m_val};\r\n    });\r\n\r\n  }  // namespace type\r\
    \n}  // namespace mtd\r\n#line 4 \"Library/Graph/Graph.hpp\"\n#include <ranges>\r\
    \n#include <tuple>\r\n#line 7 \"Library/Graph/Graph.hpp\"\n\r\nnamespace mtd {\r\
    \n  template <class Node = int, class Cost = long long>\r\n  class Graph {\r\n\
    \    // using Node = int;\r\n    // using Cost = long long;\r\n\r\n    using Edge\
    \ = std::pair<Node, Cost>;\r\n    using Edges = std::vector<Edge>;\r\n\r\n   \
    \ const int m_n;\r\n    std::vector<Edges> m_graph;\r\n\r\n  public:\r\n    Graph(int\
    \ n) : m_n(n), m_graph(n) {}\r\n    Graph(const std::vector<Edges>& edges)\r\n\
    \        : m_n(edges.size()), m_graph(edges) {}\r\n\r\n    auto addEdge(const\
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
    \  }\r\n      }\r\n    }\r\n  };\r\n}  // namespace mtd\r\n#line 2 \"Library/Graph/Tree/HeavyLightDecomposition.hpp\"\
    \n\r\n#include <queue>\r\n#include <stack>\r\n#include <unordered_map>\r\n\r\n\
    #line 8 \"Library/Graph/Tree/HeavyLightDecomposition.hpp\"\n\r\nnamespace mtd\
    \ {\r\n  template <class Node, class Cost>\r\n  class HeavyLightDecomposition\
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
    \ - 1};\r\n    }\r\n  };\r\n}  // namespace mtd\r\n#line 10 \"Test/Graph/Tree/HeavyLightDecomposition_edge.test.cpp\"\
    \n// end:tag includes\r\n\r\nusing ll = long long;\r\n\r\nsigned main() {\r\n\
    \  std::cin.tie(0);\r\n  std::ios::sync_with_stdio(0);\r\n\r\n  ll n;\r\n  std::cin\
    \ >> n;\r\n  auto size = n + n - 1;\r\n  auto tree = mtd::Graph<int, bool>(size);\r\
    \n  ll add = n;\r\n  for (int f = 0; f < n; ++f) {\r\n    int k;\r\n    std::cin\
    \ >> k;\r\n    for (int _ = 0; _ < k; ++_) {\r\n      int t;\r\n      std::cin\
    \ >> t;\r\n      tree.addEdgeUndirected(f, add);\r\n      tree.addEdgeUndirected(t,\
    \ add);\r\n      ++add;\r\n    }\r\n  }\r\n\r\n  std::vector<std::pair<ll, ll>>\
    \ v(n - 1, {0, 1});\r\n  auto segtree = mtd::LazySegmentTree<mtd::type::M_SUM,\
    \ mtd::type::M_ADD,\r\n                                      mtd::type::OP_SUM_ADD>(n\
    \ - 1, v);\r\n  // NOTE: \u521D\u671F\u5024\u304C\u542B\u307E\u308C\u308B\u5834\
    \u5408\u306FID\u9806\u306B\u4E26\u3073\u5909\u3048\u308B\r\n  // val[hld.getEdgeId(i\
    \ + n)] = v[i];\r\n  auto hld = mtd::HeavyLightDecomposition(tree);\r\n\r\n  ll\
    \ q;\r\n  std::cin >> q;\r\n  for (int _ = 0; _ < q; ++_) {\r\n    ll k;\r\n \
    \   std::cin >> k;\r\n    if (k == 0) {\r\n      ll v, w;\r\n      std::cin >>\
    \ v >> w;\r\n      for (const auto& [l, r] : hld.rangeEdge(0, v)) {\r\n      \
    \  segtree.update(l, r, w);\r\n      }\r\n    } else {\r\n      ll u;\r\n    \
    \  std::cin >> u;\r\n      ll ans = 0;\r\n      for (const auto& [l, r] : hld.rangeEdge(0,\
    \ u)) {\r\n        ans += segtree.query(l, r).first;\r\n      }\r\n      std::cout\
    \ << ans << std::endl;\r\n    }\r\n  }\r\n}\r\n"
  code: "#define PROBLEM \\\r\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E\"\
    \r\n\r\n#include <iostream>\r\n\r\n// begin:tag includes\r\n#include \"./../../../Library/DataStructure/LazySegmentTree.hpp\"\
    \r\n#include \"./../../../Library/Graph/Graph.hpp\"\r\n#include \"./../../../Library/Graph/Tree/HeavyLightDecomposition.hpp\"\
    \r\n// end:tag includes\r\n\r\nusing ll = long long;\r\n\r\nsigned main() {\r\n\
    \  std::cin.tie(0);\r\n  std::ios::sync_with_stdio(0);\r\n\r\n  ll n;\r\n  std::cin\
    \ >> n;\r\n  auto size = n + n - 1;\r\n  auto tree = mtd::Graph<int, bool>(size);\r\
    \n  ll add = n;\r\n  for (int f = 0; f < n; ++f) {\r\n    int k;\r\n    std::cin\
    \ >> k;\r\n    for (int _ = 0; _ < k; ++_) {\r\n      int t;\r\n      std::cin\
    \ >> t;\r\n      tree.addEdgeUndirected(f, add);\r\n      tree.addEdgeUndirected(t,\
    \ add);\r\n      ++add;\r\n    }\r\n  }\r\n\r\n  std::vector<std::pair<ll, ll>>\
    \ v(n - 1, {0, 1});\r\n  auto segtree = mtd::LazySegmentTree<mtd::type::M_SUM,\
    \ mtd::type::M_ADD,\r\n                                      mtd::type::OP_SUM_ADD>(n\
    \ - 1, v);\r\n  // NOTE: \u521D\u671F\u5024\u304C\u542B\u307E\u308C\u308B\u5834\
    \u5408\u306FID\u9806\u306B\u4E26\u3073\u5909\u3048\u308B\r\n  // val[hld.getEdgeId(i\
    \ + n)] = v[i];\r\n  auto hld = mtd::HeavyLightDecomposition(tree);\r\n\r\n  ll\
    \ q;\r\n  std::cin >> q;\r\n  for (int _ = 0; _ < q; ++_) {\r\n    ll k;\r\n \
    \   std::cin >> k;\r\n    if (k == 0) {\r\n      ll v, w;\r\n      std::cin >>\
    \ v >> w;\r\n      for (const auto& [l, r] : hld.rangeEdge(0, v)) {\r\n      \
    \  segtree.update(l, r, w);\r\n      }\r\n    } else {\r\n      ll u;\r\n    \
    \  std::cin >> u;\r\n      ll ans = 0;\r\n      for (const auto& [l, r] : hld.rangeEdge(0,\
    \ u)) {\r\n        ans += segtree.query(l, r).first;\r\n      }\r\n      std::cout\
    \ << ans << std::endl;\r\n    }\r\n  }\r\n}\r\n"
  dependsOn:
  - Library/DataStructure/LazySegmentTree.hpp
  - Library/Algebraic/Monoid.hpp
  - Library/Graph/Graph.hpp
  - Library/Graph/Tree/HeavyLightDecomposition.hpp
  isVerificationFile: true
  path: Test/Graph/Tree/HeavyLightDecomposition_edge.test.cpp
  requiredBy: []
  timestamp: '2025-01-23 16:34:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Graph/Tree/HeavyLightDecomposition_edge.test.cpp
layout: document
redirect_from:
- /verify/Test/Graph/Tree/HeavyLightDecomposition_edge.test.cpp
- /verify/Test/Graph/Tree/HeavyLightDecomposition_edge.test.cpp.html
title: Test/Graph/Tree/HeavyLightDecomposition_edge.test.cpp
---
