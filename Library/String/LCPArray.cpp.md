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
  bundledCode: "#line 1 \"Library/String/LCPArray.cpp\"\n/**\r\n * \u203B SuffixArray\u30AF\
    \u30E9\u30B9\u304C\u5FC5\u8981\r\n * LCPArray\u3092\u69CB\u7BC9\u3059\u308B\r\n\
    \ * O(N)\r\n * suffix array\u3067\u96A3\u63A5\u3059\u308Bstr\u306E\u6700\u9577\
    \u5171\u901A\u63A5\u982D\u8F9E(LCP:Longest Common Prefix)\u3092\u5F97\u308B\r\n\
    \ * ex) sa:[aab, ab, abaab, b, baab] -> LCPA:[1, 2, 0, 1]\r\n *\r\n * Kasai's\
    \ algorithm\u3067\u5B9F\u88C5\r\n */\r\nclass LCPArray {\r\n\r\n\tconst std::vector<int>\
    \ m_lcpArray;\r\n\r\n\tstatic std::vector<int> constructLcpArray(const std::string&\
    \ str) {\r\n\t\tauto sz = str.size();\r\n\t\tconst auto suffixArray = SuffixArray(str).getSuffixArray();\r\
    \n\r\n\t\tauto rank = std::vector<int>(sz);\r\n\t\tfor (int i = 0; i < sz; ++i)\
    \ { rank[suffixArray[i]] = i; }\r\n\r\n\t\tauto lcpArray = std::vector<int>(sz\
    \ - 1);\r\n\t\tfor (int i = 0, h = 0; i < sz; ++i) {\r\n\t\t\tif (rank[i] == 0)\
    \ { continue; }\r\n\t\t\tint j = suffixArray[rank[i] - 1];\r\n\t\t\tif (h > 0)\
    \ { --h; }\r\n\t\t\tfor (; j + h < sz && i + h < sz; ++h) {\r\n\t\t\t\tif (str[i\
    \ + h] != str[j + h]) { break; }\r\n\t\t\t}\r\n\t\t\tlcpArray[rank[i] - 1] = h;\r\
    \n\t\t}\r\n\t\treturn lcpArray;\r\n\t}\r\n\r\npublic:\r\n\tLCPArray(const std::string&\
    \ str) :m_lcpArray(constructLcpArray(str)) {}\r\n};\n"
  code: "/**\r\n * \u203B SuffixArray\u30AF\u30E9\u30B9\u304C\u5FC5\u8981\r\n * LCPArray\u3092\
    \u69CB\u7BC9\u3059\u308B\r\n * O(N)\r\n * suffix array\u3067\u96A3\u63A5\u3059\
    \u308Bstr\u306E\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E(LCP:Longest Common Prefix)\u3092\
    \u5F97\u308B\r\n * ex) sa:[aab, ab, abaab, b, baab] -> LCPA:[1, 2, 0, 1]\r\n *\r\
    \n * Kasai's algorithm\u3067\u5B9F\u88C5\r\n */\r\nclass LCPArray {\r\n\r\n\t\
    const std::vector<int> m_lcpArray;\r\n\r\n\tstatic std::vector<int> constructLcpArray(const\
    \ std::string& str) {\r\n\t\tauto sz = str.size();\r\n\t\tconst auto suffixArray\
    \ = SuffixArray(str).getSuffixArray();\r\n\r\n\t\tauto rank = std::vector<int>(sz);\r\
    \n\t\tfor (int i = 0; i < sz; ++i) { rank[suffixArray[i]] = i; }\r\n\r\n\t\tauto\
    \ lcpArray = std::vector<int>(sz - 1);\r\n\t\tfor (int i = 0, h = 0; i < sz; ++i)\
    \ {\r\n\t\t\tif (rank[i] == 0) { continue; }\r\n\t\t\tint j = suffixArray[rank[i]\
    \ - 1];\r\n\t\t\tif (h > 0) { --h; }\r\n\t\t\tfor (; j + h < sz && i + h < sz;\
    \ ++h) {\r\n\t\t\t\tif (str[i + h] != str[j + h]) { break; }\r\n\t\t\t}\r\n\t\t\
    \tlcpArray[rank[i] - 1] = h;\r\n\t\t}\r\n\t\treturn lcpArray;\r\n\t}\r\n\r\npublic:\r\
    \n\tLCPArray(const std::string& str) :m_lcpArray(constructLcpArray(str)) {}\r\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: Library/String/LCPArray.cpp
  requiredBy: []
  timestamp: '2022-08-30 04:52:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/String/LCPArray.cpp
layout: document
redirect_from:
- /library/Library/String/LCPArray.cpp
- /library/Library/String/LCPArray.cpp.html
title: Library/String/LCPArray.cpp
---
