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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../Algorithms/binarySearch.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\r\n\r\n#include \"./SuffixArray.hpp\"\r\n\r\n/**\r\n * LCPArray\u3092\
    \u69CB\u7BC9\u3059\u308B\r\n * O(N)\r\n * suffix array\u3067\u96A3\u63A5\u3059\
    \u308Bstr\u306E\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E(LCP:Longest Common Prefix)\u3092\
    \u5F97\u308B\r\n * ex) sa:[aab, ab, abaab, b, baab] -> LCPA:[1, 2, 0, 1]\r\n *\r\
    \n * Kasai's algorithm\u3067\u5B9F\u88C5\r\n */\r\nclass LCPArray {\r\n\r\n  \
    \  const std::vector<int> m_lcpArray;\r\n    const std::vector<int> m_suffixArray;\r\
    \n\r\n    static std::vector<int> constructLcpArray(const std::string& str) {\r\
    \n        auto sz = str.size();\r\n        const auto suffixArray = SuffixArray(str).getSuffixArray();\r\
    \n\r\n        auto rank = std::vector<int>(sz);\r\n        for(int i = 0; i <\
    \ sz; ++i) { rank[suffixArray[i]] = i; }\r\n\r\n        auto lcpArray = std::vector<int>(sz\
    \ - 1);\r\n        for(int i = 0, h = 0; i < sz; ++i) {\r\n            if(rank[i]\
    \ == 0) { continue; }\r\n            int j = suffixArray[rank[i] - 1];\r\n   \
    \         if(h > 0) { --h; }\r\n            for(; j + h < sz && i + h < sz; ++h)\
    \ {\r\n                if(str[i + h] != str[j + h]) { break; }\r\n           \
    \ }\r\n            lcpArray[rank[i] - 1] = h;\r\n        }\r\n        return lcpArray;\r\
    \n    }\r\n\r\npublic:\r\n    LCPArray(const std::string& str) :\r\n        m_suffixArray(SuffixArray(str).getSuffixArray()),\r\
    \n        m_lcpArray(constructLcpArray(str)) {\r\n    }\r\n\r\n    auto getLCPArray()const\
    \ { return m_lcpArray; }\r\n    auto getSuffixArrayIndexList()const {\r\n    \
    \    std::vector<int> sail(m_suffixArray.size());\r\n        for(unsigned int\
    \ i = 0; i < m_suffixArray.size(); ++i) {\r\n            sail[m_suffixArray[i]]\
    \ = i;\r\n        }\r\n        return sail;\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: Library/String/LCPArray.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/String/LCPArray.hpp
layout: document
redirect_from:
- /library/Library/String/LCPArray.hpp
- /library/Library/String/LCPArray.hpp.html
title: Library/String/LCPArray.hpp
---
