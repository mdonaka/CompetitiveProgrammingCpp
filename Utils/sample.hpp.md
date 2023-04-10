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
  bundledCode: "#line 2 \"Utils/sample.hpp\"\n#include <random>\r\n#include <vector>\r\
    \n#include<iostream>\r\n\r\nnamespace Sample {\r\n\r\n    using std::cout;\r\n\
    \    constexpr char endl = '\\n';\r\n    class Range {\r\n        const int_fast64_t\
    \ l;\r\n        const int_fast64_t u;\r\n    public:\r\n        Range(int_fast64_t\
    \ l, int_fast64_t u) :l(l), u(u) {}\r\n        Range(int_fast64_t u) :l(0), u(u)\
    \ {}\r\n\r\n        auto normalize(uint_fast64_t val)const {\r\n            return\
    \ static_cast<int_fast64_t>(val % (u + 1 - l)) + l;\r\n        }\r\n    };\r\n\
    \r\n    class RandomGenerator {\r\n        std::mt19937_64 mt;\r\n    public:\r\
    \n        RandomGenerator(unsigned int seed = std::random_device()()) : mt(std::mt19937_64(seed))\
    \ {}\r\n\r\n        // [l,u]\r\n        auto random(const Range& range) { return\
    \ range.normalize(mt()); }\r\n        auto random(int_fast64_t l, int_fast64_t\
    \ u) { return random(Range(l, u)); }\r\n        auto random(int_fast64_t u) {\
    \ return random(Range(0LL, u)); }\r\n\r\n        auto get_gen()const { return\
    \ mt; }\r\n    };\r\n\r\n    class SampleGenerator {\r\n        RandomGenerator\
    \ rnd;\r\n\r\n        auto generate_random(const Range& range) {\r\n         \
    \   return rnd.random(range);\r\n        }\r\n        auto generate_random(const\
    \ std::pair<int_fast64_t, int_fast64_t>& pair) { return rnd.random(Range(pair.first,\
    \ pair.second)); }\r\n        template<class T>\r\n        auto generate_random(const\
    \ std::vector<T>& ranges) {\r\n            std::vector<long long> v;\r\n     \
    \       v.reserve(ranges.size());\r\n            for(auto&& range : ranges) {\
    \ v.emplace_back(generate_random(range)); }\r\n            return v;\r\n     \
    \   }\r\n    public:\r\n        SampleGenerator() :rnd() {}\r\n        SampleGenerator(unsigned\
    \ int seed) :rnd(seed) {}\r\n\r\n        template<class ... T>\r\n        auto\
    \ generate(T&& ...ranges) {\r\n            return std::make_tuple(generate_random(ranges)...);\r\
    \n        }\r\n\r\n        auto generate_permutation(int size) const {\r\n   \
    \         std::vector<int> rnd_p(size);\r\n            std::iota(rnd_p.begin(),\
    \ rnd_p.end(), 0);\r\n            std::shuffle(rnd_p.begin(), rnd_p.end(), rnd.get_gen());\r\
    \n            return rnd_p;\r\n        }\r\n    };\r\n}\n"
  code: "#pragma once\r\n#include <random>\r\n#include <vector>\r\n#include<iostream>\r\
    \n\r\nnamespace Sample {\r\n\r\n    using std::cout;\r\n    constexpr char endl\
    \ = '\\n';\r\n    class Range {\r\n        const int_fast64_t l;\r\n        const\
    \ int_fast64_t u;\r\n    public:\r\n        Range(int_fast64_t l, int_fast64_t\
    \ u) :l(l), u(u) {}\r\n        Range(int_fast64_t u) :l(0), u(u) {}\r\n\r\n  \
    \      auto normalize(uint_fast64_t val)const {\r\n            return static_cast<int_fast64_t>(val\
    \ % (u + 1 - l)) + l;\r\n        }\r\n    };\r\n\r\n    class RandomGenerator\
    \ {\r\n        std::mt19937_64 mt;\r\n    public:\r\n        RandomGenerator(unsigned\
    \ int seed = std::random_device()()) : mt(std::mt19937_64(seed)) {}\r\n\r\n  \
    \      // [l,u]\r\n        auto random(const Range& range) { return range.normalize(mt());\
    \ }\r\n        auto random(int_fast64_t l, int_fast64_t u) { return random(Range(l,\
    \ u)); }\r\n        auto random(int_fast64_t u) { return random(Range(0LL, u));\
    \ }\r\n\r\n        auto get_gen()const { return mt; }\r\n    };\r\n\r\n    class\
    \ SampleGenerator {\r\n        RandomGenerator rnd;\r\n\r\n        auto generate_random(const\
    \ Range& range) {\r\n            return rnd.random(range);\r\n        }\r\n  \
    \      auto generate_random(const std::pair<int_fast64_t, int_fast64_t>& pair)\
    \ { return rnd.random(Range(pair.first, pair.second)); }\r\n        template<class\
    \ T>\r\n        auto generate_random(const std::vector<T>& ranges) {\r\n     \
    \       std::vector<long long> v;\r\n            v.reserve(ranges.size());\r\n\
    \            for(auto&& range : ranges) { v.emplace_back(generate_random(range));\
    \ }\r\n            return v;\r\n        }\r\n    public:\r\n        SampleGenerator()\
    \ :rnd() {}\r\n        SampleGenerator(unsigned int seed) :rnd(seed) {}\r\n\r\n\
    \        template<class ... T>\r\n        auto generate(T&& ...ranges) {\r\n \
    \           return std::make_tuple(generate_random(ranges)...);\r\n        }\r\
    \n\r\n        auto generate_permutation(int size) const {\r\n            std::vector<int>\
    \ rnd_p(size);\r\n            std::iota(rnd_p.begin(), rnd_p.end(), 0);\r\n  \
    \          std::shuffle(rnd_p.begin(), rnd_p.end(), rnd.get_gen());\r\n      \
    \      return rnd_p;\r\n        }\r\n    };\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: Utils/sample.hpp
  requiredBy: []
  timestamp: '2023-04-11 03:01:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utils/sample.hpp
layout: document
redirect_from:
- /library/Utils/sample.hpp
- /library/Utils/sample.hpp.html
title: Utils/sample.hpp
---
