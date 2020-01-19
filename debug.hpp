#pragma once
#include <concepts>
#include <iostream>
#include <list>
#include <string_view>

template<class T>constexpr inline auto d_val(T a, T b) { return b; }

// debug用出力マクロ
#define dump(...)                                               \
  do {                                                          \
    auto __DUMP_NAME_LIST__ = split(#__VA_ARGS__, ',');         \
    splitVariables(std::move(__DUMP_NAME_LIST__), __VA_ARGS__); \
  } while (false)

// 出力できる種類の追加
template<class S, class T>
std::ostream& operator<<(std::ostream& os, const std::pair<S, T>& p) {
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}
// split
inline auto split(std::string_view str, char del = ' ') {
	std::list<std::string_view> sList;
	int from = -1;
	int i = 0;
	for (auto && c : str) {
		if (c == ' ') {
			sList.emplace_back(str.substr(from + 1, i - from - 2));
			from = i;
		}
		++i;
	}
	sList.emplace_back(str.substr(from + 1, str.size() - from));
	return sList;
}
// 制約
template <class T>
concept Container = requires(T x) {
	x.begin();
};

template <class T>
concept Printable = requires(T x) {
	std::cerr << x;
};

// 出力
template<class T>
constexpr auto print(const T&) {
	std::cerr << "<ERROR!> \"print\" of This type is not defined." << '\n';
}
inline auto print(const std::string& s) { std::cerr << s << ' '; }
template<Printable T>
constexpr auto print(const T& p) { std::cerr << p << ' '; }
template<Container T>
constexpr auto print(const T& c) {
	for (auto&& x : c) {
		print(x);
	}
	std::cerr << '\n';
}

// 変数の出力
template<class T,class S>
constexpr auto printVariable(T&& name, const S& p) {
	std::cerr << name << ": ";
	print(p);
	std::cerr << '\n';
}
template<class T>
inline auto printVariable(T&& name, const std::string& s) {
	std::cerr << name << ": ";
	print(s);
	std::cerr << '\n';
}
template<class T, Container S>
constexpr auto printVariable(T&& name, const S& c) {
	std::cerr << "-- " << name << " --" << '\n';
	print(c);
}

// 1変数ずつ処理
template<class T>
constexpr auto splitVariables(T&& names) {}

template<class T, class S, class... Tail>
constexpr auto splitVariables(T&& names, const S& x,
							  const Tail&... tail) {
	printVariable(names.front(), x);
	names.pop_front();
	splitVariables(std::forward<decltype(names)>(names), tail...);
}