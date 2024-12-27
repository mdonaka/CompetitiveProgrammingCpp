---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Algebraic/Group.hpp
    title: Library/Algebraic/Group.hpp
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/Accumulation.hpp
    title: Library/DataStructure/Accumulation.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1456
    links:
    - https://yukicoder.me/problems/no/1456
  bundledCode: "#line 1 \"Test/DataStructure/Accumulation_xor.test.cpp\"\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/1456\"\r\n\r\n#include <iostream>\r\
    \n#include <unordered_set>\r\n\r\n// begin:tag includes\r\n#line 2 \"Library/DataStructure/Accumulation.hpp\"\
    \n\r\n#include <algorithm>\r\n#include <vector>\r\n\r\n#line 2 \"Library/Algebraic/Group.hpp\"\
    \n\n#line 4 \"Library/Algebraic/Group.hpp\"\n\nnamespace mtd {\n\n  template <class\
    \ S,    // set\n            S element,  // identity element\n            class\
    \ op,   // binary operation\n            class inv   // inverse operation\n  \
    \          >\n  requires std::is_invocable_r_v<S, op, S, S>\n  struct Group {\n\
    \    using value_type = S;\n    constexpr static S _element = element;\n    using\
    \ op_type = op;\n    using inv_type = inv;\n\n    S m_val;\n    constexpr Group()\
    \ : m_val(element) {}\n    constexpr Group(S val) : m_val(val) {}\n    constexpr\
    \ Group inverse() const { return inv()(m_val); }\n    constexpr Group binaryOperation(const\
    \ Group& g) const {\n      return op()(m_val, g.m_val);\n    }\n    constexpr\
    \ friend std::ostream& operator<<(\n        std::ostream& os, const Group<S, element,\
    \ op, inv>& g) {\n      return os << g.m_val;\n    }\n  };\n\n  namespace __detail\
    \ {\n    template <typename T,\n              template <typename, auto, typename,\
    \ typename> typename S>\n    concept is_group_specialization_of = requires {\n\
    \      typename std::enable_if_t<\n          std::is_same_v<T, S<typename T::value_type,\
    \ T::_element,\n                              typename T::op_type, typename T::inv_type>>>;\n\
    \    };\n  }  // namespace __detail\n\n  template <typename G>\n  concept group\
    \ = __detail::is_group_specialization_of<G, Group>;\n\n}  // namespace mtd\n#line\
    \ 7 \"Library/DataStructure/Accumulation.hpp\"\n\r\nnamespace mtd {\r\n\r\n  namespace\
    \ type {\r\n\r\n    using inv = decltype([](auto x) { return -x; });\r\n    using\
    \ op = decltype([](auto x, auto y) { return x + y; });\r\n    template <class\
    \ P>\r\n    using AdditiveGroup = Group<P, P(0), op, inv>;\r\n\r\n  }  // namespace\
    \ type\r\n\r\n  template <group Group = type::AdditiveGroup<long long>>\r\n  class\
    \ Accumulation {\r\n    using S = decltype(Group().m_val);\r\n\r\n    const int\
    \ size;\r\n    std::vector<Group> sumList;\r\n\r\n  public:\r\n    constexpr Accumulation()\
    \ = delete;\r\n    constexpr Accumulation(const std::vector<Group>& v)\r\n   \
    \     : size(v.size()), sumList(size + 1) {\r\n      for (int i = 0; i < size;\
    \ ++i) {\r\n        sumList[i + 1] = sumList[i].binaryOperation(v[i]);\r\n   \
    \   }\r\n    }\r\n    constexpr Accumulation(const std::vector<S>& v)\r\n    \
    \    : Accumulation(std::vector<Group>(v.begin(), v.end())) {}\r\n\r\n    constexpr\
    \ auto get(int n) const { return sumList[n + 1].m_val; }\r\n    constexpr auto\
    \ get(int l, int r) const {\r\n      if (r < l) { return Group::_element; }\r\n\
    \      l = std::max(l, 0);\r\n      r = std::min(r, size - 1);\r\n      return\
    \ sumList[r + 1].binaryOperation(sumList[l].inverse()).m_val;\r\n    }\r\n\r\n\
    \    constexpr friend std::ostream& operator<<(std::ostream& os,\r\n         \
    \                                     const Accumulation<Group>& acc) {\r\n  \
    \    for (const auto& x : acc.sumList) { os << x << \" \"; }\r\n      return os;\r\
    \n    }\r\n  };\r\n\r\n}  // namespace mtd\r\n#line 8 \"Test/DataStructure/Accumulation_xor.test.cpp\"\
    \n// end:tag includes\r\n\r\nusing ll = long long;\r\n\r\nsigned main() {\r\n\
    \  std::cin.tie(0);\r\n  std::ios::sync_with_stdio(0);\r\n\r\n  ll n, k;\r\n \
    \ std::cin >> n >> k;\r\n\r\n  std::vector<ll> a;\r\n  a.reserve(n);\r\n  for\
    \ (int _ = 0; _ < n; ++_) {\r\n    ll x;\r\n    std::cin >> x;\r\n    a.emplace_back(x);\r\
    \n  }\r\n\r\n  auto inv = [](ll x) { return x; };\r\n  auto op = [](ll x, ll y)\
    \ { return x ^ y; };\r\n  using G = mtd::Group<ll, 0, decltype(op), decltype(inv)>;\r\
    \n  auto acc = mtd::Accumulation<G>(a);\r\n\r\n  std::unordered_set<ll> st;\r\n\
    \  for (int i = 0; i < n; ++i) { st.emplace(acc.get(i) ^ k); }\r\n\r\n  if (st.find(0)\
    \ != st.end()) {\r\n    std::cout << \"Yes\" << std::endl;\r\n    return 0;\r\n\
    \  }\r\n  for (int i = 0; i < n; ++i) {\r\n    if (st.find(acc.get(i)) != st.end())\
    \ {\r\n      std::cout << \"Yes\" << std::endl;\r\n      return 0;\r\n    }\r\n\
    \  }\r\n  std::cout << \"No\" << std::endl;\r\n}\r\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1456\"\r\n\r\n#include\
    \ <iostream>\r\n#include <unordered_set>\r\n\r\n// begin:tag includes\r\n#include\
    \ \"./../../Library/DataStructure/Accumulation.hpp\"\r\n// end:tag includes\r\n\
    \r\nusing ll = long long;\r\n\r\nsigned main() {\r\n  std::cin.tie(0);\r\n  std::ios::sync_with_stdio(0);\r\
    \n\r\n  ll n, k;\r\n  std::cin >> n >> k;\r\n\r\n  std::vector<ll> a;\r\n  a.reserve(n);\r\
    \n  for (int _ = 0; _ < n; ++_) {\r\n    ll x;\r\n    std::cin >> x;\r\n    a.emplace_back(x);\r\
    \n  }\r\n\r\n  auto inv = [](ll x) { return x; };\r\n  auto op = [](ll x, ll y)\
    \ { return x ^ y; };\r\n  using G = mtd::Group<ll, 0, decltype(op), decltype(inv)>;\r\
    \n  auto acc = mtd::Accumulation<G>(a);\r\n\r\n  std::unordered_set<ll> st;\r\n\
    \  for (int i = 0; i < n; ++i) { st.emplace(acc.get(i) ^ k); }\r\n\r\n  if (st.find(0)\
    \ != st.end()) {\r\n    std::cout << \"Yes\" << std::endl;\r\n    return 0;\r\n\
    \  }\r\n  for (int i = 0; i < n; ++i) {\r\n    if (st.find(acc.get(i)) != st.end())\
    \ {\r\n      std::cout << \"Yes\" << std::endl;\r\n      return 0;\r\n    }\r\n\
    \  }\r\n  std::cout << \"No\" << std::endl;\r\n}\r\n"
  dependsOn:
  - Library/DataStructure/Accumulation.hpp
  - Library/Algebraic/Group.hpp
  isVerificationFile: true
  path: Test/DataStructure/Accumulation_xor.test.cpp
  requiredBy: []
  timestamp: '2024-12-27 16:29:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/DataStructure/Accumulation_xor.test.cpp
layout: document
redirect_from:
- /verify/Test/DataStructure/Accumulation_xor.test.cpp
- /verify/Test/DataStructure/Accumulation_xor.test.cpp.html
title: Test/DataStructure/Accumulation_xor.test.cpp
---
