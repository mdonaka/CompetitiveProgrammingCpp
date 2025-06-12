---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Algebraic/Monoid.hpp
    title: Library/Algebraic/Monoid.hpp
  - icon: ':question:'
    path: Library/Algorithms/BinarySearch.hpp
    title: Library/Algorithms/BinarySearch.hpp
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/SegmentTree.hpp
    title: Library/DataStructure/SegmentTree.hpp
  - icon: ':heavy_check_mark:'
    path: Library/String/LCPArray.hpp
    title: Library/String/LCPArray.hpp
  - icon: ':heavy_check_mark:'
    path: Library/String/SuffixArray.hpp
    title: Library/String/SuffixArray.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/599
    links:
    - https://yukicoder.me/problems/no/599
  bundledCode: "#line 1 \"Test/String/LCPArray.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/599\"\
    \r\n\r\n#line 2 \"Library/String/LCPArray.hpp\"\n\r\n#line 2 \"Library/String/SuffixArray.hpp\"\
    \n#include <iostream>\r\n#include <list>\r\n#include <set>\r\n#include <string>\r\
    \n#include <unordered_map>\r\n#include <vector>\r\n\r\n#line 2 \"Library/Algorithms/BinarySearch.hpp\"\
    \n\r\n#include <concepts>\r\n#include <numeric>\r\n#include <ranges>\r\n#include\
    \ <type_traits>\r\n\r\nnamespace mtd {\r\n\r\n  template <class Lambda>\r\n  auto\
    \ binarySearch(double ok, double ng, int rep, const Lambda& is_ok) {\r\n    for\
    \ ([[maybe_unused]] auto _ : std::views::iota(0, rep)) {\r\n      double mid =\
    \ (ok + ng) / 2.0;\r\n      (is_ok(mid) ? ok : ng) = mid;\r\n    }\r\n    return\
    \ ok;\r\n  }\r\n\r\n  template <class Lambda, std::integral T1, std::integral\
    \ T2>\r\n  auto binarySearch(T1 ok_, T2 ng_, const Lambda& is_ok) {\r\n    using\
    \ T = std::common_type_t<T1, T2>;\r\n    T ok = ok_, ng = ng_;\r\n    while (std::abs(ok\
    \ - ng) > 1) {\r\n      T mid = (ok + ng) >> 1;\r\n      (is_ok(mid) ? ok : ng)\
    \ = mid;\r\n    }\r\n    return ok;\r\n  }\r\n\r\n}  // namespace mtd\r\n#line\
    \ 10 \"Library/String/SuffixArray.hpp\"\n\r\nnamespace mtd {\r\n  /**\r\n   *\
    \ SuffixArray\u3092\u69CB\u7BC9\u3059\u308B\r\n   * O(N)\r\n   * \u6587\u5B57\u5217\
    \u306E\u5168\u3066\u306Esuffix\u3092\u30BD\u30FC\u30C8\u3057\u305F\u914D\u5217\
    \u304C\u5F97\u3089\u308C\u308B\r\n   * ex) abadc -> [0, 2, 1, 4, 3]([abadc, adc,\
    \ badc, c, dc])\r\n   *\r\n   * SA-IS(Suffix Array - Induced Sort)\u3067\u5B9F\
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
    \ 4 \"Library/String/LCPArray.hpp\"\n\r\nnamespace mtd {\r\n  /**\r\n   * LCPArray\u3092\
    \u69CB\u7BC9\u3059\u308B\r\n   * O(N)\r\n   * suffix array\u3067\u96A3\u63A5\u3059\
    \u308Bstr\u306E\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E(LCP:Longest Common Prefix)\u3092\
    \u5F97\u308B\r\n   * ex) sa:[aab, ab, abaab, b, baab] -> LCPA:[1, 2, 0, 1]\r\n\
    \   *\r\n   * Kasai's algorithm\u3067\u5B9F\u88C5\r\n   */\r\n  class LCPArray\
    \ {\r\n    const std::vector<int> m_suffixArray;\r\n    const std::vector<int>\
    \ m_lcpArray;\r\n\r\n    static std::vector<int> constructLcpArray(const std::string&\
    \ str) {\r\n      auto sz = static_cast<int>(str.size());\r\n      const auto\
    \ suffixArray = SuffixArray(str).getSuffixArray();\r\n\r\n      auto rank = std::vector<int>(sz);\r\
    \n      for (int i = 0; i < sz; ++i) { rank[suffixArray[i]] = i; }\r\n\r\n   \
    \   auto lcpArray = std::vector<int>(sz - 1);\r\n      for (int i = 0, h = 0;\
    \ i < sz; ++i) {\r\n        if (rank[i] == 0) { continue; }\r\n        int j =\
    \ suffixArray[rank[i] - 1];\r\n        if (h > 0) { --h; }\r\n        for (; j\
    \ + h < sz && i + h < sz; ++h) {\r\n          if (str[i + h] != str[j + h]) {\
    \ break; }\r\n        }\r\n        lcpArray[rank[i] - 1] = h;\r\n      }\r\n \
    \     return lcpArray;\r\n    }\r\n\r\n  public:\r\n    LCPArray(const std::string&\
    \ str)\r\n        : m_suffixArray(SuffixArray(str).getSuffixArray()),\r\n    \
    \      m_lcpArray(constructLcpArray(str)) {}\r\n\r\n    auto getLCPArray() const\
    \ { return m_lcpArray; }\r\n    auto getSuffixArrayIndexList() const {\r\n   \
    \   std::vector<int> sail(m_suffixArray.size());\r\n      for (unsigned int i\
    \ = 0; i < m_suffixArray.size(); ++i) {\r\n        sail[m_suffixArray[i]] = i;\r\
    \n      }\r\n      return sail;\r\n    }\r\n  };\r\n}  // namespace mtd\r\n#line\
    \ 4 \"Test/String/LCPArray.test.cpp\"\n\r\n#line 6 \"Test/String/LCPArray.test.cpp\"\
    \n\r\n#line 2 \"Library/DataStructure/SegmentTree.hpp\"\n\r\n#include <deque>\r\
    \n#line 5 \"Library/DataStructure/SegmentTree.hpp\"\n#include <utility>\r\n#line\
    \ 7 \"Library/DataStructure/SegmentTree.hpp\"\n\r\n#line 2 \"Library/Algebraic/Monoid.hpp\"\
    \n\n#line 4 \"Library/Algebraic/Monoid.hpp\"\n\nnamespace mtd {\n\n  template\
    \ <class S,    // set\n            S element,  // identity element\n         \
    \   class op    // binary operation\n            >\n  requires std::is_invocable_r_v<S,\
    \ op, S, S>\n  struct Monoid {\n    using value_type = S;\n    constexpr static\
    \ S _element = element;\n    using op_type = op;\n\n    S m_val;\n    constexpr\
    \ Monoid(S val) : m_val(val) {}\n    constexpr Monoid() : Monoid(element) {}\n\
    \    constexpr Monoid binaryOperation(const Monoid& m2) const {\n      return\
    \ op()(m_val, m2.m_val);\n    }\n    friend std::ostream& operator<<(std::ostream&\
    \ os,\n                                    const Monoid<S, element, op>& m) {\n\
    \      return os << m.m_val;\n    }\n  };\n\n  namespace __detail {\n    template\
    \ <typename T, template <typename, auto, typename> typename S>\n    concept is_monoid_specialization_of\
    \ = requires {\n      typename std::enable_if_t<std::is_same_v<\n          T,\
    \ S<typename T::value_type, T::_element, typename T::op_type>>>;\n    };\n  }\
    \  // namespace __detail\n\n  template <typename M>\n  concept monoid = __detail::is_monoid_specialization_of<M,\
    \ Monoid>;\n\n}  // namespace mtd\n#line 9 \"Library/DataStructure/SegmentTree.hpp\"\
    \n\r\nnamespace mtd {\r\n\r\n  template <monoid Monoid>\r\n  class SegmentTree\
    \ {\r\n  private:\r\n    const int m_size;\r\n    std::vector<Monoid> m_node;\r\
    \n    using S = decltype(Monoid().m_val);\r\n\r\n    constexpr int calcSize(int\
    \ n) const {\r\n      int size = 1;\r\n      while (size < n) { size <<= 1; }\r\
    \n      return size;\r\n    }\r\n\r\n    template <class Lambda>\r\n    constexpr\
    \ auto _update_op(int itr, Monoid&& val, const Lambda& op) {\r\n      int i =\
    \ itr + m_size - 1;\r\n      m_node[i] = op(m_node[i], std::forward<decltype(val)>(val));\r\
    \n      while (i) {\r\n        i = (i - 1) >> 1;\r\n        m_node[i] = m_node[(i\
    \ << 1) | 1].binaryOperation(m_node[(i + 1) << 1]);\r\n      }\r\n    }\r\n\r\n\
    \    constexpr auto _query(int _l, int _r) const {\r\n      auto l = std::max(_l,\
    \ 0) + m_size;\r\n      auto r = std::min(_r, m_size - 1) + m_size;\r\n      auto\
    \ lm = Monoid();\r\n      auto rm = Monoid();\r\n      while (l <= r) {\r\n  \
    \      if (l & 1) {\r\n          lm = lm.binaryOperation(m_node[l - 1]);\r\n \
    \         ++l;\r\n        }\r\n        if (!(r & 1)) {\r\n          rm = m_node[r\
    \ - 1].binaryOperation(rm);\r\n          --r;\r\n        }\r\n        l >>= 1,\
    \ r >>= 1;\r\n      }\r\n      return lm.binaryOperation(rm);\r\n    }\r\n\r\n\
    \    constexpr auto _construct(const std::vector<S>& vec) {\r\n      for (unsigned\
    \ int i = 0; i < vec.size(); ++i) {\r\n        m_node[i + m_size - 1] = Monoid(vec[i]);\r\
    \n      }\r\n      for (int i = m_size - 2; i >= 0; --i) {\r\n        m_node[i]\
    \ = m_node[(i << 1) | 1].binaryOperation(m_node[(i + 1) << 1]);\r\n      }\r\n\
    \    }\r\n\r\n  public:\r\n    SegmentTree(int n) : m_size(calcSize(n)), m_node((m_size\
    \ << 1) - 1) {}\r\n    SegmentTree(int n, const std::vector<S>& vec) : SegmentTree(n)\
    \ {\r\n      _construct(vec);\r\n    }\r\n\r\n    template <class Lambda>\r\n\
    \    constexpr auto update_op(int itr, Monoid&& val, const Lambda& op) {\r\n \
    \     return _update_op(itr, std::forward<Monoid>(val), op);\r\n    }\r\n    constexpr\
    \ auto update(int itr, Monoid&& val) {\r\n      return update_op(itr, std::forward<Monoid>(val),\r\
    \n                       [](const Monoid&, const Monoid& m2) { return m2; });\r\
    \n    }\r\n    constexpr auto add(int itr, Monoid&& val) {\r\n      return update_op(itr,\
    \ std::forward<Monoid>(val),\r\n                       [](const Monoid& m1, const\
    \ Monoid& m2) {\r\n                         return Monoid(m1.m_val + m2.m_val);\r\
    \n                       });\r\n    }\r\n    constexpr auto query(int l, int r)\
    \ const { return _query(l, r).m_val; }\r\n    constexpr auto query_all() const\
    \ { return m_node[0].m_val; }\r\n\r\n    /*\r\n     * f([l, r]) = true \u3068\u306A\
    \u308B\u6700\u5927\u306Er\r\n     * judge: (Monoid) -> bool\r\n     **/\r\n  \
    \  template <class F>\r\n    constexpr auto max_right(int _l, const F& judge)\
    \ const {\r\n      if (!judge(Monoid())) {\r\n        throw std::runtime_error(\"\
    SegmentTree.max_right.judge(e) must be true\");\r\n      }\r\n      auto l = std::max(_l,\
    \ 0) + m_size;\r\n      auto r = 2 * m_size - 1;\r\n      auto lm = Monoid();\r\
    \n      while (l <= r) {\r\n        if (l & 1) {\r\n          auto next = lm.binaryOperation(m_node[l\
    \ - 1]);\r\n          if (!judge(next)) {\r\n            auto itr = l;\r\n   \
    \         while (itr < m_size) {\r\n              auto litr = 2 * itr;\r\n   \
    \           auto ritr = 2 * itr + 1;\r\n              auto lval = lm.binaryOperation(m_node[litr\
    \ - 1]);\r\n              if (!judge(lval)) {\r\n                itr = litr;\r\
    \n              } else {\r\n                itr = ritr;\r\n                std::swap(lm,\
    \ lval);\r\n              }\r\n            }\r\n            return itr - m_size\
    \ - 1;\r\n          }\r\n          std::swap(lm, next);\r\n          ++l;\r\n\
    \        }\r\n        l >>= 1, r >>= 1;\r\n      }\r\n      return m_size - 1;\r\
    \n    }\r\n\r\n    /*\r\n     * f([l, r]) = true \u3068\u306A\u308B\u6700\u5C0F\
    \u306El\r\n     * judge: (Monoid) -> bool\r\n     **/\r\n    template <class F>\r\
    \n    constexpr auto min_left(int _r, const F& judge) const {\r\n      if (!judge(Monoid()))\
    \ {\r\n        throw std::runtime_error(\"SegmentTree.min_left.judge(e) must be\
    \ true\");\r\n      }\r\n      auto l = m_size;\r\n      auto r = std::min(_r,\
    \ m_size - 1) + m_size;\r\n      auto rm = Monoid();\r\n      while (l <= r) {\r\
    \n        if (l & 1) { ++l; }\r\n        if (!(r & 1) || (_r == m_size - 1 &&\
    \ r == 1)) {\r\n          auto next = m_node[r - 1].binaryOperation(rm);\r\n \
    \         if (!judge(next)) {\r\n            auto itr = r;\r\n            while\
    \ (itr < m_size) {\r\n              auto litr = 2 * itr;\r\n              auto\
    \ ritr = 2 * itr + 1;\r\n              auto rval = m_node[ritr - 1].binaryOperation(rm);\r\
    \n              if (!judge(rval)) {\r\n                itr = ritr;\r\n       \
    \       } else {\r\n                itr = litr;\r\n                std::swap(rm,\
    \ rval);\r\n              }\r\n            }\r\n            return itr - m_size\
    \ + 1;\r\n          }\r\n          std::swap(rm, next);\r\n          --r;\r\n\
    \        }\r\n        l >>= 1, r >>= 1;\r\n      }\r\n      return 0;\r\n    }\r\
    \n\r\n    constexpr auto debug() const {\r\n      for (int i = 0; i < m_size;\
    \ ++i) {\r\n        std::cout << m_node[m_size + i - 1] << \" \";\r\n      }\r\
    \n      std::cout << std::endl;\r\n    }\r\n  };\r\n\r\n}  // namespace mtd\r\n\
    #line 8 \"Test/String/LCPArray.test.cpp\"\n\r\nusing ll = long long;\r\nusing\
    \ std::cin;\r\nusing std::cout;\r\nconstexpr char endl = '\\n';\r\nstruct Preprocessing\
    \ {\r\n  Preprocessing() {\r\n    std::cin.tie(0);\r\n    std::ios::sync_with_stdio(0);\r\
    \n  };\r\n} _Preprocessing;\r\n\r\nstruct F {\r\n  auto operator()(int a, int\
    \ b) const { return std::min(a, b); };\r\n};\r\nusing M = mtd::Monoid<int, static_cast<int>(1e9),\
    \ F>;\r\n\r\nconstexpr ll MOD = 1000000007;\r\n\r\nsigned main() {\r\n  std::string\
    \ s;\r\n  cin >> s;\r\n\r\n  ll size = s.size();\r\n  auto lcparray = mtd::LCPArray(s);\r\
    \n  auto segtree = mtd::SegmentTree<M>(size, lcparray.getLCPArray());\r\n  auto\
    \ sai = lcparray.getSuffixArrayIndexList();\r\n\r\n  ll half = (size >> 1);\r\n\
    \  std::vector<ll> dp(half + 1);\r\n  dp[0] = 1;\r\n  for (int l = 0; l < half;\
    \ ++l) {\r\n    for (int r = l; r < half; ++r) {\r\n      auto idx1 = sai[l];\r\
    \n      auto idx2 = sai[size - r - 1];\r\n      if (idx2 < idx1) { std::swap(idx1,\
    \ idx2); }\r\n      auto lcp = segtree.query(idx1, idx2 - 1);\r\n\r\n      int\
    \ len = r - l + 1;\r\n      if (lcp >= len) {\r\n        dp[r + 1] += dp[l];\r\
    \n        if (dp[r + 1] >= MOD) { dp[r + 1] -= MOD; }\r\n      }\r\n    }\r\n\
    \  }\r\n\r\n  ll ans = 0;\r\n  for (const auto& x : dp) {\r\n    ans += x;\r\n\
    \    if (ans >= MOD) { ans -= MOD; }\r\n  }\r\n  cout << ans;\r\n}\r\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/599\"\r\n\r\n#include\
    \ \"./../../Library/String/LCPArray.hpp\"\r\n\r\n#include <iostream>\r\n\r\n#include\
    \ \"./../../Library/DataStructure/SegmentTree.hpp\"\r\n\r\nusing ll = long long;\r\
    \nusing std::cin;\r\nusing std::cout;\r\nconstexpr char endl = '\\n';\r\nstruct\
    \ Preprocessing {\r\n  Preprocessing() {\r\n    std::cin.tie(0);\r\n    std::ios::sync_with_stdio(0);\r\
    \n  };\r\n} _Preprocessing;\r\n\r\nstruct F {\r\n  auto operator()(int a, int\
    \ b) const { return std::min(a, b); };\r\n};\r\nusing M = mtd::Monoid<int, static_cast<int>(1e9),\
    \ F>;\r\n\r\nconstexpr ll MOD = 1000000007;\r\n\r\nsigned main() {\r\n  std::string\
    \ s;\r\n  cin >> s;\r\n\r\n  ll size = s.size();\r\n  auto lcparray = mtd::LCPArray(s);\r\
    \n  auto segtree = mtd::SegmentTree<M>(size, lcparray.getLCPArray());\r\n  auto\
    \ sai = lcparray.getSuffixArrayIndexList();\r\n\r\n  ll half = (size >> 1);\r\n\
    \  std::vector<ll> dp(half + 1);\r\n  dp[0] = 1;\r\n  for (int l = 0; l < half;\
    \ ++l) {\r\n    for (int r = l; r < half; ++r) {\r\n      auto idx1 = sai[l];\r\
    \n      auto idx2 = sai[size - r - 1];\r\n      if (idx2 < idx1) { std::swap(idx1,\
    \ idx2); }\r\n      auto lcp = segtree.query(idx1, idx2 - 1);\r\n\r\n      int\
    \ len = r - l + 1;\r\n      if (lcp >= len) {\r\n        dp[r + 1] += dp[l];\r\
    \n        if (dp[r + 1] >= MOD) { dp[r + 1] -= MOD; }\r\n      }\r\n    }\r\n\
    \  }\r\n\r\n  ll ans = 0;\r\n  for (const auto& x : dp) {\r\n    ans += x;\r\n\
    \    if (ans >= MOD) { ans -= MOD; }\r\n  }\r\n  cout << ans;\r\n}\r\n"
  dependsOn:
  - Library/String/LCPArray.hpp
  - Library/String/SuffixArray.hpp
  - Library/Algorithms/BinarySearch.hpp
  - Library/DataStructure/SegmentTree.hpp
  - Library/Algebraic/Monoid.hpp
  isVerificationFile: true
  path: Test/String/LCPArray.test.cpp
  requiredBy: []
  timestamp: '2025-01-23 04:47:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/String/LCPArray.test.cpp
layout: document
redirect_from:
- /verify/Test/String/LCPArray.test.cpp
- /verify/Test/String/LCPArray.test.cpp.html
title: Test/String/LCPArray.test.cpp
---
