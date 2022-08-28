#pragma once
#include <iostream>
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

template<
    class Monoid, class MonoidOp, class op,
    std::enable_if_t<isMonoid<Monoid>::value, std::nullptr_t> = nullptr,
    std::enable_if_t<isMonoid<MonoidOp>::value, std::nullptr_t> = nullptr>
class LazySegmentTree {
private:

    const int m_size;
    std::vector<Monoid> m_node;
    std::vector<MonoidOp> m_lazy;
    using S = decltype(Monoid().m_val);

    int calcSize(int n) const { int size = 1; while(size < n) { size <<= 1; }return size; }

    auto _lazy_update(int i, const MonoidOp& val) {
        if(i >= (m_size << 1) - 1) { return; }
        m_lazy[i] = m_lazy[i].binaryOperation(val);
    }

    auto _propagate(int i) {
        m_node[i] = op()(m_node[i], m_lazy[i]);
        _lazy_update((i << 1) + 1, m_lazy[i]);
        _lazy_update((i << 1) + 2, m_lazy[i]);
        m_lazy[i] = MonoidOp();
    }

    auto _update(int l, int r, int k, int nl, int nr, const MonoidOp& m) {
        _propagate(k);
        if(nr < l || r < nl) { return; }
        if(l <= nl && nr <= r) { _lazy_update(k, m); _propagate(k); return; }
        _update(l, r, (k << 1) + 1, nl, (nl + nr) >> 1, m);
        _update(l, r, (k << 1) + 2, ((nl + nr) >> 1) + 1, nr, m);
        m_node[k] = m_node[(k << 1) + 1].binaryOperation(m_node[(k << 1) + 2]);
    }

    auto _query(int l, int r, int k, int nl, int nr) {
        _propagate(k);
        if(nr < l || r < nl) { return Monoid(); }
        if(l <= nl && nr <= r) { return m_node[k]; }
        auto l_val = _query(l, r, (k << 1) + 1, nl, (nl + nr) >> 1);
        auto r_val = _query(l, r, (k << 1) + 2, ((nl + nr) >> 1) + 1, nr);
        return l_val.binaryOperation(r_val);
    }

    auto _construct(const std::vector<S>& vec) {
        for(unsigned int i = 0; i < vec.size(); ++i) {
            m_node[i + m_size - 1] = Monoid(vec[i]);
        }
        for(int i = m_size - 2; i >= 0; --i) {
            m_node[i] = m_node[(i << 1) | 1].binaryOperation(m_node[(i + 1) << 1LL]);
        }
    }
public:
    LazySegmentTree(int n) : m_size(calcSize(n)), m_node((m_size << 1) - 1), m_lazy((m_size << 1) - 1) {}
    LazySegmentTree(int n, const std::vector<S>& vec) :LazySegmentTree(n) { _construct(vec); }

    auto update(int l, int r, const MonoidOp& val) {
        _update(l, r, 0, 0, m_size - 1, val);
    }

    auto query(int l, int r) {
        return _query(l, r, 0, 0, m_size - 1).m_val;
    }

    auto output() {
        for(int i = 0; i < (m_size << 1) - 1; ++i) { _propagate(i); }
        for(int i = 0; i < m_size; ++i) { std::cout << m_node[m_size + i - 1] << " "; }
        std::cout << std::endl;
    }

};

template<
    class S,   // 要素の型
    S& element, // 元
    class T // 2項演算のFunctor
>
struct Monoid {
    S m_val;
    Monoid() :m_val(element) {}
    Monoid(S val) :m_val(val) {}
    Monoid  binaryOperation(const Monoid& m2)const { return T()(m_val, m2.m_val); }
    friend std::ostream& operator<<(std::ostream& os, const Monoid<S, element, T>& m) {
        return os << m.m_val;
    }
};
