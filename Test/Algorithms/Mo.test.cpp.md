---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Algorithms/Mo.hpp
    title: Library/Algorithms/Mo.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1471
    links:
    - https://yukicoder.me/problems/no/1471
  bundledCode: "#line 1 \"Test/Algorithms/Mo.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/1471\"\
    \r\n\r\n#include <iostream>\r\n#include <map>\r\n\r\n#line 2 \"Library/Algorithms/Mo.hpp\"\
    \n#include <vector>\r\n#include <algorithm>\r\n#include <cmath>\r\n#include <numeric>\r\
    \n\r\nclass Mo {\r\n\r\n    const int q;\r\n    const std::vector<int> lq;\r\n\
    \    const std::vector<int> rq;\r\n    const std::vector<int> order;\r\n    int\
    \ ni, nl, nr;\r\n\r\n    auto sort_query() const {\r\n        std::vector<int>\
    \ order(q);\r\n        std::iota(order.begin(), order.end(), 0);\r\n        int\
    \ w = std::sqrt(q);\r\n        std::sort(order.begin(), order.end(), [&](int a,\
    \ int b) {\r\n            if(lq[a] / w != lq[b] / w) return lq[a] < lq[b];\r\n\
    \            if(rq[a] == rq[b]) { return false; }\r\n            bool less = (rq[a]\
    \ < rq[b]);\r\n            bool flg = (lq[a] / w) & 1;\r\n            return static_cast<bool>(less\
    \ ^ flg);\r\n        });\r\n\r\n        return order;\r\n    }\r\n\r\npublic:\r\
    \n    Mo(int q,\r\n       const std::vector<int>& lq,\r\n       const std::vector<int>&\
    \ rq)\r\n        :q(q), lq(lq), rq(rq), order(sort_query()),\r\n        ni(0),\
    \ nl(0), nr(-1) {\r\n    }\r\n\r\n    template<class Lambda1, class Lambda2>\r\
    \n    auto process(const Lambda1& add, const Lambda2& del) {\r\n        const\
    \ auto l = lq[order[ni]];\r\n        const auto r = rq[order[ni]];\r\n       \
    \ while(nl > l) { add(--nl); }\r\n        while(nr < r) { add(++nr); }\r\n   \
    \     while(nl < l) { del(nl++); }\r\n        while(nr > r) { del(nr--); }\r\n\
    \        return order[ni++];\r\n    }\r\n};\n#line 7 \"Test/Algorithms/Mo.test.cpp\"\
    \n\r\nusing ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr\
    \ char endl = '\\n';\r\n\r\nsigned main() {\r\n    int n, q;\r\n    cin >> n >>\
    \ q;\r\n    std::string s;\r\n    cin >> s;\r\n\r\n    std::vector<int> lq; lq.reserve(q);\r\
    \n    std::vector<int> rq; rq.reserve(q);\r\n    std::vector<int> xv; xv.reserve(q);\r\
    \n    for(int _ = 0; _ < q; ++_) {\r\n        int l, r, x;\r\n        cin >> l\
    \ >> r >> x;\r\n        --l; --r;\r\n        lq.emplace_back(l);\r\n        rq.emplace_back(r);\r\
    \n        xv.emplace_back(x);\r\n    }\r\n\r\n    auto mo = Mo(q, lq, rq);\r\n\
    \r\n    std::map<char, int> mp;\r\n    std::vector<char> ans(q);\r\n    for(int\
    \ _ = 0; _ < q; ++_) {\r\n        auto i = mo.process([&](int i) {\r\n       \
    \     mp[s[i]]++;\r\n        }, [&](int i) {\r\n            mp[s[i]]--;\r\n  \
    \      });\r\n\r\n        int cnt = 0;\r\n        for(const auto& [c, x] : mp)\
    \ {\r\n            cnt += x;\r\n            if(cnt >= xv[i]) { ans[i] = c; break;\
    \ }\r\n        }\r\n    }\r\n\r\n    for(const auto& c : ans) { cout << c << endl;\
    \ }\r\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1471\"\r\n\r\n#include\
    \ <iostream>\r\n#include <map>\r\n\r\n#include \"./../../Library/Algorithms/Mo.hpp\"\
    \r\n\r\nusing ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr\
    \ char endl = '\\n';\r\n\r\nsigned main() {\r\n    int n, q;\r\n    cin >> n >>\
    \ q;\r\n    std::string s;\r\n    cin >> s;\r\n\r\n    std::vector<int> lq; lq.reserve(q);\r\
    \n    std::vector<int> rq; rq.reserve(q);\r\n    std::vector<int> xv; xv.reserve(q);\r\
    \n    for(int _ = 0; _ < q; ++_) {\r\n        int l, r, x;\r\n        cin >> l\
    \ >> r >> x;\r\n        --l; --r;\r\n        lq.emplace_back(l);\r\n        rq.emplace_back(r);\r\
    \n        xv.emplace_back(x);\r\n    }\r\n\r\n    auto mo = Mo(q, lq, rq);\r\n\
    \r\n    std::map<char, int> mp;\r\n    std::vector<char> ans(q);\r\n    for(int\
    \ _ = 0; _ < q; ++_) {\r\n        auto i = mo.process([&](int i) {\r\n       \
    \     mp[s[i]]++;\r\n        }, [&](int i) {\r\n            mp[s[i]]--;\r\n  \
    \      });\r\n\r\n        int cnt = 0;\r\n        for(const auto& [c, x] : mp)\
    \ {\r\n            cnt += x;\r\n            if(cnt >= xv[i]) { ans[i] = c; break;\
    \ }\r\n        }\r\n    }\r\n\r\n    for(const auto& c : ans) { cout << c << endl;\
    \ }\r\n}"
  dependsOn:
  - Library/Algorithms/Mo.hpp
  isVerificationFile: true
  path: Test/Algorithms/Mo.test.cpp
  requiredBy: []
  timestamp: '2022-08-31 02:12:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Algorithms/Mo.test.cpp
layout: document
redirect_from:
- /verify/Test/Algorithms/Mo.test.cpp
- /verify/Test/Algorithms/Mo.test.cpp.html
title: Test/Algorithms/Mo.test.cpp
---
