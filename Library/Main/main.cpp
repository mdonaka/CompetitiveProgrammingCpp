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
#include <ranges>
#include <set>
#include <stack>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// clang-format off
/* macro func */
template<class T, class S>
inline auto chmax(T& t, const S& s) { if(s > t) { t = s; return true; } return false; }
template<class T, class S>
inline auto chmin(T& t, const S& s) { if(s < t) { t = s; return true; } return false; }
template<class S> constexpr auto vec(S x) { return x; }
template<class S, class... T> constexpr auto vec(S x, int n, T... ns) { return std::vector(n, vec(x, ns...)); }

/* Initial processing  */
struct Preprocessing { Preprocessing() { std::cin.tie(0); std::ios::sync_with_stdio(0); }; }_Preprocessing;

// clang-format on
//=============================================================================================
// begin:tag debug
#include "./Library/Debug/Dump.hpp"
#include "./Library/Debug/Test.hpp"
#include "./Library/Debug/Timer.hpp"
// end:tag debug
// begin:tag includes

#include "./Library/Range/io.hpp"

// end:tag includes
//=============================================================================================

using ll = long long;

signed main() {}
