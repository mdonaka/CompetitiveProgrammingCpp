//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,avx512f")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <immintrin.h>

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#ifdef DEBUG
#include "./CompetitiveProgrammingCpp/Utils/Timer.hpp"
#include "./CompetitiveProgrammingCpp/Utils/debug.hpp"
#include "./CompetitiveProgrammingCpp/Utils/sample.hpp"
#else
#define dump(...)
template <class T>
constexpr inline auto d_val(T a, T b) {
  return a;
}
#endif

/* macro */
#define FOR(i, b, e) for (ll i = (ll)(b); i < (ll)(e); ++i)
#define RFOR(i, b, e) for (ll i = (ll)((e)-1); i >= (ll)(b); --i)
#define REP(i, n) FOR(i, 0, (n))
#define RREP(i, n) RFOR(i, 0, (n))
#define REPC(x, c) for (const auto& x : (c))
#define REPI2(it, b, e) for (auto it = (b); it != (e); ++it)
#define REPI(it, c) REPI2(it, (c).begin(), (c).end())
#define RREPI(it, c) REPI2(it, (c).rbegin(), (c).rend())
#define REPI_ERACE2(it, b, e) for (auto it = (b); it != (e);)
#define REPI_ERACE(it, c) REPI_ERACE2(it, (c).begin(), (c).end())
#define ALL(x) (x).begin(), (x).end()
/* macro func */
template <class T>
inline auto sort(T& t) {
  std::sort(ALL(t));
}
template <class T>
inline auto rsort(T& t) {
  std::sort((t).rbegin(), (t).rend());
}
template <class T, class S>
inline auto chmax(T& t, const S& s) {
  if (s > t) {
    t = s;
    return true;
  }
  return false;
}
template <class T, class S>
inline auto chmin(T& t, const S& s) {
  if (s < t) {
    t = s;
    return true;
  }
  return false;
}
inline auto BR() { std::cout << "\n"; }

/* type define */
using ll = long long;
template <class T>
using V = std::vector<T>;
using VS = V<std::string>;
using VL = V<ll>;
using VVL = V<VL>;
template <class T = ll, class U = T>
using P = std::pair<T, U>;
using PAIR = P<ll>;

/* using std */
using std::cerr;
using std::cin;
using std::cout;
constexpr char endl = '\n';

/* define hash */
namespace std {
  template <>
  class hash<std::pair<ll, ll>> {
  public:
    size_t operator()(const std::pair<ll, ll>& x) const {
      return std::hash<ll>()(x.first << 31 | x.second);
    }
  };
}  // namespace std

/* input */
template <class T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
  for (T& x : vec) is >> x;
  return is;
}

/* constant value */
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;

//=============================================================================================

auto interactive(ll x) {
  constexpr ll QUERY_LIMIT = 26;
  REP(_, QUERY_LIMIT) {}
  return false;
}

#ifdef _WIN32
auto _main()
#else
signed main()
#endif
{
  // seed settings
  auto seed = std::random_device()();
  auto gen = Sample::SampleGenerator(seed);

  // paramete settings
  constexpr ll MAX = 1e6;
  auto [x] = gen.generate(PAIR{1, MAX});

  // run
  if (!interactive(x)) {
    cerr << "-- internal data --" << endl;
    cerr << x << endl;
    cerr << "-------------------" << endl;
    cerr << "seed: " << seed << endl;
    cerr << "-------------------" << endl;
    throw std::runtime_error("Failed");
  }
}