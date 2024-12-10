---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Algebraic/Group.hpp
    title: Library/Algebraic/Group.hpp
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/Accumulation.hpp
    title: Library/DataStructure/Accumulation.hpp
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/Accumulation2D.hpp
    title: Library/DataStructure/Accumulation2D.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1623
    links:
    - https://yukicoder.me/problems/no/1623
  bundledCode: "#line 1 \"Test/DataStructure/Accumulation2D_sum.test.cpp\"\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/1623\"\r\n\r\n#include <iostream>\r\
    \n\r\n// begin:tag includes\r\n#line 2 \"Library/DataStructure/Accumulation2D.hpp\"\
    \n#include <vector>\r\n\r\n#line 2 \"Library/Algebraic/Group.hpp\"\n\n#line 4\
    \ \"Library/Algebraic/Group.hpp\"\n\nnamespace mtd {\n\n  template <class S, \
    \   // set\n            S element,  // identity element\n            class op,\
    \   // binary operation\n            class inv   // inverse operation\n      \
    \      >\n  requires std::is_invocable_r_v<S, op, S, S>\n  struct Group {\n  \
    \  using value_type = S;\n    constexpr static S _element = element;\n    using\
    \ op_type = op;\n    using inv_type = inv;\n\n    S m_val;\n    constexpr Group()\
    \ : m_val(element) {}\n    constexpr Group(S val) : m_val(val) {}\n    constexpr\
    \ Group inverse() const { return inv()(m_val); }\n    constexpr Group binaryOperation(const\
    \ Group& g) const {\n      return op()(m_val, g.m_val);\n    }\n    constexpr\
    \ friend std::ostream& operator<<(\n        std::ostream& os, const Group<S, element,\
    \ op, inv>& g) {\n      return os << g.m_val;\n    }\n  };\n\n  namespace __detail\
    \ {\n    template <typename T,\n              template <typename, auto, typename,\
    \ typename> typename S>\n    concept is_specialization_of = requires {\n     \
    \ typename std::enable_if_t<\n          std::is_same_v<T, S<typename T::value_type,\
    \ T::_element,\n                              typename T::op_type, typename T::inv_type>>>;\n\
    \    };\n  }  // namespace __detail\n\n  template <typename G>\n  concept group\
    \ = __detail::is_specialization_of<G, Group>;\n\n}  // namespace mtd\n#line 2\
    \ \"Library/DataStructure/Accumulation.hpp\"\n\r\n#include <algorithm>\r\n#line\
    \ 5 \"Library/DataStructure/Accumulation.hpp\"\n\r\n#line 7 \"Library/DataStructure/Accumulation.hpp\"\
    \n\r\nnamespace mtd {\r\n\r\n  namespace Type {\r\n\r\n    using inv = decltype([](auto\
    \ x) { return -x; });\r\n    using op = decltype([](auto x, auto y) { return x\
    \ + y; });\r\n    template <class P>\r\n    using AdditiveGroup = Group<P, P(0),\
    \ op, inv>;\r\n\r\n  }  // namespace Type\r\n\r\n  template <group Group = Type::AdditiveGroup<long\
    \ long>>\r\n  class Accumulation {\r\n    using S = decltype(Group().m_val);\r\
    \n\r\n    const int size;\r\n    std::vector<Group> sumList;\r\n\r\n  public:\r\
    \n    constexpr Accumulation() = delete;\r\n    constexpr Accumulation(const std::vector<Group>&\
    \ v)\r\n        : size(v.size()), sumList(size + 1) {\r\n      for (int i = 0;\
    \ i < size; ++i) {\r\n        sumList[i + 1] = sumList[i].binaryOperation(v[i]);\r\
    \n      }\r\n    }\r\n    constexpr Accumulation(const std::vector<S>& v)\r\n\
    \        : Accumulation(std::vector<Group>(v.begin(), v.end())) {}\r\n\r\n   \
    \ constexpr auto get(int n) const { return sumList[n + 1].m_val; }\r\n    constexpr\
    \ auto get(int l, int r) const {\r\n      if (r < l) { return Group::_element;\
    \ }\r\n      l = std::max(l, 0);\r\n      r = std::min(r, size - 1);\r\n     \
    \ return sumList[r + 1].binaryOperation(sumList[l].inverse()).m_val;\r\n    }\r\
    \n\r\n    constexpr friend std::ostream& operator<<(std::ostream& os,\r\n    \
    \                                          const Accumulation<Group>& acc) {\r\
    \n      for (const auto& x : acc.sumList) { os << x << \" \"; }\r\n      return\
    \ os;\r\n    }\r\n  };\r\n\r\n}  // namespace mtd\r\n#line 6 \"Library/DataStructure/Accumulation2D.hpp\"\
    \n\r\nnamespace mtd {\r\n\r\n  template <group Group = Type::AdditiveGroup<long\
    \ long>>\r\n  class Accumulation2D {\r\n  private:\r\n    using S = decltype(Group().m_val);\r\
    \n\r\n    const int h;\r\n    const int w;\r\n    std::vector<std::vector<Group>>\
    \ sumList;\r\n\r\n  public:\r\n    constexpr Accumulation2D() = delete;\r\n  \
    \  constexpr Accumulation2D(const std::vector<std::vector<S>>& v)\r\n        :\
    \ h(v.size()),\r\n          w(v[0].size()),\r\n          sumList(h + 1, std::vector<Group>(w\
    \ + 1)) {\r\n      for (int i = 0; i < h; ++i) {\r\n        for (int j = 0; j\
    \ < w; ++j) { sumList[i + 1][j + 1] = v[i][j]; }\r\n      }\r\n      for (int\
    \ i = 0; i < h; ++i) {\r\n        for (int j = 0; j < w + 1; ++j) {\r\n      \
    \    sumList[i + 1][j] = sumList[i + 1][j].binaryOperation(sumList[i][j]);\r\n\
    \        }\r\n      }\r\n      for (int i = 0; i < h + 1; ++i) {\r\n        for\
    \ (int j = 0; j < w; ++j) {\r\n          sumList[i][j + 1] = sumList[i][j + 1].binaryOperation(sumList[i][j]);\r\
    \n        }\r\n      }\r\n    }\r\n    constexpr S get(int y, int x) { return\
    \ sumList[y + 1][x + 1].m_val; }\r\n    constexpr S get(int y1, int x1, int y2,\
    \ int x2) {\r\n      if (y2 < y1 || x2 < x1) { return Group().m_val; }\r\n   \
    \   x1 = std::max(x1, 0);\r\n      y1 = std::max(y1, 0);\r\n      y2 = std::min(y2,\
    \ h - 1);\r\n      x2 = std::min(x2, w - 1);\r\n      return sumList[y2 + 1][x2\
    \ + 1]\r\n          .binaryOperation(sumList[y1][x1])\r\n          .binaryOperation(sumList[y2\
    \ + 1][x1].inverse())\r\n          .binaryOperation(sumList[y1][x2 + 1].inverse())\r\
    \n          .m_val;\r\n    }\r\n  };\r\n\r\n}  // namespace mtd\r\n#line 7 \"\
    Test/DataStructure/Accumulation2D_sum.test.cpp\"\n// end:tag includes\r\n\r\n\
    using ll = long long;\r\n\r\nsigned main() {\r\n  std::cin.tie(0);\r\n  std::ios::sync_with_stdio(0);\r\
    \n\r\n  int n;\r\n  std::cin >> n;\r\n\r\n  constexpr ll size = 3e3 + 1;\r\n\r\
    \n  std::vector<ll> rv;\r\n  rv.reserve(n);\r\n  for (int _ = 0; _ < n; ++_) {\r\
    \n    int r;\r\n    std::cin >> r;\r\n    rv.emplace_back(r);\r\n  }\r\n  std::vector<ll>\
    \ gc(size), bc(size);\r\n  for (int _ = 0; _ < n; ++_) {\r\n    int b;\r\n   \
    \ std::cin >> b;\r\n    ++bc[b];\r\n  }\r\n  for (int _ = 0; _ < n; ++_) {\r\n\
    \    int g;\r\n    std::cin >> g;\r\n    ++gc[g];\r\n  }\r\n\r\n  std::vector<std::vector<ll>>\
    \ table(size, std::vector<ll>(2 * size));\r\n  for (int i = 0; i < size; ++i)\r\
    \n    for (int j = 0; j < size; ++j) {\r\n      table[std::max(i, j)][i + j] +=\
    \ gc[i] * bc[j];\r\n    }\r\n  auto acc = mtd::Accumulation2D<>(table);\r\n\r\n\
    \  ll ans = 0;\r\n  for (const auto& r : rv) { ans += acc.get(0, r + 1, r, 2 *\
    \ size - 1); }\r\n  std::cout << ans << std::endl;\r\n}\r\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1623\"\r\n\r\n#include\
    \ <iostream>\r\n\r\n// begin:tag includes\r\n#include \"./../../Library/DataStructure/Accumulation2D.hpp\"\
    \r\n// end:tag includes\r\n\r\nusing ll = long long;\r\n\r\nsigned main() {\r\n\
    \  std::cin.tie(0);\r\n  std::ios::sync_with_stdio(0);\r\n\r\n  int n;\r\n  std::cin\
    \ >> n;\r\n\r\n  constexpr ll size = 3e3 + 1;\r\n\r\n  std::vector<ll> rv;\r\n\
    \  rv.reserve(n);\r\n  for (int _ = 0; _ < n; ++_) {\r\n    int r;\r\n    std::cin\
    \ >> r;\r\n    rv.emplace_back(r);\r\n  }\r\n  std::vector<ll> gc(size), bc(size);\r\
    \n  for (int _ = 0; _ < n; ++_) {\r\n    int b;\r\n    std::cin >> b;\r\n    ++bc[b];\r\
    \n  }\r\n  for (int _ = 0; _ < n; ++_) {\r\n    int g;\r\n    std::cin >> g;\r\
    \n    ++gc[g];\r\n  }\r\n\r\n  std::vector<std::vector<ll>> table(size, std::vector<ll>(2\
    \ * size));\r\n  for (int i = 0; i < size; ++i)\r\n    for (int j = 0; j < size;\
    \ ++j) {\r\n      table[std::max(i, j)][i + j] += gc[i] * bc[j];\r\n    }\r\n\
    \  auto acc = mtd::Accumulation2D<>(table);\r\n\r\n  ll ans = 0;\r\n  for (const\
    \ auto& r : rv) { ans += acc.get(0, r + 1, r, 2 * size - 1); }\r\n  std::cout\
    \ << ans << std::endl;\r\n}\r\n"
  dependsOn:
  - Library/DataStructure/Accumulation2D.hpp
  - Library/Algebraic/Group.hpp
  - Library/DataStructure/Accumulation.hpp
  isVerificationFile: true
  path: Test/DataStructure/Accumulation2D_sum.test.cpp
  requiredBy: []
  timestamp: '2024-12-11 02:34:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/DataStructure/Accumulation2D_sum.test.cpp
layout: document
redirect_from:
- /verify/Test/DataStructure/Accumulation2D_sum.test.cpp
- /verify/Test/DataStructure/Accumulation2D_sum.test.cpp.html
title: Test/DataStructure/Accumulation2D_sum.test.cpp
---
