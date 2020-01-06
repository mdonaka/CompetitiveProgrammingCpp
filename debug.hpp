#pragma once
#include <list>
#include <string>
#include <iostream>

#define dump(...) do{ auto __DUMP_NAME_LIST__ = split(#__VA_ARGS__,','); print(__DUMP_NAME_LIST__, __VA_ARGS__);std::cout<<'\n';}while(false)

/* for dump function */
inline std::list<std::string> split(std::string str, char del) {
	std::list<std::string> sList;
	std::string s = "";
	for (const auto& c : str) {
		if (c == del) {
			sList.emplace_back(s);
			s = "";
		} else {
			if (c != ' ' || del == ' ') { s += c; }
		}
	}
	sList.emplace_back(s);
	return sList;
}

template<class S, class T>
std::ostream& operator<<(std::ostream& os, const std::pair<S, T>& p) {
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}

template<class T>
struct has_begin {
private:
	template <class U>
	static auto check(U x) -> decltype(x.begin(), std::true_type{});
	static std::false_type check(...);
public:
	static bool const value = decltype(check(std::declval<T>()))::value;
};

inline void print(std::list<std::string>& str);
template<class Primitive, class... Tail, std::enable_if_t<!has_begin<Primitive>::value, std::nullptr_t> = nullptr>
inline void print(std::list<std::string> & str, const Primitive & x, const Tail & ... tail);
template<class Container, class... Tail>
inline auto print(std::list<std::string>& str, const Container& c, const Tail& ... tail) -> decltype(c.begin());
template<class... Tail>
inline void print(std::list<std::string>& str, const std::string& s, const Tail& ... tail);


template<class Container>
inline auto printSingle(const Container& c) ->decltype(c.begin()) {
	for (const auto& x : c) {
		std::cout << x << " ";
	}
	std::cout << "\n";
	return c.begin();
}

template<class Primitive, std::enable_if_t<!has_begin<Primitive>::value, std::nullptr_t> = nullptr>
inline void printSingle(const Primitive & x) {
	std::cout << x << " ";
}

inline void print(std::list<std::string>& str) {}

template<class Primitive, class... Tail, std::enable_if_t<!has_begin<Primitive>::value, std::nullptr_t>>
inline void print(std::list<std::string> & str, const Primitive & x, const Tail & ... tail) {
	std::cout << *str.begin() << ":" << x << " ";
	if (sizeof...(tail) > 0) {
		std::cout << "\n";
		str.pop_front();
		print(str, tail...);
	}
}

template<class Container, class... Tail>
inline auto print(std::list<std::string>& str, const Container& c, const Tail& ... tail) ->decltype(c.begin()) {
	std::cout << "-- " << *str.begin() << " --\n";
	for (const auto& x : c) {
		printSingle(x);
		std::cout << "\n";
	}
	std::cout << "\n";
	str.pop_front();
	print(str, tail...);
	return c.begin();
}

template<class... Tail>inline void print(std::list<std::string>& str, const std::string& s, const Tail& ... tail) {
	std::cout << *str.begin() << ":" << s << "\n";
	str.pop_front();
	print(str, tail...);
}
