---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Utils/debug.hpp
    title: Utils/debug.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/String/PalindromicTree.hpp\"\n#include <memory>\r\
    \n#include <string>\r\n#include <iostream>\r\n#include <list>\r\n#include <queue>\r\
    \n#include <vector>\r\n#line 2 \"Utils/debug.hpp\"\n#define IGNORE\n#include <concepts>\n\
    #line 6 \"Utils/debug.hpp\"\n#include <string_view>\n\ntemplate<class T>constexpr\
    \ inline auto d_val(T a, T b) { return b; }\n\n// debug\u7528\u51FA\u529B\u30DE\
    \u30AF\u30ED\n#define dump(...)                                              \
    \ \\\n  do {                                                          \\\n   \
    \ auto __DUMP_NAME_LIST__ = split(#__VA_ARGS__, ',');         \\\n    splitVariables(std::move(__DUMP_NAME_LIST__),\
    \ __VA_ARGS__); \\\n  } while (false)\n\n// \u51FA\u529B\u3067\u304D\u308B\u7A2E\
    \u985E\u306E\u8FFD\u52A0\ntemplate<class S, class T>\nstd::ostream& operator<<(std::ostream&\
    \ os, const std::pair<S, T>& p) {\n\tos << \"(\" << p.first << \", \" << p.second\
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
    \ {};\r\nclass PalindromicTree {\r\n\t//static constexpr auto nullLambda = [](int,\
    \ const std::list<int>&) {};// c++17\r\n\r\n\tclass Node :public std::enable_shared_from_this<Node>\
    \ {\r\n\t\t// \u6700\u5927\u306E\u56DE\u6587\u63A5\u5C3E\u8F9E\r\n\t\tstd::weak_ptr<Node>\
    \ m_suffixLink;\r\n\t\t// \u6B21\u30B5\u30A4\u30BA\u306E\u56DE\u6587(\u56F2\u3080\
    \u6587\u5B57, \u6B21\u306ENode)\r\n\t\tstd::unordered_map<char, std::shared_ptr<Node>>\
    \ m_edges;\r\n\r\n\t\t// \u56DE\u6587\u306E\u53F3\u7AEFitr\r\n\t\tstd::list<int>\
    \ m_itrs;\r\n\t\t// \u56DE\u6587\u30B5\u30A4\u30BA\r\n\t\tconst int m_size;\r\n\
    \r\n\t\t// xAx\u3068\u306A\u308BA\u3092\u63A2\u3059(x=str[itr])\r\n\t\tauto find(int\
    \ itr, const std::string& s, bool flg = false) {\r\n\t\t\t// root\u306B\u305F\u3069\
    \u308A\u7740\u3044\u305F\r\n\t\t\tif (m_size == -1) { return weak_from_this();\
    \ }\r\n\t\t\t// \u73FE\u5728\u5730\"A\"\u306B\u304A\u3044\u3066\"xAx\"\u3068\u306A\
    \u308B\r\n\t\t\tif (itr - m_size - 1 >= 0 && s[itr] == s[itr - m_size - 1]) {\r\
    \n\t\t\t\treturn weak_from_this();\r\n\t\t\t}\r\n\t\t\t// \u898B\u3064\u304B\u3089\
    \u306A\u3044\r\n\t\t\treturn m_suffixLink.lock()->find(itr, s, flg);\r\n\t\t}\r\
    \n\r\n\t\t// \u65B0\u3057\u3044\u56DE\u6587Node\u3092\u4F5C\u6210\u3059\u308B\r\
    \n\t\tauto create(int itr, const std::string& s) {\r\n\t\t\t// suffixLink\u306E\
    \u63A2\u7D22\r\n\t\t\tauto suffixLinkFrom = m_suffixLink.lock()/*->m_suffixLink.lock()*/->find(itr,\
    \ s, true).lock();\r\n\t\t\t// \u65B0Node\u306E\u4F5C\u6210\r\n\t\t\tauto newNode\
    \ = std::make_shared<Node>(\r\n\t\t\t\tm_size + 2, (suffixLinkFrom->m_edges.find(s[itr])\
    \ == suffixLinkFrom->m_edges.end()) ?\r\n\t\t\t\tsuffixLinkFrom->m_edges.find('\
    \ ')->second :\r\n\t\t\t\tsuffixLinkFrom->m_edges.find(s[itr])->second);\r\n\t\
    \t\tm_edges.emplace(s[itr], newNode);\r\n\t\t\treturn std::weak_ptr<Node>(newNode);\r\
    \n\t\t}\r\n\r\n\tpublic:\r\n\t\t// constructor\r\n\t\tNode(int size, const std::weak_ptr<Node>&\
    \ suffixLink) :\r\n\t\t\tm_size(size),\r\n\t\t\tm_suffixLink(suffixLink) {}\r\n\
    \t\tNode() :m_size(-1) {}\r\n\r\n\r\n\t\t// \u6B21\u30B5\u30A4\u30BA\u306E\u56DE\
    \u6587\u3092\u8FFD\u52A0\r\n\t\tauto add(int itr, const std::string& s) {\r\n\t\
    \t\tauto addRoot = find(itr, s).lock();\r\n\t\t\tauto nextNode = (addRoot->m_edges.find(s[itr])\
    \ == addRoot->m_edges.end()) ?\r\n\t\t\t\taddRoot->create(itr, s) :\r\n\t\t\t\t\
    std::weak_ptr<Node>(addRoot->m_edges.find(s[itr])->second);\r\n\t\t\tnextNode.lock()->m_itrs.emplace_back(itr);\r\
    \n\t\t\treturn nextNode;\r\n\t\t}\r\n\r\n\t\t// debug\u7528\r\n\t\tauto outputTree(const\
    \ std::string& s) ->void const {\r\n\t\t\tif (m_size <= 0) { cout << \"root\"\
    ; } else {\r\n\t\t\t\t// \u6BB5\r\n\t\t\t\tfor (int i = 0; (i < (m_size + 1) /\
    \ 2); ++i) { cout << \" |\"; }\r\n\t\t\t\tcout << \"- \" << s.substr(*m_itrs.begin()\
    \ - m_size + 1, m_size);\r\n\t\t\t\t// \u53F3itr\r\n\t\t\t\tcout << \" [ \"; for\
    \ (const auto& itr : m_itrs) { cout << itr << \" \"; }cout << \"] \";\r\n\t\t\t\
    \t// suffix link\r\n\t\t\t\t//auto p = m_suffixLink.lock();\r\n\t\t\t\t//cout\
    \ << \"{\" << s.substr(*p->m_itrs.begin() - p->m_size + 1, p->m_size) << \"} \"\
    ;\r\n\t\t\t} cout << \"\\n\";\r\n\t\t\tfor (const auto& edge : m_edges) {\r\n\t\
    \t\t\tif (m_size == -1 && edge.first == ' ') { continue; }\r\n\t\t\t\tedge.second->outputTree(s);\r\
    \n\t\t\t}\r\n\t\t}\r\n\r\n\t\t// root\u3092\u6C7A\u5B9A\r\n\t\tauto isOddRoot(const\
    \ std::weak_ptr<Node>& evenRoot) {\r\n\t\t\tm_suffixLink = weak_from_this();\r\
    \n\t\t\tm_edges.emplace(' ', evenRoot);\r\n\t\t}\r\n\r\n\t\t// \u30E9\u30E0\u30C0\
    \u5F0F\u306E\u5B9F\u884C\r\n\t\ttemplate<class Lambda>\r\n\t\tauto runLambda(const\
    \ Lambda& lambda) {\r\n\t\t\tif (m_size > 0) { lambda(m_size, m_itrs); }\r\n\t\
    \t}\r\n\r\n\t\t/*\r\n\t\t * lambda: (int size, list<int> rItr) -> void\r\n\t\t\
    \ */\r\n\t\ttemplate<class Lambda, class SuffixLinkLambda = decltype(nullLambda)>\r\
    \n\t\tauto dfs_edges(const Lambda& lambda, const SuffixLinkLambda& slLambda =\
    \ nullLambda)->void {\r\n\t\t\trunLambda(lambda);\r\n\t\t\tm_suffixLink.lock()->runLambda(slLambda);\r\
    \n\t\t\tfor (const auto& edge : m_edges) {\r\n\t\t\t\tedge.second->dfs_edges(lambda,\
    \ slLambda);\r\n\t\t\t}\r\n\t\t}\r\n\t};\r\n\r\n\t// \u5BFE\u8C61\u3068\u306A\u308B\
    \u6587\u5B57\u5217\r\n\tconst std::string m_s;\r\n\r\n\t// \u5076\u6570\u9577\uFF0C\
    \u5947\u6570\u9577\u306EPalindromicTree\u306E\u6839(0, -1)\r\n\tstd::shared_ptr<Node>\
    \ m_rootOdd;\r\n\tstd::shared_ptr<Node> m_rootEven;\r\npublic:\r\n\t// constructor\r\
    \n\tPalindromicTree(const std::string& s) :\r\n\t\tm_s(s),\r\n\t\tm_rootOdd(std::make_shared<Node>()),\r\
    \n\t\tm_rootEven(std::make_shared<Node>(0, m_rootOdd)) {\r\n\t\tm_rootOdd->isOddRoot(m_rootEven);\r\
    \n\t\tauto root = m_rootOdd;\r\n\t\tfor (int r = 0; r < s.size(); ++r) {\r\n\t\
    \t\troot = root->add(r, s).lock();\r\n\t\t}\r\n\t}\r\n\r\n\t/*\r\n\t * lambda:\
    \ (int size, list<int> rItr) -> void\r\n\t */\r\n\ttemplate<class Lambda>\r\n\t\
    auto dfs_edges(const Lambda& lambda) {\r\n\t\tm_rootOdd->dfs_edges(lambda);\r\n\
    \t}\r\n\r\n\t/*\r\n\t * \u304B\u306A\u308A\u5F37\u5F15\u306A\u5B9F\u88C5\r\n\t\
    \ * lambda: (int from, int to) -> void\r\n\t */\r\n\ttemplate<class Lambda>\r\n\
    \tauto dp_suffixLink(const Lambda& lambda) {\r\n\t\t// \u68EE\u306E\u751F\u6210\
    \uFF0C\u63A2\u7D22\u9806\u5E8F\u306E\u6C7A\u5B9A\r\n\t\tint from;\r\n\t\tstd::unordered_map<int,\
    \ int> graph;\r\n\t\tstd::vector<int> orderCount(m_s.size());\r\n\t\tm_rootOdd->dfs_edges([&](int\
    \ size, const std::list<int>& rItrs) {\r\n\t\t\tfrom = rItrs.front();\r\n\t\t\
    }, [&](int size, const std::list<int>& rItrs) {\r\n\t\t\tint to = rItrs.front();\r\
    \n\t\t\tgraph.emplace(from, to);\r\n\t\t\t++orderCount[to];\r\n\t\t});\r\n\t\t\
    // \u63A2\u7D22\u9806\u5E8F\u306B\u5F93\u3063\u3066\u51E6\u7406\r\n\t\tstd::queue<int>\
    \ q;\r\n\t\tfor (int i = 0; i < m_s.size(); ++i)if (orderCount[i] == 0) { q.emplace(i);\
    \ }\r\n\t\twhile (!q.empty()) {\r\n\t\t\tint from = q.front();\r\n\t\t\tq.pop();\r\
    \n\t\t\tauto range = graph.equal_range(from);\r\n\t\t\tfor (auto itr = range.first;\
    \ itr != range.second; ++itr) {\r\n\t\t\t\tint to = itr->second;\r\n\t\t\t\t--orderCount[to];\r\
    \n\t\t\t\tlambda(from, to);\r\n\t\t\t\tif (orderCount[to] == 0) { q.emplace(to);\
    \ }\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\t// debug\u7528\r\n\tauto outputTree()\
    \ {\r\n\t\tdump(m_s);\r\n\t\tcout << \"-- even --\\n\";\r\n\t\tm_rootEven->outputTree(m_s);\r\
    \n\t\tcout << \"-- odd --\\n\";\r\n\t\tm_rootOdd->outputTree(m_s);\r\n\t}\r\n\
    };\n"
  code: "#pragma once\r\n#include <memory>\r\n#include <string>\r\n#include <iostream>\r\
    \n#include <list>\r\n#include <queue>\r\n#include <vector>\r\n#include \"./../../Utils/debug.hpp\"\
    \r\n#include <unordered_map>\r\nusing std::cout;\r\nusing std::cin;\r\n\r\nauto\
    \ nullLambda = [](int, const std::list<int>&) {};\r\nclass PalindromicTree {\r\
    \n\t//static constexpr auto nullLambda = [](int, const std::list<int>&) {};//\
    \ c++17\r\n\r\n\tclass Node :public std::enable_shared_from_this<Node> {\r\n\t\
    \t// \u6700\u5927\u306E\u56DE\u6587\u63A5\u5C3E\u8F9E\r\n\t\tstd::weak_ptr<Node>\
    \ m_suffixLink;\r\n\t\t// \u6B21\u30B5\u30A4\u30BA\u306E\u56DE\u6587(\u56F2\u3080\
    \u6587\u5B57, \u6B21\u306ENode)\r\n\t\tstd::unordered_map<char, std::shared_ptr<Node>>\
    \ m_edges;\r\n\r\n\t\t// \u56DE\u6587\u306E\u53F3\u7AEFitr\r\n\t\tstd::list<int>\
    \ m_itrs;\r\n\t\t// \u56DE\u6587\u30B5\u30A4\u30BA\r\n\t\tconst int m_size;\r\n\
    \r\n\t\t// xAx\u3068\u306A\u308BA\u3092\u63A2\u3059(x=str[itr])\r\n\t\tauto find(int\
    \ itr, const std::string& s, bool flg = false) {\r\n\t\t\t// root\u306B\u305F\u3069\
    \u308A\u7740\u3044\u305F\r\n\t\t\tif (m_size == -1) { return weak_from_this();\
    \ }\r\n\t\t\t// \u73FE\u5728\u5730\"A\"\u306B\u304A\u3044\u3066\"xAx\"\u3068\u306A\
    \u308B\r\n\t\t\tif (itr - m_size - 1 >= 0 && s[itr] == s[itr - m_size - 1]) {\r\
    \n\t\t\t\treturn weak_from_this();\r\n\t\t\t}\r\n\t\t\t// \u898B\u3064\u304B\u3089\
    \u306A\u3044\r\n\t\t\treturn m_suffixLink.lock()->find(itr, s, flg);\r\n\t\t}\r\
    \n\r\n\t\t// \u65B0\u3057\u3044\u56DE\u6587Node\u3092\u4F5C\u6210\u3059\u308B\r\
    \n\t\tauto create(int itr, const std::string& s) {\r\n\t\t\t// suffixLink\u306E\
    \u63A2\u7D22\r\n\t\t\tauto suffixLinkFrom = m_suffixLink.lock()/*->m_suffixLink.lock()*/->find(itr,\
    \ s, true).lock();\r\n\t\t\t// \u65B0Node\u306E\u4F5C\u6210\r\n\t\t\tauto newNode\
    \ = std::make_shared<Node>(\r\n\t\t\t\tm_size + 2, (suffixLinkFrom->m_edges.find(s[itr])\
    \ == suffixLinkFrom->m_edges.end()) ?\r\n\t\t\t\tsuffixLinkFrom->m_edges.find('\
    \ ')->second :\r\n\t\t\t\tsuffixLinkFrom->m_edges.find(s[itr])->second);\r\n\t\
    \t\tm_edges.emplace(s[itr], newNode);\r\n\t\t\treturn std::weak_ptr<Node>(newNode);\r\
    \n\t\t}\r\n\r\n\tpublic:\r\n\t\t// constructor\r\n\t\tNode(int size, const std::weak_ptr<Node>&\
    \ suffixLink) :\r\n\t\t\tm_size(size),\r\n\t\t\tm_suffixLink(suffixLink) {}\r\n\
    \t\tNode() :m_size(-1) {}\r\n\r\n\r\n\t\t// \u6B21\u30B5\u30A4\u30BA\u306E\u56DE\
    \u6587\u3092\u8FFD\u52A0\r\n\t\tauto add(int itr, const std::string& s) {\r\n\t\
    \t\tauto addRoot = find(itr, s).lock();\r\n\t\t\tauto nextNode = (addRoot->m_edges.find(s[itr])\
    \ == addRoot->m_edges.end()) ?\r\n\t\t\t\taddRoot->create(itr, s) :\r\n\t\t\t\t\
    std::weak_ptr<Node>(addRoot->m_edges.find(s[itr])->second);\r\n\t\t\tnextNode.lock()->m_itrs.emplace_back(itr);\r\
    \n\t\t\treturn nextNode;\r\n\t\t}\r\n\r\n\t\t// debug\u7528\r\n\t\tauto outputTree(const\
    \ std::string& s) ->void const {\r\n\t\t\tif (m_size <= 0) { cout << \"root\"\
    ; } else {\r\n\t\t\t\t// \u6BB5\r\n\t\t\t\tfor (int i = 0; (i < (m_size + 1) /\
    \ 2); ++i) { cout << \" |\"; }\r\n\t\t\t\tcout << \"- \" << s.substr(*m_itrs.begin()\
    \ - m_size + 1, m_size);\r\n\t\t\t\t// \u53F3itr\r\n\t\t\t\tcout << \" [ \"; for\
    \ (const auto& itr : m_itrs) { cout << itr << \" \"; }cout << \"] \";\r\n\t\t\t\
    \t// suffix link\r\n\t\t\t\t//auto p = m_suffixLink.lock();\r\n\t\t\t\t//cout\
    \ << \"{\" << s.substr(*p->m_itrs.begin() - p->m_size + 1, p->m_size) << \"} \"\
    ;\r\n\t\t\t} cout << \"\\n\";\r\n\t\t\tfor (const auto& edge : m_edges) {\r\n\t\
    \t\t\tif (m_size == -1 && edge.first == ' ') { continue; }\r\n\t\t\t\tedge.second->outputTree(s);\r\
    \n\t\t\t}\r\n\t\t}\r\n\r\n\t\t// root\u3092\u6C7A\u5B9A\r\n\t\tauto isOddRoot(const\
    \ std::weak_ptr<Node>& evenRoot) {\r\n\t\t\tm_suffixLink = weak_from_this();\r\
    \n\t\t\tm_edges.emplace(' ', evenRoot);\r\n\t\t}\r\n\r\n\t\t// \u30E9\u30E0\u30C0\
    \u5F0F\u306E\u5B9F\u884C\r\n\t\ttemplate<class Lambda>\r\n\t\tauto runLambda(const\
    \ Lambda& lambda) {\r\n\t\t\tif (m_size > 0) { lambda(m_size, m_itrs); }\r\n\t\
    \t}\r\n\r\n\t\t/*\r\n\t\t * lambda: (int size, list<int> rItr) -> void\r\n\t\t\
    \ */\r\n\t\ttemplate<class Lambda, class SuffixLinkLambda = decltype(nullLambda)>\r\
    \n\t\tauto dfs_edges(const Lambda& lambda, const SuffixLinkLambda& slLambda =\
    \ nullLambda)->void {\r\n\t\t\trunLambda(lambda);\r\n\t\t\tm_suffixLink.lock()->runLambda(slLambda);\r\
    \n\t\t\tfor (const auto& edge : m_edges) {\r\n\t\t\t\tedge.second->dfs_edges(lambda,\
    \ slLambda);\r\n\t\t\t}\r\n\t\t}\r\n\t};\r\n\r\n\t// \u5BFE\u8C61\u3068\u306A\u308B\
    \u6587\u5B57\u5217\r\n\tconst std::string m_s;\r\n\r\n\t// \u5076\u6570\u9577\uFF0C\
    \u5947\u6570\u9577\u306EPalindromicTree\u306E\u6839(0, -1)\r\n\tstd::shared_ptr<Node>\
    \ m_rootOdd;\r\n\tstd::shared_ptr<Node> m_rootEven;\r\npublic:\r\n\t// constructor\r\
    \n\tPalindromicTree(const std::string& s) :\r\n\t\tm_s(s),\r\n\t\tm_rootOdd(std::make_shared<Node>()),\r\
    \n\t\tm_rootEven(std::make_shared<Node>(0, m_rootOdd)) {\r\n\t\tm_rootOdd->isOddRoot(m_rootEven);\r\
    \n\t\tauto root = m_rootOdd;\r\n\t\tfor (int r = 0; r < s.size(); ++r) {\r\n\t\
    \t\troot = root->add(r, s).lock();\r\n\t\t}\r\n\t}\r\n\r\n\t/*\r\n\t * lambda:\
    \ (int size, list<int> rItr) -> void\r\n\t */\r\n\ttemplate<class Lambda>\r\n\t\
    auto dfs_edges(const Lambda& lambda) {\r\n\t\tm_rootOdd->dfs_edges(lambda);\r\n\
    \t}\r\n\r\n\t/*\r\n\t * \u304B\u306A\u308A\u5F37\u5F15\u306A\u5B9F\u88C5\r\n\t\
    \ * lambda: (int from, int to) -> void\r\n\t */\r\n\ttemplate<class Lambda>\r\n\
    \tauto dp_suffixLink(const Lambda& lambda) {\r\n\t\t// \u68EE\u306E\u751F\u6210\
    \uFF0C\u63A2\u7D22\u9806\u5E8F\u306E\u6C7A\u5B9A\r\n\t\tint from;\r\n\t\tstd::unordered_map<int,\
    \ int> graph;\r\n\t\tstd::vector<int> orderCount(m_s.size());\r\n\t\tm_rootOdd->dfs_edges([&](int\
    \ size, const std::list<int>& rItrs) {\r\n\t\t\tfrom = rItrs.front();\r\n\t\t\
    }, [&](int size, const std::list<int>& rItrs) {\r\n\t\t\tint to = rItrs.front();\r\
    \n\t\t\tgraph.emplace(from, to);\r\n\t\t\t++orderCount[to];\r\n\t\t});\r\n\t\t\
    // \u63A2\u7D22\u9806\u5E8F\u306B\u5F93\u3063\u3066\u51E6\u7406\r\n\t\tstd::queue<int>\
    \ q;\r\n\t\tfor (int i = 0; i < m_s.size(); ++i)if (orderCount[i] == 0) { q.emplace(i);\
    \ }\r\n\t\twhile (!q.empty()) {\r\n\t\t\tint from = q.front();\r\n\t\t\tq.pop();\r\
    \n\t\t\tauto range = graph.equal_range(from);\r\n\t\t\tfor (auto itr = range.first;\
    \ itr != range.second; ++itr) {\r\n\t\t\t\tint to = itr->second;\r\n\t\t\t\t--orderCount[to];\r\
    \n\t\t\t\tlambda(from, to);\r\n\t\t\t\tif (orderCount[to] == 0) { q.emplace(to);\
    \ }\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\t// debug\u7528\r\n\tauto outputTree()\
    \ {\r\n\t\tdump(m_s);\r\n\t\tcout << \"-- even --\\n\";\r\n\t\tm_rootEven->outputTree(m_s);\r\
    \n\t\tcout << \"-- odd --\\n\";\r\n\t\tm_rootOdd->outputTree(m_s);\r\n\t}\r\n\
    };"
  dependsOn:
  - Utils/debug.hpp
  isVerificationFile: false
  path: Library/String/PalindromicTree.hpp
  requiredBy: []
  timestamp: '2022-08-30 05:07:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/String/PalindromicTree.hpp
layout: document
redirect_from:
- /library/Library/String/PalindromicTree.hpp
- /library/Library/String/PalindromicTree.hpp.html
title: Library/String/PalindromicTree.hpp
---
