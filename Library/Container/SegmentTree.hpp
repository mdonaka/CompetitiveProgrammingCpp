#pragma once

#include <vector>
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

	int calcSize(int n) const { int size = 1; while (size < n) { size <<= 1; }return size; }

	auto _query(int a, int b) {
		return _query(a, b + 1, 0, 0, m_size);
	}
	auto _query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) { return Monoid(); }
		if (a <= l && r <= b) { return m_node[k]; }
		return _query(a, b, 2 * k + 1, l, (l + r) / 2).binaryOperation(
			_query(a, b, 2 * k + 2, (l + r) / 2, r)
		);
	}
public:
	SegmentTree(int n) : m_size(calcSize(n)), m_node(m_size * 2 - 1) {}

	auto add(int itr, Monoid&& val) {
		int i = itr + m_size - 1;
		m_node[i] = std::forward<decltype(val)>(val);
		while (i > 0) {
			i = (i - 1) / 2;
			m_node[i] = m_node[i * 2 + 1].binaryOperation(m_node[i * 2 + 2]);
		}
	}
	auto query(int a, int b, int k, int l, int r) { return _query(a, b, k, l, r).m_val; }
	auto query(int a, int b) { return query(a, b + 1, 0, 0, m_size); }
};


template<
	class S,   // 要素の型
	S element, // 元
	S T(S, S)  // 2項演算子
>
struct Monoid {
	S m_val;
	Monoid() :m_val(element) {}
	Monoid(S val) :m_val(val) {}
	Monoid binaryOperation(const Monoid& m2)const { return T(m_val, m2.m_val); }
};