---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Library/String/ZAlgorithm.cpp\"\n/**\r\n * Z algorithm\u306B\
    \u3088\u308AZ Array\u3092\u69CB\u7BC9\u3059\u308B\r\n * O(N)\r\n * S[0..]\u3068\
    S[i..]\u306E\u5171\u901A\u63A5\u982D\u8F9E\u6570\r\n * ex) aaabaaaab -> [9, 2,\
    \ 1, 0, 3, 4, 2, 1, 0]\r\n */\r\nclass ZAlgorithm {\r\n\tconst std::vector<int>\
    \ m_zArray;\r\n\r\n\tstatic auto constrcutZArray(const std::string& str) {\r\n\
    \t\tauto sz = str.size();\r\n\t\tauto zArray = std::vector<int>(sz);\r\n\t\tzArray[0]\
    \ = sz;\r\n\r\n\t\tint i = 1, j = 0;\r\n\t\twhile (i < sz) {\r\n\t\t\twhile (i\
    \ + j < sz && str[j] == str[i + j]) ++j;\r\n\t\t\tzArray[i] = j;\r\n\t\t\tif (j\
    \ == 0) { ++i; continue; }\r\n\t\t\tint k = 1;\r\n\t\t\twhile (i + k < sz && k\
    \ + zArray[k] < j) {\r\n\t\t\t\tzArray[i + k] = zArray[k];\r\n\t\t\t\t++k;\r\n\
    \t\t\t}\r\n\t\t\ti += k; j -= k;\r\n\t\t}\r\n\t\treturn zArray;\r\n\t}\r\npublic:\r\
    \n\tZAlgorithm(const std::string& str) :m_zArray(constrcutZArray(str)) {}\r\n\r\
    \n\tauto getZArray() const {\r\n\t\treturn m_zArray;\r\n\t}\r\n\r\n\t/* output\
    \ fot debug */\r\n\tvoid debugOutput() const {\r\n\t\tdump(m_zArray);\r\n\t}\r\
    \n\r\n};\n"
  code: "/**\r\n * Z algorithm\u306B\u3088\u308AZ Array\u3092\u69CB\u7BC9\u3059\u308B\
    \r\n * O(N)\r\n * S[0..]\u3068S[i..]\u306E\u5171\u901A\u63A5\u982D\u8F9E\u6570\
    \r\n * ex) aaabaaaab -> [9, 2, 1, 0, 3, 4, 2, 1, 0]\r\n */\r\nclass ZAlgorithm\
    \ {\r\n\tconst std::vector<int> m_zArray;\r\n\r\n\tstatic auto constrcutZArray(const\
    \ std::string& str) {\r\n\t\tauto sz = str.size();\r\n\t\tauto zArray = std::vector<int>(sz);\r\
    \n\t\tzArray[0] = sz;\r\n\r\n\t\tint i = 1, j = 0;\r\n\t\twhile (i < sz) {\r\n\
    \t\t\twhile (i + j < sz && str[j] == str[i + j]) ++j;\r\n\t\t\tzArray[i] = j;\r\
    \n\t\t\tif (j == 0) { ++i; continue; }\r\n\t\t\tint k = 1;\r\n\t\t\twhile (i +\
    \ k < sz && k + zArray[k] < j) {\r\n\t\t\t\tzArray[i + k] = zArray[k];\r\n\t\t\
    \t\t++k;\r\n\t\t\t}\r\n\t\t\ti += k; j -= k;\r\n\t\t}\r\n\t\treturn zArray;\r\n\
    \t}\r\npublic:\r\n\tZAlgorithm(const std::string& str) :m_zArray(constrcutZArray(str))\
    \ {}\r\n\r\n\tauto getZArray() const {\r\n\t\treturn m_zArray;\r\n\t}\r\n\r\n\t\
    /* output fot debug */\r\n\tvoid debugOutput() const {\r\n\t\tdump(m_zArray);\r\
    \n\t}\r\n\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: Library/String/ZAlgorithm.cpp
  requiredBy: []
  timestamp: '2022-08-30 04:52:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/String/ZAlgorithm.cpp
layout: document
redirect_from:
- /library/Library/String/ZAlgorithm.cpp
- /library/Library/String/ZAlgorithm.cpp.html
title: Library/String/ZAlgorithm.cpp
---
