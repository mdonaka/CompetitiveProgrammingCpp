---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/DisjointSetUnion.hpp
    title: Library/DataStructure/DisjointSetUnion.hpp
  - icon: ':question:'
    path: Library/Math/Math.hpp
    title: Library/Math/Math.hpp
  - icon: ':question:'
    path: Library/Math/ModInt.hpp
    title: Library/Math/ModInt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind_with_potential
    links:
    - https://judge.yosupo.jp/problem/unionfind_with_potential
  bundledCode: "#line 1 \"Test/DataStructure/DisjointSetUnion_Potential.test.cpp\"\
    \n#include <vector>\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential\"\
    \r\n\r\n#include <iostream>\r\n#include <ranges>\r\n\r\n// begin:tag includes\r\
    \n#line 2 \"Library/DataStructure/DisjointSetUnion.hpp\"\n\r\n#line 4 \"Library/DataStructure/DisjointSetUnion.hpp\"\
    \n#include <numeric>\r\n#line 6 \"Library/DataStructure/DisjointSetUnion.hpp\"\
    \n\r\nnamespace mtd {\r\n\r\n  template <class T = int>\r\n  class PotentialDisjointSetUnion\
    \ {\r\n    std::vector<int> m_root;\r\n    std::vector<int> m_rank;\r\n    std::vector<int>\
    \ m_size;\r\n    std::vector<T> m_potential;\r\n\r\n  public:\r\n    PotentialDisjointSetUnion()\
    \ = delete;\r\n    PotentialDisjointSetUnion(int n)\r\n        : m_root(n), m_rank(n),\
    \ m_size(n, 1), m_potential(n) {\r\n      std::iota(m_root.begin(), m_root.end(),\
    \ 0);\r\n    }\r\n\r\n    auto unite(int x, int y, T p = 0) {\r\n      p += potential(x);\r\
    \n      p -= potential(y);\r\n      x = root(x);\r\n      y = root(y);\r\n   \
    \   if (x == y) { return false; }\r\n      if (m_rank[x] < m_rank[y]) {\r\n  \
    \      std::swap(x, y);\r\n        p = -p;\r\n      }\r\n      if (m_rank[x] ==\
    \ m_rank[y]) { ++m_rank[x]; }\r\n      m_size[x] = m_size[y] = size(x) + size(y);\r\
    \n      m_root[y] = x;\r\n      m_potential[y] = p;\r\n      return true;\r\n\
    \    }\r\n\r\n    auto root(int x) -> int {\r\n      if (m_root[x] == x) { return\
    \ x; }\r\n      int r = root(m_root[x]);\r\n      m_potential[x] += m_potential[m_root[x]];\r\
    \n      return m_root[x] = r;\r\n    }\r\n\r\n    auto potential(int x) -> T {\r\
    \n      root(x);\r\n      return m_potential[x];\r\n    }\r\n\r\n    auto size(int\
    \ x) -> int {\r\n      if (m_root[x] == x) { return m_size[x]; }\r\n      return\
    \ size(m_root[x] = root(m_root[x]));\r\n    }\r\n\r\n    auto isSame(int x, int\
    \ y) { return root(x) == root(y); }\r\n\r\n    auto diff(int x, int y) { return\
    \ potential(y) - potential(x); }\r\n\r\n    friend std::ostream& operator<<(std::ostream&\
    \ os,\r\n                                    const PotentialDisjointSetUnion&\
    \ dsu) {\r\n      for (const auto& x : dsu.m_root) { os << x << \" \"; }\r\n \
    \     return os;\r\n    }\r\n  };\r\n}  // namespace mtd\r\n#line 2 \"Library/Math/ModInt.hpp\"\
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
    \ auto val() const { return x; }\n  };\n\n}  // namespace mtd\n#line 10 \"Test/DataStructure/DisjointSetUnion_Potential.test.cpp\"\
    \n// end:tag includes\r\n\r\nconstexpr long long MOD = 998244353;\r\nusing mint\
    \ = mtd::ModInt<MOD>;\r\n\r\nsigned main() {\r\n  std::cin.tie(0);\r\n  std::ios::sync_with_stdio(0);\r\
    \n\r\n  int n, q;\r\n  std::cin >> n >> q;\r\n\r\n  auto dsu = mtd::PotentialDisjointSetUnion<mint>(n);\r\
    \n\r\n  for ([[maybe_unused]] auto _ : std::views::iota(0, q)) {\r\n    int t;\r\
    \n    std::cin >> t;\r\n    if (t == 0) {\r\n      int u, v, x;\r\n      std::cin\
    \ >> u >> v >> x;\r\n\r\n      if (!dsu.isSame(u, v) || dsu.diff(u, v) == x) {\r\
    \n        std::cout << 1 << std::endl;\r\n        dsu.unite(u, v, x);\r\n    \
    \  } else {\r\n        std::cout << 0 << std::endl;\r\n      }\r\n    } else {\r\
    \n      int u, v;\r\n      std::cin >> u >> v;\r\n\r\n      if (dsu.isSame(u,\
    \ v)) {\r\n        std::cout << dsu.diff(u, v) << std::endl;\r\n      } else {\r\
    \n        std::cout << -1 << std::endl;\r\n      }\r\n    }\r\n  }\r\n}\r\n"
  code: "#include <vector>\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential\"\
    \r\n\r\n#include <iostream>\r\n#include <ranges>\r\n\r\n// begin:tag includes\r\
    \n#include \"./../../Library/DataStructure/DisjointSetUnion.hpp\"\r\n#include\
    \ \"./../../Library/Math/ModInt.hpp\"\r\n// end:tag includes\r\n\r\nconstexpr\
    \ long long MOD = 998244353;\r\nusing mint = mtd::ModInt<MOD>;\r\n\r\nsigned main()\
    \ {\r\n  std::cin.tie(0);\r\n  std::ios::sync_with_stdio(0);\r\n\r\n  int n, q;\r\
    \n  std::cin >> n >> q;\r\n\r\n  auto dsu = mtd::PotentialDisjointSetUnion<mint>(n);\r\
    \n\r\n  for ([[maybe_unused]] auto _ : std::views::iota(0, q)) {\r\n    int t;\r\
    \n    std::cin >> t;\r\n    if (t == 0) {\r\n      int u, v, x;\r\n      std::cin\
    \ >> u >> v >> x;\r\n\r\n      if (!dsu.isSame(u, v) || dsu.diff(u, v) == x) {\r\
    \n        std::cout << 1 << std::endl;\r\n        dsu.unite(u, v, x);\r\n    \
    \  } else {\r\n        std::cout << 0 << std::endl;\r\n      }\r\n    } else {\r\
    \n      int u, v;\r\n      std::cin >> u >> v;\r\n\r\n      if (dsu.isSame(u,\
    \ v)) {\r\n        std::cout << dsu.diff(u, v) << std::endl;\r\n      } else {\r\
    \n        std::cout << -1 << std::endl;\r\n      }\r\n    }\r\n  }\r\n}\r\n"
  dependsOn:
  - Library/DataStructure/DisjointSetUnion.hpp
  - Library/Math/ModInt.hpp
  - Library/Math/Math.hpp
  isVerificationFile: true
  path: Test/DataStructure/DisjointSetUnion_Potential.test.cpp
  requiredBy: []
  timestamp: '2024-12-27 17:07:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/DataStructure/DisjointSetUnion_Potential.test.cpp
layout: document
redirect_from:
- /verify/Test/DataStructure/DisjointSetUnion_Potential.test.cpp
- /verify/Test/DataStructure/DisjointSetUnion_Potential.test.cpp.html
title: Test/DataStructure/DisjointSetUnion_Potential.test.cpp
---
