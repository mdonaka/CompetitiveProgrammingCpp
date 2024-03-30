---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Algorithms/BinarySearch.hpp
    title: Library/Algorithms/BinarySearch.hpp
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/SegmentTree.hpp
    title: Library/DataStructure/SegmentTree.hpp
  - icon: ':heavy_check_mark:'
    path: Library/String/LCPArray.hpp
    title: Library/String/LCPArray.hpp
  - icon: ':question:'
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
    \r\n\r\n#include <iostream>\r\n\r\n#line 2 \"Library/String/LCPArray.hpp\"\n\r\
    \n#line 2 \"Library/Algorithms/BinarySearch.hpp\"\n#include <numeric>\r\n\r\n\
    template <class Lambda>\r\nauto binarySearch(double mn, double mx, int rep, const\
    \ Lambda& judge,\r\n                  bool rev = false) {\r\n    auto ok = mx;\r\
    \n    auto ng = mn;\r\n    for(int _ = 0; _ < rep; ++_) {\r\n        auto mid\
    \ = (ok + ng) / 2;\r\n        auto isOk = judge(mid);\r\n        if((isOk && !rev)\
    \ || (!isOk && rev)) {\r\n            ok = mid;\r\n        } else {\r\n      \
    \      ng = mid;\r\n        }\r\n    }\r\n    return ok;\r\n}\r\n\r\ntemplate\
    \ <class Lambda>\r\nauto binarySearch(long long ok, long long ng, const Lambda&\
    \ is_ok) {\r\n    while(std::abs(ok - ng) > 1) {\r\n        long long mid = (ok\
    \ + ng) >> 1;\r\n        (is_ok(mid) ? ok : ng) = mid;\r\n    }\r\n    return\
    \ ok;\r\n}\r\n#line 3 \"Library/String/SuffixArray.hpp\"\n\r\n#line 5 \"Library/String/SuffixArray.hpp\"\
    \n#include <vector>\r\n#include <list>\r\n#include <string>\r\n#include <set>\r\
    \n#include <unordered_map>\r\n/**\r\n * SuffixArray\u3092\u69CB\u7BC9\u3059\u308B\
    \r\n * O(N)\r\n * \u6587\u5B57\u5217\u306E\u5168\u3066\u306Esuffix\u3092\u30BD\
    \u30FC\u30C8\u3057\u305F\u914D\u5217\u304C\u5F97\u3089\u308C\u308B\r\n * ex) abadc\
    \ -> [0, 2, 1, 4, 3]([abadc, adc, badc, c, dc])\r\n *\r\n * SA-IS(Suffix Array\
    \ - Induced Sort)\u3067\u5B9F\u88C5\r\n */\r\nclass SuffixArray {\r\n    enum\
    \ class TYPE {\r\n        L, S, LMS\r\n    };\r\n\r\n    const std::string m_str;\r\
    \n    const std::vector<int> m_suffixArray;\r\n\r\n    /* string to vector<int>\
    \ */\r\n    static std::vector<int> toIntVec(const std::string& str) {\r\n   \
    \     std::vector<int> vec;\r\n        vec.reserve(str.size() + 1);\r\n      \
    \  for(const auto& c : str) {\r\n            vec.emplace_back(c - '0' + 1);\r\n\
    \        }\r\n        vec.emplace_back(0);\r\n        return vec;\r\n    }\r\n\
    \r\n    /* classify { L, S, LMS } */\r\n    static std::vector<TYPE> classifying(const\
    \ std::vector<int>& str) {\r\n        auto sz = str.size();\r\n        auto typeArray\
    \ = std::vector<TYPE>(sz);\r\n        typeArray[sz - 1] = TYPE::S;\r\n       \
    \ for(int i = sz - 2; i >= 0; --i) {\r\n            if(str[i] == str[i + 1]) {\r\
    \n                typeArray[i] = typeArray[i + 1];\r\n                continue;\r\
    \n            }\r\n            typeArray[i] = (str[i] < str[i + 1]) ? TYPE::S\
    \ : TYPE::L;\r\n        }\r\n        for(int i = 1; i < sz; ++i) {\r\n       \
    \     if(typeArray[i - 1] == TYPE::L && typeArray[i] == TYPE::S) {\r\n       \
    \         typeArray[i] = TYPE::LMS;\r\n            }\r\n        }\r\n        return\
    \ typeArray;\r\n    }\r\n\r\n    /* induced sort */\r\n    static std::vector<int>\
    \ inducedSort(const std::vector<int>& str, const std::vector<TYPE>& type, std::list<int>&\
    \ lmsList) {\r\n        auto sz = str.size();\r\n        auto nList = std::set<int>();\r\
    \n        for(const auto& c : str) { nList.emplace(c); }\r\n\r\n        auto befCheck\
    \ = [&](int k, auto& addList, bool rev) {\r\n            if(k == 0) { return;\
    \ }\r\n            if(!rev && type[k - 1] == TYPE::L) {\r\n                addList[str[k\
    \ - 1]].emplace_back(k - 1);\r\n            }\r\n            if(rev && type[k\
    \ - 1] != TYPE::L) {\r\n                addList[str[k - 1]].emplace_front(k -\
    \ 1);\r\n            }\r\n        };\r\n\r\n        auto checkAndUpdate = [&](int\
    \ n, auto& checkList, auto& addList, bool rev) {\r\n            auto& lst = checkList[n];\r\
    \n            if(rev) {\r\n                for(auto itr = lst.rbegin(); itr !=\
    \ lst.rend(); ++itr) { befCheck(*itr, addList, rev); }\r\n            } else {\r\
    \n                for(const auto& k : lst) { befCheck(k, addList, rev); }\r\n\
    \            }\r\n        };\r\n\r\n        /* set LMS */\r\n        auto tailList\
    \ = std::unordered_map<int, std::list<int>>();\r\n        for(const auto& i :\
    \ lmsList) { tailList[str[i]].emplace_back(i); }\r\n\r\n        /* set L-type\
    \ */\r\n        auto headList = std::unordered_map<int, std::list<int>>();\r\n\
    \        for(const auto& n : nList) {\r\n            checkAndUpdate(n, headList,\
    \ headList, false);\r\n            checkAndUpdate(n, tailList, headList, false);\r\
    \n        }\r\n\r\n        /* set S-type*/\r\n        tailList = std::unordered_map<int,\
    \ std::list<int>>();\r\n        for(auto itr_n = nList.rbegin(); itr_n != nList.rend();\
    \ ++itr_n) {\r\n            auto n = *itr_n;\r\n            checkAndUpdate(n,\
    \ tailList, tailList, true);\r\n            checkAndUpdate(n, headList, tailList,\
    \ true);\r\n        }\r\n\r\n        /* merge */\r\n        auto suffixArray =\
    \ std::vector<int>();\r\n        suffixArray.reserve(sz);\r\n        for(const\
    \ auto& n : nList) {\r\n            for(const auto& c : headList[n]) { suffixArray.emplace_back(c);\
    \ }\r\n            for(const auto& c : tailList[n]) { suffixArray.emplace_back(c);\
    \ }\r\n        }\r\n\r\n        return suffixArray;\r\n    }\r\n\r\n    /* order\
    \ lms -> sorted lms */\r\n    static std::unordered_map<int, int> getLmsChanger(const\
    \ std::vector<int>& str, const std::vector<TYPE>& type, const std::list<int>&\
    \ lms) {\r\n        if(lms.size() == 1) { return std::unordered_map<int, int>{\
    \ { str.size() - 1, 0 }}; }\r\n        std::unordered_map<int, int> changer{{static_cast<int>(str.size())\
    \ - 1,0},{*++lms.begin(),1}};\r\n        int num = 1;\r\n        for(auto itr\
    \ = ++lms.begin(); itr != (--lms.end());) {\r\n            auto f1 = *itr;\r\n\
    \            auto f2 = *(++itr);\r\n\r\n            bool isSame = false;\r\n \
    \           for(int i = 0;; ++i) {\r\n                if(str[f1 + i] != str[f2\
    \ + i]) { break; }\r\n                auto b1 = (type[f1 + i] == TYPE::LMS);\r\
    \n                auto b2 = (type[f2 + i] == TYPE::LMS);\r\n                if((b1\
    \ || b2) && i > 0) {\r\n                    if(b1 && b2) { isSame = true; break;\
    \ }\r\n                    break;\r\n                }\r\n            }\r\n  \
    \          if(!isSame) { ++num; }\r\n            changer.emplace(f2, num);\r\n\
    \        }\r\n        return changer;\r\n    }\r\n\r\n    /* calc Suffix Array*/\r\
    \n    static std::vector<int> constructSuffixArray(const std::vector<int>& str)\
    \ {\r\n        auto type = classifying(str);\r\n\r\n        /* calc fake Suffix\
    \ Array using order seed*/\r\n        auto lmsOrder = [&type]() {\r\n        \
    \    auto lms = std::list<int>();\r\n            for(int i = 0; i < type.size();\
    \ ++i) if(type[i] == TYPE::LMS) { lms.emplace_back(i); }\r\n            return\
    \ lms;\r\n        }();\r\n        auto fakeArray = inducedSort(str, type, lmsOrder);\r\
    \n\r\n        /* calc true seed */\r\n        auto lmsFakeOrder = [&fakeArray,\
    \ &type]() {\r\n            auto lms = std::list<int>();\r\n            lms.emplace_back(static_cast<int>(type.size())\
    \ - 1);\r\n            for(const auto& i : fakeArray) if(type[i] == TYPE::LMS)\
    \ { lms.emplace_back(i); }\r\n            return lms;\r\n        }();\r\n    \
    \    auto changer = getLmsChanger(str, type, lmsFakeOrder);\r\n        auto& lmsTrueOrder\
    \ = lmsFakeOrder;\r\n        if(changer[*lmsFakeOrder.rbegin()] + 1 < lmsFakeOrder.size())\
    \ {\r\n            /* exist same lms-substring */\r\n            auto str = std::vector<int>();\r\
    \n            auto def = std::vector<int>();\r\n            str.reserve(lmsOrder.size());\r\
    \n            def.reserve(lmsOrder.size());\r\n            for(const auto& c :\
    \ lmsOrder) {\r\n                str.emplace_back(changer[c]);\r\n           \
    \     def.emplace_back(c);\r\n            }\r\n            auto lmsSuffixArray\
    \ = constructSuffixArray(str);\r\n            lmsTrueOrder = std::list<int>{static_cast<int>(type.size())\
    \ - 1};\r\n            for(const auto& c : lmsSuffixArray) {\r\n             \
    \   lmsTrueOrder.emplace_back(def[c]);\r\n            }\r\n        }\r\n\r\n \
    \       /* calc true Suffix Array using true seed */\r\n        auto suffixArray\
    \ = inducedSort(str, type, lmsTrueOrder);\r\n\r\n        return suffixArray;\r\
    \n    }\r\n\r\npublic:\r\n    SuffixArray(const std::string& str) :m_str(str),\
    \ m_suffixArray(constructSuffixArray(toIntVec(str))) {}\r\n\r\n    /**\r\n   \
    \  * \u5F15\u6570\u3068\u3057\u3066\u4E0E\u3048\u3089\u308C\u305Fpattern\u51FA\
    \u73FE\u4F4D\u7F6E\u306E\u533A\u9593\u3092\u8FD4\u3059\r\n     */\r\n    std::pair<int,\
    \ int> findPattern(const std::string& pattern) const {\r\n\r\n        auto find\
    \ = [&](const std::string& ptn) {\r\n            int end = m_suffixArray.size();\r\
    \n            int ptn_sz = ptn.size();\r\n            auto ret = binarySearch(0,\
    \ end, [&](int mid) {\r\n                int st = m_suffixArray[mid];\r\n    \
    \            int sub_sz = end - st;\r\n                for(int k = 0; k < std::min(ptn_sz,\
    \ sub_sz); ++k) {\r\n                    if(ptn[k] < m_str[st + k]) { return true;\
    \ }\r\n                    if(ptn[k] > m_str[st + k]) { return false; }\r\n  \
    \              }\r\n                return ptn_sz <= sub_sz;\r\n            });\r\
    \n            return ret;\r\n        };\r\n        auto patternUpper = [&pattern]()\
    \ {\r\n            auto ptn = pattern;\r\n            ++* ptn.rbegin();\r\n  \
    \          return ptn;\r\n        }();\r\n        auto fl = find(pattern);\r\n\
    \        auto fu = find(patternUpper);\r\n        return {fl,fu};\r\n    }\r\n\
    \r\n    auto getSuffixArray() const {\r\n        return m_suffixArray;\r\n   \
    \ }\r\n\r\n    /* output fot debug */\r\n    void debugOutput() const {\r\n  \
    \      for(const auto& x : m_suffixArray) {\r\n            std::cout << x << \"\
    \ \";\r\n        }std::cout << std::endl;\r\n        auto end = m_str.size();\r\
    \n        for(const auto& x : m_suffixArray) {\r\n            std::cout << m_str.substr(x,\
    \ end) << std::endl;\r\n        }\r\n    }\r\n};\n#line 4 \"Library/String/LCPArray.hpp\"\
    \n\r\n/**\r\n * LCPArray\u3092\u69CB\u7BC9\u3059\u308B\r\n * O(N)\r\n * suffix\
    \ array\u3067\u96A3\u63A5\u3059\u308Bstr\u306E\u6700\u9577\u5171\u901A\u63A5\u982D\
    \u8F9E(LCP:Longest Common Prefix)\u3092\u5F97\u308B\r\n * ex) sa:[aab, ab, abaab,\
    \ b, baab] -> LCPA:[1, 2, 0, 1]\r\n *\r\n * Kasai's algorithm\u3067\u5B9F\u88C5\
    \r\n */\r\nclass LCPArray {\r\n\r\n    const std::vector<int> m_lcpArray;\r\n\
    \    const std::vector<int> m_suffixArray;\r\n\r\n    static std::vector<int>\
    \ constructLcpArray(const std::string& str) {\r\n        auto sz = str.size();\r\
    \n        const auto suffixArray = SuffixArray(str).getSuffixArray();\r\n\r\n\
    \        auto rank = std::vector<int>(sz);\r\n        for(int i = 0; i < sz; ++i)\
    \ { rank[suffixArray[i]] = i; }\r\n\r\n        auto lcpArray = std::vector<int>(sz\
    \ - 1);\r\n        for(int i = 0, h = 0; i < sz; ++i) {\r\n            if(rank[i]\
    \ == 0) { continue; }\r\n            int j = suffixArray[rank[i] - 1];\r\n   \
    \         if(h > 0) { --h; }\r\n            for(; j + h < sz && i + h < sz; ++h)\
    \ {\r\n                if(str[i + h] != str[j + h]) { break; }\r\n           \
    \ }\r\n            lcpArray[rank[i] - 1] = h;\r\n        }\r\n        return lcpArray;\r\
    \n    }\r\n\r\npublic:\r\n    LCPArray(const std::string& str) :\r\n        m_suffixArray(SuffixArray(str).getSuffixArray()),\r\
    \n        m_lcpArray(constructLcpArray(str)) {\r\n    }\r\n\r\n    auto getLCPArray()const\
    \ { return m_lcpArray; }\r\n    auto getSuffixArrayIndexList()const {\r\n    \
    \    std::vector<int> sail(m_suffixArray.size());\r\n        for(unsigned int\
    \ i = 0; i < m_suffixArray.size(); ++i) {\r\n            sail[m_suffixArray[i]]\
    \ = i;\r\n        }\r\n        return sail;\r\n    }\r\n};\n#line 2 \"Library/DataStructure/SegmentTree.hpp\"\
    \n\r\n#line 4 \"Library/DataStructure/SegmentTree.hpp\"\n#include <deque>\r\n\
    #include <utility>\r\n\r\ntemplate<class T>\r\nclass isMonoid {\r\n    template\
    \ <class U>\r\n    static auto check(U x) -> decltype(x.binaryOperation(x), std::true_type{});\r\
    \n    static std::false_type check(...);\r\npublic:\r\n    static bool const value\
    \ = decltype(check(std::declval<T>()))::value;\r\n};\r\n\r\ntemplate<class Monoid,\
    \ std::enable_if_t<isMonoid<Monoid>::value, std::nullptr_t> = nullptr >\r\nclass\
    \ SegmentTree {\r\nprivate:\r\n    const int m_size;\r\n    std::vector<Monoid>\
    \ m_node;\r\n    using S = decltype(Monoid().m_val);\r\n\r\n    int calcSize(int\
    \ n) const { int size = 1; while(size < n) { size <<= 1; }return size; }\r\n\r\
    \n    template<class Lambda>\r\n    auto _update_op(int itr, Monoid&& val, const\
    \ Lambda& op) {\r\n        int i = itr + m_size - 1;\r\n        m_node[i] = op(m_node[i],\
    \ std::forward<decltype(val)>(val));\r\n        while(i) {\r\n            i =\
    \ (i - 1) >> 1;\r\n            m_node[i] = m_node[(i << 1) | 1].binaryOperation(m_node[(i\
    \ + 1) << 1]);\r\n        }\r\n    }\r\n\r\n    auto _query(int _l, int _r) const\
    \ {\r\n        _l = std::max(_l, 0); _r = std::min(_r, m_size - 1);\r\n      \
    \  auto l = _l + m_size;\r\n        int r = _r + m_size;\r\n        auto lm =\
    \ Monoid();\r\n        auto rm = Monoid();\r\n        while(l <= r) {\r\n    \
    \        if(l & 1) { lm = lm.binaryOperation(m_node[l - 1]); ++l; }\r\n      \
    \      if(!(r & 1)) { rm = m_node[r - 1].binaryOperation(rm); --r; }\r\n     \
    \       l >>= 1, r >>= 1;\r\n        }\r\n        return lm.binaryOperation(rm);\r\
    \n    }\r\n\r\n    auto _construct(const std::vector<S>& vec) {\r\n        for(unsigned\
    \ int i = 0; i < vec.size(); ++i) {\r\n            m_node[i + m_size - 1] = Monoid(vec[i]);\r\
    \n        }\r\n        for(int i = m_size - 2; i >= 0; --i) {\r\n            m_node[i]\
    \ = m_node[(i << 1) | 1].binaryOperation(m_node[(i + 1) << 1]);\r\n        }\r\
    \n    }\r\npublic:\r\n    SegmentTree(int n) : m_size(calcSize(n)), m_node((m_size\
    \ << 1) - 1) {}\r\n    SegmentTree(int n, const std::vector<S>& vec) :SegmentTree(n)\
    \ { _construct(vec); }\r\n\r\n    template<class Lambda>\r\n    auto update_op(int\
    \ itr, Monoid&& val, const Lambda& op) { return _update_op(itr, std::forward<Monoid>(val),\
    \ op); }\r\n    auto update(int itr, Monoid&& val) { return update_op(itr, std::forward<Monoid>(val),\
    \ [](const Monoid&, const Monoid& m2) {return m2; }); }\r\n    auto add(int itr,\
    \ Monoid&& val) { return update_op(itr, std::forward<Monoid>(val), [](const Monoid&\
    \ m1, const Monoid& m2) {return Monoid(m1.m_val + m2.m_val); }); }\r\n    auto\
    \ query(int l, int r)const { return _query(l, r).m_val; }\r\n    auto query_all()const\
    \ { return m_node[0].m_val; }\r\n\r\n    auto output()const {\r\n        for(int\
    \ i = 0; i < m_size; ++i) { std::cout << m_node[m_size + i - 1] << \" \"; }\r\n\
    \        std::cout << std::endl;\r\n    }\r\n};\r\n\r\n\r\ntemplate<\r\n    class\
    \ S,   // \u8981\u7D20\u306E\u578B\r\n    S element, // \u5143\r\n    class T\
    \ // lambda\u306FC++20\u3058\u3083\u306A\u3044\u3068\u6E21\u305B\u306A\u304B\u3063\
    \u305F\uFF0E\uFF0E\uFF0E\r\n    // S T(S, S)  // 2\u9805\u6F14\u7B97\u5B50\r\n\
    >\r\nstruct Monoid {\r\n    S m_val;\r\n    Monoid() :m_val(element) {}\r\n  \
    \  Monoid(S val) :m_val(val) {}\r\n    Monoid binaryOperation(const Monoid& m2)const\
    \ { return T()(m_val, m2.m_val); }\r\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Monoid<S, element, T>& m) {\r\n        return os << m.m_val;\r\n \
    \   }\r\n};\r\n#line 7 \"Test/String/LCPArray.test.cpp\"\n\r\nusing ll = long\
    \ long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr char endl = '\\n';\r\
    \nstruct Preprocessing { Preprocessing() { std::cin.tie(0); std::ios::sync_with_stdio(0);\
    \ }; }_Preprocessing;\r\n\r\nstruct F { auto operator()(int a, int b)const { return\
    \ std::min(a, b); }; };\r\nusing M = Monoid<int, static_cast<int>(1e9), F>;\r\n\
    \r\nconstexpr ll MOD = 1000000007;\r\n\r\nsigned main() {\r\n    std::string s;\r\
    \n    cin >> s;\r\n\r\n    ll size = s.size();\r\n    auto lcparray = LCPArray(s);\r\
    \n    auto segtree = SegmentTree<M>(size, lcparray.getLCPArray());\r\n    auto\
    \ sai = lcparray.getSuffixArrayIndexList();\r\n\r\n    ll half = (size >> 1);\r\
    \n    std::vector<ll> dp(half + 1);\r\n    dp[0] = 1;\r\n    for(int l = 0; l\
    \ < half; ++l) {\r\n        for(int r = l; r < half; ++r) {\r\n\r\n          \
    \  auto idx1 = sai[l];\r\n            auto idx2 = sai[size - r - 1];\r\n     \
    \       if(idx2 < idx1) { std::swap(idx1, idx2); }\r\n            auto lcp = segtree.query(idx1,\
    \ idx2 - 1);\r\n\r\n            int len = r - l + 1;\r\n            if(lcp >=\
    \ len) {\r\n                dp[r + 1] += dp[l];\r\n                if(dp[r + 1]\
    \ >= MOD) { dp[r + 1] -= MOD; }\r\n            }\r\n        }\r\n    }\r\n\r\n\
    \    ll ans = 0;\r\n    for(const auto& x : dp) { ans += x; if(ans >= MOD) { ans\
    \ -= MOD; } }\r\n    cout << ans;\r\n}\r\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/599\"\r\n\r\n#include\
    \ <iostream>\r\n\r\n#include \"./../../Library/String/LCPArray.hpp\"\r\n#include\
    \ \"./../../Library/DataStructure/SegmentTree.hpp\"\r\n\r\nusing ll = long long;\r\
    \nusing std::cout;\r\nusing std::cin;\r\nconstexpr char endl = '\\n';\r\nstruct\
    \ Preprocessing { Preprocessing() { std::cin.tie(0); std::ios::sync_with_stdio(0);\
    \ }; }_Preprocessing;\r\n\r\nstruct F { auto operator()(int a, int b)const { return\
    \ std::min(a, b); }; };\r\nusing M = Monoid<int, static_cast<int>(1e9), F>;\r\n\
    \r\nconstexpr ll MOD = 1000000007;\r\n\r\nsigned main() {\r\n    std::string s;\r\
    \n    cin >> s;\r\n\r\n    ll size = s.size();\r\n    auto lcparray = LCPArray(s);\r\
    \n    auto segtree = SegmentTree<M>(size, lcparray.getLCPArray());\r\n    auto\
    \ sai = lcparray.getSuffixArrayIndexList();\r\n\r\n    ll half = (size >> 1);\r\
    \n    std::vector<ll> dp(half + 1);\r\n    dp[0] = 1;\r\n    for(int l = 0; l\
    \ < half; ++l) {\r\n        for(int r = l; r < half; ++r) {\r\n\r\n          \
    \  auto idx1 = sai[l];\r\n            auto idx2 = sai[size - r - 1];\r\n     \
    \       if(idx2 < idx1) { std::swap(idx1, idx2); }\r\n            auto lcp = segtree.query(idx1,\
    \ idx2 - 1);\r\n\r\n            int len = r - l + 1;\r\n            if(lcp >=\
    \ len) {\r\n                dp[r + 1] += dp[l];\r\n                if(dp[r + 1]\
    \ >= MOD) { dp[r + 1] -= MOD; }\r\n            }\r\n        }\r\n    }\r\n\r\n\
    \    ll ans = 0;\r\n    for(const auto& x : dp) { ans += x; if(ans >= MOD) { ans\
    \ -= MOD; } }\r\n    cout << ans;\r\n}\r\n"
  dependsOn:
  - Library/String/LCPArray.hpp
  - Library/String/SuffixArray.hpp
  - Library/Algorithms/BinarySearch.hpp
  - Library/DataStructure/SegmentTree.hpp
  isVerificationFile: true
  path: Test/String/LCPArray.test.cpp
  requiredBy: []
  timestamp: '2024-03-30 16:35:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/String/LCPArray.test.cpp
layout: document
redirect_from:
- /verify/Test/String/LCPArray.test.cpp
- /verify/Test/String/LCPArray.test.cpp.html
title: Test/String/LCPArray.test.cpp
---
