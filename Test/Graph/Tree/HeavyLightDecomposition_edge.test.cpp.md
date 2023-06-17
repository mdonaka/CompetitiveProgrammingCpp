---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/LazySegmentTree.hpp
    title: Library/DataStructure/LazySegmentTree.hpp
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
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E\"\
    \r\n\r\n#include <iostream>\r\n#line 2 \"Library/Graph/Tree/HeavyLightDecomposition.hpp\"\
    \n\r\n#include <unordered_map>\r\n#include <queue>\r\n#include <stack>\r\n\r\n\
    class HeavyLightDecomposition {\r\n\r\n    using node_t = int;\r\n    using Graph_f\
    \ = std::unordered_multimap<node_t, node_t>;\r\n    using Graph = std::unordered_map<node_t,\
    \ std::deque<node_t>>;\r\n\r\n    const node_t m_n;\r\n    const std::vector<node_t>\
    \ m_size;\r\n    const Graph m_tree;\r\n    const std::vector<node_t> m_height;\r\
    \n    const std::vector<std::pair<node_t, node_t>> m_root_par;\r\n    const std::vector<node_t>\
    \ m_ids;\r\n    const std::vector<node_t> m_order;\r\n    const std::vector<node_t>\
    \ m_edge_ids;\r\n\r\n    static auto constructGraph(node_t n, const Graph_f& tree)\
    \ {\r\n        std::deque<std::pair<node_t, node_t>> order;\r\n        std::vector<node_t>\
    \ used(n);\r\n        std::stack<std::pair<node_t, node_t>> stk;\r\n        stk.emplace(0,\
    \ -1); used[0] = true;\r\n        while(!stk.empty()) {\r\n            auto [f,\
    \ p] = stk.top();\r\n            order.emplace_front(f, p);\r\n            stk.pop();\r\
    \n            auto range = tree.equal_range(f);\r\n            for(auto itr =\
    \ range.first; itr != range.second; ++itr) {\r\n                auto t = itr->second;\r\
    \n                if(!used[t]) {\r\n                    used[t] = true;\r\n  \
    \                  stk.emplace(t, f);\r\n                }\r\n            }\r\n\
    \        }\r\n\r\n        std::vector<node_t> size(n, 1);\r\n        Graph hld_tree;\r\
    \n        for(const auto& [f, p] : order) {\r\n            auto range = tree.equal_range(f);\r\
    \n            node_t size_sum = 1;\r\n            node_t size_max = 0;\r\n   \
    \         std::deque<node_t> to_list;\r\n            for(auto itr = range.first;\
    \ itr != range.second; ++itr) {\r\n                auto t = itr->second;\r\n \
    \               if(t == p) { continue; }\r\n                if(size[t] > size_max)\
    \ {\r\n                    size_max = size[t];\r\n                    to_list.emplace_back(t);\r\
    \n                } else {\r\n                    to_list.emplace_front(t);\r\n\
    \                }\r\n                size_sum += size[t];\r\n            }\r\n\
    \            if(!to_list.empty()) {\r\n                hld_tree.emplace(f, to_list);\r\
    \n            }\r\n            size[f] = size_sum;\r\n        }\r\n        return\
    \ hld_tree;\r\n    }\r\n\r\n    static auto constructSize(node_t n, const Graph_f&\
    \ tree) {\r\n        std::deque<std::pair<node_t, node_t>> order;\r\n        std::vector<node_t>\
    \ used(n);\r\n        std::stack<std::pair<node_t, node_t>> stk;\r\n        stk.emplace(0,\
    \ -1); used[0] = true;\r\n        while(!stk.empty()) {\r\n            auto [f,\
    \ p] = stk.top();\r\n            order.emplace_front(f, p);\r\n            stk.pop();\r\
    \n            auto range = tree.equal_range(f);\r\n            for(auto itr =\
    \ range.first; itr != range.second; ++itr) {\r\n                auto t = itr->second;\r\
    \n                if(!used[t]) {\r\n                    used[t] = true;\r\n  \
    \                  stk.emplace(t, f);\r\n                }\r\n            }\r\n\
    \        }\r\n\r\n        std::vector<node_t> size(n, 1);\r\n        for(const\
    \ auto& [f, p] : order) {\r\n            auto range = tree.equal_range(f);\r\n\
    \            node_t size_sum = 1;\r\n            for(auto itr = range.first; itr\
    \ != range.second; ++itr) {\r\n                auto t = itr->second;\r\n     \
    \           if(t == p) { continue; }\r\n                size_sum += size[t];\r\
    \n            }\r\n            size[f] = size_sum;\r\n        }\r\n        return\
    \ size;\r\n\r\n    }\r\n\r\n    static auto constructRootPar(node_t n, const Graph&\
    \ tree) {\r\n        std::vector<std::pair<node_t, node_t>> root_par(n);\r\n \
    \       std::stack<std::tuple<node_t, node_t, node_t>> stk;\r\n        stk.emplace(0,\
    \ 0, -1);\r\n        while(!stk.empty()) {\r\n            auto [f, root, par]\
    \ = stk.top();\r\n            stk.pop();\r\n\r\n            if(tree.find(f) ==\
    \ tree.end()) { root_par[f] = {root,par}; continue; }\r\n            auto itr\
    \ = tree.at(f).rbegin();\r\n            stk.emplace(*itr, root, par);\r\n    \
    \        root_par[f] = {root,par};\r\n            for(++itr; itr != tree.at(f).rend();\
    \ ++itr) {\r\n                stk.emplace(*itr, *itr, f);\r\n            }\r\n\
    \        }\r\n        return root_par;\r\n    }\r\n    static auto constructHeight(node_t\
    \ n, const Graph& tree) {\r\n        std::vector<node_t> height(n);\r\n      \
    \  std::queue<node_t> q;\r\n        q.emplace(0);\r\n        while(!q.empty())\
    \ {\r\n            auto f = q.front();\r\n            q.pop();\r\n           \
    \ if(tree.find(f) == tree.end()) { continue; }\r\n            for(const auto&\
    \ t : tree.at(f)) {\r\n                height[t] = height[f] + 1;\r\n        \
    \        q.emplace(t);\r\n            }\r\n        }\r\n        return height;\r\
    \n    }\r\n\r\n    auto constructIds() const {\r\n        std::vector<node_t>\
    \ ids(m_n);\r\n        node_t val = 0;\r\n        std::stack<node_t> stk;\r\n\
    \        stk.emplace(0);\r\n        while(!stk.empty()) {\r\n            auto\
    \ f = stk.top();\r\n            stk.pop();\r\n            ids[f] = val; ++val;\r\
    \n            if(m_tree.find(f) == m_tree.end()) { continue; }\r\n           \
    \ for(const auto& t : m_tree.at(f)) { stk.emplace(t); }\r\n        }\r\n     \
    \   return ids;\r\n    }\r\n\r\n    auto constructOrder()const {\r\n        std::vector<node_t>\
    \ order(m_n);\r\n        for(int i = 0; i < m_n; ++i) { order[m_ids[i]] = i; }\r\
    \n        return order;\r\n    }\r\n    /*\r\n     * \u8FBA\u3092node\u3068\u3057\
    \u3066\u62E1\u5F35\u3057\u305F\u5834\u5408\u306E\u8FBAnode\u3060\u3051ID\u3092\
    \u632F\u308B\r\n     * (1) - (2)\r\n     * (1) - (e) - (2)\r\n     * [-1, -1,\
    \ 0]\r\n     */\r\n    auto constructEdgeIds() const {\r\n        node_t edge_size\
    \ = (m_n >> 1);\r\n        std::vector<node_t> edge_ids(m_n, -1);\r\n        node_t\
    \ val = 0;\r\n        std::stack<node_t> stk;\r\n        stk.emplace(0);\r\n \
    \       while(!stk.empty()) {\r\n            auto f = stk.top();\r\n         \
    \   stk.pop();\r\n            if(f > edge_size) { edge_ids[f] = val; ++val; }\r\
    \n            if(m_tree.find(f) == m_tree.end()) { continue; }\r\n           \
    \ for(const auto& t : m_tree.at(f)) { stk.emplace(t); }\r\n        }\r\n     \
    \   return edge_ids;\r\n    }\r\n\r\npublic:\r\n\r\n    HeavyLightDecomposition(node_t\
    \ n, const Graph_f& tree) :\r\n        m_n(n),\r\n        m_size(constructSize(n,\
    \ tree)),\r\n        m_tree(constructGraph(n, tree)),\r\n        m_root_par(constructRootPar(n,\
    \ m_tree)),\r\n        m_height(constructHeight(n, m_tree)),\r\n        m_ids(constructIds()),\r\
    \n        m_order(constructOrder()),\r\n        m_edge_ids(constructEdgeIds())\
    \ {\r\n    }\r\n\r\n    auto getId(node_t i)const { return m_ids[i]; }\r\n   \
    \ auto getEdgeId(node_t i)const { return m_edge_ids[i]; }\r\n    auto getOrder(node_t\
    \ i)const { return m_order[i]; }\r\n\r\n    auto lca(node_t f, node_t t)const\
    \ {\r\n        do {\r\n            auto [fr, fp] = m_root_par[f];\r\n        \
    \    auto [tr, tp] = m_root_par[t];\r\n            if(fr == tr) { break; }\r\n\
    \            auto fph = (fp > -1) ? m_height[fp] : -1;\r\n            auto tph\
    \ = (tp > -1) ? m_height[tp] : -1;\r\n            if(fph < tph) { t = tp; } else\
    \ { f = fp; }\r\n        } while(true);\r\n        return (m_height[f] < m_height[t])\
    \ ? f : t;\r\n    }\r\n\r\n    auto range(node_t f, node_t t)const {\r\n     \
    \   std::deque<std::pair<node_t, node_t>> ret;\r\n        auto add = [&](node_t\
    \ f, node_t t) {\r\n            auto l = std::min(m_ids[f], m_ids[t]);\r\n   \
    \         auto r = std::max(m_ids[f], m_ids[t]);\r\n            ret.emplace_back(l,\
    \ r);\r\n        };\r\n        do {\r\n            auto [fr, fp] = m_root_par[f];\r\
    \n            auto [tr, tp] = m_root_par[t];\r\n            if(fr == tr) { add(f,\
    \ t); break; }\r\n            auto fph = (fp > -1) ? m_height[fp] : -1;\r\n  \
    \          auto tph = (tp > -1) ? m_height[tp] : -1;\r\n            if(fph < tph)\
    \ { add(t, tr); t = tp; } else { add(f, fr); f = fp; }\r\n        } while(true);\r\
    \n        return ret;\r\n    }\r\n\r\n    auto rangeEdge(node_t f, node_t t)const\
    \ {\r\n        node_t edge_size = (m_n >> 1);\r\n        std::deque<std::pair<node_t,\
    \ node_t>> ret;\r\n        auto add = [&](node_t f, node_t t) {\r\n          \
    \  auto l = std::min(m_ids[f], m_ids[t]);\r\n            auto r = std::max(m_ids[f],\
    \ m_ids[t]);\r\n            if(m_order[l] <= edge_size) { ++l; }\r\n         \
    \   if(m_order[r] <= edge_size) { --r; }\r\n            if(l > r) { return; }\r\
    \n            auto edge_l = m_edge_ids[m_order[l]];\r\n            auto edge_r\
    \ = m_edge_ids[m_order[r]];\r\n            ret.emplace_back(edge_l, edge_r);\r\
    \n        };\r\n        do {\r\n            auto [fr, fp] = m_root_par[f];\r\n\
    \            auto [tr, tp] = m_root_par[t];\r\n            if(fr == tr) { add(f,\
    \ t); break; }\r\n            auto fph = (fp > -1) ? m_height[fp] : -1;\r\n  \
    \          auto tph = (tp > -1) ? m_height[tp] : -1;\r\n            if(fph < tph)\
    \ { add(t, tr); t = tp; } else { add(f, fr); f = fp; }\r\n        } while(true);\r\
    \n        return ret;\r\n    }\r\n\r\n    auto rangeSubTree(node_t f)const {\r\
    \n        return std::pair<node_t, node_t>{\r\n            m_ids[f], m_ids[f]\
    \ + m_size[f] - 1\r\n        };\r\n    }\r\n};\r\n#line 3 \"Library/DataStructure/LazySegmentTree.hpp\"\
    \n#include <vector>\r\n#include <deque>\r\n#include <utility>\r\n\r\ntemplate<class\
    \ T>\r\nclass isMonoid {\r\n    template <class U>\r\n    static auto check(U\
    \ x) -> decltype(x.binaryOperation(x), std::true_type{});\r\n    static std::false_type\
    \ check(...);\r\npublic:\r\n    static bool const value = decltype(check(std::declval<T>()))::value;\r\
    \n};\r\n\r\ntemplate<\r\n    class Monoid, class MonoidOp, class op,\r\n    std::enable_if_t<isMonoid<Monoid>::value,\
    \ std::nullptr_t> = nullptr,\r\n    std::enable_if_t<isMonoid<MonoidOp>::value,\
    \ std::nullptr_t> = nullptr>\r\nclass LazySegmentTree {\r\nprivate:\r\n\r\n  \
    \  const int m_size;\r\n    std::vector<Monoid> m_node;\r\n    std::vector<MonoidOp>\
    \ m_lazy;\r\n    using S = decltype(Monoid().m_val);\r\n\r\n    int calcSize(int\
    \ n) const { int size = 1; while(size < n) { size <<= 1; }return size; }\r\n\r\
    \n    auto _lazy_update(int i, const MonoidOp& val) {\r\n        if(i >= (m_size\
    \ << 1) - 1) { return; }\r\n        m_lazy[i] = m_lazy[i].binaryOperation(val);\r\
    \n    }\r\n\r\n    auto _propagate(int i) {\r\n        m_node[i] = op()(m_node[i],\
    \ m_lazy[i]);\r\n        _lazy_update((i << 1) + 1, m_lazy[i]);\r\n        _lazy_update((i\
    \ << 1) + 2, m_lazy[i]);\r\n        m_lazy[i] = MonoidOp();\r\n    }\r\n\r\n \
    \   auto _update(int l, int r, int k, int nl, int nr, const MonoidOp& m) {\r\n\
    \        _propagate(k);\r\n        if(nr < l || r < nl) { return; }\r\n      \
    \  if(l <= nl && nr <= r) { _lazy_update(k, m); _propagate(k); return; }\r\n \
    \       _update(l, r, (k << 1) + 1, nl, (nl + nr) >> 1, m);\r\n        _update(l,\
    \ r, (k << 1) + 2, ((nl + nr) >> 1) + 1, nr, m);\r\n        m_node[k] = m_node[(k\
    \ << 1) + 1].binaryOperation(m_node[(k << 1) + 2]);\r\n    }\r\n\r\n    auto _query(int\
    \ l, int r, int k, int nl, int nr) {\r\n        _propagate(k);\r\n        if(nr\
    \ < l || r < nl) { return Monoid(); }\r\n        if(l <= nl && nr <= r) { return\
    \ m_node[k]; }\r\n        auto l_val = _query(l, r, (k << 1) + 1, nl, (nl + nr)\
    \ >> 1);\r\n        auto r_val = _query(l, r, (k << 1) + 2, ((nl + nr) >> 1) +\
    \ 1, nr);\r\n        return l_val.binaryOperation(r_val);\r\n    }\r\n\r\n   \
    \ auto _construct(const std::vector<S>& vec) {\r\n        for(unsigned int i =\
    \ 0; i < vec.size(); ++i) {\r\n            m_node[i + m_size - 1] = Monoid(vec[i]);\r\
    \n        }\r\n        for(int i = m_size - 2; i >= 0; --i) {\r\n            m_node[i]\
    \ = m_node[(i << 1) | 1].binaryOperation(m_node[(i + 1) << 1LL]);\r\n        }\r\
    \n    }\r\npublic:\r\n    LazySegmentTree(int n) : m_size(calcSize(n)), m_node((m_size\
    \ << 1) - 1), m_lazy((m_size << 1) - 1) {}\r\n    LazySegmentTree(int n, const\
    \ std::vector<S>& vec) :LazySegmentTree(n) { _construct(vec); }\r\n\r\n    auto\
    \ update(int l, int r, const MonoidOp& val) {\r\n        _update(l, r, 0, 0, m_size\
    \ - 1, val);\r\n    }\r\n\r\n    auto query(int l, int r) {\r\n        return\
    \ _query(l, r, 0, 0, m_size - 1).m_val;\r\n    }\r\n\r\n    auto output() {\r\n\
    \        for(int i = 0; i < (m_size << 1) - 1; ++i) { _propagate(i); }\r\n   \
    \     for(int i = 0; i < m_size; ++i) { std::cout << m_node[m_size + i - 1] <<\
    \ \" \"; }\r\n        std::cout << std::endl;\r\n    }\r\n\r\n};\r\n\r\ntemplate<\r\
    \n    class S,   // \u8981\u7D20\u306E\u578B\r\n    S& element, // \u5143\r\n\
    \    class T // 2\u9805\u6F14\u7B97\u306EFunctor\r\n>\r\nstruct Monoid {\r\n \
    \   S m_val;\r\n    Monoid() :m_val(element) {}\r\n    Monoid(S val) :m_val(val)\
    \ {}\r\n    Monoid  binaryOperation(const Monoid& m2)const { return T()(m_val,\
    \ m2.m_val); }\r\n    friend std::ostream& operator<<(std::ostream& os, const\
    \ Monoid<S, element, T>& m) {\r\n        return os << m.m_val;\r\n    }\r\n};\r\
    \n\r\n/*\r\n\u5404\u7A2E\u983B\u51FA\u30B5\u30F3\u30D7\u30EB\r\nex) \u533A\u9593\
    \u6700\u5C0F\u5024\uFF0C\u533A\u9593\u66F4\u65B0\r\nLazySegmentTree<M_M, M_U,\
    \ OP_RUQ_RMQ>\r\n*/\r\n//---- \u8981\u7D20 ----\r\nstd::pair<long long, long long>\
    \ base_s{0,0};\r\nstruct F_RSQ {\r\n    auto operator()(const std::pair<long long,\
    \ long long>& a, const std::pair<long long, long long>& b)const {\r\n        return\
    \ std::pair<long long, long long>{a.first + b.first, a.second + b.second};\r\n\
    \    }\r\n};\r\nusing M_S = Monoid<std::pair<long long, long long>, base_s, F_RSQ>;\r\
    \n\r\nlong long base_m{static_cast<long long>(1e18)};\r\nstruct F_RMQ {\r\n  \
    \  auto operator()(long long a, long long b)const {\r\n        return std::min(a,\
    \ b);\r\n    }\r\n};\r\nusing M_M = Monoid<long long, base_m, F_RMQ>;\r\n\r\n\
    //---- \u4F5C\u7528\u7D20 ----\r\nlong long base_u{static_cast<long long>(-1e18)};\r\
    \nstruct F_RUQ {\r\n    auto operator()(long long a, long long b)const {\r\n \
    \       if(b == base_u) { return a; }\r\n        return b;\r\n    }\r\n};\r\n\
    using M_U = Monoid<long long, base_u, F_RUQ>;\r\n\r\nlong long base_a{static_cast<long\
    \ long>(0)};\r\nstruct F_RAQ {\r\n    auto operator()(long long a, long long b)const\
    \ {\r\n        return a + b;\r\n    }\r\n};\r\nusing M_A = Monoid<long long, base_a,\
    \ F_RAQ>;\r\n\r\n//---- \u4F5C\u7528 ----\r\nstruct OP_RUQ_RSQ {\r\n    auto operator()(const\
    \ M_S& m, const M_U& m2) {\r\n        if(m2.m_val == base_u) { return m; }\r\n\
    \        return M_S(std::pair<long long, long long>{m.m_val.second* m2.m_val,\
    \ m.m_val.second});\r\n    }\r\n};\r\nstruct OP_RUQ_RMQ {\r\n    auto operator()(const\
    \ M_M& m, const M_U& m2) {\r\n        if(m2.m_val == base_u) { return m; }\r\n\
    \        return M_M(m2.m_val);\r\n    }\r\n};\r\nstruct OP_RAQ_RSQ {\r\n    auto\
    \ operator()(const M_S& m, const M_A& m2) {\r\n        return M_S(std::pair<long\
    \ long, long long>{m.m_val.first + m.m_val.second * m2.m_val, m.m_val.second});\r\
    \n    }\r\n};\r\nstruct OP_RAQ_RMQ {\r\n    auto operator()(const M_M& m, const\
    \ M_A& m2) {\r\n        return M_M{m.m_val + m2.m_val};\r\n    }\r\n};\r\n#line\
    \ 6 \"Test/Graph/Tree/HeavyLightDecomposition_edge.test.cpp\"\n\r\nusing ll =\
    \ long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr char endl = '\\\
    n';\r\n\r\nsigned main() {\r\n\r\n    ll n;\r\n    cin >> n;\r\n    std::unordered_multimap<int,\
    \ int> tree;\r\n    ll add = n;\r\n    for(int f = 0; f < n; ++f) {\r\n      \
    \  int k;\r\n        cin >> k;\r\n        for(int _ = 0; _ < k; ++_) {\r\n   \
    \         int t;\r\n            cin >> t;\r\n            tree.emplace(f, add);\r\
    \n            tree.emplace(t, add);\r\n            tree.emplace(add, t);\r\n \
    \           tree.emplace(add, f);\r\n            ++add;\r\n        }\r\n    }\r\
    \n\r\n    int size = n + n - 1;\r\n    std::vector<std::pair<ll, ll>> v(n - 1,\
    \ {0,1});\r\n    auto segtree = LazySegmentTree<M_S, M_A, OP_RAQ_RSQ>(n - 1, v);\r\
    \n    auto hld = HeavyLightDecomposition(size, tree);\r\n\r\n    ll q;\r\n   \
    \ cin >> q;\r\n    for(int _ = 0; _ < q; ++_) {\r\n        ll k;\r\n        cin\
    \ >> k;\r\n        if(k == 0) {\r\n            ll v, w;\r\n            cin >>\
    \ v >> w;\r\n            for(const auto& [l, r] : hld.rangeEdge(0, v)) {\r\n \
    \               segtree.update(l, r, w);\r\n            }\r\n        } else {\r\
    \n            ll u;\r\n            cin >> u;\r\n            ll ans = 0;\r\n  \
    \          for(const auto& [l, r] : hld.rangeEdge(0, u)) {\r\n               \
    \ ans += segtree.query(l, r).first;\r\n            }\r\n            cout << ans\
    \ << endl;\r\n        }\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E\"\
    \r\n\r\n#include <iostream>\r\n#include \"./../../../Library/Graph/Tree/HeavyLightDecomposition.hpp\"\
    \r\n#include \"./../../../Library/DataStructure/LazySegmentTree.hpp\"\r\n\r\n\
    using ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr char\
    \ endl = '\\n';\r\n\r\nsigned main() {\r\n\r\n    ll n;\r\n    cin >> n;\r\n \
    \   std::unordered_multimap<int, int> tree;\r\n    ll add = n;\r\n    for(int\
    \ f = 0; f < n; ++f) {\r\n        int k;\r\n        cin >> k;\r\n        for(int\
    \ _ = 0; _ < k; ++_) {\r\n            int t;\r\n            cin >> t;\r\n    \
    \        tree.emplace(f, add);\r\n            tree.emplace(t, add);\r\n      \
    \      tree.emplace(add, t);\r\n            tree.emplace(add, f);\r\n        \
    \    ++add;\r\n        }\r\n    }\r\n\r\n    int size = n + n - 1;\r\n    std::vector<std::pair<ll,\
    \ ll>> v(n - 1, {0,1});\r\n    auto segtree = LazySegmentTree<M_S, M_A, OP_RAQ_RSQ>(n\
    \ - 1, v);\r\n    auto hld = HeavyLightDecomposition(size, tree);\r\n\r\n    ll\
    \ q;\r\n    cin >> q;\r\n    for(int _ = 0; _ < q; ++_) {\r\n        ll k;\r\n\
    \        cin >> k;\r\n        if(k == 0) {\r\n            ll v, w;\r\n       \
    \     cin >> v >> w;\r\n            for(const auto& [l, r] : hld.rangeEdge(0,\
    \ v)) {\r\n                segtree.update(l, r, w);\r\n            }\r\n     \
    \   } else {\r\n            ll u;\r\n            cin >> u;\r\n            ll ans\
    \ = 0;\r\n            for(const auto& [l, r] : hld.rangeEdge(0, u)) {\r\n    \
    \            ans += segtree.query(l, r).first;\r\n            }\r\n          \
    \  cout << ans << endl;\r\n        }\r\n    }\r\n}"
  dependsOn:
  - Library/Graph/Tree/HeavyLightDecomposition.hpp
  - Library/DataStructure/LazySegmentTree.hpp
  isVerificationFile: true
  path: Test/Graph/Tree/HeavyLightDecomposition_edge.test.cpp
  requiredBy: []
  timestamp: '2023-04-08 05:40:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Graph/Tree/HeavyLightDecomposition_edge.test.cpp
layout: document
redirect_from:
- /verify/Test/Graph/Tree/HeavyLightDecomposition_edge.test.cpp
- /verify/Test/Graph/Tree/HeavyLightDecomposition_edge.test.cpp.html
title: Test/Graph/Tree/HeavyLightDecomposition_edge.test.cpp
---