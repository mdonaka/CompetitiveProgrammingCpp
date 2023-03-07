---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Library/DataStructure/LiChaoTree.hpp
    title: Library/DataStructure/LiChaoTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"Test/DataStructure/LiChaoTree.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/line_add_get_min\"\r\n\r\n#include <iostream>\r\
    \n#include <vector>\r\n#include <deque>\r\n\r\n#line 2 \"Library/DataStructure/LiChaoTree.hpp\"\
    \n\r\n#line 4 \"Library/DataStructure/LiChaoTree.hpp\"\n#include <algorithm>\r\
    \n#include <unordered_map>\r\n\r\nclass LiChaoTree {\r\n    using T = long long;\r\
    \n    using Line = std::pair<T, T>;\r\n    constexpr static T INF = std::numeric_limits<\
    \ T >::max() / 2;\r\n\r\n    int m_size;\r\n    std::vector<T> m_x;\r\n    std::vector<Line>\
    \ m_node;\r\n    std::unordered_map<T, T> m_xtoi;\r\n\r\n    static inline int\
    \ calcSize(int n) { int size = 1; while(size < n) { size <<= 1; }return size;\
    \ }\r\n    auto f(const Line& line, const T& x)const { return line.first * x +\
    \ line.second; }\r\n\r\n    auto add(const Line& line_, int k, int l, int r) {\r\
    \n        auto line = line_;\r\n\r\n        auto m = (l + r) / 2;\r\n        if(f(line,\
    \ m_x[m]) < f(m_node[k], m_x[m])) { std::swap(line, m_node[k]); }\r\n        if(l\
    \ + 1 == r) { return; }\r\n        if(line.first > m_node[k].first) {\r\n    \
    \        add(line, (k << 1) + 1, l, m);\r\n        } else if(line.first < m_node[k].first)\
    \ {\r\n            add(line, (k << 1) + 2, m, r);\r\n        }\r\n    }\r\n\r\n\
    public:\r\n    LiChaoTree(const std::vector<T>& x_) :m_size(calcSize(x_.size()))\
    \ {\r\n        auto x = x_;\r\n        std::sort(x.begin(), x.end());\r\n    \
    \    x.erase(std::unique(x.begin(), x.end()), x.end());\r\n        m_x = decltype(m_x)(m_size);\r\
    \n        for(size_t i = 0; i < x.size(); ++i) {\r\n            m_x[i] = x[i];\r\
    \n            m_xtoi.emplace(x[i], i);\r\n        }\r\n        for(size_t i =\
    \ x.size(); i < m_size; ++i) { m_x[i] = m_x[i - 1] + 1; }\r\n        m_node =\
    \ decltype(m_node)(m_size << 1, {0,INF});\r\n    }\r\n\r\n    auto add(const Line&\
    \ line) { add(line, 0, 0, m_size); }\r\n    auto add(const T& a, const T& b) {\
    \ add({a,b}); }\r\n\r\n    auto query(const T& x) {\r\n        auto k = m_xtoi[x]\
    \ + m_size;\r\n        auto ret = INF;\r\n        while(k > 0) {\r\n         \
    \   ret = std::min(ret, f(m_node[k - 1], x));\r\n            k >>= 1;\r\n    \
    \    }\r\n        return ret;\r\n    }\r\n};\r\n#line 8 \"Test/DataStructure/LiChaoTree.test.cpp\"\
    \n\r\nusing ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr\
    \ char endl = '\\n';\r\n\r\nstruct Query {\r\n    int k;\r\n    ll a, b;\r\n \
    \   Query(int k, ll a, ll b) :k(k), a(a), b(b) {}\r\n    Query(int k, ll x) :Query(k,\
    \ x, 0) {}\r\n};\r\n\r\nsigned main() {\r\n    ll n, q;\r\n    cin >> n >> q;\r\
    \n    std::vector<std::pair<ll, ll>> v; v.reserve(n);\r\n    for(int _ = 0; _\
    \ < n; ++_) {\r\n        ll a, b;\r\n        cin >> a >> b;\r\n        v.emplace_back(a,\
    \ b);\r\n    }\r\n    std::vector<Query> queries; queries.reserve(q);\r\n    std::vector<ll>\
    \ xs; xs.reserve(q);\r\n    for(int _ = 0; _ < q; ++_) {\r\n        ll k;\r\n\
    \        cin >> k;\r\n        if(k == 0) {\r\n            ll a, b;\r\n       \
    \     cin >> a >> b;\r\n            queries.emplace_back(k, a, b);\r\n       \
    \ } else {\r\n            ll x;\r\n            cin >> x;\r\n            queries.emplace_back(k,\
    \ x);\r\n            xs.emplace_back(x);\r\n        }\r\n    }\r\n\r\n    auto\
    \ lct = LiChaoTree(xs);\r\n    for(const auto& [a, b] : v) { lct.add(a, b); }\r\
    \n\r\n    for(const auto& query : queries) {\r\n        if(query.k == 0) {\r\n\
    \            lct.add(query.a, query.b);\r\n        } else {\r\n            cout\
    \ << lct.query(query.a) << endl;\r\n        }\r\n    }\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\r\n\r\
    \n#include <iostream>\r\n#include <vector>\r\n#include <deque>\r\n\r\n#include\
    \ \"./../../Library/DataStructure/LiChaoTree.hpp\"\r\n\r\nusing ll = long long;\r\
    \nusing std::cout;\r\nusing std::cin;\r\nconstexpr char endl = '\\n';\r\n\r\n\
    struct Query {\r\n    int k;\r\n    ll a, b;\r\n    Query(int k, ll a, ll b) :k(k),\
    \ a(a), b(b) {}\r\n    Query(int k, ll x) :Query(k, x, 0) {}\r\n};\r\n\r\nsigned\
    \ main() {\r\n    ll n, q;\r\n    cin >> n >> q;\r\n    std::vector<std::pair<ll,\
    \ ll>> v; v.reserve(n);\r\n    for(int _ = 0; _ < n; ++_) {\r\n        ll a, b;\r\
    \n        cin >> a >> b;\r\n        v.emplace_back(a, b);\r\n    }\r\n    std::vector<Query>\
    \ queries; queries.reserve(q);\r\n    std::vector<ll> xs; xs.reserve(q);\r\n \
    \   for(int _ = 0; _ < q; ++_) {\r\n        ll k;\r\n        cin >> k;\r\n   \
    \     if(k == 0) {\r\n            ll a, b;\r\n            cin >> a >> b;\r\n \
    \           queries.emplace_back(k, a, b);\r\n        } else {\r\n           \
    \ ll x;\r\n            cin >> x;\r\n            queries.emplace_back(k, x);\r\n\
    \            xs.emplace_back(x);\r\n        }\r\n    }\r\n\r\n    auto lct = LiChaoTree(xs);\r\
    \n    for(const auto& [a, b] : v) { lct.add(a, b); }\r\n\r\n    for(const auto&\
    \ query : queries) {\r\n        if(query.k == 0) {\r\n            lct.add(query.a,\
    \ query.b);\r\n        } else {\r\n            cout << lct.query(query.a) << endl;\r\
    \n        }\r\n    }\r\n}\r\n"
  dependsOn:
  - Library/DataStructure/LiChaoTree.hpp
  isVerificationFile: true
  path: Test/DataStructure/LiChaoTree.test.cpp
  requiredBy: []
  timestamp: '2023-03-07 14:07:37+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/DataStructure/LiChaoTree.test.cpp
layout: document
redirect_from:
- /verify/Test/DataStructure/LiChaoTree.test.cpp
- /verify/Test/DataStructure/LiChaoTree.test.cpp.html
title: Test/DataStructure/LiChaoTree.test.cpp
---
