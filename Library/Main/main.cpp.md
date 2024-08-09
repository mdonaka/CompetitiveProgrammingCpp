---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Library/Debug/Dump.hpp
    title: Library/Debug/Dump.hpp
  - icon: ':warning:'
    path: Library/Debug/Test.hpp
    title: Library/Debug/Test.hpp
  - icon: ':warning:'
    path: Library/Debug/Timer.hpp
    title: Library/Debug/Timer.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Library/Main/main.cpp\"\n#include <algorithm>\r\n#include\
    \ <bitset>\r\n#include <cassert>\r\n#include <cmath>\r\n#include <complex>\r\n\
    #include <functional>\r\n#include <iomanip>\r\n#include <iostream>\r\n#include\
    \ <list>\r\n#include <map>\r\n#include <memory>\r\n#include <numeric>\r\n#include\
    \ <queue>\r\n#include <random>\r\n#include <ranges>\r\n#include <set>\r\n#include\
    \ <stack>\r\n#include <stdexcept>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <unordered_set>\r\n#include <vector>\r\n\r\n// clang-format off\r\n\
    /* macro func */\r\ntemplate<class T, class S>\r\ninline auto chmax(T& t, const\
    \ S& s) { if(s > t) { t = s; return true; } return false; }\r\ntemplate<class\
    \ T, class S>\r\ninline auto chmin(T& t, const S& s) { if(s < t) { t = s; return\
    \ true; } return false; }\r\ntemplate<class S> constexpr auto vec(S x) { return\
    \ x; }\r\ntemplate<class S, class... T> constexpr auto vec(S x, int n, T... ns)\
    \ { return std::vector(n, vec(x, ns...)); }\r\n\r\n/* Initial processing  */\r\
    \nstruct Preprocessing { Preprocessing() { std::cin.tie(0); std::ios::sync_with_stdio(0);\
    \ }; }_Preprocessing;\r\n\r\n/* input */\r\ntemplate<class T> std::istream& operator\
    \ >> (std::istream& is, std::vector<T>& vec) { for(T& x : vec) is >> x; return\
    \ is; }\r\n\r\n// clang-format on\r\n//=============================================================================================\r\
    \n// begin:tag debug\r\n#line 2 \"Library/Debug/Dump.hpp\"\n#include <concepts>\n\
    #include <deque>\n#line 5 \"Library/Debug/Dump.hpp\"\n#include <string_view>\n\
    \ntemplate <class T>\nconstexpr inline auto d_val(T a, T b) {\n  return b;\n}\n\
    \n// debug\u7528\u51FA\u529B\u30DE\u30AF\u30ED\n#define dump(...)            \
    \                                   \\\n  do {                               \
    \                           \\\n    auto __DUMP_NAME_LIST__ = split(#__VA_ARGS__,\
    \ ',');         \\\n    splitVariables(std::move(__DUMP_NAME_LIST__), __VA_ARGS__);\
    \ \\\n  } while (false)\n\n// split\ninline auto split(std::string_view str, char\
    \ del = ' ') {\n  std::deque<std::string_view> sList;\n  int from = 0;\n  for\
    \ (int i = 0; auto&& c : str) {\n    if (c == del) {\n      sList.emplace_back(str.substr(from,\
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
    \ tail...);\n}\n#line 6 \"Library/Debug/Test.hpp\"\n\r\n#line 1 \"Library/Debug/Timer.hpp\"\
    \n\uFEFF#pragma once\r\n\r\n#include <chrono>\r\n#line 7 \"Library/Debug/Timer.hpp\"\
    \n\r\nnamespace Timer {\r\n\r\n  /**\r\n   * \u6642\u9593\u306E\u5358\u4F4D\u7FA4\
    \r\n   */\r\n  namespace UNITS {\r\n    struct NANO {\r\n      using second =\
    \ std::chrono::nanoseconds;\r\n      static constexpr long long magnification\
    \ = 1;\r\n      static constexpr std::string_view str = \"ns\";\r\n    };\r\n\
    \    struct MICRO {\r\n      using second = std::chrono::microseconds;\r\n   \
    \   static constexpr long long magnification = 1000;\r\n      static constexpr\
    \ std::string_view str = \"\u03BCs\";\r\n    };\r\n    struct MILLI {\r\n    \
    \  using second = std::chrono::milliseconds;\r\n      static constexpr long long\
    \ magnification = 1000000;\r\n      static constexpr std::string_view str = \"\
    ms\";\r\n    };\r\n    struct SECOND {\r\n      using second = std::chrono::microseconds;\r\
    \n      static constexpr long long magnification = 1000000000;\r\n      static\
    \ constexpr std::string_view str = \"s\";\r\n    };\r\n  }  // namespace UNITS\r\
    \n\r\n  /**\r\n   * \u6642\u9593\u306E\u51FA\u529B\r\n   */\r\n  template <class\
    \ UNIT>\r\n  void _print(long long time) {\r\n    std::cerr << time << UNIT::str\
    \ << std::endl;\r\n  }\r\n\r\n  /**\r\n   * \u7C21\u6613\u6642\u9593\u8A08\u6E2C\
    \u30AF\u30E9\u30B9\r\n   * \u958B\u59CB\u304B\u3089\u306E\u6642\u9593\u306E\u307F\
    \u8A08\u6E2C\r\n   */\r\n  class SimpleTimer {\r\n    std::chrono::system_clock::time_point\
    \ start;\r\n\r\n  public:\r\n    SimpleTimer() : start(std::chrono::system_clock::now())\
    \ {}\r\n    SimpleTimer& operator=(SimpleTimer&& tm) {\r\n      start = std::move(tm.start);\r\
    \n      return *this;\r\n    }\r\n\r\n    template <class UNIT = std::chrono::nanoseconds>\r\
    \n    auto now() const {\r\n      const auto now = std::chrono::system_clock::now();\r\
    \n      return std::chrono::duration_cast<UNIT>(now - start).count();\r\n    }\r\
    \n\r\n    template <class UNIT = UNITS::NANO>\r\n    auto print() const {\r\n\
    \      _print<UNIT>(now<typename UNIT::second>());\r\n    }\r\n  };\r\n\r\n  /**\r\
    \n   * \u30E9\u30C3\u30D7\u4ED8\u304D\u6642\u9593\u8A08\u6E2C\u30AF\u30E9\u30B9\
    \r\n   */\r\n  class LapTimer {\r\n    std::list<long long> lapTimeList;\r\n \
    \   SimpleTimer timer;\r\n\r\n  public:\r\n    LapTimer() : timer(SimpleTimer())\
    \ {}\r\n\r\n    auto lap() {\r\n      lapTimeList.emplace_back(timer.now());\r\
    \n      timer = SimpleTimer();\r\n    }\r\n\r\n    template <class UNIT = UNITS::NANO>\r\
    \n    auto print() const {\r\n      for (auto&& t : lapTimeList) { _print<UNIT>(t\
    \ / UNIT::magnification); }\r\n    }\r\n  };\r\n}  // namespace Timer\n#line 8\
    \ \"Library/Debug/Test.hpp\"\n\r\nnamespace Sample {\r\n\r\n  using std::cout;\r\
    \n  constexpr char endl = '\\n';\r\n  class Range {\r\n    const int_fast64_t\
    \ l;\r\n    const int_fast64_t u;\r\n\r\n  public:\r\n    Range(int_fast64_t l,\
    \ int_fast64_t u) : l(l), u(u) {}\r\n    Range(int_fast64_t u) : l(0), u(u) {}\r\
    \n    template <class S, class T>\r\n    Range(const std::pair<S, T>& p) : Range(p.first,\
    \ p.second) {}\r\n\r\n    auto normalize(uint_fast64_t val) const {\r\n      return\
    \ static_cast<int_fast64_t>(val % (u + 1 - l)) + l;\r\n    }\r\n  };\r\n\r\n \
    \ class RandomGenerator {\r\n    std::mt19937_64 mt;\r\n\r\n  public:\r\n    RandomGenerator(unsigned\
    \ int seed = std::random_device()())\r\n        : mt(std::mt19937_64(seed)) {}\r\
    \n\r\n    // [l,u]\r\n    auto random(const Range& range) { return range.normalize(mt());\
    \ }\r\n    auto random(int_fast64_t l, int_fast64_t u) { return random(Range(l,\
    \ u)); }\r\n    auto random(int_fast64_t u) { return random(Range(0LL, u)); }\r\
    \n\r\n    auto& get_gen() { return mt; }\r\n  };\r\n\r\n  class SampleGenerator\
    \ {\r\n    RandomGenerator rnd;\r\n\r\n    auto generate_random(const Range& range)\
    \ { return rnd.random(range); }\r\n    template <class T>\r\n    auto generate_random(const\
    \ std::pair<T, T>& pair) {\r\n      return rnd.random(Range(pair.first, pair.second));\r\
    \n    }\r\n    template <class T>\r\n    auto generate_random(const std::vector<T>&\
    \ ranges) {\r\n      std::vector<long long> v;\r\n      v.reserve(ranges.size());\r\
    \n      for (auto&& range : ranges) { v.emplace_back(generate_random(range));\
    \ }\r\n      return v;\r\n    }\r\n\r\n  public:\r\n    SampleGenerator() : rnd()\
    \ {}\r\n    SampleGenerator(unsigned int seed) : rnd(seed) {}\r\n\r\n    template\
    \ <class... T>\r\n    auto generate(T&&... ranges) {\r\n      return std::make_tuple(generate_random(ranges)...);\r\
    \n    }\r\n\r\n    auto generate_permutation(int size) {\r\n      std::vector<int>\
    \ rnd_p(size);\r\n      std::iota(rnd_p.begin(), rnd_p.end(), 0);\r\n      std::shuffle(rnd_p.begin(),\
    \ rnd_p.end(), rnd.get_gen());\r\n      return rnd_p;\r\n    }\r\n\r\n    auto\
    \ generate_string(const Range& range, int csize = 26) {\r\n      auto size = generate_random(range);\r\
    \n      auto v = generate_random(std::vector<Range>(size, {0, csize - 1}));\r\n\
    \      std::string s = \"\";\r\n      for (const auto& c : v) { s += c + 'a';\
    \ }\r\n      return std::make_tuple(size, s);\r\n    }\r\n\r\n    template <class\
    \ T>\r\n    auto shuffle(const std::vector<T>& v_) {\r\n      auto v = v_;\r\n\
    \      std::shuffle(v.begin(), v.end(), rnd.get_gen());\r\n      return v;\r\n\
    \    }\r\n  };\r\n\r\n  namespace Inner {\r\n    template <int N>\r\n    struct\
    \ Expand {\r\n      template <typename F, typename Tuple, typename... Args>\r\n\
    \      static auto apply(F& f, Tuple& t, Args&... args) {\r\n        return Expand<N\
    \ - 1>::apply(f, t, std::get<N - 1>(t), args...);\r\n      }\r\n    };\r\n\r\n\
    \    template <>\r\n    struct Expand<0> {\r\n      template <typename F, typename\
    \ Tuple, typename... Args>\r\n      static auto apply(F& f, Tuple& t, Args&...\
    \ args) {\r\n        return f(args...);\r\n      }\r\n    };\r\n\r\n    template\
    \ <typename F, typename Tuple>\r\n    auto apply(F& f, Tuple& t) {\r\n      return\
    \ Expand<std::tuple_size<Tuple>::value>::apply(f, t);\r\n    }\r\n  };  // namespace\
    \ Inner\r\n\r\n  class RandomCaseDebugger {\r\n  public:\r\n    auto compare(int\
    \ conut, const auto& gen, const auto& outputer,\r\n                 const auto&\
    \ solver1, const auto& solver2,\r\n                 int output_itr = 1000) {\r\
    \n      for (int i = 1; i <= conut; ++i) {\r\n        if (i == 1 || (i > 0 &&\
    \ i % output_itr == 0)) {\r\n          std::cerr << \"-- \" << i << \"th run -\"\
    \ << endl;\r\n        }\r\n        auto args = gen();\r\n        if (Inner::apply(solver1,\
    \ args) != Inner::apply(solver2, args)) {\r\n          std::cerr << \"Failed test\"\
    \ << std::endl;\r\n          Inner::apply(outputer, args);\r\n          return\
    \ false;\r\n        }\r\n      }\r\n      std::cerr << \"All test are success!\"\
    \ << std::endl;\r\n      return true;\r\n    }\r\n    auto run(int conut, const\
    \ auto& gen, const auto& solver) {\r\n      auto tm = Timer::LapTimer();\r\n \
    \     for (int i = 1; i <= conut; ++i) {\r\n        auto tm = Timer::SimpleTimer();\r\
    \n        auto args = gen();\r\n        Inner::apply(solver, args);\r\n      \
    \  tm.print<Timer::UNITS::MILLI>();\r\n      }\r\n    }\r\n  };\r\n\r\n}  // namespace\
    \ Sample\n#line 1 \"Library/Debug/Timer.hpp\"\n\uFEFF#pragma once\r\n\r\n#line\
    \ 7 \"Library/Debug/Timer.hpp\"\n\r\nnamespace Timer {\r\n\r\n  /**\r\n   * \u6642\
    \u9593\u306E\u5358\u4F4D\u7FA4\r\n   */\r\n  namespace UNITS {\r\n    struct NANO\
    \ {\r\n      using second = std::chrono::nanoseconds;\r\n      static constexpr\
    \ long long magnification = 1;\r\n      static constexpr std::string_view str\
    \ = \"ns\";\r\n    };\r\n    struct MICRO {\r\n      using second = std::chrono::microseconds;\r\
    \n      static constexpr long long magnification = 1000;\r\n      static constexpr\
    \ std::string_view str = \"\u03BCs\";\r\n    };\r\n    struct MILLI {\r\n    \
    \  using second = std::chrono::milliseconds;\r\n      static constexpr long long\
    \ magnification = 1000000;\r\n      static constexpr std::string_view str = \"\
    ms\";\r\n    };\r\n    struct SECOND {\r\n      using second = std::chrono::microseconds;\r\
    \n      static constexpr long long magnification = 1000000000;\r\n      static\
    \ constexpr std::string_view str = \"s\";\r\n    };\r\n  }  // namespace UNITS\r\
    \n\r\n  /**\r\n   * \u6642\u9593\u306E\u51FA\u529B\r\n   */\r\n  template <class\
    \ UNIT>\r\n  void _print(long long time) {\r\n    std::cerr << time << UNIT::str\
    \ << std::endl;\r\n  }\r\n\r\n  /**\r\n   * \u7C21\u6613\u6642\u9593\u8A08\u6E2C\
    \u30AF\u30E9\u30B9\r\n   * \u958B\u59CB\u304B\u3089\u306E\u6642\u9593\u306E\u307F\
    \u8A08\u6E2C\r\n   */\r\n  class SimpleTimer {\r\n    std::chrono::system_clock::time_point\
    \ start;\r\n\r\n  public:\r\n    SimpleTimer() : start(std::chrono::system_clock::now())\
    \ {}\r\n    SimpleTimer& operator=(SimpleTimer&& tm) {\r\n      start = std::move(tm.start);\r\
    \n      return *this;\r\n    }\r\n\r\n    template <class UNIT = std::chrono::nanoseconds>\r\
    \n    auto now() const {\r\n      const auto now = std::chrono::system_clock::now();\r\
    \n      return std::chrono::duration_cast<UNIT>(now - start).count();\r\n    }\r\
    \n\r\n    template <class UNIT = UNITS::NANO>\r\n    auto print() const {\r\n\
    \      _print<UNIT>(now<typename UNIT::second>());\r\n    }\r\n  };\r\n\r\n  /**\r\
    \n   * \u30E9\u30C3\u30D7\u4ED8\u304D\u6642\u9593\u8A08\u6E2C\u30AF\u30E9\u30B9\
    \r\n   */\r\n  class LapTimer {\r\n    std::list<long long> lapTimeList;\r\n \
    \   SimpleTimer timer;\r\n\r\n  public:\r\n    LapTimer() : timer(SimpleTimer())\
    \ {}\r\n\r\n    auto lap() {\r\n      lapTimeList.emplace_back(timer.now());\r\
    \n      timer = SimpleTimer();\r\n    }\r\n\r\n    template <class UNIT = UNITS::NANO>\r\
    \n    auto print() const {\r\n      for (auto&& t : lapTimeList) { _print<UNIT>(t\
    \ / UNIT::magnification); }\r\n    }\r\n  };\r\n}  // namespace Timer\n#line 45\
    \ \"Library/Main/main.cpp\"\n// end:tag debug\r\n// begin:tag includes\r\n\r\n\
    // end:tag includes\r\n//=============================================================================================\r\
    \n\r\nusing ll = long long;\r\n\r\nsigned main() {}\r\n"
  code: "#include <algorithm>\r\n#include <bitset>\r\n#include <cassert>\r\n#include\
    \ <cmath>\r\n#include <complex>\r\n#include <functional>\r\n#include <iomanip>\r\
    \n#include <iostream>\r\n#include <list>\r\n#include <map>\r\n#include <memory>\r\
    \n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\n#include <ranges>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <stdexcept>\r\n#include <string>\r\
    \n#include <unordered_map>\r\n#include <unordered_set>\r\n#include <vector>\r\n\
    \r\n// clang-format off\r\n/* macro func */\r\ntemplate<class T, class S>\r\n\
    inline auto chmax(T& t, const S& s) { if(s > t) { t = s; return true; } return\
    \ false; }\r\ntemplate<class T, class S>\r\ninline auto chmin(T& t, const S& s)\
    \ { if(s < t) { t = s; return true; } return false; }\r\ntemplate<class S> constexpr\
    \ auto vec(S x) { return x; }\r\ntemplate<class S, class... T> constexpr auto\
    \ vec(S x, int n, T... ns) { return std::vector(n, vec(x, ns...)); }\r\n\r\n/*\
    \ Initial processing  */\r\nstruct Preprocessing { Preprocessing() { std::cin.tie(0);\
    \ std::ios::sync_with_stdio(0); }; }_Preprocessing;\r\n\r\n/* input */\r\ntemplate<class\
    \ T> std::istream& operator >> (std::istream& is, std::vector<T>& vec) { for(T&\
    \ x : vec) is >> x; return is; }\r\n\r\n// clang-format on\r\n//=============================================================================================\r\
    \n// begin:tag debug\r\n#include \"./Library/Debug/Dump.hpp\"\r\n#include \"./Library/Debug/Test.hpp\"\
    \r\n#include \"./Library/Debug/Timer.hpp\"\r\n// end:tag debug\r\n// begin:tag\
    \ includes\r\n\r\n// end:tag includes\r\n//=============================================================================================\r\
    \n\r\nusing ll = long long;\r\n\r\nsigned main() {}\r\n"
  dependsOn:
  - Library/Debug/Dump.hpp
  - Library/Debug/Test.hpp
  - Library/Debug/Timer.hpp
  isVerificationFile: false
  path: Library/Main/main.cpp
  requiredBy: []
  timestamp: '2024-08-10 04:02:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Main/main.cpp
layout: document
redirect_from:
- /library/Library/Main/main.cpp
- /library/Library/Main/main.cpp.html
title: Library/Main/main.cpp
---
