---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Library/String/TrieTree.hpp
    title: Library/String/TrieTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/430
    links:
    - https://yukicoder.me/problems/no/430
  bundledCode: "#line 1 \"Test/String/TrieTree.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/430\"\
    \r\n\r\n#line 2 \"Library/String/TrieTree.hpp\"\n\r\n#include <memory>\r\n#include\
    \ <vector>\r\n\r\nnamespace mtd {\r\n  template <class Val = bool, Val ignore\
    \ = false>\r\n  class TrieTree {\r\n    Val m_val;\r\n    std::vector<std::unique_ptr<TrieTree>>\
    \ m_next;\r\n    static constexpr auto nullLambda = [](int) {};\r\n\r\n    auto\
    \ emplace(const std::vector<int>& vec, Val val, int it) {\r\n      if (it == vec.size())\
    \ {\r\n        m_val = val;\r\n        return;\r\n      }\r\n      if (!m_next[vec[it]])\
    \ { m_next[vec[it]] = std::make_unique<TrieTree>(); }\r\n      m_next[vec[it]]->emplace(vec,\
    \ val, it + 1);\r\n    }\r\n\r\n    template <class Lambda>\r\n    auto find(const\
    \ std::vector<int>& vec, int it, const Lambda& lambda) const {\r\n      if (m_val\
    \ != ignore) { lambda(m_val); }\r\n      if (it == vec.size()) { return m_val;\
    \ }\r\n      if (!m_next[vec[it]]) { return ignore; }\r\n      return m_next[vec[it]]->find(vec,\
    \ it + 1, lambda);\r\n    }\r\n\r\n  public:\r\n    TrieTree() : TrieTree(ignore)\
    \ {}\r\n    TrieTree(Val val)\r\n        : m_val(val), m_next(std::vector<std::unique_ptr<TrieTree>>(26))\
    \ {}\r\n\r\n    auto emplace(const std::vector<int>& vec, Val val) {\r\n     \
    \ return emplace(vec, val, 0);\r\n    }\r\n\r\n    template <class Lambda = decltype(nullLambda)>\r\
    \n    auto find(const std::vector<int>& vec, const Lambda& lambda = nullLambda)\
    \ {\r\n      return find(vec, 0, lambda);\r\n    }\r\n  };\r\n}  // namespace\
    \ mtd\r\n#line 4 \"Test/String/TrieTree.test.cpp\"\n\r\n#include <iostream>\r\n\
    \r\nusing ll = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr\
    \ char endl = '\\n';\r\n\r\nsigned main() {\r\n  std::string str;\r\n  cin >>\
    \ str;\r\n  ll n;\r\n  cin >> n;\r\n\r\n  auto tree = mtd::TrieTree<bool, false>();\r\
    \n  for (int _ = 0; _ < n; ++_) {\r\n    std::string s;\r\n    cin >> s;\r\n \
    \   std::vector<int> v(s.begin(), s.end());\r\n    for (auto&& c : v) { c -= 'A';\
    \ }\r\n    tree.emplace(v, true);\r\n  }\r\n\r\n  int sz = str.size();\r\n  constexpr\
    \ int ss = 10;\r\n  ll ans = 0;\r\n  for (int i = 0; i < sz; ++i) {\r\n    std::vector<int>\
    \ v;\r\n    v.reserve(ss);\r\n    for (int j = i; j < std::min(i + ss, sz); ++j)\
    \ {\r\n      v.emplace_back(str[j] - 'A');\r\n    }\r\n    tree.find(v, [&](bool)\
    \ { ++ans; });\r\n  }\r\n  cout << ans << endl;\r\n}\r\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/430\"\r\n\r\n#include\
    \ \"./../../Library/String/TrieTree.hpp\"\r\n\r\n#include <iostream>\r\n\r\nusing\
    \ ll = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr char endl\
    \ = '\\n';\r\n\r\nsigned main() {\r\n  std::string str;\r\n  cin >> str;\r\n \
    \ ll n;\r\n  cin >> n;\r\n\r\n  auto tree = mtd::TrieTree<bool, false>();\r\n\
    \  for (int _ = 0; _ < n; ++_) {\r\n    std::string s;\r\n    cin >> s;\r\n  \
    \  std::vector<int> v(s.begin(), s.end());\r\n    for (auto&& c : v) { c -= 'A';\
    \ }\r\n    tree.emplace(v, true);\r\n  }\r\n\r\n  int sz = str.size();\r\n  constexpr\
    \ int ss = 10;\r\n  ll ans = 0;\r\n  for (int i = 0; i < sz; ++i) {\r\n    std::vector<int>\
    \ v;\r\n    v.reserve(ss);\r\n    for (int j = i; j < std::min(i + ss, sz); ++j)\
    \ {\r\n      v.emplace_back(str[j] - 'A');\r\n    }\r\n    tree.find(v, [&](bool)\
    \ { ++ans; });\r\n  }\r\n  cout << ans << endl;\r\n}\r\n"
  dependsOn:
  - Library/String/TrieTree.hpp
  isVerificationFile: true
  path: Test/String/TrieTree.test.cpp
  requiredBy: []
  timestamp: '2024-12-27 17:07:26+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/String/TrieTree.test.cpp
layout: document
redirect_from:
- /verify/Test/String/TrieTree.test.cpp
- /verify/Test/String/TrieTree.test.cpp.html
title: Test/String/TrieTree.test.cpp
---
