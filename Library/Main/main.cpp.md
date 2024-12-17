---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Debug/Dump.hpp
    title: Library/Debug/Dump.hpp
  - icon: ':warning:'
    path: Library/Debug/Test.hpp
    title: Library/Debug/Test.hpp
  - icon: ':warning:'
    path: Library/Debug/Timer.hpp
    title: Library/Debug/Timer.hpp
  - icon: ':warning:'
    path: Library/Main/includes.hpp
    title: Library/Main/includes.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Range/istream.hpp
    title: Library/Range/istream.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Range/util.hpp
    title: Library/Range/util.hpp
  - icon: ':warning:'
    path: Library/Utility/Tools.hpp
    title: Library/Utility/Tools.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Utility/Tuple.hpp
    title: Library/Utility/Tuple.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Utility/io.hpp
    title: Library/Utility/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Library/Main/main.cpp\"\n// begin:tag time\r\n// end:tag\
    \ time\r\n//=============================================================================================\r\
    \n// begin:tag debug\r\n#line 2 \"Library/Debug/Dump.hpp\"\n#include <concepts>\n\
    #include <deque>\n#include <functional>\n#include <iostream>\n#include <string_view>\n\
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
    \ x) {\n  std::cerr << x;\n};\n\n// \u5BA3\u8A00\ntemplate <class... T>\nconstexpr\
    \ auto print(const std::tuple<T...>&, bool b = true);\ntemplate <class S, class\
    \ T>\nconstexpr auto print(const std::pair<S, T>&, bool b = true);\ninline auto\
    \ print(const std::string&, bool b = true);\nconstexpr auto print(const Printable\
    \ auto&, bool b = true);\nconstexpr auto print(const Container auto&, bool b =\
    \ true);\n// \u5B9A\u7FA9\nconstexpr auto print(const auto&, bool) {\n  std::cerr\
    \ << \"<ERROR!> \\\"print\\\" of This type is not defined.\" << '\\n';\n}\n\n\
    template <class... T>\nconstexpr auto print(const std::tuple<T...>& t, bool b)\
    \ {\n  std::cerr << \"{\";\n  std::apply(\n      [&]<class... Ts>(Ts&&... elems)\
    \ {\n        (std::invoke([](auto i) { print(i, true); }, std::forward<Ts>(elems)),\n\
    \         ...);\n      },\n      t);\n  std::cerr << \"}\";\n  if (b) { std::cerr\
    \ << \" \"; }\n}\ntemplate <class S, class T>\nconstexpr auto print(const std::pair<S,\
    \ T>& p, bool b) {\n  std::cerr << '(';\n  print(p.first, false);\n  std::cerr\
    \ << \", \";\n  print(p.second, false);\n  std::cerr << ')';\n  if (b) { std::cerr\
    \ << \" \"; }\n}\ninline auto print(const std::string& s, bool b) {\n  std::cerr\
    \ << s;\n  if (b) { std::cerr << std::endl; }\n}\nconstexpr auto print(const Printable\
    \ auto& p, bool b) {\n  std::cerr << p;\n  if (b) { std::cerr << ' '; }\n}\nconstexpr\
    \ auto print(const Container auto& c, bool b) {\n  for (auto&& x : c) { print(x);\
    \ }\n  if (b) { std::cerr << '\\n'; }\n}\n\n// \u5909\u6570\u306E\u51FA\u529B\n\
    constexpr auto printVariable(auto&& name, const auto& p) {\n  std::cerr << name\
    \ << \": \";\n  print(p);\n  std::cerr << '\\n';\n}\ninline auto printVariable(auto&&\
    \ name, const std::string& s) {\n  std::cerr << name << \": \";\n  print(s);\n\
    \  std::cerr << '\\n';\n}\nconstexpr auto printVariable(auto&& name, const Container\
    \ auto& c) {\n  std::cerr << \"-- \" << name << \" --\" << '\\n';\n  print(c);\n\
    }\n\n// 1\u5909\u6570\u305A\u3064\u51E6\u7406\nconstexpr auto splitVariables(auto&&\
    \ names) {}\nconstexpr auto splitVariables(auto&& names, const auto& x,\n    \
    \                          const auto&... tail) {\n  printVariable(names.front(),\
    \ x);\n  names.pop_front();\n  splitVariables(std::forward<decltype(names)>(names),\
    \ tail...);\n}\n#line 2 \"Library/Debug/Test.hpp\"\n\r\n#include <algorithm>\r\
    \n#line 6 \"Library/Debug/Test.hpp\"\n#include <map>\r\n#include <random>\r\n\
    #include <ranges>\r\n#include <string>\r\n#include <tuple>\r\n#include <vector>\r\
    \n\r\n#line 1 \"Library/Debug/Timer.hpp\"\n\uFEFF#pragma once\r\n\r\n#include\
    \ <chrono>\r\n#line 5 \"Library/Debug/Timer.hpp\"\n#include <list>\r\n#line 7\
    \ \"Library/Debug/Timer.hpp\"\n\r\nnamespace Timer {\r\n\r\n  /**\r\n   * \u6642\
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
    \ / UNIT::magnification); }\r\n    }\r\n  };\r\n}  // namespace Timer\n#line 14\
    \ \"Library/Debug/Test.hpp\"\n\r\nnamespace mtd {\r\n  namespace debug {\r\n\r\
    \n    constexpr char endl = '\\n';\r\n    using engine = std::mt19937_64;\r\n\r\
    \n    namespace type {\r\n      template <class T>\r\n      class Range {\r\n\
    \        const T l;\r\n        const T u;\r\n\r\n      public:\r\n        Range(T\
    \ l, T u) : l(l), u(u) {}\r\n        Range(T u) : l(0), u(u) {}\r\n        Range(const\
    \ std::initializer_list<int>& v)\r\n            : l(*v.begin()), u(*std::next(v.begin()))\
    \ {}\r\n\r\n        auto generate(engine& mt) const {\r\n          return static_cast<T>(mt()\
    \ % (u + 1 - l) + l);\r\n        }\r\n      };\r\n\r\n      template <class T,\
    \ class U>\r\n      class Vector {\r\n        const Range<T> size;\r\n       \
    \ const Range<U> r;\r\n\r\n      public:\r\n        Vector(const Range<T>& size,\
    \ const Range<U>& r) : size(size), r(r) {}\r\n\r\n        auto generate(engine&\
    \ mt) const {\r\n          auto v_mt = std::vector<U>(size.generate(mt)) |\r\n\
    \                      std::views::transform([&](U) { return r.generate(mt); });\r\
    \n          return std::vector<U>(v_mt.begin(), v_mt.end());\r\n        }\r\n\
    \      };\r\n\r\n      template <class T>\r\n      class Permutation {\r\n   \
    \     const Range<T> size;\r\n\r\n      public:\r\n        Permutation(const Range<T>&\
    \ size) : size(size) {}\r\n        Permutation(const std::initializer_list<int>&\
    \ size)\r\n            : Permutation(Range<T>(size)) {}\r\n\r\n        auto generate(engine&\
    \ mt) const {\r\n          std::vector<T> p(size.generate(mt));\r\n          std::iota(p.begin(),\
    \ p.end(), 0);\r\n          std::shuffle(p.begin(), p.end(), mt);\r\n        \
    \  return p;\r\n        }\r\n      };\r\n\r\n      template <class T>\r\n    \
    \  class String {\r\n        const Range<T> size;\r\n        const Range<T> r;\r\
    \n\r\n      public:\r\n        String(const Range<T>& size, const Range<T>& r)\
    \ : size(size), r(r) {}\r\n\r\n        auto generate(engine& mt) const {\r\n \
    \         auto v_mt =\r\n              std::vector<T>(size.generate(mt)) | std::views::transform([&](T)\
    \ {\r\n                return static_cast<char>(r.generate(mt) + 'a');\r\n   \
    \           });\r\n          return std::string(v_mt.begin(), v_mt.end());\r\n\
    \        }\r\n      };\r\n\r\n      template <class T, bool directed, bool connected,\
    \ bool loop,\r\n                bool multiple>\r\n      class Graph {\r\n    \
    \    const Range<T> node_size;\r\n        const Range<T> edge_size;\r\n      \
    \  const Range<T> cost_size;\r\n\r\n      public:\r\n        Graph(const Range<T>&\
    \ node_size, const Range<T>& edge_size,\r\n              const Range<T>& cost_size\
    \ = {1, 1})\r\n            : node_size(node_size),\r\n              edge_size(edge_size),\r\
    \n              cost_size(cost_size) {}\r\n\r\n        auto generate(engine& mt)\
    \ const {\r\n          using Edge = std::pair<int, long long>;\r\n          auto\
    \ n = node_size.generate(mt);\r\n          auto m = edge_size.generate(mt);\r\n\
    \          if (!multiple) { m = std::min(m, n * (n - 1) / 2); }\r\n          if\
    \ (connected) { m = std::max(m, n - 1); }\r\n\r\n          using Key = std::pair<int,\
    \ int>;\r\n          using Val = long long;\r\n          using Map =\r\n     \
    \         typename std::conditional<multiple, std::multimap<Key, Val>,\r\n   \
    \                                     std::map<Key, Val>>::type;\r\n         \
    \ Map edges;\r\n          if (connected) {\r\n            for (auto f : std::views::iota(1,\
    \ n)) {\r\n              auto t = Range<T>(0, f - 1).generate(mt);\r\n       \
    \       auto c = cost_size.generate(mt);\r\n              edges.emplace(std::make_pair(f,\
    \ t), c);\r\n            }\r\n          }\r\n          while (edges.size() < m)\
    \ {\r\n            auto f = Range<T>(0, n - 1).generate(mt);\r\n            auto\
    \ t = Range<T>(0, n - 1).generate(mt);\r\n            auto c = cost_size.generate(mt);\r\
    \n            if (!loop && f == t) { continue; }\r\n            if (!directed\
    \ && f > t) { std::swap(f, t); }\r\n            edges.emplace(std::make_pair(f,\
    \ t), c);\r\n          }\r\n\r\n          std::vector<std::vector<Edge>> graph(n);\r\
    \n          for (const auto& [p, c] : edges) {\r\n            auto [f, t] = p;\r\
    \n            graph[f].emplace_back(t, c);\r\n            if (!directed) { graph[t].emplace_back(f,\
    \ c); }\r\n          }\r\n          return graph;\r\n        }\r\n      };\r\n\
    \    }  // namespace type\r\n\r\n    class SampleGenerator {\r\n      engine mt;\r\
    \n\r\n    public:\r\n      SampleGenerator(unsigned int seed = std::random_device()())\
    \ : mt(seed) {}\r\n\r\n      template <class... T>\r\n      auto generate(T&&...\
    \ t) {\r\n        return std::make_tuple((std::forward<T>(t).generate(mt))...);\r\
    \n      }\r\n    };\r\n\r\n    namespace Inner {\r\n      template <int N>\r\n\
    \      struct Expand {\r\n        template <typename F, typename Tuple, typename...\
    \ Args>\r\n        static auto apply(F& f, Tuple& t, Args&... args) {\r\n    \
    \      return Expand<N - 1>::apply(f, t, std::get<N - 1>(t), args...);\r\n   \
    \     }\r\n      };\r\n\r\n      template <>\r\n      struct Expand<0> {\r\n \
    \       template <typename F, typename Tuple, typename... Args>\r\n        static\
    \ auto apply(F& f, Tuple& t, Args&... args) {\r\n          return f(args...);\r\
    \n        }\r\n      };\r\n\r\n      template <typename F, typename Tuple>\r\n\
    \      auto apply(F& f, Tuple& t) {\r\n        return Expand<std::tuple_size<Tuple>::value>::apply(f,\
    \ t);\r\n      }\r\n    };  // namespace Inner\r\n\r\n    class RandomCaseDebugger\
    \ {\r\n    public:\r\n      auto compare(int conut, const auto& gen, const auto&\
    \ outputer,\r\n                   const auto& solver1, const auto& solver2,\r\n\
    \                   int output_itr = 1000) {\r\n        for (int i = 1; i <= conut;\
    \ ++i) {\r\n          if (i == 1 || (i > 0 && i % output_itr == 0)) {\r\n    \
    \        std::cerr << \"-- \" << i << \"th run -\" << endl;\r\n          }\r\n\
    \          auto args = gen();\r\n          auto ans1 = Inner::apply(solver1, args);\r\
    \n          auto ans2 = Inner::apply(solver2, args);\r\n          if (ans1 !=\
    \ ans2) {\r\n            std::cerr << \"Failed test\" << std::endl;\r\n      \
    \      auto t = std::tuple_cat(args, std::make_tuple(ans1, ans2));\r\n       \
    \     Inner::apply(outputer, t);\r\n            return false;\r\n          }\r\
    \n        }\r\n        std::cerr << \"All test are success!\" << std::endl;\r\n\
    \        return true;\r\n      }\r\n      auto run(int conut, const auto& gen,\
    \ const auto& solver) {\r\n        auto tm = Timer::LapTimer();\r\n        for\
    \ (int i = 1; i <= conut; ++i) {\r\n          auto tm = Timer::SimpleTimer();\r\
    \n          auto args = gen();\r\n          Inner::apply(solver, args);\r\n  \
    \        tm.print<Timer::UNITS::MILLI>();\r\n        }\r\n      }\r\n    };\r\n\
    \  }  // namespace debug\r\n\r\n  template <class T = long long>\r\n  using tr\
    \ = debug::type::Range<T>;\r\n  template <class T = int, class U = long long>\r\
    \n  using tv = debug::type::Vector<T, U>;\r\n  template <class T = long long>\r\
    \n  using tp = debug::type::Permutation<T>;\r\n  template <class T>\r\n  using\
    \ ts = debug::type::String<T>;\r\n  template <class T, bool directed = false,\
    \ bool connected = true,\r\n            bool loop = false, bool multiple = false>\r\
    \n  using tg = debug::type::Graph<T, directed, connected, loop, multiple>;\r\n\
    \r\n}  // namespace mtd\r\n#line 1 \"Library/Debug/Timer.hpp\"\n\uFEFF#pragma\
    \ once\r\n\r\n#line 7 \"Library/Debug/Timer.hpp\"\n\r\nnamespace Timer {\r\n\r\
    \n  /**\r\n   * \u6642\u9593\u306E\u5358\u4F4D\u7FA4\r\n   */\r\n  namespace UNITS\
    \ {\r\n    struct NANO {\r\n      using second = std::chrono::nanoseconds;\r\n\
    \      static constexpr long long magnification = 1;\r\n      static constexpr\
    \ std::string_view str = \"ns\";\r\n    };\r\n    struct MICRO {\r\n      using\
    \ second = std::chrono::microseconds;\r\n      static constexpr long long magnification\
    \ = 1000;\r\n      static constexpr std::string_view str = \"\u03BCs\";\r\n  \
    \  };\r\n    struct MILLI {\r\n      using second = std::chrono::milliseconds;\r\
    \n      static constexpr long long magnification = 1000000;\r\n      static constexpr\
    \ std::string_view str = \"ms\";\r\n    };\r\n    struct SECOND {\r\n      using\
    \ second = std::chrono::microseconds;\r\n      static constexpr long long magnification\
    \ = 1000000000;\r\n      static constexpr std::string_view str = \"s\";\r\n  \
    \  };\r\n  }  // namespace UNITS\r\n\r\n  /**\r\n   * \u6642\u9593\u306E\u51FA\
    \u529B\r\n   */\r\n  template <class UNIT>\r\n  void _print(long long time) {\r\
    \n    std::cerr << time << UNIT::str << std::endl;\r\n  }\r\n\r\n  /**\r\n   *\
    \ \u7C21\u6613\u6642\u9593\u8A08\u6E2C\u30AF\u30E9\u30B9\r\n   * \u958B\u59CB\u304B\
    \u3089\u306E\u6642\u9593\u306E\u307F\u8A08\u6E2C\r\n   */\r\n  class SimpleTimer\
    \ {\r\n    std::chrono::system_clock::time_point start;\r\n\r\n  public:\r\n \
    \   SimpleTimer() : start(std::chrono::system_clock::now()) {}\r\n    SimpleTimer&\
    \ operator=(SimpleTimer&& tm) {\r\n      start = std::move(tm.start);\r\n    \
    \  return *this;\r\n    }\r\n\r\n    template <class UNIT = std::chrono::nanoseconds>\r\
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
    \ \"Library/Main/main.cpp\"\n// end:tag debug\r\n// begin:tag includes\r\n#line\
    \ 2 \"Library/Main/includes.hpp\"\n\n#line 4 \"Library/Main/includes.hpp\"\n#include\
    \ <bitset>\n#include <cmath>\n#line 7 \"Library/Main/includes.hpp\"\n#include\
    \ <iomanip>\n#line 11 \"Library/Main/includes.hpp\"\n#include <memory>\n#include\
    \ <numeric>\n#line 15 \"Library/Main/includes.hpp\"\n#include <set>\n#include\
    \ <stdexcept>\n#line 19 \"Library/Main/includes.hpp\"\n\n#line 2 \"Library/Range/istream.hpp\"\
    \n\n#line 4 \"Library/Range/istream.hpp\"\n\n#line 2 \"Library/Utility/io.hpp\"\
    \n\n#line 5 \"Library/Utility/io.hpp\"\n#include <type_traits>\n#line 7 \"Library/Utility/io.hpp\"\
    \n\n#line 2 \"Library/Utility/Tuple.hpp\"\n\n#line 4 \"Library/Utility/Tuple.hpp\"\
    \n\nnamespace mtd {\n  namespace util {\n    template <class F, class T>\n   \
    \ constexpr auto tuple_transform(F&& f, T&& t) {\n      return std::apply(\n \
    \         [&]<class... Ts>(Ts&&... elems) {\n            return std::tuple<std::invoke_result_t<F&,\
    \ Ts>...>(\n                std::invoke(f, std::forward<Ts>(elems))...);\n   \
    \       },\n          std::forward<T>(t));\n    }\n    template <class F, class\
    \ T>\n    constexpr auto tuple_for_each(F&& f, T&& t) {\n      std::apply(\n \
    \         [&]<class... Ts>(Ts&&... elems) {\n            (std::invoke(f, std::forward<Ts>(elems)),\
    \ ...);\n          },\n          std::forward<T>(t));\n    }\n  }  // namespace\
    \ util\n}  // namespace mtd\n#line 10 \"Library/Utility/io.hpp\"\n\nnamespace\
    \ mtd {\n  namespace io {\n\n    namespace type {\n      template <class T>\n\
    \      struct vec {\n        using value_type = T;\n      };\n      template <class\
    \ T>\n      concept is_vec = requires {\n        requires std::is_same_v<T, vec<typename\
    \ T::value_type>>;\n      };\n\n      template <class T>\n      struct mat {\n\
    \        using value_type = T;\n      };\n      template <class T>\n      concept\
    \ is_mat = requires {\n        requires std::is_same_v<T, mat<typename T::value_type>>;\n\
    \      };\n    }  // namespace type\n\n    template <class T>\n    auto _input()\
    \ {\n      T x;\n      std::cin >> x;\n      return x;\n    }\n    template <typename\
    \ T>\n    requires requires { typename std::tuple_size<T>::type; }\n    auto _input()\
    \ {\n      T x;\n      util::tuple_for_each([](auto&& i) { std::cin >> i; }, x);\n\
    \      return x;\n    }\n    template <type::is_vec T>\n    auto _input(int n)\
    \ {\n      std::vector<typename T::value_type> v;\n      v.reserve(n);\n     \
    \ for (auto i : std::views::iota(0, n)) {\n        v.emplace_back(_input<typename\
    \ T::value_type>());\n      }\n      return v;\n    }\n    template <type::is_mat\
    \ T>\n    auto _input(int h, int w) {\n      std::vector<std::vector<typename\
    \ T::value_type>> mat;\n      mat.reserve(h);\n      for (auto i : std::views::iota(0,\
    \ h)) {\n        mat.emplace_back(_input<type::vec<typename T::value_type>>(w));\n\
    \      }\n      return mat;\n    }\n\n    template <int N, class Tuple, class\
    \ T, class... Args, class... Sizes>\n    auto _tuple_input(Tuple& t, Sizes...\
    \ sizes);\n    template <int N, class Tuple, type::is_vec T, class... Args, class\
    \ Size,\n              class... Sizes>\n    auto _tuple_input(Tuple& t, Size size,\
    \ Sizes... sizes);\n    template <int N, class Tuple, type::is_mat T, class...\
    \ Args, class Size,\n              class... Sizes>\n    auto _tuple_input(Tuple&\
    \ t, Size size_h, Size size_w, Sizes... sizes);\n\n    template <int N, class\
    \ Tuple, class T, class... Args, class... Sizes>\n    auto _tuple_input(Tuple&\
    \ t, Sizes... sizes) {\n      std::get<N>(t) = _input<T>();\n      if constexpr\
    \ (sizeof...(Args) > 0) {\n        _tuple_input<N + 1, Tuple, Args...>(t, sizes...);\n\
    \      }\n    }\n    template <int N, class Tuple, type::is_vec T, class... Args,\
    \ class Size,\n              class... Sizes>\n    auto _tuple_input(Tuple& t,\
    \ Size size, Sizes... sizes) {\n      std::get<N>(t) = _input<T>(size);\n    \
    \  if constexpr (sizeof...(Args) > 0) {\n        _tuple_input<N + 1, Tuple, Args...>(t,\
    \ sizes...);\n      }\n    }\n    template <int N, class Tuple, type::is_mat T,\
    \ class... Args, class Size,\n              class... Sizes>\n    auto _tuple_input(Tuple&\
    \ t, Size size_h, Size size_w, Sizes... sizes) {\n      std::get<N>(t) = _input<T>(size_h,\
    \ size_w);\n      if constexpr (sizeof...(Args) > 0) {\n        _tuple_input<N\
    \ + 1, Tuple, Args...>(t, sizes...);\n      }\n    }\n\n    template <class T>\n\
    \    struct _Converter {\n      using type = T;\n    };\n    template <class T>\n\
    \    struct _Converter<type::vec<T>> {\n      using type = std::vector<T>;\n \
    \   };\n    template <class T>\n    struct _Converter<type::mat<T>> {\n      using\
    \ type = std::vector<std::vector<T>>;\n    };\n\n    template <class... Args,\
    \ class... Sizes>\n    requires(std::convertible_to<Sizes, size_t>&&...) auto\
    \ in(Sizes... sizes) {\n      auto base = std::tuple<typename _Converter<Args>::type...>();\n\
    \      _tuple_input<0, decltype(base), Args...>(base, sizes...);\n      return\
    \ base;\n    }\n\n  }  // namespace io\n\n}  // namespace mtd\n#line 6 \"Library/Range/istream.hpp\"\
    \n\nnamespace mtd {\n  namespace ranges {\n\n    constexpr int _inf = 1e9;\n\n\
    \    template <class... Args>\n    struct istream_view\n        : public std::ranges::view_interface<istream_view<Args...>>\
    \ {\n      class iterator {\n        int count;\n        std::tuple<typename io::_Converter<Args>::type...>\
    \ val;\n\n      public:\n        using difference_type = int;\n        using value_type\
    \ = decltype(val);\n        using iterator_concept = std::input_iterator_tag;\n\
    \n        constexpr iterator() = default;\n        constexpr explicit iterator(int\
    \ count) : count(count) { operator++(); }\n\n        constexpr auto operator*()\
    \ const { return val; }\n        constexpr auto& operator++() {\n          --count;\n\
    \          if (count >= 0) { val = io::in<Args...>(); }\n          return *this;\n\
    \        }\n        constexpr auto operator++(int) { return ++*this; }\n\n   \
    \     constexpr auto operator==(const iterator& s) const {\n          return count\
    \ == s.count;\n        }\n        constexpr auto operator==(std::default_sentinel_t\
    \ s) const {\n          return count < 0 || std::cin.eof() || std::cin.fail()\
    \ ||\n                 std::cin.bad();\n        }\n        constexpr friend auto\
    \ operator==(std::default_sentinel_t s,\n                                    \
    \     const iterator& li) {\n          return li == s;\n        }\n      };\n\n\
    \      int count;\n\n    public:\n      constexpr explicit istream_view(int count)\
    \ : count(count) {}\n      constexpr explicit istream_view() : istream_view(_inf)\
    \ {}\n      constexpr auto begin() const { return iterator(count); }\n      constexpr\
    \ auto end() const { return std::default_sentinel; }\n    };\n  }  // namespace\
    \ ranges\n\n  namespace views {\n    namespace __detail {\n      template <typename...\
    \ _Args>\n      concept __can_istream_view = requires {\n        ranges::istream_view(std::declval<_Args>()...);\n\
    \      };\n    }  // namespace __detail\n\n    template <class... Args>\n    struct\
    \ _Istream {\n      template <class... _Tp>\n      requires __detail::__can_istream_view<_Tp...>\n\
    \      constexpr auto operator() [[nodiscard]] (_Tp&&... __e) const {\n      \
    \  return ranges::istream_view<Args...>(std::forward<_Tp>(__e)...);\n      }\n\
    \    };\n\n    template <class... Args>\n    inline constexpr _Istream<Args...>\
    \ istream{};\n  }  // namespace views\n\n}  // namespace mtd\n#line 2 \"Library/Utility/Tools.hpp\"\
    \n\n#line 4 \"Library/Utility/Tools.hpp\"\n\nnamespace mtd {\n\n  template <class\
    \ T, class S>\n  inline auto chmax(T& t, const S& s) {\n    if (s > t) {\n   \
    \   t = s;\n      return true;\n    }\n    return false;\n  }\n\n  template <class\
    \ T, class S>\n  inline auto chmin(T& t, const S& s) {\n    if (s < t) {\n   \
    \   t = s;\n      return true;\n    }\n    return false;\n  }\n\n  template <class\
    \ S>\n  constexpr auto vec(S x) {\n    return x;\n  }\n\n  template <class S,\
    \ class... T>\n  constexpr auto vec(S x, int n, T... ns) {\n    return std::vector(n,\
    \ vec(x, ns...));\n  }\n\n}  // namespace mtd\n#line 23 \"Library/Main/includes.hpp\"\
    \n\nnamespace mtd {\n\n  struct Preprocessing {\n    Preprocessing() {\n     \
    \ std::cin.tie(0);\n      std::ios::sync_with_stdio(0);\n    };\n  } _Preprocessing;\n\
    \n  template <class T>\n  using tvec = mtd::io::type::vec<T>;\n  template <class\
    \ T>\n  using tmat = mtd::io::type::mat<T>;\n  using mtd::io::in;\n\n  inline\
    \ constexpr auto i = std::views::iota;\n  template <class... Args>\n  inline constexpr\
    \ auto ins = mtd::views::istream<Args...>;\n}  // namespace mtd\n#line 2 \"Library/Range/util.hpp\"\
    \n\n#line 6 \"Library/Range/util.hpp\"\n\n#line 8 \"Library/Range/util.hpp\"\n\
    \nnamespace mtd {\n  namespace ranges {\n\n    namespace __detail {\n      template\
    \ <typename... T>\n      concept __all_random_access = (std::ranges::random_access_range<T>\
    \ &&\n                                     ...);\n      template <typename...\
    \ T>\n      concept __all_bidirectional = (std::ranges::bidirectional_range<T>\
    \ &&\n                                     ...);\n      template <typename...\
    \ T>\n      concept __all_forward = (std::ranges::forward_range<T> && ...);\n\n\
    \      template <class... T>\n      constexpr auto _S_iter_concept() {\n     \
    \   if constexpr (__all_random_access<T...>) {\n          return std::random_access_iterator_tag{};\n\
    \        } else if constexpr (__all_bidirectional<T...>) {\n          return std::bidirectional_iterator_tag{};\n\
    \        } else if constexpr (__all_forward<T...>) {\n          return std::forward_iterator_tag{};\n\
    \        } else {\n          return std::input_iterator_tag{};\n        }\n  \
    \    }\n    }  // namespace __detail\n\n    template <std::ranges::range... _Range>\n\
    \    struct zip_view : public std::ranges::view_interface<zip_view<_Range...>>\
    \ {\n      class iterator {\n      public:\n        std::tuple<std::ranges::iterator_t<_Range>...>\
    \ _M_current;\n\n        using difference_type = int;\n        using value_type\
    \ = std::tuple<\n            std::iter_reference_t<std::ranges::iterator_t<_Range>>...>;\n\
    \        using iterator_concept =\n            decltype(__detail::_S_iter_concept<_Range...>());\n\
    \n        constexpr iterator() = default;\n        constexpr explicit iterator(const\
    \ decltype(_M_current)& __current)\n            : _M_current(__current) {}\n \
    \       constexpr auto operator*() const {\n          return util::tuple_transform([](auto&\
    \ __i) { return *__i; },\n                                       _M_current);\n\
    \        }\n        constexpr auto& operator++() {\n          util::tuple_for_each([](auto&\
    \ __i) { ++__i; }, _M_current);\n          return *this;\n        }\n        constexpr\
    \ auto operator++(int) { return ++*this; }\n        constexpr auto operator==(const\
    \ iterator& other) const {\n          return [&]<size_t... _Is>(std::index_sequence<_Is...>)\
    \ {\n            return ((std::get<_Is>(_M_current) ==\n                     std::get<_Is>(other._M_current))\
    \ ||\n                    ...);\n          }\n          (std::make_index_sequence<sizeof...(_Range)>{});\n\
    \        }\n        constexpr auto& operator--() requires\n            __detail::__all_bidirectional<_Range...>\
    \ {\n          util::tuple_for_each([](auto& __i) { --__i; }, _M_current);\n \
    \         return *this;\n        }\n        constexpr auto operator--(\n     \
    \       int) requires __detail::__all_bidirectional<_Range...> {\n          return\
    \ --*this;\n        }\n        constexpr auto operator<=>(const iterator&)\n \
    \           const requires __detail::__all_random_access<_Range...>\n        =\
    \ default;\n        constexpr auto operator-(const iterator& itr)\n          \
    \  const requires __detail::__all_random_access<_Range...> {\n          return\
    \ [&]<size_t... _Is>(std::index_sequence<_Is...>) {\n            return std::ranges::min({difference_type(\n\
    \                std::get<_Is>(_M_current) - std::get<_Is>(itr._M_current))...});\n\
    \          }\n          (std::make_index_sequence<sizeof...(_Range)>{});\n   \
    \     }\n        constexpr auto& operator+=(const difference_type n) requires\n\
    \            __detail::__all_random_access<_Range...> {\n          util::tuple_for_each([&n](auto&\
    \ __i) { __i += n; }, _M_current);\n          return *this;\n        }\n     \
    \   constexpr auto operator+(const difference_type n)\n            const requires\
    \ __detail::__all_random_access<_Range...> {\n          auto __r = *this;\n  \
    \        __r += n;\n          return __r;\n        }\n        constexpr friend\
    \ auto operator+(const difference_type n,\n                                  \
    \      const iterator& itr) requires\n            __detail::__all_random_access<_Range...>\
    \ {\n          return itr + n;\n        }\n        constexpr auto& operator-=(const\
    \ difference_type n) requires\n            __detail::__all_random_access<_Range...>\
    \ {\n          util::tuple_for_each([&n](auto& __i) { __i -= n; }, _M_current);\n\
    \          return *this;\n        }\n        constexpr auto operator-(const difference_type\
    \ n)\n            const requires __detail::__all_random_access<_Range...> {\n\
    \          auto __r = *this;\n          __r -= n;\n          return __r;\n   \
    \     }\n        constexpr auto operator[](const difference_type n)\n        \
    \    const requires __detail::__all_random_access<_Range...> {\n          return\
    \ util::tuple_transform([&n](auto& __i) { return __i[n]; },\n                \
    \                       _M_current);\n        }\n      };\n\n      class sentinel\
    \ {\n      public:\n        std::tuple<std::ranges::sentinel_t<_Range>...> _M_end;\n\
    \n        constexpr sentinel() = default;\n        constexpr explicit sentinel(const\
    \ decltype(_M_end)& __end)\n            : _M_end(__end) {}\n\n        friend constexpr\
    \ bool operator==(const iterator& __x,\n                                     \
    \    const sentinel& __y) {\n          return [&]<size_t... _Is>(std::index_sequence<_Is...>)\
    \ {\n            return (\n                (std::get<_Is>(__x._M_current) == std::get<_Is>(__y._M_end))\
    \ ||\n                ...);\n          }\n          (std::make_index_sequence<sizeof...(_Range)>{});\n\
    \        }\n      };\n\n      std::tuple<_Range...> __r;\n      constexpr explicit\
    \ zip_view(const _Range&... __r) : __r(__r...) {}\n      constexpr auto begin()\
    \ {\n        return iterator(util::tuple_transform(std::ranges::begin, __r));\n\
    \      }\n      constexpr auto end() {\n        return sentinel(util::tuple_transform(std::ranges::end,\
    \ __r));\n      }\n    };\n\n    namespace __detail {\n      template <typename\
    \ T>\n      auto _flatten(const T& t) {\n        return std::make_tuple(t);\n\
    \      }\n      template <typename... T>\n      auto _flatten(const std::tuple<T...>&\
    \ t);\n\n      template <typename Head, typename... Tail>\n      auto _flatten_impl(const\
    \ Head& head, const Tail&... tail) {\n        return std::tuple_cat(_flatten(head),\
    \ _flatten(tail)...);\n      }\n      template <typename... T>\n      auto _flatten(const\
    \ std::tuple<T...>& t) {\n        return std::apply(\n            [](const auto&...\
    \ args) { return _flatten_impl(args...); }, t);\n      }\n    }  // namespace\
    \ __detail\n\n    template <std::ranges::range _Range>\n    struct flatten_view\n\
    \        : public std::ranges::view_interface<flatten_view<_Range>> {\n      class\
    \ iterator {\n      public:\n        std::ranges::iterator_t<_Range> _M_current;\n\
    \n        using difference_type = std::ranges::range_difference_t<_Range>;\n \
    \       using value_type = decltype(__detail::_flatten(\n            std::declval<\n\
    \                std::iter_reference_t<std::ranges::iterator_t<_Range>>>()));\n\
    \        using iterator_concept = decltype(__detail::_S_iter_concept<_Range>());\n\
    \n        constexpr iterator() = default;\n        constexpr explicit iterator(decltype(_M_current)\
    \ __current)\n            : _M_current(__current) {}\n        constexpr auto operator*()\
    \ const {\n          return __detail::_flatten(*_M_current);\n        }\n    \
    \    constexpr auto& operator++() {\n          ++_M_current;\n          return\
    \ *this;\n        }\n        constexpr auto operator++(int) { return ++*this;\
    \ }\n        constexpr auto operator==(const iterator& other) const {\n      \
    \    return _M_current == other._M_current;\n        }\n        constexpr auto&\
    \ operator--() requires\n            __detail::__all_bidirectional<_Range> {\n\
    \          --_M_current;\n          return *this;\n        }\n        constexpr\
    \ auto operator--(\n            int) requires __detail::__all_bidirectional<_Range>\
    \ {\n          return --*this;\n        }\n        constexpr auto operator<=>(const\
    \ iterator&)\n            const requires __detail::__all_random_access<_Range>\n\
    \        = default;\n        constexpr auto operator-(const iterator& itr)\n \
    \           const requires __detail::__all_random_access<_Range> {\n         \
    \ return _M_current - itr._M_current;\n        }\n        constexpr auto& operator+=(const\
    \ difference_type n) requires\n            __detail::__all_random_access<_Range>\
    \ {\n          _M_current += n;\n          return *this;\n        }\n        constexpr\
    \ auto operator+(const difference_type n)\n            const requires __detail::__all_random_access<_Range>\
    \ {\n          auto __r = *this;\n          __r += n;\n          return __r;\n\
    \        }\n        constexpr friend auto operator+(const difference_type n,\n\
    \                                        const iterator& itr) requires\n     \
    \       __detail::__all_random_access<_Range> {\n          return itr + n;\n \
    \       }\n        constexpr auto& operator-=(const difference_type n) requires\n\
    \            __detail::__all_random_access<_Range> {\n          _M_current -=\
    \ n;\n          return *this;\n        }\n        constexpr auto operator-(const\
    \ difference_type n)\n            const requires __detail::__all_random_access<_Range>\
    \ {\n          auto __r = *this;\n          __r -= n;\n          return __r;\n\
    \        }\n        constexpr auto operator[](const difference_type n)\n     \
    \       const requires __detail::__all_random_access<_Range> {\n          return\
    \ __detail::_flatten(_M_current[n]);\n        }\n      };\n\n      class sentinel\
    \ {\n        std::ranges::sentinel_t<_Range> _M_end;\n\n      public:\n      \
    \  constexpr sentinel() = default;\n        constexpr explicit sentinel(const\
    \ decltype(_M_end)& __end)\n            : _M_end(__end) {}\n\n        friend constexpr\
    \ bool operator==(const iterator& __x,\n                                     \
    \    const sentinel& __y) {\n          return __x._M_current == __y._M_end;\n\
    \        }\n      };\n\n      _Range __r;\n      constexpr explicit flatten_view(const\
    \ _Range& __r) : __r(__r) {}\n      constexpr auto begin() { return iterator(std::ranges::begin(__r));\
    \ }\n      constexpr auto end() { return sentinel(std::ranges::end(__r)); }\n\
    \    };\n\n  }  // namespace ranges\n\n  namespace views {\n    namespace __detail\
    \ {\n      template <typename... _Args>\n      concept __can_zip_view = requires\
    \ {\n        ranges::zip_view(std::declval<_Args>()...);\n      };\n      template\
    \ <typename... _Args>\n      concept __can_flatten_view = requires {\n       \
    \ ranges::flatten_view(std::declval<_Args>()...);\n      };\n    }  // namespace\
    \ __detail\n\n    struct _ZipView {\n      template <class... _Tp>\n      requires\
    \ __detail::__can_zip_view<_Tp...>\n      constexpr auto operator() [[nodiscard]]\
    \ (_Tp&&... __e) const {\n        return ranges::zip_view(std::forward<_Tp>(__e)...);\n\
    \      }\n    };\n    struct _Enumerate : std::views::__adaptor::_RangeAdaptorClosure\
    \ {\n      template <class _Tp>\n      requires __detail::__can_zip_view<std::ranges::iota_view<size_t>,\
    \ _Tp>\n      constexpr auto operator() [[nodiscard]] (_Tp&& __e) const {\n  \
    \      return ranges::zip_view{std::views::iota(0), std::forward<_Tp>(__e)};\n\
    \      }\n      static constexpr bool _S_has_simple_call_op = true;\n    };\n\
    \    struct _Flatten : std::views::__adaptor::_RangeAdaptorClosure {\n      template\
    \ <class... _Tp>\n      requires __detail::__can_flatten_view<_Tp...>\n      constexpr\
    \ auto operator() [[nodiscard]] (_Tp&&... __e) const {\n        return ranges::flatten_view(std::forward<_Tp>(__e)...);\n\
    \      }\n      static constexpr bool _S_has_simple_call_op = true;\n    };\n\n\
    \    inline constexpr _ZipView zip{};\n    inline constexpr _Enumerate enumerate{};\n\
    \    inline constexpr _Flatten flatten{};\n\n  }  // namespace views\n}  // namespace\
    \ mtd\n#line 12 \"Library/Main/main.cpp\"\n// end:tag includes\r\n//=============================================================================================\r\
    \n\r\nusing ll = long long;\r\n\r\nsigned main() {}\r\n"
  code: "// begin:tag time\r\n// end:tag time\r\n//=============================================================================================\r\
    \n// begin:tag debug\r\n#include \"./Library/Debug/Dump.hpp\"\r\n#include \"./Library/Debug/Test.hpp\"\
    \r\n#include \"./Library/Debug/Timer.hpp\"\r\n// end:tag debug\r\n// begin:tag\
    \ includes\r\n#include \"./Library/Main/includes.hpp\"\r\n#include \"./Library/Range/util.hpp\"\
    \r\n// end:tag includes\r\n//=============================================================================================\r\
    \n\r\nusing ll = long long;\r\n\r\nsigned main() {}\r\n"
  dependsOn:
  - Library/Debug/Dump.hpp
  - Library/Debug/Test.hpp
  - Library/Debug/Timer.hpp
  - Library/Main/includes.hpp
  - Library/Range/istream.hpp
  - Library/Utility/io.hpp
  - Library/Utility/Tuple.hpp
  - Library/Utility/Tools.hpp
  - Library/Range/util.hpp
  isVerificationFile: false
  path: Library/Main/main.cpp
  requiredBy: []
  timestamp: '2024-12-18 00:20:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Main/main.cpp
layout: document
redirect_from:
- /library/Library/Main/main.cpp
- /library/Library/Main/main.cpp.html
title: Library/Main/main.cpp
---
