#pragma once

#include <iostream>

class EuclideanAlgorithm {
    using T = long long;

    const T m_a;
    const T m_b;
    const T m_mx; // �傫������ƃI�[�o�[�t���[���Ă��܂�

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

    auto kRange(T x, T b, T l) const -> std::tuple<T, T> {
        // x + b * k >= l �𖞂��� k �͈̔͂����߂�
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
            << " = " << m_gcd << std::endl;
        std::cout << m_a * m_x + m_b * m_y
            << " = " << m_gcd << std::endl;
    }

    EuclideanAlgorithm(T a, T b, T mx = 1e9) :m_a(a), m_b(b), m_mx(mx) {
        if(a == 0 && b == 0) { throw std::runtime_error(""); }
        auto [g, x, y] = excludedEuclidAlgorithm(a, b);
        m_gcd = g; m_x = x; m_y = y;
    }

    auto gcd() const {
        return m_gcd;
    }
    auto get(T x, T y) const {
        return m_a * x + m_b * y;
    }
    auto get(T k) const ->std::tuple<T, T> {
        if(m_b == 0) { return {m_x,m_y - k}; }
        if(m_a == 0) { return {m_x + k,m_y}; }
        return {m_x + m_b * k, m_y - m_a * k};
    }
    auto getMinX(T x_l = 0)const -> std::tuple<T, T> {
        return kRange(m_x, m_b, x_l);
    }
    auto getMinY(T y_l = 0)const -> std::tuple<T, T> {
        return kRange(m_y, -1 * m_a, y_l);
    }
    auto getMin(T x_l = 0, T y_l = 0)const -> std::tuple<T, T> {
        auto [xl, xr] = getMinX(x_l);
        auto [yl, yr] = getMinY(y_l);
        return {std::max(xl,yl),std::min(xr,yr)};
    }
};
