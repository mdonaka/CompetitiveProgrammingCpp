#pragma once

#include <vector>
#include <deque>
#include <utility>

template<class T>
class isMonoid {
    template <class U>
    static auto check(U x) -> decltype(x.binaryOperation(x), std::true_type{});
    static std::false_type check(...);
public:
    static bool const value = decltype(check(std::declval<T>()))::value;
};

template<class Monoid, std::enable_if_t<isMonoid<Monoid>::value, std::nullptr_t> = nullptr >
class SegmentTree {
private:
    const int m_size;
    vector<Monoid> m_node;
    using S = decltype(Monoid().m_val);

    int calcSize(int n) const { int size = 1; while(size < n) { size <<= 1; }return size; }

    auto _add(int itr, Monoid&& val) {
        int i = itr + m_size - 1;
        m_node[i] = std::forward<decltype(val)>(val);
        while(i) {
            i = (i - 1) >> 1;
            m_node[i] = m_node[(i << 1) | 1].binaryOperation(m_node[(i + 1) << 1]);
        }
    }

    auto _query(int _l, int _r) const {
        auto l = _l + m_size;
        int r = _r + m_size;
        std::deque<Monoid> dq;
        while(l < r) {
            if(l & 1) { dq.emplace_front(m_node[l - 1]); ++l; }
            if(r & 1) { --r; dq.emplace_back(m_node[r - 1]); }
            l >>= 1, r >>= 1;
        }
        auto res = Monoid();
        for(auto&& m : dq) { res = res.binaryOperation(m); }
        return res;
    }
    auto _construct(const std::vector<S>& vec) {
        for(unsigned int i = 0; i < vec.size(); ++i) {
            m_node[i + m_size - 1] = Monoid(vec[i]);
        }
        for(int i = m_size - 2; i >= 0; --i) {
            m_node[i] = m_node[(i << 1) | 1].binaryOperation(m_node[(i + 1) << 1]);
        }
    }
public:
    SegmentTree(int n) : m_size(calcSize(n)), m_node((m_size << 1) - 1) {}
    SegmentTree(int n, const std::vector<S>& vec) :SegmentTree(n) { _construct(vec); }

    auto add(int itr, Monoid&& val) { return _add(itr, std::forward<Monoid>(val)); }
    auto query(int l, int r)const { return _query(l, r + 1).m_val; }

    auto output()const {
        for(int i = 0; i < m_size; ++i) { std::cout << m_node[m_size + i - 1] << " "; }
        std::cout << std::endl;
    }
};


template<
    class S,   // 要素の型
    S element, // 元
    class T // lambdaはC++20じゃないと渡せなかった．．．
    // S T(S, S)  // 2項演算子
>
struct Monoid {
    S m_val;
    Monoid() :m_val(element) {}
    Monoid(S val) :m_val(val) {}
    Monoid binaryOperation(const Monoid& m2)const { return T()(m_val, m2.m_val); }
    friend std::ostream& operator<<(std::ostream& os, const Monoid<S, element, T>& m) {
        return os << m.m_val;
    }
};