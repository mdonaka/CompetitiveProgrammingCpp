---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/LiChaoTree.hpp
    title: Library/DataStructure/LiChaoTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"Test/DataStructure/LiChaoTree.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/line_add_get_min\"\r\n\r\n#include <iostream>\r\
    \n#include <vector>\r\n#include <deque>\r\n\r\n#line 2 \"Library/DataStructure/LiChaoTree.hpp\"\
    \n\r\n#include <limits>\r\n#line 5 \"Library/DataStructure/LiChaoTree.hpp\"\n\
    #include <memory>\r\n#include <algorithm>\r\n#include <unordered_map>\r\n#line\
    \ 9 \"Library/DataStructure/LiChaoTree.hpp\"\n\r\n/*\r\n * \u30AF\u30A8\u30EA\u5148\
    \u8AAD\u307F\u304C\u5FC5\u8981\r\n * \u30AF\u30A8\u30EA\u3067\u547C\u3070\u308C\
    \u308Bx\u3068\u7DDA\u5206\u306E\u7AEF\u70B9\u3092\u5168\u3066\u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF\u306B\u6E21\u3059\r\n */\r\nclass LiChaoTree {\r\n  \
    \  using T = long long;\r\n    using Line = std::pair<T, T>;\r\n    constexpr\
    \ static T INF = std::numeric_limits< T >::max() / 2;\r\n\r\n    int m_size;\r\
    \n    std::vector<T> m_x;\r\n    std::vector<Line> m_node;\r\n    std::unordered_map<T,\
    \ T> m_xtoi;\r\n\r\n    static inline int calcSize(int n) { int size = 1; while(size\
    \ < n) { size <<= 1; }return size; }\r\n    auto f(const Line& line, const T&\
    \ x)const { return line.first * x + line.second; }\r\n\r\n    auto addLine(const\
    \ Line& line_, int k, int l, int r) {\r\n        auto line = line_;\r\n\r\n  \
    \      auto m = (l + r) / 2;\r\n        if(f(line, m_x[m]) < f(m_node[k], m_x[m]))\
    \ { std::swap(line, m_node[k]); }\r\n        if(l + 1 == r) { return; }\r\n  \
    \      if(line.first > m_node[k].first) {\r\n            addLine(line, (k << 1)\
    \ + 1, l, m);\r\n        } else if(line.first < m_node[k].first) {\r\n       \
    \     addLine(line, (k << 1) + 2, m, r);\r\n        }\r\n    }\r\n\r\npublic:\r\
    \n    LiChaoTree(const std::vector<T>& x_) :m_size(calcSize(x_.size())) {\r\n\
    \        auto x = x_;\r\n        std::sort(x.begin(), x.end());\r\n        x.erase(std::unique(x.begin(),\
    \ x.end()), x.end());\r\n        m_x = decltype(m_x)(m_size);\r\n        for(size_t\
    \ i = 0; i < x.size(); ++i) {\r\n            m_x[i] = x[i];\r\n            m_xtoi.emplace(x[i],\
    \ i);\r\n        }\r\n        for(size_t i = x.size(); i < m_size; ++i) { m_x[i]\
    \ = m_x[i - 1] + 1; }\r\n        m_node = decltype(m_node)(m_size << 1, {0,INF});\r\
    \n    }\r\n\r\n    auto addLine(const Line& line) { addLine(line, 0, 0, m_size);\
    \ }\r\n    auto addLine(const T& a, const T& b) { addLine({a,b}); }\r\n    auto\
    \ addSegment(const Line& line, const T& l_, const T& r_) {\r\n        auto l =\
    \ m_xtoi[l_], r = m_xtoi[r_];\r\n        auto lk = l + m_size - 1;\r\n       \
    \ auto rk = r + m_size - 1;\r\n        auto len = 1;\r\n        while(lk <= rk)\
    \ {\r\n            if(!(lk & 1)) {\r\n                addLine(line, lk, l, l +\
    \ len);\r\n                l += len;\r\n                ++lk;\r\n            }\r\
    \n            if(rk & 1) {\r\n                r -= len;\r\n                addLine(line,\
    \ rk, r + 1, r + len + 1);\r\n                --rk;\r\n            }\r\n     \
    \       lk = (lk - 1) >> 1;\r\n            rk = (rk - 1) >> 1;\r\n           \
    \ len <<= 1;\r\n        }\r\n    }\r\n    auto addSegment(const T& a, const T&\
    \ b, const T& l, const T& r) { addSegment({a,b}, l, r); }\r\n\r\n    auto query(const\
    \ T& x) {\r\n        auto k = m_xtoi[x] + m_size;\r\n        auto ret = INF;\r\
    \n        while(k > 0) {\r\n            ret = std::min(ret, f(m_node[k - 1], x));\r\
    \n            k >>= 1;\r\n        }\r\n        return ret;\r\n    }\r\n\r\n  \
    \  auto debug()const {\r\n        std::cerr << \"-- Li Chao Tree --\" << std::endl;\r\
    \n        for(unsigned int i = 0; i < m_node.size(); ++i) {\r\n            std::cerr\
    \ << i << \": (\" << m_node[i].first\r\n                << \" \" << m_node[i].second\
    \ << \")\" << std::endl;\r\n        }\r\n    }\r\n};\r\n\r\n/*\r\n * \u30AF\u30A8\
    \u30EA\u5148\u8AAD\u307F\u304C\u4E0D\u8981\u306ALiChaoTree\r\n * \u7DDA\u5206\u8FFD\
    \u52A0\u306F\u975E\u5E38\u306B\u9045\u3044\u305F\u3081\u975E\u63A8\u5968\r\n *\
    \ \r\n * X_MAX: ax+b\u3067\u3042\u308Bx\u3068\u3057\u3066\u53D6\u308A\u3046\u308B\
    \u6700\u5927\u5024\r\n */\r\ntemplate<long long X_MAX, class T = long long>\r\n\
    class DynamicLiChaoTree {\r\n    constexpr static T INF = 2e18;\r\n\r\n    class\
    \ Line {\r\n        T a, b;\r\n    public:\r\n        Line(const T& a, const T&\
    \ b) :a(a), b(b) {}\r\n        Line() :Line(0, INF) {}\r\n        Line(const Line&\
    \ other) noexcept :Line(other.a, other.b) {}\r\n        Line(Line&& other) noexcept\
    \ :Line(other) {}\r\n        Line& operator=(Line&& other) noexcept {\r\n    \
    \        if(this != &other) { a = other.a; b = other.b; }\r\n            return\
    \ *this;\r\n        }\r\n        auto operator<(const Line& line)const { return\
    \ a < line.a; }\r\n        auto operator>(const Line& line)const { return line.operator<(*this);\
    \ }\r\n\r\n        auto f(const T& x)const { return a * x + b; }\r\n        auto\
    \ debug()const {\r\n            if(b == INF) {\r\n                std::cerr <<\
    \ \"(\" << a << \" inf)\" << std::endl;\r\n            } else {\r\n          \
    \      std::cerr << \"(\" << a << \" \" << b << \")\" << std::endl;\r\n      \
    \      }\r\n        }\r\n    };\r\n\r\n    struct Node {\r\n        Line line;\r\
    \n        std::unique_ptr<Node> left;\r\n        std::unique_ptr<Node> right;\r\
    \n\r\n        Node(const Line& line) :line(line) {}\r\n        auto f(const T&\
    \ x)const { return line.f(x); }\r\n    };\r\n\r\n    std::unique_ptr<Node> m_root;\r\
    \n\r\n    auto addLine(std::unique_ptr<Node>& node, Line&& line, long long l,\
    \ long long r) {\r\n        if(!node) { node = std::make_unique<Node>(line); return;\
    \ }\r\n\r\n        auto m = (l + 1 == r) ? l : (l + r) / 2;\r\n        if(line.f(m)\
    \ < node->f(m)) { std::swap(node->line, line); }\r\n        if(l + 1 == r) { return;\
    \ }\r\n        if(line > node->line) {\r\n            addLine(node->left, std::move(line),\
    \ l, m);\r\n        } else if(line < node->line) {\r\n            addLine(node->right,\
    \ std::move(line), m, r);\r\n        }\r\n    }\r\n    auto addSegment(std::unique_ptr<Node>&\
    \ node, const Line& line, T l, T r, T sl, T sr) {\r\n        if(sr <= l || r <=\
    \ sl) { return; }\r\n        if(l <= sl && sr <= r) { addLine(node, Line(line),\
    \ sl, sr); return; }\r\n        auto m = (sl + sr) / 2;\r\n        if(!node) {\
    \ node = std::make_unique<Node>(Line()); }\r\n        addSegment(node->left, line,\
    \ l, r, sl, m);\r\n        addSegment(node->right, line, l, r, m, sr);\r\n   \
    \ }\r\n\r\n    auto query(const std::unique_ptr<Node>& node, const T& x, long\
    \ long l, long long r) const {\r\n        if(!node) { return Line().f(x); }\r\n\
    \        auto m = (l + r) / 2;\r\n        return std::min(\r\n            node->f(x),\r\
    \n            (x < m) ? query(node->left, x, l, m) : query(node->right, x, m,\
    \ r)\r\n        );\r\n    }\r\npublic:\r\n    DynamicLiChaoTree() {}\r\n\r\n \
    \   auto addLine(const T& a, const T& b) { addLine(m_root, Line(a, b), -X_MAX,\
    \ X_MAX + 1); }\r\n    auto addLine(const std::pair<T, T>& line) { addLine(line.first,\
    \ line.second); }\r\n    [[deprecated(\"This method is too slow. Please use LiChaoTree\
    \ and not DynamicLiChaoTree.\")]]\r\n    auto addSegment(const T& a, const T&\
    \ b, const T& l, const T& r) { addSegment(m_root, Line(a, b), l, r + 1, -X_MAX,\
    \ X_MAX + 1); }\r\n    auto addSegment(const std::pair<T, T>& line, const T& l,\
    \ const T& r) { addSegment(line.first, line.second, l, r); }\r\n    auto query(const\
    \ T& x) const { return query(m_root, x, -X_MAX, X_MAX + 1); }\r\n\r\n    auto\
    \ debug(const std::unique_ptr<Node>& node, int size)const {\r\n        if(size\
    \ == 0) { std::cerr << \"-- li chao tree --\" << std::endl; }\r\n        if(!node)\
    \ { return; }\r\n        for(int i = 0; i < size; ++i) { std::cerr << \"- \";\
    \ }\r\n        node->line.debug();\r\n        if(node->left) { std::cout << \"\
    L\"; debug(node->left, size + 1); }\r\n        if(node->right) { std::cout <<\
    \ \"R\"; debug(node->right, size + 1); }\r\n    }\r\n    auto debug()const { debug(m_root,\
    \ 0); }\r\n};\r\n#line 8 \"Test/DataStructure/LiChaoTree.test.cpp\"\n\r\nusing\
    \ ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr char endl\
    \ = '\\n';\r\n\r\nstruct Query {\r\n    int k;\r\n    ll a, b;\r\n    Query(int\
    \ k, ll a, ll b) :k(k), a(a), b(b) {}\r\n    Query(int k, ll x) :Query(k, x, 0)\
    \ {}\r\n};\r\n\r\nsigned main() {\r\n    ll n, q;\r\n    cin >> n >> q;\r\n  \
    \  std::vector<std::pair<ll, ll>> v; v.reserve(n);\r\n    for(int _ = 0; _ < n;\
    \ ++_) {\r\n        ll a, b;\r\n        cin >> a >> b;\r\n        v.emplace_back(a,\
    \ b);\r\n    }\r\n    std::vector<Query> queries; queries.reserve(q);\r\n    std::vector<ll>\
    \ xs; xs.reserve(q);\r\n    for(int _ = 0; _ < q; ++_) {\r\n        ll k;\r\n\
    \        cin >> k;\r\n        if(k == 0) {\r\n            ll a, b;\r\n       \
    \     cin >> a >> b;\r\n            queries.emplace_back(k, a, b);\r\n       \
    \ } else {\r\n            ll x;\r\n            cin >> x;\r\n            queries.emplace_back(k,\
    \ x);\r\n            xs.emplace_back(x);\r\n        }\r\n    }\r\n\r\n    auto\
    \ lct = LiChaoTree(xs);\r\n    for(const auto& [a, b] : v) { lct.addLine(a, b);\
    \ }\r\n\r\n    for(const auto& query : queries) {\r\n        if(query.k == 0)\
    \ {\r\n            lct.addLine(query.a, query.b);\r\n        } else {\r\n    \
    \        cout << lct.query(query.a) << endl;\r\n        }\r\n    }\r\n}\r\n"
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
    \n    for(const auto& [a, b] : v) { lct.addLine(a, b); }\r\n\r\n    for(const\
    \ auto& query : queries) {\r\n        if(query.k == 0) {\r\n            lct.addLine(query.a,\
    \ query.b);\r\n        } else {\r\n            cout << lct.query(query.a) << endl;\r\
    \n        }\r\n    }\r\n}\r\n"
  dependsOn:
  - Library/DataStructure/LiChaoTree.hpp
  isVerificationFile: true
  path: Test/DataStructure/LiChaoTree.test.cpp
  requiredBy: []
  timestamp: '2023-04-13 03:52:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/DataStructure/LiChaoTree.test.cpp
layout: document
redirect_from:
- /verify/Test/DataStructure/LiChaoTree.test.cpp
- /verify/Test/DataStructure/LiChaoTree.test.cpp.html
title: Test/DataStructure/LiChaoTree.test.cpp
---
