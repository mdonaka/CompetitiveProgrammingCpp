---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Math/Matrix_pow.test.cpp
    title: Test/Math/Matrix_pow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Math/Matrix.hpp\"\n\r\n#include <cassert>\r\n#include\
    \ <iostream>\r\n#include <vector>\r\n\r\nnamespace mtd {\r\n  template <class\
    \ T>\r\n  class Matrix {\r\n    int h, w;\r\n    std::vector<std::vector<T>> mat;\r\
    \n\r\n  public:\r\n    Matrix(const std::vector<std::vector<T>>& mat)\r\n    \
    \    : h(mat.size()), w(mat[0].size()), mat(mat) {}\r\n\r\n    inline static auto\
    \ identity(int size) {\r\n      std::vector<std::vector<T>> ret(size, std::vector<T>(size));\r\
    \n      for (int i = 0; i < size; ++i) { ret[i][i] = 1; }\r\n      return Matrix(ret);\r\
    \n    }\r\n\r\n    auto begin() const { return mat.begin(); }\r\n    auto end()\
    \ const { return mat.end(); }\r\n\r\n    const auto& operator[](int i) const {\
    \ return mat[i]; }\r\n    auto& operator[](int i) { return mat[i]; }\r\n\r\n \
    \   auto operator*(const Matrix& tgt) const {\r\n      assert(w == tgt.h);\r\n\
    \      std::vector<std::vector<T>> ret(h, std::vector<T>(tgt.w));\r\n      for\
    \ (int i = 0; i < h; ++i)\r\n        for (int j = 0; j < tgt.w; ++j) {\r\n   \
    \       for (int k = 0; k < w; ++k) { ret[i][j] += mat[i][k] * tgt[k][j]; }\r\n\
    \        }\r\n      return Matrix(ret);\r\n    }\r\n\r\n    auto pow(long long\
    \ n) const {\r\n      assert(h == w);\r\n      auto ret = identity(h);\r\n   \
    \   auto now = *this;\r\n      while (n) {\r\n        if (n & 1) { ret = ret *\
    \ now; }\r\n        n >>= 1;\r\n        now = now * now;\r\n      }\r\n      return\
    \ ret;\r\n    }\r\n  };\r\n}  // namespace mtd\r\n"
  code: "#pragma once\r\n\r\n#include <cassert>\r\n#include <iostream>\r\n#include\
    \ <vector>\r\n\r\nnamespace mtd {\r\n  template <class T>\r\n  class Matrix {\r\
    \n    int h, w;\r\n    std::vector<std::vector<T>> mat;\r\n\r\n  public:\r\n \
    \   Matrix(const std::vector<std::vector<T>>& mat)\r\n        : h(mat.size()),\
    \ w(mat[0].size()), mat(mat) {}\r\n\r\n    inline static auto identity(int size)\
    \ {\r\n      std::vector<std::vector<T>> ret(size, std::vector<T>(size));\r\n\
    \      for (int i = 0; i < size; ++i) { ret[i][i] = 1; }\r\n      return Matrix(ret);\r\
    \n    }\r\n\r\n    auto begin() const { return mat.begin(); }\r\n    auto end()\
    \ const { return mat.end(); }\r\n\r\n    const auto& operator[](int i) const {\
    \ return mat[i]; }\r\n    auto& operator[](int i) { return mat[i]; }\r\n\r\n \
    \   auto operator*(const Matrix& tgt) const {\r\n      assert(w == tgt.h);\r\n\
    \      std::vector<std::vector<T>> ret(h, std::vector<T>(tgt.w));\r\n      for\
    \ (int i = 0; i < h; ++i)\r\n        for (int j = 0; j < tgt.w; ++j) {\r\n   \
    \       for (int k = 0; k < w; ++k) { ret[i][j] += mat[i][k] * tgt[k][j]; }\r\n\
    \        }\r\n      return Matrix(ret);\r\n    }\r\n\r\n    auto pow(long long\
    \ n) const {\r\n      assert(h == w);\r\n      auto ret = identity(h);\r\n   \
    \   auto now = *this;\r\n      while (n) {\r\n        if (n & 1) { ret = ret *\
    \ now; }\r\n        n >>= 1;\r\n        now = now * now;\r\n      }\r\n      return\
    \ ret;\r\n    }\r\n  };\r\n}  // namespace mtd\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Math/Matrix.hpp
  requiredBy: []
  timestamp: '2024-11-26 15:19:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Math/Matrix_pow.test.cpp
documentation_of: Library/Math/Matrix.hpp
layout: document
redirect_from:
- /library/Library/Math/Matrix.hpp
- /library/Library/Math/Matrix.hpp.html
title: Library/Math/Matrix.hpp
---
