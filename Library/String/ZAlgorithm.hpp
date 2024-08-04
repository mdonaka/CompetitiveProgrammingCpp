#pragma once

#include <deque>
#include <iostream>
#include <string>
#include <vector>

/**
 * Z algorithmによりZ Arrayを構築する
 * O(N)
 * S[0..]とS[i..]の共通接頭辞数
 * ex) aaabaaaab -> [9, 2, 1, 0, 3, 4, 2, 1, 0]
 */
class ZAlgorithm {
  const std::vector<int> m_zArray;

  static auto constrcutZArray(const std::string& str) {
    auto sz = str.size();
    auto zArray = std::vector<int>(sz);
    zArray[0] = sz;

    int i = 1, j = 0;
    while (i < sz) {
      while (i + j < sz && str[j] == str[i + j]) ++j;
      zArray[i] = j;
      if (j == 0) {
        ++i;
        continue;
      }
      int k = 1;
      while (i + k < sz && k + zArray[k] < j) {
        zArray[i + k] = zArray[k];
        ++k;
      }
      i += k;
      j -= k;
    }
    return zArray;
  }

public:
  ZAlgorithm(const std::string& str) : m_zArray(constrcutZArray(str)) {}

  /* i∈[l,r]でz[i]=sizeとなるindexを返す */
  auto find(int l, int r, int size) const {
    std::deque<int> dq;
    for (int i = l; i <= r; ++i)
      if (m_zArray[i] == size) {
        dq.emplace_back(i);
      }
    return dq;
  }

  /* output for debug */
  void debugOutput() const {
    std::cerr << "-- z array --" << std::endl;
    for (const auto& x : m_zArray) {
      std::cerr << x << " ";
    }
    std::cerr << std::endl;
  }

  auto get() const { return m_zArray; }
};
