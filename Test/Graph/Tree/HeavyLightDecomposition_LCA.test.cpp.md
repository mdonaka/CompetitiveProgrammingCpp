---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Graph/Graph.hpp
    title: Library/Graph/Graph.hpp
  - icon: ':question:'
    path: Library/Graph/Tree/HeavyLightDecomposition.hpp
    title: Library/Graph/Tree/HeavyLightDecomposition.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C
  bundledCode: "#line 1 \"Test/Graph/Tree/HeavyLightDecomposition_LCA.test.cpp\"\n\
    #define PROBLEM \\\r\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C\"\
    \r\n\r\n#include <iostream>\r\n\r\n#line 2 \"Library/Graph/Graph.hpp\"\n#include\
    \ <vector>\r\n#include <deque>\r\n#include <tuple>\r\n\r\ntemplate<class Node\
    \ = int, class Cost = long long>\r\nclass Graph {\r\n    //using Node = int;\r\
    \n    //using Cost = long long;\r\n\r\n    using Edge = std::pair<Node, Cost>;\r\
    \n    using Edges = std::vector<Edge>;\r\n\r\n    const int m_n;\r\n    std::vector<Edges>\
    \ m_graph;\r\n\r\npublic:\r\n    Graph(int n) :m_n(n), m_graph(n) {}\r\n\r\n \
    \   auto addEdge(const Node& f, const Node& t, const Cost& c = 1) {\r\n      \
    \  m_graph[f].emplace_back(t, c);\r\n    }\r\n    auto addEdgeUndirected(const\
    \ Node& f, const Node& t, const Cost& c = 1) {\r\n        addEdge(f, t, c); addEdge(t,\
    \ f, c);\r\n    }\r\n    auto getEdges(const Node& from)const {\r\n        class\
    \ EdgesRange {\r\n            const typename Edges::const_iterator b, e;\r\n \
    \       public:\r\n            EdgesRange(const Edges& edges) :b(edges.begin()),\
    \ e(edges.end()) {}\r\n            auto begin()const { return b; }\r\n       \
    \     auto end()const { return e; }\r\n        };\r\n        return EdgesRange(m_graph[from]);\r\
    \n    }\r\n    auto getEdges()const {\r\n        std::deque<std::tuple<Node, Node,\
    \ Cost>> edges;\r\n        for(Node from = 0; from < m_n; ++from) for(const auto&\
    \ [to, c] : getEdges(from)) {\r\n            edges.emplace_back(from, to, c);\r\
    \n        }\r\n        return edges;\r\n    }\r\n    auto getEdgesExcludeCost()const\
    \ {\r\n        std::deque<std::pair<Node, Node>> edges;\r\n        for(Node from\
    \ = 0; from < m_n; ++from) for(const auto& [to, _] : getEdges(from)) {\r\n   \
    \         edges.emplace_back(from, to);\r\n        }\r\n        return edges;\r\
    \n    }\r\n    auto reverse()const {\r\n        auto rev = Graph<Node, Cost>(m_n);\r\
    \n        for(const auto& [from, to, c] : getEdges()) {\r\n            rev.addEdge(to,\
    \ from, c);\r\n        }\r\n        return rev;\r\n    }\r\n    auto size()const\
    \ { return m_n; };\r\n    auto debug(bool directed = false)const {\r\n       \
    \ for(const auto& [f, t, c] : getEdges())if(f < t || directed) {\r\n         \
    \   std::cout << f << \" -> \" << t << \": \" << c << std::endl;\r\n        }\r\
    \n    }\r\n};\n#line 2 \"Library/Graph/Tree/HeavyLightDecomposition.hpp\"\n\r\n\
    #include <unordered_map>\r\n#include <queue>\r\n#include <stack>\r\n\r\n#line\
    \ 8 \"Library/Graph/Tree/HeavyLightDecomposition.hpp\"\n\r\ntemplate<class Node,\
    \ class Cost>\r\nclass HeavyLightDecomposition {\r\n\r\n    using GraphOrderd\
    \ = std::unordered_map<Node, std::deque<Node>>;\r\n\r\n    const Node m_n;\r\n\
    \    const std::vector<Node> m_size;\r\n    const GraphOrderd m_tree;\r\n    const\
    \ std::vector<Node> m_height;\r\n    const std::vector<std::pair<Node, Node>>\
    \ m_root_par;\r\n    const std::vector<Node> m_ids;\r\n    const std::vector<Node>\
    \ m_order;\r\n    const std::vector<Node> m_edge_ids;\r\n\r\n    static auto constructGraph(const\
    \ Graph<Node, Cost>& tree) {\r\n        auto n = tree.size();\r\n        std::deque<std::pair<Node,\
    \ Node>> order;\r\n        std::vector<Node> used(n);\r\n        std::stack<std::pair<Node,\
    \ Node>> stk;\r\n        stk.emplace(0, -1); used[0] = true;\r\n        while(!stk.empty())\
    \ {\r\n            auto [f, p] = stk.top();\r\n            order.emplace_front(f,\
    \ p);\r\n            stk.pop();\r\n            for(const auto& [t, _] : tree.getEdges(f))\
    \ {\r\n                if(used[t]) { continue;; }\r\n                used[t] =\
    \ true;\r\n                stk.emplace(t, f);\r\n            }\r\n        }\r\n\
    \r\n        std::vector<Node> size(n, 1);\r\n        GraphOrderd hld_tree;\r\n\
    \        for(const auto& [f, p] : order) {\r\n            Node size_sum = 1;\r\
    \n            Node size_max = 0;\r\n            std::deque<Node> to_list;\r\n\
    \            for(const auto& [t, _] : tree.getEdges(f)) {\r\n                if(t\
    \ == p) { continue; }\r\n                if(size[t] > size_max) {\r\n        \
    \            size_max = size[t];\r\n                    to_list.emplace_back(t);\r\
    \n                } else {\r\n                    to_list.emplace_front(t);\r\n\
    \                }\r\n                size_sum += size[t];\r\n            }\r\n\
    \            if(!to_list.empty()) {\r\n                hld_tree.emplace(f, to_list);\r\
    \n            }\r\n            size[f] = size_sum;\r\n        }\r\n        return\
    \ hld_tree;\r\n    }\r\n\r\n    static auto constructSize(const Graph<Node, Cost>&\
    \ tree) {\r\n        auto n = tree.size();\r\n        std::deque<std::pair<Node,\
    \ Node>> order;\r\n        std::vector<Node> used(n);\r\n        std::stack<std::pair<Node,\
    \ Node>> stk;\r\n        stk.emplace(0, -1); used[0] = true;\r\n        while(!stk.empty())\
    \ {\r\n            auto [f, p] = stk.top();\r\n            order.emplace_front(f,\
    \ p);\r\n            stk.pop();\r\n            for(const auto& [t, _] : tree.getEdges(f))\
    \ {\r\n                if(used[t]) { continue;; }\r\n                used[t] =\
    \ true;\r\n                stk.emplace(t, f);\r\n            }\r\n        }\r\n\
    \r\n        std::vector<Node> size(n, 1);\r\n        for(const auto& [f, p] :\
    \ order) {\r\n            Node size_sum = 1;\r\n            for(const auto& [t,\
    \ _] : tree.getEdges(f)) {\r\n                if(t == p) { continue; }\r\n   \
    \             size_sum += size[t];\r\n            }\r\n            size[f] = size_sum;\r\
    \n        }\r\n        return size;\r\n\r\n    }\r\n\r\n    static auto constructRootPar(Node\
    \ n, const GraphOrderd& tree) {\r\n        std::vector<std::pair<Node, Node>>\
    \ root_par(n);\r\n        std::stack<std::tuple<Node, Node, Node>> stk;\r\n  \
    \      stk.emplace(0, 0, -1);\r\n        while(!stk.empty()) {\r\n           \
    \ auto [f, root, par] = stk.top();\r\n            stk.pop();\r\n\r\n         \
    \   if(tree.find(f) == tree.end()) { root_par[f] = {root,par}; continue; }\r\n\
    \            auto itr = tree.at(f).rbegin();\r\n            stk.emplace(*itr,\
    \ root, par);\r\n            root_par[f] = {root,par};\r\n            for(++itr;\
    \ itr != tree.at(f).rend(); ++itr) {\r\n                stk.emplace(*itr, *itr,\
    \ f);\r\n            }\r\n        }\r\n        return root_par;\r\n    }\r\n \
    \   static auto constructHeight(Node n, const GraphOrderd& tree) {\r\n       \
    \ std::vector<Node> height(n);\r\n        std::queue<Node> q;\r\n        q.emplace(0);\r\
    \n        while(!q.empty()) {\r\n            auto f = q.front();\r\n         \
    \   q.pop();\r\n            if(tree.find(f) == tree.end()) { continue; }\r\n \
    \           for(const auto& t : tree.at(f)) {\r\n                height[t] = height[f]\
    \ + 1;\r\n                q.emplace(t);\r\n            }\r\n        }\r\n    \
    \    return height;\r\n    }\r\n\r\n    auto constructIds() const {\r\n      \
    \  std::vector<Node> ids(m_n);\r\n        Node val = 0;\r\n        std::stack<Node>\
    \ stk;\r\n        stk.emplace(0);\r\n        while(!stk.empty()) {\r\n       \
    \     auto f = stk.top();\r\n            stk.pop();\r\n            ids[f] = val;\
    \ ++val;\r\n            if(m_tree.find(f) == m_tree.end()) { continue; }\r\n \
    \           for(const auto& t : m_tree.at(f)) { stk.emplace(t); }\r\n        }\r\
    \n        return ids;\r\n    }\r\n\r\n    auto constructOrder()const {\r\n   \
    \     std::vector<Node> order(m_n);\r\n        for(int i = 0; i < m_n; ++i) {\
    \ order[m_ids[i]] = i; }\r\n        return order;\r\n    }\r\n    /*\r\n     *\
    \ \u8FBA\u3092node\u3068\u3057\u3066\u62E1\u5F35\u3057\u305F\u5834\u5408\u306E\
    \u8FBAnode\u3060\u3051ID\u3092\u632F\u308B\r\n     * (1) - (2)\r\n     * (1) -\
    \ (e) - (2)\r\n     * [-1, -1, 0]\r\n     */\r\n    auto constructEdgeIds() const\
    \ {\r\n        Node edge_size = (m_n >> 1);\r\n        std::vector<Node> edge_ids(m_n,\
    \ -1);\r\n        Node val = 0;\r\n        std::stack<Node> stk;\r\n        stk.emplace(0);\r\
    \n        while(!stk.empty()) {\r\n            auto f = stk.top();\r\n       \
    \     stk.pop();\r\n            if(f > edge_size) { edge_ids[f] = val; ++val;\
    \ }\r\n            if(m_tree.find(f) == m_tree.end()) { continue; }\r\n      \
    \      for(const auto& t : m_tree.at(f)) { stk.emplace(t); }\r\n        }\r\n\
    \        return edge_ids;\r\n    }\r\n\r\npublic:\r\n\r\n    HeavyLightDecomposition(const\
    \ Graph<Node, Cost>& tree) :\r\n        m_n(tree.size()),\r\n        m_size(constructSize(tree)),\r\
    \n        m_tree(constructGraph(tree)),\r\n        m_root_par(constructRootPar(m_n,\
    \ m_tree)),\r\n        m_height(constructHeight(m_n, m_tree)),\r\n        m_ids(constructIds()),\r\
    \n        m_order(constructOrder()),\r\n        m_edge_ids(constructEdgeIds())\
    \ {\r\n    }\r\n\r\n    auto getId(Node i)const { return m_ids[i]; }\r\n    auto\
    \ getEdgeId(Node i)const { return m_edge_ids[i]; }\r\n    auto getOrder(Node i)const\
    \ { return m_order[i]; }\r\n\r\n    auto lca(Node f, Node t)const {\r\n      \
    \  do {\r\n            auto [fr, fp] = m_root_par[f];\r\n            auto [tr,\
    \ tp] = m_root_par[t];\r\n            if(fr == tr) { break; }\r\n            auto\
    \ fph = (fp > -1) ? m_height[fp] : -1;\r\n            auto tph = (tp > -1) ? m_height[tp]\
    \ : -1;\r\n            if(fph < tph) { t = tp; } else { f = fp; }\r\n        }\
    \ while(true);\r\n        return (m_height[f] < m_height[t]) ? f : t;\r\n    }\r\
    \n\r\n    auto range(Node f, Node t)const {\r\n        std::deque<std::pair<Node,\
    \ Node>> ret;\r\n        auto add = [&](Node f, Node t) {\r\n            auto\
    \ l = std::min(m_ids[f], m_ids[t]);\r\n            auto r = std::max(m_ids[f],\
    \ m_ids[t]);\r\n            ret.emplace_back(l, r);\r\n        };\r\n        do\
    \ {\r\n            auto [fr, fp] = m_root_par[f];\r\n            auto [tr, tp]\
    \ = m_root_par[t];\r\n            if(fr == tr) { add(f, t); break; }\r\n     \
    \       auto fph = (fp > -1) ? m_height[fp] : -1;\r\n            auto tph = (tp\
    \ > -1) ? m_height[tp] : -1;\r\n            if(fph < tph) { add(t, tr); t = tp;\
    \ } else { add(f, fr); f = fp; }\r\n        } while(true);\r\n        return ret;\r\
    \n    }\r\n\r\n    auto rangeEdge(Node f, Node t)const {\r\n        Node edge_size\
    \ = (m_n >> 1);\r\n        std::deque<std::pair<Node, Node>> ret;\r\n        auto\
    \ add = [&](Node f, Node t) {\r\n            auto l = std::min(m_ids[f], m_ids[t]);\r\
    \n            auto r = std::max(m_ids[f], m_ids[t]);\r\n            if(m_order[l]\
    \ <= edge_size) { ++l; }\r\n            if(m_order[r] <= edge_size) { --r; }\r\
    \n            if(l > r) { return; }\r\n            auto edge_l = m_edge_ids[m_order[l]];\r\
    \n            auto edge_r = m_edge_ids[m_order[r]];\r\n            ret.emplace_back(edge_l,\
    \ edge_r);\r\n        };\r\n        do {\r\n            auto [fr, fp] = m_root_par[f];\r\
    \n            auto [tr, tp] = m_root_par[t];\r\n            if(fr == tr) { add(f,\
    \ t); break; }\r\n            auto fph = (fp > -1) ? m_height[fp] : -1;\r\n  \
    \          auto tph = (tp > -1) ? m_height[tp] : -1;\r\n            if(fph < tph)\
    \ { add(t, tr); t = tp; } else { add(f, fr); f = fp; }\r\n        } while(true);\r\
    \n        return ret;\r\n    }\r\n\r\n    auto rangeSubTree(Node f)const {\r\n\
    \        return std::pair<Node, Node>{\r\n            m_ids[f], m_ids[f] + m_size[f]\
    \ - 1\r\n        };\r\n    }\r\n};\r\n#line 8 \"Test/Graph/Tree/HeavyLightDecomposition_LCA.test.cpp\"\
    \n\r\nusing ll = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr\
    \ char endl = '\\n';\r\n\r\nsigned main() {\r\n  ll n;\r\n  cin >> n;\r\n  auto\
    \ tree = Graph<int, bool>(n);\r\n  for (int f = 0; f < n; ++f) {\r\n    ll k;\r\
    \n    cin >> k;\r\n    for (int _ = 0; _ < k; ++_) {\r\n      int t;\r\n     \
    \ cin >> t;\r\n      tree.addEdge(f, t);\r\n    }\r\n  }\r\n\r\n  auto hld = HeavyLightDecomposition(tree);\r\
    \n\r\n  int q;\r\n  cin >> q;\r\n  for (int _ = 0; _ < q; ++_) {\r\n    int u,\
    \ v;\r\n    cin >> u >> v;\r\n    cout << hld.lca(u, v) << endl;\r\n  }\r\n}\n"
  code: "#define PROBLEM \\\r\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C\"\
    \r\n\r\n#include <iostream>\r\n\r\n#include \"./../../../Library/Graph/Graph.hpp\"\
    \r\n#include \"./../../../Library/Graph/Tree/HeavyLightDecomposition.hpp\"\r\n\
    \r\nusing ll = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr\
    \ char endl = '\\n';\r\n\r\nsigned main() {\r\n  ll n;\r\n  cin >> n;\r\n  auto\
    \ tree = Graph<int, bool>(n);\r\n  for (int f = 0; f < n; ++f) {\r\n    ll k;\r\
    \n    cin >> k;\r\n    for (int _ = 0; _ < k; ++_) {\r\n      int t;\r\n     \
    \ cin >> t;\r\n      tree.addEdge(f, t);\r\n    }\r\n  }\r\n\r\n  auto hld = HeavyLightDecomposition(tree);\r\
    \n\r\n  int q;\r\n  cin >> q;\r\n  for (int _ = 0; _ < q; ++_) {\r\n    int u,\
    \ v;\r\n    cin >> u >> v;\r\n    cout << hld.lca(u, v) << endl;\r\n  }\r\n}"
  dependsOn:
  - Library/Graph/Graph.hpp
  - Library/Graph/Tree/HeavyLightDecomposition.hpp
  isVerificationFile: true
  path: Test/Graph/Tree/HeavyLightDecomposition_LCA.test.cpp
  requiredBy: []
  timestamp: '2024-08-05 00:48:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Graph/Tree/HeavyLightDecomposition_LCA.test.cpp
layout: document
redirect_from:
- /verify/Test/Graph/Tree/HeavyLightDecomposition_LCA.test.cpp
- /verify/Test/Graph/Tree/HeavyLightDecomposition_LCA.test.cpp.html
title: Test/Graph/Tree/HeavyLightDecomposition_LCA.test.cpp
---
