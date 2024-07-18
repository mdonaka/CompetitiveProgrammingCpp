---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "#line 1 \"Test/DataStructure/Accumulation_xor.test.cpp\"\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/1456\"\r\n\r\n#include <iostream>\r\
    \n#include <unordered_set>\r\n\r\n#line 2 \"Library/DataStructure/Accumulation.hpp\"\
    \n#include <vector>\r\n#include <algorithm>\r\n\r\ntemplate<\r\n    class S, \
    \  // \u8981\u7D20\u306E\u578B\r\n    S element, // \u5143\r\n    class T, //\
    \ 2\u9805\u6F14\u7B97\u5B50\r\n    class U // \u9006\u5143\r\n>\r\nstruct Group\
    \ {\r\n    S m_val;\r\n    Group() :m_val(element) {}\r\n    Group(S val) :m_val(val)\
    \ {}\r\n    Group inverse()const { return U()(m_val); }\r\n    Group binaryOperation(const\
    \ Group& g)const { return T()(m_val, g.m_val); }\r\n};\r\n\r\ntemplate<class P>\
    \ struct F_A_Inv { auto operator()(P x)const { return -x; } };\r\ntemplate<class\
    \ P> struct F_A_Bin { auto operator()(P x, P y)const { return x + y; } };\r\n\
    template<class P> using AdditiveGroup = Group<P, P(0), F_A_Bin<P>, F_A_Inv<P>>;\r\
    \n\r\ntemplate <class Group = AdditiveGroup<long long>>\r\nclass Accumulation\
    \ {\r\n    using S = decltype(Group().m_val);\r\n\r\n    const int size;\r\n \
    \   std::vector<Group> sumList;\r\npublic:\r\n\r\n    Accumulation() = delete;\r\
    \n    Accumulation(const std::vector<Group>& v) :size(v.size()), sumList(size\
    \ + 1) {\r\n        for(int i = 0; i < size; ++i) {\r\n            sumList[i +\
    \ 1] = sumList[i].binaryOperation(v[i]);\r\n        }\r\n    }\r\n    Accumulation(const\
    \ std::vector<S>& v)\r\n        :Accumulation(std::vector<Group>(v.begin(), v.end()))\
    \ {\r\n    }\r\n\r\n    auto get(int n) {\r\n        return sumList[n + 1].m_val;\r\
    \n    }\r\n    auto get(int l, int r) {\r\n        if(r < l) { return Group().m_val;\
    \ }\r\n        l = std::max(l, 0); r = std::min(r, size - 1);\r\n        return\
    \ sumList[r + 1].binaryOperation(sumList[l].inverse()).m_val;\r\n    }\r\n};\r\
    \n#line 7 \"Test/DataStructure/Accumulation_xor.test.cpp\"\n\r\nusing ll = long\
    \ long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr char endl = '\\n';\r\
    \n\r\nstruct F_inv { auto operator()(ll x) { return x; } };\r\nstruct F_xor {\
    \ auto operator()(ll x, ll y) { return x ^ y; } };\r\nusing G = Group<ll, 0, F_xor,\
    \ F_inv>;\r\n\r\nsigned main() {\r\n    ll n, k;\r\n    cin >> n >> k;\r\n\r\n\
    \    std::vector<ll> a; a.reserve(n);\r\n    for(int _ = 0; _ < n; ++_) {\r\n\
    \        ll x; cin >> x;\r\n        a.emplace_back(x);\r\n    }\r\n\r\n    auto\
    \ acc = Accumulation<G>(a);\r\n    std::unordered_set<ll> st;\r\n    for(int i\
    \ = 0; i < n; ++i) {\r\n        st.emplace(acc.get(i) ^ k);\r\n    }\r\n\r\n \
    \   if(st.find(0) != st.end()) { cout << \"Yes\" << endl; return 0; }\r\n    for(int\
    \ i = 0; i < n; ++i) {\r\n        if(st.find(acc.get(i)) != st.end()) { cout <<\
    \ \"Yes\" << endl; return 0; }\r\n    }\r\n    cout << \"No\" << endl;\r\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1456\"\r\n\r\n#include\
    \ <iostream>\r\n#include <unordered_set>\r\n\r\n#include \"./../../Library/DataStructure/Accumulation.hpp\"\
    \r\n\r\nusing ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr\
    \ char endl = '\\n';\r\n\r\nstruct F_inv { auto operator()(ll x) { return x; }\
    \ };\r\nstruct F_xor { auto operator()(ll x, ll y) { return x ^ y; } };\r\nusing\
    \ G = Group<ll, 0, F_xor, F_inv>;\r\n\r\nsigned main() {\r\n    ll n, k;\r\n \
    \   cin >> n >> k;\r\n\r\n    std::vector<ll> a; a.reserve(n);\r\n    for(int\
    \ _ = 0; _ < n; ++_) {\r\n        ll x; cin >> x;\r\n        a.emplace_back(x);\r\
    \n    }\r\n\r\n    auto acc = Accumulation<G>(a);\r\n    std::unordered_set<ll>\
    \ st;\r\n    for(int i = 0; i < n; ++i) {\r\n        st.emplace(acc.get(i) ^ k);\r\
    \n    }\r\n\r\n    if(st.find(0) != st.end()) { cout << \"Yes\" << endl; return\
    \ 0; }\r\n    for(int i = 0; i < n; ++i) {\r\n        if(st.find(acc.get(i)) !=\
    \ st.end()) { cout << \"Yes\" << endl; return 0; }\r\n    }\r\n    cout << \"\
    No\" << endl;\r\n}"
  dependsOn: []
  isVerificationFile: true
  path: Test/DataStructure/Accumulation_xor.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/DataStructure/Accumulation_xor.test.cpp
layout: document
redirect_from:
- /verify/Test/DataStructure/Accumulation_xor.test.cpp
- /verify/Test/DataStructure/Accumulation_xor.test.cpp.html
title: Test/DataStructure/Accumulation_xor.test.cpp
---
