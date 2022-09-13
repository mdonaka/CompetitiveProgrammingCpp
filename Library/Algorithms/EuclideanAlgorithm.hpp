#pragma once

#include <iostream>
#include <numeric>
#include <tuple>

class EuclideanAlgorithm {
    using T = long long;

    // 大きすぎるとオーバーフローしてしまう
    const static inline T m_mx = 1e9;

    const T m_a;
    const T m_b;
    const T m_c;

    T m_gcd;
    T m_x;
    T m_y;

    auto excludedEuclidAlgorithm(T a, T b) -> std::tuple<T, T, T> {
        if(a < 0) {
            auto [g, x, y] = excludedEuclidAlgorithm(-a, -b);
            return {g,-x,-y};
        }
        if(b == 0) { return {a, 1, 0}; }
        auto [g, y, x] = excludedEuclidAlgorithm(b, a % b);
        y -= a / b * x;
        return {g, x, y};
    }

    auto kRange(T x, T b, T l) const -> std::pair<T, T> {
        // x + b * k >= l を満たす k の範囲を求める
        T xd = (l - x);
        if(b == 0 && x >= l) { return {-m_mx,m_mx}; }
        if(b == 0 && x < l) { return {m_mx,-m_mx}; }
        if(b > 0 && xd < 0) { return {xd / b,m_mx}; }
        if(b > 0 && xd >= 0) { return {(xd + b - 1) / b,m_mx}; }
        if(b < 0 && xd < 0) { return {-m_mx,(-xd) / (-b)}; }
        if(b < 0 && xd >= 0) { return {-m_mx,-(xd - b - 1) / (-b)}; }
        return {m_mx,-m_mx};
    }

public:
    auto debug()const {
        std::cout << m_a << " * " << m_x
            << " + " << m_b << " * " << m_y
            << " = " << m_c << std::endl;
        std::cout << "calc: " << m_a * m_x + m_b * m_y
            << " = " << m_c << std::endl;
    }

    EuclideanAlgorithm(T a, T b, T c) :m_a(a), m_b(b), m_c(c) {
        if(a == 0 && b == 0) { throw std::runtime_error(""); }
        auto [g, x, y] = excludedEuclidAlgorithm(a, b);
        if(c % g > 0) { throw std::runtime_error("There is no solution to the equation. c must be divisible by gcd(a,b)."); }
        m_gcd = g; m_x = c / g * x; m_y = c / g * y;
    }
    EuclideanAlgorithm(T a, T b) :EuclideanAlgorithm(a, b, std::gcd(a, b)) {}

    auto gcd() const {
        return m_gcd;
    }
    auto get(T x, T y) const {
        return m_a * x + m_b * y;
    }
    auto get(T k) const ->std::pair<T, T> {
        if(m_b == 0) { return {m_x,m_y - k}; }
        if(m_a == 0) { return {m_x + k,m_y}; }
        return {m_x + m_b * k, m_y - m_a * k};
    }
    auto getMinX(T x_l = 0)const -> std::pair<T, T> {
        return kRange(m_x, m_b, x_l);
    }
    auto getMinY(T y_l = 0)const -> std::pair<T, T> {
        return kRange(m_y, -1 * m_a, y_l);
    }
    auto getMin(T x_l = 0, T y_l = 0)const -> std::pair<T, T> {
        auto [xl, xr] = getMinX(x_l);
        auto [yl, yr] = getMinY(y_l);
        return {std::max(xl,yl),std::min(xr,yr)};
    }
};
