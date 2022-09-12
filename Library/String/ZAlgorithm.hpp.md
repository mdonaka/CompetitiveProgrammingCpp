---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/String/ZAlgorithm.test.cpp
    title: Test/String/ZAlgorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/String/ZAlgorithm.hpp\"\n\r\n#include <iostream>\r\
    \n#include <vector>\r\n#include <string>\r\n#include <deque>\r\n\r\n/**\r\n *\
    \ Z algorithm\u306B\u3088\u308AZ Array\u3092\u69CB\u7BC9\u3059\u308B\r\n * O(N)\r\
    \n * S[0..]\u3068S[i..]\u306E\u5171\u901A\u63A5\u982D\u8F9E\u6570\r\n * ex) aaabaaaab\
    \ -> [9, 2, 1, 0, 3, 4, 2, 1, 0]\r\n */\r\nclass ZAlgorithm {\r\n    const std::vector<int>\
    \ m_zArray;\r\n\r\n    static auto constrcutZArray(const std::string& str) {\r\
    \n        auto sz = str.size();\r\n        auto zArray = std::vector<int>(sz);\r\
    \n        zArray[0] = sz;\r\n\r\n        int i = 1, j = 0;\r\n        while(i\
    \ < sz) {\r\n            while(i + j < sz && str[j] == str[i + j]) ++j;\r\n  \
    \          zArray[i] = j;\r\n            if(j == 0) { ++i; continue; }\r\n   \
    \         int k = 1;\r\n            while(i + k < sz && k + zArray[k] < j) {\r\
    \n                zArray[i + k] = zArray[k];\r\n                ++k;\r\n     \
    \       }\r\n            i += k; j -= k;\r\n        }\r\n        return zArray;\r\
    \n    }\r\npublic:\r\n    ZAlgorithm(const std::string& str) :m_zArray(constrcutZArray(str))\
    \ {}\r\n\r\n    /* i\u2208[l,r]\u3067z[i]=size\u3068\u306A\u308Bindex\u3092\u8FD4\
    \u3059 */\r\n    auto find(int l, int r, int size) const {\r\n        std::deque<int>\
    \ dq;\r\n        for(int i = l; i <= r; ++i)if(m_zArray[i] == size) { dq.emplace_back(i);\
    \ }\r\n        return dq;\r\n    }\r\n\r\n    /* output for debug */\r\n    void\
    \ debugOutput() const {\r\n        std::cerr << \"-- z array --\" << std::endl;\r\
    \n        for(const auto& x : m_zArray) { std::cerr << x << \" \"; }\r\n     \
    \   std::cerr << std::endl;\r\n    }\r\n};\r\n"
  code: "#pragma once\r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include\
    \ <string>\r\n#include <deque>\r\n\r\n/**\r\n * Z algorithm\u306B\u3088\u308A\
    Z Array\u3092\u69CB\u7BC9\u3059\u308B\r\n * O(N)\r\n * S[0..]\u3068S[i..]\u306E\
    \u5171\u901A\u63A5\u982D\u8F9E\u6570\r\n * ex) aaabaaaab -> [9, 2, 1, 0, 3, 4,\
    \ 2, 1, 0]\r\n */\r\nclass ZAlgorithm {\r\n    const std::vector<int> m_zArray;\r\
    \n\r\n    static auto constrcutZArray(const std::string& str) {\r\n        auto\
    \ sz = str.size();\r\n        auto zArray = std::vector<int>(sz);\r\n        zArray[0]\
    \ = sz;\r\n\r\n        int i = 1, j = 0;\r\n        while(i < sz) {\r\n      \
    \      while(i + j < sz && str[j] == str[i + j]) ++j;\r\n            zArray[i]\
    \ = j;\r\n            if(j == 0) { ++i; continue; }\r\n            int k = 1;\r\
    \n            while(i + k < sz && k + zArray[k] < j) {\r\n                zArray[i\
    \ + k] = zArray[k];\r\n                ++k;\r\n            }\r\n            i\
    \ += k; j -= k;\r\n        }\r\n        return zArray;\r\n    }\r\npublic:\r\n\
    \    ZAlgorithm(const std::string& str) :m_zArray(constrcutZArray(str)) {}\r\n\
    \r\n    /* i\u2208[l,r]\u3067z[i]=size\u3068\u306A\u308Bindex\u3092\u8FD4\u3059\
    \ */\r\n    auto find(int l, int r, int size) const {\r\n        std::deque<int>\
    \ dq;\r\n        for(int i = l; i <= r; ++i)if(m_zArray[i] == size) { dq.emplace_back(i);\
    \ }\r\n        return dq;\r\n    }\r\n\r\n    /* output for debug */\r\n    void\
    \ debugOutput() const {\r\n        std::cerr << \"-- z array --\" << std::endl;\r\
    \n        for(const auto& x : m_zArray) { std::cerr << x << \" \"; }\r\n     \
    \   std::cerr << std::endl;\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/String/ZAlgorithm.hpp
  requiredBy: []
  timestamp: '2022-09-13 03:16:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/String/ZAlgorithm.test.cpp
documentation_of: Library/String/ZAlgorithm.hpp
layout: document
redirect_from:
- /library/Library/String/ZAlgorithm.hpp
- /library/Library/String/ZAlgorithm.hpp.html
title: Library/String/ZAlgorithm.hpp
---
