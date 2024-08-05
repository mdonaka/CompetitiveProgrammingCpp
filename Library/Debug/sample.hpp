#pragma once
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "Timer.hpp"

namespace Sample {

  using std::cout;
  constexpr char endl = '\n';
  class Range {
    const int_fast64_t l;
    const int_fast64_t u;

  public:
    Range(int_fast64_t l, int_fast64_t u) : l(l), u(u) {}
    Range(int_fast64_t u) : l(0), u(u) {}
    template <class S, class T>
    Range(const std::pair<S, T>& p) : Range(p.first, p.second) {}

    auto normalize(uint_fast64_t val) const {
      return static_cast<int_fast64_t>(val % (u + 1 - l)) + l;
    }
  };

  class RandomGenerator {
    std::mt19937_64 mt;

  public:
    RandomGenerator(unsigned int seed = std::random_device()())
        : mt(std::mt19937_64(seed)) {}

    // [l,u]
    auto random(const Range& range) { return range.normalize(mt()); }
    auto random(int_fast64_t l, int_fast64_t u) { return random(Range(l, u)); }
    auto random(int_fast64_t u) { return random(Range(0LL, u)); }

    auto& get_gen() { return mt; }
  };

  class SampleGenerator {
    RandomGenerator rnd;

    auto generate_random(const Range& range) { return rnd.random(range); }
    template <class T>
    auto generate_random(const std::pair<T, T>& pair) {
      return rnd.random(Range(pair.first, pair.second));
    }
    template <class T>
    auto generate_random(const std::vector<T>& ranges) {
      std::vector<long long> v;
      v.reserve(ranges.size());
      for (auto&& range : ranges) { v.emplace_back(generate_random(range)); }
      return v;
    }

  public:
    SampleGenerator() : rnd() {}
    SampleGenerator(unsigned int seed) : rnd(seed) {}

    template <class... T>
    auto generate(T&&... ranges) {
      return std::make_tuple(generate_random(ranges)...);
    }

    auto generate_permutation(int size) {
      std::vector<int> rnd_p(size);
      std::iota(rnd_p.begin(), rnd_p.end(), 0);
      std::shuffle(rnd_p.begin(), rnd_p.end(), rnd.get_gen());
      return rnd_p;
    }

    auto generate_string(const Range& range, int csize = 26) {
      auto size = generate_random(range);
      auto v = generate_random(std::vector<Range>(size, {0, csize - 1}));
      std::string s = "";
      for (const auto& c : v) { s += c + 'a'; }
      return std::make_tuple(size, s);
    }

    template <class T>
    auto shuffle(const std::vector<T>& v_) {
      auto v = v_;
      std::shuffle(v.begin(), v.end(), rnd.get_gen());
      return v;
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

}  // namespace Sample