---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Math/Bit.hpp
    title: Library/Math/Bit.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Range/bit.hpp
    title: Library/Range/bit.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Utility/Tools.hpp
    title: Library/Utility/Tools.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/733
    links:
    - https://yukicoder.me/problems/no/733
  bundledCode: "#line 1 \"Test/Range/bit_subset.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/733\"\
    \n\n#include <iostream>\n#include <vector>\n\n// begin:tag includes\n#line 2 \"\
    Library/Range/bit.hpp\"\n\n#include <ranges>\n\n#line 2 \"Library/Math/Bit.hpp\"\
    \n\nnamespace mtd {\n\n  constexpr unsigned clz(unsigned int x) {\n    int c =\
    \ 0;\n    if (x == 0) { return 0; }\n    if (x & 0xffff0000) {\n      x &= 0xffff0000;\n\
    \      c |= 0x10;\n    }\n    if (x & 0xff00ff00) {\n      x &= 0xff00ff00;\n\
    \      c |= 0x08;\n    }\n    if (x & 0xf0f0f0f0) {\n      x &= 0xf0f0f0f0;\n\
    \      c |= 0x04;\n    }\n    if (x & 0xcccccccc) {\n      x &= 0xcccccccc;\n\
    \      c |= 0x02;\n    }\n    if (x & 0xaaaaaaaa) { c |= 0x01; }\n    return c\
    \ + 1;\n  }\n\n  constexpr unsigned ctz(unsigned int n) {\n    if (!n) return\
    \ -1;\n    unsigned int c = 32;\n    n &= -static_cast<signed int>(n);\n    if\
    \ (n) c--;\n    if (n & 0x0000FFFF) c -= 16;\n    if (n & 0x00FF00FF) c -= 8;\n\
    \    if (n & 0x0F0F0F0F) c -= 4;\n    if (n & 0x33333333) c -= 2;\n    if (n &\
    \ 0x55555555) c -= 1;\n    return c;\n  }\n\n  constexpr unsigned long long popcount(unsigned\
    \ long long x) {\n    x = x - ((x >> 1) & 0x5555555555555555);\n    x = (x & 0x3333333333333333)\
    \ + ((x >> 2) & 0x3333333333333333);\n    x = (x + (x >> 4)) & 0x0f0f0f0f0f0f0f0f;\n\
    \    x = x + (x >> 8);\n    x = x + (x >> 16);\n    x = x + (x >> 32);\n    return\
    \ x & 0x0000007f;\n  }\n\n}  // namespace mtd\n#line 6 \"Library/Range/bit.hpp\"\
    \n\nnamespace mtd {\n  namespace ranges {\n    struct bit_index_view : public\
    \ std::ranges::view_interface<bit_index_view> {\n      class iterator {\n    \
    \    int i;\n        int bit;\n\n      public:\n        using difference_type\
    \ = int;\n        using value_type = int;\n        using iterator_concept = std::forward_iterator_tag;\n\
    \n        constexpr iterator() = default;\n        constexpr explicit iterator(int\
    \ _bit) : i(ctz(_bit)), bit(_bit) {}\n        constexpr auto operator*() const\
    \ { return i; }\n        constexpr auto &operator++() {\n          bit ^= (1 <<\
    \ i);\n          i = ctz(bit);\n          return *this;\n        }\n        constexpr\
    \ auto operator++(int) { return ++*this; }\n        constexpr auto operator==(const\
    \ iterator &other) const {\n          return bit == other.bit;\n        }\n  \
    \    };\n\n      int bit;\n\n      constexpr explicit bit_index_view(int _bit)\
    \ : bit(_bit) {}\n      constexpr auto begin() const { return iterator(bit); }\n\
    \      constexpr auto end() const { return iterator(); }\n    };\n\n    struct\
    \ bit_subset_view\n        : public std::ranges::view_interface<bit_subset_view>\
    \ {\n      class iterator {\n        int i;\n        int bit;\n\n      public:\n\
    \        using difference_type = int;\n        using value_type = int;\n     \
    \   using iterator_concept = std::bidirectional_iterator_tag;\n\n        constexpr\
    \ iterator() = default;\n        constexpr explicit iterator(int _bit) : i(_bit),\
    \ bit(_bit) {}\n        constexpr auto operator*() const { return i; }\n     \
    \   constexpr auto &operator++() {\n          i = (i - 1) & bit;\n          return\
    \ *this;\n        }\n        constexpr auto operator++(int) { return ++*this;\
    \ }\n        constexpr auto operator==(const iterator &other) const {\n      \
    \    return i == other.i;\n        }\n      };\n\n      int bit;\n\n      constexpr\
    \ explicit bit_subset_view(int _bit) : bit(_bit) {}\n      constexpr auto begin()\
    \ const { return iterator(bit); }\n      constexpr auto end() const { return iterator();\
    \ }\n    };\n\n    struct bit_supset_view\n        : public std::ranges::view_interface<bit_supset_view>\
    \ {\n      class iterator {\n        int i;\n        int bit;\n        int n;\n\
    \n      public:\n        using difference_type = int;\n        using value_type\
    \ = int;\n        using iterator_concept = std::bidirectional_iterator_tag;\n\n\
    \        constexpr iterator() = default;\n        constexpr explicit iterator(int\
    \ _bit, int _n)\n            : i(_bit), bit(_bit), n(_n) {}\n        constexpr\
    \ auto operator*() const { return i; }\n        constexpr auto &operator++() {\n\
    \          i = (i + 1) | bit;\n          return *this;\n        }\n        constexpr\
    \ auto operator++(int) { return ++*this; }\n        constexpr auto operator==(const\
    \ iterator &other) const {\n          return i == other.i && bit == other.bit\
    \ && n == other.n;\n        }\n        constexpr auto operator==(const std::default_sentinel_t\
    \ &) const {\n          return i >= (1 << n);\n        }\n      };\n\n      int\
    \ bit;\n      int n;\n\n      constexpr explicit bit_supset_view(int _bit, int\
    \ _n) : bit(_bit), n(_n) {}\n      constexpr auto begin() const { return iterator(bit,\
    \ n); }\n      constexpr auto end() const { return std::default_sentinel; }\n\
    \    };\n\n    struct k_bit_subset_view\n        : public std::ranges::view_interface<k_bit_subset_view>\
    \ {\n      class iterator {\n        int i;\n        int n;\n\n      public:\n\
    \        using difference_type = int;\n        using value_type = int;\n     \
    \   using iterator_concept = std::bidirectional_iterator_tag;\n\n        constexpr\
    \ iterator() = default;\n        constexpr explicit iterator(int _n, int _k) :\
    \ i((1 << _k) - 1), n(_n) {}\n        constexpr auto operator*() const { return\
    \ i; }\n        constexpr auto &operator++() {\n          int x = i & -i;\n  \
    \        int y = i + x;\n          i = (((i & ~y) / x) >> 1) | y;\n          return\
    \ *this;\n        }\n        constexpr auto operator++(int) { return ++*this;\
    \ }\n        constexpr auto operator==(const iterator &other) const {\n      \
    \    return i == other.i && n == other.n;\n        }\n        constexpr auto operator==(const\
    \ std::default_sentinel_t &) const {\n          return i >= (1 << n);\n      \
    \  }\n      };\n\n      int n, k;\n      constexpr explicit k_bit_subset_view(int\
    \ _n, int _k) : n(_n), k(_k) {}\n      constexpr auto begin() const { return iterator(n,\
    \ k); }\n      constexpr auto end() const { return std::default_sentinel; }\n\
    \    };\n  }  // namespace ranges\n\n  namespace views {\n    namespace __detail\
    \ {\n      template <typename... _Args>\n      concept __can_bit_index_view =\
    \ requires {\n        ranges::bit_index_view(std::declval<_Args>()...);\n    \
    \  };\n      template <typename... _Args>\n      concept __can_bit_subset_view\
    \ = requires {\n        ranges::bit_subset_view(std::declval<_Args>()...);\n \
    \     };\n      template <typename... _Args>\n      concept __can_bit_supset_view\
    \ = requires {\n        ranges::bit_supset_view(std::declval<_Args>()...);\n \
    \     };\n      template <typename... _Args>\n      concept __can_k_bit_subset_view\
    \ = requires {\n        ranges::k_bit_subset_view(std::declval<_Args>()...);\n\
    \      };\n    }  // namespace __detail\n\n    struct _BitIndex {\n      template\
    \ <class... _Tp>\n      requires __detail::__can_bit_index_view<_Tp...>\n    \
    \  constexpr auto operator() [[nodiscard]] (_Tp &&...__e) const {\n        return\
    \ ranges::bit_index_view(std::forward<_Tp>(__e)...);\n      }\n    };\n    inline\
    \ constexpr _BitIndex bit_index{};\n\n    struct _BitSubsetView {\n      template\
    \ <class... _Tp>\n      requires __detail::__can_bit_subset_view<_Tp...>\n   \
    \   constexpr auto operator() [[nodiscard]] (_Tp &&...__e) const {\n        return\
    \ ranges::bit_subset_view(std::forward<_Tp>(__e)...);\n      }\n    };\n    inline\
    \ constexpr _BitSubsetView bit_subset{};\n\n    struct _BitSupsetView {\n    \
    \  template <class... _Tp>\n      requires __detail::__can_bit_supset_view<_Tp...>\n\
    \      constexpr auto operator() [[nodiscard]] (_Tp &&...__e) const {\n      \
    \  return ranges::bit_supset_view(std::forward<_Tp>(__e)...);\n      }\n    };\n\
    \    inline constexpr _BitSupsetView bit_supset{};\n\n    struct _KBitSubsetView\
    \ {\n      template <class... _Tp>\n      requires __detail::__can_k_bit_subset_view<_Tp...>\n\
    \      constexpr auto operator() [[nodiscard]] (_Tp &&...__e) const {\n      \
    \  return ranges::k_bit_subset_view(std::forward<_Tp>(__e)...);\n      }\n   \
    \ };\n    inline constexpr _KBitSubsetView k_bit_subset{};\n  }  // namespace\
    \ views\n\n}  // namespace mtd\n#line 2 \"Library/Utility/Tools.hpp\"\n\n#line\
    \ 4 \"Library/Utility/Tools.hpp\"\n\nnamespace mtd {\n\n  template <class T, class\
    \ S>\n  inline auto chmax(T& t, const S& s) {\n    if (s > t) {\n      t = s;\n\
    \      return true;\n    }\n    return false;\n  }\n\n  template <class T, class\
    \ S>\n  inline auto chmin(T& t, const S& s) {\n    if (s < t) {\n      t = s;\n\
    \      return true;\n    }\n    return false;\n  }\n\n  template <class S>\n \
    \ constexpr auto vec(S x) {\n    return x;\n  }\n\n  template <class S, class...\
    \ T>\n  constexpr auto vec(S x, int n, T... ns) {\n    return std::vector(n, vec(x,\
    \ ns...));\n  }\n\n}  // namespace mtd\n#line 9 \"Test/Range/bit_subset.test.cpp\"\
    \n// end:tag includes\n\nint main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(0);\n\
    \n  int t, n;\n  std::cin >> t >> n;\n  std::vector<int> a(n);\n  for (auto i\
    \ : std::views::iota(0, n)) { std::cin >> a[i]; }\n\n  auto sum = mtd::vec(0,\
    \ 1 << n);\n  for (auto bit : std::views::iota(1, 1 << n)) {\n    auto b = mtd::ctz(bit);\n\
    \    sum[bit] = (bit == (1 << b) ? 0 : sum[bit ^ (1 << b)]) + a[b];\n  }\n\n \
    \ auto dp = mtd::vec(n, 1 << n);\n  for (auto bit : std::views::iota(0, 1 << n))\
    \ {\n    if (sum[bit] <= t) { dp[bit] = 1; }\n  }\n  for (auto bit : std::views::iota(0,\
    \ 1 << n)) {\n    for (auto sub : mtd::views::bit_subset(bit)) {\n      mtd::chmin(dp[bit],\
    \ dp[sub] + dp[bit ^ sub]);\n    }\n  }\n  std::cout << dp[(1 << n) - 1] << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/733\"\n\n#include <iostream>\n\
    #include <vector>\n\n// begin:tag includes\n#include \"../../Library/Range/bit.hpp\"\
    \n#include \"../../Library/Utility/Tools.hpp\"\n// end:tag includes\n\nint main()\
    \ {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(0);\n\n  int t, n;\n  std::cin\
    \ >> t >> n;\n  std::vector<int> a(n);\n  for (auto i : std::views::iota(0, n))\
    \ { std::cin >> a[i]; }\n\n  auto sum = mtd::vec(0, 1 << n);\n  for (auto bit\
    \ : std::views::iota(1, 1 << n)) {\n    auto b = mtd::ctz(bit);\n    sum[bit]\
    \ = (bit == (1 << b) ? 0 : sum[bit ^ (1 << b)]) + a[b];\n  }\n\n  auto dp = mtd::vec(n,\
    \ 1 << n);\n  for (auto bit : std::views::iota(0, 1 << n)) {\n    if (sum[bit]\
    \ <= t) { dp[bit] = 1; }\n  }\n  for (auto bit : std::views::iota(0, 1 << n))\
    \ {\n    for (auto sub : mtd::views::bit_subset(bit)) {\n      mtd::chmin(dp[bit],\
    \ dp[sub] + dp[bit ^ sub]);\n    }\n  }\n  std::cout << dp[(1 << n) - 1] << std::endl;\n\
    }\n"
  dependsOn:
  - Library/Range/bit.hpp
  - Library/Math/Bit.hpp
  - Library/Utility/Tools.hpp
  isVerificationFile: true
  path: Test/Range/bit_subset.test.cpp
  requiredBy: []
  timestamp: '2024-12-27 17:07:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Range/bit_subset.test.cpp
layout: document
redirect_from:
- /verify/Test/Range/bit_subset.test.cpp
- /verify/Test/Range/bit_subset.test.cpp.html
title: Test/Range/bit_subset.test.cpp
---
