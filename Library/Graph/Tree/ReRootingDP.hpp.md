---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Library/Search/BFSonGraph.hpp
    title: Library/Search/BFSonGraph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Graph/Tree/ReRootingDP.hpp\"\n\r\n#line 1 \"Library/Search/BFSonGraph.hpp\"\
    \n#include <unordered_map>\r\n#include <queue>\r\n\r\ntemplate<class Lambda>\r\
    \nauto graphBFS(long long n, const std::unordered_multimap<long long, long long>&\
    \ graph, long long root, const Lambda& lambda) {\r\n\tV<bool> isUsed(n, false);\
    \ isUsed[root] = true;\r\n\tstd::queue<long long> q; q.emplace(root);\r\n\twhile\
    \ (!q.empty()) {\r\n\t\tauto from = q.front();\r\n\t\tq.pop();\r\n\r\n\t\tauto\
    \ range = graph.equal_range(from);\r\n\t\tREPI2(itr, range.first, range.second)\
    \ {\r\n\t\t\tauto to = itr->second;\r\n\t\t\tif (!isUsed[to]) {\r\n\t\t\t\tq.emplace(to);\r\
    \n\t\t\t\tisUsed[to] = true;\r\n\t\t\t\tlambda(from, to);\r\n\t\t\t}\r\n\t\t}\r\
    \n\t}\r\n}\r\n#line 4 \"Library/Graph/Tree/ReRootingDP.hpp\"\n\r\n/*\r\n * \u90E8\
    \u5206\u6728\u306E\u60C5\u5831\u3092\u30DE\u30FC\u30B8\u3059\u308BMonoid\r\n *\
    \ edge\u306E\u60C5\u5831\u3092\u89AA\u306B\u6D41\u3059edge_f(M, f, t)\r\n * node\u306E\
    \u60C5\u5831\u3092\u89AA\u306B\u6D41\u3059node_f(M, i)\r\n */\r\ntemplate<class\
    \ Monoid, class Lambda1, class Lambda2>\r\nauto reRootingDP(long long n,\r\n \
    \                const std::unordered_multimap<long long, long long>& graph,\r\
    \n                 const Lambda1& edge_f,\r\n                 const Lambda2& node_f)\
    \ {\r\n\r\n    constexpr int root = 0;\r\n\r\n    // <\u8FBA\u60C5\u5831\u3092\
    \u8003\u616E\u3057\u305FMonoid\u306E2\u9805\u6F14\u7B97>\r\n    auto merge = [&](Monoid&\
    \ m1, const Monoid& m2, ll f = -1, ll t = -1) {\r\n        if(f == -1 && t ==\
    \ -1) { m1 = m1.binaryOperation(m2); return; }\r\n        m1 = m1.binaryOperation(edge_f(m2,\
    \ f, t));\r\n    };\r\n\r\n    // <node:to\u3092\u6839\u3068\u3057\u305F\u6728\
    \u3067\u5168\u3066\u30DE\u30FC\u30B8\u3057\u305F\u89E3\u3092\u6C42\u3081\u308B\
    >\r\n    std::vector<std::deque<pair<int, Monoid>>> partial(n);\r\n    auto all_merge\
    \ = [&](ll to) {\r\n        Monoid val{};\r\n        for(const auto& [from, ad]\
    \ : partial[to]) { merge(val, ad, from, to); }\r\n        return node_f(val, to);\r\
    \n    };\r\n\r\n    // <node:to\u3092\u6839\u3068\u3057\u305F\u6728\u3067from\u4EE5\
    \u5916\u30DE\u30FC\u30B8\u3057\u305F\u89E3\u3092\u6C42\u3081\u308B>\r\n    std::vector<std::unordered_map<int,\
    \ Monoid>> partial_ac(n);\r\n    std::vector<Monoid> ret(n);\r\n    auto accumulation\
    \ = [&](ll to) {\r\n        // \u5DE6\u304B\u3089\u30DE\u30FC\u30B8\r\n      \
    \  Monoid val_ord{};\r\n        for(const auto& [from, ad] : partial[to]) {\r\n\
    \            partial_ac[to].emplace(from, val_ord);\r\n            merge(val_ord,\
    \ ad, from, to);\r\n        }\r\n        // \u53F3\u304B\u3089\u30DE\u30FC\u30B8\
    \r\n        Monoid val_rord{};\r\n        for(auto rit = partial[to].rbegin();\
    \ rit != partial[to].rend(); ++rit) {\r\n            auto [from, ad] = *rit;\r\
    \n            merge(partial_ac[to][from], val_rord);\r\n            merge(val_rord,\
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
  code: "#pragma once\r\n\r\n#include \"../../Search/BFSonGraph.hpp\"\r\n\r\n/*\r\n\
    \ * \u90E8\u5206\u6728\u306E\u60C5\u5831\u3092\u30DE\u30FC\u30B8\u3059\u308BMonoid\r\
    \n * edge\u306E\u60C5\u5831\u3092\u89AA\u306B\u6D41\u3059edge_f(M, f, t)\r\n *\
    \ node\u306E\u60C5\u5831\u3092\u89AA\u306B\u6D41\u3059node_f(M, i)\r\n */\r\n\
    template<class Monoid, class Lambda1, class Lambda2>\r\nauto reRootingDP(long\
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
  dependsOn:
  - Library/Search/BFSonGraph.hpp
  isVerificationFile: false
  path: Library/Graph/Tree/ReRootingDP.hpp
  requiredBy: []
  timestamp: '2023-06-14 03:49:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Graph/Tree/ReRootingDP.hpp
layout: document
redirect_from:
- /library/Library/Graph/Tree/ReRootingDP.hpp
- /library/Library/Graph/Tree/ReRootingDP.hpp.html
title: Library/Graph/Tree/ReRootingDP.hpp
---
