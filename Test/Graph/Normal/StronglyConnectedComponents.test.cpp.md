---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Normal/StronglyConnectedComponents.hpp
    title: Library/Graph/Normal/StronglyConnectedComponents.hpp
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
    #include <iostream>\r\n#line 2 \"Library/Graph/Normal/StronglyConnectedComponents.hpp\"\
    \n\r\n#include <unordered_map>\r\n#include <unordered_set>\r\n#include <algorithm>\r\
    \n#include <vector>\r\n#include <deque>\r\n\r\nclass StronglyConnectedComponents\
    \ {\r\n\r\n    struct HashPair {\r\n        template<class T1, class T2>\r\n \
    \       size_t operator()(const std::pair<T1, T2>& p) const {\r\n            auto\
    \ hash1 = std::hash<T1>{}(p.first);\r\n            auto hash2 = std::hash<T2>{}(p.second);\r\
    \n            size_t seed = 0;\r\n            seed ^= hash1 + 0x9e3779b9 + (seed\
    \ << 6) + (seed >> 2);\r\n            seed ^= hash2 + 0x9e3779b9 + (seed << 6)\
    \ + (seed >> 2);\r\n            return seed;\r\n        }\r\n    };\r\n\r\n  \
    \  using Graph = std::vector<std::vector<int>>;\r\n\r\n    const int m_n;\r\n\
    \    const Graph m_graph;\r\n    const std::vector<int> m_group;\r\n\r\n    static\
    \ inline auto reverse(int n, const Graph& graph) {\r\n        std::vector<std::vector<int>>\
    \ ret(n);\r\n        for(int f = 0; f < n; ++f) for(const auto& t : graph[f])\
    \ {\r\n            ret[t].emplace_back(f);\r\n        }\r\n        return ret;\r\
    \n    }\r\n    template <class F>\r\n    static inline auto dfs(const std::vector<std::vector<int>>&\
    \ graph, int from,\r\n                           std::vector<bool>& is_used,\r\
    \n                           const F& f)->void {\r\n        is_used[from] = true;\r\
    \n        for(const auto& to : graph[from]) {\r\n            if(is_used[to]) {\
    \ continue; }\r\n            dfs(graph, to, is_used, f);\r\n        }\r\n    \
    \    f(from);\r\n    }\r\n\r\n    static inline auto constructGroup(int n, const\
    \ Graph& graph) {\r\n        std::vector<int> order; order.reserve(n);\r\n   \
    \     std::vector<bool> is_used(n);\r\n        for(int from = 0; from < n; ++from)\
    \ if(!is_used[from]) {\r\n            dfs(graph, from, is_used, [&](int f) {\r\
    \n                order.emplace_back(f);\r\n            });\r\n        }\r\n\r\
    \n        int g = 0;\r\n        std::vector<int> group(n);\r\n        std::vector<bool>\
    \ is_used2(n);\r\n        auto rev = reverse(n, graph);\r\n        for(int i =\
    \ n - 1; i >= 0; --i)if(!is_used2[order[i]]) {\r\n            dfs(rev, order[i],\
    \ is_used2, [&](int f) {group[f] = g; });\r\n            ++g;\r\n        }\r\n\
    \        return group;\r\n    }\r\n    auto constructGroupNodes() const {\r\n\
    \    }\r\npublic:\r\n    StronglyConnectedComponents(int n, const Graph& graph)\
    \ :\r\n        m_n(n),\r\n        m_graph(graph),\r\n        m_group(constructGroup(n,\
    \ m_graph)) {\r\n    }\r\n    // graph\u306E\u30B3\u30D4\u30FC\u30B3\u30B9\u30C8\
    \u304C\u5927\u304D\u3044\u306E\u3067\u3053\u3063\u3061\u63A8\u5968\r\n    StronglyConnectedComponents(int\
    \ n, Graph&& graph) :\r\n        m_n(n),\r\n        m_graph(std::move(graph)),\r\
    \n        m_group(constructGroup(n, m_graph)) {\r\n    }\r\n\r\n    auto isSameGroup(int\
    \ a, int b)const {\r\n        return m_group[a] == m_group[b];\r\n    }\r\n  \
    \  auto getGroupNodes()const {\r\n        auto size = *std::max_element(m_group.begin(),\
    \ m_group.end()) + 1;\r\n        std::vector<std::deque<int>> groupNodes(size);\r\
    \n        for(int gi = 0; gi < m_n; ++gi) {\r\n            groupNodes[m_group[gi]].emplace_back(gi);\r\
    \n        }\r\n        return groupNodes;\r\n    }\r\n    auto getGroupGraph()const\
    \ {\r\n        std::unordered_set<std::pair<int, int>, HashPair> st;\r\n     \
    \   st.reserve(m_graph.size());\r\n        for(int f = 0; f < m_n; ++f) for(const\
    \ auto& t : m_graph[f]) if(!isSameGroup(f, t)) {\r\n            st.emplace(m_group[f],\
    \ m_group[t]);\r\n        }\r\n        Graph ret(m_n);\r\n        for(const auto&\
    \ [f, t] : st) { ret[f].emplace_back(t); }\r\n        return ret;\r\n    }\r\n\
    };\r\n#line 5 \"Test/Graph/Normal/StronglyConnectedComponents.test.cpp\"\n\r\n\
    using ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr char\
    \ endl = '\\n';\r\n\r\n\r\nsigned main() {\r\n    int n, m;\r\n    cin >> n >>\
    \ m;\r\n    std::vector<std::vector<int>> graph(n);\r\n    for(int _ = 0; _ <\
    \ m; ++_) {\r\n        int f, t;\r\n        cin >> f >> t;\r\n        graph[f].emplace_back(t);\r\
    \n    }\r\n\r\n    auto scc = StronglyConnectedComponents(n, graph);\r\n\r\n \
    \   int q;\r\n    cin >> q;\r\n    for(int _ = 0; _ < q; ++_) {\r\n        int\
    \ u, v;\r\n        cin >> u >> v;\r\n        cout << scc.isSameGroup(u, v) <<\
    \ endl;\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C\"\r\n\
    \r\n#include <iostream>\r\n#include \"./../../../Library/Graph/Normal/StronglyConnectedComponents.hpp\"\
    \r\n\r\nusing ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr\
    \ char endl = '\\n';\r\n\r\n\r\nsigned main() {\r\n    int n, m;\r\n    cin >>\
    \ n >> m;\r\n    std::vector<std::vector<int>> graph(n);\r\n    for(int _ = 0;\
    \ _ < m; ++_) {\r\n        int f, t;\r\n        cin >> f >> t;\r\n        graph[f].emplace_back(t);\r\
    \n    }\r\n\r\n    auto scc = StronglyConnectedComponents(n, graph);\r\n\r\n \
    \   int q;\r\n    cin >> q;\r\n    for(int _ = 0; _ < q; ++_) {\r\n        int\
    \ u, v;\r\n        cin >> u >> v;\r\n        cout << scc.isSameGroup(u, v) <<\
    \ endl;\r\n    }\r\n}"
  dependsOn:
  - Library/Graph/Normal/StronglyConnectedComponents.hpp
  isVerificationFile: true
  path: Test/Graph/Normal/StronglyConnectedComponents.test.cpp
  requiredBy: []
  timestamp: '2023-03-21 10:05:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Graph/Normal/StronglyConnectedComponents.test.cpp
layout: document
redirect_from:
- /verify/Test/Graph/Normal/StronglyConnectedComponents.test.cpp
- /verify/Test/Graph/Normal/StronglyConnectedComponents.test.cpp.html
title: Test/Graph/Normal/StronglyConnectedComponents.test.cpp
---
