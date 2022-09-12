---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/sample/sample1.test.cpp
    title: Test/sample/sample1.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utils/sample.hpp\"\n#include <random>\r\n#include <vector>\r\
    \n#include <tuple>\r\n#include<iostream>\r\n\r\nnamespace Sample {\r\n\r\n\tusing\
    \ std::cout;\r\n\tconstexpr char endl = '\\n';\r\n\tclass Range {\r\n\t\tconst\
    \ uint_fast64_t l;\r\n\t\tconst uint_fast64_t u;\r\n\tpublic:\r\n\t\tRange(uint_fast64_t\
    \ l, uint_fast64_t u) :l(l), u(u) {}\r\n\t\tRange(uint_fast64_t u) :l(0), u(u)\
    \ {}\r\n\r\n\t\tauto normalize(uint_fast64_t val)const {\r\n\t\t\treturn (val\
    \ % (u + 1 - l)) + l;\r\n\t\t}\r\n\t};\r\n\r\n\tclass RandomGenerator {\r\n\t\t\
    std::mt19937_64 mt;\r\n\tpublic:\r\n\t\tRandomGenerator(unsigned int seed = std::random_device()())\
    \ : mt(std::mt19937_64(seed)) {}\r\n\r\n\t\t// [l,u]\r\n\t\tauto random(const\
    \ Range& range) { return range.normalize(mt()); }\r\n\t\tauto random(uint_fast64_t\
    \ l, uint_fast64_t u) { return random(Range(l, u)); }\r\n\t\tauto random(uint_fast64_t\
    \ u) { return random(Range(0LL, u)); }\r\n\r\n\t\tauto get_gen()const { return\
    \ mt; }\r\n\t};\r\n\r\n\tclass SampleGenerator {\r\n\t\tRandomGenerator rnd;\r\
    \n\r\n\t\tauto generate_random(const Range& range) {\r\n\t\t\treturn rnd.random(range);\r\
    \n\t\t}\r\n\t\tauto generate_random(const std::pair<int_fast64_t, int_fast64_t>&\
    \ pair) { return rnd.random(Range(pair.first, pair.second)); }\r\n\t\ttemplate<class\
    \ T>\r\n\t\tauto generate_random(const std::vector<T>& ranges) {\r\n\t\t\tstd::vector<long\
    \ long> v;\r\n\t\t\tv.reserve(ranges.size());\r\n\t\t\tfor (auto&& range : ranges)\
    \ { v.emplace_back(generate_random(range)); }\r\n\t\t\treturn v;\r\n\t\t}\r\n\t\
    public:\r\n\t\tSampleGenerator() :rnd() {}\r\n\t\tSampleGenerator(unsigned int\
    \ seed) :rnd(seed) {}\r\n\r\n\t\ttemplate<class ... T>\r\n\t\tauto generate(T&&\
    \ ...ranges) {\r\n\t\t\treturn std::make_tuple(generate_random(ranges)...);\r\n\
    \t\t}\r\n\r\n\t\tauto generate_permutation(int size) const {\r\n\t\t\tstd::vector<int>\
    \ rnd_p(size);\r\n\t\t\tstd::iota(rnd_p.begin(), rnd_p.end(), 0);\r\n\t\t\tstd::shuffle(rnd_p.begin(),\
    \ rnd_p.end(), rnd.get_gen());\r\n\t\t\treturn rnd_p;\r\n\t\t}\r\n\t};\r\n}\n"
  code: "#pragma once\r\n#include <random>\r\n#include <vector>\r\n#include <tuple>\r\
    \n#include<iostream>\r\n\r\nnamespace Sample {\r\n\r\n\tusing std::cout;\r\n\t\
    constexpr char endl = '\\n';\r\n\tclass Range {\r\n\t\tconst uint_fast64_t l;\r\
    \n\t\tconst uint_fast64_t u;\r\n\tpublic:\r\n\t\tRange(uint_fast64_t l, uint_fast64_t\
    \ u) :l(l), u(u) {}\r\n\t\tRange(uint_fast64_t u) :l(0), u(u) {}\r\n\r\n\t\tauto\
    \ normalize(uint_fast64_t val)const {\r\n\t\t\treturn (val % (u + 1 - l)) + l;\r\
    \n\t\t}\r\n\t};\r\n\r\n\tclass RandomGenerator {\r\n\t\tstd::mt19937_64 mt;\r\n\
    \tpublic:\r\n\t\tRandomGenerator(unsigned int seed = std::random_device()()) :\
    \ mt(std::mt19937_64(seed)) {}\r\n\r\n\t\t// [l,u]\r\n\t\tauto random(const Range&\
    \ range) { return range.normalize(mt()); }\r\n\t\tauto random(uint_fast64_t l,\
    \ uint_fast64_t u) { return random(Range(l, u)); }\r\n\t\tauto random(uint_fast64_t\
    \ u) { return random(Range(0LL, u)); }\r\n\r\n\t\tauto get_gen()const { return\
    \ mt; }\r\n\t};\r\n\r\n\tclass SampleGenerator {\r\n\t\tRandomGenerator rnd;\r\
    \n\r\n\t\tauto generate_random(const Range& range) {\r\n\t\t\treturn rnd.random(range);\r\
    \n\t\t}\r\n\t\tauto generate_random(const std::pair<int_fast64_t, int_fast64_t>&\
    \ pair) { return rnd.random(Range(pair.first, pair.second)); }\r\n\t\ttemplate<class\
    \ T>\r\n\t\tauto generate_random(const std::vector<T>& ranges) {\r\n\t\t\tstd::vector<long\
    \ long> v;\r\n\t\t\tv.reserve(ranges.size());\r\n\t\t\tfor (auto&& range : ranges)\
    \ { v.emplace_back(generate_random(range)); }\r\n\t\t\treturn v;\r\n\t\t}\r\n\t\
    public:\r\n\t\tSampleGenerator() :rnd() {}\r\n\t\tSampleGenerator(unsigned int\
    \ seed) :rnd(seed) {}\r\n\r\n\t\ttemplate<class ... T>\r\n\t\tauto generate(T&&\
    \ ...ranges) {\r\n\t\t\treturn std::make_tuple(generate_random(ranges)...);\r\n\
    \t\t}\r\n\r\n\t\tauto generate_permutation(int size) const {\r\n\t\t\tstd::vector<int>\
    \ rnd_p(size);\r\n\t\t\tstd::iota(rnd_p.begin(), rnd_p.end(), 0);\r\n\t\t\tstd::shuffle(rnd_p.begin(),\
    \ rnd_p.end(), rnd.get_gen());\r\n\t\t\treturn rnd_p;\r\n\t\t}\r\n\t};\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: Utils/sample.hpp
  requiredBy: []
  timestamp: '2022-09-13 04:17:20+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Test/sample/sample1.test.cpp
documentation_of: Utils/sample.hpp
layout: document
redirect_from:
- /library/Utils/sample.hpp
- /library/Utils/sample.hpp.html
title: Utils/sample.hpp
---
