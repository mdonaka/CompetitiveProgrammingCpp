---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/String/TrieTree.hpp
    title: Library/String/TrieTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/430
    links:
    - https://yukicoder.me/problems/no/430
  bundledCode: "#line 1 \"Test/String/TrieTree.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/430\"\
    \r\n\r\n#include <iostream>\r\n#line 2 \"Library/String/TrieTree.hpp\"\n\r\n#include\
    \ <vector>\r\n#include <memory>\r\n\r\nconstexpr auto nullLambda = [](int n) {};\r\
    \ntemplate<class Val = bool, Val ignore = false>\r\nclass TrieTree {\r\n    Val\
    \ m_val;\r\n    std::vector<std::unique_ptr<TrieTree>> m_next;\r\n    //static\
    \ constexpr auto nullLambda = [](ll n) {}; c++17\r\n\r\n    auto emplace(const\
    \ std::vector<int>& vec, Val val, int it) {\r\n        if(it == vec.size()) {\r\
    \n            m_val = val;\r\n            return;\r\n        }\r\n        if(!m_next[vec[it]])\
    \ {\r\n            m_next[vec[it]] = std::make_unique<TrieTree>();\r\n       \
    \ }\r\n        m_next[vec[it]]->emplace(vec, val, it + 1);\r\n    }\r\n\r\n  \
    \  template<class Lambda>\r\n    auto find(const std::vector<int>& vec, int it,\
    \ const Lambda& lambda)const {\r\n        if(m_val != ignore) { lambda(m_val);\
    \ }\r\n        if(it == vec.size()) { return m_val; }\r\n        if(!m_next[vec[it]])\
    \ { return ignore; }\r\n        return m_next[vec[it]]->find(vec, it + 1, lambda);\r\
    \n    }\r\n\r\npublic:\r\n    TrieTree() : TrieTree(ignore) {}\r\n    TrieTree(Val\
    \ val) :m_val(val), m_next(std::vector<std::unique_ptr<TrieTree>>(26)) {}\r\n\r\
    \n    auto emplace(const std::vector<int>& vec, Val val) { return emplace(vec,\
    \ val, 0); }\r\n\r\n    template<class Lambda = decltype(nullLambda)>\r\n    auto\
    \ find(const std::vector<int>& vec, const Lambda& lambda = nullLambda) { return\
    \ find(vec, 0, lambda); }\r\n};\n#line 5 \"Test/String/TrieTree.test.cpp\"\n\r\
    \nusing ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr char\
    \ endl = '\\n';\r\n\r\nsigned main() {\r\n    std::string str;\r\n    cin >> str;\r\
    \n    ll n;\r\n    cin >> n;\r\n\r\n    auto tree = TrieTree<bool, false>();\r\
    \n    for(int _ = 0; _ < n; ++_) {\r\n        std::string s;\r\n        cin >>\
    \ s;\r\n        std::vector<int> v(s.begin(), s.end());\r\n        for(auto&&\
    \ c : v) { c -= 'A'; }\r\n        tree.emplace(v, true);\r\n    }\r\n\r\n    int\
    \ sz = str.size();\r\n    constexpr int ss = 10;\r\n    ll ans = 0;\r\n    for(int\
    \ i = 0; i < sz; ++i) {\r\n        std::vector<int> v;\r\n        v.reserve(ss);\r\
    \n        for(int j = i; j < std::min(i + ss, sz); ++j) {\r\n            v.emplace_back(str[j]\
    \ - 'A');\r\n        }\r\n        tree.find(v, [&](bool) { ++ans; });\r\n    }\r\
    \n    cout << ans << endl;\r\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/430\"\r\n\r\n#include\
    \ <iostream>\r\n#include \"./../../Library/String/TrieTree.hpp\"\r\n\r\nusing\
    \ ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr char endl\
    \ = '\\n';\r\n\r\nsigned main() {\r\n    std::string str;\r\n    cin >> str;\r\
    \n    ll n;\r\n    cin >> n;\r\n\r\n    auto tree = TrieTree<bool, false>();\r\
    \n    for(int _ = 0; _ < n; ++_) {\r\n        std::string s;\r\n        cin >>\
    \ s;\r\n        std::vector<int> v(s.begin(), s.end());\r\n        for(auto&&\
    \ c : v) { c -= 'A'; }\r\n        tree.emplace(v, true);\r\n    }\r\n\r\n    int\
    \ sz = str.size();\r\n    constexpr int ss = 10;\r\n    ll ans = 0;\r\n    for(int\
    \ i = 0; i < sz; ++i) {\r\n        std::vector<int> v;\r\n        v.reserve(ss);\r\
    \n        for(int j = i; j < std::min(i + ss, sz); ++j) {\r\n            v.emplace_back(str[j]\
    \ - 'A');\r\n        }\r\n        tree.find(v, [&](bool) { ++ans; });\r\n    }\r\
    \n    cout << ans << endl;\r\n}"
  dependsOn:
  - Library/String/TrieTree.hpp
  isVerificationFile: true
  path: Test/String/TrieTree.test.cpp
  requiredBy: []
  timestamp: '2022-09-11 06:12:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/String/TrieTree.test.cpp
layout: document
redirect_from:
- /verify/Test/String/TrieTree.test.cpp
- /verify/Test/String/TrieTree.test.cpp.html
title: Test/String/TrieTree.test.cpp
---
