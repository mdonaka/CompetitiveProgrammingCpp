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
    PROBLEM: https://yukicoder.me/problems/no/263
    links:
    - https://yukicoder.me/problems/no/263
  bundledCode: "#line 1 \"Test/String/PalindromicTree_large.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/263\"\r\n\r\n#include <algorithm>\r\n#include\
    \ <iostream>\r\n\r\n#line 3 \"Library/String/PalindromicTree.hpp\"\n#include <queue>\r\
    \n#include <stack>\r\n#include <string>\r\n#include <vector>\r\n\r\nnamespace\
    \ mtd {\r\n  class PalindromicTree {\r\n    struct Node {\r\n      int size;\r\
    \n      int suffix_link;\r\n      int first_itr = -1;\r\n      std::vector<std::pair<char,\
    \ int>> edges;\r\n      std::vector<int> rest_itrs;\r\n\r\n      Node(int s, int\
    \ sl) : size(s), suffix_link(sl) {}\r\n\r\n      auto find_edge(char c) const\
    \ -> int {\r\n        for (const auto& [ch, idx] : edges) {\r\n          if (ch\
    \ == c) { return idx; }\r\n        }\r\n        return -1;\r\n      }\r\n\r\n\
    \      auto add_edge(char c, int idx) -> void { edges.emplace_back(c, idx); }\r\
    \n\r\n      auto add_itr(int itr) -> void {\r\n        if (first_itr == -1) {\r\
    \n          first_itr = itr;\r\n        } else {\r\n          rest_itrs.push_back(itr);\r\
    \n        }\r\n      }\r\n\r\n      auto get_itrs() const -> std::vector<int>\
    \ {\r\n        if (first_itr == -1) { return {}; }\r\n        std::vector<int>\
    \ result;\r\n        result.reserve(1 + rest_itrs.size());\r\n        result.push_back(first_itr);\r\
    \n        result.insert(result.end(), rest_itrs.begin(), rest_itrs.end());\r\n\
    \        return result;\r\n      }\r\n    };\r\n\r\n    const std::string m_s;\r\
    \n    std::vector<Node> m_nodes;\r\n    static constexpr int ROOT_ODD = 0;\r\n\
    \    static constexpr int ROOT_EVEN = 1;\r\n\r\n    auto find(int node_idx, int\
    \ itr) const -> int {\r\n      while (true) {\r\n        int size = m_nodes[node_idx].size;\r\
    \n        if (size == -1) { return node_idx; }\r\n        if (itr - size - 1 >=\
    \ 0 && m_s[itr] == m_s[itr - size - 1]) {\r\n          return node_idx;\r\n  \
    \      }\r\n        node_idx = m_nodes[node_idx].suffix_link;\r\n      }\r\n \
    \   }\r\n\r\n    auto add(int node_idx, int itr) -> int {\r\n      int add_root\
    \ = find(node_idx, itr);\r\n      char c = m_s[itr];\r\n\r\n      int existing\
    \ = m_nodes[add_root].find_edge(c);\r\n      if (existing != -1) {\r\n       \
    \ m_nodes[existing].add_itr(itr);\r\n        return existing;\r\n      }\r\n\r\
    \n      int new_size = m_nodes[add_root].size + 2;\r\n      int suffix_link_from\
    \ = find(m_nodes[add_root].suffix_link, itr);\r\n\r\n      int new_suffix_link\
    \ = m_nodes[suffix_link_from].find_edge(c);\r\n      if (new_suffix_link == -1)\
    \ { new_suffix_link = ROOT_EVEN; }\r\n\r\n      int new_idx = static_cast<int>(m_nodes.size());\r\
    \n      m_nodes.emplace_back(new_size, new_suffix_link);\r\n      m_nodes[new_idx].add_itr(itr);\r\
    \n      m_nodes[add_root].add_edge(c, new_idx);\r\n\r\n      return new_idx;\r\
    \n    }\r\n\r\n  public:\r\n    PalindromicTree(const std::string& s) : m_s(s)\
    \ {\r\n      m_nodes.reserve(s.size() + 2);\r\n      m_nodes.emplace_back(-1,\
    \ ROOT_ODD);\r\n      m_nodes.emplace_back(0, ROOT_ODD);\r\n\r\n      int cur\
    \ = ROOT_ODD;\r\n      for (int i = 0; i < static_cast<int>(s.size()); ++i) {\
    \ cur = add(cur, i); }\r\n\r\n      m_nodes.shrink_to_fit();\r\n      for (auto&\
    \ node : m_nodes) {\r\n        node.edges.shrink_to_fit();\r\n        node.rest_itrs.shrink_to_fit();\r\
    \n      }\r\n    }\r\n\r\n    template <class Lambda>\r\n    auto dfs_edges(const\
    \ Lambda& lambda) const -> void {\r\n      std::stack<int, std::vector<int>> stk;\r\
    \n      stk.push(ROOT_ODD);\r\n      stk.push(ROOT_EVEN);\r\n\r\n      while (!stk.empty())\
    \ {\r\n        int idx = stk.top();\r\n        stk.pop();\r\n\r\n        const\
    \ auto& node = m_nodes[idx];\r\n        if (node.size > 0) { lambda(node.size,\
    \ node.get_itrs()); }\r\n\r\n        for (const auto& [_, next_idx] : node.edges)\
    \ { stk.push(next_idx); }\r\n      }\r\n    }\r\n\r\n    template <class Lambda>\r\
    \n    auto dp_suffixLink(const Lambda& lambda) const -> void {\r\n      std::vector<int>\
    \ order_count(m_s.size(), 0);\r\n      std::vector<std::vector<int>> graph(m_s.size());\r\
    \n\r\n      for (int idx = 2; idx < static_cast<int>(m_nodes.size()); ++idx) {\r\
    \n        const auto& node = m_nodes[idx];\r\n        if (node.first_itr == -1)\
    \ { continue; }\r\n\r\n        int from = node.first_itr;\r\n        int sl_idx\
    \ = node.suffix_link;\r\n        if (sl_idx >= 2 && m_nodes[sl_idx].first_itr\
    \ != -1) {\r\n          int to = m_nodes[sl_idx].first_itr;\r\n          graph[from].push_back(to);\r\
    \n          ++order_count[to];\r\n        }\r\n      }\r\n\r\n      std::queue<int>\
    \ q;\r\n      for (int i = 0; i < static_cast<int>(m_s.size()); ++i) {\r\n   \
    \     if (order_count[i] == 0) { q.push(i); }\r\n      }\r\n\r\n      while (!q.empty())\
    \ {\r\n        int f = q.front();\r\n        q.pop();\r\n        for (int t :\
    \ graph[f]) {\r\n          --order_count[t];\r\n          lambda(f, t);\r\n  \
    \        if (order_count[t] == 0) { q.push(t); }\r\n        }\r\n      }\r\n \
    \   }\r\n  };\r\n}  // namespace mtd\r\n#line 7 \"Test/String/PalindromicTree_large.test.cpp\"\
    \n\r\nusing ll = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr\
    \ char endl = '\\n';\r\nstruct Preprocessing {\r\n  Preprocessing() {\r\n    std::cin.tie(0);\r\
    \n    std::ios::sync_with_stdio(0);\r\n  };\r\n} _Preprocessing;\r\n\r\nsigned\
    \ main() {\r\n  std::string a, b;\r\n  cin >> a >> b;\r\n  std::string s = a +\
    \ \"$%\" + b;\r\n\r\n  auto tree = mtd::PalindromicTree(s);\r\n\r\n  ll an = a.size();\r\
    \n  std::vector<std::pair<ll, ll>> dp(s.size());\r\n  tree.dfs_edges([&](int size,\
    \ const std::vector<int>& ritr) {\r\n    ll l = 0, r = 0;\r\n    for (const auto&\
    \ x : ritr)\r\n      if (x != an && x != an + 1) { ++((x < an) ? l : r); }\r\n\
    \    dp[ritr.front()] = {l, r};\r\n  });\r\n\r\n  tree.dp_suffixLink([&](int from,\
    \ int to) {\r\n    dp[to].first += dp[from].first;\r\n    dp[to].second += dp[from].second;\r\
    \n  });\r\n\r\n  ll ans = 0;\r\n  for (const auto& p : dp) { ans += (p.first *\
    \ p.second); }\r\n  cout << ans << endl;\r\n}\r\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/263\"\r\n\r\n#include\
    \ <algorithm>\r\n#include <iostream>\r\n\r\n#include \"./../../Library/String/PalindromicTree.hpp\"\
    \r\n\r\nusing ll = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr\
    \ char endl = '\\n';\r\nstruct Preprocessing {\r\n  Preprocessing() {\r\n    std::cin.tie(0);\r\
    \n    std::ios::sync_with_stdio(0);\r\n  };\r\n} _Preprocessing;\r\n\r\nsigned\
    \ main() {\r\n  std::string a, b;\r\n  cin >> a >> b;\r\n  std::string s = a +\
    \ \"$%\" + b;\r\n\r\n  auto tree = mtd::PalindromicTree(s);\r\n\r\n  ll an = a.size();\r\
    \n  std::vector<std::pair<ll, ll>> dp(s.size());\r\n  tree.dfs_edges([&](int size,\
    \ const std::vector<int>& ritr) {\r\n    ll l = 0, r = 0;\r\n    for (const auto&\
    \ x : ritr)\r\n      if (x != an && x != an + 1) { ++((x < an) ? l : r); }\r\n\
    \    dp[ritr.front()] = {l, r};\r\n  });\r\n\r\n  tree.dp_suffixLink([&](int from,\
    \ int to) {\r\n    dp[to].first += dp[from].first;\r\n    dp[to].second += dp[from].second;\r\
    \n  });\r\n\r\n  ll ans = 0;\r\n  for (const auto& p : dp) { ans += (p.first *\
    \ p.second); }\r\n  cout << ans << endl;\r\n}\r\n"
  dependsOn:
  - Library/String/PalindromicTree.hpp
  isVerificationFile: true
  path: Test/String/PalindromicTree_large.test.cpp
  requiredBy: []
  timestamp: '2025-12-20 03:22:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/String/PalindromicTree_large.test.cpp
layout: document
redirect_from:
- /verify/Test/String/PalindromicTree_large.test.cpp
- /verify/Test/String/PalindromicTree_large.test.cpp.html
title: Test/String/PalindromicTree_large.test.cpp
---
