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
      template <class T>
      class Range {
        const T l;
        const T u;

      public:
        Range(T _l, T _u) : l(_l), u(_u) {}
        Range(T _u) : l(0), u(_u) {}
        Range(const std::initializer_list<int>& v)
            : l(*v.begin()), u(*std::next(v.begin())) {}

        auto generate(engine& mt) const {
          return static_cast<T>(mt() % (u + 1 - l) + l);
        }
      };

      template <class T, class U>
      class Vector {
        const Range<T> size;
        const Range<U> r;

      public:
        Vector(const Range<T>& _size, const Range<U>& _r)
            : size(_size), r(_r) {}

        auto generate(engine& mt) const {
          auto v_mt = std::vector<U>(size.generate(mt)) |
                      std::views::transform([&](U) { return r.generate(mt); });
          return std::vector<U>(v_mt.begin(), v_mt.end());
        }
      };

      template <class T>
      class Permutation {
        const Range<T> size;

      public:
        Permutation(const Range<T>& _size) : size(_size) {}
        Permutation(const std::initializer_list<int>& _size)
            : Permutation(Range<T>(_size)) {}

        auto generate(engine& mt) const {
          std::vector<T> p(size.generate(mt));
          std::iota(p.begin(), p.end(), 0);
          std::shuffle(p.begin(), p.end(), mt);
          return p;
        }
      };

      template <class T>
      class String {
        const Range<T> size;
        const Range<T> r;

      public:
        String(const Range<T>& _size, const Range<T>& _r)
            : size(_size), r(_r) {}

        auto generate(engine& mt) const {
          auto v_mt =
              std::vector<T>(size.generate(mt)) | std::views::transform([&](T) {
                return static_cast<char>(r.generate(mt) + 'a');
              });
          return std::string(v_mt.begin(), v_mt.end());
        }
      };

      template <class S, class T, bool directed, bool connected, bool loop,
                bool multiple>
      class Graph {
        const Range<S> node_size;
        const Range<S> edge_size;
        const Range<T> cost_size;

      public:
        Graph(const Range<S>& _node_size, const Range<S>& _edge_size,
              const Range<T>& _cost_size = {1, 1})
            : node_size(_node_size),
              edge_size(_edge_size),
              cost_size(_cost_size) {}

        auto generate(engine& mt) const {
          using Edge = std::pair<S, T>;
          auto n = node_size.generate(mt);
          auto m = edge_size.generate(mt);
          if (!multiple) { m = std::min(m, n * (n - 1) / 2); }
          if (connected) { m = std::max(m, n - 1); }

          using Key = std::pair<S, S>;
          using Val = long long;
          using Map =
              typename std::conditional<multiple, std::multimap<Key, Val>,
                                        std::map<Key, Val>>::type;
          Map edges;
          if (connected) {
            for (auto f : std::views::iota(1, n)) {
              auto t = Range<T>(0, f - 1).generate(mt);
              auto c = cost_size.generate(mt);
              edges.emplace(std::make_pair(f, t), c);
            }
          }
          while (edges.size() < m) {
            auto f = Range<T>(0, n - 1).generate(mt);
            auto t = Range<T>(0, n - 1).generate(mt);
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
  }  // namespace debug

  template <class T = long long>
  using tr = debug::type::Range<T>;
  template <class T = int, class U = long long>
  using tv = debug::type::Vector<T, U>;
  template <class T = long long>
  using tp = debug::type::Permutation<T>;
  template <class T>
  using ts = debug::type::String<T>;
  template <class S = int, class T = long long, bool directed = false,
            bool connected = true, bool loop = false, bool multiple = false>
  using tg = debug::type::Graph<S, T, directed, connected, loop, multiple>;

}  // namespace mtd
