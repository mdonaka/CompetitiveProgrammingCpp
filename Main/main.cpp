#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <functional>
#include <immintrin.h>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <ranges>
#include <complex>
#include <set>
#include <stack>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#ifdef DEBUG
#include "./CompetitiveProgrammingCpp/Utils/debug.hpp"
#include "./CompetitiveProgrammingCpp/Utils/Timer.hpp"
#include "./CompetitiveProgrammingCpp/Utils/sample.hpp"
#else
#define dump(...)
template<class T>constexpr inline auto d_val(T a, T b) { return a; }
#endif

/* macro func */
template<class T, class S>
inline auto chmax(T& t, const S& s) { if(s > t) { t = s; return true; } return false; }
template<class T, class S>
inline auto chmin(T& t, const S& s) { if(s < t) { t = s; return true; } return false; }
template<class S> constexpr auto vec(S x) { return x; }
template<class S, class... T> constexpr auto vec(S x, int n, T... ns) { return std::vector(n, vec(x, ns...)); }

/* type define */
using ll = long long;
template<class T>
using V = std::vector<T>;
template<class T = ll, class U = T>
using P = std::pair<T, U>;

/* Initial processing  */
struct Preprocessing { Preprocessing() { std::cin.tie(0); std::ios::sync_with_stdio(0); }; }_Preprocessing;

/* input */
template<class T> std::istream& operator >> (std::istream& is, std::vector<T>& vec) { for(T& x : vec) is >> x; return is; }

//=============================================================================================


signed main() {

}