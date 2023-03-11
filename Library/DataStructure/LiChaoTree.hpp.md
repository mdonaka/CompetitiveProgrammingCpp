---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/DynamicLiChaoTree.test.cpp
    title: Test/DataStructure/DynamicLiChaoTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/LiChaoTree.test.cpp
    title: Test/DataStructure/LiChaoTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/LiChaoTree_bias.test.cpp
    title: Test/DataStructure/LiChaoTree_bias.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/DataStructure/LiChaoTree.hpp\"\n\r\n#include <limits>\r\
    \n#include <vector>\r\n#include <memory>\r\n#include <algorithm>\r\n#include <unordered_map>\r\
    \n#include <iostream>\r\n\r\nclass LiChaoTree {\r\n    using T = long long;\r\n\
    \    using Line = std::pair<T, T>;\r\n    constexpr static T INF = std::numeric_limits<\
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
    \    }\r\n        return ret;\r\n    }\r\n};\r\n\r\n// X_MAX: ax+b\u3067\u3042\
    \u308Bx\u3068\u3057\u3066\u53D6\u308A\u3046\u308B\u6700\u5927\u5024\r\ntemplate<long\
    \ long X_MAX, class T = long long>\r\nclass DynamicLiChaoTree {\r\n    constexpr\
    \ static T INF = 2e18;\r\n\r\n    class Line {\r\n        T a, b;\r\n    public:\r\
    \n        Line(const T& a, const T& b) :a(a), b(b) {}\r\n        Line() :Line(0,\
    \ INF) {}\r\n        Line(const Line& other) noexcept :Line(other.a, other.b)\
    \ {}\r\n        Line(Line&& other) noexcept :Line(other) {}\r\n        Line& operator=(Line&&\
    \ other) noexcept {\r\n            if(this != &other) { a = other.a; b = other.b;\
    \ }\r\n            return *this;\r\n        }\r\n        auto operator<(const\
    \ Line& line)const { return a < line.a; }\r\n        auto operator>(const Line&\
    \ line)const { return line.operator<(*this); }\r\n\r\n        auto f(const T&\
    \ x)const { return a * x + b; }\r\n        auto debug()const { std::cerr << \"\
    (\" << a << \" \" << b << \")\" << std::endl; }\r\n    };\r\n\r\n    struct Node\
    \ {\r\n        Line line;\r\n        std::unique_ptr<Node> left;\r\n        std::unique_ptr<Node>\
    \ right;\r\n\r\n        Node(const Line& line) :line(line) {}\r\n        auto\
    \ f(const T& x)const { return line.f(x); }\r\n    };\r\n\r\n    std::unique_ptr<Node>\
    \ m_root;\r\n\r\n    auto add(std::unique_ptr<Node>& node, Line&& line, long long\
    \ l, long long r) {\r\n        if(!node) { node = std::make_unique<Node>(line);\
    \ return; }\r\n\r\n        auto m = (l + r) / 2;\r\n        if(line.f(m) < node->f(m))\
    \ { std::swap(node->line, line); }\r\n        if(l + 1 == r) { return; }\r\n \
    \       if(line > node->line) {\r\n            add(node->left, std::move(line),\
    \ l, m);\r\n        } else if(line < node->line) {\r\n            add(node->right,\
    \ std::move(line), m, r);\r\n        }\r\n    }\r\n\r\n    auto query(const std::unique_ptr<Node>&\
    \ node, const T& x, long long l, long long r) const {\r\n        if(!node) { return\
    \ Line().f(x); }\r\n        auto m = (l + r) / 2;\r\n        return std::min(\r\
    \n            node->f(x),\r\n            (x < m) ? query(node->left, x, l, m)\
    \ : query(node->right, x, m, r)\r\n        );\r\n    }\r\npublic:\r\n    DynamicLiChaoTree()\
    \ {}\r\n\r\n    auto add(const T& a, const T& b) { add(m_root, Line(a, b), -X_MAX,\
    \ X_MAX); }\r\n    auto add(const std::pair<T, T>& line) { add(line.first, line.second);\
    \ }\r\n    auto query(const T& x) const { return query(m_root, x, -X_MAX, X_MAX);\
    \ }\r\n\r\n    auto debug(const std::unique_ptr<Node>& node, int size)const {\r\
    \n        if(size == 0) { std::cerr << \"-- li chao tree --\" << std::endl; }\r\
    \n        if(!node) { return; }\r\n        for(int i = 0; i < size; ++i) { std::cerr\
    \ << \"- \"; }\r\n        node->line.debug();\r\n        if(node->left) { std::cout\
    \ << \"L\"; debug(node->left, size + 1); }\r\n        if(node->right) { std::cout\
    \ << \"R\"; debug(node->right, size + 1); }\r\n    }\r\n    auto debug()const\
    \ { debug(m_root, 0); }\r\n};\r\n"
  code: "#pragma once\r\n\r\n#include <limits>\r\n#include <vector>\r\n#include <memory>\r\
    \n#include <algorithm>\r\n#include <unordered_map>\r\n#include <iostream>\r\n\r\
    \nclass LiChaoTree {\r\n    using T = long long;\r\n    using Line = std::pair<T,\
    \ T>;\r\n    constexpr static T INF = std::numeric_limits< T >::max() / 2;\r\n\
    \r\n    int m_size;\r\n    std::vector<T> m_x;\r\n    std::vector<Line> m_node;\r\
    \n    std::unordered_map<T, T> m_xtoi;\r\n\r\n    static inline int calcSize(int\
    \ n) { int size = 1; while(size < n) { size <<= 1; }return size; }\r\n    auto\
    \ f(const Line& line, const T& x)const { return line.first * x + line.second;\
    \ }\r\n\r\n    auto add(const Line& line_, int k, int l, int r) {\r\n        auto\
    \ line = line_;\r\n\r\n        auto m = (l + r) / 2;\r\n        if(f(line, m_x[m])\
    \ < f(m_node[k], m_x[m])) { std::swap(line, m_node[k]); }\r\n        if(l + 1\
    \ == r) { return; }\r\n        if(line.first > m_node[k].first) {\r\n        \
    \    add(line, (k << 1) + 1, l, m);\r\n        } else if(line.first < m_node[k].first)\
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
    \    }\r\n        return ret;\r\n    }\r\n};\r\n\r\n// X_MAX: ax+b\u3067\u3042\
    \u308Bx\u3068\u3057\u3066\u53D6\u308A\u3046\u308B\u6700\u5927\u5024\r\ntemplate<long\
    \ long X_MAX, class T = long long>\r\nclass DynamicLiChaoTree {\r\n    constexpr\
    \ static T INF = 2e18;\r\n\r\n    class Line {\r\n        T a, b;\r\n    public:\r\
    \n        Line(const T& a, const T& b) :a(a), b(b) {}\r\n        Line() :Line(0,\
    \ INF) {}\r\n        Line(const Line& other) noexcept :Line(other.a, other.b)\
    \ {}\r\n        Line(Line&& other) noexcept :Line(other) {}\r\n        Line& operator=(Line&&\
    \ other) noexcept {\r\n            if(this != &other) { a = other.a; b = other.b;\
    \ }\r\n            return *this;\r\n        }\r\n        auto operator<(const\
    \ Line& line)const { return a < line.a; }\r\n        auto operator>(const Line&\
    \ line)const { return line.operator<(*this); }\r\n\r\n        auto f(const T&\
    \ x)const { return a * x + b; }\r\n        auto debug()const { std::cerr << \"\
    (\" << a << \" \" << b << \")\" << std::endl; }\r\n    };\r\n\r\n    struct Node\
    \ {\r\n        Line line;\r\n        std::unique_ptr<Node> left;\r\n        std::unique_ptr<Node>\
    \ right;\r\n\r\n        Node(const Line& line) :line(line) {}\r\n        auto\
    \ f(const T& x)const { return line.f(x); }\r\n    };\r\n\r\n    std::unique_ptr<Node>\
    \ m_root;\r\n\r\n    auto add(std::unique_ptr<Node>& node, Line&& line, long long\
    \ l, long long r) {\r\n        if(!node) { node = std::make_unique<Node>(line);\
    \ return; }\r\n\r\n        auto m = (l + r) / 2;\r\n        if(line.f(m) < node->f(m))\
    \ { std::swap(node->line, line); }\r\n        if(l + 1 == r) { return; }\r\n \
    \       if(line > node->line) {\r\n            add(node->left, std::move(line),\
    \ l, m);\r\n        } else if(line < node->line) {\r\n            add(node->right,\
    \ std::move(line), m, r);\r\n        }\r\n    }\r\n\r\n    auto query(const std::unique_ptr<Node>&\
    \ node, const T& x, long long l, long long r) const {\r\n        if(!node) { return\
    \ Line().f(x); }\r\n        auto m = (l + r) / 2;\r\n        return std::min(\r\
    \n            node->f(x),\r\n            (x < m) ? query(node->left, x, l, m)\
    \ : query(node->right, x, m, r)\r\n        );\r\n    }\r\npublic:\r\n    DynamicLiChaoTree()\
    \ {}\r\n\r\n    auto add(const T& a, const T& b) { add(m_root, Line(a, b), -X_MAX,\
    \ X_MAX); }\r\n    auto add(const std::pair<T, T>& line) { add(line.first, line.second);\
    \ }\r\n    auto query(const T& x) const { return query(m_root, x, -X_MAX, X_MAX);\
    \ }\r\n\r\n    auto debug(const std::unique_ptr<Node>& node, int size)const {\r\
    \n        if(size == 0) { std::cerr << \"-- li chao tree --\" << std::endl; }\r\
    \n        if(!node) { return; }\r\n        for(int i = 0; i < size; ++i) { std::cerr\
    \ << \"- \"; }\r\n        node->line.debug();\r\n        if(node->left) { std::cout\
    \ << \"L\"; debug(node->left, size + 1); }\r\n        if(node->right) { std::cout\
    \ << \"R\"; debug(node->right, size + 1); }\r\n    }\r\n    auto debug()const\
    \ { debug(m_root, 0); }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/DataStructure/LiChaoTree.hpp
  requiredBy: []
  timestamp: '2023-03-10 17:00:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/DataStructure/LiChaoTree_bias.test.cpp
  - Test/DataStructure/DynamicLiChaoTree.test.cpp
  - Test/DataStructure/LiChaoTree.test.cpp
documentation_of: Library/DataStructure/LiChaoTree.hpp
layout: document
redirect_from:
- /library/Library/DataStructure/LiChaoTree.hpp
- /library/Library/DataStructure/LiChaoTree.hpp.html
title: Library/DataStructure/LiChaoTree.hpp
---
