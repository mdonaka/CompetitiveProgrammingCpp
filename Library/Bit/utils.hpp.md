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
  bundledCode: "#line 2 \"Library/Bit/utils.hpp\"\n#include <deque>\r\n\r\nunsigned\
    \ ctz(unsigned int n) {\r\n    #ifdef __GNUC__\r\n    return __builtin_ctz(bit);\r\
    \n    #endif\r\n    if(!n) return -1;\r\n    unsigned int c = 32;\r\n    n &=\
    \ -static_cast<signed int>(n);\r\n    if(n) c--;\r\n    if(n & 0x0000FFFF) c -=\
    \ 16;\r\n    if(n & 0x00FF00FF) c -= 8;\r\n    if(n & 0x0F0F0F0F) c -= 4;\r\n\
    \    if(n & 0x33333333) c -= 2;\r\n    if(n & 0x55555555) c -= 1;\r\n    return\
    \ c;\r\n}\r\n\r\nauto all_index(unsigned int bit) {\r\n    std::deque<int> dq;\r\
    \n    while(bit) {\r\n        auto i = ctz(bit);\r\n        bit ^= (1LL << i);\r\
    \n        dq.emplace_back(i);\r\n    }\r\n    return dq;\r\n}\r\n\r\nauto count(unsigned\
    \ int bit) {\r\n    bit = (bit & 0x55555555) + (bit >> 1 & 0x55555555);\r\n  \
    \  bit = (bit & 0x33333333) + (bit >> 2 & 0x33333333);\r\n    bit = (bit & 0x0f0f0f0f)\
    \ + (bit >> 4 & 0x0f0f0f0f);\r\n    bit = (bit & 0x00ff00ff) + (bit >> 8 & 0x00ff00ff);\r\
    \n    return (bit & 0x0000ffff) + (bit >> 16 & 0x0000ffff);\r\n}\n"
  code: "#pragma once\r\n#include <deque>\r\n\r\nunsigned ctz(unsigned int n) {\r\n\
    \    #ifdef __GNUC__\r\n    return __builtin_ctz(bit);\r\n    #endif\r\n    if(!n)\
    \ return -1;\r\n    unsigned int c = 32;\r\n    n &= -static_cast<signed int>(n);\r\
    \n    if(n) c--;\r\n    if(n & 0x0000FFFF) c -= 16;\r\n    if(n & 0x00FF00FF)\
    \ c -= 8;\r\n    if(n & 0x0F0F0F0F) c -= 4;\r\n    if(n & 0x33333333) c -= 2;\r\
    \n    if(n & 0x55555555) c -= 1;\r\n    return c;\r\n}\r\n\r\nauto all_index(unsigned\
    \ int bit) {\r\n    std::deque<int> dq;\r\n    while(bit) {\r\n        auto i\
    \ = ctz(bit);\r\n        bit ^= (1LL << i);\r\n        dq.emplace_back(i);\r\n\
    \    }\r\n    return dq;\r\n}\r\n\r\nauto count(unsigned int bit) {\r\n    bit\
    \ = (bit & 0x55555555) + (bit >> 1 & 0x55555555);\r\n    bit = (bit & 0x33333333)\
    \ + (bit >> 2 & 0x33333333);\r\n    bit = (bit & 0x0f0f0f0f) + (bit >> 4 & 0x0f0f0f0f);\r\
    \n    bit = (bit & 0x00ff00ff) + (bit >> 8 & 0x00ff00ff);\r\n    return (bit &\
    \ 0x0000ffff) + (bit >> 16 & 0x0000ffff);\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: Library/Bit/utils.hpp
  requiredBy: []
  timestamp: '2023-03-14 03:59:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Bit/utils.hpp
layout: document
redirect_from:
- /library/Library/Bit/utils.hpp
- /library/Library/Bit/utils.hpp.html
title: Library/Bit/utils.hpp
---
