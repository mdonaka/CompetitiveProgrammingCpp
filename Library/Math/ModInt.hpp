#pragma once

#include <iostream>
#include <iterator>

#include "./Math.hpp"

namespace mtd {

  template <int MOD, class T = long long>
  class ModInt {
    T x;

  public:
    constexpr ModInt(T x) : x(x % MOD) {}
    constexpr ModInt() : ModInt(0) {}

    // 四則演算
    constexpr auto& operator+=(const ModInt<MOD, T>& m) {
      x += m.x;
      if (x >= MOD) { x -= MOD; }
      return *this;
    }
    constexpr auto& operator-=(const ModInt<MOD, T>& m) {
      x -= m.x;
      if (x < 0) { x += MOD; }
      return *this;
    }
    constexpr auto& operator*=(const ModInt<MOD, T>& m) {
      x *= m.x;
      if (x >= MOD) { x %= MOD; }
      return *this;
    }
    constexpr auto& operator/=(const ModInt<MOD, T>& m) {
      x *= mtd::Math<ModInt<MOD, T>>::pow(m.x, MOD - 2).x;
      if (x >= MOD) { x %= MOD; }
      return *this;
    }

    constexpr auto operator+(const ModInt<MOD, T>& m) const {
      auto t = *this;
      t += m;
      return t;
    }
    constexpr auto operator-(const ModInt<MOD, T>& m) const {
      auto t = *this;
      t -= m;
      return t;
    }
    constexpr auto operator*(const ModInt<MOD, T>& m) const {
      auto t = *this;
      t *= m;
      return t;
    }
    constexpr auto operator/(const ModInt<MOD, T>& m) const {
      auto t = *this;
      t /= m;
      return t;
    }

    constexpr auto& operator+=(const T& t) {
      return *this += ModInt<MOD, T>(t);
    }
    constexpr auto& operator-=(const T& t) {
      return *this -= ModInt<MOD, T>(t);
    }
    constexpr auto& operator*=(const T& n) {
      return *this *= ModInt<MOD, T>(n);
    }
    constexpr auto& operator/=(const T& n) {
      return *this /= ModInt<MOD, T>(n);
    }
    constexpr auto operator+(const T& t) const {
      return *this + ModInt<MOD, T>(t);
    }
    constexpr auto operator-(const T& t) const {
      return *this - ModInt<MOD, T>(t);
    }
    constexpr auto operator*(const T& t) const {
      return *this * ModInt<MOD, T>(t);
    }
    constexpr auto operator/(const T& t) const {
      return *this / ModInt<MOD, T>(t);
    }
    constexpr friend auto operator+(const T& t, const ModInt<MOD, T>& m) {
      return m + t;
    }
    constexpr friend auto operator-(const T& t, const ModInt<MOD, T>& m) {
      return -m + t;
    }
    constexpr friend auto operator*(const T& t, const ModInt<MOD, T>& m) {
      return m * t;
    }
    constexpr friend auto operator/(const T& t, const ModInt<MOD, T>& m) {
      return ModInt<MOD, T>(1) / m * t;
    }

    // 入出力
    constexpr friend std::ostream& operator<<(std::ostream& os,
                                              const ModInt<MOD, T>& m) {
      return os << m.x;
    }
    constexpr friend std::istream& operator>>(std::istream& is,
                                              ModInt<MOD, T>& m) {
      return is >> m.x;
    }

    constexpr auto val() const { return x; }
  };

}  // namespace mtd
