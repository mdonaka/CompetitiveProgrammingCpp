#pragma once
#include <iostream>
#include <list>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#include "./../Algorithms/BinarySearch.hpp"

namespace mtd {
  /**
   * SuffixArrayを構築する
   * O(N)
   * 文字列の全てのsuffixをソートした配列が得られる
   * ex) abadc -> [0, 2, 1, 4, 3]([abadc, adc, badc, c, dc])
   *
   * SA-IS(Suffix Array - Induced Sort)で実装
   */
  class SuffixArray {
    enum class TYPE { L, S, LMS };

    const std::string m_str;
    const std::vector<int> m_suffixArray;

    /* string to vector<int> */
    static std::vector<int> toIntVec(const std::string& str) {
      std::vector<int> vec;
      vec.reserve(str.size() + 1);
      for (const auto& c : str) { vec.emplace_back(c - '0' + 1); }
      vec.emplace_back(0);
      return vec;
    }

    /* classify { L, S, LMS } */
    static std::vector<TYPE> classifying(const std::vector<int>& str) {
      auto sz = static_cast<int>(str.size());
      auto typeArray = std::vector<TYPE>(sz);
      typeArray[sz - 1] = TYPE::S;
      for (int i = sz - 2; i >= 0; --i) {
        if (str[i] == str[i + 1]) {
          typeArray[i] = typeArray[i + 1];
          continue;
        }
        typeArray[i] = (str[i] < str[i + 1]) ? TYPE::S : TYPE::L;
      }
      for (int i = 1; i < sz; ++i) {
        if (typeArray[i - 1] == TYPE::L && typeArray[i] == TYPE::S) {
          typeArray[i] = TYPE::LMS;
        }
      }
      return typeArray;
    }

    /* induced sort */
    static std::vector<int> inducedSort(const std::vector<int>& str,
                                        const std::vector<TYPE>& type,
                                        std::list<int>& lmsList) {
      auto sz = str.size();
      auto nList = std::set<int>();
      for (const auto& c : str) { nList.emplace(c); }

      auto befCheck = [&](int k, auto& addList, bool rev) {
        if (k == 0) { return; }
        if (!rev && type[k - 1] == TYPE::L) {
          addList[str[k - 1]].emplace_back(k - 1);
        }
        if (rev && type[k - 1] != TYPE::L) {
          addList[str[k - 1]].emplace_front(k - 1);
        }
      };

      auto checkAndUpdate = [&](int n, auto& checkList, auto& addList,
                                bool rev) {
        auto& lst = checkList[n];
        if (rev) {
          for (auto itr = lst.rbegin(); itr != lst.rend(); ++itr) {
            befCheck(*itr, addList, rev);
          }
        } else {
          for (const auto& k : lst) { befCheck(k, addList, rev); }
        }
      };

      /* set LMS */
      auto tailList = std::unordered_map<int, std::list<int>>();
      for (const auto& i : lmsList) { tailList[str[i]].emplace_back(i); }

      /* set L-type */
      auto headList = std::unordered_map<int, std::list<int>>();
      for (const auto& n : nList) {
        checkAndUpdate(n, headList, headList, false);
        checkAndUpdate(n, tailList, headList, false);
      }

      /* set S-type*/
      tailList = std::unordered_map<int, std::list<int>>();
      for (auto itr_n = nList.rbegin(); itr_n != nList.rend(); ++itr_n) {
        auto n = *itr_n;
        checkAndUpdate(n, tailList, tailList, true);
        checkAndUpdate(n, headList, tailList, true);
      }

      /* merge */
      auto suffixArray = std::vector<int>();
      suffixArray.reserve(sz);
      for (const auto& n : nList) {
        for (const auto& c : headList[n]) { suffixArray.emplace_back(c); }
        for (const auto& c : tailList[n]) { suffixArray.emplace_back(c); }
      }

      return suffixArray;
    }

    /* order lms -> sorted lms */
    static std::unordered_map<int, int> getLmsChanger(
        const std::vector<int>& str, const std::vector<TYPE>& type,
        const std::list<int>& lms) {
      if (lms.size() == 1) {
        return std::unordered_map<int, int>{{str.size() - 1, 0}};
      }
      std::unordered_map<int, int> changer{
          {static_cast<int>(str.size()) - 1, 0}, {*++lms.begin(), 1}};
      int num = 1;
      for (auto itr = ++lms.begin(); itr != (--lms.end());) {
        auto f1 = *itr;
        auto f2 = *(++itr);

        bool isSame = false;
        for (int i = 0;; ++i) {
          if (str[f1 + i] != str[f2 + i]) { break; }
          auto b1 = (type[f1 + i] == TYPE::LMS);
          auto b2 = (type[f2 + i] == TYPE::LMS);
          if ((b1 || b2) && i > 0) {
            if (b1 && b2) {
              isSame = true;
              break;
            }
            break;
          }
        }
        if (!isSame) { ++num; }
        changer.emplace(f2, num);
      }
      return changer;
    }

    /* calc Suffix Array*/
    static std::vector<int> constructSuffixArray(const std::vector<int>& str) {
      auto type = classifying(str);

      /* calc fake Suffix Array using order seed*/
      auto lmsOrder = [&type]() {
        auto lms = std::list<int>();
        for (size_t i = 0; i < type.size(); ++i)
          if (type[i] == TYPE::LMS) { lms.emplace_back(i); }
        return lms;
      }();
      auto fakeArray = inducedSort(str, type, lmsOrder);

      /* calc true seed */
      auto lmsFakeOrder = [&fakeArray, &type]() {
        auto lms = std::list<int>();
        lms.emplace_back(static_cast<int>(type.size()) - 1);
        for (const auto& i : fakeArray)
          if (type[i] == TYPE::LMS) { lms.emplace_back(i); }
        return lms;
      }();
      auto changer = getLmsChanger(str, type, lmsFakeOrder);
      auto& lmsTrueOrder = lmsFakeOrder;
      if (changer[*lmsFakeOrder.rbegin()] + 1 <
          static_cast<int>(lmsFakeOrder.size())) {
        /* exist same lms-substring */
        auto s = std::vector<int>();
        auto def = std::vector<int>();
        s.reserve(lmsOrder.size());
        def.reserve(lmsOrder.size());
        for (const auto& c : lmsOrder) {
          s.emplace_back(changer[c]);
          def.emplace_back(c);
        }
        auto lmsSuffixArray = constructSuffixArray(s);
        lmsTrueOrder = std::list<int>{static_cast<int>(type.size()) - 1};
        for (const auto& c : lmsSuffixArray) {
          lmsTrueOrder.emplace_back(def[c]);
        }
      }

      /* calc true Suffix Array using true seed */
      auto suffixArray = inducedSort(str, type, lmsTrueOrder);

      return suffixArray;
    }

  public:
    SuffixArray(const std::string& str)
        : m_str(str), m_suffixArray(constructSuffixArray(toIntVec(str))) {}

    /**
     * 引数として与えられたpattern出現位置の区間を返す
     */
    std::pair<int, int> findPattern(const std::string& pattern) const {
      auto find = [&](const std::string& ptn) {
        int end = static_cast<int>(m_suffixArray.size());
        int ptn_sz = static_cast<int>(ptn.size());
        auto ret = binarySearch(end, -1, [&](int mid) {
          int st = m_suffixArray[mid];
          int sub_sz = end - st;
          for (int k = 0; k < std::min(ptn_sz, sub_sz); ++k) {
            if (ptn[k] < m_str[st + k]) { return true; }
            if (ptn[k] > m_str[st + k]) { return false; }
          }
          return ptn_sz <= sub_sz;
        });
        return ret;
      };
      auto patternUpper = [&pattern]() {
        auto ptn = pattern;
        ++*ptn.rbegin();
        return ptn;
      }();
      auto fl = find(pattern);
      auto fu = find(patternUpper);
      return {fl, fu};
    }

    auto getSuffixArray() const { return m_suffixArray; }

    /* output fot debug */
    void debugOutput() const {
      for (const auto& x : m_suffixArray) { std::cout << x << " "; }
      std::cout << std::endl;
      auto end = m_str.size();
      for (const auto& x : m_suffixArray) {
        std::cout << m_str.substr(x, end) << std::endl;
      }
    }
  };
}  // namespace mtd
