---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Library/String/SuffixArray.cpp\"\n/**\r\n * SuffixArray\u3092\
    \u69CB\u7BC9\u3059\u308B\r\n * O(N)\r\n * \u6587\u5B57\u5217\u306E\u5168\u3066\
    \u306Esuffix\u3092\u30BD\u30FC\u30C8\u3057\u305F\u914D\u5217\u304C\u5F97\u3089\
    \u308C\u308B\r\n * ex) abadc -> [0, 2, 1, 4, 3]([abadc, adc, badc, c, dc])\r\n\
    \ *\r\n * SA-IS(Suffix Array - Induced Sort)\u3067\u5B9F\u88C5\r\n */\r\nclass\
    \ SuffixArray {\r\n\tenum class TYPE {\r\n\t\tL, S, LMS\r\n\t};\r\n\r\n\tconst\
    \ std::string m_str;\r\n\tconst std::vector<int> m_suffixArray;\r\n\r\n\t/* string\
    \ to vector<int> */\r\n\tstatic std::vector<int> toIntVec(const std::string& str)\
    \ {\r\n\t\tstd::vector<int> vec;\r\n\t\tvec.reserve(str.size() + 1);\r\n\t\tfor\
    \ (const auto& c : str) {\r\n\t\t\tvec.emplace_back(c - '0' + 1);\r\n\t\t}\r\n\
    \t\tvec.emplace_back(0);\r\n\t\treturn vec;\r\n\t}\r\n\r\n\t/* classify { L, S,\
    \ LMS } */\r\n\tstatic std::vector<TYPE> classifying(const std::vector<int>& str)\
    \ {\r\n\t\tauto sz = str.size();\r\n\t\tauto typeArray = std::vector<TYPE>(sz);\r\
    \n\t\ttypeArray[sz - 1] = TYPE::S;\r\n\t\tfor (int i = sz - 2; i >= 0; --i) {\r\
    \n\t\t\tif (str[i] == str[i + 1]) {\r\n\t\t\t\ttypeArray[i] = typeArray[i + 1];\r\
    \n\t\t\t\tcontinue;\r\n\t\t\t}\r\n\t\t\ttypeArray[i] = (str[i] < str[i + 1]) ?\
    \ TYPE::S : TYPE::L;\r\n\t\t}\r\n\t\tfor (int i = 1; i < sz; ++i) {\r\n\t\t\t\
    if (typeArray[i - 1] == TYPE::L && typeArray[i] == TYPE::S) {\r\n\t\t\t\ttypeArray[i]\
    \ = TYPE::LMS;\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn typeArray;\r\n\t}\r\n\r\n\t/*\
    \ induced sort */\r\n\tstatic std::vector<int> inducedSort(const std::vector<int>&\
    \ str, const std::vector<TYPE>& type, std::list<int>& lmsList) {\r\n\t\tauto sz\
    \ = str.size();\r\n\t\tauto nList = std::set<int>();\r\n\t\tfor (const auto& c\
    \ : str) { nList.emplace(c); }\r\n\r\n\t\tauto befCheck = [&](int k, auto& addList,\
    \ bool rev) {\r\n\t\t\tif (k == 0) { return; }\r\n\t\t\tif (!rev && type[k - 1]\
    \ == TYPE::L) {\r\n\t\t\t\taddList[str[k - 1]].emplace_back(k - 1);\r\n\t\t\t\
    }\r\n\t\t\tif (rev && type[k - 1] != TYPE::L) {\r\n\t\t\t\taddList[str[k - 1]].emplace_front(k\
    \ - 1);\r\n\t\t\t}\r\n\t\t};\r\n\r\n\t\tauto checkAndUpdate = [&](int n, auto&\
    \ checkList, auto& addList, bool rev) {\r\n\t\t\tauto& lst = checkList[n];\r\n\
    \t\t\tif (rev) {\r\n\t\t\t\tfor (auto itr = lst.rbegin(); itr != lst.rend(); ++itr)\
    \ { befCheck(*itr, addList, rev); }\r\n\t\t\t} else {\r\n\t\t\t\tfor (const auto&\
    \ k : lst) { befCheck(k, addList, rev); }\r\n\t\t\t}\r\n\t\t};\r\n\r\n\t\t/* set\
    \ LMS */\r\n\t\tauto tailList = std::unordered_map<int, std::list<int>>();\r\n\
    \t\tfor (const auto& i : lmsList) { tailList[str[i]].emplace_back(i); }\r\n\r\n\
    \t\t/* set L-type */\r\n\t\tauto headList = std::unordered_map<int, std::list<int>>();\r\
    \n\t\tfor (const auto& n : nList) {\r\n\t\t\tcheckAndUpdate(n, headList, headList,\
    \ false);\r\n\t\t\tcheckAndUpdate(n, tailList, headList, false);\r\n\t\t}\r\n\r\
    \n\t\t/* set S-type*/\r\n\t\ttailList = std::unordered_map<int, std::list<int>>();\r\
    \n\t\tfor (auto itr_n = nList.rbegin(); itr_n != nList.rend(); ++itr_n) {\r\n\t\
    \t\tauto n = *itr_n;\r\n\t\t\tcheckAndUpdate(n, tailList, tailList, true);\r\n\
    \t\t\tcheckAndUpdate(n, headList, tailList, true);\r\n\t\t}\r\n\r\n\t\t/* merge\
    \ */\r\n\t\tauto suffixArray = std::vector<int>();\r\n\t\tsuffixArray.reserve(sz);\r\
    \n\t\tfor (const auto& n : nList) {\r\n\t\t\tfor (const auto& c : headList[n])\
    \ { suffixArray.emplace_back(c); }\r\n\t\t\tfor (const auto& c : tailList[n])\
    \ { suffixArray.emplace_back(c); }\r\n\t\t}\r\n\r\n\t\treturn suffixArray;\r\n\
    \t}\r\n\r\n\t/* order lms -> sorted lms */\r\n\tstatic std::unordered_map<int,\
    \ int> getLmsChanger(const std::vector<int>& str, const std::vector<TYPE>& type,\
    \ const std::list<int>& lms) {\r\n\t\tif (lms.size() == 1) { return std::unordered_map<int,\
    \ int>{ { str.size() - 1, 0 }}; }\r\n\t\tstd::unordered_map<int, int> changer{{static_cast<int>(str.size())\
    \ - 1,0},{*++lms.begin(),1}};\r\n\t\tint num = 1;\r\n\t\tfor (auto itr = ++lms.begin();\
    \ itr != (--lms.end());) {\r\n\t\t\tauto f1 = *itr;\r\n\t\t\tauto f2 = *(++itr);\r\
    \n\r\n\t\t\tbool isSame = false;\r\n\t\t\tfor (int i = 0;; ++i) {\r\n\t\t\t\t\
    if (str[f1 + i] != str[f2 + i]) { break; }\r\n\t\t\t\tauto b1 = (type[f1 + i]\
    \ == TYPE::LMS);\r\n\t\t\t\tauto b2 = (type[f2 + i] == TYPE::LMS);\r\n\t\t\t\t\
    if (b1 | b2 && i > 0) {\r\n\t\t\t\t\tif (b1 & b2) { isSame = true; break; }\r\n\
    \t\t\t\t\tbreak;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tif (!isSame) { ++num; }\r\n\t\
    \t\tchanger.emplace(f2, num);\r\n\t\t}\r\n\t\treturn changer;\r\n\t}\r\n\r\n\t\
    /* calc Suffix Array*/\r\n\tstatic std::vector<int> constructSuffixArray(const\
    \ std::vector<int>& str) {\r\n\t\tauto type = classifying(str);\r\n\r\n\t\t/*\
    \ calc fake Suffix Array using order seed*/\r\n\t\tauto lmsOrder = [&type]() {\r\
    \n\t\t\tauto lms = std::list<int>();\r\n\t\t\tfor (int i = 0; i < type.size();\
    \ ++i) if (type[i] == TYPE::LMS) { lms.emplace_back(i); }\r\n\t\t\treturn lms;\r\
    \n\t\t}();\r\n\t\tauto fakeArray = inducedSort(str, type, lmsOrder);\r\n\r\n\t\
    \t/* calc true seed */\r\n\t\tauto lmsFakeOrder = [&fakeArray, &type]() {\r\n\t\
    \t\tauto lms = std::list<int>();\r\n\t\t\tlms.emplace_back(static_cast<int>(type.size())\
    \ - 1);\r\n\t\t\tfor (const auto& i : fakeArray) if (type[i] == TYPE::LMS) { lms.emplace_back(i);\
    \ }\r\n\t\t\treturn lms;\r\n\t\t}();\r\n\t\tauto changer = getLmsChanger(str,\
    \ type, lmsFakeOrder);\r\n\t\tauto& lmsTrueOrder = lmsFakeOrder;\r\n\t\tif (changer[*lmsFakeOrder.rbegin()]\
    \ + 1 < lmsFakeOrder.size()) {\r\n\t\t\t/* exist same lms-substring */\r\n\t\t\
    \tauto str = std::vector<int>();\r\n\t\t\tauto def = std::vector<int>();\r\n\t\
    \t\tstr.reserve(lmsOrder.size());\r\n\t\t\tdef.reserve(lmsOrder.size());\r\n\t\
    \t\tfor (const auto& c : lmsOrder) {\r\n\t\t\t\tstr.emplace_back(changer[c]);\r\
    \n\t\t\t\tdef.emplace_back(c);\r\n\t\t\t}\r\n\t\t\tauto lmsSuffixArray = constructSuffixArray(str);\r\
    \n\t\t\tlmsTrueOrder = std::list<int>{static_cast<int>(type.size()) - 1};\r\n\t\
    \t\tfor (const auto& c : lmsSuffixArray) {\r\n\t\t\t\tlmsTrueOrder.emplace_back(def[c]);\r\
    \n\t\t\t}\r\n\t\t}\r\n\r\n\t\t/* calc true Suffix Array using true seed */\r\n\
    \t\tauto suffixArray = inducedSort(str, type, lmsTrueOrder);\r\n\r\n\t\treturn\
    \ suffixArray;\r\n\t}\r\n\r\npublic:\r\n\tSuffixArray(const std::string& str)\
    \ :m_str(str), m_suffixArray(constructSuffixArray(toIntVec(str))) {}\r\n\r\n\t\
    /**\r\n\t * \u5F15\u6570\u3068\u3057\u3066\u4E0E\u3048\u3089\u308C\u305Fpattern\u306E\
    \u51FA\u73FE\u4F4D\u7F6E\u30EA\u30B9\u30C8\u3092\u8FD4\u3059\r\n\t */\r\n\tstd::list<int>\
    \ findPattern(const std::string& pattern) const {\r\n\r\n\t\tauto find = [&](const\
    \ std::string& ptn) {\r\n\t\t\tint end = m_suffixArray.size();\r\n\t\t\tint ok\
    \ = end;\r\n\t\t\tint ng = -1;\r\n\t\t\twhile (ok - ng > 1) {\r\n\t\t\t\tint mid\
    \ = (ok + ng) / 2;\r\n\t\t\t\tauto sub = m_str.substr(m_suffixArray[mid], end);\r\
    \n\t\t\t\tint isOk = (ptn <= sub);\r\n\t\t\t\tif (isOk) { ok = mid; } else { ng\
    \ = mid; }\r\n\t\t\t}\r\n\t\t\treturn ok;\r\n\t\t};\r\n\t\tauto patternUpper =\
    \ [&pattern]() {\r\n\t\t\tauto ptn = pattern;\r\n\t\t\t++* ptn.rbegin();\r\n\t\
    \t\treturn ptn;\r\n\t\t}();\r\n\t\tauto fl = find(pattern);\r\n\t\tauto fu = find(patternUpper);\r\
    \n\t\tstd::list<int> lst;\r\n\t\tfor (int i = fl; i < fu; ++i) {\r\n\t\t\tlst.emplace_back(m_suffixArray[i]);\r\
    \n\t\t}\r\n\t\treturn lst;\r\n\t}\r\n\r\n\tauto getSuffixArray() const {\r\n\t\
    \treturn m_suffixArray;\r\n\t}\r\n\r\n\t/* output fot debug */\r\n\tvoid debugOutput()\
    \ const {\r\n\t\tdump(m_suffixArray);\r\n\t\tauto end = m_str.size();\r\n\t\t\
    REPC(x, m_suffixArray) {\r\n\t\t\tcout << m_str.substr(x, end) << endl;\r\n\t\t\
    }\r\n\t}\r\n};\n"
  code: "/**\r\n * SuffixArray\u3092\u69CB\u7BC9\u3059\u308B\r\n * O(N)\r\n * \u6587\
    \u5B57\u5217\u306E\u5168\u3066\u306Esuffix\u3092\u30BD\u30FC\u30C8\u3057\u305F\
    \u914D\u5217\u304C\u5F97\u3089\u308C\u308B\r\n * ex) abadc -> [0, 2, 1, 4, 3]([abadc,\
    \ adc, badc, c, dc])\r\n *\r\n * SA-IS(Suffix Array - Induced Sort)\u3067\u5B9F\
    \u88C5\r\n */\r\nclass SuffixArray {\r\n\tenum class TYPE {\r\n\t\tL, S, LMS\r\
    \n\t};\r\n\r\n\tconst std::string m_str;\r\n\tconst std::vector<int> m_suffixArray;\r\
    \n\r\n\t/* string to vector<int> */\r\n\tstatic std::vector<int> toIntVec(const\
    \ std::string& str) {\r\n\t\tstd::vector<int> vec;\r\n\t\tvec.reserve(str.size()\
    \ + 1);\r\n\t\tfor (const auto& c : str) {\r\n\t\t\tvec.emplace_back(c - '0' +\
    \ 1);\r\n\t\t}\r\n\t\tvec.emplace_back(0);\r\n\t\treturn vec;\r\n\t}\r\n\r\n\t\
    /* classify { L, S, LMS } */\r\n\tstatic std::vector<TYPE> classifying(const std::vector<int>&\
    \ str) {\r\n\t\tauto sz = str.size();\r\n\t\tauto typeArray = std::vector<TYPE>(sz);\r\
    \n\t\ttypeArray[sz - 1] = TYPE::S;\r\n\t\tfor (int i = sz - 2; i >= 0; --i) {\r\
    \n\t\t\tif (str[i] == str[i + 1]) {\r\n\t\t\t\ttypeArray[i] = typeArray[i + 1];\r\
    \n\t\t\t\tcontinue;\r\n\t\t\t}\r\n\t\t\ttypeArray[i] = (str[i] < str[i + 1]) ?\
    \ TYPE::S : TYPE::L;\r\n\t\t}\r\n\t\tfor (int i = 1; i < sz; ++i) {\r\n\t\t\t\
    if (typeArray[i - 1] == TYPE::L && typeArray[i] == TYPE::S) {\r\n\t\t\t\ttypeArray[i]\
    \ = TYPE::LMS;\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn typeArray;\r\n\t}\r\n\r\n\t/*\
    \ induced sort */\r\n\tstatic std::vector<int> inducedSort(const std::vector<int>&\
    \ str, const std::vector<TYPE>& type, std::list<int>& lmsList) {\r\n\t\tauto sz\
    \ = str.size();\r\n\t\tauto nList = std::set<int>();\r\n\t\tfor (const auto& c\
    \ : str) { nList.emplace(c); }\r\n\r\n\t\tauto befCheck = [&](int k, auto& addList,\
    \ bool rev) {\r\n\t\t\tif (k == 0) { return; }\r\n\t\t\tif (!rev && type[k - 1]\
    \ == TYPE::L) {\r\n\t\t\t\taddList[str[k - 1]].emplace_back(k - 1);\r\n\t\t\t\
    }\r\n\t\t\tif (rev && type[k - 1] != TYPE::L) {\r\n\t\t\t\taddList[str[k - 1]].emplace_front(k\
    \ - 1);\r\n\t\t\t}\r\n\t\t};\r\n\r\n\t\tauto checkAndUpdate = [&](int n, auto&\
    \ checkList, auto& addList, bool rev) {\r\n\t\t\tauto& lst = checkList[n];\r\n\
    \t\t\tif (rev) {\r\n\t\t\t\tfor (auto itr = lst.rbegin(); itr != lst.rend(); ++itr)\
    \ { befCheck(*itr, addList, rev); }\r\n\t\t\t} else {\r\n\t\t\t\tfor (const auto&\
    \ k : lst) { befCheck(k, addList, rev); }\r\n\t\t\t}\r\n\t\t};\r\n\r\n\t\t/* set\
    \ LMS */\r\n\t\tauto tailList = std::unordered_map<int, std::list<int>>();\r\n\
    \t\tfor (const auto& i : lmsList) { tailList[str[i]].emplace_back(i); }\r\n\r\n\
    \t\t/* set L-type */\r\n\t\tauto headList = std::unordered_map<int, std::list<int>>();\r\
    \n\t\tfor (const auto& n : nList) {\r\n\t\t\tcheckAndUpdate(n, headList, headList,\
    \ false);\r\n\t\t\tcheckAndUpdate(n, tailList, headList, false);\r\n\t\t}\r\n\r\
    \n\t\t/* set S-type*/\r\n\t\ttailList = std::unordered_map<int, std::list<int>>();\r\
    \n\t\tfor (auto itr_n = nList.rbegin(); itr_n != nList.rend(); ++itr_n) {\r\n\t\
    \t\tauto n = *itr_n;\r\n\t\t\tcheckAndUpdate(n, tailList, tailList, true);\r\n\
    \t\t\tcheckAndUpdate(n, headList, tailList, true);\r\n\t\t}\r\n\r\n\t\t/* merge\
    \ */\r\n\t\tauto suffixArray = std::vector<int>();\r\n\t\tsuffixArray.reserve(sz);\r\
    \n\t\tfor (const auto& n : nList) {\r\n\t\t\tfor (const auto& c : headList[n])\
    \ { suffixArray.emplace_back(c); }\r\n\t\t\tfor (const auto& c : tailList[n])\
    \ { suffixArray.emplace_back(c); }\r\n\t\t}\r\n\r\n\t\treturn suffixArray;\r\n\
    \t}\r\n\r\n\t/* order lms -> sorted lms */\r\n\tstatic std::unordered_map<int,\
    \ int> getLmsChanger(const std::vector<int>& str, const std::vector<TYPE>& type,\
    \ const std::list<int>& lms) {\r\n\t\tif (lms.size() == 1) { return std::unordered_map<int,\
    \ int>{ { str.size() - 1, 0 }}; }\r\n\t\tstd::unordered_map<int, int> changer{{static_cast<int>(str.size())\
    \ - 1,0},{*++lms.begin(),1}};\r\n\t\tint num = 1;\r\n\t\tfor (auto itr = ++lms.begin();\
    \ itr != (--lms.end());) {\r\n\t\t\tauto f1 = *itr;\r\n\t\t\tauto f2 = *(++itr);\r\
    \n\r\n\t\t\tbool isSame = false;\r\n\t\t\tfor (int i = 0;; ++i) {\r\n\t\t\t\t\
    if (str[f1 + i] != str[f2 + i]) { break; }\r\n\t\t\t\tauto b1 = (type[f1 + i]\
    \ == TYPE::LMS);\r\n\t\t\t\tauto b2 = (type[f2 + i] == TYPE::LMS);\r\n\t\t\t\t\
    if (b1 | b2 && i > 0) {\r\n\t\t\t\t\tif (b1 & b2) { isSame = true; break; }\r\n\
    \t\t\t\t\tbreak;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tif (!isSame) { ++num; }\r\n\t\
    \t\tchanger.emplace(f2, num);\r\n\t\t}\r\n\t\treturn changer;\r\n\t}\r\n\r\n\t\
    /* calc Suffix Array*/\r\n\tstatic std::vector<int> constructSuffixArray(const\
    \ std::vector<int>& str) {\r\n\t\tauto type = classifying(str);\r\n\r\n\t\t/*\
    \ calc fake Suffix Array using order seed*/\r\n\t\tauto lmsOrder = [&type]() {\r\
    \n\t\t\tauto lms = std::list<int>();\r\n\t\t\tfor (int i = 0; i < type.size();\
    \ ++i) if (type[i] == TYPE::LMS) { lms.emplace_back(i); }\r\n\t\t\treturn lms;\r\
    \n\t\t}();\r\n\t\tauto fakeArray = inducedSort(str, type, lmsOrder);\r\n\r\n\t\
    \t/* calc true seed */\r\n\t\tauto lmsFakeOrder = [&fakeArray, &type]() {\r\n\t\
    \t\tauto lms = std::list<int>();\r\n\t\t\tlms.emplace_back(static_cast<int>(type.size())\
    \ - 1);\r\n\t\t\tfor (const auto& i : fakeArray) if (type[i] == TYPE::LMS) { lms.emplace_back(i);\
    \ }\r\n\t\t\treturn lms;\r\n\t\t}();\r\n\t\tauto changer = getLmsChanger(str,\
    \ type, lmsFakeOrder);\r\n\t\tauto& lmsTrueOrder = lmsFakeOrder;\r\n\t\tif (changer[*lmsFakeOrder.rbegin()]\
    \ + 1 < lmsFakeOrder.size()) {\r\n\t\t\t/* exist same lms-substring */\r\n\t\t\
    \tauto str = std::vector<int>();\r\n\t\t\tauto def = std::vector<int>();\r\n\t\
    \t\tstr.reserve(lmsOrder.size());\r\n\t\t\tdef.reserve(lmsOrder.size());\r\n\t\
    \t\tfor (const auto& c : lmsOrder) {\r\n\t\t\t\tstr.emplace_back(changer[c]);\r\
    \n\t\t\t\tdef.emplace_back(c);\r\n\t\t\t}\r\n\t\t\tauto lmsSuffixArray = constructSuffixArray(str);\r\
    \n\t\t\tlmsTrueOrder = std::list<int>{static_cast<int>(type.size()) - 1};\r\n\t\
    \t\tfor (const auto& c : lmsSuffixArray) {\r\n\t\t\t\tlmsTrueOrder.emplace_back(def[c]);\r\
    \n\t\t\t}\r\n\t\t}\r\n\r\n\t\t/* calc true Suffix Array using true seed */\r\n\
    \t\tauto suffixArray = inducedSort(str, type, lmsTrueOrder);\r\n\r\n\t\treturn\
    \ suffixArray;\r\n\t}\r\n\r\npublic:\r\n\tSuffixArray(const std::string& str)\
    \ :m_str(str), m_suffixArray(constructSuffixArray(toIntVec(str))) {}\r\n\r\n\t\
    /**\r\n\t * \u5F15\u6570\u3068\u3057\u3066\u4E0E\u3048\u3089\u308C\u305Fpattern\u306E\
    \u51FA\u73FE\u4F4D\u7F6E\u30EA\u30B9\u30C8\u3092\u8FD4\u3059\r\n\t */\r\n\tstd::list<int>\
    \ findPattern(const std::string& pattern) const {\r\n\r\n\t\tauto find = [&](const\
    \ std::string& ptn) {\r\n\t\t\tint end = m_suffixArray.size();\r\n\t\t\tint ok\
    \ = end;\r\n\t\t\tint ng = -1;\r\n\t\t\twhile (ok - ng > 1) {\r\n\t\t\t\tint mid\
    \ = (ok + ng) / 2;\r\n\t\t\t\tauto sub = m_str.substr(m_suffixArray[mid], end);\r\
    \n\t\t\t\tint isOk = (ptn <= sub);\r\n\t\t\t\tif (isOk) { ok = mid; } else { ng\
    \ = mid; }\r\n\t\t\t}\r\n\t\t\treturn ok;\r\n\t\t};\r\n\t\tauto patternUpper =\
    \ [&pattern]() {\r\n\t\t\tauto ptn = pattern;\r\n\t\t\t++* ptn.rbegin();\r\n\t\
    \t\treturn ptn;\r\n\t\t}();\r\n\t\tauto fl = find(pattern);\r\n\t\tauto fu = find(patternUpper);\r\
    \n\t\tstd::list<int> lst;\r\n\t\tfor (int i = fl; i < fu; ++i) {\r\n\t\t\tlst.emplace_back(m_suffixArray[i]);\r\
    \n\t\t}\r\n\t\treturn lst;\r\n\t}\r\n\r\n\tauto getSuffixArray() const {\r\n\t\
    \treturn m_suffixArray;\r\n\t}\r\n\r\n\t/* output fot debug */\r\n\tvoid debugOutput()\
    \ const {\r\n\t\tdump(m_suffixArray);\r\n\t\tauto end = m_str.size();\r\n\t\t\
    REPC(x, m_suffixArray) {\r\n\t\t\tcout << m_str.substr(x, end) << endl;\r\n\t\t\
    }\r\n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: Library/String/SuffixArray.cpp
  requiredBy: []
  timestamp: '2022-08-30 04:52:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/String/SuffixArray.cpp
layout: document
redirect_from:
- /library/Library/String/SuffixArray.cpp
- /library/Library/String/SuffixArray.cpp.html
title: Library/String/SuffixArray.cpp
---
