---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/String/ZAlgorithm.hpp
    title: Library/String/ZAlgorithm.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B
  bundledCode: "#line 1 \"Test/String/ZAlgorithm.test.cpp\"\n#define PROBLEM \\\r\n\
    \  \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B\"\r\
    \n\r\n#line 2 \"Library/String/ZAlgorithm.hpp\"\n\r\n#include <deque>\r\n#include\
    \ <iostream>\r\n#include <string>\r\n#include <vector>\r\n\r\nnamespace mtd {\r\
    \n  /**\r\n   * Z algorithm\u306B\u3088\u308AZ Array\u3092\u69CB\u7BC9\u3059\u308B\
    \r\n   * O(N)\r\n   * S[0..]\u3068S[i..]\u306E\u5171\u901A\u63A5\u982D\u8F9E\u6570\
    \r\n   * ex) aaabaaaab -> [9, 2, 1, 0, 3, 4, 2, 1, 0]\r\n   */\r\n  class ZAlgorithm\
    \ {\r\n    const std::vector<int> m_zArray;\r\n\r\n    static auto constrcutZArray(const\
    \ std::string& str) {\r\n      auto sz = str.size();\r\n      auto zArray = std::vector<int>(sz);\r\
    \n      zArray[0] = sz;\r\n\r\n      int i = 1, j = 0;\r\n      while (i < sz)\
    \ {\r\n        while (i + j < sz && str[j] == str[i + j]) ++j;\r\n        zArray[i]\
    \ = j;\r\n        if (j == 0) {\r\n          ++i;\r\n          continue;\r\n \
    \       }\r\n        int k = 1;\r\n        while (i + k < sz && k + zArray[k]\
    \ < j) {\r\n          zArray[i + k] = zArray[k];\r\n          ++k;\r\n       \
    \ }\r\n        i += k;\r\n        j -= k;\r\n      }\r\n      return zArray;\r\
    \n    }\r\n\r\n  public:\r\n    ZAlgorithm(const std::string& str) : m_zArray(constrcutZArray(str))\
    \ {}\r\n\r\n    /* i\u2208[l,r]\u3067z[i]=size\u3068\u306A\u308Bindex\u3092\u8FD4\
    \u3059 */\r\n    auto find(int l, int r, int size) const {\r\n      std::deque<int>\
    \ dq;\r\n      for (int i = l; i <= r; ++i)\r\n        if (m_zArray[i] == size)\
    \ { dq.emplace_back(i); }\r\n      return dq;\r\n    }\r\n\r\n    /* output for\
    \ debug */\r\n    void debugOutput() const {\r\n      std::cerr << \"-- z array\
    \ --\" << std::endl;\r\n      for (const auto& x : m_zArray) { std::cerr << x\
    \ << \" \"; }\r\n      std::cerr << std::endl;\r\n    }\r\n\r\n    auto get()\
    \ const { return m_zArray; }\r\n  };\r\n}  // namespace mtd\r\n#line 5 \"Test/String/ZAlgorithm.test.cpp\"\
    \n\r\n#line 7 \"Test/String/ZAlgorithm.test.cpp\"\n\r\nusing ll = long long;\r\
    \nusing std::cin;\r\nusing std::cout;\r\nconstexpr char endl = '\\n';\r\nstruct\
    \ Preprocessing {\r\n  Preprocessing() {\r\n    std::cin.tie(0);\r\n    std::ios::sync_with_stdio(0);\r\
    \n  };\r\n} _Preprocessing;\r\n\r\nsigned main() {\r\n  std::string p, t;\r\n\
    \  cin >> p >> t;\r\n\r\n  std::string s = t + \"$\" + p;\r\n  auto za = mtd::ZAlgorithm(s);\r\
    \n\r\n  int tsz = t.size();\r\n  int ssz = s.size();\r\n  auto ans = za.find(tsz,\
    \ ssz - 1, tsz);\r\n\r\n  for (const auto& it : ans) { cout << it - tsz - 1 <<\
    \ endl; }\r\n}\r\n"
  code: "#define PROBLEM \\\r\n  \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B\"\
    \r\n\r\n#include \"./../../Library/String/ZAlgorithm.hpp\"\r\n\r\n#include <iostream>\r\
    \n\r\nusing ll = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr\
    \ char endl = '\\n';\r\nstruct Preprocessing {\r\n  Preprocessing() {\r\n    std::cin.tie(0);\r\
    \n    std::ios::sync_with_stdio(0);\r\n  };\r\n} _Preprocessing;\r\n\r\nsigned\
    \ main() {\r\n  std::string p, t;\r\n  cin >> p >> t;\r\n\r\n  std::string s =\
    \ t + \"$\" + p;\r\n  auto za = mtd::ZAlgorithm(s);\r\n\r\n  int tsz = t.size();\r\
    \n  int ssz = s.size();\r\n  auto ans = za.find(tsz, ssz - 1, tsz);\r\n\r\n  for\
    \ (const auto& it : ans) { cout << it - tsz - 1 << endl; }\r\n}\r\n"
  dependsOn:
  - Library/String/ZAlgorithm.hpp
  isVerificationFile: true
  path: Test/String/ZAlgorithm.test.cpp
  requiredBy: []
  timestamp: '2024-11-12 00:26:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/String/ZAlgorithm.test.cpp
layout: document
redirect_from:
- /verify/Test/String/ZAlgorithm.test.cpp
- /verify/Test/String/ZAlgorithm.test.cpp.html
title: Test/String/ZAlgorithm.test.cpp
---
