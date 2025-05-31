---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Graph.hpp
    title: Library/Graph/Graph.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Normal/StronglyConnectedComponents.hpp
    title: Library/Graph/Normal/StronglyConnectedComponents.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Normal/Topological.hpp
    title: Library/Graph/Normal/Topological.hpp
  - icon: ':question:'
    path: Library/Range/util.hpp
    title: Library/Range/util.hpp
  - icon: ':question:'
    path: Library/Utility/Tuple.hpp
    title: Library/Utility/Tuple.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/2780
    links:
    - https://yukicoder.me/problems/no/2780
  bundledCode: "#line 1 \"Test/Graph/Normal/Topological.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/2780\"\n#include <iostream>\n\n// begin:tag\
    \ includes\n#line 2 \"Library/Graph/Normal/StronglyConnectedComponents.hpp\"\n\
    \r\n#include <algorithm>\r\n#include <ranges>\r\n#include <set>\r\n#include <unordered_set>\r\
    \n#include <vector>\r\n\r\n#line 2 \"Library/Graph/Graph.hpp\"\n#include <deque>\r\
    \n#line 5 \"Library/Graph/Graph.hpp\"\n#include <tuple>\r\n#line 7 \"Library/Graph/Graph.hpp\"\
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
    \  }\r\n      }\r\n    }\r\n  };\r\n}  // namespace mtd\r\n#line 10 \"Library/Graph/Normal/StronglyConnectedComponents.hpp\"\
    \n\r\nnamespace mtd {\r\n  template <class Node, class Cost>\r\n  class StronglyConnectedComponents\
    \ {\r\n    struct HashPair {\r\n      template <class T1, class T2>\r\n      size_t\
    \ operator()(const std::pair<T1, T2>& p) const {\r\n        auto hash1 = std::hash<T1>{}(p.first);\r\
    \n        auto hash2 = std::hash<T2>{}(p.second);\r\n        size_t seed = 0;\r\
    \n        seed ^= hash1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);\r\n        seed\
    \ ^= hash2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);\r\n        return seed;\r\
    \n      }\r\n    };\r\n\r\n    const Graph<Node, Cost> m_graph;\r\n    const std::vector<int>\
    \ m_group;\r\n\r\n    template <class F>\r\n    constexpr static inline auto dfs(const\
    \ Graph<Node, Cost>& graph, int from,\r\n                                    \
    \ std::vector<bool>& is_used, const F& f)\r\n        -> void {\r\n      is_used[from]\
    \ = true;\r\n      for (const auto& [to, _] : graph.getEdges(from)) {\r\n    \
    \    if (is_used[to]) { continue; }\r\n        dfs(graph, to, is_used, f);\r\n\
    \      }\r\n      f(from);\r\n    }\r\n\r\n    constexpr static auto constructGroup(const\
    \ Graph<Node, Cost>& graph) {\r\n      int n = graph.size();\r\n      std::vector<Node>\
    \ order;\r\n      std::vector<bool> is_used(n);\r\n      for (auto from : std::views::iota(0,\
    \ n)) {\r\n        if (is_used[from]) { continue; }\r\n        dfs(graph, from,\
    \ is_used, [&](int f) { order.emplace_back(f); });\r\n      }\r\n\r\n      int\
    \ g = 0;\r\n      std::vector<Node> group(n);\r\n      std::vector<bool> is_used2(n);\r\
    \n      auto rev = graph.reverse();\r\n      for (auto from : order | std::views::reverse)\
    \ {\r\n        if (is_used2[from]) { continue; }\r\n        dfs(rev, from, is_used2,\
    \ [&](int f) { group[f] = g; });\r\n        ++g;\r\n      }\r\n      return group;\r\
    \n    }\r\n\r\n  public:\r\n    [[deprecated]] constexpr StronglyConnectedComponents(\r\
    \n        const Graph<Node, Cost>& graph)\r\n        : m_graph(graph), m_group(constructGroup(m_graph))\
    \ {}\r\n    // graph\u306E\u30B3\u30D4\u30FC\u30B3\u30B9\u30C8\u304C\u5927\u304D\
    \u3044\u306E\u3067\u3053\u3063\u3061\u63A8\u5968\r\n    constexpr StronglyConnectedComponents(Graph<Node,\
    \ Cost>&& graph)\r\n        : m_graph(std::move(graph)), m_group(constructGroup(m_graph))\
    \ {}\r\n\r\n    constexpr auto size() const {\r\n      return *std::max_element(m_group.begin(),\
    \ m_group.end()) + 1;\r\n    }\r\n    constexpr auto group(int a) const { return\
    \ m_group[a]; }\r\n    constexpr auto isSameGroup(int a, int b) const {\r\n  \
    \    return m_group[a] == m_group[b];\r\n    }\r\n    constexpr auto getGroupNodes()\
    \ const {\r\n      std::vector<std::vector<int>> groupNodes(size());\r\n     \
    \ for (int gi = 0; gi < m_graph.size(); ++gi) {\r\n        groupNodes[m_group[gi]].emplace_back(gi);\r\
    \n      }\r\n      return groupNodes;\r\n    }\r\n    constexpr auto getGroupGraph()\
    \ const {\r\n      std::unordered_set<std::pair<int, int>, HashPair> st;\r\n \
    \     st.reserve(m_graph.size());\r\n      for (int f = 0; f < m_graph.size();\
    \ ++f) {\r\n        for (const auto& [t, _] : m_graph.getEdges(f)) {\r\n     \
    \     if (!isSameGroup(f, t)) { st.emplace(m_group[f], m_group[t]); }\r\n    \
    \    }\r\n      }\r\n      Graph<Node, Cost> ret(size());\r\n      for (const\
    \ auto& [f, t] : st) { ret.addEdge(f, t); }\r\n      return ret;\r\n    }\r\n\
    \  };\r\n}  // namespace mtd\r\n#line 2 \"Library/Graph/Normal/Topological.hpp\"\
    \n\r\n#line 5 \"Library/Graph/Normal/Topological.hpp\"\n\r\n#line 2 \"Library/Range/util.hpp\"\
    \n\n#line 6 \"Library/Range/util.hpp\"\n\n#line 2 \"Library/Utility/Tuple.hpp\"\
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
    \    }\n    }  // namespace __detail\n\n    template <std::ranges::range... _Range>\n\
    \    struct zip_view : public std::ranges::view_interface<zip_view<_Range...>>\
    \ {\n      class iterator {\n      public:\n        std::tuple<std::ranges::iterator_t<_Range>...>\
    \ _M_current;\n\n        using difference_type = int;\n        using value_type\
    \ = std::tuple<\n            std::iter_reference_t<std::ranges::iterator_t<_Range>>...>;\n\
    \        using iterator_concept =\n            decltype(__detail::_S_iter_concept<_Range...>());\n\
    \n        constexpr iterator() = default;\n        constexpr explicit iterator(const\
    \ decltype(_M_current)& __current)\n            : _M_current(__current) {}\n \
    \       constexpr auto operator*() const {\n          return util::tuple_transform([](auto&\
    \ __i) { return *__i; },\n                                       _M_current);\n\
    \        }\n        constexpr auto& operator++() {\n          util::tuple_for_each([](auto&\
    \ __i) { ++__i; }, _M_current);\n          return *this;\n        }\n        constexpr\
    \ auto operator++(int) { return ++*this; }\n        constexpr auto operator==(const\
    \ iterator& other) const {\n          return [&]<size_t... _Is>(std::index_sequence<_Is...>)\
    \ {\n            return ((std::get<_Is>(_M_current) ==\n                     std::get<_Is>(other._M_current))\
    \ ||\n                    ...);\n          }\n          (std::make_index_sequence<sizeof...(_Range)>{});\n\
    \        }\n        constexpr auto& operator--() requires\n            __detail::__all_bidirectional<_Range...>\
    \ {\n          util::tuple_for_each([](auto& __i) { --__i; }, _M_current);\n \
    \         return *this;\n        }\n        constexpr auto operator--(\n     \
    \       int) requires __detail::__all_bidirectional<_Range...> {\n          return\
    \ --*this;\n        }\n        constexpr auto operator<=>(const iterator&)\n \
    \           const requires __detail::__all_random_access<_Range...>\n        =\
    \ default;\n        constexpr auto operator-(const iterator& itr)\n          \
    \  const requires __detail::__all_random_access<_Range...> {\n          return\
    \ [&]<size_t... _Is>(std::index_sequence<_Is...>) {\n            return std::ranges::min({difference_type(\n\
    \                std::get<_Is>(_M_current) - std::get<_Is>(itr._M_current))...});\n\
    \          }\n          (std::make_index_sequence<sizeof...(_Range)>{});\n   \
    \     }\n        constexpr auto& operator+=(const difference_type n) requires\n\
    \            __detail::__all_random_access<_Range...> {\n          util::tuple_for_each([&n](auto&\
    \ __i) { __i += n; }, _M_current);\n          return *this;\n        }\n     \
    \   constexpr auto operator+(const difference_type n)\n            const requires\
    \ __detail::__all_random_access<_Range...> {\n          auto __tmp = *this;\n\
    \          __tmp += n;\n          return __tmp;\n        }\n        constexpr\
    \ friend auto operator+(const difference_type n,\n                           \
    \             const iterator& itr) requires\n            __detail::__all_random_access<_Range...>\
    \ {\n          return itr + n;\n        }\n        constexpr auto& operator-=(const\
    \ difference_type n) requires\n            __detail::__all_random_access<_Range...>\
    \ {\n          util::tuple_for_each([&n](auto& __i) { __i -= n; }, _M_current);\n\
    \          return *this;\n        }\n        constexpr auto operator-(const difference_type\
    \ n)\n            const requires __detail::__all_random_access<_Range...> {\n\
    \          auto __tmp = *this;\n          __tmp -= n;\n          return __tmp;\n\
    \        }\n        constexpr auto operator[](const difference_type n)\n     \
    \       const requires __detail::__all_random_access<_Range...> {\n          return\
    \ util::tuple_transform([&n](auto& __i) { return __i[n]; },\n                \
    \                       _M_current);\n        }\n      };\n\n      class sentinel\
    \ {\n      public:\n        std::tuple<std::ranges::sentinel_t<_Range>...> _M_end;\n\
    \n        constexpr sentinel() = default;\n        constexpr explicit sentinel(const\
    \ decltype(_M_end)& __end)\n            : _M_end(__end) {}\n\n        friend constexpr\
    \ bool operator==(const iterator& __x,\n                                     \
    \    const sentinel& __y) {\n          return [&]<size_t... _Is>(std::index_sequence<_Is...>)\
    \ {\n            return (\n                (std::get<_Is>(__x._M_current) == std::get<_Is>(__y._M_end))\
    \ ||\n                ...);\n          }\n          (std::make_index_sequence<sizeof...(_Range)>{});\n\
    \        }\n      };\n\n      std::tuple<_Range...> _M_views;\n      constexpr\
    \ explicit zip_view(const _Range&... __views)\n          : _M_views(__views...)\
    \ {}\n      constexpr auto begin() {\n        return iterator(util::tuple_transform(std::ranges::begin,\
    \ _M_views));\n      }\n      constexpr auto end() {\n        return sentinel(util::tuple_transform(std::ranges::end,\
    \ _M_views));\n      }\n    };\n\n    namespace __detail {\n      template <typename\
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
    \ { return sentinel(std::ranges::end(_M_views)); }\n    };\n\n    template <std::ranges::range...\
    \ _Range>\n    struct cartesian_product_view : public std::ranges::view_interface<\n\
    \                                        cartesian_product_view<_Range...>> {\n\
    \      class iterator {\n      public:\n        using _Parent = cartesian_product_view;\n\
    \        _Parent* _M_parent = nullptr;\n        std::tuple<std::ranges::iterator_t<_Range>...>\
    \ _M_current;\n\n        using difference_type = int;\n        using value_type\
    \ = std::tuple<\n            std::iter_reference_t<std::ranges::iterator_t<_Range>>...>;\n\
    \        using iterator_concept =\n            decltype(__detail::_S_iter_concept<_Range...>());\n\
    \n      private:\n        template <size_t _Nm = sizeof...(_Range) - 1>\n    \
    \    constexpr void _M_next() {\n          auto& __it = std::get<_Nm>(_M_current);\n\
    \          ++__it;\n          if constexpr (_Nm > 0)\n            if (__it ==\
    \ std::ranges::end(std::get<_Nm>(_M_parent->_M_views))) {\n              __it\
    \ = std::ranges::begin(std::get<_Nm>(_M_parent->_M_views));\n              _M_next<_Nm\
    \ - 1>();\n            }\n        }\n        template <size_t _Nm = sizeof...(_Range)\
    \ - 1>\n        constexpr void _M_prev() {\n          auto& __it = std::get<_Nm>(_M_current);\n\
    \          if constexpr (_Nm > 0)\n            if (__it ==\n                std::ranges::begin(std::get<_Nm>(_M_parent->_M_views)))\
    \ {\n              __it = std::ranges::end(std::get<_Nm>(_M_parent->_M_views));\n\
    \              _M_prev<_Nm - 1>();\n            }\n          --__it;\n       \
    \ }\n\n        template <size_t _Nm = sizeof...(_Range) - 1>\n        constexpr\
    \ void _M_advance(difference_type __x) requires\n            __detail::__all_random_access<_Range...>\
    \ {\n          if (__x == 1)\n            _M_next<_Nm>();\n          else if (__x\
    \ == -1)\n            _M_prev<_Nm>();\n          else if (__x != 0) {\n      \
    \      auto& __r = std::get<_Nm>(_M_parent->_M_views);\n            auto& __it\
    \ = std::get<_Nm>(_M_current);\n            if constexpr (_Nm == 0) {\n      \
    \        __it += __x;\n            } else {\n              auto __size = std::ranges::ssize(__r);\n\
    \              auto __begin = std::ranges::begin(__r);\n              auto __offset\
    \ = __it - __begin;\n              __offset += __x;\n              __x = __offset\
    \ / __size;\n              __offset %= __size;\n              if (__offset < 0)\
    \ {\n                __offset = __size + __offset;\n                --__x;\n \
    \             }\n              __it = __begin + __offset;\n              _M_advance<_Nm\
    \ - 1>(__x);\n            }\n          }\n        }\n\n      public:\n       \
    \ constexpr iterator() = default;\n        constexpr explicit iterator(_Parent&\
    \ __parent,\n                                    const decltype(_M_current)& __current)\n\
    \            : _M_parent(std::addressof(__parent)), _M_current(__current) {}\n\
    \        constexpr auto operator*() const {\n          return util::tuple_transform([](auto&\
    \ __i) { return *__i; },\n                                       _M_current);\n\
    \        }\n        constexpr auto& operator++() {\n          _M_next();\n   \
    \       return *this;\n        }\n        constexpr auto operator++(int) { return\
    \ ++*this; }\n        constexpr auto operator==(const iterator& other) const {\n\
    \          return [&]<size_t... _Is>(std::index_sequence<_Is...>) {\n        \
    \    return ((std::get<_Is>(_M_current) ==\n                     std::get<_Is>(other._M_current))\
    \ ||\n                    ...);\n          }\n          (std::make_index_sequence<sizeof...(_Range)>{});\n\
    \        }\n        constexpr auto& operator--() requires\n            __detail::__all_bidirectional<_Range...>\
    \ {\n          _M_prev();\n          return *this;\n        }\n        constexpr\
    \ auto operator--(\n            int) requires __detail::__all_bidirectional<_Range...>\
    \ {\n          return --*this;\n        }\n        constexpr auto operator<=>(const\
    \ iterator&)\n            const requires __detail::__all_random_access<_Range...>\n\
    \        = default;\n        constexpr auto operator-(const iterator& itr)\n \
    \           const requires __detail::__all_random_access<_Range...> {\n      \
    \    return [&]<size_t... _Is>(std::index_sequence<_Is...>) {\n            return\
    \ std::ranges::min({difference_type(\n                std::get<_Is>(_M_current)\
    \ - std::get<_Is>(itr._M_current))...});\n          }\n          (std::make_index_sequence<sizeof...(_Range)>{});\n\
    \        }\n        constexpr auto& operator+=(const difference_type n) requires\n\
    \            __detail::__all_random_access<_Range...> {\n          _M_advance(n);\n\
    \          return *this;\n        }\n        constexpr auto operator+(const difference_type\
    \ n)\n            const requires __detail::__all_random_access<_Range...> {\n\
    \          auto __tmp = *this;\n          __tmp += n;\n          return __tmp;\n\
    \        }\n        constexpr friend auto operator+(const difference_type n,\n\
    \                                        const iterator& itr) requires\n     \
    \       __detail::__all_random_access<_Range...> {\n          return itr + n;\n\
    \        }\n        constexpr auto& operator-=(const difference_type n) requires\n\
    \            __detail::__all_random_access<_Range...> {\n          *this += -n;\n\
    \          return *this;\n        }\n        constexpr auto operator-(const difference_type\
    \ n)\n            const requires __detail::__all_random_access<_Range...> {\n\
    \          auto __tmp = *this;\n          __tmp -= n;\n          return __tmp;\n\
    \        }\n        constexpr auto operator[](const difference_type n)\n     \
    \       const requires __detail::__all_random_access<_Range...> {\n          return\
    \ util::tuple_transform([&n](auto& __i) { return __i[n]; },\n                \
    \                       _M_current);\n        }\n      };\n\n      class sentinel\
    \ {\n      public:\n        std::tuple<std::ranges::sentinel_t<_Range>...> _M_end;\n\
    \n        constexpr sentinel() = default;\n        constexpr explicit sentinel(const\
    \ decltype(_M_end)& __end)\n            : _M_end(__end) {}\n\n        friend constexpr\
    \ bool operator==(const iterator& __x,\n                                     \
    \    const sentinel& __y) {\n          return [&]<size_t... _Is>(std::index_sequence<_Is...>)\
    \ {\n            return (\n                (std::get<_Is>(__x._M_current) == std::get<_Is>(__y._M_end))\
    \ ||\n                ...);\n          }\n          (std::make_index_sequence<sizeof...(_Range)>{});\n\
    \        }\n      };\n\n      std::tuple<_Range...> _M_views;\n      constexpr\
    \ explicit cartesian_product_view(const _Range&... __views)\n          : _M_views(__views...)\
    \ {}\n      constexpr auto begin() {\n        return iterator(*this,\n       \
    \                 util::tuple_transform(std::ranges::begin, _M_views));\n    \
    \  }\n      constexpr auto end() {\n        return sentinel(util::tuple_transform(std::ranges::end,\
    \ _M_views));\n      }\n    };\n\n  }  // namespace ranges\n\n  namespace views\
    \ {\n    namespace __detail {\n      template <typename... _Args>\n      concept\
    \ __can_zip_view = requires {\n        ranges::zip_view(std::declval<_Args>()...);\n\
    \      };\n      template <typename... _Args>\n      concept __can_flatten_view\
    \ = requires {\n        ranges::flatten_view(std::declval<_Args>()...);\n    \
    \  };\n      template <typename... _Args>\n      concept __can_cartesian_product_view\
    \ = requires {\n        ranges::cartesian_product_view(std::declval<_Args>()...);\n\
    \      };\n    }  // namespace __detail\n\n    struct _ZipView {\n      template\
    \ <class... _Tp>\n      requires __detail::__can_zip_view<_Tp...>\n      constexpr\
    \ auto operator() [[nodiscard]] (_Tp&&... __e) const {\n        return ranges::zip_view(std::forward<_Tp>(__e)...);\n\
    \      }\n    };\n    struct _Enumerate : std::views::__adaptor::_RangeAdaptorClosure\
    \ {\n      template <class _Tp>\n      requires __detail::__can_zip_view<std::ranges::iota_view<size_t>,\
    \ _Tp>\n      constexpr auto operator() [[nodiscard]] (_Tp&& __e) const {\n  \
    \      return ranges::zip_view{std::views::iota(0), std::forward<_Tp>(__e)};\n\
    \      }\n      static constexpr bool _S_has_simple_call_op = true;\n    };\n\
    \    struct _Flatten : std::views::__adaptor::_RangeAdaptorClosure {\n      template\
    \ <class... _Tp>\n      requires __detail::__can_flatten_view<_Tp...>\n      constexpr\
    \ auto operator() [[nodiscard]] (_Tp&&... __e) const {\n        return ranges::flatten_view(std::forward<_Tp>(__e)...);\n\
    \      }\n      static constexpr bool _S_has_simple_call_op = true;\n    };\n\
    \    struct _CartesianProduct {\n      template <class... _Tp>\n      requires\
    \ __detail::__can_cartesian_product_view<_Tp...>\n      constexpr auto operator()\
    \ [[nodiscard]] (_Tp&&... __e) const {\n        return ranges::cartesian_product_view(std::forward<_Tp>(__e)...);\n\
    \      }\n    };\n    struct _ProductN {\n      template <class... _Tp>\n    \
    \  requires __detail::__can_cartesian_product_view<\n          std::ranges::iota_view<size_t,\
    \ _Tp>...>\n      constexpr auto operator() [[nodiscard]] (_Tp... __e) const {\n\
    \        return ranges::cartesian_product_view(std::views::iota(0, __e)...);\n\
    \      }\n    };\n\n    inline constexpr _ZipView zip{};\n    inline constexpr\
    \ _Enumerate enumerate{};\n    inline constexpr _Flatten flatten{};\n    inline\
    \ constexpr _CartesianProduct cartesian_product{};\n    inline constexpr _ProductN\
    \ product_n{};\n  }  // namespace views\n}  // namespace mtd\n#line 8 \"Library/Graph/Normal/Topological.hpp\"\
    \n\r\nnamespace mtd {\r\n  template <class Node, class Cost>\r\n  auto topological_order(const\
    \ mtd::Graph<Node, Cost>& graph) {\r\n    std::vector<Node> cnt(graph.size());\r\
    \n    for (auto [_, v] : graph.getEdgesExcludeCost()) { ++cnt[v]; }\r\n\r\n  \
    \  std::deque<Node> q;\r\n    for (auto [nd, c] : cnt | mtd::views::enumerate)\
    \ {\r\n      if (c == 0) { q.emplace_back(nd); }\r\n    }\r\n\r\n    std::vector<Node>\
    \ order;\r\n    while (!q.empty()) {\r\n      auto nd = q.front();\r\n      q.pop_front();\r\
    \n      order.emplace_back(nd);\r\n      for (auto [v, _] : graph.getEdges(nd))\
    \ {\r\n        --cnt[v];\r\n        if (cnt[v] == 0) { q.emplace_back(v); }\r\n\
    \      }\r\n    }\r\n    return order;\r\n  }\r\n}  // namespace mtd\r\n#line\
    \ 7 \"Test/Graph/Normal/Topological.test.cpp\"\n// end:tag includes\n\nint main()\
    \ {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(0);\n\n  int n;\n  std::cin\
    \ >> n;\n  auto graph = mtd::Graph<>(n);\n  for (auto u : std::views::iota(0,\
    \ n)) {\n    int m;\n    std::cin >> m;\n    for ([[maybe_unused]] auto _ : std::views::iota(0,\
    \ m)) {\n      int v;\n      std::cin >> v;\n      graph.addEdge(u, v - 1);\n\
    \    }\n  }\n\n  auto scc = mtd::StronglyConnectedComponents(std::move(graph));\n\
    \  auto scc_graph = scc.getGroupGraph();\n  auto scc_nodes = scc.getGroupNodes();\n\
    \n  int now = -1;\n  bool yes = true;\n  for (auto u : mtd::topological_order(scc_graph))\
    \ {\n    bool ex = (now == -1 ? u == scc.group(0) : false);\n    if (now > -1)\
    \ {\n      for (auto [v, _] : scc_graph.getEdges(now)) { ex |= (u == v); }\n \
    \   }\n    yes &= ex;\n    now = u;\n  }\n\n  std::cout << (yes ? \"Yes\" : \"\
    No\") << std::endl;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/2780\"\n#include <iostream>\n\
    \n// begin:tag includes\n#include \"../../../Library/Graph/Normal/StronglyConnectedComponents.hpp\"\
    \n#include \"../../../Library/Graph/Normal/Topological.hpp\"\n// end:tag includes\n\
    \nint main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(0);\n\n  int n;\n\
    \  std::cin >> n;\n  auto graph = mtd::Graph<>(n);\n  for (auto u : std::views::iota(0,\
    \ n)) {\n    int m;\n    std::cin >> m;\n    for ([[maybe_unused]] auto _ : std::views::iota(0,\
    \ m)) {\n      int v;\n      std::cin >> v;\n      graph.addEdge(u, v - 1);\n\
    \    }\n  }\n\n  auto scc = mtd::StronglyConnectedComponents(std::move(graph));\n\
    \  auto scc_graph = scc.getGroupGraph();\n  auto scc_nodes = scc.getGroupNodes();\n\
    \n  int now = -1;\n  bool yes = true;\n  for (auto u : mtd::topological_order(scc_graph))\
    \ {\n    bool ex = (now == -1 ? u == scc.group(0) : false);\n    if (now > -1)\
    \ {\n      for (auto [v, _] : scc_graph.getEdges(now)) { ex |= (u == v); }\n \
    \   }\n    yes &= ex;\n    now = u;\n  }\n\n  std::cout << (yes ? \"Yes\" : \"\
    No\") << std::endl;\n}\n"
  dependsOn:
  - Library/Graph/Normal/StronglyConnectedComponents.hpp
  - Library/Graph/Graph.hpp
  - Library/Graph/Normal/Topological.hpp
  - Library/Range/util.hpp
  - Library/Utility/Tuple.hpp
  isVerificationFile: true
  path: Test/Graph/Normal/Topological.test.cpp
  requiredBy: []
  timestamp: '2025-01-24 16:53:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Graph/Normal/Topological.test.cpp
layout: document
redirect_from:
- /verify/Test/Graph/Normal/Topological.test.cpp
- /verify/Test/Graph/Normal/Topological.test.cpp.html
title: Test/Graph/Normal/Topological.test.cpp
---
