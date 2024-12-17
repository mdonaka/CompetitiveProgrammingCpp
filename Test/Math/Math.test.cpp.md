---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Debug/Dump.hpp
    title: Library/Debug/Dump.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Math/Math.hpp
    title: Library/Math/Math.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Math/ModInt.hpp
    title: Library/Math/ModInt.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Range/istream.hpp
    title: Library/Range/istream.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Utility/Tuple.hpp
    title: Library/Utility/Tuple.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Utility/io.hpp
    title: Library/Utility/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/117
    links:
    - https://yukicoder.me/problems/no/117
  bundledCode: "#line 1 \"Test/Math/Math.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/117\"\
    \r\n\r\n#include <iostream>\r\n#include <string>\r\n\r\n// begin:tag includes\r\
    \n#line 2 \"Library/Math/ModInt.hpp\"\n\n#line 4 \"Library/Math/ModInt.hpp\"\n\
    #include <iterator>\n\n#line 2 \"Library/Math/Math.hpp\"\n\r\n#include <vector>\r\
    \n\r\nnamespace mtd {\r\n  template <class T>\r\n  class Math {\r\n    const std::vector<T>\
    \ m_fac;\r\n    const std::vector<T> m_finv;\r\n\r\n    auto constructFac(int\
    \ s) {\r\n      std::vector<T> fac(s);\r\n      fac[0] = fac[1] = 1;\r\n     \
    \ for (long long i = 2; i < s; ++i) { fac[i] = fac[i - 1] * i; }\r\n      return\
    \ fac;\r\n    }\r\n    auto constructInv(int s) {\r\n      std::vector<T> finv(s);\r\
    \n      finv[s - 1] = 1 / m_fac[s - 1];\r\n      for (long long i = s - 2; i >=\
    \ 0; --i) {\r\n        finv[i] = finv[i + 1] * (i + 1);\r\n      }\r\n      return\
    \ finv;\r\n    }\r\n\r\n  public:\r\n    constexpr Math(long long size = 3 * 1e6)\r\
    \n        : m_fac(constructFac(size)), m_finv(constructInv(size)) {}\r\n\r\n \
    \   static constexpr T pow(T a, long long b) {\r\n      T ans = 1;\r\n      while\
    \ (b > 0) {\r\n        if (b & 1) { ans *= a; }\r\n        b >>= 1;\r\n      \
    \  a *= a;\r\n      }\r\n      return ans;\r\n    }\r\n    constexpr auto fact(int\
    \ n) const { return (n < 0) ? 0 : m_fac[n]; }\r\n    constexpr auto factInv(int\
    \ n) const { return (n < 0 ? 0 : m_finv[n]); }\r\n    constexpr auto comb(int\
    \ n, int r) const {\r\n      return fact(n) * factInv(r) * factInv(n - r);\r\n\
    \    }\r\n    constexpr auto perm(int n, int r) const { return fact(n) * factInv(n\
    \ - r); }\r\n  };\r\n}  // namespace mtd\r\n#line 7 \"Library/Math/ModInt.hpp\"\
    \n\nnamespace mtd {\n\n  template <int MOD, class T = long long>\n  class ModInt\
    \ {\n  public:\n    T x;\n\n    constexpr ModInt(T x) : x(x >= 0 ? x % MOD : MOD\
    \ + (x % MOD)) {}\n    constexpr ModInt() : ModInt(0) {}\n\n    // \u56DB\u5247\
    \u6F14\u7B97\n    constexpr auto& operator+=(const ModInt<MOD, T>& m) {\n    \
    \  x += m.x;\n      if (x >= MOD) { x -= MOD; }\n      return *this;\n    }\n\
    \    constexpr auto& operator-=(const ModInt<MOD, T>& m) {\n      x -= m.x;\n\
    \      if (x < 0) { x += MOD; }\n      return *this;\n    }\n    constexpr auto&\
    \ operator*=(const ModInt<MOD, T>& m) {\n      x *= m.x;\n      if (x >= MOD)\
    \ { x %= MOD; }\n      return *this;\n    }\n    constexpr auto& operator/=(const\
    \ ModInt<MOD, T>& m) {\n      x *= mtd::Math<ModInt<MOD, T>>::pow(m.x, MOD - 2).x;\n\
    \      if (x >= MOD) { x %= MOD; }\n      return *this;\n    }\n\n    constexpr\
    \ auto operator+(const ModInt<MOD, T>& m) const {\n      auto t = *this;\n   \
    \   t += m;\n      return t;\n    }\n    constexpr auto operator-(const ModInt<MOD,\
    \ T>& m) const {\n      auto t = *this;\n      t -= m;\n      return t;\n    }\n\
    \    constexpr auto operator*(const ModInt<MOD, T>& m) const {\n      auto t =\
    \ *this;\n      t *= m;\n      return t;\n    }\n    constexpr auto operator/(const\
    \ ModInt<MOD, T>& m) const {\n      auto t = *this;\n      t /= m;\n      return\
    \ t;\n    }\n\n    constexpr auto& operator+=(const T& t) {\n      return *this\
    \ += ModInt<MOD, T>(t);\n    }\n    constexpr auto& operator-=(const T& t) {\n\
    \      return *this -= ModInt<MOD, T>(t);\n    }\n    constexpr auto& operator*=(const\
    \ T& n) {\n      return *this *= ModInt<MOD, T>(n);\n    }\n    constexpr auto&\
    \ operator/=(const T& n) {\n      return *this /= ModInt<MOD, T>(n);\n    }\n\
    \    constexpr auto operator+(const T& t) const {\n      return *this + ModInt<MOD,\
    \ T>(t);\n    }\n    constexpr auto operator-(const T& t) const {\n      return\
    \ *this - ModInt<MOD, T>(t);\n    }\n    constexpr auto operator*(const T& t)\
    \ const {\n      return *this * ModInt<MOD, T>(t);\n    }\n    constexpr auto\
    \ operator/(const T& t) const {\n      return *this / ModInt<MOD, T>(t);\n   \
    \ }\n    constexpr friend auto operator+(const T& t, const ModInt<MOD, T>& m)\
    \ {\n      return m + t;\n    }\n    constexpr friend auto operator-(const T&\
    \ t, const ModInt<MOD, T>& m) {\n      return -m + t;\n    }\n    constexpr friend\
    \ auto operator*(const T& t, const ModInt<MOD, T>& m) {\n      return m * t;\n\
    \    }\n    constexpr friend auto operator/(const T& t, const ModInt<MOD, T>&\
    \ m) {\n      return ModInt<MOD, T>(1) / m * t;\n    }\n\n    // \u5358\u9805\u6F14\
    \u7B97\n    constexpr auto operator-() const { return ModInt<MOD, T>(0 - x); }\n\
    \n    // \u6BD4\u8F03\u6F14\u7B97\n    constexpr auto operator!=(const ModInt<MOD,\
    \ T>& m) const {\n      return x != m.x;\n    }\n    constexpr auto operator==(const\
    \ ModInt<MOD, T>& m) const {\n      return !(x != m.x);\n    }\n\n    // \u5165\
    \u51FA\u529B\n    constexpr friend std::ostream& operator<<(std::ostream& os,\n\
    \                                              const ModInt<MOD, T>& m) {\n  \
    \    return os << m.x;\n    }\n    constexpr friend std::istream& operator>>(std::istream&\
    \ is,\n                                              ModInt<MOD, T>& m) {\n  \
    \    return is >> m.x;\n    }\n\n    constexpr auto val() const { return x; }\n\
    \  };\n\n}  // namespace mtd\n#line 2 \"Library/Range/istream.hpp\"\n\n#include\
    \ <ranges>\n\n#line 2 \"Library/Utility/io.hpp\"\n\n#line 5 \"Library/Utility/io.hpp\"\
    \n#include <type_traits>\n#line 7 \"Library/Utility/io.hpp\"\n\n#line 2 \"Library/Debug/Dump.hpp\"\
    \n#include <concepts>\n#include <deque>\n#include <functional>\n#line 6 \"Library/Debug/Dump.hpp\"\
    \n#include <string_view>\n\ntemplate <class T>\nconstexpr inline auto d_val(T\
    \ a, T b) {\n  return b;\n}\n\n// debug\u7528\u51FA\u529B\u30DE\u30AF\u30ED\n\
    #define dump(...)                                               \\\n  do {   \
    \                                                       \\\n    auto __DUMP_NAME_LIST__\
    \ = split(#__VA_ARGS__, ',');         \\\n    splitVariables(std::move(__DUMP_NAME_LIST__),\
    \ __VA_ARGS__); \\\n  } while (false)\n\n// split\ninline auto split(std::string_view\
    \ str, char del = ' ') {\n  std::deque<std::string_view> sList;\n  int from =\
    \ 0;\n  for (int i = 0; auto&& c : str) {\n    if (c == del) {\n      sList.emplace_back(str.substr(from,\
    \ i - from));\n      from = i + 1;\n    }\n    if (c == ' ') { ++from; }\n   \
    \ ++i;\n  }\n  sList.emplace_back(str.substr(from, str.size() - from));\n  return\
    \ sList;\n}\n// \u5236\u7D04\ntemplate <class T>\nconcept Container = requires(T\
    \ x) {\n  x.begin();\n};\n\ntemplate <class T>\nconcept Printable = requires(T\
    \ x) {\n  std::cerr << x;\n};\n\n// \u5BA3\u8A00\ntemplate <class... T>\nconstexpr\
    \ auto print(const std::tuple<T...>&, bool b = true);\ntemplate <class S, class\
    \ T>\nconstexpr auto print(const std::pair<S, T>&, bool b = true);\ninline auto\
    \ print(const std::string&, bool b = true);\nconstexpr auto print(const Printable\
    \ auto&, bool b = true);\nconstexpr auto print(const Container auto&, bool b =\
    \ true);\n// \u5B9A\u7FA9\nconstexpr auto print(const auto&, bool) {\n  std::cerr\
    \ << \"<ERROR!> \\\"print\\\" of This type is not defined.\" << '\\n';\n}\n\n\
    template <class... T>\nconstexpr auto print(const std::tuple<T...>& t, bool b)\
    \ {\n  std::cerr << \"{\";\n  std::apply(\n      [&]<class... Ts>(Ts&&... elems)\
    \ {\n        (std::invoke([](auto i) { print(i, true); }, std::forward<Ts>(elems)),\n\
    \         ...);\n      },\n      t);\n  std::cerr << \"}\";\n  if (b) { std::cerr\
    \ << \" \"; }\n}\ntemplate <class S, class T>\nconstexpr auto print(const std::pair<S,\
    \ T>& p, bool b) {\n  std::cerr << '(';\n  print(p.first, false);\n  std::cerr\
    \ << \", \";\n  print(p.second, false);\n  std::cerr << ')';\n  if (b) { std::cerr\
    \ << \" \"; }\n}\ninline auto print(const std::string& s, bool b) {\n  std::cerr\
    \ << s;\n  if (b) { std::cerr << std::endl; }\n}\nconstexpr auto print(const Printable\
    \ auto& p, bool b) {\n  std::cerr << p;\n  if (b) { std::cerr << ' '; }\n}\nconstexpr\
    \ auto print(const Container auto& c, bool b) {\n  for (auto&& x : c) { print(x);\
    \ }\n  if (b) { std::cerr << '\\n'; }\n}\n\n// \u5909\u6570\u306E\u51FA\u529B\n\
    constexpr auto printVariable(auto&& name, const auto& p) {\n  std::cerr << name\
    \ << \": \";\n  print(p);\n  std::cerr << '\\n';\n}\ninline auto printVariable(auto&&\
    \ name, const std::string& s) {\n  std::cerr << name << \": \";\n  print(s);\n\
    \  std::cerr << '\\n';\n}\nconstexpr auto printVariable(auto&& name, const Container\
    \ auto& c) {\n  std::cerr << \"-- \" << name << \" --\" << '\\n';\n  print(c);\n\
    }\n\n// 1\u5909\u6570\u305A\u3064\u51E6\u7406\nconstexpr auto splitVariables(auto&&\
    \ names) {}\nconstexpr auto splitVariables(auto&& names, const auto& x,\n    \
    \                          const auto&... tail) {\n  printVariable(names.front(),\
    \ x);\n  names.pop_front();\n  splitVariables(std::forward<decltype(names)>(names),\
    \ tail...);\n}\n#line 2 \"Library/Utility/Tuple.hpp\"\n\n#line 4 \"Library/Utility/Tuple.hpp\"\
    \n\nnamespace mtd {\n  namespace util {\n    template <class F, class T>\n   \
    \ constexpr auto tuple_transform(F&& f, T&& t) {\n      return std::apply(\n \
    \         [&]<class... Ts>(Ts&&... elems) {\n            return std::tuple<std::invoke_result_t<F&,\
    \ Ts>...>(\n                std::invoke(f, std::forward<Ts>(elems))...);\n   \
    \       },\n          std::forward<T>(t));\n    }\n    template <class F, class\
    \ T>\n    constexpr auto tuple_for_each(F&& f, T&& t) {\n      std::apply(\n \
    \         [&]<class... Ts>(Ts&&... elems) {\n            (std::invoke(f, std::forward<Ts>(elems)),\
    \ ...);\n          },\n          std::forward<T>(t));\n    }\n  }  // namespace\
    \ util\n}  // namespace mtd\n#line 10 \"Library/Utility/io.hpp\"\n\nnamespace\
    \ mtd {\n  namespace io {\n\n    namespace type {\n      template <class T>\n\
    \      struct vec {\n        using value_type = T;\n      };\n      template <class\
    \ T>\n      concept is_vec = requires {\n        requires std::is_same_v<T, vec<typename\
    \ T::value_type>>;\n      };\n\n      template <class T>\n      struct mat {\n\
    \        using value_type = T;\n      };\n      template <class T>\n      concept\
    \ is_mat = requires {\n        requires std::is_same_v<T, mat<typename T::value_type>>;\n\
    \      };\n    }  // namespace type\n\n    template <class T>\n    auto _input()\
    \ {\n      T x;\n      std::cin >> x;\n      return x;\n    }\n    template <typename\
    \ T>\n    requires requires { typename std::tuple_size<T>::type; }\n    auto _input()\
    \ {\n      T x;\n      util::tuple_for_each([](auto&& i) { std::cin >> i; }, x);\n\
    \      return x;\n    }\n    template <type::is_vec T>\n    auto _input(int n)\
    \ {\n      std::vector<typename T::value_type> v;\n      v.reserve(n);\n     \
    \ for (auto i : std::views::iota(0, n)) {\n        v.emplace_back(_input<typename\
    \ T::value_type>());\n      }\n      return v;\n    }\n    template <type::is_mat\
    \ T>\n    auto _input(int h, int w) {\n      std::vector<std::vector<typename\
    \ T::value_type>> mat;\n      mat.reserve(h);\n      for (auto i : std::views::iota(0,\
    \ h)) {\n        mat.emplace_back(_input<type::vec<typename T::value_type>>(w));\n\
    \      }\n      return mat;\n    }\n\n    template <int N, class Tuple, class\
    \ T, class... Args, class... Sizes>\n    auto _tuple_input(Tuple& t, Sizes...\
    \ sizes);\n    template <int N, class Tuple, type::is_vec T, class... Args, class\
    \ Size,\n              class... Sizes>\n    auto _tuple_input(Tuple& t, Size size,\
    \ Sizes... sizes);\n    template <int N, class Tuple, type::is_mat T, class...\
    \ Args, class Size,\n              class... Sizes>\n    auto _tuple_input(Tuple&\
    \ t, Size size_h, Size size_w, Sizes... sizes);\n\n    template <int N, class\
    \ Tuple, class T, class... Args, class... Sizes>\n    auto _tuple_input(Tuple&\
    \ t, Sizes... sizes) {\n      std::get<N>(t) = _input<T>();\n      if constexpr\
    \ (sizeof...(Args) > 0) {\n        _tuple_input<N + 1, Tuple, Args...>(t, sizes...);\n\
    \      }\n    }\n    template <int N, class Tuple, type::is_vec T, class... Args,\
    \ class Size,\n              class... Sizes>\n    auto _tuple_input(Tuple& t,\
    \ Size size, Sizes... sizes) {\n      std::get<N>(t) = _input<T>(size);\n    \
    \  if constexpr (sizeof...(Args) > 0) {\n        _tuple_input<N + 1, Tuple, Args...>(t,\
    \ sizes...);\n      }\n    }\n    template <int N, class Tuple, type::is_mat T,\
    \ class... Args, class Size,\n              class... Sizes>\n    auto _tuple_input(Tuple&\
    \ t, Size size_h, Size size_w, Sizes... sizes) {\n      std::get<N>(t) = _input<T>(size_h,\
    \ size_w);\n      if constexpr (sizeof...(Args) > 0) {\n        _tuple_input<N\
    \ + 1, Tuple, Args...>(t, sizes...);\n      }\n    }\n\n    template <class T>\n\
    \    struct _Converter {\n      using type = T;\n    };\n    template <class T>\n\
    \    struct _Converter<type::vec<T>> {\n      using type = std::vector<T>;\n \
    \   };\n    template <class T>\n    struct _Converter<type::mat<T>> {\n      using\
    \ type = std::vector<std::vector<T>>;\n    };\n\n    template <class... Args,\
    \ class... Sizes>\n    requires(std::convertible_to<Sizes, size_t>&&...) auto\
    \ in(Sizes... sizes) {\n      auto base = std::tuple<typename _Converter<Args>::type...>();\n\
    \      _tuple_input<0, decltype(base), Args...>(base, sizes...);\n      return\
    \ base;\n    }\n\n  }  // namespace io\n\n}  // namespace mtd\n#line 6 \"Library/Range/istream.hpp\"\
    \n\nnamespace mtd {\n  namespace ranges {\n\n    constexpr int _inf = 1e9;\n\n\
    \    template <class... Args>\n    struct istream_view\n        : public std::ranges::view_interface<istream_view<Args...>>\
    \ {\n      class iterator {\n        int count;\n        std::tuple<typename io::_Converter<Args>::type...>\
    \ val;\n\n      public:\n        using difference_type = int;\n        using value_type\
    \ = decltype(val);\n        using iterator_concept = std::input_iterator_tag;\n\
    \n        constexpr iterator() = default;\n        constexpr explicit iterator(int\
    \ count) : count(count) { operator++(); }\n\n        constexpr auto operator*()\
    \ const { return val; }\n        constexpr auto& operator++() {\n          --count;\n\
    \          if (count >= 0) { val = io::in<Args...>(); }\n          return *this;\n\
    \        }\n        constexpr auto operator++(int) { return ++*this; }\n\n   \
    \     constexpr auto operator==(const iterator& s) const {\n          return count\
    \ == s.count;\n        }\n        constexpr auto operator==(std::default_sentinel_t\
    \ s) const {\n          return count < 0 || std::cin.eof() || std::cin.fail()\
    \ ||\n                 std::cin.bad();\n        }\n        constexpr friend auto\
    \ operator==(std::default_sentinel_t s,\n                                    \
    \     const iterator& li) {\n          return li == s;\n        }\n      };\n\n\
    \      int count;\n\n    public:\n      constexpr explicit istream_view(int count)\
    \ : count(count) {}\n      constexpr explicit istream_view() : istream_view(_inf)\
    \ {}\n      constexpr auto begin() const { return iterator(count); }\n      constexpr\
    \ auto end() const { return std::default_sentinel; }\n    };\n  }  // namespace\
    \ ranges\n\n  namespace views {\n    namespace __detail {\n      template <typename...\
    \ _Args>\n      concept __can_istream_view = requires {\n        ranges::istream_view(std::declval<_Args>()...);\n\
    \      };\n    }  // namespace __detail\n\n    template <class... Args>\n    struct\
    \ _Istream {\n      template <class... _Tp>\n      requires __detail::__can_istream_view<_Tp...>\n\
    \      constexpr auto operator() [[nodiscard]] (_Tp&&... __e) const {\n      \
    \  return ranges::istream_view<Args...>(std::forward<_Tp>(__e)...);\n      }\n\
    \    };\n\n    template <class... Args>\n    inline constexpr _Istream<Args...>\
    \ istream{};\n  }  // namespace views\n\n}  // namespace mtd\n#line 9 \"Test/Math/Math.test.cpp\"\
    \n// end:tag includes\r\n\r\nauto parse(const std::string s) {\r\n  long long\
    \ a = 0, b = 0;\r\n  bool isa = true;\r\n  for (unsigned int i = 2; i < s.size()\
    \ - 1; ++i) {\r\n    if (s[i] == ',') {\r\n      isa = false;\r\n      continue;\r\
    \n    }\r\n    auto& x = ((isa) ? a : b);\r\n    x = 10 * x + (s[i] - '0');\r\n\
    \  }\r\n  return std::make_pair(a, b);\r\n}\r\n\r\nsigned main() {\r\n  std::cin.tie(0);\r\
    \n  std::ios::sync_with_stdio(0);\r\n\r\n  auto [t] = mtd::io::in<int>();\r\n\r\
    \n  constexpr long long MOD = 1e9 + 7;\r\n  using mint = mtd::ModInt<MOD>;\r\n\
    \  auto math = mtd::Math<mint>();\r\n  for (auto [s] : mtd::views::istream<std::string>(t))\
    \ {\r\n    auto [n, k] = parse(s);\r\n    if (s[0] == 'C') {\r\n      std::cout\
    \ << math.comb(n, k) << std::endl;\r\n    } else if (s[0] == 'P') {\r\n      std::cout\
    \ << math.perm(n, k) << std::endl;\r\n    } else {\r\n      std::cout << math.comb(std::max(0LL,\
    \ n + k - 1), k) << std::endl;\r\n    }\r\n  }\r\n}\r\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/117\"\r\n\r\n#include\
    \ <iostream>\r\n#include <string>\r\n\r\n// begin:tag includes\r\n#include \"\
    ../../Library/Math/ModInt.hpp\"\r\n#include \"../../Library/Range/istream.hpp\"\
    \r\n// end:tag includes\r\n\r\nauto parse(const std::string s) {\r\n  long long\
    \ a = 0, b = 0;\r\n  bool isa = true;\r\n  for (unsigned int i = 2; i < s.size()\
    \ - 1; ++i) {\r\n    if (s[i] == ',') {\r\n      isa = false;\r\n      continue;\r\
    \n    }\r\n    auto& x = ((isa) ? a : b);\r\n    x = 10 * x + (s[i] - '0');\r\n\
    \  }\r\n  return std::make_pair(a, b);\r\n}\r\n\r\nsigned main() {\r\n  std::cin.tie(0);\r\
    \n  std::ios::sync_with_stdio(0);\r\n\r\n  auto [t] = mtd::io::in<int>();\r\n\r\
    \n  constexpr long long MOD = 1e9 + 7;\r\n  using mint = mtd::ModInt<MOD>;\r\n\
    \  auto math = mtd::Math<mint>();\r\n  for (auto [s] : mtd::views::istream<std::string>(t))\
    \ {\r\n    auto [n, k] = parse(s);\r\n    if (s[0] == 'C') {\r\n      std::cout\
    \ << math.comb(n, k) << std::endl;\r\n    } else if (s[0] == 'P') {\r\n      std::cout\
    \ << math.perm(n, k) << std::endl;\r\n    } else {\r\n      std::cout << math.comb(std::max(0LL,\
    \ n + k - 1), k) << std::endl;\r\n    }\r\n  }\r\n}\r\n"
  dependsOn:
  - Library/Math/ModInt.hpp
  - Library/Math/Math.hpp
  - Library/Range/istream.hpp
  - Library/Utility/io.hpp
  - Library/Debug/Dump.hpp
  - Library/Utility/Tuple.hpp
  isVerificationFile: true
  path: Test/Math/Math.test.cpp
  requiredBy: []
  timestamp: '2024-12-18 00:20:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Math/Math.test.cpp
layout: document
redirect_from:
- /verify/Test/Math/Math.test.cpp
- /verify/Test/Math/Math.test.cpp.html
title: Test/Math/Math.test.cpp
---
