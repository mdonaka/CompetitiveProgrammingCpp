---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Algorithms/BinarySearch.hpp
    title: Library/Algorithms/BinarySearch.hpp
  - icon: ':x:'
    path: Library/String/SuffixArray.hpp
    title: Library/String/SuffixArray.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_D
  bundledCode: "#line 1 \"Test/String/SuffixArray.test.cpp\"\n#define PROBLEM \\\r\
    \n  \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_D\"\r\
    \n\r\n#line 2 \"Library/String/SuffixArray.hpp\"\n#include <iostream>\r\n#include\
    \ <list>\r\n#include <set>\r\n#include <string>\r\n#include <unordered_map>\r\n\
    #include <vector>\r\n\r\n#line 2 \"Library/Algorithms/BinarySearch.hpp\"\n\r\n\
    #include <numeric>\r\n#include <ranges>\r\n\r\nnamespace mtd {\r\n\r\n  template\
    \ <class Lambda>\r\n  auto binarySearch(double ok, double ng, int rep, const Lambda&\
    \ is_ok) {\r\n    for ([[maybe_unused]] auto _ : std::views::iota(0, rep)) {\r\
    \n      double mid = (ok + ng) / 2.0;\r\n      (is_ok(mid) ? ok : ng) = mid;\r\
    \n    }\r\n    return ok;\r\n  }\r\n\r\n  template <class Lambda, class T = long\
    \ long>\r\n  auto binarySearch(T ok, T ng, const Lambda& is_ok) {\r\n    while\
    \ (std::abs(ok - ng) > 1) {\r\n      T mid = (ok + ng) >> 1;\r\n      (is_ok(mid)\
    \ ? ok : ng) = mid;\r\n    }\r\n    return ok;\r\n  }\r\n\r\n}  // namespace mtd\r\
    \n#line 10 \"Library/String/SuffixArray.hpp\"\n\r\nnamespace mtd {\r\n  /**\r\n\
    \   * SuffixArray\u3092\u69CB\u7BC9\u3059\u308B\r\n   * O(N)\r\n   * \u6587\u5B57\
    \u5217\u306E\u5168\u3066\u306Esuffix\u3092\u30BD\u30FC\u30C8\u3057\u305F\u914D\
    \u5217\u304C\u5F97\u3089\u308C\u308B\r\n   * ex) abadc -> [0, 2, 1, 4, 3]([abadc,\
    \ adc, badc, c, dc])\r\n   *\r\n   * SA-IS(Suffix Array - Induced Sort)\u3067\u5B9F\
    \u88C5\r\n   */\r\n  class SuffixArray {\r\n    enum class TYPE { L, S, LMS };\r\
    \n\r\n    const std::string m_str;\r\n    const std::vector<int> m_suffixArray;\r\
    \n\r\n    /* string to vector<int> */\r\n    static std::vector<int> toIntVec(const\
    \ std::string& str) {\r\n      std::vector<int> vec;\r\n      vec.reserve(str.size()\
    \ + 1);\r\n      for (const auto& c : str) { vec.emplace_back(c - '0' + 1); }\r\
    \n      vec.emplace_back(0);\r\n      return vec;\r\n    }\r\n\r\n    /* classify\
    \ { L, S, LMS } */\r\n    static std::vector<TYPE> classifying(const std::vector<int>&\
    \ str) {\r\n      auto sz = static_cast<int>(str.size());\r\n      auto typeArray\
    \ = std::vector<TYPE>(sz);\r\n      typeArray[sz - 1] = TYPE::S;\r\n      for\
    \ (int i = sz - 2; i >= 0; --i) {\r\n        if (str[i] == str[i + 1]) {\r\n \
    \         typeArray[i] = typeArray[i + 1];\r\n          continue;\r\n        }\r\
    \n        typeArray[i] = (str[i] < str[i + 1]) ? TYPE::S : TYPE::L;\r\n      }\r\
    \n      for (int i = 1; i < sz; ++i) {\r\n        if (typeArray[i - 1] == TYPE::L\
    \ && typeArray[i] == TYPE::S) {\r\n          typeArray[i] = TYPE::LMS;\r\n   \
    \     }\r\n      }\r\n      return typeArray;\r\n    }\r\n\r\n    /* induced sort\
    \ */\r\n    static std::vector<int> inducedSort(const std::vector<int>& str,\r\
    \n                                        const std::vector<TYPE>& type,\r\n \
    \                                       std::list<int>& lmsList) {\r\n      auto\
    \ sz = str.size();\r\n      auto nList = std::set<int>();\r\n      for (const\
    \ auto& c : str) { nList.emplace(c); }\r\n\r\n      auto befCheck = [&](int k,\
    \ auto& addList, bool rev) {\r\n        if (k == 0) { return; }\r\n        if\
    \ (!rev && type[k - 1] == TYPE::L) {\r\n          addList[str[k - 1]].emplace_back(k\
    \ - 1);\r\n        }\r\n        if (rev && type[k - 1] != TYPE::L) {\r\n     \
    \     addList[str[k - 1]].emplace_front(k - 1);\r\n        }\r\n      };\r\n\r\
    \n      auto checkAndUpdate = [&](int n, auto& checkList, auto& addList,\r\n \
    \                               bool rev) {\r\n        auto& lst = checkList[n];\r\
    \n        if (rev) {\r\n          for (auto itr = lst.rbegin(); itr != lst.rend();\
    \ ++itr) {\r\n            befCheck(*itr, addList, rev);\r\n          }\r\n   \
    \     } else {\r\n          for (const auto& k : lst) { befCheck(k, addList, rev);\
    \ }\r\n        }\r\n      };\r\n\r\n      /* set LMS */\r\n      auto tailList\
    \ = std::unordered_map<int, std::list<int>>();\r\n      for (const auto& i : lmsList)\
    \ { tailList[str[i]].emplace_back(i); }\r\n\r\n      /* set L-type */\r\n    \
    \  auto headList = std::unordered_map<int, std::list<int>>();\r\n      for (const\
    \ auto& n : nList) {\r\n        checkAndUpdate(n, headList, headList, false);\r\
    \n        checkAndUpdate(n, tailList, headList, false);\r\n      }\r\n\r\n   \
    \   /* set S-type*/\r\n      tailList = std::unordered_map<int, std::list<int>>();\r\
    \n      for (auto itr_n = nList.rbegin(); itr_n != nList.rend(); ++itr_n) {\r\n\
    \        auto n = *itr_n;\r\n        checkAndUpdate(n, tailList, tailList, true);\r\
    \n        checkAndUpdate(n, headList, tailList, true);\r\n      }\r\n\r\n    \
    \  /* merge */\r\n      auto suffixArray = std::vector<int>();\r\n      suffixArray.reserve(sz);\r\
    \n      for (const auto& n : nList) {\r\n        for (const auto& c : headList[n])\
    \ { suffixArray.emplace_back(c); }\r\n        for (const auto& c : tailList[n])\
    \ { suffixArray.emplace_back(c); }\r\n      }\r\n\r\n      return suffixArray;\r\
    \n    }\r\n\r\n    /* order lms -> sorted lms */\r\n    static std::unordered_map<int,\
    \ int> getLmsChanger(\r\n        const std::vector<int>& str, const std::vector<TYPE>&\
    \ type,\r\n        const std::list<int>& lms) {\r\n      if (lms.size() == 1)\
    \ {\r\n        return std::unordered_map<int, int>{{str.size() - 1, 0}};\r\n \
    \     }\r\n      std::unordered_map<int, int> changer{\r\n          {static_cast<int>(str.size())\
    \ - 1, 0}, {*++lms.begin(), 1}};\r\n      int num = 1;\r\n      for (auto itr\
    \ = ++lms.begin(); itr != (--lms.end());) {\r\n        auto f1 = *itr;\r\n   \
    \     auto f2 = *(++itr);\r\n\r\n        bool isSame = false;\r\n        for (int\
    \ i = 0;; ++i) {\r\n          if (str[f1 + i] != str[f2 + i]) { break; }\r\n \
    \         auto b1 = (type[f1 + i] == TYPE::LMS);\r\n          auto b2 = (type[f2\
    \ + i] == TYPE::LMS);\r\n          if ((b1 || b2) && i > 0) {\r\n            if\
    \ (b1 && b2) {\r\n              isSame = true;\r\n              break;\r\n   \
    \         }\r\n            break;\r\n          }\r\n        }\r\n        if (!isSame)\
    \ { ++num; }\r\n        changer.emplace(f2, num);\r\n      }\r\n      return changer;\r\
    \n    }\r\n\r\n    /* calc Suffix Array*/\r\n    static std::vector<int> constructSuffixArray(const\
    \ std::vector<int>& str) {\r\n      auto type = classifying(str);\r\n\r\n    \
    \  /* calc fake Suffix Array using order seed*/\r\n      auto lmsOrder = [&type]()\
    \ {\r\n        auto lms = std::list<int>();\r\n        for (size_t i = 0; i <\
    \ type.size(); ++i)\r\n          if (type[i] == TYPE::LMS) { lms.emplace_back(i);\
    \ }\r\n        return lms;\r\n      }();\r\n      auto fakeArray = inducedSort(str,\
    \ type, lmsOrder);\r\n\r\n      /* calc true seed */\r\n      auto lmsFakeOrder\
    \ = [&fakeArray, &type]() {\r\n        auto lms = std::list<int>();\r\n      \
    \  lms.emplace_back(static_cast<int>(type.size()) - 1);\r\n        for (const\
    \ auto& i : fakeArray)\r\n          if (type[i] == TYPE::LMS) { lms.emplace_back(i);\
    \ }\r\n        return lms;\r\n      }();\r\n      auto changer = getLmsChanger(str,\
    \ type, lmsFakeOrder);\r\n      auto& lmsTrueOrder = lmsFakeOrder;\r\n      if\
    \ (changer[*lmsFakeOrder.rbegin()] + 1 <\r\n          static_cast<int>(lmsFakeOrder.size()))\
    \ {\r\n        /* exist same lms-substring */\r\n        auto s = std::vector<int>();\r\
    \n        auto def = std::vector<int>();\r\n        s.reserve(lmsOrder.size());\r\
    \n        def.reserve(lmsOrder.size());\r\n        for (const auto& c : lmsOrder)\
    \ {\r\n          s.emplace_back(changer[c]);\r\n          def.emplace_back(c);\r\
    \n        }\r\n        auto lmsSuffixArray = constructSuffixArray(s);\r\n    \
    \    lmsTrueOrder = std::list<int>{static_cast<int>(type.size()) - 1};\r\n   \
    \     for (const auto& c : lmsSuffixArray) {\r\n          lmsTrueOrder.emplace_back(def[c]);\r\
    \n        }\r\n      }\r\n\r\n      /* calc true Suffix Array using true seed\
    \ */\r\n      auto suffixArray = inducedSort(str, type, lmsTrueOrder);\r\n\r\n\
    \      return suffixArray;\r\n    }\r\n\r\n  public:\r\n    SuffixArray(const\
    \ std::string& str)\r\n        : m_str(str), m_suffixArray(constructSuffixArray(toIntVec(str)))\
    \ {}\r\n\r\n    /**\r\n     * \u5F15\u6570\u3068\u3057\u3066\u4E0E\u3048\u3089\
    \u308C\u305Fpattern\u51FA\u73FE\u4F4D\u7F6E\u306E\u533A\u9593\u3092\u8FD4\u3059\
    \r\n     */\r\n    std::pair<int, int> findPattern(const std::string& pattern)\
    \ const {\r\n      auto find = [&](const std::string& ptn) {\r\n        int end\
    \ = static_cast<int>(m_suffixArray.size());\r\n        int ptn_sz = static_cast<int>(ptn.size());\r\
    \n        auto ret = binarySearch(end, -1, [&](int mid) {\r\n          int st\
    \ = m_suffixArray[mid];\r\n          int sub_sz = end - st;\r\n          for (int\
    \ k = 0; k < std::min(ptn_sz, sub_sz); ++k) {\r\n            if (ptn[k] < m_str[st\
    \ + k]) { return true; }\r\n            if (ptn[k] > m_str[st + k]) { return false;\
    \ }\r\n          }\r\n          return ptn_sz <= sub_sz;\r\n        });\r\n  \
    \      return ret;\r\n      };\r\n      auto patternUpper = [&pattern]() {\r\n\
    \        auto ptn = pattern;\r\n        ++*ptn.rbegin();\r\n        return ptn;\r\
    \n      }();\r\n      auto fl = find(pattern);\r\n      auto fu = find(patternUpper);\r\
    \n      return {fl, fu};\r\n    }\r\n\r\n    auto getSuffixArray() const { return\
    \ m_suffixArray; }\r\n\r\n    /* output fot debug */\r\n    void debugOutput()\
    \ const {\r\n      for (const auto& x : m_suffixArray) { std::cout << x << \"\
    \ \"; }\r\n      std::cout << std::endl;\r\n      auto end = m_str.size();\r\n\
    \      for (const auto& x : m_suffixArray) {\r\n        std::cout << m_str.substr(x,\
    \ end) << std::endl;\r\n      }\r\n    }\r\n  };\r\n}  // namespace mtd\r\n#line\
    \ 5 \"Test/String/SuffixArray.test.cpp\"\n\r\n#line 7 \"Test/String/SuffixArray.test.cpp\"\
    \n\r\nusing ll = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr\
    \ char endl = '\\n';\r\nstruct Preprocessing {\r\n  Preprocessing() {\r\n    std::cin.tie(0);\r\
    \n    std::ios::sync_with_stdio(0);\r\n  };\r\n} _Preprocessing;\r\n\r\nsigned\
    \ main() {\r\n  std::string s;\r\n  ll n;\r\n  cin >> s >> n;\r\n  std::vector<std::string>\
    \ vt;\r\n  vt.reserve(n);\r\n  for (int _ = 0; _ < n; ++_) {\r\n    std::string\
    \ t;\r\n    cin >> t;\r\n    vt.emplace_back(t);\r\n  }\r\n\r\n  auto sa = mtd::SuffixArray(s);\r\
    \n\r\n  for (const auto& t : vt) {\r\n    auto [l, r] = sa.findPattern(t);\r\n\
    \    cout << ((r - l) > 0) << endl;\r\n  }\r\n}\r\n"
  code: "#define PROBLEM \\\r\n  \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_D\"\
    \r\n\r\n#include \"./../../Library/String/SuffixArray.hpp\"\r\n\r\n#include <iostream>\r\
    \n\r\nusing ll = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr\
    \ char endl = '\\n';\r\nstruct Preprocessing {\r\n  Preprocessing() {\r\n    std::cin.tie(0);\r\
    \n    std::ios::sync_with_stdio(0);\r\n  };\r\n} _Preprocessing;\r\n\r\nsigned\
    \ main() {\r\n  std::string s;\r\n  ll n;\r\n  cin >> s >> n;\r\n  std::vector<std::string>\
    \ vt;\r\n  vt.reserve(n);\r\n  for (int _ = 0; _ < n; ++_) {\r\n    std::string\
    \ t;\r\n    cin >> t;\r\n    vt.emplace_back(t);\r\n  }\r\n\r\n  auto sa = mtd::SuffixArray(s);\r\
    \n\r\n  for (const auto& t : vt) {\r\n    auto [l, r] = sa.findPattern(t);\r\n\
    \    cout << ((r - l) > 0) << endl;\r\n  }\r\n}\r\n"
  dependsOn:
  - Library/String/SuffixArray.hpp
  - Library/Algorithms/BinarySearch.hpp
  isVerificationFile: true
  path: Test/String/SuffixArray.test.cpp
  requiredBy: []
  timestamp: '2024-12-27 17:07:26+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/String/SuffixArray.test.cpp
layout: document
redirect_from:
- /verify/Test/String/SuffixArray.test.cpp
- /verify/Test/String/SuffixArray.test.cpp.html
title: Test/String/SuffixArray.test.cpp
---
