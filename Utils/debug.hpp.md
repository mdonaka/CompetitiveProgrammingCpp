---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Library/String/PalindromicTree.hpp
    title: Library/String/PalindromicTree.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utils/debug.hpp\"\n#define IGNORE\n#include <concepts>\n\
    #include <iostream>\n#include <list>\n#include <string_view>\n\ntemplate<class\
    \ T>constexpr inline auto d_val(T a, T b) { return b; }\n\n// debug\u7528\u51FA\
    \u529B\u30DE\u30AF\u30ED\n#define dump(...)                                  \
    \             \\\n  do {                                                     \
    \     \\\n    auto __DUMP_NAME_LIST__ = split(#__VA_ARGS__, ',');         \\\n\
    \    splitVariables(std::move(__DUMP_NAME_LIST__), __VA_ARGS__); \\\n  } while\
    \ (false)\n\n// \u51FA\u529B\u3067\u304D\u308B\u7A2E\u985E\u306E\u8FFD\u52A0\n\
    template<class S, class T>\nstd::ostream& operator<<(std::ostream& os, const std::pair<S,\
    \ T>& p) {\n\tos << \"(\" << p.first << \", \" << p.second << \")\";\n\treturn\
    \ os;\n}\n// split\ninline auto split(std::string_view str, char del = ' ') {\n\
    \tstd::list<std::string_view> sList;\n\tint from = -1;\n\tfor (int i = 0; auto\
    \ && c : str) {\n\t\tif (c == ' ') {\n\t\t\tsList.emplace_back(str.substr(from\
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
    \ tail...);\n}\n"
  code: "#pragma once\n#define IGNORE\n#include <concepts>\n#include <iostream>\n\
    #include <list>\n#include <string_view>\n\ntemplate<class T>constexpr inline auto\
    \ d_val(T a, T b) { return b; }\n\n// debug\u7528\u51FA\u529B\u30DE\u30AF\u30ED\
    \n#define dump(...)                                               \\\n  do { \
    \                                                         \\\n    auto __DUMP_NAME_LIST__\
    \ = split(#__VA_ARGS__, ',');         \\\n    splitVariables(std::move(__DUMP_NAME_LIST__),\
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
    \ tail...);\n}"
  dependsOn: []
  isVerificationFile: false
  path: Utils/debug.hpp
  requiredBy:
  - Library/String/PalindromicTree.hpp
  timestamp: '2022-08-30 05:07:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utils/debug.hpp
layout: document
redirect_from:
- /library/Utils/debug.hpp
- /library/Utils/debug.hpp.html
title: Utils/debug.hpp
---
