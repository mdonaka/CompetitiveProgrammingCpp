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
    PROBLEM: https://yukicoder.me/problems/no/409
    links:
    - https://yukicoder.me/problems/no/409
  bundledCode: "#line 1 \"Test/DataStructure/LiChaoTree_bias.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/409\"\r\n\r\n#include <iostream>\r\n#include\
    \ <vector>\r\n#include <numeric>\r\n#line 2 \"Library/DataStructure/LiChaoTree.hpp\"\
    \n\r\n#include <limits>\r\n#line 5 \"Library/DataStructure/LiChaoTree.hpp\"\n\
    #include <memory>\r\n#include <algorithm>\r\n#include <unordered_map>\r\n#line\
    \ 9 \"Library/DataStructure/LiChaoTree.hpp\"\n\r\nclass LiChaoTree {\r\n    using\
    \ T = long long;\r\n    using Line = std::pair<T, T>;\r\n    constexpr static\
    \ T INF = std::numeric_limits< T >::max() / 2;\r\n\r\n    int m_size;\r\n    std::vector<T>\
    \ m_x;\r\n    std::vector<Line> m_node;\r\n    std::unordered_map<T, T> m_xtoi;\r\
    \n\r\n    static inline int calcSize(int n) { int size = 1; while(size < n) {\
    \ size <<= 1; }return size; }\r\n    auto f(const Line& line, const T& x)const\
    \ { return line.first * x + line.second; }\r\n\r\n    auto add(const Line& line_,\
    \ int k, int l, int r) {\r\n        auto line = line_;\r\n\r\n        auto m =\
    \ (l + r) / 2;\r\n        if(f(line, m_x[m]) < f(m_node[k], m_x[m])) { std::swap(line,\
    \ m_node[k]); }\r\n        if(l + 1 == r) { return; }\r\n        if(line.first\
    \ > m_node[k].first) {\r\n            add(line, (k << 1) + 1, l, m);\r\n     \
    \   } else if(line.first < m_node[k].first) {\r\n            add(line, (k << 1)\
    \ + 2, m, r);\r\n        }\r\n    }\r\n\r\npublic:\r\n    LiChaoTree(const std::vector<T>&\
    \ x_) :m_size(calcSize(x_.size())) {\r\n        auto x = x_;\r\n        std::sort(x.begin(),\
    \ x.end());\r\n        x.erase(std::unique(x.begin(), x.end()), x.end());\r\n\
    \        m_x = decltype(m_x)(m_size);\r\n        for(size_t i = 0; i < x.size();\
    \ ++i) {\r\n            m_x[i] = x[i];\r\n            m_xtoi.emplace(x[i], i);\r\
    \n        }\r\n        for(size_t i = x.size(); i < m_size; ++i) { m_x[i] = m_x[i\
    \ - 1] + 1; }\r\n        m_node = decltype(m_node)(m_size << 1, {0,INF});\r\n\
    \    }\r\n\r\n    auto add(const Line& line) { add(line, 0, 0, m_size); }\r\n\
    \    auto add(const T& a, const T& b) { add({a,b}); }\r\n\r\n    auto query(const\
    \ T& x) {\r\n        auto k = m_xtoi[x] + m_size;\r\n        auto ret = INF;\r\
    \n        while(k > 0) {\r\n            ret = std::min(ret, f(m_node[k - 1], x));\r\
    \n            k >>= 1;\r\n        }\r\n        return ret;\r\n    }\r\n};\r\n\r\
    \n// X_MAX: ax+b\u3067\u3042\u308Bx\u3068\u3057\u3066\u53D6\u308A\u3046\u308B\u6700\
    \u5927\u5024\r\ntemplate<long long X_MAX, class T = long long>\r\nclass DynamicLiChaoTree\
    \ {\r\n    constexpr static T INF = 2e18;\r\n\r\n    class Line {\r\n        T\
    \ a, b;\r\n    public:\r\n        Line(const T& a, const T& b) :a(a), b(b) {}\r\
    \n        Line() :Line(0, INF) {}\r\n        Line(const Line& other) noexcept\
    \ :Line(other.a, other.b) {}\r\n        Line(Line&& other) noexcept :Line(other)\
    \ {}\r\n        Line& operator=(Line&& other) noexcept {\r\n            if(this\
    \ != &other) { a = other.a; b = other.b; }\r\n            return *this;\r\n  \
    \      }\r\n        auto operator<(const Line& line)const { return a < line.a;\
    \ }\r\n        auto operator>(const Line& line)const { return line.operator<(*this);\
    \ }\r\n\r\n        auto f(const T& x)const { return a * x + b; }\r\n        auto\
    \ debug()const { std::cerr << \"(\" << a << \" \" << b << \")\" << std::endl;\
    \ }\r\n    };\r\n\r\n    struct Node {\r\n        Line line;\r\n        std::unique_ptr<Node>\
    \ left;\r\n        std::unique_ptr<Node> right;\r\n\r\n        Node(const Line&\
    \ line) :line(line) {}\r\n        auto f(const T& x)const { return line.f(x);\
    \ }\r\n    };\r\n\r\n    std::unique_ptr<Node> m_root;\r\n\r\n    auto add(std::unique_ptr<Node>&\
    \ node, Line&& line, long long l, long long r) {\r\n        if(!node) { node =\
    \ std::make_unique<Node>(line); return; }\r\n\r\n        auto m = (l + r) / 2;\r\
    \n        if(line.f(m) < node->f(m)) { std::swap(node->line, line); }\r\n    \
    \    if(l + 1 == r) { return; }\r\n        if(line > node->line) {\r\n       \
    \     add(node->left, std::move(line), l, m);\r\n        } else if(line < node->line)\
    \ {\r\n            add(node->right, std::move(line), m, r);\r\n        }\r\n \
    \   }\r\n\r\n    auto query(const std::unique_ptr<Node>& node, const T& x, long\
    \ long l, long long r) const {\r\n        if(!node) { return Line().f(x); }\r\n\
    \        auto m = (l + r) / 2;\r\n        return std::min(\r\n            node->f(x),\r\
    \n            (x < m) ? query(node->left, x, l, m) : query(node->right, x, m,\
    \ r)\r\n        );\r\n    }\r\npublic:\r\n    DynamicLiChaoTree() {}\r\n\r\n \
    \   auto add(const T& a, const T& b) { add(m_root, Line(a, b), -X_MAX, X_MAX);\
    \ }\r\n    auto add(const std::pair<T, T>& line) { add(line.first, line.second);\
    \ }\r\n    auto query(const T& x) const { return query(m_root, x, -X_MAX, X_MAX);\
    \ }\r\n\r\n    auto debug(const std::unique_ptr<Node>& node, int size)const {\r\
    \n        if(size == 0) { std::cerr << \"-- li chao tree --\" << std::endl; }\r\
    \n        if(!node) { return; }\r\n        for(int i = 0; i < size; ++i) { std::cerr\
    \ << \"- \"; }\r\n        node->line.debug();\r\n        if(node->left) { std::cout\
    \ << \"L\"; debug(node->left, size + 1); }\r\n        if(node->right) { std::cout\
    \ << \"R\"; debug(node->right, size + 1); }\r\n    }\r\n    auto debug()const\
    \ { debug(m_root, 0); }\r\n};\r\n#line 7 \"Test/DataStructure/LiChaoTree_bias.test.cpp\"\
    \n\r\nusing ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr\
    \ char endl = '\\n';\r\n\r\n\r\nsigned main() {\r\n    ll n, a, b, w;\r\n    cin\
    \ >> n >> a >> b >> w;\r\n    std::vector<ll> d; d.reserve(n);\r\n    for(int\
    \ i = 0; i < n; ++i) {\r\n        ll x; cin >> x;\r\n        d.emplace_back(x);\r\
    \n    }\r\n\r\n    std::vector<ll> xs(n);\r\n    std::iota(xs.begin(), xs.end(),\
    \ 1);\r\n    LiChaoTree lct(xs);\r\n\r\n    constexpr ll mx = 1e18;\r\n    std::vector<ll>\
    \ dp(n + 1, mx);\r\n    auto update = [&](ll i, ll x) {\r\n        dp[i] = x;\r\
    \n        auto pa = -b * i;\r\n        auto pb = a * i + i * (i + 1) / 2 * b +\
    \ dp[i];\r\n        lct.add(pa, pb);\r\n    };\r\n\r\n    update(0, w);\r\n  \
    \  for(ll i = 1; i < n + 1; ++i) {\r\n        auto ad = d[i - 1] - a * i + a +\
    \ i * (i - 1) / 2 * b;\r\n        auto min = lct.query(i);\r\n        update(i,\
    \ ad + min);\r\n    }\r\n\r\n    ll ans = dp[n];\r\n    for(ll i = 0; i < n; ++i)\
    \ {\r\n        ll k = n - i;\r\n        ans = std::min(ans, dp[i] + -a * k + k\
    \ * (k + 1) / 2 * b);\r\n    }\r\n\r\n    cout << ans << endl;\r\n}\r\n\r\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/409\"\r\n\r\n#include\
    \ <iostream>\r\n#include <vector>\r\n#include <numeric>\r\n#include \"./../../Library/DataStructure/LiChaoTree.hpp\"\
    \r\n\r\nusing ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr\
    \ char endl = '\\n';\r\n\r\n\r\nsigned main() {\r\n    ll n, a, b, w;\r\n    cin\
    \ >> n >> a >> b >> w;\r\n    std::vector<ll> d; d.reserve(n);\r\n    for(int\
    \ i = 0; i < n; ++i) {\r\n        ll x; cin >> x;\r\n        d.emplace_back(x);\r\
    \n    }\r\n\r\n    std::vector<ll> xs(n);\r\n    std::iota(xs.begin(), xs.end(),\
    \ 1);\r\n    LiChaoTree lct(xs);\r\n\r\n    constexpr ll mx = 1e18;\r\n    std::vector<ll>\
    \ dp(n + 1, mx);\r\n    auto update = [&](ll i, ll x) {\r\n        dp[i] = x;\r\
    \n        auto pa = -b * i;\r\n        auto pb = a * i + i * (i + 1) / 2 * b +\
    \ dp[i];\r\n        lct.add(pa, pb);\r\n    };\r\n\r\n    update(0, w);\r\n  \
    \  for(ll i = 1; i < n + 1; ++i) {\r\n        auto ad = d[i - 1] - a * i + a +\
    \ i * (i - 1) / 2 * b;\r\n        auto min = lct.query(i);\r\n        update(i,\
    \ ad + min);\r\n    }\r\n\r\n    ll ans = dp[n];\r\n    for(ll i = 0; i < n; ++i)\
    \ {\r\n        ll k = n - i;\r\n        ans = std::min(ans, dp[i] + -a * k + k\
    \ * (k + 1) / 2 * b);\r\n    }\r\n\r\n    cout << ans << endl;\r\n}\r\n\r\n"
  dependsOn:
  - Library/DataStructure/LiChaoTree.hpp
  isVerificationFile: true
  path: Test/DataStructure/LiChaoTree_bias.test.cpp
  requiredBy: []
  timestamp: '2023-03-10 17:00:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/DataStructure/LiChaoTree_bias.test.cpp
layout: document
redirect_from:
- /verify/Test/DataStructure/LiChaoTree_bias.test.cpp
- /verify/Test/DataStructure/LiChaoTree_bias.test.cpp.html
title: Test/DataStructure/LiChaoTree_bias.test.cpp
---
