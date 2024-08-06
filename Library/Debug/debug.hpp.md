---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Debug/debug.hpp\"\n#include <concepts>\n#include\
    \ <deque>\n#include <iostream>\n#include <string_view>\n\ntemplate <class T>\n\
    constexpr inline auto d_val(T a, T b) {\n  return b;\n}\n\n// debug\u7528\u51FA\
    \u529B\u30DE\u30AF\u30ED\n#define dump(...)                                  \
    \             \\\n  do {                                                     \
    \     \\\n    auto __DUMP_NAME_LIST__ = split(#__VA_ARGS__, ',');         \\\n\
    \    splitVariables(std::move(__DUMP_NAME_LIST__), __VA_ARGS__); \\\n  } while\
    \ (false)\n\n// split\ninline auto split(std::string_view str, char del = ' ')\
    \ {\n  std::deque<std::string_view> sList;\n  int from = 0;\n  for (int i = 0;\
    \ auto&& c : str) {\n    if (c == del) {\n      sList.emplace_back(str.substr(from,\
    \ i - from));\n      from = i + 1;\n    }\n    if (c == ' ') { ++from; }\n   \
    \ ++i;\n  }\n  sList.emplace_back(str.substr(from, str.size() - from));\n  return\
    \ sList;\n}\n// \u5236\u7D04\ntemplate <class T>\nconcept Container = requires(T\
    \ x) {\n  x.begin();\n};\n\ntemplate <class T>\nconcept Printable = requires(T\
    \ x) {\n  std::cerr << x;\n};\n\n// \u5BA3\u8A00\ntemplate <class S, class T>\n\
    constexpr auto print(const std::pair<S, T>&, bool b = true);\ninline auto print(const\
    \ std::string&, bool b = true);\nconstexpr auto print(const Printable auto&, bool\
    \ b = true);\nconstexpr auto print(const Container auto&, bool b = true);\n//\
    \ \u5B9A\u7FA9\nconstexpr auto print(const auto&, bool) {\n  std::cerr << \"<ERROR!>\
    \ \\\"print\\\" of This type is not defined.\" << '\\n';\n}\ntemplate <class S,\
    \ class T>\nconstexpr auto print(const std::pair<S, T>& p, bool b) {\n  std::cerr\
    \ << '(';\n  print(p.first, false);\n  std::cerr << \", \";\n  print(p.second,\
    \ false);\n  std::cerr << ')';\n  if (b) { std::cerr << \" \"; }\n}\ninline auto\
    \ print(const std::string& s, bool b) {\n  std::cerr << s;\n  if (b) { std::cerr\
    \ << std::endl; }\n}\nconstexpr auto print(const Printable auto& p, bool b) {\n\
    \  std::cerr << p;\n  if (b) { std::cerr << ' '; }\n}\nconstexpr auto print(const\
    \ Container auto& c, bool b) {\n  for (auto&& x : c) { print(x); }\n  if (b) {\
    \ std::cerr << '\\n'; }\n}\n\n// \u5909\u6570\u306E\u51FA\u529B\nconstexpr auto\
    \ printVariable(auto&& name, const auto& p) {\n  std::cerr << name << \": \";\n\
    \  print(p);\n  std::cerr << '\\n';\n}\ninline auto printVariable(auto&& name,\
    \ const std::string& s) {\n  std::cerr << name << \": \";\n  print(s);\n  std::cerr\
    \ << '\\n';\n}\nconstexpr auto printVariable(auto&& name, const Container auto&\
    \ c) {\n  std::cerr << \"-- \" << name << \" --\" << '\\n';\n  print(c);\n}\n\n\
    // 1\u5909\u6570\u305A\u3064\u51E6\u7406\nconstexpr auto splitVariables(auto&&\
    \ names) {}\nconstexpr auto splitVariables(auto&& names, const auto& x,\n    \
    \                          const auto&... tail) {\n  printVariable(names.front(),\
    \ x);\n  names.pop_front();\n  splitVariables(std::forward<decltype(names)>(names),\
    \ tail...);\n}\n"
  code: "#pragma once\n#include <concepts>\n#include <deque>\n#include <iostream>\n\
    #include <string_view>\n\ntemplate <class T>\nconstexpr inline auto d_val(T a,\
    \ T b) {\n  return b;\n}\n\n// debug\u7528\u51FA\u529B\u30DE\u30AF\u30ED\n#define\
    \ dump(...)                                               \\\n  do {         \
    \                                                 \\\n    auto __DUMP_NAME_LIST__\
    \ = split(#__VA_ARGS__, ',');         \\\n    splitVariables(std::move(__DUMP_NAME_LIST__),\
    \ __VA_ARGS__); \\\n  } while (false)\n\n// split\ninline auto split(std::string_view\
    \ str, char del = ' ') {\n  std::deque<std::string_view> sList;\n  int from =\
    \ 0;\n  for (int i = 0; auto&& c : str) {\n    if (c == del) {\n      sList.emplace_back(str.substr(from,\
    \ i - from));\n      from = i + 1;\n    }\n    if (c == ' ') { ++from; }\n   \
    \ ++i;\n  }\n  sList.emplace_back(str.substr(from, str.size() - from));\n  return\
    \ sList;\n}\n// \u5236\u7D04\ntemplate <class T>\nconcept Container = requires(T\
    \ x) {\n  x.begin();\n};\n\ntemplate <class T>\nconcept Printable = requires(T\
    \ x) {\n  std::cerr << x;\n};\n\n// \u5BA3\u8A00\ntemplate <class S, class T>\n\
    constexpr auto print(const std::pair<S, T>&, bool b = true);\ninline auto print(const\
    \ std::string&, bool b = true);\nconstexpr auto print(const Printable auto&, bool\
    \ b = true);\nconstexpr auto print(const Container auto&, bool b = true);\n//\
    \ \u5B9A\u7FA9\nconstexpr auto print(const auto&, bool) {\n  std::cerr << \"<ERROR!>\
    \ \\\"print\\\" of This type is not defined.\" << '\\n';\n}\ntemplate <class S,\
    \ class T>\nconstexpr auto print(const std::pair<S, T>& p, bool b) {\n  std::cerr\
    \ << '(';\n  print(p.first, false);\n  std::cerr << \", \";\n  print(p.second,\
    \ false);\n  std::cerr << ')';\n  if (b) { std::cerr << \" \"; }\n}\ninline auto\
    \ print(const std::string& s, bool b) {\n  std::cerr << s;\n  if (b) { std::cerr\
    \ << std::endl; }\n}\nconstexpr auto print(const Printable auto& p, bool b) {\n\
    \  std::cerr << p;\n  if (b) { std::cerr << ' '; }\n}\nconstexpr auto print(const\
    \ Container auto& c, bool b) {\n  for (auto&& x : c) { print(x); }\n  if (b) {\
    \ std::cerr << '\\n'; }\n}\n\n// \u5909\u6570\u306E\u51FA\u529B\nconstexpr auto\
    \ printVariable(auto&& name, const auto& p) {\n  std::cerr << name << \": \";\n\
    \  print(p);\n  std::cerr << '\\n';\n}\ninline auto printVariable(auto&& name,\
    \ const std::string& s) {\n  std::cerr << name << \": \";\n  print(s);\n  std::cerr\
    \ << '\\n';\n}\nconstexpr auto printVariable(auto&& name, const Container auto&\
    \ c) {\n  std::cerr << \"-- \" << name << \" --\" << '\\n';\n  print(c);\n}\n\n\
    // 1\u5909\u6570\u305A\u3064\u51E6\u7406\nconstexpr auto splitVariables(auto&&\
    \ names) {}\nconstexpr auto splitVariables(auto&& names, const auto& x,\n    \
    \                          const auto&... tail) {\n  printVariable(names.front(),\
    \ x);\n  names.pop_front();\n  splitVariables(std::forward<decltype(names)>(names),\
    \ tail...);\n}"
  dependsOn: []
  isVerificationFile: false
  path: Library/Debug/debug.hpp
  requiredBy: []
  timestamp: '2024-08-06 04:18:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Debug/debug.hpp
layout: document
redirect_from:
- /library/Library/Debug/debug.hpp
- /library/Library/Debug/debug.hpp.html
title: Library/Debug/debug.hpp
---
