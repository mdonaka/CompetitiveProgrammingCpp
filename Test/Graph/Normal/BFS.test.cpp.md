---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Algorithms/BinarySearch.hpp
    title: Library/Algorithms/BinarySearch.hpp
  - icon: ':question:'
    path: Library/Graph/Graph.hpp
    title: Library/Graph/Graph.hpp
  - icon: ':question:'
    path: Library/Graph/Normal/BFS.hpp
    title: Library/Graph/Normal/BFS.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1473
    links:
    - https://yukicoder.me/problems/no/1473
  bundledCode: "#line 1 \"Test/Graph/Normal/BFS.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/1473\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n\r\n#line 3 \"Library/Graph/Graph.hpp\"\
    \n#include <deque>\r\n#include <tuple>\r\n\r\ntemplate<class Node = int, class\
    \ Cost = long long>\r\nclass Graph {\r\n    //using Node = int;\r\n    //using\
    \ Cost = long long;\r\n\r\n    using Edge = std::pair<Node, Cost>;\r\n    using\
    \ Edges = std::vector<Edge>;\r\n\r\n    const int m_n;\r\n    std::vector<Edges>\
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
    \n    }\r\n};\n#line 2 \"Library/Graph/Normal/BFS.hpp\"\n\r\n#line 4 \"Library/Graph/Normal/BFS.hpp\"\
    \n#include <queue>\r\n\r\n#line 7 \"Library/Graph/Normal/BFS.hpp\"\n\r\ntemplate<class\
    \ Node, class Cost, class Lambda>\r\nauto bfs(const Graph<Node, Cost>& graph,\
    \ const Node& root, const Lambda& lambda) {\r\n    auto n = graph.size();\r\n\
    \    std::vector<bool> used(n); used[root] = true;\r\n    std::queue<Node> q;\
    \ q.emplace(root);\r\n    while(!q.empty()) {\r\n        auto from = q.front();\r\
    \n        q.pop();\r\n        for(const auto& [to, _] : graph.getEdges(from))\
    \ {\r\n            if(used[to]) { continue; }\r\n            q.emplace(to);\r\n\
    \            used[to] = true;\r\n            lambda(from, to);\r\n        }\r\n\
    \    }\r\n}\r\n#line 2 \"Library/Algorithms/BinarySearch.hpp\"\n#include <numeric>\r\
    \n\r\ntemplate <class Lambda>\r\nauto binarySearch(double mn, double mx, int rep,\
    \ const Lambda& judge,\r\n                  bool rev = false) {\r\n    auto ok\
    \ = mx;\r\n    auto ng = mn;\r\n    for(int _ = 0; _ < rep; ++_) {\r\n       \
    \ auto mid = (ok + ng) / 2;\r\n        auto isOk = judge(mid);\r\n        if((isOk\
    \ && !rev) || (!isOk && rev)) {\r\n            ok = mid;\r\n        } else {\r\
    \n            ng = mid;\r\n        }\r\n    }\r\n    return ok;\r\n}\r\n\r\ntemplate\
    \ <class Lambda>\r\nauto binarySearch(long long ok, long long ng, const Lambda&\
    \ is_ok) {\r\n    while(std::abs(ok - ng) > 1) {\r\n        long long mid = (ok\
    \ + ng) >> 1;\r\n        (is_ok(mid) ? ok : ng) = mid;\r\n    }\r\n    return\
    \ ok;\r\n}\r\n#line 9 \"Test/Graph/Normal/BFS.test.cpp\"\n\r\nusing ll = long\
    \ long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr char endl = '\\n';\r\
    \n\r\nsigned main() {\r\n    ll n, m;\r\n    cin >> n >> m;\r\n    auto graph_all\
    \ = Graph(n);\r\n    for(int i = 0; i < m; ++i) {\r\n        ll s, t, d;\r\n \
    \       cin >> s >> t >> d;\r\n        graph_all.addEdgeUndirected(s - 1, t -\
    \ 1, d);\r\n    }\r\n\r\n    auto solve = [&](ll w) {\r\n        auto graph =\
    \ Graph(n);\r\n        for(const auto& [s, t, d] : graph_all.getEdges()) {\r\n\
    \            if(w <= d) { graph.addEdge(s, t); }\r\n        }\r\n\r\n        std::vector<int>\
    \ dv(n);\r\n        bfs(graph, 0, [&](ll f, ll t) {dv[t] = dv[f] + 1; });\r\n\
    \        return dv[n - 1];\r\n    };\r\n\r\n    auto w_max = binarySearch(0, 1e9,\
    \ [&](ll w) {\r\n        auto d = solve(w);\r\n        return d > 0;\r\n    });\r\
    \n\r\n    auto ans = solve(w_max);\r\n    cout << w_max << \" \" << ans << endl;\r\
    \n}\r\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1473\"\r\n\r\n#include\
    \ <iostream>\r\n#include <vector>\r\n\r\n#include \"./../../../Library/Graph/Graph.hpp\"\
    \r\n#include \"./../../../Library/Graph/Normal/BFS.hpp\"\r\n#include \"./../../../Library/Algorithms/BinarySearch.hpp\"\
    \r\n\r\nusing ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr\
    \ char endl = '\\n';\r\n\r\nsigned main() {\r\n    ll n, m;\r\n    cin >> n >>\
    \ m;\r\n    auto graph_all = Graph(n);\r\n    for(int i = 0; i < m; ++i) {\r\n\
    \        ll s, t, d;\r\n        cin >> s >> t >> d;\r\n        graph_all.addEdgeUndirected(s\
    \ - 1, t - 1, d);\r\n    }\r\n\r\n    auto solve = [&](ll w) {\r\n        auto\
    \ graph = Graph(n);\r\n        for(const auto& [s, t, d] : graph_all.getEdges())\
    \ {\r\n            if(w <= d) { graph.addEdge(s, t); }\r\n        }\r\n\r\n  \
    \      std::vector<int> dv(n);\r\n        bfs(graph, 0, [&](ll f, ll t) {dv[t]\
    \ = dv[f] + 1; });\r\n        return dv[n - 1];\r\n    };\r\n\r\n    auto w_max\
    \ = binarySearch(0, 1e9, [&](ll w) {\r\n        auto d = solve(w);\r\n       \
    \ return d > 0;\r\n    });\r\n\r\n    auto ans = solve(w_max);\r\n    cout <<\
    \ w_max << \" \" << ans << endl;\r\n}\r\n"
  dependsOn:
  - Library/Graph/Graph.hpp
  - Library/Graph/Normal/BFS.hpp
  - Library/Algorithms/BinarySearch.hpp
  isVerificationFile: true
  path: Test/Graph/Normal/BFS.test.cpp
  requiredBy: []
  timestamp: '2024-07-18 23:59:07+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/Graph/Normal/BFS.test.cpp
layout: document
redirect_from:
- /verify/Test/Graph/Normal/BFS.test.cpp
- /verify/Test/Graph/Normal/BFS.test.cpp.html
title: Test/Graph/Normal/BFS.test.cpp
---
