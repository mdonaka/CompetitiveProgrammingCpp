---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Graph/Graph.hpp
    title: Library/Graph/Graph.hpp
  - icon: ':question:'
    path: Library/Range/util.hpp
    title: Library/Range/util.hpp
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
    #include <functional>\n#include <iostream>\n#include <ranges>\n\nnamespace mtd\
    \ {\n  namespace ranges {\n\n    namespace __detail {\n      template <class F,\
    \ class T>\n      constexpr auto __tuple_transform(F&& f, T&& t) {\n        return\
    \ std::apply(\n            [&]<class... Ts>(Ts&&... elems) {\n              return\
    \ std::tuple<std::invoke_result_t<F&, Ts>...>(\n                  std::invoke(f,\
    \ std::forward<Ts>(elems))...);\n            },\n            std::forward<T>(t));\n\
    \      }\n      template <class F, class T>\n      constexpr auto __tuple_for_each(F&&\
    \ f, T&& t) {\n        std::apply(\n            [&]<class... Ts>(Ts&&... elems)\
    \ {\n              (std::invoke(f, std::forward<Ts>(elems)), ...);\n         \
    \   },\n            std::forward<T>(t));\n      }\n      template <typename...\
    \ T>\n      concept __all_random_access = (std::ranges::random_access_range<T>\
    \ &&\n                                     ...);\n      template <typename...\
    \ T>\n      concept __all_bidirectional = (std::ranges::bidirectional_range<T>\
    \ &&\n                                     ...);\n      template <typename...\
    \ T>\n      concept __all_forward = (std::ranges::forward_range<T> && ...);\n\n\
    \      template <class... T>\n      constexpr auto _S_iter_concept() {\n     \
    \   if constexpr (__all_random_access<T...>) {\n          return std::random_access_iterator_tag{};\n\
    \        } else if constexpr (__all_bidirectional<T...>) {\n          return std::bidirectional_iterator_tag{};\n\
    \        } else if constexpr (__all_forward<T...>) {\n          return std::forward_iterator_tag{};\n\
    \        } else {\n          return std::input_iterator_tag{};\n        }\n  \
    \    }\n    }  // namespace __detail\n\n    template <std::ranges::range... _Range>\n\
    \    struct zip_view : public std::ranges::view_interface<zip_view<_Range...>>\
    \ {\n      class iterator {\n      public:\n        std::tuple<std::ranges::iterator_t<_Range>...>\
    \ _M_current;\n\n        using difference_type = int;\n        using value_type\
    \ = std::tuple<\n            std::iter_reference_t<std::ranges::iterator_t<_Range>>...>;\n\
    \        using iterator_concept =\n            decltype(__detail::_S_iter_concept<_Range...>());\n\
    \n        constexpr iterator() = default;\n        constexpr explicit iterator(const\
    \ decltype(_M_current)& __current)\n            : _M_current(__current) {}\n \
    \       constexpr auto operator*() const {\n          return __detail::__tuple_transform([](auto&\
    \ __i) { return *__i; },\n                                             _M_current);\n\
    \        }\n        constexpr auto& operator++() {\n          __detail::__tuple_for_each([](auto&\
    \ __i) { ++__i; }, _M_current);\n          return *this;\n        }\n        constexpr\
    \ auto operator++(int) { return ++*this; }\n        constexpr auto operator==(const\
    \ iterator& other) const {\n          return [&]<size_t... _Is>(std::index_sequence<_Is...>)\
    \ {\n            return ((std::get<_Is>(_M_current) ==\n                     std::get<_Is>(other._M_current))\
    \ ||\n                    ...);\n          }\n          (std::make_index_sequence<sizeof...(_Range)>{});\n\
    \        }\n        constexpr auto& operator--() requires\n            __detail::__all_bidirectional<_Range...>\
    \ {\n          __detail::__tuple_for_each([](auto& __i) { --__i; }, _M_current);\n\
    \          return *this;\n        }\n        constexpr auto operator--(\n    \
    \        int) requires __detail::__all_bidirectional<_Range...> {\n          return\
    \ --*this;\n        }\n        constexpr auto operator<=>(const iterator&)\n \
    \           const requires __detail::__all_random_access<_Range...>\n        =\
    \ default;\n        constexpr auto operator-(const iterator& itr)\n          \
    \  const requires __detail::__all_random_access<_Range...> {\n          return\
    \ [&]<size_t... _Is>(std::index_sequence<_Is...>) {\n            return std::ranges::min({difference_type(\n\
    \                std::get<_Is>(_M_current) - std::get<_Is>(itr._M_current))...});\n\
    \          }\n          (std::make_index_sequence<sizeof...(_Range)>{});\n   \
    \     }\n        constexpr auto& operator+=(const difference_type n) requires\n\
    \            __detail::__all_random_access<_Range...> {\n          __detail::__tuple_for_each([&n](auto&\
    \ __i) { __i += n; }, _M_current);\n          return *this;\n        }\n     \
    \   constexpr auto operator+(const difference_type n)\n            const requires\
    \ __detail::__all_random_access<_Range...> {\n          auto __r = *this;\n  \
    \        __r += n;\n          return __r;\n        }\n        constexpr friend\
    \ auto operator+(const difference_type n,\n                                  \
    \      const iterator& itr) requires\n            __detail::__all_random_access<_Range...>\
    \ {\n          return itr + n;\n        }\n        constexpr auto& operator-=(const\
    \ difference_type n) requires\n            __detail::__all_random_access<_Range...>\
    \ {\n          __detail::__tuple_for_each([&n](auto& __i) { __i -= n; }, _M_current);\n\
    \          return *this;\n        }\n        constexpr auto operator-(const difference_type\
    \ n)\n            const requires __detail::__all_random_access<_Range...> {\n\
    \          auto __r = *this;\n          __r -= n;\n          return __r;\n   \
    \     }\n        constexpr auto operator[](const difference_type n)\n        \
    \    const requires __detail::__all_random_access<_Range...> {\n          return\
    \ __detail::__tuple_transform([&n](auto& __i) { return __i[n]; },\n          \
    \                                   _M_current);\n        }\n      };\n\n    \
    \  class sentinel {\n      public:\n        std::tuple<std::ranges::sentinel_t<_Range>...>\
    \ _M_end;\n\n        constexpr sentinel() = default;\n        constexpr explicit\
    \ sentinel(const decltype(_M_end)& __end)\n            : _M_end(__end) {}\n\n\
    \        friend constexpr bool operator==(const iterator& __x,\n             \
    \                            const sentinel& __y) {\n          return [&]<size_t...\
    \ _Is>(std::index_sequence<_Is...>) {\n            return (\n                (std::get<_Is>(__x._M_current)\
    \ == std::get<_Is>(__y._M_end)) ||\n                ...);\n          }\n     \
    \     (std::make_index_sequence<sizeof...(_Range)>{});\n        }\n      };\n\n\
    \      std::tuple<_Range...> __r;\n      constexpr explicit zip_view(const _Range&...\
    \ __r) : __r(__r...) {}\n      constexpr auto begin() {\n        return iterator(__detail::__tuple_transform(std::ranges::begin,\
    \ __r));\n      }\n      constexpr auto end() {\n        return sentinel(__detail::__tuple_transform(std::ranges::end,\
    \ __r));\n      }\n    };\n\n    namespace __detail {\n      template <typename\
    \ T>\n      auto _flatten(const T& t) {\n        return std::make_tuple(t);\n\
    \      }\n      template <typename... T>\n      auto _flatten(const std::tuple<T...>&\
    \ t);\n\n      template <typename Head, typename... Tail>\n      auto _flatten_impl(const\
    \ Head& head, const Tail&... tail) {\n        return std::tuple_cat(_flatten(head),\
    \ _flatten(tail)...);\n      }\n      template <typename... T>\n      auto _flatten(const\
    \ std::tuple<T...>& t) {\n        return std::apply(\n            [](const auto&...\
    \ args) { return _flatten_impl(args...); }, t);\n      }\n    }  // namespace\
    \ __detail\n\n    template <std::ranges::range _Range>\n    struct flatten_view\n\
    \        : public std::ranges::view_interface<flatten_view<_Range>> {\n      class\
    \ iterator {\n      public:\n        std::ranges::iterator_t<_Range> _M_current;\n\
    \n        using difference_type = std::ranges::range_difference_t<_Range>;\n \
    \       using value_type = decltype(__detail::_flatten(\n            std::declval<\n\
    \                std::iter_reference_t<std::ranges::iterator_t<_Range>>>()));\n\
    \        using iterator_concept = decltype(__detail::_S_iter_concept<_Range>());\n\
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
    \ {\n          auto __r = *this;\n          __r += n;\n          return __r;\n\
    \        }\n        constexpr friend auto operator+(const difference_type n,\n\
    \                                        const iterator& itr) requires\n     \
    \       __detail::__all_random_access<_Range> {\n          return itr + n;\n \
    \       }\n        constexpr auto& operator-=(const difference_type n) requires\n\
    \            __detail::__all_random_access<_Range> {\n          _M_current -=\
    \ n;\n          return *this;\n        }\n        constexpr auto operator-(const\
    \ difference_type n)\n            const requires __detail::__all_random_access<_Range>\
    \ {\n          auto __r = *this;\n          __r -= n;\n          return __r;\n\
    \        }\n        constexpr auto operator[](const difference_type n)\n     \
    \       const requires __detail::__all_random_access<_Range> {\n          return\
    \ __detail::_flatten(_M_current[n]);\n        }\n      };\n\n      class sentinel\
    \ {\n        std::ranges::sentinel_t<_Range> _M_end;\n\n      public:\n      \
    \  constexpr sentinel() = default;\n        constexpr explicit sentinel(const\
    \ decltype(_M_end)& __end)\n            : _M_end(__end) {}\n\n        friend constexpr\
    \ bool operator==(const iterator& __x,\n                                     \
    \    const sentinel& __y) {\n          return __x._M_current == __y._M_end;\n\
    \        }\n      };\n\n      _Range __r;\n      constexpr explicit flatten_view(const\
    \ _Range& __r) : __r(__r) {}\n      constexpr auto begin() { return iterator(std::ranges::begin(__r));\
    \ }\n      constexpr auto end() { return sentinel(std::ranges::end(__r)); }\n\
    \    };\n\n  }  // namespace ranges\n\n  namespace views {\n    namespace __detail\
    \ {\n      template <typename... _Args>\n      concept __can_zip_view = requires\
    \ {\n        ranges::zip_view(std::declval<_Args>()...);\n      };\n      template\
    \ <typename... _Args>\n      concept __can_flatten_view = requires {\n       \
    \ ranges::flatten_view(std::declval<_Args>()...);\n      };\n    }  // namespace\
    \ __detail\n\n    struct _ZipView {\n      template <class... _Tp>\n      requires\
    \ __detail::__can_zip_view<_Tp...>\n      constexpr auto operator() [[nodiscard]]\
    \ (_Tp&&... __e) const {\n        return ranges::zip_view(std::forward<_Tp>(__e)...);\n\
    \      }\n    };\n    struct _Enumerate : std::views::__adaptor::_RangeAdaptorClosure\
    \ {\n      template <class _Tp>\n      requires __detail::__can_zip_view<std::ranges::iota_view<size_t>,\
    \ _Tp>\n      constexpr auto operator() [[nodiscard]] (_Tp&& __e) const {\n  \
    \      return ranges::zip_view{std::views::iota(0), std::forward<_Tp>(__e)};\n\
    \      }\n      static constexpr bool _S_has_simple_call_op = true;\n    };\n\
    \    struct _Flatten : std::views::__adaptor::_RangeAdaptorClosure {\n      template\
    \ <class... _Tp>\n      requires __detail::__can_flatten_view<_Tp...>\n      constexpr\
    \ auto operator() [[nodiscard]] (_Tp&&... __e) const {\n        return ranges::flatten_view(std::forward<_Tp>(__e)...);\n\
    \      }\n      static constexpr bool _S_has_simple_call_op = true;\n    };\n\n\
    \    inline constexpr _ZipView zip{};\n    inline constexpr _Enumerate enumerate{};\n\
    \    inline constexpr _Flatten flatten{};\n\n  }  // namespace views\n}  // namespace\
    \ mtd\n#line 5 \"Library/Graph/Graph.hpp\"\n#include <tuple>\r\n#line 7 \"Library/Graph/Graph.hpp\"\
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
  - Library/Graph/Graph.hpp
  isVerificationFile: false
  path: Library/Graph/Normal/Topological.hpp
  requiredBy: []
  timestamp: '2024-11-26 08:23:43+09:00'
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
