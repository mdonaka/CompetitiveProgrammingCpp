#pragma once

#include <algorithm>
#include <unordered_map>
#include <vector>

namespace mtd {

  class CoordinateCompression {
    const std::vector<long long> m_v;
    const std::vector<long long> m_itox;
    const std::unordered_map<long long, int> m_xtoi;

    static inline auto c_itox(const std::vector<long long>& v) {
      auto itox = v;
      std::sort(itox.begin(), itox.end());
      itox.erase(std::unique(itox.begin(), itox.end()), itox.end());
      return itox;
    }
    static inline auto c_xtoi(const std::vector<long long>& itox) {
      std::unordered_map<long long, int> xtoi;
      for (unsigned int i = 0; i < itox.size(); ++i) {
        xtoi.emplace(itox[i], i);
      }
      return xtoi;
    }

  public:
    CoordinateCompression(const std::vector<long long>& v)
        : m_v(v), m_itox(c_itox(v)), m_xtoi(c_xtoi(m_itox)) {}
    auto size() const { return m_itox.size(); }
    auto toi(long long x) const { return m_xtoi.at(x); }
    auto tox(int i) const { return m_itox[i]; }
    auto c(const std::vector<long long>& v) const {
      std::vector<long long> ret;
      ret.reserve(size());
      for (const auto& x : v) { ret.emplace_back(toi(x)); }
      return ret;
    }
    auto c() const { return c(m_v); }
  };

}  // namespace mtd
