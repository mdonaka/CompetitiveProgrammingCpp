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
  bundledCode: "#line 2 \"Utils/debug.hpp\"\n#include <concepts>\n#include <iostream>\n\
    #include <deque>\n#include <string_view>\n\ntemplate<class T>constexpr inline\
    \ auto d_val(T a, T b) { return b; }\n\n// debug\u7528\u51FA\u529B\u30DE\u30AF\
    \u30ED\n#define dump(...)                                               \\\n \
    \ do {                                                          \\\n    auto __DUMP_NAME_LIST__\
    \ = split(#__VA_ARGS__, ',');         \\\n    splitVariables(std::move(__DUMP_NAME_LIST__),\
    \ __VA_ARGS__); \\\n  } while (false)\n\n// split\ninline auto split(std::string_view\
    \ str, char del = ' ') {\n    std::deque<std::string_view> sList;\n    int from\
    \ = 0;\n    for(int i = 0; auto && c : str) {\n        if(c == del) {\n      \
    \      sList.emplace_back(str.substr(from, i - from));\n            from = i +\
    \ 1;\n        }\n        if(c == ' ') { ++from; }\n        ++i;\n    }\n    sList.emplace_back(str.substr(from,\
    \ str.size() - from));\n    return sList;\n}\n// \u5236\u7D04\ntemplate <class\
    \ T>\nconcept Container = requires(T x) {\n    x.begin();\n};\n\ntemplate <class\
    \ T>\nconcept Printable = requires(T x) {\n    std::cerr << x;\n};\n\n// \u51FA\
    \u529B\nconstexpr auto print(const auto&) {\n    std::cerr << \"<ERROR!> \\\"\
    print\\\" of This type is not defined.\" << '\\n';\n}\n// \u5BA3\u8A00\ntemplate<class\
    \ S, class T>\nconstexpr auto print(const std::pair<S, T>&, bool);\ninline auto\
    \ print(const std::string&, bool);\nconstexpr auto print(const Printable auto&,\
    \ bool);\nconstexpr auto print(const Container auto&, bool);\n// \u5B9A\u7FA9\n\
    template<class S, class T>\nconstexpr auto print(const std::pair<S, T>& p, bool\
    \ b = true) {\n    std::cerr << \"(\"; print(p.first, false);\n    std::cerr <<\
    \ \", \"; print(p.second, false);\n    std::cerr << \")\"; if(b) { std::cerr <<\
    \ \" \"; }\n}\ninline auto print(const std::string& s, bool b = true) {\n    std::cerr\
    \ << s;\n    if(b) { std::cerr << \" \"; }\n}\nconstexpr auto print(const Printable\
    \ auto& p, bool b = true) {\n    std::cerr << p;\n    if(b) { std::cerr << \"\
    \ \"; }\n}\nconstexpr auto print(const Container auto& c, bool b = true) {\n \
    \   for(auto&& x : c) { print(x); }\n    if(b) { std::cerr << '\\n'; }\n}\n\n\
    // \u5909\u6570\u306E\u51FA\u529B\nconstexpr auto printVariable(auto&& name, const\
    \ auto& p) {\n    std::cerr << name << \": \";\n    print(p);\n    std::cerr <<\
    \ '\\n';\n}\ninline auto printVariable(auto&& name, const std::string& s) {\n\
    \    std::cerr << name << \": \";\n    print(s);\n    std::cerr << '\\n';\n}\n\
    constexpr auto printVariable(auto&& name, const Container auto& c) {\n    std::cerr\
    \ << \"-- \" << name << \" --\" << '\\n';\n    print(c);\n}\n\n// 1\u5909\u6570\
    \u305A\u3064\u51E6\u7406\nconstexpr auto splitVariables(auto&& names) {}\nconstexpr\
    \ auto splitVariables(auto&& names, const auto& x,\n                         \
    \     const auto&... tail) {\n    printVariable(names.front(), x);\n    names.pop_front();\n\
    \    splitVariables(std::forward<decltype(names)>(names), tail...);\n}\n"
  code: "#pragma once\n#include <concepts>\n#include <iostream>\n#include <deque>\n\
    #include <string_view>\n\ntemplate<class T>constexpr inline auto d_val(T a, T\
    \ b) { return b; }\n\n// debug\u7528\u51FA\u529B\u30DE\u30AF\u30ED\n#define dump(...)\
    \                                               \\\n  do {                   \
    \                                       \\\n    auto __DUMP_NAME_LIST__ = split(#__VA_ARGS__,\
    \ ',');         \\\n    splitVariables(std::move(__DUMP_NAME_LIST__), __VA_ARGS__);\
    \ \\\n  } while (false)\n\n// split\ninline auto split(std::string_view str, char\
    \ del = ' ') {\n    std::deque<std::string_view> sList;\n    int from = 0;\n \
    \   for(int i = 0; auto && c : str) {\n        if(c == del) {\n            sList.emplace_back(str.substr(from,\
    \ i - from));\n            from = i + 1;\n        }\n        if(c == ' ') { ++from;\
    \ }\n        ++i;\n    }\n    sList.emplace_back(str.substr(from, str.size() -\
    \ from));\n    return sList;\n}\n// \u5236\u7D04\ntemplate <class T>\nconcept\
    \ Container = requires(T x) {\n    x.begin();\n};\n\ntemplate <class T>\nconcept\
    \ Printable = requires(T x) {\n    std::cerr << x;\n};\n\n// \u51FA\u529B\nconstexpr\
    \ auto print(const auto&) {\n    std::cerr << \"<ERROR!> \\\"print\\\" of This\
    \ type is not defined.\" << '\\n';\n}\n// \u5BA3\u8A00\ntemplate<class S, class\
    \ T>\nconstexpr auto print(const std::pair<S, T>&, bool);\ninline auto print(const\
    \ std::string&, bool);\nconstexpr auto print(const Printable auto&, bool);\nconstexpr\
    \ auto print(const Container auto&, bool);\n// \u5B9A\u7FA9\ntemplate<class S,\
    \ class T>\nconstexpr auto print(const std::pair<S, T>& p, bool b = true) {\n\
    \    std::cerr << \"(\"; print(p.first, false);\n    std::cerr << \", \"; print(p.second,\
    \ false);\n    std::cerr << \")\"; if(b) { std::cerr << \" \"; }\n}\ninline auto\
    \ print(const std::string& s, bool b = true) {\n    std::cerr << s;\n    if(b)\
    \ { std::cerr << \" \"; }\n}\nconstexpr auto print(const Printable auto& p, bool\
    \ b = true) {\n    std::cerr << p;\n    if(b) { std::cerr << \" \"; }\n}\nconstexpr\
    \ auto print(const Container auto& c, bool b = true) {\n    for(auto&& x : c)\
    \ { print(x); }\n    if(b) { std::cerr << '\\n'; }\n}\n\n// \u5909\u6570\u306E\
    \u51FA\u529B\nconstexpr auto printVariable(auto&& name, const auto& p) {\n   \
    \ std::cerr << name << \": \";\n    print(p);\n    std::cerr << '\\n';\n}\ninline\
    \ auto printVariable(auto&& name, const std::string& s) {\n    std::cerr << name\
    \ << \": \";\n    print(s);\n    std::cerr << '\\n';\n}\nconstexpr auto printVariable(auto&&\
    \ name, const Container auto& c) {\n    std::cerr << \"-- \" << name << \" --\"\
    \ << '\\n';\n    print(c);\n}\n\n// 1\u5909\u6570\u305A\u3064\u51E6\u7406\nconstexpr\
    \ auto splitVariables(auto&& names) {}\nconstexpr auto splitVariables(auto&& names,\
    \ const auto& x,\n                              const auto&... tail) {\n    printVariable(names.front(),\
    \ x);\n    names.pop_front();\n    splitVariables(std::forward<decltype(names)>(names),\
    \ tail...);\n}"
  dependsOn: []
  isVerificationFile: false
  path: Utils/debug.hpp
  requiredBy: []
  timestamp: '2023-06-09 23:40:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utils/debug.hpp
layout: document
redirect_from:
- /library/Utils/debug.hpp
- /library/Utils/debug.hpp.html
title: Utils/debug.hpp
---
