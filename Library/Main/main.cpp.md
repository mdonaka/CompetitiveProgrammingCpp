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
  - icon: ':warning:'
    path: Library/Main/includes.hpp
    title: Library/Main/includes.hpp
  - icon: ':warning:'
    path: Library/Range/istream.hpp
    title: Library/Range/istream.hpp
  - icon: ':x:'
    path: Library/Utility/io.hpp
    title: Library/Utility/io.hpp
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
    \ }; }_Preprocessing;\r\n\r\n// clang-format on\r\n//=============================================================================================\r\
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
    \ tail...);\n}\n#line 2 \"Library/Debug/Test.hpp\"\n\r\n#line 10 \"Library/Debug/Test.hpp\"\
    \n#include <tuple>\r\n#line 12 \"Library/Debug/Test.hpp\"\n\r\n#line 1 \"Library/Debug/Timer.hpp\"\
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
    \ / UNIT::magnification); }\r\n    }\r\n  };\r\n}  // namespace Timer\n#line 14\
    \ \"Library/Debug/Test.hpp\"\n\r\nnamespace mtd {\r\n  namespace debug {\r\n\r\
    \n    constexpr char endl = '\\n';\r\n    using engine = std::mt19937_64;\r\n\r\
    \n    namespace type {\r\n      class Range {\r\n        const int_fast64_t l;\r\
    \n        const int_fast64_t u;\r\n\r\n      public:\r\n        Range(int_fast64_t\
    \ l, int_fast64_t u) : l(l), u(u) {}\r\n        Range(int_fast64_t u) : l(0),\
    \ u(u) {}\r\n        Range(const std::initializer_list<int>& v)\r\n          \
    \  : l(*v.begin()), u(*std::next(v.begin())) {}\r\n\r\n        auto generate(engine&\
    \ mt) const {\r\n          return static_cast<int_fast64_t>(mt() % (u + 1 - l))\
    \ + l;\r\n        }\r\n      };\r\n\r\n      class Vector {\r\n        const Range\
    \ size;\r\n        const Range r;\r\n\r\n      public:\r\n        Vector(const\
    \ Range& size, const Range& r) : size(size), r(r) {}\r\n\r\n        auto generate(engine&\
    \ mt) const {\r\n          auto v_mt = std::vector<int_fast64_t>(size.generate(mt))\
    \ |\r\n                      std::views::transform(\r\n                      \
    \    [&](int_fast64_t) { return r.generate(mt); });\r\n          return std::vector<int_fast64_t>(v_mt.begin(),\
    \ v_mt.end());\r\n        }\r\n      };\r\n\r\n      class Permutation {\r\n \
    \       const Range size;\r\n\r\n      public:\r\n        Permutation(const Range&\
    \ size) : size(size) {}\r\n        Permutation(const std::initializer_list<int>&\
    \ size)\r\n            : Permutation(Range(size)) {}\r\n\r\n        auto generate(engine&\
    \ mt) const {\r\n          std::vector<int_fast64_t> p(size.generate(mt));\r\n\
    \          std::iota(p.begin(), p.end(), 0);\r\n          std::shuffle(p.begin(),\
    \ p.end(), mt);\r\n          return p;\r\n        }\r\n      };\r\n\r\n      class\
    \ String {\r\n        const Range size;\r\n        const Range r;\r\n\r\n    \
    \  public:\r\n        String(const Range& size, const Range& r) : size(size),\
    \ r(r) {}\r\n\r\n        auto generate(engine& mt) const {\r\n          auto v_mt\
    \ = std::vector<int_fast64_t>(size.generate(mt)) |\r\n                      std::views::transform([&](int_fast64_t)\
    \ {\r\n                        return static_cast<char>(r.generate(mt) + 'a');\r\
    \n                      });\r\n          return std::string(v_mt.begin(), v_mt.end());\r\
    \n        }\r\n      };\r\n\r\n      template <bool directed, bool connected,\
    \ bool loop, bool multiple>\r\n      class Graph {\r\n        const Range node_size;\r\
    \n        const Range edge_size;\r\n        const Range cost_size;\r\n\r\n   \
    \   public:\r\n        Graph(const Range& node_size, const Range& edge_size,\r\
    \n              const Range& cost_size = {1, 1})\r\n            : node_size(node_size),\r\
    \n              edge_size(edge_size),\r\n              cost_size(cost_size) {}\r\
    \n\r\n        auto generate(engine& mt) const {\r\n          using Edge = std::pair<int,\
    \ long long>;\r\n          auto n = node_size.generate(mt);\r\n          auto\
    \ m = edge_size.generate(mt);\r\n          if (!multiple) { m = std::min(m, n\
    \ * (n - 1) / 2); }\r\n          if (connected) { m = std::max(m, n - 1); }\r\n\
    \r\n          using Key = std::pair<int, int>;\r\n          using Val = long long;\r\
    \n          using Map =\r\n              typename std::conditional<multiple, std::multimap<Key,\
    \ Val>,\r\n                                        std::map<Key, Val>>::type;\r\
    \n          Map edges;\r\n          if (connected) {\r\n            for (auto\
    \ f : std::views::iota(1, n)) {\r\n              auto t = Range(0, f - 1).generate(mt);\r\
    \n              auto c = cost_size.generate(mt);\r\n              edges.emplace(std::make_pair(f,\
    \ t), c);\r\n            }\r\n          }\r\n          while (edges.size() < m)\
    \ {\r\n            auto f = Range(0, n - 1).generate(mt);\r\n            auto\
    \ t = Range(0, n - 1).generate(mt);\r\n            auto c = cost_size.generate(mt);\r\
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
    \  }  // namespace debug\r\n\r\n  using tr = debug::type::Range;\r\n  using tv\
    \ = debug::type::Vector;\r\n  using tp = debug::type::Permutation;\r\n  using\
    \ ts = debug::type::String;\r\n  template <bool directed = false, bool connected\
    \ = true, bool loop = false,\r\n            bool multiple = false>\r\n  using\
    \ tg = debug::type::Graph<directed, connected, loop, multiple>;\r\n\r\n}  // namespace\
    \ mtd\r\n#line 1 \"Library/Debug/Timer.hpp\"\n\uFEFF#pragma once\r\n\r\n#line\
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
    \ / UNIT::magnification); }\r\n    }\r\n  };\r\n}  // namespace Timer\n#line 42\
    \ \"Library/Main/main.cpp\"\n// end:tag debug\r\n// begin:tag includes\r\n#line\
    \ 2 \"Library/Main/includes.hpp\"\n\n#line 2 \"Library/Range/istream.hpp\"\n\n\
    #line 4 \"Library/Range/istream.hpp\"\n\n#line 2 \"Library/Utility/io.hpp\"\n\n\
    #line 5 \"Library/Utility/io.hpp\"\n#include <type_traits>\n#line 7 \"Library/Utility/io.hpp\"\
    \n\nnamespace mtd {\n  namespace io {\n\n    namespace type {\n      template\
    \ <class T, int Pre = 1, int Size = 0>\n      struct vec {\n        using value_type\
    \ = T;\n        static constexpr int pre = Pre;\n        static constexpr int\
    \ size = Size;\n      };\n      template <class T>\n      concept is_vec = requires\
    \ {\n        std::is_same_v<T, vec<typename T::value_type, T::pre, T::size>>;\n\
    \      };\n    }  // namespace type\n\n    template <type::is_vec T>\n    auto\
    \ _input(int n) {\n      std::vector<typename T::value_type> v(n);\n      for\
    \ (auto i : std::views::iota(0, n)) { std::cin >> v[i]; }\n      return v;\n \
    \   }\n\n    template <class T>\n    auto _input() {\n      T x;\n      std::cin\
    \ >> x;\n      return x;\n    }\n\n    template <int N, class Tuple, class T,\
    \ class... Args>\n    auto _tuple_input(Tuple& t) {\n      if constexpr (type::is_vec<T>)\
    \ {\n        if constexpr (T::size == 0) {\n          std::get<N>(t) = _input<T>(std::get<N\
    \ - T::pre>(t));\n        } else {\n          std::get<N>(t) = _input<T>(T::size);\n\
    \        }\n      } else {\n        std::get<N>(t) = _input<T>();\n      }\n \
    \     if constexpr (sizeof...(Args) > 0) {\n        _tuple_input<N + 1, Tuple,\
    \ Args...>(t);\n      }\n    }\n\n    template <class T>\n    struct _Converter\
    \ {\n      using type = T;\n    };\n    template <class T, int Pre, int Size>\n\
    \    struct _Converter<type::vec<T, Pre, Size>> {\n      using type = std::vector<T>;\n\
    \    };\n\n    template <class... Args>\n    auto in() {\n      auto base = std::tuple<typename\
    \ _Converter<Args>::type...>();\n      _tuple_input<0, decltype(base), Args...>(base);\n\
    \      return base;\n    }\n\n  }  // namespace io\n\n}  // namespace mtd\n#line\
    \ 6 \"Library/Range/istream.hpp\"\n\nnamespace mtd {\n  namespace ranges {\n\n\
    \    constexpr int _inf = 1e9;\n\n    template <class... Args>\n    struct istream_view\n\
    \        : public std::ranges::view_interface<istream_view<Args...>> {\n     \
    \ class iterator {\n        int count;\n        std::tuple<typename io::_Converter<Args>::type...>\
    \ val;\n\n      public:\n        using difference_type = int;\n        using value_type\
    \ = decltype(val);\n        using iterator_concept = std::input_iterator_tag;\n\
    \n        explicit iterator(int count = 0) : count(count) { operator++(); }\n\n\
    \        auto operator*() const { return val; }\n        auto& operator++() {\n\
    \          --count;\n          if (count >= 0) { val = io::in<Args...>(); }\n\
    \          return *this;\n        }\n        auto operator++(int) { return ++*this;\
    \ }\n\n        auto operator==(std::default_sentinel_t s) const {\n          return\
    \ count < 0 || std::cin.eof() || std::cin.fail() ||\n                 std::cin.bad();\n\
    \        }\n        friend auto operator==(std::default_sentinel_t s, const iterator&\
    \ li) {\n          return li == s;\n        }\n      };\n\n      int count;\n\n\
    \    public:\n      constexpr explicit istream_view(int count) : count(count)\
    \ {}\n      constexpr explicit istream_view() : istream_view(_inf) {}\n      auto\
    \ begin() const { return iterator(count); }\n      auto end() const { return std::default_sentinel;\
    \ }\n    };\n  }  // namespace ranges\n\n  namespace views {\n    namespace __detail\
    \ {\n      template <typename... _Args>\n      concept __can_istream_view = requires\
    \ {\n        ranges::istream_view(std::declval<_Args>()...);\n      };\n    }\
    \  // namespace __detail\n\n    template <class... Args>\n    struct _Istream\
    \ {\n      template <class... _Tp>\n      requires __detail::__can_istream_view<_Tp...>\n\
    \      constexpr auto operator() [[nodiscard]] (_Tp&&... __e) const {\n      \
    \  return ranges::istream_view<Args...>(std::forward<_Tp>(__e)...);\n      }\n\
    \    };\n\n    template <class... Args>\n    inline constexpr _Istream<Args...>\
    \ istream{};\n  }  // namespace views\n\n}  // namespace mtd\n#line 5 \"Library/Main/includes.hpp\"\
    \n\nnamespace mtd {\n\n  template <class T, int Pre = 1, int Size = 0>\n  using\
    \ tvec = mtd::io::type::vec<T, Pre, Size>;\n  using mtd::io::in;\n\n  inline constexpr\
    \ auto i = std::views::iota;\n  template <class... Args>\n  inline constexpr auto\
    \ ins = mtd::views::istream<Args...>;\n}  // namespace mtd\n#line 45 \"Library/Main/main.cpp\"\
    \n// end:tag includes\r\n//=============================================================================================\r\
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
    \ std::ios::sync_with_stdio(0); }; }_Preprocessing;\r\n\r\n// clang-format on\r\
    \n//=============================================================================================\r\
    \n// begin:tag debug\r\n#include \"./Library/Debug/Dump.hpp\"\r\n#include \"./Library/Debug/Test.hpp\"\
    \r\n#include \"./Library/Debug/Timer.hpp\"\r\n// end:tag debug\r\n// begin:tag\
    \ includes\r\n#include \"./Library/Main/includes.hpp\"\r\n// end:tag includes\r\
    \n//=============================================================================================\r\
    \n\r\nusing ll = long long;\r\n\r\nsigned main() {}\r\n"
  dependsOn:
  - Library/Debug/Dump.hpp
  - Library/Debug/Test.hpp
  - Library/Debug/Timer.hpp
  - Library/Main/includes.hpp
  - Library/Range/istream.hpp
  - Library/Utility/io.hpp
  isVerificationFile: false
  path: Library/Main/main.cpp
  requiredBy: []
  timestamp: '2024-08-24 16:45:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Main/main.cpp
layout: document
redirect_from:
- /library/Library/Main/main.cpp
- /library/Library/Main/main.cpp.html
title: Library/Main/main.cpp
---
