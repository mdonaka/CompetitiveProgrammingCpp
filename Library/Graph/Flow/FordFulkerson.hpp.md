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
  bundledCode: "#line 2 \"Library/Graph/Flow/FordFulkerson.hpp\"\n\r\n#include <vector>\r\
    \n#include <queue>\r\n#include <unordered_map>\r\n#include <unordered_set>\r\n\
    #include <map>\r\n\r\nclass FordFulkerson {\r\n\r\n\tstruct HashPair {\r\n\t\t\
    template<class T1, class T2>\r\n\t\tsize_t operator()(const std::pair<T1, T2>&\
    \ p) const {\r\n\t\t\tauto hash1 = std::hash<T1>{}(p.first);\r\n\t\t\tauto hash2\
    \ = std::hash<T2>{}(p.second);\r\n\t\t\tsize_t seed = 0;\r\n\t\t\tseed ^= hash1\
    \ + 0x9e3779b9 + (seed << 6) + (seed >> 2);\r\n\t\t\tseed ^= hash2 + 0x9e3779b9\
    \ + (seed << 6) + (seed >> 2);\r\n\t\t\treturn seed;\r\n\t\t}\r\n\t};\r\n\r\n\t\
    using node_t = int;\r\n\tusing cost_t = long long;\r\n\tusing Graph_f = std::unordered_multimap<node_t,\
    \ std::pair<node_t, cost_t>>;\r\n\tusing Graph = std::unordered_map<std::pair<node_t,\
    \ node_t>, cost_t, HashPair>;\r\n\r\n\tconst node_t m_n;\r\n\tconst Graph m_graph;\r\
    \n\tconst std::vector<std::unordered_set<node_t>> m_to_list;\r\n\r\n\tstatic auto\
    \ construct_to_list(node_t n, const Graph_f& graph_f) {\r\n\t\tstd::vector<std::unordered_set<node_t>>\
    \ to_list(n);\r\n\t\tfor (const auto& [f, tc] : graph_f) {\r\n\t\t\tauto [t, c]\
    \ = tc;\r\n\t\t\tto_list[f].emplace(t);\r\n\t\t\tto_list[t].emplace(f);\r\n\t\t\
    }\r\n\t\treturn to_list;\r\n\t}\r\n\tstatic auto construct_graph(const Graph_f&\
    \ graph_f) {\r\n\t\tGraph graph;\r\n\t\tfor (const auto& [f, tc] : graph_f) {\r\
    \n\t\t\tauto [t, c] = tc;\r\n\t\t\tgraph[std::pair<node_t, node_t>{f, t}] += c;\r\
    \n\t\t}\r\n\t\treturn graph;\r\n\t}\r\n\r\n\tauto get_route(node_t s, node_t t,\
    \ const Graph& graph) const {\r\n\t\tstd::unordered_set<node_t> visited;\r\n\t\
    \tauto f = [&](auto&& f, node_t now, std::list<node_t>& route)->bool {\r\n\t\t\
    \troute.emplace_back(now);\r\n\t\t\tfor (const auto& to : m_to_list[now]) {\r\n\
    \t\t\t\tif (graph.find({ now, to }) == graph.end()) { continue; }\r\n\t\t\t\t\
    if (to == t) { route.emplace_back(t); return true; }\r\n\t\t\t\tif (visited.find(to)\
    \ == visited.end()) {\r\n\t\t\t\t\tvisited.emplace(to);\r\n\t\t\t\t\tif (f(f,\
    \ to, route)) { return true; }\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\troute.pop_back();\r\
    \n\t\t\treturn false;\r\n\t\t};\r\n\t\tstd::list<node_t> route;\r\n\t\tvisited.emplace(s);\r\
    \n\t\tauto ok = f(f, s, route);\r\n\t\tif (ok) { return route; } else { return\
    \ std::list<node_t>{}; }\r\n\t}\r\n\r\n\r\n\tauto construct_residual(node_t s,\
    \ node_t t)const {\r\n\t\tauto residual = m_graph;\r\n\t\twhile(true) {\r\n\t\t\
    \tauto route = get_route(s, t, residual);\r\n\t\t\tif(route.empty()) { break;\
    \ }\r\n\r\n\t\t\tcost_t mn = 1e9;\r\n\t\t\tnode_t from = s;\r\n\t\t\tfor(const\
    \ auto& to : route)if(from != to) {\r\n\t\t\t\tmn = std::min(mn, residual[{from,\
    \ to}]);\r\n\t\t\t\tfrom = to;\r\n\t\t\t}\r\n\r\n\t\t\tfrom = s;\r\n\t\t\tfor(const\
    \ auto& to : route)if(from != to) {\r\n\t\t\t\tauto& ft = residual[{from, to}];\r\
    \n\t\t\t\tauto use = ft - mn;\r\n\t\t\t\tft -= mn;\r\n\t\t\t\tif(ft == 0) { residual.erase({from,to});\
    \ }\r\n\t\t\t\tresidual[{to, from}] += mn;\r\n\t\t\t\tfrom = to;\r\n\t\t\t}\r\n\
    \t\t}\r\n\t\treturn residual;\r\n\t}\r\npublic:\r\n\tFordFulkerson(node_t n, const\
    \ Graph_f& graph) :\r\n\t\tm_n(n),\r\n\t\tm_graph(construct_graph(graph)),\r\n\
    \t\tm_to_list(construct_to_list(n, graph)) {\r\n\t}\r\n\r\n\tauto max_flow(node_t\
    \ s, node_t t)const {\r\n\t\tauto residual = construct_residual(s, t);\r\n\r\n\
    \t\tcost_t val = 0;\r\n\t\tfor (const auto& to : m_to_list[s]) {\r\n\t\t\tif (m_graph.find({\
    \ s,to }) == m_graph.end()) { continue; }\r\n\t\t\tval += m_graph.at({ s, to })\
    \ - residual[{s, to}];\r\n\t\t}\r\n\t\treturn val;\r\n\t}\r\n\r\n\r\n\tauto get_cut_list(node_t\
    \ s, node_t t) const {\r\n\t\t// \u6B8B\u4F59\u30B0\u30E9\u30D5\u3067\u59CB\u70B9\
    \u304B\u3089\u5230\u9054\u3067\u304D\u308B\u96C6\u5408\r\n\t\tstd::unordered_set<node_t>\
    \ st;\r\n\r\n\t\tauto residual = construct_residual(s, t);\r\n\t\tstd::queue<node_t>\
    \ q;\r\n\t\tauto add = [&](node_t t) {\r\n\t\t\tif(st.find(t) != st.end()) { return;\
    \ }\r\n\t\t\tq.emplace(t);\r\n\t\t\tst.emplace(t);\r\n\t\t};\r\n\t\tadd(s);\r\n\
    \t\tstd::deque<node_t> ans;\r\n\t\twhile(!q.empty()) {\r\n\t\t\tauto f = q.front();\r\
    \n\t\t\tq.pop();\r\n\t\t\tfor(const auto& t : m_to_list[f]) {\r\n\t\t\t\tif(residual.find({f,t})\
    \ == residual.end()) { continue; }\r\n\t\t\t\tadd(t);\r\n\t\t\t}\r\n\t\t}\r\n\r\
    \n\t\tstd::deque<std::pair<node_t, node_t>> cut;\r\n\t\tfor(const auto& f : st)\
    \ for(const auto& t : m_to_list[f]) {\r\n\t\t\tif(st.find(t) == st.end() &&\r\n\
    \t\t\t   m_graph.find({f,t}) != m_graph.end()) {\r\n\t\t\t\tcut.emplace_back(f,\
    \ t);\r\n\t\t\t}\r\n\t\t}\r\n\r\n\t\treturn cut;\r\n\t}\r\n\r\n\r\n\tauto get_edge(node_t\
    \ s, node_t t)const {\r\n\t\tauto residual = construct_residual(s, t);\r\n\r\n\
    \t\tGraph_f edge;\r\n\t\tfor(node_t from = 0; from < m_n; ++from) {\r\n\t\t\t\
    for(const auto& to : m_to_list[from]) {\r\n\t\t\t\tif(m_graph.find({from,to})\
    \ == m_graph.end()) { continue; }\r\n\t\t\t\tauto val = m_graph.at({from, to})\
    \ - residual[{from, to}];\r\n\t\t\t\tif(val > 0) { edge.emplace(from, std::pair<node_t,\
    \ cost_t>{to, val}); }\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn edge;\r\n\r\n\t}\r\n\
    };\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n#include <queue>\r\n#include <unordered_map>\r\
    \n#include <unordered_set>\r\n#include <map>\r\n\r\nclass FordFulkerson {\r\n\r\
    \n\tstruct HashPair {\r\n\t\ttemplate<class T1, class T2>\r\n\t\tsize_t operator()(const\
    \ std::pair<T1, T2>& p) const {\r\n\t\t\tauto hash1 = std::hash<T1>{}(p.first);\r\
    \n\t\t\tauto hash2 = std::hash<T2>{}(p.second);\r\n\t\t\tsize_t seed = 0;\r\n\t\
    \t\tseed ^= hash1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);\r\n\t\t\tseed ^= hash2\
    \ + 0x9e3779b9 + (seed << 6) + (seed >> 2);\r\n\t\t\treturn seed;\r\n\t\t}\r\n\
    \t};\r\n\r\n\tusing node_t = int;\r\n\tusing cost_t = long long;\r\n\tusing Graph_f\
    \ = std::unordered_multimap<node_t, std::pair<node_t, cost_t>>;\r\n\tusing Graph\
    \ = std::unordered_map<std::pair<node_t, node_t>, cost_t, HashPair>;\r\n\r\n\t\
    const node_t m_n;\r\n\tconst Graph m_graph;\r\n\tconst std::vector<std::unordered_set<node_t>>\
    \ m_to_list;\r\n\r\n\tstatic auto construct_to_list(node_t n, const Graph_f& graph_f)\
    \ {\r\n\t\tstd::vector<std::unordered_set<node_t>> to_list(n);\r\n\t\tfor (const\
    \ auto& [f, tc] : graph_f) {\r\n\t\t\tauto [t, c] = tc;\r\n\t\t\tto_list[f].emplace(t);\r\
    \n\t\t\tto_list[t].emplace(f);\r\n\t\t}\r\n\t\treturn to_list;\r\n\t}\r\n\tstatic\
    \ auto construct_graph(const Graph_f& graph_f) {\r\n\t\tGraph graph;\r\n\t\tfor\
    \ (const auto& [f, tc] : graph_f) {\r\n\t\t\tauto [t, c] = tc;\r\n\t\t\tgraph[std::pair<node_t,\
    \ node_t>{f, t}] += c;\r\n\t\t}\r\n\t\treturn graph;\r\n\t}\r\n\r\n\tauto get_route(node_t\
    \ s, node_t t, const Graph& graph) const {\r\n\t\tstd::unordered_set<node_t> visited;\r\
    \n\t\tauto f = [&](auto&& f, node_t now, std::list<node_t>& route)->bool {\r\n\
    \t\t\troute.emplace_back(now);\r\n\t\t\tfor (const auto& to : m_to_list[now])\
    \ {\r\n\t\t\t\tif (graph.find({ now, to }) == graph.end()) { continue; }\r\n\t\
    \t\t\tif (to == t) { route.emplace_back(t); return true; }\r\n\t\t\t\tif (visited.find(to)\
    \ == visited.end()) {\r\n\t\t\t\t\tvisited.emplace(to);\r\n\t\t\t\t\tif (f(f,\
    \ to, route)) { return true; }\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\troute.pop_back();\r\
    \n\t\t\treturn false;\r\n\t\t};\r\n\t\tstd::list<node_t> route;\r\n\t\tvisited.emplace(s);\r\
    \n\t\tauto ok = f(f, s, route);\r\n\t\tif (ok) { return route; } else { return\
    \ std::list<node_t>{}; }\r\n\t}\r\n\r\n\r\n\tauto construct_residual(node_t s,\
    \ node_t t)const {\r\n\t\tauto residual = m_graph;\r\n\t\twhile(true) {\r\n\t\t\
    \tauto route = get_route(s, t, residual);\r\n\t\t\tif(route.empty()) { break;\
    \ }\r\n\r\n\t\t\tcost_t mn = 1e9;\r\n\t\t\tnode_t from = s;\r\n\t\t\tfor(const\
    \ auto& to : route)if(from != to) {\r\n\t\t\t\tmn = std::min(mn, residual[{from,\
    \ to}]);\r\n\t\t\t\tfrom = to;\r\n\t\t\t}\r\n\r\n\t\t\tfrom = s;\r\n\t\t\tfor(const\
    \ auto& to : route)if(from != to) {\r\n\t\t\t\tauto& ft = residual[{from, to}];\r\
    \n\t\t\t\tauto use = ft - mn;\r\n\t\t\t\tft -= mn;\r\n\t\t\t\tif(ft == 0) { residual.erase({from,to});\
    \ }\r\n\t\t\t\tresidual[{to, from}] += mn;\r\n\t\t\t\tfrom = to;\r\n\t\t\t}\r\n\
    \t\t}\r\n\t\treturn residual;\r\n\t}\r\npublic:\r\n\tFordFulkerson(node_t n, const\
    \ Graph_f& graph) :\r\n\t\tm_n(n),\r\n\t\tm_graph(construct_graph(graph)),\r\n\
    \t\tm_to_list(construct_to_list(n, graph)) {\r\n\t}\r\n\r\n\tauto max_flow(node_t\
    \ s, node_t t)const {\r\n\t\tauto residual = construct_residual(s, t);\r\n\r\n\
    \t\tcost_t val = 0;\r\n\t\tfor (const auto& to : m_to_list[s]) {\r\n\t\t\tif (m_graph.find({\
    \ s,to }) == m_graph.end()) { continue; }\r\n\t\t\tval += m_graph.at({ s, to })\
    \ - residual[{s, to}];\r\n\t\t}\r\n\t\treturn val;\r\n\t}\r\n\r\n\r\n\tauto get_cut_list(node_t\
    \ s, node_t t) const {\r\n\t\t// \u6B8B\u4F59\u30B0\u30E9\u30D5\u3067\u59CB\u70B9\
    \u304B\u3089\u5230\u9054\u3067\u304D\u308B\u96C6\u5408\r\n\t\tstd::unordered_set<node_t>\
    \ st;\r\n\r\n\t\tauto residual = construct_residual(s, t);\r\n\t\tstd::queue<node_t>\
    \ q;\r\n\t\tauto add = [&](node_t t) {\r\n\t\t\tif(st.find(t) != st.end()) { return;\
    \ }\r\n\t\t\tq.emplace(t);\r\n\t\t\tst.emplace(t);\r\n\t\t};\r\n\t\tadd(s);\r\n\
    \t\tstd::deque<node_t> ans;\r\n\t\twhile(!q.empty()) {\r\n\t\t\tauto f = q.front();\r\
    \n\t\t\tq.pop();\r\n\t\t\tfor(const auto& t : m_to_list[f]) {\r\n\t\t\t\tif(residual.find({f,t})\
    \ == residual.end()) { continue; }\r\n\t\t\t\tadd(t);\r\n\t\t\t}\r\n\t\t}\r\n\r\
    \n\t\tstd::deque<std::pair<node_t, node_t>> cut;\r\n\t\tfor(const auto& f : st)\
    \ for(const auto& t : m_to_list[f]) {\r\n\t\t\tif(st.find(t) == st.end() &&\r\n\
    \t\t\t   m_graph.find({f,t}) != m_graph.end()) {\r\n\t\t\t\tcut.emplace_back(f,\
    \ t);\r\n\t\t\t}\r\n\t\t}\r\n\r\n\t\treturn cut;\r\n\t}\r\n\r\n\r\n\tauto get_edge(node_t\
    \ s, node_t t)const {\r\n\t\tauto residual = construct_residual(s, t);\r\n\r\n\
    \t\tGraph_f edge;\r\n\t\tfor(node_t from = 0; from < m_n; ++from) {\r\n\t\t\t\
    for(const auto& to : m_to_list[from]) {\r\n\t\t\t\tif(m_graph.find({from,to})\
    \ == m_graph.end()) { continue; }\r\n\t\t\t\tauto val = m_graph.at({from, to})\
    \ - residual[{from, to}];\r\n\t\t\t\tif(val > 0) { edge.emplace(from, std::pair<node_t,\
    \ cost_t>{to, val}); }\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn edge;\r\n\r\n\t}\r\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: Library/Graph/Flow/FordFulkerson.hpp
  requiredBy: []
  timestamp: '2022-08-30 04:52:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Graph/Flow/FordFulkerson.hpp
layout: document
redirect_from:
- /library/Library/Graph/Flow/FordFulkerson.hpp
- /library/Library/Graph/Flow/FordFulkerson.hpp.html
title: Library/Graph/Flow/FordFulkerson.hpp
---
