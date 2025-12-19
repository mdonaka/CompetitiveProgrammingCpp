---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Graph/Graph.hpp
    title: Library/Graph/Graph.hpp
  - icon: ':x:'
    path: Library/Range/util.hpp
    title: Library/Range/util.hpp
  - icon: ':question:'
    path: Library/Utility/Tuple.hpp
    title: Library/Utility/Tuple.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/Graph/Normal/Topological.test.cpp
    title: Test/Graph/Normal/Topological.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Graph/Normal/Topological.hpp\"\n\r\n#include <deque>\r\
    \n#include <vector>\r\n\r\n#line 2 \"Library/Range/util.hpp\"\n\n#include <algorithm>\n\
    #include <iostream>\n#include <ranges>\n\n#line 2 \"Library/Utility/Tuple.hpp\"\
    \n\n#include <functional>\n\nnamespace mtd {\n  namespace util {\n    template\
    \ <class F, class T>\n    constexpr auto tuple_transform(F&& f, T&& t) {\n   \
    \   return std::apply(\n          [&]<class... Ts>(Ts&&... elems) {\n        \
    \    return std::tuple<std::invoke_result_t<F&, Ts>...>(\n                std::invoke(f,\
    \ std::forward<Ts>(elems))...);\n          },\n          std::forward<T>(t));\n\
    \    }\n    template <class F, class T>\n    constexpr auto tuple_for_each(F&&\
    \ f, T&& t) {\n      std::apply(\n          [&]<class... Ts>(Ts&&... elems) {\n\
    \            (std::invoke(f, std::forward<Ts>(elems)), ...);\n          },\n \
    \         std::forward<T>(t));\n    }\n  }  // namespace util\n}  // namespace\
    \ mtd\n#line 8 \"Library/Range/util.hpp\"\n\nnamespace mtd {\n  namespace ranges\
    \ {\n\n    namespace __detail {\n      template <typename... T>\n      concept\
    \ __all_random_access = (std::ranges::random_access_range<T> &&\n            \
    \                         ...);\n      template <typename... T>\n      concept\
    \ __all_bidirectional = (std::ranges::bidirectional_range<T> &&\n            \
    \                         ...);\n      template <typename... T>\n      concept\
    \ __all_forward = (std::ranges::forward_range<T> && ...);\n\n      template <class...\
    \ T>\n      constexpr auto _S_iter_concept() {\n        if constexpr (__all_random_access<T...>)\
    \ {\n          return std::random_access_iterator_tag{};\n        } else if constexpr\
    \ (__all_bidirectional<T...>) {\n          return std::bidirectional_iterator_tag{};\n\
    \        } else if constexpr (__all_forward<T...>) {\n          return std::forward_iterator_tag{};\n\
    \        } else {\n          return std::input_iterator_tag{};\n        }\n  \
    \    }\n\n      template <typename T>\n      auto _flatten(const T& t) {\n   \
    \     return std::make_tuple(t);\n      }\n      template <typename... T>\n  \
    \    auto _flatten(const std::tuple<T...>& t);\n\n      template <typename Head,\
    \ typename... Tail>\n      auto _flatten_impl(const Head& head, const Tail&...\
    \ tail) {\n        return std::tuple_cat(_flatten(head), _flatten(tail)...);\n\
    \      }\n      template <typename... T>\n      auto _flatten(const std::tuple<T...>&\
    \ t) {\n        return std::apply(\n            [](const auto&... args) { return\
    \ _flatten_impl(args...); }, t);\n      }\n    }  // namespace __detail\n\n  \
    \  template <std::ranges::range _Range>\n    struct flatten_view\n        : public\
    \ std::ranges::view_interface<flatten_view<_Range>> {\n      class iterator {\n\
    \      public:\n        std::ranges::iterator_t<_Range> _M_current;\n\n      \
    \  using difference_type = std::ranges::range_difference_t<_Range>;\n        using\
    \ value_type = decltype(__detail::_flatten(\n            std::declval<\n     \
    \           std::iter_reference_t<std::ranges::iterator_t<_Range>>>()));\n   \
    \     using iterator_concept = decltype(__detail::_S_iter_concept<_Range>());\n\
    \n        constexpr iterator() = default;\n        constexpr explicit iterator(decltype(_M_current)\
    \ __current)\n            : _M_current(__current) {}\n        constexpr auto operator*()\
    \ const {\n          return __detail::_flatten(*_M_current);\n        }\n    \
    \    constexpr auto& operator++() {\n          ++_M_current;\n          return\
    \ *this;\n        }\n        constexpr auto operator++(int) { return ++*this;\
    \ }\n        constexpr auto operator==(const iterator& other) const {\n      \
    \    return _M_current == other._M_current;\n        }\n        constexpr auto&\
    \ operator--() requires\n            __detail::__all_bidirectional<_Range> {\n\
    \          --_M_current;\n          return *this;\n        }\n        constexpr\
    \ auto operator--(\n            int) requires __detail::__all_bidirectional<_Range>\
    \ {\n          return --*this;\n        }\n        constexpr auto operator<=>(const\
    \ iterator&)\n            const requires __detail::__all_random_access<_Range>\n\
    \        = default;\n        constexpr auto operator-(const iterator& itr)\n \
    \           const requires __detail::__all_random_access<_Range> {\n         \
    \ return _M_current - itr._M_current;\n        }\n        constexpr auto& operator+=(const\
    \ difference_type n) requires\n            __detail::__all_random_access<_Range>\
    \ {\n          _M_current += n;\n          return *this;\n        }\n        constexpr\
    \ auto operator+(const difference_type n)\n            const requires __detail::__all_random_access<_Range>\
    \ {\n          auto __tmp = *this;\n          __tmp += n;\n          return __tmp;\n\
    \        }\n        constexpr friend auto operator+(const difference_type n,\n\
    \                                        const iterator& itr) requires\n     \
    \       __detail::__all_random_access<_Range> {\n          return itr + n;\n \
    \       }\n        constexpr auto& operator-=(const difference_type n) requires\n\
    \            __detail::__all_random_access<_Range> {\n          _M_current -=\
    \ n;\n          return *this;\n        }\n        constexpr auto operator-(const\
    \ difference_type n)\n            const requires __detail::__all_random_access<_Range>\
    \ {\n          auto __tmp = *this;\n          __tmp -= n;\n          return __tmp;\n\
    \        }\n        constexpr auto operator[](const difference_type n)\n     \
    \       const requires __detail::__all_random_access<_Range> {\n          return\
    \ __detail::_flatten(_M_current[n]);\n        }\n      };\n\n      class sentinel\
    \ {\n        std::ranges::sentinel_t<_Range> _M_end;\n\n      public:\n      \
    \  constexpr sentinel() = default;\n        constexpr explicit sentinel(const\
    \ decltype(_M_end)& __end)\n            : _M_end(__end) {}\n\n        friend constexpr\
    \ bool operator==(const iterator& __x,\n                                     \
    \    const sentinel& __y) {\n          return __x._M_current == __y._M_end;\n\
    \        }\n      };\n\n      _Range _M_views;\n      constexpr explicit flatten_view(const\
    \ _Range& __views)\n          : _M_views(__views) {}\n      constexpr auto begin()\
    \ { return iterator(std::ranges::begin(_M_views)); }\n      constexpr auto end()\
    \ { return sentinel(std::ranges::end(_M_views)); }\n    };\n\n  }  // namespace\
    \ ranges\n\n  namespace views {\n    namespace __detail {\n      template <typename...\
    \ _Args>\n      concept __can_flatten_view = requires {\n        ranges::flatten_view(std::declval<_Args>()...);\n\
    \      };\n    }  // namespace __detail\n\n    struct _Flatten : std::ranges::range_adaptor_closure<_Flatten>\
    \ {\n      template <class... _Tp>\n      requires __detail::__can_flatten_view<_Tp...>\n\
    \      constexpr auto operator() [[nodiscard]] (_Tp&&... __e) const {\n      \
    \  return ranges::flatten_view(std::forward<_Tp>(__e)...);\n      }\n      static\
    \ constexpr bool _S_has_simple_call_op = true;\n    };\n    struct _ProductN {\n\
    \      template <class... _Tp>\n      constexpr auto operator() [[nodiscard]]\
    \ (_Tp... __e) const {\n        return std::views::cartesian_product(std::views::iota(0,\
    \ __e)...);\n      }\n    };\n\n    inline constexpr _Flatten flatten{};\n   \
    \ inline constexpr _ProductN product_n{};\n  }  // namespace views\n}  // namespace\
    \ mtd\n#line 5 \"Library/Graph/Graph.hpp\"\n#include <tuple>\r\n#line 7 \"Library/Graph/Graph.hpp\"\
    \n\r\nnamespace mtd {\r\n  template <class Node = long long, class Cost = long\
    \ long>\r\n  class Graph {\r\n    using Edge = std::pair<Node, Cost>;\r\n    using\
    \ Edges = std::vector<Edge>;\r\n\r\n    const int m_n;\r\n    std::vector<Edges>\
    \ m_graph;\r\n\r\n  public:\r\n    Graph(int n) : m_n(n), m_graph(n) {}\r\n  \
    \  Graph(const std::vector<Edges>& edges)\r\n        : m_n(edges.size()), m_graph(edges)\
    \ {}\r\n    Graph(int n, const std::vector<std::tuple<Node, Node>>& edges,\r\n\
    \          bool is_arc = false, bool is_index1 = true)\r\n        : Graph<Node,\
    \ Cost>(n) {\r\n      for (auto [u, v] : edges) {\r\n        u -= is_index1;\r\
    \n        v -= is_index1;\r\n        if (is_arc) {\r\n          addArc(u, v);\r\
    \n        } else {\r\n          addEdge(u, v);\r\n        }\r\n      }\r\n   \
    \ }\r\n    Graph(int n, const std::vector<std::tuple<Node, Node, Cost>>& edges,\r\
    \n          bool is_arc = false, bool is_index1 = true)\r\n        : Graph<Node,\
    \ Cost>(n) {\r\n      for (auto [u, v, c] : edges) {\r\n        u -= is_index1;\r\
    \n        v -= is_index1;\r\n        if (is_arc) {\r\n          addArc(u, v, c);\r\
    \n        } else {\r\n          addEdge(u, v, c);\r\n        }\r\n      }\r\n\
    \    }\r\n\r\n    auto addEdge(const Node& f, const Node& t, const Cost& c = 1)\
    \ {\r\n      addArc(f, t, c);\r\n      addArc(t, f, c);\r\n    }\r\n    auto addArc(const\
    \ Node& f, const Node& t, const Cost& c = 1) {\r\n      m_graph[f].emplace_back(t,\
    \ c);\r\n    }\r\n    auto getEdges(const Node& from) const {\r\n      class EdgesRange\
    \ {\r\n        const typename Edges::const_iterator b, e;\r\n\r\n      public:\r\
    \n        EdgesRange(const Edges& edges) : b(edges.begin()), e(edges.end()) {}\r\
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
    \ Cost>(m_n);\r\n      for (const auto& [from, to, c] : getEdges()) { rev.addArc(to,\
    \ from, c); }\r\n      return rev;\r\n    }\r\n    auto size() const { return\
    \ m_n; };\r\n    auto debug(bool directed = false) const {\r\n      for (const\
    \ auto& [f, t, c] : getEdges()) {\r\n        if (f < t || directed) {\r\n    \
    \      std::cout << f << \" -> \" << t << \": \" << c << std::endl;\r\n      \
    \  }\r\n      }\r\n    }\r\n  };\r\n}  // namespace mtd\r\n#line 8 \"Library/Graph/Normal/Topological.hpp\"\
    \n\r\nnamespace mtd {\r\n  template <class Node, class Cost>\r\n  auto topological_order(const\
    \ mtd::Graph<Node, Cost>& graph) {\r\n    std::vector<Node> cnt(graph.size());\r\
    \n    for (auto [_, v] : graph.getEdgesExcludeCost()) { ++cnt[v]; }\r\n\r\n  \
    \  std::deque<Node> q;\r\n    for (auto [nd, c] : cnt | mtd::views::enumerate)\
    \ {\r\n      if (c == 0) { q.emplace_back(nd); }\r\n    }\r\n\r\n    std::vector<Node>\
    \ order;\r\n    while (!q.empty()) {\r\n      auto nd = q.front();\r\n      q.pop_front();\r\
    \n      order.emplace_back(nd);\r\n      for (auto [v, _] : graph.getEdges(nd))\
    \ {\r\n        --cnt[v];\r\n        if (cnt[v] == 0) { q.emplace_back(v); }\r\n\
    \      }\r\n    }\r\n    return order;\r\n  }\r\n}  // namespace mtd\r\n"
  code: "#pragma once\r\n\r\n#include <deque>\r\n#include <vector>\r\n\r\n#include\
    \ \"../../Range/util.hpp\"\r\n#include \"../Graph.hpp\"\r\n\r\nnamespace mtd {\r\
    \n  template <class Node, class Cost>\r\n  auto topological_order(const mtd::Graph<Node,\
    \ Cost>& graph) {\r\n    std::vector<Node> cnt(graph.size());\r\n    for (auto\
    \ [_, v] : graph.getEdgesExcludeCost()) { ++cnt[v]; }\r\n\r\n    std::deque<Node>\
    \ q;\r\n    for (auto [nd, c] : cnt | mtd::views::enumerate) {\r\n      if (c\
    \ == 0) { q.emplace_back(nd); }\r\n    }\r\n\r\n    std::vector<Node> order;\r\
    \n    while (!q.empty()) {\r\n      auto nd = q.front();\r\n      q.pop_front();\r\
    \n      order.emplace_back(nd);\r\n      for (auto [v, _] : graph.getEdges(nd))\
    \ {\r\n        --cnt[v];\r\n        if (cnt[v] == 0) { q.emplace_back(v); }\r\n\
    \      }\r\n    }\r\n    return order;\r\n  }\r\n}  // namespace mtd\r\n"
  dependsOn:
  - Library/Range/util.hpp
  - Library/Utility/Tuple.hpp
  - Library/Graph/Graph.hpp
  isVerificationFile: false
  path: Library/Graph/Normal/Topological.hpp
  requiredBy: []
  timestamp: '2025-12-20 01:59:21+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Test/Graph/Normal/Topological.test.cpp
documentation_of: Library/Graph/Normal/Topological.hpp
layout: document
redirect_from:
- /library/Library/Graph/Normal/Topological.hpp
- /library/Library/Graph/Normal/Topological.hpp.html
title: Library/Graph/Normal/Topological.hpp
---
