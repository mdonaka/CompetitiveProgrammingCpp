---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Algebraic/Monoid.hpp
    title: Library/Algebraic/Monoid.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Graph.hpp
    title: Library/Graph/Graph.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Normal/BFS.hpp
    title: Library/Graph/Normal/BFS.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Tree/ReRootingDP.hpp
    title: Library/Graph/Tree/ReRootingDP.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Tree/TreeDP.hpp
    title: Library/Graph/Tree/TreeDP.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Math/Math.hpp
    title: Library/Math/Math.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Math/ModInt.hpp
    title: Library/Math/ModInt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/2360
    links:
    - https://yukicoder.me/problems/no/2360
  bundledCode: "#line 1 \"Test/Graph/Tree/ReRootingDP.test.cpp\"\n#include <vector>\n\
    #define PROBLEM \"https://yukicoder.me/problems/no/2360\"\n\n#include <iostream>\n\
    \n// begin:tag includes\n#line 2 \"Library/Graph/Tree/ReRootingDP.hpp\"\n#include\
    \ <unordered_map>\r\n#line 4 \"Library/Graph/Tree/ReRootingDP.hpp\"\n\r\n#line\
    \ 2 \"Library/Algebraic/Monoid.hpp\"\n\n#line 4 \"Library/Algebraic/Monoid.hpp\"\
    \n\nnamespace mtd {\n\n  template <class S,    // set\n            S element,\
    \  // identity element\n            class op    // binary operation\n        \
    \    >\n  requires std::is_invocable_r_v<S, op, S, S>\n  struct Monoid {\n   \
    \ using value_type = S;\n    constexpr static S _element = element;\n    using\
    \ op_type = op;\n\n    S m_val;\n    constexpr Monoid(S val) : m_val(val) {}\n\
    \    constexpr Monoid() : Monoid(element) {}\n    constexpr Monoid binaryOperation(const\
    \ Monoid& m2) const {\n      return op()(m_val, m2.m_val);\n    }\n    friend\
    \ std::ostream& operator<<(std::ostream& os,\n                               \
    \     const Monoid<S, element, op>& m) {\n      return os << m.m_val;\n    }\n\
    \  };\n\n  namespace __detail {\n    template <typename T, template <typename,\
    \ auto, typename> typename S>\n    concept is_specialization_of = requires {\n\
    \      typename std::enable_if_t<std::is_same_v<\n          T, S<typename T::value_type,\
    \ T::_element, typename T::op_type>>>;\n    };\n  }  // namespace __detail\n\n\
    \  template <typename M>\n  concept monoid = __detail::is_specialization_of<M,\
    \ Monoid>;\n\n}  // namespace mtd\n#line 2 \"Library/Graph/Normal/BFS.hpp\"\n\r\
    \n#include <queue>\r\n#line 5 \"Library/Graph/Normal/BFS.hpp\"\n\r\n#line 2 \"\
    Library/Graph/Graph.hpp\"\n#include <deque>\r\n#line 4 \"Library/Graph/Graph.hpp\"\
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
    \  }\r\n      }\r\n    }\r\n  };\r\n}  // namespace mtd\r\n#line 7 \"Library/Graph/Normal/BFS.hpp\"\
    \n\r\nnamespace mtd {\r\n  template <class Node, class Cost, class Lambda>\r\n\
    \  auto bfs(const Graph<Node, Cost>& graph, const Node& root,\r\n           const\
    \ Lambda& lambda) {\r\n    auto n = graph.size();\r\n    std::vector<bool> used(n);\r\
    \n    used[root] = true;\r\n    std::queue<Node> q;\r\n    q.emplace(root);\r\n\
    \    while (!q.empty()) {\r\n      auto from = q.front();\r\n      q.pop();\r\n\
    \      for (const auto& [to, cost] : graph.getEdges(from)) {\r\n        if (used[to])\
    \ { continue; }\r\n        q.emplace(to);\r\n        used[to] = true;\r\n    \
    \    lambda(from, to, cost);\r\n      }\r\n    }\r\n  }\r\n}  // namespace mtd\r\
    \n#line 4 \"Library/Graph/Tree/TreeDP.hpp\"\n\r\n#line 6 \"Library/Graph/Tree/TreeDP.hpp\"\
    \n\r\nnamespace mtd {\r\n  template <class Node, class Cost, class Lambda>\r\n\
    \  auto treeDP(const Graph<Node, Cost>& tree, Node root, const Lambda& lambda)\
    \ {\r\n    auto n = tree.size();\r\n    std::vector<Node> in(n);\r\n    for (const\
    \ auto& [f, t] : tree.getEdgesExcludeCost())\r\n      if (f < t) {\r\n       \
    \ ++in[f];\r\n        ++in[t];\r\n      }\r\n    std::queue<Node> q;\r\n    std::vector<bool>\
    \ used(n);\r\n    for (Node i = 0; i < n; ++i)\r\n      if (i != root && in[i]\
    \ == 1) { q.emplace(i); }\r\n    while (!q.empty()) {\r\n      auto from = q.front();\r\
    \n      q.pop();\r\n      used[from] = true;\r\n\r\n      for (const auto& [to,\
    \ cost] : tree.getEdges(from)) {\r\n        if (used[to]) { continue; }\r\n  \
    \      lambda(from, to, cost);\r\n        --in[to];\r\n        if (to != root\
    \ && in[to] == 1) { q.emplace(to); }\r\n      }\r\n    }\r\n  }\r\n}  // namespace\
    \ mtd\r\n#line 8 \"Library/Graph/Tree/ReRootingDP.hpp\"\n\r\nnamespace mtd {\r\
    \n  /*\r\n   * Monoid: \u90E8\u5206\u6728\u306E\u60C5\u5831\r\n   * edge_f: \u8FBA\
    \u306E\u60C5\u5831\u3092\u89AA\u306B\u6D41\u3059\u95A2\u6570: (M, f, t, c) ->\
    \ M\r\n   * node_f: \u5B50\u306E\u60C5\u5831\u3092\u89AA\u306B\u6D41\u3059\u95A2\
    \u6570: (M, i) -> M\r\n   */\r\n  template <monoid Monoid, class Node, class Cost,\
    \ class Lambda1, class Lambda2>\r\n  auto reRootingDP(const Graph<Node, Cost>&\
    \ graph, const Lambda1& edge_f,\r\n                   const Lambda2& node_f) {\r\
    \n    constexpr int root = 0;\r\n    auto n = graph.size();\r\n\r\n    // <\u8FBA\
    \u60C5\u5831\u3092\u8003\u616E\u3057\u305FMonoid\u306E2\u9805\u6F14\u7B97>\r\n\
    \    auto merge = [&](Monoid& m1, const Monoid& m2, Node f = -1, Node t = -1,\r\
    \n                     const Cost& c = Cost()) {\r\n      m1 = m1.binaryOperation((f\
    \ == -1 || t == -1) ? m2 : edge_f(m2, f, t, c));\r\n    };\r\n\r\n    // <node:to\u3092\
    \u6839\u3068\u3057\u305F\u6728\u3067\u5168\u3066\u30DE\u30FC\u30B8\u3057\u305F\
    \u89E3\u3092\u6C42\u3081\u308B>\r\n    std::vector<std::vector<std::tuple<Monoid,\
    \ Node, Cost>>> partial(n);\r\n    auto all_merge = [&](Node to) {\r\n      Monoid\
    \ val{};\r\n      for (const auto& [ad, from, cost] : partial[to]) {\r\n     \
    \   merge(val, ad, from, to, cost);\r\n      }\r\n      return node_f(val, to);\r\
    \n    };\r\n\r\n    // <node:to\u3092\u6839\u3068\u3057\u305F\u6728\u3067from\u4EE5\
    \u5916\u30DE\u30FC\u30B8\u3057\u305F\u89E3\u3092\u6C42\u3081\u308B>\r\n    std::vector<std::unordered_map<Node,\
    \ Monoid>> partial_ac(n);\r\n    std::vector<Monoid> ret_m(n);\r\n    auto accumulation\
    \ = [&](Node to) {\r\n      // \u5DE6\u304B\u3089\u30DE\u30FC\u30B8\r\n      Monoid\
    \ val_ord{};\r\n      for (const auto& [ad, from, cost] : partial[to]) {\r\n \
    \       partial_ac[to].emplace(from, val_ord);\r\n        merge(val_ord, ad, from,\
    \ to, cost);\r\n      }\r\n      // \u53F3\u304B\u3089\u30DE\u30FC\u30B8\r\n \
    \     Monoid val_rord{};\r\n      for (auto rit = partial[to].rbegin(); rit !=\
    \ partial[to].rend(); ++rit) {\r\n        auto [ad, from, cost] = *rit;\r\n  \
    \      merge(partial_ac[to][from], val_rord, cost);\r\n        merge(val_rord,\
    \ ad, from, to, cost);\r\n      }\r\n      // node\u60C5\u5831\u3092\u53CD\u6620\
    \u3055\u305B\u3066\u5024\u3092\u78BA\u5B9A\r\n      ret_m[to] = node_f(val_ord,\
    \ to);\r\n      for (auto&& [_, pac] : partial_ac[to]) { pac = node_f(pac, to);\
    \ }\r\n    };\r\n\r\n    // root\u3092\u6839\u3068\u3057\u305F\u89E3\u3092\u6C42\
    \u3081\u308B\r\n    treeDP(graph, root, [&](Node f, Node t, const Cost& c) {\r\
    \n      partial[t].emplace_back(all_merge(f), f, c);\r\n    });\r\n    accumulation(0);\r\
    \n\r\n    // root\u304B\u3089bfs\u3057\u3066\u5404node\u3092\u6839\u3068\u3057\
    \u305F\u89E3\u3092\u6C42\u3081\u308B\r\n    bfs(graph, root, [&](Node f, Node\
    \ t, const Cost& c) {\r\n      partial[t].emplace_back(partial_ac[f][t], f, c);\r\
    \n      accumulation(t);\r\n    });\r\n\r\n    std::vector<typename Monoid::value_type>\
    \ ret;\r\n    for (const auto x : ret_m) { ret.emplace_back(x.m_val); }\r\n  \
    \  return ret;\r\n  }\r\n}  // namespace mtd\r\n#line 2 \"Library/Math/ModInt.hpp\"\
    \n\n#line 4 \"Library/Math/ModInt.hpp\"\n#include <iterator>\n\n#line 2 \"Library/Math/Math.hpp\"\
    \n\r\n#line 4 \"Library/Math/Math.hpp\"\n\r\nnamespace mtd {\r\n  template <class\
    \ T>\r\n  class Math {\r\n    const std::vector<T> m_fac;\r\n    const std::vector<T>\
    \ m_finv;\r\n\r\n    auto constructFac(int s) {\r\n      std::vector<T> fac(s);\r\
    \n      fac[0] = fac[1] = 1;\r\n      for (long long i = 2; i < s; ++i) { fac[i]\
    \ = fac[i - 1] * i; }\r\n      return fac;\r\n    }\r\n    auto constructInv(int\
    \ s) {\r\n      std::vector<T> finv(s);\r\n      finv[s - 1] = 1 / m_fac[s - 1];\r\
    \n      for (long long i = s - 2; i >= 0; --i) {\r\n        finv[i] = finv[i +\
    \ 1] * (i + 1);\r\n      }\r\n      return finv;\r\n    }\r\n\r\n  public:\r\n\
    \    constexpr Math(long long size = 3 * 1e6)\r\n        : m_fac(constructFac(size)),\
    \ m_finv(constructInv(size)) {}\r\n\r\n    static constexpr T pow(T a, long long\
    \ b) {\r\n      T ans = 1;\r\n      while (b > 0) {\r\n        if (b & 1) { ans\
    \ *= a; }\r\n        b >>= 1;\r\n        a *= a;\r\n      }\r\n      return ans;\r\
    \n    }\r\n    constexpr auto fact(int n) const { return (n < 0) ? 0 : m_fac[n];\
    \ }\r\n    constexpr auto factInv(int n) const { return (n < 0 ? 0 : m_finv[n]);\
    \ }\r\n    constexpr auto comb(int n, int r) const {\r\n      return fact(n) *\
    \ factInv(r) * factInv(n - r);\r\n    }\r\n    constexpr auto perm(int n, int\
    \ r) const { return fact(n) * factInv(n - r); }\r\n  };\r\n}  // namespace mtd\r\
    \n#line 7 \"Library/Math/ModInt.hpp\"\n\nnamespace mtd {\n\n  template <int MOD,\
    \ class T = long long>\n  class ModInt {\n  public:\n    T x;\n\n    constexpr\
    \ ModInt(T x) : x(x >= 0 ? x % MOD : MOD + (x % MOD)) {}\n    constexpr ModInt()\
    \ : ModInt(0) {}\n\n    // \u56DB\u5247\u6F14\u7B97\n    constexpr auto& operator+=(const\
    \ ModInt<MOD, T>& m) {\n      x += m.x;\n      if (x >= MOD) { x -= MOD; }\n \
    \     return *this;\n    }\n    constexpr auto& operator-=(const ModInt<MOD, T>&\
    \ m) {\n      x -= m.x;\n      if (x < 0) { x += MOD; }\n      return *this;\n\
    \    }\n    constexpr auto& operator*=(const ModInt<MOD, T>& m) {\n      x *=\
    \ m.x;\n      if (x >= MOD) { x %= MOD; }\n      return *this;\n    }\n    constexpr\
    \ auto& operator/=(const ModInt<MOD, T>& m) {\n      x *= mtd::Math<ModInt<MOD,\
    \ T>>::pow(m.x, MOD - 2).x;\n      if (x >= MOD) { x %= MOD; }\n      return *this;\n\
    \    }\n\n    constexpr auto operator+(const ModInt<MOD, T>& m) const {\n    \
    \  auto t = *this;\n      t += m;\n      return t;\n    }\n    constexpr auto\
    \ operator-(const ModInt<MOD, T>& m) const {\n      auto t = *this;\n      t -=\
    \ m;\n      return t;\n    }\n    constexpr auto operator*(const ModInt<MOD, T>&\
    \ m) const {\n      auto t = *this;\n      t *= m;\n      return t;\n    }\n \
    \   constexpr auto operator/(const ModInt<MOD, T>& m) const {\n      auto t =\
    \ *this;\n      t /= m;\n      return t;\n    }\n\n    constexpr auto& operator+=(const\
    \ T& t) {\n      return *this += ModInt<MOD, T>(t);\n    }\n    constexpr auto&\
    \ operator-=(const T& t) {\n      return *this -= ModInt<MOD, T>(t);\n    }\n\
    \    constexpr auto& operator*=(const T& n) {\n      return *this *= ModInt<MOD,\
    \ T>(n);\n    }\n    constexpr auto& operator/=(const T& n) {\n      return *this\
    \ /= ModInt<MOD, T>(n);\n    }\n    constexpr auto operator+(const T& t) const\
    \ {\n      return *this + ModInt<MOD, T>(t);\n    }\n    constexpr auto operator-(const\
    \ T& t) const {\n      return *this - ModInt<MOD, T>(t);\n    }\n    constexpr\
    \ auto operator*(const T& t) const {\n      return *this * ModInt<MOD, T>(t);\n\
    \    }\n    constexpr auto operator/(const T& t) const {\n      return *this /\
    \ ModInt<MOD, T>(t);\n    }\n    constexpr friend auto operator+(const T& t, const\
    \ ModInt<MOD, T>& m) {\n      return m + t;\n    }\n    constexpr friend auto\
    \ operator-(const T& t, const ModInt<MOD, T>& m) {\n      return -m + t;\n   \
    \ }\n    constexpr friend auto operator*(const T& t, const ModInt<MOD, T>& m)\
    \ {\n      return m * t;\n    }\n    constexpr friend auto operator/(const T&\
    \ t, const ModInt<MOD, T>& m) {\n      return ModInt<MOD, T>(1) / m * t;\n   \
    \ }\n\n    // \u5358\u9805\u6F14\u7B97\n    constexpr auto operator-() const {\
    \ return ModInt<MOD, T>(0 - x); }\n\n    // \u6BD4\u8F03\u6F14\u7B97\n    constexpr\
    \ auto operator!=(const ModInt<MOD, T>& m) const {\n      return x != m.x;\n \
    \   }\n    constexpr auto operator==(const ModInt<MOD, T>& m) const {\n      return\
    \ !(x != m.x);\n    }\n\n    // \u5165\u51FA\u529B\n    constexpr friend std::ostream&\
    \ operator<<(std::ostream& os,\n                                             \
    \ const ModInt<MOD, T>& m) {\n      return os << m.x;\n    }\n    constexpr friend\
    \ std::istream& operator>>(std::istream& is,\n                               \
    \               ModInt<MOD, T>& m) {\n      return is >> m.x;\n    }\n\n    constexpr\
    \ auto val() const { return x; }\n  };\n\n}  // namespace mtd\n#line 9 \"Test/Graph/Tree/ReRootingDP.test.cpp\"\
    \n// end:tag includes\n\nusing ll = long long;\nconstexpr ll MOD = 998244353;\n\
    using mint = mtd::ModInt<MOD>;\nauto math = mtd::Math<mint>();\n\nstruct S {\n\
    \  mint m;\n  ll s;\n  constexpr S(const mint& m, const ll s) : m(m), s(s) {}\n\
    \  constexpr S() : S(0, 0) {}\n};\n\nint main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(0);\n\
    \n  ll n;\n  std::cin >> n;\n  std::vector<ll> a(n);\n  for (auto i : std::views::iota(0,\
    \ n)) { std::cin >> a[i]; }\n  auto graph = mtd::Graph<>(n);\n  for ([[maybe_unused]]\
    \ auto _ : std::views::iota(0, n - 1)) {\n    int u, v;\n    std::cin >> u >>\
    \ v;\n    graph.addEdgeUndirected(u - 1, v - 1);\n  }\n\n  std::vector<mint> at;\n\
    \  for (auto x : a) {\n    auto size = std::to_string(x).size();\n    at.emplace_back(math.pow(10,\
    \ size));\n  }\n\n  auto op = [](const S& a, const S& b) { return S(a.m + b.m,\
    \ a.s + b.s); };\n  using M = mtd::Monoid<S, S(0, 0), decltype(op)>;\n\n  auto\
    \ edge_f = [&](const M& m, int f, int t, int c) {\n    return M(S(m.m_val.m *\
    \ at[t] + m.m_val.s * a[t], m.m_val.s));\n  };\n  auto node_f = [&](const M& m,\
    \ int i) {\n    return M(S(m.m_val.m + a[i], m.m_val.s + 1));\n  };\n  auto dp\
    \ = mtd::reRootingDP<M>(graph, edge_f, node_f);\n\n  mint ans = 0;\n  for (auto\
    \ x : dp) { ans += x.m; }\n  std::cout << ans << std::endl;\n}\n"
  code: "#include <vector>\n#define PROBLEM \"https://yukicoder.me/problems/no/2360\"\
    \n\n#include <iostream>\n\n// begin:tag includes\n#include \"../../../Library/Graph/Tree/ReRootingDP.hpp\"\
    \n#include \"../../../Library/Math/ModInt.hpp\"\n// end:tag includes\n\nusing\
    \ ll = long long;\nconstexpr ll MOD = 998244353;\nusing mint = mtd::ModInt<MOD>;\n\
    auto math = mtd::Math<mint>();\n\nstruct S {\n  mint m;\n  ll s;\n  constexpr\
    \ S(const mint& m, const ll s) : m(m), s(s) {}\n  constexpr S() : S(0, 0) {}\n\
    };\n\nint main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(0);\n\n  ll\
    \ n;\n  std::cin >> n;\n  std::vector<ll> a(n);\n  for (auto i : std::views::iota(0,\
    \ n)) { std::cin >> a[i]; }\n  auto graph = mtd::Graph<>(n);\n  for ([[maybe_unused]]\
    \ auto _ : std::views::iota(0, n - 1)) {\n    int u, v;\n    std::cin >> u >>\
    \ v;\n    graph.addEdgeUndirected(u - 1, v - 1);\n  }\n\n  std::vector<mint> at;\n\
    \  for (auto x : a) {\n    auto size = std::to_string(x).size();\n    at.emplace_back(math.pow(10,\
    \ size));\n  }\n\n  auto op = [](const S& a, const S& b) { return S(a.m + b.m,\
    \ a.s + b.s); };\n  using M = mtd::Monoid<S, S(0, 0), decltype(op)>;\n\n  auto\
    \ edge_f = [&](const M& m, int f, int t, int c) {\n    return M(S(m.m_val.m *\
    \ at[t] + m.m_val.s * a[t], m.m_val.s));\n  };\n  auto node_f = [&](const M& m,\
    \ int i) {\n    return M(S(m.m_val.m + a[i], m.m_val.s + 1));\n  };\n  auto dp\
    \ = mtd::reRootingDP<M>(graph, edge_f, node_f);\n\n  mint ans = 0;\n  for (auto\
    \ x : dp) { ans += x.m; }\n  std::cout << ans << std::endl;\n}\n"
  dependsOn:
  - Library/Graph/Tree/ReRootingDP.hpp
  - Library/Algebraic/Monoid.hpp
  - Library/Graph/Normal/BFS.hpp
  - Library/Graph/Graph.hpp
  - Library/Graph/Tree/TreeDP.hpp
  - Library/Math/ModInt.hpp
  - Library/Math/Math.hpp
  isVerificationFile: true
  path: Test/Graph/Tree/ReRootingDP.test.cpp
  requiredBy: []
  timestamp: '2024-12-19 23:41:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Graph/Tree/ReRootingDP.test.cpp
layout: document
redirect_from:
- /verify/Test/Graph/Tree/ReRootingDP.test.cpp
- /verify/Test/Graph/Tree/ReRootingDP.test.cpp.html
title: Test/Graph/Tree/ReRootingDP.test.cpp
---
