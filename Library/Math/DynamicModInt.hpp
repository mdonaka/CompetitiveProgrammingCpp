#pragma once

#include <iostream>
#include <iterator>

#include "./Math.hpp"

namespace mtd {

  template <class T = long long>
  class DynamicModInt {
    static inline T MOD = 0;
    T x;

  public:
    constexpr static inline auto set_mod(T _MOD) { MOD = _MOD; }

    constexpr DynamicModInt(T _x) : x(_x >= 0 ? _x % MOD : MOD + (_x % MOD)) {}
    constexpr DynamicModInt() : DynamicModInt(0) {}

    // 四則演算
    constexpr auto& operator+=(const DynamicModInt<T>& m) {
      x += m.x;
      if (x >= MOD) { x -= MOD; }
      return *this;
    }
    constexpr auto& operator-=(const DynamicModInt<T>& m) {
      x -= m.x;
      if (x < 0) { x += MOD; }
      return *this;
    }
    constexpr auto& operator*=(const DynamicModInt<T>& m) {
      x *= m.x;
      if (x >= MOD) { x %= MOD; }
      return *this;
    }
    constexpr auto& operator/=(const DynamicModInt<T>& m) {
      x *= mtd::Math<DynamicModInt<T>>::pow(m.x, MOD - 2).x;
      if (x >= MOD) { x %= MOD; }
      return *this;
    }

    constexpr auto operator+(const DynamicModInt<T>& m) const {
      auto t = *this;
      t += m;
      return t;
    }
    constexpr auto operator-(const DynamicModInt<T>& m) const {
      auto t = *this;
      t -= m;
      return t;
    }
    constexpr auto operator*(const DynamicModInt<T>& m) const {
      auto t = *this;
      t *= m;
      return t;
    }
    constexpr auto operator/(const DynamicModInt<T>& m) const {
      auto t = *this;
      t /= m;
      return t;
    }

    constexpr auto& operator+=(const T& t) {
      return *this += DynamicModInt<T>(t);
    }
    constexpr auto& operator-=(const T& t) {
      return *this -= DynamicModInt<T>(t);
    }
    constexpr auto& operator*=(const T& n) {
      return *this *= DynamicModInt<T>(n);
    }
    constexpr auto& operator/=(const T& n) {
      return *this /= DynamicModInt<T>(n);
    }
    constexpr auto operator+(const T& t) const {
      return *this + DynamicModInt<T>(t);
    }
    constexpr auto operator-(const T& t) const {
      return *this - DynamicModInt<T>(t);
    }
    constexpr auto operator*(const T& t) const {
      return *this * DynamicModInt<T>(t);
    }
    constexpr auto operator/(const T& t) const {
      return *this / DynamicModInt<T>(t);
    }
    constexpr friend auto operator+(const T& t, const DynamicModInt<T>& m) {
      return m + t;
    }
    constexpr friend auto operator-(const T& t, const DynamicModInt<T>& m) {
      return -m + t;
    }
    constexpr friend auto operator*(const T& t, const DynamicModInt<T>& m) {
      return m * t;
    }
    constexpr friend auto operator/(const T& t, const DynamicModInt<T>& m) {
      return DynamicModInt<T>(1) / m * t;
    }

    // 単項演算
    constexpr auto operator-() const { return DynamicModInt<T>(0 - x); }

    // 比較演算
    constexpr auto operator!=(const DynamicModInt<T>& m) const {
      return x != m.x;
    }

    // 入出力
    constexpr friend std::ostream& operator<<(std::ostream& os,
                                              const DynamicModInt<T>& m) {
      return os << m.x;
    }
    constexpr friend std::istream& operator>>(std::istream& is,
                                              DynamicModInt<T>& m) {
      return is >> m.x;
    }

    constexpr auto val() const { return x; }
  };

}  // namespace mtd
