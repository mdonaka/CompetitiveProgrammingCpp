---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Algorithms/BinarySearch.hpp
    title: Library/Algorithms/BinarySearch.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Library/String/LCPArray.hpp
    title: Library/String/LCPArray.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/String/LCPArray.test.cpp
    title: Test/String/LCPArray.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/String/SuffixArray.test.cpp
    title: Test/String/SuffixArray.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Algorithms/BinarySearch.hpp\"\n#include <numeric>\r\
    \n#include <ranges>\r\n\r\ntemplate <class Lambda>\r\nauto binarySearch(double\
    \ ok, double ng, int rep, const Lambda& is_ok) {\r\n    for([[maybe_unused]] auto\
    \ _ : std::views::iota(0, rep)) {\r\n        double mid = (ok + ng) / 2.0;\r\n\
    \        (is_ok(mid) ? ok : ng) = mid;\r\n    }\r\n    return ok;\r\n}\r\n\r\n\
    template <class Lambda>\r\nauto binarySearch(long long ok, long long ng, const\
    \ Lambda& is_ok) {\r\n    while(std::abs(ok - ng) > 1) {\r\n        long long\
    \ mid = (ok + ng) >> 1;\r\n        (is_ok(mid) ? ok : ng) = mid;\r\n    }\r\n\
    \    return ok;\r\n}\r\n#line 3 \"Library/String/SuffixArray.hpp\"\n\r\n#include\
    \ <iostream>\r\n#include <vector>\r\n#include <list>\r\n#include <string>\r\n\
    #include <set>\r\n#include <unordered_map>\r\n/**\r\n * SuffixArray\u3092\u69CB\
    \u7BC9\u3059\u308B\r\n * O(N)\r\n * \u6587\u5B57\u5217\u306E\u5168\u3066\u306E\
    suffix\u3092\u30BD\u30FC\u30C8\u3057\u305F\u914D\u5217\u304C\u5F97\u3089\u308C\
    \u308B\r\n * ex) abadc -> [0, 2, 1, 4, 3]([abadc, adc, badc, c, dc])\r\n *\r\n\
    \ * SA-IS(Suffix Array - Induced Sort)\u3067\u5B9F\u88C5\r\n */\r\nclass SuffixArray\
    \ {\r\n    enum class TYPE {\r\n        L, S, LMS\r\n    };\r\n\r\n    const std::string\
    \ m_str;\r\n    const std::vector<int> m_suffixArray;\r\n\r\n    /* string to\
    \ vector<int> */\r\n    static std::vector<int> toIntVec(const std::string& str)\
    \ {\r\n        std::vector<int> vec;\r\n        vec.reserve(str.size() + 1);\r\
    \n        for(const auto& c : str) {\r\n            vec.emplace_back(c - '0' +\
    \ 1);\r\n        }\r\n        vec.emplace_back(0);\r\n        return vec;\r\n\
    \    }\r\n\r\n    /* classify { L, S, LMS } */\r\n    static std::vector<TYPE>\
    \ classifying(const std::vector<int>& str) {\r\n        auto sz = str.size();\r\
    \n        auto typeArray = std::vector<TYPE>(sz);\r\n        typeArray[sz - 1]\
    \ = TYPE::S;\r\n        for(int i = sz - 2; i >= 0; --i) {\r\n            if(str[i]\
    \ == str[i + 1]) {\r\n                typeArray[i] = typeArray[i + 1];\r\n   \
    \             continue;\r\n            }\r\n            typeArray[i] = (str[i]\
    \ < str[i + 1]) ? TYPE::S : TYPE::L;\r\n        }\r\n        for(int i = 1; i\
    \ < sz; ++i) {\r\n            if(typeArray[i - 1] == TYPE::L && typeArray[i] ==\
    \ TYPE::S) {\r\n                typeArray[i] = TYPE::LMS;\r\n            }\r\n\
    \        }\r\n        return typeArray;\r\n    }\r\n\r\n    /* induced sort */\r\
    \n    static std::vector<int> inducedSort(const std::vector<int>& str, const std::vector<TYPE>&\
    \ type, std::list<int>& lmsList) {\r\n        auto sz = str.size();\r\n      \
    \  auto nList = std::set<int>();\r\n        for(const auto& c : str) { nList.emplace(c);\
    \ }\r\n\r\n        auto befCheck = [&](int k, auto& addList, bool rev) {\r\n \
    \           if(k == 0) { return; }\r\n            if(!rev && type[k - 1] == TYPE::L)\
    \ {\r\n                addList[str[k - 1]].emplace_back(k - 1);\r\n          \
    \  }\r\n            if(rev && type[k - 1] != TYPE::L) {\r\n                addList[str[k\
    \ - 1]].emplace_front(k - 1);\r\n            }\r\n        };\r\n\r\n        auto\
    \ checkAndUpdate = [&](int n, auto& checkList, auto& addList, bool rev) {\r\n\
    \            auto& lst = checkList[n];\r\n            if(rev) {\r\n          \
    \      for(auto itr = lst.rbegin(); itr != lst.rend(); ++itr) { befCheck(*itr,\
    \ addList, rev); }\r\n            } else {\r\n                for(const auto&\
    \ k : lst) { befCheck(k, addList, rev); }\r\n            }\r\n        };\r\n\r\
    \n        /* set LMS */\r\n        auto tailList = std::unordered_map<int, std::list<int>>();\r\
    \n        for(const auto& i : lmsList) { tailList[str[i]].emplace_back(i); }\r\
    \n\r\n        /* set L-type */\r\n        auto headList = std::unordered_map<int,\
    \ std::list<int>>();\r\n        for(const auto& n : nList) {\r\n            checkAndUpdate(n,\
    \ headList, headList, false);\r\n            checkAndUpdate(n, tailList, headList,\
    \ false);\r\n        }\r\n\r\n        /* set S-type*/\r\n        tailList = std::unordered_map<int,\
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
    \n            int ptn_sz = ptn.size();\r\n            auto ret = binarySearch(end,\
    \ -1, [&](int mid) {\r\n                int st = m_suffixArray[mid];\r\n     \
    \           int sub_sz = end - st;\r\n                for(int k = 0; k < std::min(ptn_sz,\
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
    \ end) << std::endl;\r\n        }\r\n    }\r\n};\n"
  code: "#pragma once\r\n#include \"./../Algorithms/BinarySearch.hpp\"\r\n\r\n#include\
    \ <iostream>\r\n#include <vector>\r\n#include <list>\r\n#include <string>\r\n\
    #include <set>\r\n#include <unordered_map>\r\n/**\r\n * SuffixArray\u3092\u69CB\
    \u7BC9\u3059\u308B\r\n * O(N)\r\n * \u6587\u5B57\u5217\u306E\u5168\u3066\u306E\
    suffix\u3092\u30BD\u30FC\u30C8\u3057\u305F\u914D\u5217\u304C\u5F97\u3089\u308C\
    \u308B\r\n * ex) abadc -> [0, 2, 1, 4, 3]([abadc, adc, badc, c, dc])\r\n *\r\n\
    \ * SA-IS(Suffix Array - Induced Sort)\u3067\u5B9F\u88C5\r\n */\r\nclass SuffixArray\
    \ {\r\n    enum class TYPE {\r\n        L, S, LMS\r\n    };\r\n\r\n    const std::string\
    \ m_str;\r\n    const std::vector<int> m_suffixArray;\r\n\r\n    /* string to\
    \ vector<int> */\r\n    static std::vector<int> toIntVec(const std::string& str)\
    \ {\r\n        std::vector<int> vec;\r\n        vec.reserve(str.size() + 1);\r\
    \n        for(const auto& c : str) {\r\n            vec.emplace_back(c - '0' +\
    \ 1);\r\n        }\r\n        vec.emplace_back(0);\r\n        return vec;\r\n\
    \    }\r\n\r\n    /* classify { L, S, LMS } */\r\n    static std::vector<TYPE>\
    \ classifying(const std::vector<int>& str) {\r\n        auto sz = str.size();\r\
    \n        auto typeArray = std::vector<TYPE>(sz);\r\n        typeArray[sz - 1]\
    \ = TYPE::S;\r\n        for(int i = sz - 2; i >= 0; --i) {\r\n            if(str[i]\
    \ == str[i + 1]) {\r\n                typeArray[i] = typeArray[i + 1];\r\n   \
    \             continue;\r\n            }\r\n            typeArray[i] = (str[i]\
    \ < str[i + 1]) ? TYPE::S : TYPE::L;\r\n        }\r\n        for(int i = 1; i\
    \ < sz; ++i) {\r\n            if(typeArray[i - 1] == TYPE::L && typeArray[i] ==\
    \ TYPE::S) {\r\n                typeArray[i] = TYPE::LMS;\r\n            }\r\n\
    \        }\r\n        return typeArray;\r\n    }\r\n\r\n    /* induced sort */\r\
    \n    static std::vector<int> inducedSort(const std::vector<int>& str, const std::vector<TYPE>&\
    \ type, std::list<int>& lmsList) {\r\n        auto sz = str.size();\r\n      \
    \  auto nList = std::set<int>();\r\n        for(const auto& c : str) { nList.emplace(c);\
    \ }\r\n\r\n        auto befCheck = [&](int k, auto& addList, bool rev) {\r\n \
    \           if(k == 0) { return; }\r\n            if(!rev && type[k - 1] == TYPE::L)\
    \ {\r\n                addList[str[k - 1]].emplace_back(k - 1);\r\n          \
    \  }\r\n            if(rev && type[k - 1] != TYPE::L) {\r\n                addList[str[k\
    \ - 1]].emplace_front(k - 1);\r\n            }\r\n        };\r\n\r\n        auto\
    \ checkAndUpdate = [&](int n, auto& checkList, auto& addList, bool rev) {\r\n\
    \            auto& lst = checkList[n];\r\n            if(rev) {\r\n          \
    \      for(auto itr = lst.rbegin(); itr != lst.rend(); ++itr) { befCheck(*itr,\
    \ addList, rev); }\r\n            } else {\r\n                for(const auto&\
    \ k : lst) { befCheck(k, addList, rev); }\r\n            }\r\n        };\r\n\r\
    \n        /* set LMS */\r\n        auto tailList = std::unordered_map<int, std::list<int>>();\r\
    \n        for(const auto& i : lmsList) { tailList[str[i]].emplace_back(i); }\r\
    \n\r\n        /* set L-type */\r\n        auto headList = std::unordered_map<int,\
    \ std::list<int>>();\r\n        for(const auto& n : nList) {\r\n            checkAndUpdate(n,\
    \ headList, headList, false);\r\n            checkAndUpdate(n, tailList, headList,\
    \ false);\r\n        }\r\n\r\n        /* set S-type*/\r\n        tailList = std::unordered_map<int,\
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
    \n            int ptn_sz = ptn.size();\r\n            auto ret = binarySearch(end,\
    \ -1, [&](int mid) {\r\n                int st = m_suffixArray[mid];\r\n     \
    \           int sub_sz = end - st;\r\n                for(int k = 0; k < std::min(ptn_sz,\
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
    \ end) << std::endl;\r\n        }\r\n    }\r\n};"
  dependsOn:
  - Library/Algorithms/BinarySearch.hpp
  isVerificationFile: false
  path: Library/String/SuffixArray.hpp
  requiredBy:
  - Library/String/LCPArray.hpp
  timestamp: '2024-07-19 01:34:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/String/SuffixArray.test.cpp
  - Test/String/LCPArray.test.cpp
documentation_of: Library/String/SuffixArray.hpp
layout: document
redirect_from:
- /library/Library/String/SuffixArray.hpp
- /library/Library/String/SuffixArray.hpp.html
title: Library/String/SuffixArray.hpp
---
