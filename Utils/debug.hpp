#pragma once
#include <concepts>
#include <iostream>
#include <deque>
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
    std::deque<std::string_view> sList;
    int from = 0;
    for(int i = 0; auto && c : str) {
        if(c == del) {
            sList.emplace_back(str.substr(from, i - from));
            from = i + 1;
        }
        if(c == ' ') { ++from; }
        ++i;
    }
    sList.emplace_back(str.substr(from, str.size() - from));
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
constexpr auto print(const auto&) {
    std::cerr << "<ERROR!> \"print\" of This type is not defined." << '\n';
}
inline auto print(const std::string& s) { std::cerr << s << ' '; }
constexpr auto print(const Printable auto& p) { std::cerr << p << ' '; }
constexpr auto print(const Container auto& c) {
    for(auto&& x : c) {
        print(x);
    }
    std::cerr << '\n';
}

// 変数の出力
constexpr auto printVariable(auto&& name, const auto& p) {
    std::cerr << name << ": ";
    print(p);
    std::cerr << '\n';
}
inline auto printVariable(auto&& name, const std::string& s) {
    std::cerr << name << ": ";
    print(s);
    std::cerr << '\n';
}
constexpr auto printVariable(auto&& name, const Container auto& c) {
    std::cerr << "-- " << name << " --" << '\n';
    print(c);
}

// 1変数ずつ処理
constexpr auto splitVariables(auto&& names) {}
constexpr auto splitVariables(auto&& names, const auto& x,
                              const auto&... tail) {
    printVariable(names.front(), x);
    names.pop_front();
    splitVariables(std::forward<decltype(names)>(names), tail...);
}