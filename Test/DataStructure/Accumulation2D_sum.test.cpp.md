---
data:
  _extendedDependsOn:
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
    \n\r\n#line 2 \"Library/DataStructure/Accumulation2D.hpp\"\n#include <vector>\r\
    \n\r\ntemplate<\r\n    class S,   // \u8981\u7D20\u306E\u578B\r\n    S element,\
    \ // \u5143\r\n    class T, // 2\u9805\u6F14\u7B97\u5B50\r\n    class U // \u9006\
    \u5143\r\n>\r\nstruct Group {\r\n    S m_val;\r\n    Group() :m_val(element) {}\r\
    \n    Group(S val) :m_val(val) {}\r\n    Group inverse()const { return U()(m_val);\
    \ }\r\n    Group binaryOperation(const Group& g)const { return T()(m_val, g.m_val);\
    \ }\r\n};\r\n\r\ntemplate<class P> struct F_A_Inv { auto operator()(P x)const\
    \ { return -x; } };\r\ntemplate<class P> struct F_A_Bin { auto operator()(P x,\
    \ P y)const { return x + y; } };\r\ntemplate<class P> using AdditiveGroup = Group<P,\
    \ P(0), F_A_Bin<P>, F_A_Inv<P>>;\r\n\r\ntemplate <class Group = AdditiveGroup<long\
    \ long>>\r\nclass Accumulation2D {\r\nprivate:\r\n    using S = decltype(Group().m_val);\r\
    \n\r\n    const int h;\r\n    const int w;\r\n    std::vector<std::vector<Group>>\
    \ sumList;\r\npublic:\r\n\r\n    Accumulation2D() = delete;\r\n    Accumulation2D(const\
    \ std::vector<std::vector<S>>& v) :\r\n        h(v.size()),\r\n        w(v[0].size()),\r\
    \n        sumList(h + 1, std::vector<Group>(w + 1)) {\r\n        for(int i = 0;\
    \ i < h; ++i) for(int j = 0; j < w; ++j) {\r\n            sumList[i + 1][j + 1]\
    \ = v[i][j];\r\n        }\r\n        for(int i = 0; i < h; ++i) for(int j = 0;\
    \ j < w + 1; ++j) {\r\n            sumList[i + 1][j] = sumList[i + 1][j].binaryOperation(sumList[i][j]);\r\
    \n        }\r\n        for(int i = 0; i < h + 1; ++i) for(int j = 0; j < w; ++j)\
    \ {\r\n            sumList[i][j + 1] = sumList[i][j + 1].binaryOperation(sumList[i][j]);\r\
    \n        }\r\n    }\r\n    S get(int y, int x) {\r\n        return sumList[y\
    \ + 1][x + 1].m_val;\r\n    }\r\n    S get(int y1, int x1, int y2, int x2) {\r\
    \n        if(y2 < y1 || x2 < x1) { return Group().m_val; }\r\n        x1 = std::max(x1,\
    \ 0); y1 = std::max(y1, 0);\r\n        y2 = std::min(y2, h - 1); x2 = std::min(x2,\
    \ w - 1);\r\n        return sumList[y2 + 1][x2 + 1]\r\n            .binaryOperation(sumList[y1][x1])\r\
    \n            .binaryOperation(sumList[y2 + 1][x1].inverse())\r\n            .binaryOperation(sumList[y1][x2\
    \ + 1].inverse()).m_val;\r\n    }\r\n};\r\n#line 6 \"Test/DataStructure/Accumulation2D_sum.test.cpp\"\
    \n\r\nusing ll = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr\
    \ char endl = '\\n';\r\n\r\nsigned main() {\r\n  int n;\r\n  cin >> n;\r\n\r\n\
    \  constexpr ll size = 3e3 + 1;\r\n\r\n  std::vector<ll> rv;\r\n  rv.reserve(n);\r\
    \n  for (int _ = 0; _ < n; ++_) {\r\n    int r;\r\n    cin >> r;\r\n    rv.emplace_back(r);\r\
    \n  }\r\n  std::vector<ll> gc(size), bc(size);\r\n  for (int _ = 0; _ < n; ++_)\
    \ {\r\n    int b;\r\n    cin >> b;\r\n    ++bc[b];\r\n  }\r\n  for (int _ = 0;\
    \ _ < n; ++_) {\r\n    int g;\r\n    cin >> g;\r\n    ++gc[g];\r\n  }\r\n\r\n\
    \  std::vector<std::vector<ll>> table(size, std::vector<ll>(2 * size));\r\n  for\
    \ (int i = 0; i < size; ++i)\r\n    for (int j = 0; j < size; ++j) {\r\n     \
    \ table[std::max(i, j)][i + j] += gc[i] * bc[j];\r\n    }\r\n  auto acc = Accumulation2D<>(table);\r\
    \n\r\n  ll ans = 0;\r\n  for (const auto& r : rv) { ans += acc.get(0, r + 1, r,\
    \ 2 * size - 1); }\r\n  cout << ans << endl;\r\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1623\"\r\n\r\n#include\
    \ <iostream>\r\n\r\n#include \"./../../Library/DataStructure/Accumulation2D.hpp\"\
    \r\n\r\nusing ll = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr\
    \ char endl = '\\n';\r\n\r\nsigned main() {\r\n  int n;\r\n  cin >> n;\r\n\r\n\
    \  constexpr ll size = 3e3 + 1;\r\n\r\n  std::vector<ll> rv;\r\n  rv.reserve(n);\r\
    \n  for (int _ = 0; _ < n; ++_) {\r\n    int r;\r\n    cin >> r;\r\n    rv.emplace_back(r);\r\
    \n  }\r\n  std::vector<ll> gc(size), bc(size);\r\n  for (int _ = 0; _ < n; ++_)\
    \ {\r\n    int b;\r\n    cin >> b;\r\n    ++bc[b];\r\n  }\r\n  for (int _ = 0;\
    \ _ < n; ++_) {\r\n    int g;\r\n    cin >> g;\r\n    ++gc[g];\r\n  }\r\n\r\n\
    \  std::vector<std::vector<ll>> table(size, std::vector<ll>(2 * size));\r\n  for\
    \ (int i = 0; i < size; ++i)\r\n    for (int j = 0; j < size; ++j) {\r\n     \
    \ table[std::max(i, j)][i + j] += gc[i] * bc[j];\r\n    }\r\n  auto acc = Accumulation2D<>(table);\r\
    \n\r\n  ll ans = 0;\r\n  for (const auto& r : rv) { ans += acc.get(0, r + 1, r,\
    \ 2 * size - 1); }\r\n  cout << ans << endl;\r\n}"
  dependsOn:
  - Library/DataStructure/Accumulation2D.hpp
  isVerificationFile: true
  path: Test/DataStructure/Accumulation2D_sum.test.cpp
  requiredBy: []
  timestamp: '2024-08-05 00:48:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/DataStructure/Accumulation2D_sum.test.cpp
layout: document
redirect_from:
- /verify/Test/DataStructure/Accumulation2D_sum.test.cpp
- /verify/Test/DataStructure/Accumulation2D_sum.test.cpp.html
title: Test/DataStructure/Accumulation2D_sum.test.cpp
---
