---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/String/PalindromicTree.hpp
    title: Library/String/PalindromicTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/273
    links:
    - https://yukicoder.me/problems/no/273
  bundledCode: "#line 1 \"Test/String/PalindromicTree.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/273\"\r\n\r\n#line 2 \"Library/String/PalindromicTree.hpp\"\
    \n#include <iostream>\r\n#include <list>\r\n#include <memory>\r\n#include <queue>\r\
    \n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\n#include\
    \ <vector>\r\n\r\nnamespace mtd {\r\n  auto nullLambda = [](int, const std::list<int>&)\
    \ {};\r\n  class PalindromicTree {\r\n    // static constexpr auto nullLambda\
    \ = [](int, const std::list<int>&) {};//\r\n    // c++17\r\n\r\n    class Node\
    \ : public std::enable_shared_from_this<Node> {\r\n      // \u56DE\u6587\u306E\
    \u53F3\u7AEFitr\r\n      std::list<int> m_itrs;\r\n      // \u56DE\u6587\u30B5\
    \u30A4\u30BA\r\n      const int m_size;\r\n\r\n      // \u6700\u5927\u306E\u56DE\
    \u6587\u63A5\u5C3E\u8F9E\r\n      std::weak_ptr<Node> m_suffixLink;\r\n      //\
    \ \u6B21\u30B5\u30A4\u30BA\u306E\u56DE\u6587(\u56F2\u3080\u6587\u5B57, \u6B21\u306E\
    Node)\r\n      std::unordered_map<char, std::shared_ptr<Node>> m_edges;\r\n\r\n\
    \      // xAx\u3068\u306A\u308BA\u3092\u63A2\u3059(x=str[itr])\r\n      auto find(int\
    \ itr, const std::string& s) {\r\n        auto p = this->weak_from_this();\r\n\
    \        while (true) {\r\n          auto size = p.lock()->m_size;\r\n       \
    \   // root\u306B\u305F\u3069\u308A\u7740\u3044\u305F\r\n          if (size ==\
    \ -1) { return p; }\r\n          // \u73FE\u5728\u5730\"A\"\u306B\u304A\u3044\u3066\
    \"xAx\"\u3068\u306A\u308B\r\n          if (itr - size - 1 >= 0 && s[itr] == s[itr\
    \ - size - 1]) { return p; }\r\n          p = p.lock()->m_suffixLink;\r\n    \
    \    }\r\n      }\r\n\r\n      // \u65B0\u3057\u3044\u56DE\u6587Node\u3092\u4F5C\
    \u6210\u3059\u308B\r\n      auto create(int itr, const std::string& s) {\r\n \
    \       // suffixLink\u306E\u63A2\u7D22\r\n        auto suffixLinkFrom =\r\n \
    \           m_suffixLink.lock() /*->m_suffixLink.lock()*/->find(itr, s).lock();\r\
    \n        // \u65B0Node\u306E\u4F5C\u6210\r\n        auto newNode = std::make_shared<Node>(\r\
    \n            m_size + 2, (suffixLinkFrom->m_edges.find(s[itr]) ==\r\n       \
    \                  suffixLinkFrom->m_edges.end())\r\n                        \
    \    ? suffixLinkFrom->m_edges.find(' ')->second\r\n                         \
    \   : suffixLinkFrom->m_edges.find(s[itr])->second);\r\n        m_edges.emplace(s[itr],\
    \ newNode);\r\n        return std::weak_ptr<Node>(newNode);\r\n      }\r\n\r\n\
    \    public:\r\n      // constructor\r\n      Node(int size, const std::weak_ptr<Node>&\
    \ suffixLink)\r\n          : m_size(size), m_suffixLink(suffixLink) {}\r\n   \
    \   Node() : m_size(-1) {}\r\n\r\n      // \u6B21\u30B5\u30A4\u30BA\u306E\u56DE\
    \u6587\u3092\u8FFD\u52A0\r\n      auto add(int itr, const std::string& s) {\r\n\
    \        auto addRoot = find(itr, s).lock();\r\n        auto nextNode =\r\n  \
    \          (addRoot->m_edges.find(s[itr]) == addRoot->m_edges.end())\r\n     \
    \           ? addRoot->create(itr, s)\r\n                : std::weak_ptr<Node>(addRoot->m_edges.find(s[itr])->second);\r\
    \n        nextNode.lock()->m_itrs.emplace_back(itr);\r\n        return nextNode;\r\
    \n      }\r\n\r\n      // debug\u7528\r\n      auto outputTree(const std::string&\
    \ s) const -> void {\r\n        if (m_size <= 0) {\r\n          std::cerr << \"\
    root\";\r\n        } else {\r\n          // \u6BB5\r\n          for (int i = 0;\
    \ (i < (m_size + 1) / 2); ++i) { std::cerr << \" |\"; }\r\n          std::cerr\
    \ << \"- \" << s.substr(*m_itrs.begin() - m_size + 1, m_size);\r\n          //\
    \ \u53F3itr\r\n          std::cerr << \" [ \";\r\n          for (const auto& itr\
    \ : m_itrs) { std::cerr << itr << \" \"; }\r\n          std::cerr << \"] \";\r\
    \n          // suffix link\r\n          // auto p = m_suffixLink.lock();\r\n \
    \         // std::cerr << \"{\" << s.substr(*p->m_itrs.begin() - p->m_size + 1,\r\
    \n          // p->m_size) << \"} \";\r\n        }\r\n        std::cerr << \"\\\
    n\";\r\n        for (const auto& edge : m_edges) {\r\n          if (m_size ==\
    \ -1 && edge.first == ' ') { continue; }\r\n          edge.second->outputTree(s);\r\
    \n        }\r\n      }\r\n\r\n      // root\u3092\u6C7A\u5B9A\r\n      auto isOddRoot(const\
    \ std::weak_ptr<Node>& evenRoot) {\r\n        m_suffixLink = weak_from_this();\r\
    \n        m_edges.emplace(' ', evenRoot);\r\n      }\r\n\r\n      // \u30E9\u30E0\
    \u30C0\u5F0F\u306E\u5B9F\u884C\r\n      template <class Lambda>\r\n      auto\
    \ runLambda(const Lambda& lambda) {\r\n        if (m_size > 0) { lambda(m_size,\
    \ m_itrs); }\r\n      }\r\n\r\n      /*\r\n       * lambda: (int size, list<int>\
    \ rItr) -> void\r\n       */\r\n      template <class Lambda, class SuffixLinkLambda\
    \ = decltype(nullLambda)>\r\n      auto dfs_edges(const Lambda& lambda,\r\n  \
    \                   const SuffixLinkLambda& slLambda = nullLambda) -> void {\r\
    \n        std::stack<std::shared_ptr<Node>, std::vector<std::shared_ptr<Node>>>\r\
    \n            stk;\r\n        stk.emplace(this->weak_from_this().lock());\r\n\
    \        while (!stk.empty()) {\r\n          auto p = stk.top();\r\n         \
    \ stk.pop();\r\n          p->runLambda(lambda);\r\n          p->m_suffixLink.lock()->runLambda(slLambda);\r\
    \n          for (const auto& [_, next_p] : p->m_edges) {\r\n            // std::cerr\
    \ << p->m_size << \" -> \" << next_p->m_size << std::endl;\r\n            stk.emplace(next_p);\r\
    \n          }\r\n        }\r\n      }\r\n    };\r\n\r\n    // \u5BFE\u8C61\u3068\
    \u306A\u308B\u6587\u5B57\u5217\r\n    const std::string m_s;\r\n\r\n    // \u5076\
    \u6570\u9577\uFF0C\u5947\u6570\u9577\u306EPalindromicTree\u306E\u6839(0, -1)\r\
    \n    std::shared_ptr<Node> m_rootOdd;\r\n    std::shared_ptr<Node> m_rootEven;\r\
    \n\r\n  public:\r\n    // constructor\r\n    PalindromicTree(const std::string&\
    \ s)\r\n        : m_s(s),\r\n          m_rootOdd(std::make_shared<Node>()),\r\n\
    \          m_rootEven(std::make_shared<Node>(0, m_rootOdd)) {\r\n      m_rootOdd->isOddRoot(m_rootEven);\r\
    \n      auto root = m_rootOdd;\r\n      for (int r = 0; r < static_cast<int>(s.size());\
    \ ++r) {\r\n        root = root->add(r, s).lock();\r\n      }\r\n    }\r\n\r\n\
    \    /*\r\n     * lambda: (int size, list<int> rItr) -> void\r\n     */\r\n  \
    \  template <class Lambda>\r\n    auto dfs_edges(const Lambda& lambda) {\r\n \
    \     m_rootOdd->dfs_edges(lambda);\r\n    }\r\n\r\n    /*\r\n     * \u304B\u306A\
    \u308A\u5F37\u5F15\u306A\u5B9F\u88C5\r\n     * lambda: (int from, int to) -> void\r\
    \n     */\r\n    template <class Lambda>\r\n    auto dp_suffixLink(const Lambda&\
    \ lambda) {\r\n      // \u68EE\u306E\u751F\u6210\uFF0C\u63A2\u7D22\u9806\u5E8F\
    \u306E\u6C7A\u5B9A\r\n      int from;\r\n      std::unordered_map<int, int> graph;\r\
    \n      std::vector<int> orderCount(m_s.size());\r\n      m_rootOdd->dfs_edges(\r\
    \n          [&](int, const std::list<int>& rItrs) { from = rItrs.front(); },\r\
    \n          [&](int, const std::list<int>& rItrs) {\r\n            int to = rItrs.front();\r\
    \n            graph.emplace(from, to);\r\n            ++orderCount[to];\r\n  \
    \        });\r\n      // \u63A2\u7D22\u9806\u5E8F\u306B\u5F93\u3063\u3066\u51E6\
    \u7406\r\n      std::queue<int, std::list<int>> q;\r\n      for (int i = 0; i\
    \ < static_cast<int>(m_s.size()); ++i) {\r\n        if (orderCount[i] == 0) {\
    \ q.emplace(i); }\r\n      }\r\n      while (!q.empty()) {\r\n        int f =\
    \ q.front();\r\n        q.pop();\r\n        auto range = graph.equal_range(f);\r\
    \n        for (auto itr = range.first; itr != range.second; ++itr) {\r\n     \
    \     int t = itr->second;\r\n          --orderCount[t];\r\n          lambda(f,\
    \ t);\r\n          if (orderCount[t] == 0) { q.emplace(t); }\r\n        }\r\n\
    \      }\r\n    }\r\n\r\n    // debug\u7528\r\n    auto outputTree() {\r\n   \
    \   std::cerr << m_s << std::endl;\r\n      std::cerr << \"-- even --\\n\";\r\n\
    \      m_rootEven->outputTree(m_s);\r\n      std::cerr << \"-- odd --\\n\";\r\n\
    \      m_rootOdd->outputTree(m_s);\r\n    }\r\n  };\r\n}  // namespace mtd\r\n\
    #line 4 \"Test/String/PalindromicTree.test.cpp\"\n\r\n#include <algorithm>\r\n\
    #line 7 \"Test/String/PalindromicTree.test.cpp\"\n\r\nusing ll = long long;\r\n\
    using std::cin;\r\nusing std::cout;\r\nconstexpr char endl = '\\n';\r\nstruct\
    \ Preprocessing {\r\n  Preprocessing() {\r\n    std::cin.tie(0);\r\n    std::ios::sync_with_stdio(0);\r\
    \n  };\r\n} _Preprocessing;\r\n\r\nsigned main() {\r\n  std::string s;\r\n  cin\
    \ >> s;\r\n\r\n  auto p = mtd::PalindromicTree(s);\r\n\r\n  ll ans = 0;\r\n  p.dfs_edges([&](ll\
    \ size, const auto& _) {\r\n    if (size < s.size()) { ans = std::max(ans, size);\
    \ }\r\n  });\r\n  cout << ans << endl;\r\n}\r\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/273\"\r\n\r\n#include\
    \ \"./../../Library/String/PalindromicTree.hpp\"\r\n\r\n#include <algorithm>\r\
    \n#include <iostream>\r\n\r\nusing ll = long long;\r\nusing std::cin;\r\nusing\
    \ std::cout;\r\nconstexpr char endl = '\\n';\r\nstruct Preprocessing {\r\n  Preprocessing()\
    \ {\r\n    std::cin.tie(0);\r\n    std::ios::sync_with_stdio(0);\r\n  };\r\n}\
    \ _Preprocessing;\r\n\r\nsigned main() {\r\n  std::string s;\r\n  cin >> s;\r\n\
    \r\n  auto p = mtd::PalindromicTree(s);\r\n\r\n  ll ans = 0;\r\n  p.dfs_edges([&](ll\
    \ size, const auto& _) {\r\n    if (size < s.size()) { ans = std::max(ans, size);\
    \ }\r\n  });\r\n  cout << ans << endl;\r\n}\r\n"
  dependsOn:
  - Library/String/PalindromicTree.hpp
  isVerificationFile: true
  path: Test/String/PalindromicTree.test.cpp
  requiredBy: []
  timestamp: '2024-12-27 17:07:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/String/PalindromicTree.test.cpp
layout: document
redirect_from:
- /verify/Test/String/PalindromicTree.test.cpp
- /verify/Test/String/PalindromicTree.test.cpp.html
title: Test/String/PalindromicTree.test.cpp
---
