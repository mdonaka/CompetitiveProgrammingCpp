#pragma once
#include <vector>
#include <algorithm>

template<
    class S,   // 要素の型
    S element, // 元
    class T, // 2項演算子
    class U // 逆元
>
struct Group {
    S m_val;
    Group() :m_val(element) {}
    Group(S val) :m_val(val) {}
    Group inverse()const { return U()(m_val); }
    Group binaryOperation(const Group& g)const { return T()(m_val, g.m_val); }
};

template<class P> struct F_A_Inv { auto operator()(P x)const { return -x; } };
template<class P> struct F_A_Bin { auto operator()(P x, P y)const { return x + y; } };
template<class P> using AdditiveGroup = Group<P, P(0), F_A_Bin<P>, F_A_Inv<P>>;

template <class Group = AdditiveGroup<long long>>
class Accumulation {
    using S = decltype(Group().m_val);

    const int size;
    std::vector<Group> sumList;
public:

    Accumulation() = delete;
    Accumulation(const std::vector<Group>& v) :size(v.size()), sumList(size + 1) {
        for(int i = 0; i < size; ++i) {
            sumList[i + 1] = sumList[i].binaryOperation(v[i]);
        }
    }
    Accumulation(const std::vector<S>& v)
        :Accumulation(std::vector<Group>(v.begin(), v.end())) {
    }

    auto get(int n) {
        return sumList[n + 1].m_val;
    }
    auto get(int l, int r) {
        if(r < l) { return Group().m_val; }
        l = std::max(l, 0); r = std::min(r, size - 1);
        return sumList[r + 1].binaryOperation(sumList[l].inverse()).m_val;
    }
};
