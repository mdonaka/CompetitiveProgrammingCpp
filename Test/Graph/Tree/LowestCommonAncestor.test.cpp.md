---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../Library/Graph/Tree/LCA.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C\"\
    \r\n\r\n#include <iostream>\r\n#include \"./../../../Library/Graph/Tree/LCA.hpp\"\
    \r\n\r\nusing ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr\
    \ char endl = '\\n';\r\n\r\nsigned main() {\r\n    ll n;\r\n    cin >> n;\r\n\
    \    std::unordered_multimap<int, int> tree;\r\n    for(int f = 0; f < n; ++f)\
    \ {\r\n        ll k;\r\n        cin >> k;\r\n        for(int _ = 0; _ < k; ++_)\
    \ {\r\n            int t;\r\n            cin >> t;\r\n            tree.emplace(f,\
    \ t);\r\n            tree.emplace(t, f);\r\n        }\r\n    }\r\n\r\n    auto\
    \ lca = LowestCommonAncestor(n, tree, 0);\r\n\r\n    int q;\r\n    cin >> q;\r\
    \n    for(int _ = 0; _ < q; ++_) {\r\n        int u, v;\r\n        cin >> u >>\
    \ v;\r\n        cout << lca.lca(u, v) << endl;\r\n    }\r\n}"
  dependsOn: []
  isVerificationFile: true
  path: Test/Graph/Tree/LowestCommonAncestor.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/Graph/Tree/LowestCommonAncestor.test.cpp
layout: document
redirect_from:
- /verify/Test/Graph/Tree/LowestCommonAncestor.test.cpp
- /verify/Test/Graph/Tree/LowestCommonAncestor.test.cpp.html
title: Test/Graph/Tree/LowestCommonAncestor.test.cpp
---
