---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Graph/Tree/ReRootingDP.hpp\"\n#include <unordered_map>\r\
    \n\r\n#line 2 \"Library/Graph/Normal/BFS.hpp\"\n\r\n#include <vector>\r\n#include\
    \ <queue>\r\n\r\n#line 3 \"Library/Graph/Graph.hpp\"\n#include <deque>\r\n\r\n\
    template<class Node = int, class Cost = long long>\r\nclass Graph {\r\n    //using\
    \ Node = int;\r\n    //using Cost = long long;\r\n\r\n    using Edge = std::pair<Node,\
    \ Cost>;\r\n    using Edges = std::vector<Edge>;\r\n\r\n    const int m_n;\r\n\
    \    std::vector<Edges> m_graph;\r\n\r\npublic:\r\n    Graph(int n) :m_n(n), m_graph(n)\
    \ {}\r\n\r\n    auto addEdge(const Node& f, const Node& t, const Cost& c = 1)\
    \ {\r\n        m_graph[f].emplace_back(t, c);\r\n    }\r\n    auto addEdgeUndirected(const\
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
    \n    }\r\n};\n#line 7 \"Library/Graph/Normal/BFS.hpp\"\n\r\ntemplate<class Node,\
    \ class Cost, class Lambda>\r\nauto bfs(const Graph<Node, Cost>& graph, const\
    \ Node& root, const Lambda& lambda) {\r\n    auto n = graph.size();\r\n    std::vector<bool>\
    \ used(n); used[root] = true;\r\n    std::queue<Node> q; q.emplace(root);\r\n\
    \    while(!q.empty()) {\r\n        auto from = q.front();\r\n        q.pop();\r\
    \n        for(const auto& [to, _] : graph.getEdges(from)) {\r\n            if(used[to])\
    \ { continue; }\r\n            q.emplace(to);\r\n            used[to] = true;\r\
    \n            lambda(from, to);\r\n        }\r\n    }\r\n}\r\n#line 5 \"Library/Graph/Tree/ReRootingDP.hpp\"\
    \n\r\n/*\r\n * \u90E8\u5206\u6728\u306E\u60C5\u5831\u3092\u30DE\u30FC\u30B8\u3059\
    \u308BMonoid\r\n * edge\u306E\u60C5\u5831\u3092\u89AA\u306B\u6D41\u3059edge_f(M,\
    \ f, t)\r\n * node\u306E\u60C5\u5831\u3092\u89AA\u306B\u6D41\u3059node_f(M, i)\r\
    \n */\r\ntemplate<class Monoid, class Lambda1, class Lambda2>\r\nauto reRootingDP(long\
    \ long n,\r\n                 const std::unordered_multimap<long long, long long>&\
    \ graph,\r\n                 const Lambda1& edge_f,\r\n                 const\
    \ Lambda2& node_f) {\r\n\r\n    constexpr int root = 0;\r\n\r\n    // <\u8FBA\u60C5\
    \u5831\u3092\u8003\u616E\u3057\u305FMonoid\u306E2\u9805\u6F14\u7B97>\r\n    auto\
    \ merge = [&](Monoid& m1, const Monoid& m2, ll f = -1, ll t = -1) {\r\n      \
    \  if(f == -1 && t == -1) { m1 = m1.binaryOperation(m2); return; }\r\n       \
    \ m1 = m1.binaryOperation(edge_f(m2, f, t));\r\n    };\r\n\r\n    // <node:to\u3092\
    \u6839\u3068\u3057\u305F\u6728\u3067\u5168\u3066\u30DE\u30FC\u30B8\u3057\u305F\
    \u89E3\u3092\u6C42\u3081\u308B>\r\n    std::vector<std::deque<pair<int, Monoid>>>\
    \ partial(n);\r\n    auto all_merge = [&](ll to) {\r\n        Monoid val{};\r\n\
    \        for(const auto& [from, ad] : partial[to]) { merge(val, ad, from, to);\
    \ }\r\n        return node_f(val, to);\r\n    };\r\n\r\n    // <node:to\u3092\u6839\
    \u3068\u3057\u305F\u6728\u3067from\u4EE5\u5916\u30DE\u30FC\u30B8\u3057\u305F\u89E3\
    \u3092\u6C42\u3081\u308B>\r\n    std::vector<std::unordered_map<int, Monoid>>\
    \ partial_ac(n);\r\n    std::vector<Monoid> ret(n);\r\n    auto accumulation =\
    \ [&](ll to) {\r\n        // \u5DE6\u304B\u3089\u30DE\u30FC\u30B8\r\n        Monoid\
    \ val_ord{};\r\n        for(const auto& [from, ad] : partial[to]) {\r\n      \
    \      partial_ac[to].emplace(from, val_ord);\r\n            merge(val_ord, ad,\
    \ from, to);\r\n        }\r\n        // \u53F3\u304B\u3089\u30DE\u30FC\u30B8\r\
    \n        Monoid val_rord{};\r\n        for(auto rit = partial[to].rbegin(); rit\
    \ != partial[to].rend(); ++rit) {\r\n            auto [from, ad] = *rit;\r\n \
    \           merge(partial_ac[to][from], val_rord);\r\n            merge(val_rord,\
    \ ad, from, to);\r\n        }\r\n        // node\u60C5\u5831\u3092\u53CD\u6620\
    \u3055\u305B\u3066\u5024\u3092\u78BA\u5B9A\r\n        ret[to] = node_f(val_ord,\
    \ to);\r\n        for(auto&& [_, pac] : partial_ac[to]) { pac = node_f(pac, to);\
    \ }\r\n    };\r\n\r\n    // root\u3092\u6839\u3068\u3057\u305F\u89E3\u3092\u6C42\
    \u3081\u308B\r\n    treeDP(n, graph, root, [&](ll f, ll t) {\r\n        partial[t].emplace_back(f,\
    \ all_merge(f));\r\n    });\r\n    accumulation(0);\r\n\r\n    // root\u304B\u3089\
    bfs\u3057\u3066\u5404node\u3092\u6839\u3068\u3057\u305F\u89E3\u3092\u6C42\u3081\
    \u308B\r\n    graphBFS(n, graph, root, [&](int f, int t) {\r\n        partial[t].emplace_back(f,\
    \ partial_ac[f][t]);\r\n        accumulation(t);\r\n    });\r\n\r\n    return\
    \ ret;\r\n}\r\n\r\ntemplate<\r\n    class S,   // \u8981\u7D20\u306E\u578B\r\n\
    \    // \u203BC++17\u3067\u306F\u307B\u3068\u3093\u3069\u306E\u578B\u3092\u30B0\
    \u30ED\u30FC\u30D0\u30EB\u5BA3\u8A00\u3057\u305F\u521D\u671F\u5024\u3092\u53C2\
    \u7167\u3067\u6E21\u3059\u5FC5\u8981\u3042\u308A\r\n    S& element, // \u5143\r\
    \n    class T // 2\u9805\u6F14\u7B97\u5B50\uFF0E\r\n>\r\nstruct Monoid {\r\n \
    \   S m_val;\r\n    Monoid() :m_val(element) {}\r\n    Monoid(S val) :m_val(val)\
    \ {}\r\n    Monoid binaryOperation(const Monoid& m2)const { return T()(m_val,\
    \ m2.m_val); }\r\n    friend std::ostream& operator<<(std::ostream& os, const\
    \ Monoid& m) {\r\n        os << m.m_val;\r\n        return os;\r\n    }\r\n};\r\
    \n"
  code: "#pragma once\r\n#include <unordered_map>\r\n\r\n#include \"../../Graph/Normal/BFS.hpp\"\
    \r\n\r\n/*\r\n * \u90E8\u5206\u6728\u306E\u60C5\u5831\u3092\u30DE\u30FC\u30B8\u3059\
    \u308BMonoid\r\n * edge\u306E\u60C5\u5831\u3092\u89AA\u306B\u6D41\u3059edge_f(M,\
    \ f, t)\r\n * node\u306E\u60C5\u5831\u3092\u89AA\u306B\u6D41\u3059node_f(M, i)\r\
    \n */\r\ntemplate<class Monoid, class Lambda1, class Lambda2>\r\nauto reRootingDP(long\
    \ long n,\r\n                 const std::unordered_multimap<long long, long long>&\
    \ graph,\r\n                 const Lambda1& edge_f,\r\n                 const\
    \ Lambda2& node_f) {\r\n\r\n    constexpr int root = 0;\r\n\r\n    // <\u8FBA\u60C5\
    \u5831\u3092\u8003\u616E\u3057\u305FMonoid\u306E2\u9805\u6F14\u7B97>\r\n    auto\
    \ merge = [&](Monoid& m1, const Monoid& m2, ll f = -1, ll t = -1) {\r\n      \
    \  if(f == -1 && t == -1) { m1 = m1.binaryOperation(m2); return; }\r\n       \
    \ m1 = m1.binaryOperation(edge_f(m2, f, t));\r\n    };\r\n\r\n    // <node:to\u3092\
    \u6839\u3068\u3057\u305F\u6728\u3067\u5168\u3066\u30DE\u30FC\u30B8\u3057\u305F\
    \u89E3\u3092\u6C42\u3081\u308B>\r\n    std::vector<std::deque<pair<int, Monoid>>>\
    \ partial(n);\r\n    auto all_merge = [&](ll to) {\r\n        Monoid val{};\r\n\
    \        for(const auto& [from, ad] : partial[to]) { merge(val, ad, from, to);\
    \ }\r\n        return node_f(val, to);\r\n    };\r\n\r\n    // <node:to\u3092\u6839\
    \u3068\u3057\u305F\u6728\u3067from\u4EE5\u5916\u30DE\u30FC\u30B8\u3057\u305F\u89E3\
    \u3092\u6C42\u3081\u308B>\r\n    std::vector<std::unordered_map<int, Monoid>>\
    \ partial_ac(n);\r\n    std::vector<Monoid> ret(n);\r\n    auto accumulation =\
    \ [&](ll to) {\r\n        // \u5DE6\u304B\u3089\u30DE\u30FC\u30B8\r\n        Monoid\
    \ val_ord{};\r\n        for(const auto& [from, ad] : partial[to]) {\r\n      \
    \      partial_ac[to].emplace(from, val_ord);\r\n            merge(val_ord, ad,\
    \ from, to);\r\n        }\r\n        // \u53F3\u304B\u3089\u30DE\u30FC\u30B8\r\
    \n        Monoid val_rord{};\r\n        for(auto rit = partial[to].rbegin(); rit\
    \ != partial[to].rend(); ++rit) {\r\n            auto [from, ad] = *rit;\r\n \
    \           merge(partial_ac[to][from], val_rord);\r\n            merge(val_rord,\
    \ ad, from, to);\r\n        }\r\n        // node\u60C5\u5831\u3092\u53CD\u6620\
    \u3055\u305B\u3066\u5024\u3092\u78BA\u5B9A\r\n        ret[to] = node_f(val_ord,\
    \ to);\r\n        for(auto&& [_, pac] : partial_ac[to]) { pac = node_f(pac, to);\
    \ }\r\n    };\r\n\r\n    // root\u3092\u6839\u3068\u3057\u305F\u89E3\u3092\u6C42\
    \u3081\u308B\r\n    treeDP(n, graph, root, [&](ll f, ll t) {\r\n        partial[t].emplace_back(f,\
    \ all_merge(f));\r\n    });\r\n    accumulation(0);\r\n\r\n    // root\u304B\u3089\
    bfs\u3057\u3066\u5404node\u3092\u6839\u3068\u3057\u305F\u89E3\u3092\u6C42\u3081\
    \u308B\r\n    graphBFS(n, graph, root, [&](int f, int t) {\r\n        partial[t].emplace_back(f,\
    \ partial_ac[f][t]);\r\n        accumulation(t);\r\n    });\r\n\r\n    return\
    \ ret;\r\n}\r\n\r\ntemplate<\r\n    class S,   // \u8981\u7D20\u306E\u578B\r\n\
    \    // \u203BC++17\u3067\u306F\u307B\u3068\u3093\u3069\u306E\u578B\u3092\u30B0\
    \u30ED\u30FC\u30D0\u30EB\u5BA3\u8A00\u3057\u305F\u521D\u671F\u5024\u3092\u53C2\
    \u7167\u3067\u6E21\u3059\u5FC5\u8981\u3042\u308A\r\n    S& element, // \u5143\r\
    \n    class T // 2\u9805\u6F14\u7B97\u5B50\uFF0E\r\n>\r\nstruct Monoid {\r\n \
    \   S m_val;\r\n    Monoid() :m_val(element) {}\r\n    Monoid(S val) :m_val(val)\
    \ {}\r\n    Monoid binaryOperation(const Monoid& m2)const { return T()(m_val,\
    \ m2.m_val); }\r\n    friend std::ostream& operator<<(std::ostream& os, const\
    \ Monoid& m) {\r\n        os << m.m_val;\r\n        return os;\r\n    }\r\n};\r\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Graph/Tree/ReRootingDP.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Graph/Tree/ReRootingDP.hpp
layout: document
redirect_from:
- /library/Library/Graph/Tree/ReRootingDP.hpp
- /library/Library/Graph/Tree/ReRootingDP.hpp.html
title: Library/Graph/Tree/ReRootingDP.hpp
---
