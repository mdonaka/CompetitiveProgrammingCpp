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
    path: Library/Range/istream.hpp
    title: Library/Range/istream.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Utility/io.hpp
    title: Library/Utility/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C
  bundledCode: "#line 1 \"Test/Graph/Normal/StronglyConnectedComponents.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C\"\r\n\r\n\
    // begin:tag includes\r\n#line 2 \"Library/Graph/Normal/StronglyConnectedComponents.hpp\"\
    \n\r\n#include <algorithm>\r\n#include <ranges>\r\n#include <unordered_set>\r\n\
    #include <vector>\r\n\r\n#line 2 \"Library/Graph/Graph.hpp\"\n#include <deque>\r\
    \n#include <iostream>\r\n#line 5 \"Library/Graph/Graph.hpp\"\n#include <tuple>\r\
    \n#line 7 \"Library/Graph/Graph.hpp\"\n\r\nnamespace mtd {\r\n  template <class\
    \ Node = int, class Cost = long long>\r\n  class Graph {\r\n    // using Node\
    \ = int;\r\n    // using Cost = long long;\r\n\r\n    using Edge = std::pair<Node,\
    \ Cost>;\r\n    using Edges = std::vector<Edge>;\r\n\r\n    const int m_n;\r\n\
    \    std::vector<Edges> m_graph;\r\n\r\n  public:\r\n    Graph(int n) : m_n(n),\
    \ m_graph(n) {}\r\n    Graph(const std::vector<Edges>& edges)\r\n        : m_n(edges.size()),\
    \ m_graph(edges) {}\r\n\r\n    auto addEdge(const Node& f, const Node& t, const\
    \ Cost& c = 1) {\r\n      m_graph[f].emplace_back(t, c);\r\n    }\r\n    auto\
    \ addEdgeUndirected(const Node& f, const Node& t, const Cost& c = 1) {\r\n   \
    \   addEdge(f, t, c);\r\n      addEdge(t, f, c);\r\n    }\r\n    auto getEdges(const\
    \ Node& from) const {\r\n      class EdgesRange {\r\n        const typename Edges::const_iterator\
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
    \ to, c] : getEdges()) { rev.addEdge(to, from, c); }\r\n      return rev;\r\n\
    \    }\r\n    auto size() const { return m_n; };\r\n    auto debug(bool directed\
    \ = false) const {\r\n      for (const auto& [f, t, c] : getEdges()) {\r\n   \
    \     if (f < t || directed) {\r\n          std::cout << f << \" -> \" << t <<\
    \ \": \" << c << std::endl;\r\n        }\r\n      }\r\n    }\r\n  };\r\n}  //\
    \ namespace mtd\r\n#line 9 \"Library/Graph/Normal/StronglyConnectedComponents.hpp\"\
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
    \ {}\r\n\r\n    constexpr auto isSameGroup(int a, int b) const {\r\n      return\
    \ m_group[a] == m_group[b];\r\n    }\r\n    constexpr auto getGroupNodes() const\
    \ {\r\n      auto size = *std::max_element(m_group.begin(), m_group.end()) + 1;\r\
    \n      std::vector<std::vector<int>> groupNodes(size);\r\n      for (int gi =\
    \ 0; gi < m_graph.size(); ++gi) {\r\n        groupNodes[m_group[gi]].emplace_back(gi);\r\
    \n      }\r\n      return groupNodes;\r\n    }\r\n    constexpr auto getGroupGraph()\
    \ const {\r\n      std::unordered_set<std::pair<int, int>, HashPair> st;\r\n \
    \     st.reserve(m_graph.size());\r\n      for (int f = 0; f < m_graph.size();\
    \ ++f) {\r\n        for (const auto& [t, _] : m_graph.getEdges(f)) {\r\n     \
    \     if (!isSameGroup(f, t)) { st.emplace(m_group[f], m_group[t]); }\r\n    \
    \    }\r\n      }\r\n      Graph<Node, Cost> ret(m_graph.size());\r\n      for\
    \ (const auto& [f, t] : st) { ret.addEdge(f, t); }\r\n      return ret;\r\n  \
    \  }\r\n  };\r\n}  // namespace mtd\r\n#line 5 \"Test/Graph/Normal/StronglyConnectedComponents.test.cpp\"\
    \n\r\n#line 2 \"Library/Range/istream.hpp\"\n\n#line 4 \"Library/Range/istream.hpp\"\
    \n\n#line 2 \"Library/Utility/io.hpp\"\n\n#line 5 \"Library/Utility/io.hpp\"\n\
    #include <type_traits>\n#line 7 \"Library/Utility/io.hpp\"\n\nnamespace mtd {\n\
    \  namespace io {\n\n    namespace type {\n      template <class T, int Pre =\
    \ 1, int Size = 0>\n      struct vec {\n        using value_type = T;\n      \
    \  static constexpr int pre = Pre;\n        static constexpr int size = Size;\n\
    \      };\n      template <class T>\n      concept is_vec = requires {\n     \
    \   std::is_same_v<T, vec<typename T::value_type, T::pre, T::size>>;\n      };\n\
    \    }  // namespace type\n\n    template <type::is_vec T>\n    auto _input(int\
    \ n) {\n      std::vector<typename T::value_type> v(n);\n      for (auto i : std::views::iota(0,\
    \ n)) { std::cin >> v[i]; }\n      return v;\n    }\n\n    template <class T>\n\
    \    auto _input() {\n      T x;\n      std::cin >> x;\n      return x;\n    }\n\
    \n    template <int N, class Tuple, class T, class... Args>\n    auto _tuple_input(Tuple&\
    \ t) {\n      if constexpr (type::is_vec<T>) {\n        if constexpr (T::size\
    \ == 0) {\n          std::get<N>(t) = _input<T>(std::get<N - T::pre>(t));\n  \
    \      } else {\n          std::get<N>(t) = _input<T>(T::size);\n        }\n \
    \     } else {\n        std::get<N>(t) = _input<T>();\n      }\n      if constexpr\
    \ (sizeof...(Args) > 0) {\n        _tuple_input<N + 1, Tuple, Args...>(t);\n \
    \     }\n    }\n\n    template <class T>\n    struct _Converter {\n      using\
    \ type = T;\n    };\n    template <class T, int Pre, int Size>\n    struct _Converter<type::vec<T,\
    \ Pre, Size>> {\n      using type = std::vector<T>;\n    };\n\n    template <class...\
    \ Args>\n    auto in() {\n      auto base = std::tuple<typename _Converter<Args>::type...>();\n\
    \      _tuple_input<0, decltype(base), Args...>(base);\n      return base;\n \
    \   }\n\n  }  // namespace io\n\n}  // namespace mtd\n#line 6 \"Library/Range/istream.hpp\"\
    \n\nnamespace mtd {\n  namespace ranges {\n\n    constexpr int _inf = 1e9;\n\n\
    \    template <class... Args>\n    struct istream_view\n        : public std::ranges::view_interface<istream_view<Args...>>\
    \ {\n      class iterator {\n        int count;\n        std::tuple<typename io::_Converter<Args>::type...>\
    \ val;\n\n      public:\n        using difference_type = int;\n        using value_type\
    \ = decltype(val);\n        using iterator_concept = std::input_iterator_tag;\n\
    \n        constexpr iterator() = default;\n        constexpr explicit iterator(int\
    \ count) : count(count) { operator++(); }\n\n        constexpr auto operator*()\
    \ const { return val; }\n        constexpr auto& operator++() {\n          --count;\n\
    \          if (count >= 0) { val = io::in<Args...>(); }\n          return *this;\n\
    \        }\n        constexpr auto operator++(int) { return ++*this; }\n\n   \
    \     constexpr auto operator==(const iterator& s) const {\n          return count\
    \ == s.count;\n        }\n        constexpr auto operator==(std::default_sentinel_t\
    \ s) const {\n          return count < 0 || std::cin.eof() || std::cin.fail()\
    \ ||\n                 std::cin.bad();\n        }\n        constexpr friend auto\
    \ operator==(std::default_sentinel_t s,\n                                    \
    \     const iterator& li) {\n          return li == s;\n        }\n      };\n\n\
    \      int count;\n\n    public:\n      constexpr explicit istream_view(int count)\
    \ : count(count) {}\n      constexpr explicit istream_view() : istream_view(_inf)\
    \ {}\n      constexpr auto begin() const { return iterator(count); }\n      constexpr\
    \ auto end() const { return std::default_sentinel; }\n    };\n  }  // namespace\
    \ ranges\n\n  namespace views {\n    namespace __detail {\n      template <typename...\
    \ _Args>\n      concept __can_istream_view = requires {\n        ranges::istream_view(std::declval<_Args>()...);\n\
    \      };\n    }  // namespace __detail\n\n    template <class... Args>\n    struct\
    \ _Istream {\n      template <class... _Tp>\n      requires __detail::__can_istream_view<_Tp...>\n\
    \      constexpr auto operator() [[nodiscard]] (_Tp&&... __e) const {\n      \
    \  return ranges::istream_view<Args...>(std::forward<_Tp>(__e)...);\n      }\n\
    \    };\n\n    template <class... Args>\n    inline constexpr _Istream<Args...>\
    \ istream{};\n  }  // namespace views\n\n}  // namespace mtd\n#line 8 \"Test/Graph/Normal/StronglyConnectedComponents.test.cpp\"\
    \n// end:tag includes\r\n\r\nsigned main() {\r\n  std::cin.tie(0);\r\n  std::ios::sync_with_stdio(0);\r\
    \n\r\n  auto [n, m] = mtd::io::in<int, int>();\r\n  auto graph = mtd::Graph(n);\r\
    \n  for (auto [f, t] : mtd::views::istream<int, int>(m)) { graph.addEdge(f, t);\
    \ }\r\n\r\n  auto scc = mtd::StronglyConnectedComponents(std::move(graph));\r\n\
    \r\n  auto [q] = mtd::io::in<int>();\r\n  for (auto [u, v] : mtd::views::istream<int,\
    \ int>(q)) {\r\n    std::cout << scc.isSameGroup(u, v) << std::endl;\r\n  }\r\n\
    }\r\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C\"\r\n\
    \r\n// begin:tag includes\r\n#include \"../../../Library/Graph/Normal/StronglyConnectedComponents.hpp\"\
    \r\n\r\n#include \"../../../Library/Graph/Graph.hpp\"\r\n#include \"../../../Library/Range/istream.hpp\"\
    \r\n// end:tag includes\r\n\r\nsigned main() {\r\n  std::cin.tie(0);\r\n  std::ios::sync_with_stdio(0);\r\
    \n\r\n  auto [n, m] = mtd::io::in<int, int>();\r\n  auto graph = mtd::Graph(n);\r\
    \n  for (auto [f, t] : mtd::views::istream<int, int>(m)) { graph.addEdge(f, t);\
    \ }\r\n\r\n  auto scc = mtd::StronglyConnectedComponents(std::move(graph));\r\n\
    \r\n  auto [q] = mtd::io::in<int>();\r\n  for (auto [u, v] : mtd::views::istream<int,\
    \ int>(q)) {\r\n    std::cout << scc.isSameGroup(u, v) << std::endl;\r\n  }\r\n\
    }\r\n"
  dependsOn:
  - Library/Graph/Normal/StronglyConnectedComponents.hpp
  - Library/Graph/Graph.hpp
  - Library/Range/istream.hpp
  - Library/Utility/io.hpp
  isVerificationFile: true
  path: Test/Graph/Normal/StronglyConnectedComponents.test.cpp
  requiredBy: []
  timestamp: '2024-11-19 07:35:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Graph/Normal/StronglyConnectedComponents.test.cpp
layout: document
redirect_from:
- /verify/Test/Graph/Normal/StronglyConnectedComponents.test.cpp
- /verify/Test/Graph/Normal/StronglyConnectedComponents.test.cpp.html
title: Test/Graph/Normal/StronglyConnectedComponents.test.cpp
---