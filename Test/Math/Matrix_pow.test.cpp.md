---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Math/Math.hpp
    title: Library/Math/Math.hpp
  - icon: ':x:'
    path: Library/Math/Matrix.hpp
    title: Library/Math/Matrix.hpp
  - icon: ':question:'
    path: Library/Math/ModInt.hpp
    title: Library/Math/ModInt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1136
    links:
    - https://yukicoder.me/problems/no/1136
  bundledCode: "#line 1 \"Test/Math/Matrix_pow.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/1136\"\
    \r\n\r\n#include <iostream>\r\n\r\n// begin:tag includes\r\n#line 2 \"Library/Math/Matrix.hpp\"\
    \n\r\n#include <cassert>\r\n#line 5 \"Library/Math/Matrix.hpp\"\n#include <vector>\r\
    \n\r\nnamespace mtd {\r\n  template <class T>\r\n  class Matrix {\r\n    int h,\
    \ w;\r\n    std::vector<std::vector<T>> mat;\r\n\r\n  public:\r\n    Matrix(const\
    \ std::vector<std::vector<T>>& _mat)\r\n        : h(_mat.size()), w(_mat[0].size()),\
    \ mat(_mat) {}\r\n\r\n    inline static auto identity(int size) {\r\n      std::vector<std::vector<T>>\
    \ ret(size, std::vector<T>(size));\r\n      for (int i = 0; i < size; ++i) { ret[i][i]\
    \ = 1; }\r\n      return Matrix(ret);\r\n    }\r\n\r\n    auto begin() const {\
    \ return mat.begin(); }\r\n    auto end() const { return mat.end(); }\r\n\r\n\
    \    const auto& operator[](int i) const { return mat[i]; }\r\n    auto& operator[](int\
    \ i) { return mat[i]; }\r\n\r\n    auto operator*(const Matrix& tgt) const {\r\
    \n      assert(w == tgt.h);\r\n      std::vector<std::vector<T>> ret(h, std::vector<T>(tgt.w));\r\
    \n      for (int i = 0; i < h; ++i)\r\n        for (int j = 0; j < tgt.w; ++j)\
    \ {\r\n          for (int k = 0; k < w; ++k) { ret[i][j] += mat[i][k] * tgt[k][j];\
    \ }\r\n        }\r\n      return Matrix(ret);\r\n    }\r\n\r\n    auto pow(long\
    \ long n) const {\r\n      assert(h == w);\r\n      auto ret = identity(h);\r\n\
    \      auto now = *this;\r\n      while (n) {\r\n        if (n & 1) { ret = ret\
    \ * now; }\r\n        n >>= 1;\r\n        now = now * now;\r\n      }\r\n    \
    \  return ret;\r\n    }\r\n  };\r\n}  // namespace mtd\r\n#line 2 \"Library/Math/ModInt.hpp\"\
    \n\n#line 4 \"Library/Math/ModInt.hpp\"\n#include <iterator>\n\n#line 2 \"Library/Math/Math.hpp\"\
    \n\r\n#line 4 \"Library/Math/Math.hpp\"\n\r\nnamespace mtd {\r\n  template <class\
    \ T>\r\n  class Math {\r\n    const std::vector<T> m_fac;\r\n    const std::vector<T>\
    \ m_finv;\r\n\r\n    auto constructFac(int s) {\r\n      std::vector<T> fac(s);\r\
    \n      fac[0] = fac[1] = 1;\r\n      for (long long i = 2; i < s; ++i) { fac[i]\
    \ = fac[i - 1] * i; }\r\n      return fac;\r\n    }\r\n    auto constructInv(int\
    \ s) {\r\n      std::vector<T> finv(s);\r\n      finv[s - 1] = 1 / m_fac[s - 1];\r\
    \n      for (long long i = s - 2; i >= 0; --i) {\r\n        finv[i] = finv[i +\
    \ 1] * (i + 1);\r\n      }\r\n      return finv;\r\n    }\r\n\r\n  public:\r\n\
    \    constexpr Math(long long size = 3 * 1e6)\r\n        : m_fac(constructFac(size)),\
    \ m_finv(constructInv(size)) {}\r\n\r\n    static constexpr T pow(T a, long long\
    \ b) {\r\n      T ans = 1;\r\n      while (b > 0) {\r\n        if (b & 1) { ans\
    \ *= a; }\r\n        b >>= 1;\r\n        a *= a;\r\n      }\r\n      return ans;\r\
    \n    }\r\n    constexpr auto fact(int n) const { return (n < 0) ? 0 : m_fac[n];\
    \ }\r\n    constexpr auto factInv(int n) const { return (n < 0 ? 0 : m_finv[n]);\
    \ }\r\n    constexpr auto comb(int n, int r) const {\r\n      return fact(n) *\
    \ factInv(r) * factInv(n - r);\r\n    }\r\n    constexpr auto perm(int n, int\
    \ r) const { return fact(n) * factInv(n - r); }\r\n  };\r\n}  // namespace mtd\r\
    \n#line 7 \"Library/Math/ModInt.hpp\"\n\nnamespace mtd {\n\n  template <int MOD,\
    \ class T = long long>\n  class ModInt {\n  public:\n    T x;\n\n    constexpr\
    \ ModInt(T _x) : x(_x >= 0 ? _x % MOD : MOD + (_x % MOD)) {}\n    constexpr ModInt()\
    \ : ModInt(0) {}\n\n    // \u56DB\u5247\u6F14\u7B97\n    constexpr auto& operator+=(const\
    \ ModInt<MOD, T>& m) {\n      x += m.x;\n      if (x >= MOD) { x -= MOD; }\n \
    \     return *this;\n    }\n    constexpr auto& operator-=(const ModInt<MOD, T>&\
    \ m) {\n      x -= m.x;\n      if (x < 0) { x += MOD; }\n      return *this;\n\
    \    }\n    constexpr auto& operator*=(const ModInt<MOD, T>& m) {\n      x *=\
    \ m.x;\n      if (x >= MOD) { x %= MOD; }\n      return *this;\n    }\n    constexpr\
    \ auto& operator/=(const ModInt<MOD, T>& m) {\n      x *= mtd::Math<ModInt<MOD,\
    \ T>>::pow(m.x, MOD - 2).x;\n      if (x >= MOD) { x %= MOD; }\n      return *this;\n\
    \    }\n\n    constexpr auto operator+(const ModInt<MOD, T>& m) const {\n    \
    \  auto t = *this;\n      t += m;\n      return t;\n    }\n    constexpr auto\
    \ operator-(const ModInt<MOD, T>& m) const {\n      auto t = *this;\n      t -=\
    \ m;\n      return t;\n    }\n    constexpr auto operator*(const ModInt<MOD, T>&\
    \ m) const {\n      auto t = *this;\n      t *= m;\n      return t;\n    }\n \
    \   constexpr auto operator/(const ModInt<MOD, T>& m) const {\n      auto t =\
    \ *this;\n      t /= m;\n      return t;\n    }\n\n    constexpr auto& operator+=(const\
    \ T& t) {\n      return *this += ModInt<MOD, T>(t);\n    }\n    constexpr auto&\
    \ operator-=(const T& t) {\n      return *this -= ModInt<MOD, T>(t);\n    }\n\
    \    constexpr auto& operator*=(const T& n) {\n      return *this *= ModInt<MOD,\
    \ T>(n);\n    }\n    constexpr auto& operator/=(const T& n) {\n      return *this\
    \ /= ModInt<MOD, T>(n);\n    }\n    constexpr auto operator+(const T& t) const\
    \ {\n      return *this + ModInt<MOD, T>(t);\n    }\n    constexpr auto operator-(const\
    \ T& t) const {\n      return *this - ModInt<MOD, T>(t);\n    }\n    constexpr\
    \ auto operator*(const T& t) const {\n      return *this * ModInt<MOD, T>(t);\n\
    \    }\n    constexpr auto operator/(const T& t) const {\n      return *this /\
    \ ModInt<MOD, T>(t);\n    }\n    constexpr friend auto operator+(const T& t, const\
    \ ModInt<MOD, T>& m) {\n      return m + t;\n    }\n    constexpr friend auto\
    \ operator-(const T& t, const ModInt<MOD, T>& m) {\n      return -m + t;\n   \
    \ }\n    constexpr friend auto operator*(const T& t, const ModInt<MOD, T>& m)\
    \ {\n      return m * t;\n    }\n    constexpr friend auto operator/(const T&\
    \ t, const ModInt<MOD, T>& m) {\n      return ModInt<MOD, T>(1) / m * t;\n   \
    \ }\n\n    // \u5358\u9805\u6F14\u7B97\n    constexpr auto operator-() const {\
    \ return ModInt<MOD, T>(0 - x); }\n\n    // \u6BD4\u8F03\u6F14\u7B97\n    constexpr\
    \ auto operator!=(const ModInt<MOD, T>& m) const {\n      return x != m.x;\n \
    \   }\n    constexpr auto operator==(const ModInt<MOD, T>& m) const {\n      return\
    \ !(x != m.x);\n    }\n\n    // \u5165\u51FA\u529B\n    constexpr friend std::ostream&\
    \ operator<<(std::ostream& os,\n                                             \
    \ const ModInt<MOD, T>& m) {\n      return os << m.x;\n    }\n    constexpr friend\
    \ std::istream& operator>>(std::istream& is,\n                               \
    \               ModInt<MOD, T>& m) {\n      return is >> m.x;\n    }\n\n    constexpr\
    \ auto val() const { return x; }\n  };\n\n}  // namespace mtd\n#line 8 \"Test/Math/Matrix_pow.test.cpp\"\
    \n// end:tag includes\r\n\r\nsigned main() {\r\n  std::cin.tie(0);\r\n  std::ios::sync_with_stdio(0);\r\
    \n  constexpr long long MOD = 1e9 + 7;\r\n  using mint = mtd::ModInt<MOD>;\r\n\
    \r\n  long long n;\r\n  std::cin >> n;\r\n\r\n  mtd::Matrix<mint> mat({{-1, 1},\
    \ {0, 3}});\r\n  auto mat_p = mat.pow(n);\r\n  mint ans = mat_p[0][0] + mat_p[0][1];\r\
    \n  std::cout << ans << std::endl;\r\n}\r\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1136\"\r\n\r\n#include\
    \ <iostream>\r\n\r\n// begin:tag includes\r\n#include \"../../Library/Math/Matrix.hpp\"\
    \r\n#include \"../../Library/Math/ModInt.hpp\"\r\n// end:tag includes\r\n\r\n\
    signed main() {\r\n  std::cin.tie(0);\r\n  std::ios::sync_with_stdio(0);\r\n \
    \ constexpr long long MOD = 1e9 + 7;\r\n  using mint = mtd::ModInt<MOD>;\r\n\r\
    \n  long long n;\r\n  std::cin >> n;\r\n\r\n  mtd::Matrix<mint> mat({{-1, 1},\
    \ {0, 3}});\r\n  auto mat_p = mat.pow(n);\r\n  mint ans = mat_p[0][0] + mat_p[0][1];\r\
    \n  std::cout << ans << std::endl;\r\n}\r\n"
  dependsOn:
  - Library/Math/Matrix.hpp
  - Library/Math/ModInt.hpp
  - Library/Math/Math.hpp
  isVerificationFile: true
  path: Test/Math/Matrix_pow.test.cpp
  requiredBy: []
  timestamp: '2024-12-27 17:07:26+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/Math/Matrix_pow.test.cpp
layout: document
redirect_from:
- /verify/Test/Math/Matrix_pow.test.cpp
- /verify/Test/Math/Matrix_pow.test.cpp.html
title: Test/Math/Matrix_pow.test.cpp
---
