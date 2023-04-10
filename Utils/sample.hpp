#pragma once
#include <random>
#include <vector>
#include<iostream>

namespace Sample {

    using std::cout;
    constexpr char endl = '\n';
    class Range {
        const int_fast64_t l;
        const int_fast64_t u;
    public:
        Range(int_fast64_t l, int_fast64_t u) :l(l), u(u) {}
        Range(int_fast64_t u) :l(0), u(u) {}

        auto normalize(uint_fast64_t val)const {
            return static_cast<int_fast64_t>(val % (u + 1 - l)) + l;
        }
    };

    class RandomGenerator {
        std::mt19937_64 mt;
    public:
        RandomGenerator(unsigned int seed = std::random_device()()) : mt(std::mt19937_64(seed)) {}

        // [l,u]
        auto random(const Range& range) { return range.normalize(mt()); }
        auto random(int_fast64_t l, int_fast64_t u) { return random(Range(l, u)); }
        auto random(int_fast64_t u) { return random(Range(0LL, u)); }

        auto get_gen()const { return mt; }
    };

    class SampleGenerator {
        RandomGenerator rnd;

        auto generate_random(const Range& range) {
            return rnd.random(range);
        }
        auto generate_random(const std::pair<int_fast64_t, int_fast64_t>& pair) { return rnd.random(Range(pair.first, pair.second)); }
        template<class T>
        auto generate_random(const std::vector<T>& ranges) {
            std::vector<long long> v;
            v.reserve(ranges.size());
            for(auto&& range : ranges) { v.emplace_back(generate_random(range)); }
            return v;
        }
    public:
        SampleGenerator() :rnd() {}
        SampleGenerator(unsigned int seed) :rnd(seed) {}

        template<class ... T>
        auto generate(T&& ...ranges) {
            return std::make_tuple(generate_random(ranges)...);
        }

        auto generate_permutation(int size) const {
            std::vector<int> rnd_p(size);
            std::iota(rnd_p.begin(), rnd_p.end(), 0);
            std::shuffle(rnd_p.begin(), rnd_p.end(), rnd.get_gen());
            return rnd_p;
        }
    };
}