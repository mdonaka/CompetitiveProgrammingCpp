---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Library/Container/SegmentMap.hpp
    title: Library/Container/SegmentMap.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/674
    links:
    - https://yukicoder.me/problems/no/674
  bundledCode: "#line 1 \"Test/Container/SegmentMap.test.cpp\"\n#define PROBLEM \"\
    https://yukicoder.me/problems/no/674\"\r\n\r\n#include <iostream>\r\n#line 3 \"\
    Library/Container/SegmentMap.hpp\"\n#include <map>\r\n#include <stdexcept>\r\n\
    #include <deque>\r\n\r\n\r\ntemplate<class ValType = long long, class SizeType\
    \ = long long>\r\nclass SegmentMap {\r\n\r\n    const SizeType n;\r\n    std::map<SizeType,\
    \ ValType> mp;\r\n\r\n    auto add(SizeType i, ValType val, bool left = true,\
    \ bool right = true) {\r\n        auto it = std::prev(mp.upper_bound(i));\r\n\
    \        if(right && std::next(it)->second == val) { mp.erase(std::next(it));\
    \ }\r\n        if(left && it->second == val) { return; }\r\n        mp.emplace(i,\
    \ val);\r\n\r\n    }\r\n\r\n    auto remove(SizeType l, SizeType r, auto& it)\
    \ {\r\n        auto nx = std::next(it)->first;\r\n        auto val = it->second;\r\
    \n        auto ret = std::next(it);\r\n        if(l <= it->first) { ret = mp.erase(it);\
    \ }\r\n        if(r < nx - 1) { add(r + 1, val, false, true); }\r\n        return\
    \ ret;\r\n    }\r\n\r\n    auto remove(SizeType l, SizeType r) {\r\n        auto\
    \ it = std::prev(mp.upper_bound(l));\r\n        while(it->first <= r) {\r\n  \
    \          it = remove(l, r, it);\r\n        }\r\n    }\r\n\r\n\r\npublic:\r\n\
    \r\n    SegmentMap(SizeType n) :n(n) {\r\n        mp.emplace(-1, -1);\r\n    \
    \    mp.emplace(0, -2);\r\n        mp.emplace(n, -1);\r\n    }\r\n\r\n    auto\
    \ output() const {\r\n        for(auto it = std::next(mp.begin()); it != std::prev(mp.end());\
    \ ++it) {\r\n            std::cout << \"[\" << it->first << \", \" <<\r\n    \
    \            std::next(it)->first - 1 << \"] :\" <<\r\n                it->second\
    \ << std::endl;\r\n        }\r\n    }\r\n\r\n    auto update(SizeType l, SizeType\
    \ r, ValType val) {\r\n        if(l < 0 || r >= n) { throw std::runtime_error(\"\
    \"); }\r\n        if(l > r) { throw std::runtime_error(\"\"); }\r\n        remove(l,\
    \ r);\r\n        add(l, val);\r\n    }\r\n\r\n    auto query(SizeType l, SizeType\
    \ r) {\r\n        if(l < 0 || r >= n) { throw std::runtime_error(\"\"); }\r\n\
    \        if(l > r) { throw std::runtime_error(\"\"); }\r\n        auto it = std::prev(mp.upper_bound(l));\r\
    \n        std::deque<std::pair<ValType, std::pair<SizeType, SizeType>>> dq;\r\n\
    \        while(it->first <= r) {\r\n            auto nx = std::next(it)->first;\r\
    \n            auto nr = std::min(nx - 1, r);\r\n            auto nl = std::max(l,\
    \ it->first);\r\n            dq.emplace_back(it->second, std::pair{nl,nr});\r\n\
    \            ++it;\r\n        }\r\n        return dq;\r\n    }\r\n\r\n    auto\
    \ get(SizeType i) {\r\n        auto it = std::prev(mp.upper_bound(i));\r\n   \
    \     auto nx = std::next(it)->first;\r\n        auto nr = nx - 1;\r\n       \
    \ auto nl = it->first;\r\n        return std::pair{it->second,std::pair{nl,nr}};\r\
    \n    }\r\n};\r\n#line 5 \"Test/Container/SegmentMap.test.cpp\"\n\r\nusing ll\
    \ = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr char endl =\
    \ '\\n';\r\n\r\nsigned main() {\r\n    ll d, q;\r\n    cin >> d >> q;\r\n\r\n\
    \    auto segmap = SegmentMap(d);\r\n\r\n    ll ans = 0;\r\n    for(int _ = 0;\
    \ _ < q; ++_) {\r\n        ll a, b;\r\n        cin >> a >> b;\r\n        segmap.update(a,\
    \ b, 1);\r\n\r\n        auto [__, range] = segmap.get(a);\r\n        ans = std::max(ans,\
    \ range.second - range.first + 1);\r\n        cout << ans << endl;\r\n    }\r\n\
    }\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/674\"\r\n\r\n#include\
    \ <iostream>\r\n#include \"./../../Library/Container/SegmentMap.hpp\"\r\n\r\n\
    using ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr char\
    \ endl = '\\n';\r\n\r\nsigned main() {\r\n    ll d, q;\r\n    cin >> d >> q;\r\
    \n\r\n    auto segmap = SegmentMap(d);\r\n\r\n    ll ans = 0;\r\n    for(int _\
    \ = 0; _ < q; ++_) {\r\n        ll a, b;\r\n        cin >> a >> b;\r\n       \
    \ segmap.update(a, b, 1);\r\n\r\n        auto [__, range] = segmap.get(a);\r\n\
    \        ans = std::max(ans, range.second - range.first + 1);\r\n        cout\
    \ << ans << endl;\r\n    }\r\n}"
  dependsOn:
  - Library/Container/SegmentMap.hpp
  isVerificationFile: true
  path: Test/Container/SegmentMap.test.cpp
  requiredBy: []
  timestamp: '2022-09-04 13:08:59+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/Container/SegmentMap.test.cpp
layout: document
redirect_from:
- /verify/Test/Container/SegmentMap.test.cpp
- /verify/Test/Container/SegmentMap.test.cpp.html
title: Test/Container/SegmentMap.test.cpp
---
