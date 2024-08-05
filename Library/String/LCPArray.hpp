#pragma once

#include "./SuffixArray.hpp"

/**
 * LCPArrayを構築する
 * O(N)
 * suffix arrayで隣接するstrの最長共通接頭辞(LCP:Longest Common Prefix)を得る
 * ex) sa:[aab, ab, abaab, b, baab] -> LCPA:[1, 2, 0, 1]
 *
 * Kasai's algorithmで実装
 */
class LCPArray {
  const std::vector<int> m_lcpArray;
  const std::vector<int> m_suffixArray;

  static std::vector<int> constructLcpArray(const std::string& str) {
    auto sz = str.size();
    const auto suffixArray = SuffixArray(str).getSuffixArray();

    auto rank = std::vector<int>(sz);
    for (int i = 0; i < sz; ++i) { rank[suffixArray[i]] = i; }

    auto lcpArray = std::vector<int>(sz - 1);
    for (int i = 0, h = 0; i < sz; ++i) {
      if (rank[i] == 0) { continue; }
      int j = suffixArray[rank[i] - 1];
      if (h > 0) { --h; }
      for (; j + h < sz && i + h < sz; ++h) {
        if (str[i + h] != str[j + h]) { break; }
      }
      lcpArray[rank[i] - 1] = h;
    }
    return lcpArray;
  }

public:
  LCPArray(const std::string& str)
      : m_suffixArray(SuffixArray(str).getSuffixArray()),
        m_lcpArray(constructLcpArray(str)) {}

  auto getLCPArray() const { return m_lcpArray; }
  auto getSuffixArrayIndexList() const {
    std::vector<int> sail(m_suffixArray.size());
    for (unsigned int i = 0; i < m_suffixArray.size(); ++i) {
      sail[m_suffixArray[i]] = i;
    }
    return sail;
  }
};