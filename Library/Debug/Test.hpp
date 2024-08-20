#pragma once

#include <algorithm>
#include <concepts>
#include <iostream>
#include <map>
#include <random>
#include <ranges>
#include <string>
#include <tuple>
#include <vector>

#include "Timer.hpp"

namespace mtd {
  namespace debug {

    constexpr char endl = '\n';
    using engine = std::mt19937_64;

    namespace type {
      class Range {
        const int_fast64_t l;
        const int_fast64_t u;

      public:
        Range(int_fast64_t l, int_fast64_t u) : l(l), u(u) {}
        Range(int_fast64_t u) : l(0), u(u) {}
        Range(const std::initializer_list<int>& v)
            : l(*v.begin()), u(*std::next(v.begin())) {}

        auto generate(engine& mt) const {
          return static_cast<int_fast64_t>(mt() % (u + 1 - l)) + l;
        }
      };

      class Vector {
        const Range size;
        const Range r;

      public:
        Vector(const Range& size, const Range& r) : size(size), r(r) {}

        auto generate(engine& mt) const {
          auto v_mt = std::vector<int_fast64_t>(size.generate(mt)) |
                      std::views::transform(
                          [&](int_fast64_t) { return r.generate(mt); });
          return std::vector<int_fast64_t>(v_mt.begin(), v_mt.end());
        }
      };

      class Permutation {
        const Range size;

      public:
        Permutation(const Range& size) : size(size) {}
        Permutation(const std::initializer_list<int>& size)
            : Permutation(Range(size)) {}

        auto generate(engine& mt) const {
          std::vector<int_fast64_t> p(size.generate(mt));
          std::iota(p.begin(), p.end(), 0);
          std::shuffle(p.begin(), p.end(), mt);
          return p;
        }
      };

      class String {
        const Range size;
        const Range r;

      public:
        String(const Range& size, const Range& r) : size(size), r(r) {}

        auto generate(engine& mt) const {
          auto v_mt = std::vector<int_fast64_t>(size.generate(mt)) |
                      std::views::transform([&](int_fast64_t) {
                        return static_cast<char>(r.generate(mt) + 'a');
                      });
          return std::string(v_mt.begin(), v_mt.end());
        }
      };

      template <bool directed, bool connected, bool loop, bool multiple>
      class Graph {
        const Range node_size;
        const Range edge_size;
        const Range cost_size;

      public:
        Graph(const Range& node_size, const Range& edge_size,
              const Range& cost_size = {1, 1})
            : node_size(node_size),
              edge_size(edge_size),
              cost_size(cost_size) {}

        auto generate(engine& mt) const {
          using Edge = std::pair<int, long long>;
          auto n = node_size.generate(mt);
          auto m = edge_size.generate(mt);
          if (!multiple) { m = std::min(m, n * (n - 1) / 2); }
          if (connected) { m = std::max(m, n - 1); }

          using Key = std::pair<int, int>;
          using Val = long long;
          using Map =
              typename std::conditional<multiple, std::multimap<Key, Val>,
                                        std::map<Key, Val>>::type;
          Map edges;
          if (connected) {
            for (auto f : std::views::iota(1, n)) {
              auto t = Range(0, f - 1).generate(mt);
              auto c = cost_size.generate(mt);
              edges.emplace(std::make_pair(f, t), c);
            }
          }
          while (edges.size() < m) {
            auto f = Range(0, n - 1).generate(mt);
            auto t = Range(0, n - 1).generate(mt);
            auto c = cost_size.generate(mt);
            if (!loop && f == t) { continue; }
            if (!directed && f > t) { std::swap(f, t); }
            edges.emplace(std::make_pair(f, t), c);
          }

          std::vector<std::vector<Edge>> graph(n);
          for (const auto& [p, c] : edges) {
            auto [f, t] = p;
            graph[f].emplace_back(t, c);
            if (!directed) { graph[t].emplace_back(f, c); }
          }
          return graph;
        }
      };
    }  // namespace type

    class SampleGenerator {
      engine mt;

    public:
      SampleGenerator(unsigned int seed = std::random_device()()) : mt(seed) {}

      template <class... T>
      auto generate(T&&... t) {
        return std::make_tuple((std::forward<T>(t).generate(mt))...);
      }
    };

    namespace Inner {
      template <int N>
      struct Expand {
        template <typename F, typename Tuple, typename... Args>
        static auto apply(F& f, Tuple& t, Args&... args) {
          return Expand<N - 1>::apply(f, t, std::get<N - 1>(t), args...);
        }
      };

      template <>
      struct Expand<0> {
        template <typename F, typename Tuple, typename... Args>
        static auto apply(F& f, Tuple& t, Args&... args) {
          return f(args...);
        }
      };

      template <typename F, typename Tuple>
      auto apply(F& f, Tuple& t) {
        return Expand<std::tuple_size<Tuple>::value>::apply(f, t);
      }
    };  // namespace Inner

    class RandomCaseDebugger {
    public:
      auto compare(int conut, const auto& gen, const auto& outputer,
                   const auto& solver1, const auto& solver2,
                   int output_itr = 1000) {
        for (int i = 1; i <= conut; ++i) {
          if (i == 1 || (i > 0 && i % output_itr == 0)) {
            std::cerr << "-- " << i << "th run -" << endl;
          }
          auto args = gen();
          if (Inner::apply(solver1, args) != Inner::apply(solver2, args)) {
            std::cerr << "Failed test" << std::endl;
            Inner::apply(outputer, args);
            return false;
          }
        }
        std::cerr << "All test are success!" << std::endl;
        return true;
      }
      auto run(int conut, const auto& gen, const auto& solver) {
        auto tm = Timer::LapTimer();
        for (int i = 1; i <= conut; ++i) {
          auto tm = Timer::SimpleTimer();
          auto args = gen();
          Inner::apply(solver, args);
          tm.print<Timer::UNITS::MILLI>();
        }
      }
    };
  }  // namespace debug

  using tr = debug::type::Range;
  using tv = debug::type::Vector;
  using tp = debug::type::Permutation;
  using ts = debug::type::String;
  template <bool directed = false, bool connected = true, bool loop = false,
            bool multiple = false>
  using tg = debug::type::Graph<directed, connected, loop, multiple>;

}  // namespace mtd
