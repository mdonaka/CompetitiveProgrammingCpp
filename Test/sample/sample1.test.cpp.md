---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Utils/Timer.hpp
    title: Utils/Timer.hpp
  - icon: ':x:'
    path: Utils/debug.hpp
    title: Utils/debug.hpp
  - icon: ':x:'
    path: Utils/sample.hpp
    title: Utils/sample.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "#line 1 \"Test/sample/sample1.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n#include <iostream>\n\n#line 2 \"Utils/debug.hpp\"\n#include <concepts>\n#line\
    \ 4 \"Utils/debug.hpp\"\n#include <list>\n#include <string_view>\n\ntemplate<class\
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
    \ tail...);\n}\n#line 2 \"Utils/sample.hpp\"\n#include <random>\r\n#include <vector>\r\
    \n#include <tuple>\r\n#line 6 \"Utils/sample.hpp\"\n\r\nnamespace Sample {\r\n\
    \r\n\tusing std::cout;\r\n\tconstexpr char endl = '\\n';\r\n\tclass Range {\r\n\
    \t\tconst uint_fast64_t l;\r\n\t\tconst uint_fast64_t u;\r\n\tpublic:\r\n\t\t\
    Range(uint_fast64_t l, uint_fast64_t u) :l(l), u(u) {}\r\n\t\tRange(uint_fast64_t\
    \ u) :l(0), u(u) {}\r\n\r\n\t\tauto normalize(uint_fast64_t val)const {\r\n\t\t\
    \treturn (val % (u + 1 - l)) + l;\r\n\t\t}\r\n\t};\r\n\r\n\tclass RandomGenerator\
    \ {\r\n\t\tstd::mt19937_64 mt;\r\n\tpublic:\r\n\t\tRandomGenerator(unsigned int\
    \ seed = std::random_device()()) : mt(std::mt19937_64(seed)) {}\r\n\r\n\t\t//\
    \ [l,u]\r\n\t\tauto random(const Range& range) { return range.normalize(mt());\
    \ }\r\n\t\tauto random(uint_fast64_t l, uint_fast64_t u) { return random(Range(l,\
    \ u)); }\r\n\t\tauto random(uint_fast64_t u) { return random(Range(0LL, u)); }\r\
    \n\r\n\t\tauto get_gen()const { return mt; }\r\n\t};\r\n\r\n\tclass SampleGenerator\
    \ {\r\n\t\tRandomGenerator rnd;\r\n\r\n\t\tauto generate_random(const Range& range)\
    \ {\r\n\t\t\treturn rnd.random(range);\r\n\t\t}\r\n\t\tauto generate_random(const\
    \ std::pair<int_fast64_t, int_fast64_t>& pair) { return rnd.random(Range(pair.first,\
    \ pair.second)); }\r\n\t\ttemplate<class T>\r\n\t\tauto generate_random(const\
    \ std::vector<T>& ranges) {\r\n\t\t\tstd::vector<long long> v;\r\n\t\t\tv.reserve(ranges.size());\r\
    \n\t\t\tfor (auto&& range : ranges) { v.emplace_back(generate_random(range));\
    \ }\r\n\t\t\treturn v;\r\n\t\t}\r\n\tpublic:\r\n\t\tSampleGenerator() :rnd() {}\r\
    \n\t\tSampleGenerator(unsigned int seed) :rnd(seed) {}\r\n\r\n\t\ttemplate<class\
    \ ... T>\r\n\t\tauto generate(T&& ...ranges) {\r\n\t\t\treturn std::make_tuple(generate_random(ranges)...);\r\
    \n\t\t}\r\n\r\n\t\tauto generate_permutation(int size) const {\r\n\t\t\tstd::vector<int>\
    \ rnd_p(size);\r\n\t\t\tstd::iota(rnd_p.begin(), rnd_p.end(), 0);\r\n\t\t\tstd::shuffle(rnd_p.begin(),\
    \ rnd_p.end(), rnd.get_gen());\r\n\t\t\treturn rnd_p;\r\n\t\t}\r\n\t};\r\n}\n\
    #line 1 \"Utils/Timer.hpp\"\n\uFEFF#pragma once\r\n\r\n#line 4 \"Utils/Timer.hpp\"\
    \n#include <chrono>\r\n#line 7 \"Utils/Timer.hpp\"\n\r\nnamespace Timer {\r\n\r\
    \n    /**\r\n     * \u6642\u9593\u306E\u5358\u4F4D\u7FA4\r\n     */\r\n    namespace\
    \ UNITS {\r\n        struct NANO {\r\n            using second = std::chrono::nanoseconds;\r\
    \n            static constexpr long long magnification = 1;\r\n            static\
    \ constexpr std::string_view str = \"ns\";\r\n        };\r\n        struct MICRO\
    \ {\r\n            using second = std::chrono::microseconds;\r\n            static\
    \ constexpr long long magnification = 1000;\r\n            static constexpr std::string_view\
    \ str = \"\u03BCs\";\r\n        };\r\n        struct MILLI {\r\n            using\
    \ second = std::chrono::milliseconds;\r\n            static constexpr long long\
    \ magnification = 1000000;\r\n            static constexpr std::string_view str\
    \ = \"ms\";\r\n        };\r\n        struct SECOND {\r\n            using second\
    \ = std::chrono::microseconds;\r\n            static constexpr long long magnification\
    \ = 1000000000;\r\n            static constexpr std::string_view str = \"s\";\r\
    \n        };\r\n    }\r\n\r\n    /**\r\n     * \u6642\u9593\u306E\u51FA\u529B\r\
    \n     */\r\n    template<class UNIT>\r\n    void _print(long long time) {\r\n\
    \        std::cerr << time << UNIT::str << std::endl;\r\n    }\r\n\r\n    /**\r\
    \n     * \u7C21\u6613\u6642\u9593\u8A08\u6E2C\u30AF\u30E9\u30B9\r\n     * \u958B\
    \u59CB\u304B\u3089\u306E\u6642\u9593\u306E\u307F\u8A08\u6E2C\r\n     */\r\n  \
    \  class SimpleTimer {\r\n        std::chrono::system_clock::time_point start;\r\
    \n\r\n    public:\r\n        SimpleTimer() :start(std::chrono::system_clock::now())\
    \ {}\r\n        SimpleTimer& operator=(SimpleTimer&& tm) { start = std::move(tm.start);\
    \  return *this; }\r\n\r\n        template <class UNIT = std::chrono::nanoseconds>\r\
    \n        auto now() const {\r\n            const auto now = std::chrono::system_clock::now();\r\
    \n            return std::chrono::duration_cast<UNIT>(now - start).count();\r\n\
    \        }\r\n\r\n        template<class UNIT = UNITS::NANO>\r\n        auto print()\
    \ const {\r\n            _print<UNIT>(now<typename UNIT::second>());\r\n     \
    \   }\r\n    };\r\n\r\n    /**\r\n     * \u30E9\u30C3\u30D7\u4ED8\u304D\u6642\u9593\
    \u8A08\u6E2C\u30AF\u30E9\u30B9\r\n     */\r\n    class LapTimer {\r\n        std::list<long\
    \ long> lapTimeList;\r\n        SimpleTimer timer;\r\n    public:\r\n        LapTimer()\
    \ :timer(SimpleTimer()) {}\r\n\r\n        auto lap() {\r\n            lapTimeList.emplace_back(timer.now());\r\
    \n            timer = SimpleTimer();\r\n        }\r\n\r\n        template<class\
    \ UNIT = UNITS::NANO>\r\n        auto print() const {\r\n            for(auto&&\
    \ t : lapTimeList) {\r\n                _print<UNIT>(t / UNIT::magnification);\r\
    \n            }\r\n        }\r\n    };\r\n}\n#line 7 \"Test/sample/sample1.test.cpp\"\
    \n\nint main() {\n    int a, b;\n    std::cin >> a >> b;\n    std::cout << a +\
    \ b << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include <iostream>\n\
    \n#include \"./../../Utils/debug.hpp\"\n#include \"./../../Utils/sample.hpp\"\n\
    #include \"./../../Utils/Timer.hpp\"\n\nint main() {\n    int a, b;\n    std::cin\
    \ >> a >> b;\n    std::cout << a + b << std::endl;\n}\n"
  dependsOn:
  - Utils/debug.hpp
  - Utils/sample.hpp
  - Utils/Timer.hpp
  isVerificationFile: true
  path: Test/sample/sample1.test.cpp
  requiredBy: []
  timestamp: '2022-09-13 04:17:20+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/sample/sample1.test.cpp
layout: document
redirect_from:
- /verify/Test/sample/sample1.test.cpp
- /verify/Test/sample/sample1.test.cpp.html
title: Test/sample/sample1.test.cpp
---
