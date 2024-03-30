//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,avx512f")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <stack>
#include <queue>
#include <bitset>
#include <numeric>
#include <cassert>
#include <memory>
#include <random>
#include <functional>
#include <complex>
#include <immintrin.h>
#include <stdexcept>
#ifdef DEBUG
#include "./CompetitiveProgrammingCpp/Utils/debug.hpp"
#include "./CompetitiveProgrammingCpp/Utils/Timer.hpp"
#include "./CompetitiveProgrammingCpp/Utils/sample.hpp"
#else
#define dump(...)
template<class T>constexpr inline auto d_val(T a, T b) { return a; }
#endif

/* macro */
#define FOR(i, b, e) for(ll i = (ll)(b); i < (ll)(e); ++i)
#define RFOR(i, b, e) for(ll i = (ll)((e)-1); i >= (ll)(b); --i)
#define REP(i, n) FOR(i, 0, (n))
#define RREP(i, n) RFOR(i, 0, (n))
#define REPC(x,c) for(const auto& x:(c))
#define REPI2(it,b,e) for(auto it = (b); it != (e); ++it)
#define REPI(it,c) REPI2(it, (c).begin(), (c).end())
#define RREPI(it,c) REPI2(it, (c).rbegin(), (c).rend())
#define REPI_ERACE2(it, b, e) for(auto it = (b); it != (e);)
#define REPI_ERACE(it, c) REPI_ERACE2(it, (c).begin(), (c).end())
#define ALL(x) (x).begin(),(x).end()
/* macro func */
template<class T>
inline auto sort(T& t) { std::sort(ALL(t)); }
template<class T>
inline auto rsort(T& t) { std::sort((t).rbegin(), (t).rend()); }
template<class T, class S>
inline auto chmax(T& t, const S& s) { if(s > t) { t = s; return true; } return false; }
template<class T, class S>
inline auto chmin(T& t, const S& s) { if(s < t) { t = s; return true; } return false; }
inline auto BR() { std::cout << "\n"; }
template<class S> constexpr auto vec(S x) { return x; }
template<class S, class... T>constexpr auto vec(S x, int n, T... ns) { return std::vector(n, vec(x, ns...)); }

/* type define */
using ll = long long;
template<class T>
using V = std::vector<T>;
using VS = V<std::string>;
using VL = V<ll>;
using VVL = V<VL>;
template<class T = ll, class U = T>
using P = std::pair<T, U>;
using PAIR = P<ll>;

/* using std */
using std::cout;
using std::cin;
using std::cerr;
constexpr char endl = '\n';

/* Initial processing  */
struct Preprocessing { Preprocessing() { std::cin.tie(0); std::ios::sync_with_stdio(0); }; }_Preprocessing;

/* define hash */
constexpr unsigned int static_random() { return 1u * __TIME__[0] * __TIME__[1] * __TIME__[3] * __TIME__[4] * __TIME__[6] * __TIME__[7]; }
template<class T> struct Hash { auto operator()(T x) const { return std::hash<T>()(x) ^ static_random(); } };
template<> struct Hash<std::pair<int, int>> { auto operator()(const std::pair<int, int>& x) const { return Hash<long long>()(x.first << 31 | x.second); } };

/* input */
template<class T> std::istream& operator >> (std::istream& is, std::vector<T>& vec) { for(T& x : vec) is >> x; return is; }

/* constant value */
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;

//=============================================================================================

signed main() {

}