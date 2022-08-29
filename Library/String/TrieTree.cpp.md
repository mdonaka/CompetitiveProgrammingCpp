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
  bundledCode: "#line 1 \"Library/String/TrieTree.cpp\"\nconstexpr auto nullLambda\
    \ = [](ll n) {};\r\ntemplate<class Val = bool, Val ignore = false>\r\nclass TrieTree\
    \ {\r\n\tVal m_val;\r\n\tstd::vector<std::unique_ptr<TrieTree>> m_next;\r\n\t\
    //static constexpr auto nullLambda = [](ll n) {}; c++17\r\n\r\n\tauto emplace(const\
    \ std::vector<int>& vec, Val val, int it) {\r\n\t\tif (it == vec.size()) {\r\n\
    \t\t\tm_val = val;\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tif (!m_next[vec[it]]) {\r\n\
    \t\t\tm_next[vec[it]] = std::make_unique<TrieTree>();\r\n\t\t}\r\n\t\tm_next[vec[it]]->emplace(vec,\
    \ val, it + 1);\r\n\t}\r\n\r\n\ttemplate<class Lambda>\r\n\tauto find(const std::vector<int>&\
    \ vec, int it, const Lambda& lambda)const {\r\n\t\tif (m_val != ignore) { lambda(m_val);\
    \ }\r\n\t\tif (it == vec.size()) { return m_val; }\r\n\t\tif (!m_next[vec[it]])\
    \ { return ignore; }\r\n\t\treturn m_next[vec[it]]->find(vec, it + 1, lambda);\r\
    \n\t}\r\n\r\npublic:\r\n\tTrieTree() : TrieTree(ignore) {}\r\n\tTrieTree(Val val)\
    \ :m_val(val), m_next(std::vector<std::unique_ptr<TrieTree>>(26)) {}\r\n\r\n\t\
    auto emplace(const std::vector<int>& vec, Val val) { return emplace(vec, val,\
    \ 0); }\r\n\r\n\ttemplate<class Lambda = decltype(nullLambda)>\r\n\tauto find(const\
    \ std::vector<int> & vec, const Lambda & lambda = nullLambda) { return find(vec,\
    \ 0, lambda); }\r\n};\n"
  code: "constexpr auto nullLambda = [](ll n) {};\r\ntemplate<class Val = bool, Val\
    \ ignore = false>\r\nclass TrieTree {\r\n\tVal m_val;\r\n\tstd::vector<std::unique_ptr<TrieTree>>\
    \ m_next;\r\n\t//static constexpr auto nullLambda = [](ll n) {}; c++17\r\n\r\n\
    \tauto emplace(const std::vector<int>& vec, Val val, int it) {\r\n\t\tif (it ==\
    \ vec.size()) {\r\n\t\t\tm_val = val;\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tif (!m_next[vec[it]])\
    \ {\r\n\t\t\tm_next[vec[it]] = std::make_unique<TrieTree>();\r\n\t\t}\r\n\t\t\
    m_next[vec[it]]->emplace(vec, val, it + 1);\r\n\t}\r\n\r\n\ttemplate<class Lambda>\r\
    \n\tauto find(const std::vector<int>& vec, int it, const Lambda& lambda)const\
    \ {\r\n\t\tif (m_val != ignore) { lambda(m_val); }\r\n\t\tif (it == vec.size())\
    \ { return m_val; }\r\n\t\tif (!m_next[vec[it]]) { return ignore; }\r\n\t\treturn\
    \ m_next[vec[it]]->find(vec, it + 1, lambda);\r\n\t}\r\n\r\npublic:\r\n\tTrieTree()\
    \ : TrieTree(ignore) {}\r\n\tTrieTree(Val val) :m_val(val), m_next(std::vector<std::unique_ptr<TrieTree>>(26))\
    \ {}\r\n\r\n\tauto emplace(const std::vector<int>& vec, Val val) { return emplace(vec,\
    \ val, 0); }\r\n\r\n\ttemplate<class Lambda = decltype(nullLambda)>\r\n\tauto\
    \ find(const std::vector<int> & vec, const Lambda & lambda = nullLambda) { return\
    \ find(vec, 0, lambda); }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: Library/String/TrieTree.cpp
  requiredBy: []
  timestamp: '2019-12-07 04:12:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/String/TrieTree.cpp
layout: document
redirect_from:
- /library/Library/String/TrieTree.cpp
- /library/Library/String/TrieTree.cpp.html
title: Library/String/TrieTree.cpp
---
