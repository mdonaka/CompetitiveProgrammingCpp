---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Library/Debug/Timer.hpp
    title: Library/Debug/Timer.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Library/Main/main.cpp
    title: Library/Main/main.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Debug/Test.hpp\"\n\r\n#include <algorithm>\r\n#include\
    \ <concepts>\r\n#include <iostream>\r\n#include <map>\r\n#include <random>\r\n\
    #include <ranges>\r\n#include <string>\r\n#include <tuple>\r\n#include <vector>\r\
    \n\r\n#line 1 \"Library/Debug/Timer.hpp\"\n\uFEFF#pragma once\r\n\r\n#include\
    \ <chrono>\r\n#line 5 \"Library/Debug/Timer.hpp\"\n#include <list>\r\n#include\
    \ <string_view>\r\n\r\nnamespace Timer {\r\n\r\n  /**\r\n   * \u6642\u9593\u306E\
    \u5358\u4F4D\u7FA4\r\n   */\r\n  namespace UNITS {\r\n    struct NANO {\r\n  \
    \    using second = std::chrono::nanoseconds;\r\n      static constexpr long long\
    \ magnification = 1;\r\n      static constexpr std::string_view str = \"ns\";\r\
    \n    };\r\n    struct MICRO {\r\n      using second = std::chrono::microseconds;\r\
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
    \r\n}  // namespace mtd\r\n"
  code: "#pragma once\r\n\r\n#include <algorithm>\r\n#include <concepts>\r\n#include\
    \ <iostream>\r\n#include <map>\r\n#include <random>\r\n#include <ranges>\r\n#include\
    \ <string>\r\n#include <tuple>\r\n#include <vector>\r\n\r\n#include \"Timer.hpp\"\
    \r\n\r\nnamespace mtd {\r\n  namespace debug {\r\n\r\n    constexpr char endl\
    \ = '\\n';\r\n    using engine = std::mt19937_64;\r\n\r\n    namespace type {\r\
    \n      template <class T>\r\n      class Range {\r\n        const T l;\r\n  \
    \      const T u;\r\n\r\n      public:\r\n        Range(T l, T u) : l(l), u(u)\
    \ {}\r\n        Range(T u) : l(0), u(u) {}\r\n        Range(const std::initializer_list<int>&\
    \ v)\r\n            : l(*v.begin()), u(*std::next(v.begin())) {}\r\n\r\n     \
    \   auto generate(engine& mt) const {\r\n          return static_cast<T>(mt()\
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
    \r\n}  // namespace mtd\r\n"
  dependsOn:
  - Library/Debug/Timer.hpp
  isVerificationFile: false
  path: Library/Debug/Test.hpp
  requiredBy:
  - Library/Main/main.cpp
  timestamp: '2024-11-02 22:12:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Debug/Test.hpp
layout: document
redirect_from:
- /library/Library/Debug/Test.hpp
- /library/Library/Debug/Test.hpp.html
title: Library/Debug/Test.hpp
---
