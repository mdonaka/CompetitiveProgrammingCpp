---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Library/String/PalindromicTree.hpp
    title: Library/String/PalindromicTree.hpp
  - icon: ':x:'
    path: Utils/debug.hpp
    title: Utils/debug.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "#line 1 \"Test/String/PalindromicTree.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/273\"\r\n\r\n#include <iostream>\r\n#include\
    \ <algorithm>\r\n#line 2 \"Library/String/PalindromicTree.hpp\"\n#include <memory>\r\
    \n#include <string>\r\n#line 5 \"Library/String/PalindromicTree.hpp\"\n#include\
    \ <list>\r\n#include <queue>\r\n#include <vector>\r\n#line 2 \"Utils/debug.hpp\"\
    \n#include <concepts>\n#line 5 \"Utils/debug.hpp\"\n#include <string_view>\n\n\
    template<class T>constexpr inline auto d_val(T a, T b) { return b; }\n\n// debug\u7528\
    \u51FA\u529B\u30DE\u30AF\u30ED\n#define dump(...)                            \
    \                   \\\n  do {                                               \
    \           \\\n    auto __DUMP_NAME_LIST__ = split(#__VA_ARGS__, ',');      \
    \   \\\n    splitVariables(std::move(__DUMP_NAME_LIST__), __VA_ARGS__); \\\n \
    \ } while (false)\n\n// \u51FA\u529B\u3067\u304D\u308B\u7A2E\u985E\u306E\u8FFD\
    \u52A0\ntemplate<class S, class T>\nstd::ostream& operator<<(std::ostream& os,\
    \ const std::pair<S, T>& p) {\n\tos << \"(\" << p.first << \", \" << p.second\
    \ << \")\";\n\treturn os;\n}\n// split\ninline auto split(std::string_view str,\
    \ char del = ' ') {\n\tstd::list<std::string_view> sList;\n\tint from = -1;\n\t\
    for (int i = 0; auto && c : str) {\n\t\tif (c == ' ') {\n\t\t\tsList.emplace_back(str.substr(from\
    \ + 1, i - from - 2));\n\t\t\tfrom = i;\n\t\t}\n\t\t++i;\n\t}\n\tsList.emplace_back(str.substr(from\
    \ + 1, str.size() - from));\n\treturn sList;\n}\n// \u5236\u7D04\ntemplate <class\
    \ T>\nconcept Container = requires(T x) {\n\tx.begin();\n};\n\ntemplate <class\
    \ T>\nconcept Printable = requires(T x) {\n\tstd::cerr << x;\n};\n\n// \u51FA\u529B\
    \nconstexpr auto print(const auto&) {\n\tstd::cerr << \"<ERROR!> \\\"print\\\"\
    \ of This type is not defined.\" << '\\n';\n}\ninline auto print(const std::string&\
    \ s) { std::cerr << s << ' '; }\nconstexpr auto print(const Printable auto& p)\
    \ { std::cerr << p << ' '; }\nconstexpr auto print(const Container auto& c) {\n\
    \tfor (auto&& x : c) {\n\t\tprint(x);\n\t}\n\tstd::cerr << '\\n';\n}\n\n// \u5909\
    \u6570\u306E\u51FA\u529B\nconstexpr auto printVariable(auto&& name, const auto&\
    \ p) {\n\tstd::cerr << name << \": \";\n\tprint(p);\n\tstd::cerr << '\\n';\n}\n\
    inline auto printVariable(auto&& name, const std::string& s) {\n\tstd::cerr <<\
    \ name << \": \";\n\tprint(s);\n\tstd::cerr << '\\n';\n}\nconstexpr auto printVariable(auto&&\
    \ name, const Container auto& c) {\n\tstd::cerr << \"-- \" << name << \" --\"\
    \ << '\\n';\n\tprint(c);\n}\n\n// 1\u5909\u6570\u305A\u3064\u51E6\u7406\nconstexpr\
    \ auto splitVariables(auto&& names) {}\nconstexpr auto splitVariables(auto&& names,\
    \ const auto& x,\n\t\t\t\t\t\t\t  const auto&... tail) {\n\tprintVariable(names.front(),\
    \ x);\n\tnames.pop_front();\n\tsplitVariables(std::forward<decltype(names)>(names),\
    \ tail...);\n}\n#line 9 \"Library/String/PalindromicTree.hpp\"\n#include <unordered_map>\r\
    \nusing std::cout;\r\nusing std::cin;\r\n\r\nauto nullLambda = [](int, const std::list<int>&)\
    \ {};\r\nclass PalindromicTree {\r\n    //static constexpr auto nullLambda = [](int,\
    \ const std::list<int>&) {};// c++17\r\n\r\n    class Node :public std::enable_shared_from_this<Node>\
    \ {\r\n        // \u6700\u5927\u306E\u56DE\u6587\u63A5\u5C3E\u8F9E\r\n       \
    \ std::weak_ptr<Node> m_suffixLink;\r\n        // \u6B21\u30B5\u30A4\u30BA\u306E\
    \u56DE\u6587(\u56F2\u3080\u6587\u5B57, \u6B21\u306ENode)\r\n        std::unordered_map<char,\
    \ std::shared_ptr<Node>> m_edges;\r\n\r\n        // \u56DE\u6587\u306E\u53F3\u7AEF\
    itr\r\n        std::list<int> m_itrs;\r\n        // \u56DE\u6587\u30B5\u30A4\u30BA\
    \r\n        const int m_size;\r\n\r\n        // xAx\u3068\u306A\u308BA\u3092\u63A2\
    \u3059(x=str[itr])\r\n        auto find(int itr, const std::string& s, bool flg\
    \ = false) {\r\n            // root\u306B\u305F\u3069\u308A\u7740\u3044\u305F\r\
    \n            if(m_size == -1) { return weak_from_this(); }\r\n            //\
    \ \u73FE\u5728\u5730\"A\"\u306B\u304A\u3044\u3066\"xAx\"\u3068\u306A\u308B\r\n\
    \            if(itr - m_size - 1 >= 0 && s[itr] == s[itr - m_size - 1]) {\r\n\
    \                return weak_from_this();\r\n            }\r\n            // \u898B\
    \u3064\u304B\u3089\u306A\u3044\r\n            return m_suffixLink.lock()->find(itr,\
    \ s, flg);\r\n        }\r\n\r\n        // \u65B0\u3057\u3044\u56DE\u6587Node\u3092\
    \u4F5C\u6210\u3059\u308B\r\n        auto create(int itr, const std::string& s)\
    \ {\r\n            // suffixLink\u306E\u63A2\u7D22\r\n            auto suffixLinkFrom\
    \ = m_suffixLink.lock()/*->m_suffixLink.lock()*/->find(itr, s, true).lock();\r\
    \n            // \u65B0Node\u306E\u4F5C\u6210\r\n            auto newNode = std::make_shared<Node>(\r\
    \n                m_size + 2, (suffixLinkFrom->m_edges.find(s[itr]) == suffixLinkFrom->m_edges.end())\
    \ ?\r\n                suffixLinkFrom->m_edges.find(' ')->second :\r\n       \
    \         suffixLinkFrom->m_edges.find(s[itr])->second);\r\n            m_edges.emplace(s[itr],\
    \ newNode);\r\n            return std::weak_ptr<Node>(newNode);\r\n        }\r\
    \n\r\n    public:\r\n        // constructor\r\n        Node(int size, const std::weak_ptr<Node>&\
    \ suffixLink) :\r\n            m_size(size),\r\n            m_suffixLink(suffixLink)\
    \ {\r\n        }\r\n        Node() :m_size(-1) {}\r\n\r\n\r\n        // \u6B21\
    \u30B5\u30A4\u30BA\u306E\u56DE\u6587\u3092\u8FFD\u52A0\r\n        auto add(int\
    \ itr, const std::string& s) {\r\n            auto addRoot = find(itr, s).lock();\r\
    \n            auto nextNode = (addRoot->m_edges.find(s[itr]) == addRoot->m_edges.end())\
    \ ?\r\n                addRoot->create(itr, s) :\r\n                std::weak_ptr<Node>(addRoot->m_edges.find(s[itr])->second);\r\
    \n            nextNode.lock()->m_itrs.emplace_back(itr);\r\n            return\
    \ nextNode;\r\n        }\r\n\r\n        // debug\u7528\r\n        auto outputTree(const\
    \ std::string& s) ->void const {\r\n            if(m_size <= 0) { cout << \"root\"\
    ; } else {\r\n                // \u6BB5\r\n                for(int i = 0; (i <\
    \ (m_size + 1) / 2); ++i) { cout << \" |\"; }\r\n                cout << \"- \"\
    \ << s.substr(*m_itrs.begin() - m_size + 1, m_size);\r\n                // \u53F3\
    itr\r\n                cout << \" [ \"; for(const auto& itr : m_itrs) { cout <<\
    \ itr << \" \"; }cout << \"] \";\r\n                // suffix link\r\n       \
    \         //auto p = m_suffixLink.lock();\r\n                //cout << \"{\" <<\
    \ s.substr(*p->m_itrs.begin() - p->m_size + 1, p->m_size) << \"} \";\r\n     \
    \       } cout << \"\\n\";\r\n            for(const auto& edge : m_edges) {\r\n\
    \                if(m_size == -1 && edge.first == ' ') { continue; }\r\n     \
    \           edge.second->outputTree(s);\r\n            }\r\n        }\r\n\r\n\
    \        // root\u3092\u6C7A\u5B9A\r\n        auto isOddRoot(const std::weak_ptr<Node>&\
    \ evenRoot) {\r\n            m_suffixLink = weak_from_this();\r\n            m_edges.emplace('\
    \ ', evenRoot);\r\n        }\r\n\r\n        // \u30E9\u30E0\u30C0\u5F0F\u306E\u5B9F\
    \u884C\r\n        template<class Lambda>\r\n        auto runLambda(const Lambda&\
    \ lambda) {\r\n            if(m_size > 0) { lambda(m_size, m_itrs); }\r\n    \
    \    }\r\n\r\n        /*\r\n         * lambda: (int size, list<int> rItr) -> void\r\
    \n         */\r\n        template<class Lambda, class SuffixLinkLambda = decltype(nullLambda)>\r\
    \n        auto dfs_edges(const Lambda& lambda, const SuffixLinkLambda& slLambda\
    \ = nullLambda)->void {\r\n            runLambda(lambda);\r\n            m_suffixLink.lock()->runLambda(slLambda);\r\
    \n            for(const auto& edge : m_edges) {\r\n                edge.second->dfs_edges(lambda,\
    \ slLambda);\r\n            }\r\n        }\r\n    };\r\n\r\n    // \u5BFE\u8C61\
    \u3068\u306A\u308B\u6587\u5B57\u5217\r\n    const std::string m_s;\r\n\r\n   \
    \ // \u5076\u6570\u9577\uFF0C\u5947\u6570\u9577\u306EPalindromicTree\u306E\u6839\
    (0, -1)\r\n    std::shared_ptr<Node> m_rootOdd;\r\n    std::shared_ptr<Node> m_rootEven;\r\
    \npublic:\r\n    // constructor\r\n    PalindromicTree(const std::string& s) :\r\
    \n        m_s(s),\r\n        m_rootOdd(std::make_shared<Node>()),\r\n        m_rootEven(std::make_shared<Node>(0,\
    \ m_rootOdd)) {\r\n        m_rootOdd->isOddRoot(m_rootEven);\r\n        auto root\
    \ = m_rootOdd;\r\n        for(int r = 0; r < s.size(); ++r) {\r\n            root\
    \ = root->add(r, s).lock();\r\n        }\r\n    }\r\n\r\n    /*\r\n     * lambda:\
    \ (int size, list<int> rItr) -> void\r\n     */\r\n    template<class Lambda>\r\
    \n    auto dfs_edges(const Lambda& lambda) {\r\n        m_rootOdd->dfs_edges(lambda);\r\
    \n    }\r\n\r\n    /*\r\n     * \u304B\u306A\u308A\u5F37\u5F15\u306A\u5B9F\u88C5\
    \r\n     * lambda: (int from, int to) -> void\r\n     */\r\n    template<class\
    \ Lambda>\r\n    auto dp_suffixLink(const Lambda& lambda) {\r\n        // \u68EE\
    \u306E\u751F\u6210\uFF0C\u63A2\u7D22\u9806\u5E8F\u306E\u6C7A\u5B9A\r\n       \
    \ int from;\r\n        std::unordered_map<int, int> graph;\r\n        std::vector<int>\
    \ orderCount(m_s.size());\r\n        m_rootOdd->dfs_edges([&](int size, const\
    \ std::list<int>& rItrs) {\r\n            from = rItrs.front();\r\n        },\
    \ [&](int size, const std::list<int>& rItrs) {\r\n            int to = rItrs.front();\r\
    \n            graph.emplace(from, to);\r\n            ++orderCount[to];\r\n  \
    \      });\r\n        // \u63A2\u7D22\u9806\u5E8F\u306B\u5F93\u3063\u3066\u51E6\
    \u7406\r\n        std::queue<int> q;\r\n        for(int i = 0; i < m_s.size();\
    \ ++i)if(orderCount[i] == 0) { q.emplace(i); }\r\n        while(!q.empty()) {\r\
    \n            int from = q.front();\r\n            q.pop();\r\n            auto\
    \ range = graph.equal_range(from);\r\n            for(auto itr = range.first;\
    \ itr != range.second; ++itr) {\r\n                int to = itr->second;\r\n \
    \               --orderCount[to];\r\n                lambda(from, to);\r\n   \
    \             if(orderCount[to] == 0) { q.emplace(to); }\r\n            }\r\n\
    \        }\r\n    }\r\n\r\n    // debug\u7528\r\n    auto outputTree() {\r\n \
    \       dump(m_s);\r\n        cout << \"-- even --\\n\";\r\n        m_rootEven->outputTree(m_s);\r\
    \n        cout << \"-- odd --\\n\";\r\n        m_rootOdd->outputTree(m_s);\r\n\
    \    }\r\n};\n#line 6 \"Test/String/PalindromicTree.test.cpp\"\n\r\nusing ll =\
    \ long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr char endl = '\\\
    n';\r\nstruct Preprocessing { Preprocessing() { std::cin.tie(0); std::ios::sync_with_stdio(0);\
    \ }; }_Preprocessing;\r\n\r\nsigned main() {\r\n    std::string s;\r\n    cin\
    \ >> s;\r\n\r\n    auto p = PalindromicTree(s);\r\n\r\n    ll ans = 0;\r\n   \
    \ p.dfs_edges([&](ll size, const auto& _) {\r\n        if(size < s.size()) { ans\
    \ = std::max(ans, size); }\r\n    });\r\n    cout << ans << endl;\r\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/273\"\r\n\r\n#include\
    \ <iostream>\r\n#include <algorithm>\r\n#include \"./../../Library/String/PalindromicTree.hpp\"\
    \r\n\r\nusing ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr\
    \ char endl = '\\n';\r\nstruct Preprocessing { Preprocessing() { std::cin.tie(0);\
    \ std::ios::sync_with_stdio(0); }; }_Preprocessing;\r\n\r\nsigned main() {\r\n\
    \    std::string s;\r\n    cin >> s;\r\n\r\n    auto p = PalindromicTree(s);\r\
    \n\r\n    ll ans = 0;\r\n    p.dfs_edges([&](ll size, const auto& _) {\r\n   \
    \     if(size < s.size()) { ans = std::max(ans, size); }\r\n    });\r\n    cout\
    \ << ans << endl;\r\n}"
  dependsOn:
  - Library/String/PalindromicTree.hpp
  - Utils/debug.hpp
  isVerificationFile: true
  path: Test/String/PalindromicTree.test.cpp
  requiredBy: []
  timestamp: '2022-09-12 02:58:26+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/String/PalindromicTree.test.cpp
layout: document
redirect_from:
- /verify/Test/String/PalindromicTree.test.cpp
- /verify/Test/String/PalindromicTree.test.cpp.html
title: Test/String/PalindromicTree.test.cpp
---
