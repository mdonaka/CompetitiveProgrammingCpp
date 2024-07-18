---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Graph/Graph.hpp
    title: Library/Graph/Graph.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Tree/TreeDP.hpp
    title: Library/Graph/Tree/TreeDP.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/763
    links:
    - https://yukicoder.me/problems/no/763
  bundledCode: "#line 1 \"Test/Graph/Tree/TreeDP.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/763\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include <queue>\r\n\r\nusing\
    \ ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr char endl\
    \ = '\\n';\r\n\r\n#line 3 \"Library/Graph/Graph.hpp\"\n#include <deque>\r\n#include\
    \ <tuple>\r\n\r\ntemplate<class Node = int, class Cost = long long>\r\nclass Graph\
    \ {\r\n    //using Node = int;\r\n    //using Cost = long long;\r\n\r\n    using\
    \ Edge = std::pair<Node, Cost>;\r\n    using Edges = std::vector<Edge>;\r\n\r\n\
    \    const int m_n;\r\n    std::vector<Edges> m_graph;\r\n\r\npublic:\r\n    Graph(int\
    \ n) :m_n(n), m_graph(n) {}\r\n\r\n    auto addEdge(const Node& f, const Node&\
    \ t, const Cost& c = 1) {\r\n        m_graph[f].emplace_back(t, c);\r\n    }\r\
    \n    auto addEdgeUndirected(const Node& f, const Node& t, const Cost& c = 1)\
    \ {\r\n        addEdge(f, t, c); addEdge(t, f, c);\r\n    }\r\n    auto getEdges(const\
    \ Node& from)const {\r\n        class EdgesRange {\r\n            const typename\
    \ Edges::const_iterator b, e;\r\n        public:\r\n            EdgesRange(const\
    \ Edges& edges) :b(edges.begin()), e(edges.end()) {}\r\n            auto begin()const\
    \ { return b; }\r\n            auto end()const { return e; }\r\n        };\r\n\
    \        return EdgesRange(m_graph[from]);\r\n    }\r\n    auto getEdges()const\
    \ {\r\n        std::deque<std::tuple<Node, Node, Cost>> edges;\r\n        for(Node\
    \ from = 0; from < m_n; ++from) for(const auto& [to, c] : getEdges(from)) {\r\n\
    \            edges.emplace_back(from, to, c);\r\n        }\r\n        return edges;\r\
    \n    }\r\n    auto getEdgesExcludeCost()const {\r\n        std::deque<std::pair<Node,\
    \ Node>> edges;\r\n        for(Node from = 0; from < m_n; ++from) for(const auto&\
    \ [to, _] : getEdges(from)) {\r\n            edges.emplace_back(from, to);\r\n\
    \        }\r\n        return edges;\r\n    }\r\n    auto reverse()const {\r\n\
    \        auto rev = Graph<Node, Cost>(m_n);\r\n        for(const auto& [from,\
    \ to, c] : getEdges()) {\r\n            rev.addEdge(to, from, c);\r\n        }\r\
    \n        return rev;\r\n    }\r\n    auto size()const { return m_n; };\r\n  \
    \  auto debug(bool directed = false)const {\r\n        for(const auto& [f, t,\
    \ c] : getEdges())if(f < t || directed) {\r\n            std::cout << f << \"\
    \ -> \" << t << \": \" << c << std::endl;\r\n        }\r\n    }\r\n};\n#line 4\
    \ \"Library/Graph/Tree/TreeDP.hpp\"\n\r\n#line 6 \"Library/Graph/Tree/TreeDP.hpp\"\
    \n\r\ntemplate<class Node, class Cost, class Lambda>\r\nauto treeDP(const Graph<Node,\
    \ Cost>& tree, Node root, const Lambda& lambda) {\r\n    auto n = tree.size();\r\
    \n    std::vector<Node> in(n);\r\n    for(const auto& [f, t] : tree.getEdgesExcludeCost())\
    \ if(f < t) {\r\n        ++in[f]; ++in[t];\r\n    }\r\n    std::queue<Node> q;\r\
    \n    std::vector<bool> used(n);\r\n    for(Node i = 0; i < n; ++i)if(i != root\
    \ && in[i] == 1) {\r\n        q.emplace(i);\r\n    }\r\n    while(!q.empty())\
    \ {\r\n        auto from = q.front();\r\n        q.pop();\r\n        used[from]\
    \ = true;\r\n\r\n        for(const auto& [to, _] : tree.getEdges(from)) {\r\n\
    \            if(used[to]) { continue; }\r\n            lambda(from, to);\r\n \
    \           --in[to];\r\n            if(to != root && in[to] == 1) { q.emplace(to);\
    \ }\r\n        }\r\n    }\r\n}\r\n#line 14 \"Test/Graph/Tree/TreeDP.test.cpp\"\
    \n\r\nsigned main() {\r\n    ll n;\r\n    cin >> n;\r\n    Graph<int, bool> tree(n);\r\
    \n    for(int f = 0; f < n - 1; ++f) {\r\n        int u, v;\r\n        cin >>\
    \ u >> v;\r\n        --u; --v;\r\n        tree.addEdgeUndirected(u, v);\r\n  \
    \  }\r\n\r\n    std::vector<int> dp1(n);\r\n    std::vector<int> dp2(n, 1);\r\n\
    \    treeDP(tree, 0, [&](int f, int t) {\r\n        dp1[t] += std::max(dp1[f],\
    \ dp2[f]);\r\n        dp2[t] += std::max(dp1[f], dp2[f] - 1);\r\n    });\r\n\r\
    \n    auto ans = std::max(dp1[0], dp2[0]);\r\n    cout << ans << endl;\r\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/763\"\r\n\r\n#include\
    \ <iostream>\r\n#include <vector>\r\n#include <queue>\r\n\r\nusing ll = long long;\r\
    \nusing std::cout;\r\nusing std::cin;\r\nconstexpr char endl = '\\n';\r\n\r\n\
    #include \"./../../../Library/Graph/Graph.hpp\"\r\n#include \"./../../../Library/Graph/Tree/TreeDP.hpp\"\
    \r\n\r\nsigned main() {\r\n    ll n;\r\n    cin >> n;\r\n    Graph<int, bool>\
    \ tree(n);\r\n    for(int f = 0; f < n - 1; ++f) {\r\n        int u, v;\r\n  \
    \      cin >> u >> v;\r\n        --u; --v;\r\n        tree.addEdgeUndirected(u,\
    \ v);\r\n    }\r\n\r\n    std::vector<int> dp1(n);\r\n    std::vector<int> dp2(n,\
    \ 1);\r\n    treeDP(tree, 0, [&](int f, int t) {\r\n        dp1[t] += std::max(dp1[f],\
    \ dp2[f]);\r\n        dp2[t] += std::max(dp1[f], dp2[f] - 1);\r\n    });\r\n\r\
    \n    auto ans = std::max(dp1[0], dp2[0]);\r\n    cout << ans << endl;\r\n}"
  dependsOn:
  - Library/Graph/Graph.hpp
  - Library/Graph/Tree/TreeDP.hpp
  isVerificationFile: true
  path: Test/Graph/Tree/TreeDP.test.cpp
  requiredBy: []
  timestamp: '2024-07-18 23:59:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Graph/Tree/TreeDP.test.cpp
layout: document
redirect_from:
- /verify/Test/Graph/Tree/TreeDP.test.cpp
- /verify/Test/Graph/Tree/TreeDP.test.cpp.html
title: Test/Graph/Tree/TreeDP.test.cpp
---
