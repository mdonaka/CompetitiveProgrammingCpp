---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/UnionFind.hpp
    title: Library/DataStructure/UnionFind.hpp
  - icon: ':question:'
    path: Library/Graph/Graph.hpp
    title: Library/Graph/Graph.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Normal/Kruskal.hpp
    title: Library/Graph/Normal/Kruskal.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
  bundledCode: "#line 1 \"Test/Graph/Normal/Kruskal.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\"\r\n\r\n#include\
    \ <iostream>\r\n#line 2 \"Library/Graph/Graph.hpp\"\n#include <vector>\r\n#include\
    \ <deque>\r\n#include <tuple>\r\n\r\ntemplate<class Node = int, class Cost = long\
    \ long>\r\nclass Graph {\r\n    //using Node = int;\r\n    //using Cost = long\
    \ long;\r\n\r\n    using Edge = std::pair<Node, Cost>;\r\n    using Edges = std::vector<Edge>;\r\
    \n\r\n    const int m_n;\r\n    std::vector<Edges> m_graph;\r\n\r\npublic:\r\n\
    \    Graph(int n) :m_n(n), m_graph(n) {}\r\n\r\n    auto addEdge(const Node& f,\
    \ const Node& t, const Cost& c = 1) {\r\n        m_graph[f].emplace_back(t, c);\r\
    \n    }\r\n    auto addEdgeUndirected(const Node& f, const Node& t, const Cost&\
    \ c = 1) {\r\n        addEdge(f, t, c); addEdge(t, f, c);\r\n    }\r\n    auto\
    \ getEdges(const Node& from)const {\r\n        class EdgesRange {\r\n        \
    \    const typename Edges::const_iterator b, e;\r\n        public:\r\n       \
    \     EdgesRange(const Edges& edges) :b(edges.begin()), e(edges.end()) {}\r\n\
    \            auto begin()const { return b; }\r\n            auto end()const {\
    \ return e; }\r\n        };\r\n        return EdgesRange(m_graph[from]);\r\n \
    \   }\r\n    auto getEdges()const {\r\n        std::deque<std::tuple<Node, Node,\
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
    \n    }\r\n};\n#line 2 \"Library/Graph/Normal/Kruskal.hpp\"\n\r\n#include <queue>\r\
    \n#line 3 \"Library/DataStructure/UnionFind.hpp\"\n#include <numeric>\r\n/**\r\
    \n *\tUnionFind\u6728\u3092\u69CB\u6210\u3059\u308B\r\n *\tnode\u306E\u6DF1\u3055\
    \uFF0C\u6728\u306E\u30B5\u30A4\u30BA\u3092\u53D6\u5F97\u53EF\u80FD\r\n */\r\n\
    class UnionFind {\r\n    std::vector<int> m_root;\r\n    std::vector<int> m_depth;\r\
    \n    std::vector<int> m_size;\r\npublic:\r\n    UnionFind(int size) :\r\n   \
    \     m_root(size),\r\n        m_depth(size, 0),\r\n        m_size(size, 1) {\r\
    \n        std::iota(m_root.begin(), m_root.end(), 0);\r\n    }\r\n    void unite(int\
    \ x, int y) {\r\n        x = root(x); y = root(y);\r\n        if(x == y) { return;\
    \ }\r\n        auto t = size(x) + size(y);\r\n        m_size[x] = m_size[y] =\
    \ t;\r\n        if(m_depth[x] < m_depth[y]) { m_root[x] = y; } else { m_root[y]\
    \ = x; }\r\n        if(m_depth[x] == m_depth[y]) { ++m_depth[x]; }\r\n    }\r\n\
    \    bool isSame(int x, int y) {\r\n        return root(x) == root(y);\r\n   \
    \ }\r\n    int root(int x) {\r\n        if(m_root[x] == x) { return x; }\r\n \
    \       return m_root[x] = root(m_root[x]);\r\n    }\r\n    int size(int x) {\r\
    \n        if(m_root[x] == x) { return m_size[x]; }\r\n        return size(m_root[x]\
    \ = root(m_root[x]));\r\n    }\r\n};\r\n#line 6 \"Library/Graph/Normal/Kruskal.hpp\"\
    \n\r\ntemplate<class Node, class Cost>\r\nauto kruskal(const Graph<Node, Cost>&\
    \ graph) {\r\n    auto n = graph.size();\r\n    auto min_spanning_tree = Graph<Node,\
    \ Cost>(n);\r\n\r\n    auto dsu = UnionFind(n);\r\n    using Type = std::pair<Cost,\
    \ std::pair<Node, Node>>;\r\n    std::priority_queue<Type, std::vector<Type>,\
    \ std::greater<Type>> q;\r\n    for(const auto& [f, t, c] : graph.getEdges())\
    \ {\r\n        q.emplace(c, std::make_pair(f, t));\r\n    }\r\n\r\n    while(!q.empty())\
    \ {\r\n        auto [cost, ft] = q.top();\r\n        auto [from, to] = ft;\r\n\
    \        q.pop();\r\n        if(dsu.isSame(from, to)) { continue; }\r\n      \
    \  dsu.unite(from, to);\r\n        min_spanning_tree.addEdgeUndirected(from, to,\
    \ cost);\r\n    }\r\n\r\n    return min_spanning_tree;\r\n}\r\n#line 6 \"Test/Graph/Normal/Kruskal.test.cpp\"\
    \n\r\nusing ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr\
    \ char endl = '\\n';\r\n\r\n\r\nsigned main() {\r\n    int n, m;\r\n    cin >>\
    \ n >> m;\r\n\r\n    auto graph = Graph(n);\r\n    for(int i = 0; i < m; ++i)\
    \ {\r\n        int s, t, w;\r\n        cin >> s >> t >> w;\r\n        graph.addEdgeUndirected(s,\
    \ t, w);\r\n    }\r\n\r\n    auto min_spanning_tree = kruskal(graph);\r\n\r\n\
    \    ll ans = 0;\r\n    for(const auto& [f, t, c] : min_spanning_tree.getEdges())\
    \ {\r\n        if(f < t) { ans += c; }\r\n    }\r\n    cout << ans << endl;\r\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\"\
    \r\n\r\n#include <iostream>\r\n#include \"./../../../Library/Graph/Graph.hpp\"\
    \r\n#include \"./../../../Library/Graph/Normal/Kruskal.hpp\"\r\n\r\nusing ll =\
    \ long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr char endl = '\\\
    n';\r\n\r\n\r\nsigned main() {\r\n    int n, m;\r\n    cin >> n >> m;\r\n\r\n\
    \    auto graph = Graph(n);\r\n    for(int i = 0; i < m; ++i) {\r\n        int\
    \ s, t, w;\r\n        cin >> s >> t >> w;\r\n        graph.addEdgeUndirected(s,\
    \ t, w);\r\n    }\r\n\r\n    auto min_spanning_tree = kruskal(graph);\r\n\r\n\
    \    ll ans = 0;\r\n    for(const auto& [f, t, c] : min_spanning_tree.getEdges())\
    \ {\r\n        if(f < t) { ans += c; }\r\n    }\r\n    cout << ans << endl;\r\n\
    }"
  dependsOn:
  - Library/Graph/Graph.hpp
  - Library/Graph/Normal/Kruskal.hpp
  - Library/DataStructure/UnionFind.hpp
  isVerificationFile: true
  path: Test/Graph/Normal/Kruskal.test.cpp
  requiredBy: []
  timestamp: '2024-07-18 23:59:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Graph/Normal/Kruskal.test.cpp
layout: document
redirect_from:
- /verify/Test/Graph/Normal/Kruskal.test.cpp
- /verify/Test/Graph/Normal/Kruskal.test.cpp.html
title: Test/Graph/Normal/Kruskal.test.cpp
---
