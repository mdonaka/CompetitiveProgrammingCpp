---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Graph/Graph.hpp
    title: Library/Graph/Graph.hpp
  - icon: ':x:'
    path: Library/Graph/Normal/BFS.hpp
    title: Library/Graph/Normal/BFS.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/Graph/Tree/LowestCommonAncestor.test.cpp
    title: Test/Graph/Tree/LowestCommonAncestor.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Graph/Tree/LowestCommonAncestor.hpp\"\n#include\
    \ <vector>\r\n#include <cmath>\r\n\r\n#line 3 \"Library/Graph/Graph.hpp\"\n#include\
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
    \n    }\r\n};\n#line 2 \"Library/Graph/Normal/BFS.hpp\"\n\r\n#line 4 \"Library/Graph/Normal/BFS.hpp\"\
    \n#include <queue>\r\n\r\n#line 7 \"Library/Graph/Normal/BFS.hpp\"\n\r\ntemplate<class\
    \ Node, class Cost, class Lambda>\r\nauto bfs(const Graph<Node, Cost>& graph,\
    \ const Node& root, const Lambda& lambda) {\r\n    auto n = graph.size();\r\n\
    \    std::vector<bool> used(n); used[root] = true;\r\n    std::queue<Node> q;\
    \ q.emplace(root);\r\n    while(!q.empty()) {\r\n        auto from = q.front();\r\
    \n        q.pop();\r\n        for(const auto& [to, _] : graph.getEdges(from))\
    \ {\r\n            if(used[to]) { continue; }\r\n            q.emplace(to);\r\n\
    \            used[to] = true;\r\n            lambda(from, to);\r\n        }\r\n\
    \    }\r\n}\r\n#line 7 \"Library/Graph/Tree/LowestCommonAncestor.hpp\"\n\r\ntemplate<class\
    \ Node, class Cost>\r\nclass LowestCommonAncestor {\r\n    const std::vector<std::vector<Node>>\
    \ m_parent;\r\n    const std::vector<Node> m_depth;\r\n\r\n    static inline auto\
    \ constructParent(const Graph<Node, Cost>& tree, const Node& root) {\r\n     \
    \   auto n = tree.size();\r\n        auto size = static_cast<int>(std::log2(n)\
    \ + 1);\r\n        std::vector<std::vector<Node>> parent(n, std::vector<Node>(size,\
    \ root));\r\n        bfs(tree, root, [&](const Node& from, const Node& to) {\r\
    \n            parent[to][0] = from;\r\n        });\r\n        for(int p2 = 1;\
    \ p2 < size; ++p2)for(int f = 0; f < n; ++f) {\r\n            parent[f][p2] =\
    \ parent[parent[f][p2 - 1]][p2 - 1];\r\n        }\r\n        return parent;\r\n\
    \    }\r\n    static inline auto constructDepth(const Graph<Node, Cost>& tree,\
    \ const Node& root) {\r\n        auto n = tree.size();\r\n        std::vector<Node>\
    \ depth(n);\r\n        bfs(tree, root, [&](const Node& from, const Node& to) {\r\
    \n            depth[to] = depth[from] + 1;\r\n        });\r\n        return depth;\r\
    \n    }\r\npublic:\r\n    LowestCommonAncestor(const Graph<Node, Cost>& tree,\
    \ const Node& root) :\r\n        m_parent(constructParent(tree, root)),\r\n  \
    \      m_depth(constructDepth(tree, root)) {\r\n    }\r\n\r\n    auto lca(Node\
    \ l, Node r)const {\r\n        int size = m_parent[0].size();\r\n        if(m_depth[l]\
    \ < m_depth[r]) { std::swap(l, r); }\r\n        for(int k = 0; k < size; ++k)\
    \ {\r\n            if(((m_depth[l] - m_depth[r]) >> k) & 1) {\r\n            \
    \    l = m_parent[l][k];\r\n            }\r\n        }\r\n        if(l == r) {\
    \ return l; }\r\n        for(int k = size - 1; k >= 0; k--) {\r\n            if(m_parent[l][k]\
    \ != m_parent[r][k]) {\r\n                l = m_parent[l][k];\r\n            \
    \    r = m_parent[r][k];\r\n            }\r\n        }\r\n        return m_parent[l][0];\r\
    \n    }\r\n};\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <cmath>\r\n\r\n#include \"\
    ../Graph.hpp\"\r\n#include \"../Normal/BFS.hpp\"\r\n\r\ntemplate<class Node, class\
    \ Cost>\r\nclass LowestCommonAncestor {\r\n    const std::vector<std::vector<Node>>\
    \ m_parent;\r\n    const std::vector<Node> m_depth;\r\n\r\n    static inline auto\
    \ constructParent(const Graph<Node, Cost>& tree, const Node& root) {\r\n     \
    \   auto n = tree.size();\r\n        auto size = static_cast<int>(std::log2(n)\
    \ + 1);\r\n        std::vector<std::vector<Node>> parent(n, std::vector<Node>(size,\
    \ root));\r\n        bfs(tree, root, [&](const Node& from, const Node& to) {\r\
    \n            parent[to][0] = from;\r\n        });\r\n        for(int p2 = 1;\
    \ p2 < size; ++p2)for(int f = 0; f < n; ++f) {\r\n            parent[f][p2] =\
    \ parent[parent[f][p2 - 1]][p2 - 1];\r\n        }\r\n        return parent;\r\n\
    \    }\r\n    static inline auto constructDepth(const Graph<Node, Cost>& tree,\
    \ const Node& root) {\r\n        auto n = tree.size();\r\n        std::vector<Node>\
    \ depth(n);\r\n        bfs(tree, root, [&](const Node& from, const Node& to) {\r\
    \n            depth[to] = depth[from] + 1;\r\n        });\r\n        return depth;\r\
    \n    }\r\npublic:\r\n    LowestCommonAncestor(const Graph<Node, Cost>& tree,\
    \ const Node& root) :\r\n        m_parent(constructParent(tree, root)),\r\n  \
    \      m_depth(constructDepth(tree, root)) {\r\n    }\r\n\r\n    auto lca(Node\
    \ l, Node r)const {\r\n        int size = m_parent[0].size();\r\n        if(m_depth[l]\
    \ < m_depth[r]) { std::swap(l, r); }\r\n        for(int k = 0; k < size; ++k)\
    \ {\r\n            if(((m_depth[l] - m_depth[r]) >> k) & 1) {\r\n            \
    \    l = m_parent[l][k];\r\n            }\r\n        }\r\n        if(l == r) {\
    \ return l; }\r\n        for(int k = size - 1; k >= 0; k--) {\r\n            if(m_parent[l][k]\
    \ != m_parent[r][k]) {\r\n                l = m_parent[l][k];\r\n            \
    \    r = m_parent[r][k];\r\n            }\r\n        }\r\n        return m_parent[l][0];\r\
    \n    }\r\n};"
  dependsOn:
  - Library/Graph/Graph.hpp
  - Library/Graph/Normal/BFS.hpp
  isVerificationFile: false
  path: Library/Graph/Tree/LowestCommonAncestor.hpp
  requiredBy: []
  timestamp: '2024-07-18 23:59:07+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Test/Graph/Tree/LowestCommonAncestor.test.cpp
documentation_of: Library/Graph/Tree/LowestCommonAncestor.hpp
layout: document
redirect_from:
- /library/Library/Graph/Tree/LowestCommonAncestor.hpp
- /library/Library/Graph/Tree/LowestCommonAncestor.hpp.html
title: Library/Graph/Tree/LowestCommonAncestor.hpp
---
