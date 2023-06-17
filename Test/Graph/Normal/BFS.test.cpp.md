---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../Library/Algorithms/binarySearch.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/67\"\r\n#define ERROR\
    \ \"1e-9\"\r\n\r\n#include <iostream>\r\n#include <vector>\r\n\r\n#include \"\
    ./../../../Library/Graph/Graph.hpp\"\r\n#include \"./../../../Library/Graph/Normal/BFS.hpp\"\
    \r\n#include \"./../../../Library/Algorithms/binarySearch.hpp\"\r\n\r\nusing ll\
    \ = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr char endl =\
    \ '\\n';\r\n\r\nsigned main() {\r\n    ll n, m;\r\n    cin >> n >> m;\r\n    auto\
    \ graph_all = Graph(n);\r\n    for(int i = 0; i < m; ++i) {\r\n        ll s, t,\
    \ d;\r\n        cin >> s >> t >> d;\r\n        graph_all.addEdgeUndirected(s -\
    \ 1, t - 1, d);\r\n    }\r\n\r\n    auto solve = [&](ll w) {\r\n        auto graph\
    \ = Graph(n);\r\n        for(const auto& [s, td] : graph_all.getEdgesAll()) {\r\
    \n            auto [t, d] = td;\r\n            if(w <= d) { graph.addEdge(s, t);\
    \ }\r\n        }\r\n\r\n        std::vector<int> dv(n);\r\n        bfs(graph,\
    \ 0, [&](ll f, ll t) {dv[t] = dv[f] + 1; });\r\n        return dv[n - 1];\r\n\
    \    };\r\n\r\n    auto w_max = binarySearch(0, 1e9, [&](ll w) {\r\n        auto\
    \ d = solve(w);\r\n        return d > 0;\r\n    }, true);\r\n\r\n    auto ans\
    \ = solve(w_max);\r\n    cout << w_max << \" \" << ans << endl;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: Test/Graph/Normal/BFS.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/Graph/Normal/BFS.test.cpp
layout: document
redirect_from:
- /verify/Test/Graph/Normal/BFS.test.cpp
- /verify/Test/Graph/Normal/BFS.test.cpp.html
title: Test/Graph/Normal/BFS.test.cpp
---
