---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Library/String/ZAlgorithm.hpp
    title: Library/String/ZAlgorithm.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B
  bundledCode: "#line 1 \"Test/String/ZAlgorithm.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B\"\
    \r\n\r\n#include <iostream>\r\n\r\n#line 2 \"Library/String/ZAlgorithm.hpp\"\n\
    \r\n#line 4 \"Library/String/ZAlgorithm.hpp\"\n#include <vector>\r\n#include <string>\r\
    \n#include <deque>\r\n\r\n/**\r\n * Z algorithm\u306B\u3088\u308AZ Array\u3092\
    \u69CB\u7BC9\u3059\u308B\r\n * O(N)\r\n * S[0..]\u3068S[i..]\u306E\u5171\u901A\
    \u63A5\u982D\u8F9E\u6570\r\n * ex) aaabaaaab -> [9, 2, 1, 0, 3, 4, 2, 1, 0]\r\n\
    \ */\r\nclass ZAlgorithm {\r\n    const std::vector<int> m_zArray;\r\n\r\n   \
    \ static auto constrcutZArray(const std::string& str) {\r\n        auto sz = str.size();\r\
    \n        auto zArray = std::vector<int>(sz);\r\n        zArray[0] = sz;\r\n\r\
    \n        int i = 1, j = 0;\r\n        while(i < sz) {\r\n            while(i\
    \ + j < sz && str[j] == str[i + j]) ++j;\r\n            zArray[i] = j;\r\n   \
    \         if(j == 0) { ++i; continue; }\r\n            int k = 1;\r\n        \
    \    while(i + k < sz && k + zArray[k] < j) {\r\n                zArray[i + k]\
    \ = zArray[k];\r\n                ++k;\r\n            }\r\n            i += k;\
    \ j -= k;\r\n        }\r\n        return zArray;\r\n    }\r\npublic:\r\n    ZAlgorithm(const\
    \ std::string& str) :m_zArray(constrcutZArray(str)) {}\r\n\r\n    /* i\u2208[l,r]\u3067\
    z[i]=size\u3068\u306A\u308Bindex\u3092\u8FD4\u3059 */\r\n    auto find(int l,\
    \ int r, int size) const {\r\n        std::deque<int> dq;\r\n        for(int i\
    \ = l; i <= r; ++i)if(m_zArray[i] == size) { dq.emplace_back(i); }\r\n       \
    \ return dq;\r\n    }\r\n\r\n    /* output for debug */\r\n    void debugOutput()\
    \ const {\r\n        std::cerr << \"-- z array --\" << std::endl;\r\n        for(const\
    \ auto& x : m_zArray) { std::cerr << x << \" \"; }\r\n        std::cerr << std::endl;\r\
    \n    }\r\n};\r\n#line 6 \"Test/String/ZAlgorithm.test.cpp\"\n\r\nusing ll = long\
    \ long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr char endl = '\\n';\r\
    \nstruct Preprocessing { Preprocessing() { std::cin.tie(0); std::ios::sync_with_stdio(0);\
    \ }; }_Preprocessing;\r\n\r\nsigned main() {\r\n    std::string p, t;\r\n    cin\
    \ >> p >> t;\r\n\r\n    std::string s = t + \"$\" + p;\r\n    auto za = ZAlgorithm(s);\r\
    \n\r\n    int tsz = t.size();\r\n    int ssz = s.size();\r\n    auto ans = za.find(tsz,\
    \ ssz - 1, tsz);\r\n\r\n    for(const auto& it : ans) {\r\n        cout << it\
    \ - tsz - 1 << endl;\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B\"\
    \r\n\r\n#include <iostream>\r\n\r\n#include \"./../../Library/String/ZAlgorithm.hpp\"\
    \r\n\r\nusing ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr\
    \ char endl = '\\n';\r\nstruct Preprocessing { Preprocessing() { std::cin.tie(0);\
    \ std::ios::sync_with_stdio(0); }; }_Preprocessing;\r\n\r\nsigned main() {\r\n\
    \    std::string p, t;\r\n    cin >> p >> t;\r\n\r\n    std::string s = t + \"\
    $\" + p;\r\n    auto za = ZAlgorithm(s);\r\n\r\n    int tsz = t.size();\r\n  \
    \  int ssz = s.size();\r\n    auto ans = za.find(tsz, ssz - 1, tsz);\r\n\r\n \
    \   for(const auto& it : ans) {\r\n        cout << it - tsz - 1 << endl;\r\n \
    \   }\r\n}"
  dependsOn:
  - Library/String/ZAlgorithm.hpp
  isVerificationFile: true
  path: Test/String/ZAlgorithm.test.cpp
  requiredBy: []
  timestamp: '2022-09-13 03:16:39+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/String/ZAlgorithm.test.cpp
layout: document
redirect_from:
- /verify/Test/String/ZAlgorithm.test.cpp
- /verify/Test/String/ZAlgorithm.test.cpp.html
title: Test/String/ZAlgorithm.test.cpp
---
