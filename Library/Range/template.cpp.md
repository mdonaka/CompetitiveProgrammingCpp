---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Library/Range/bit.hpp
    title: Library/Range/bit.hpp
  - icon: ':x:'
    path: Library/Range/check.hpp
    title: Library/Range/check.hpp
  - icon: ':warning:'
    path: Library/Range/istream.hpp
    title: Library/Range/istream.hpp
  - icon: ':x:'
    path: Library/Range/util.hpp
    title: Library/Range/util.hpp
  - icon: ':x:'
    path: Library/Utility/io.hpp
    title: Library/Utility/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Range/bit.hpp\"\n\n#include <ranges>\n\nnamespace\
    \ mtd {\n  namespace ranges {\n    struct bit_index_view : public std::ranges::view_interface<bit_index_view>\
    \ {\n      class iterator {\n        int i;\n        int bit;\n\n        unsigned\
    \ ctz(unsigned int n) {\n          if (!n) return -1;\n          unsigned int\
    \ c = 32;\n          n &= -static_cast<signed int>(n);\n          if (n) c--;\n\
    \          if (n & 0x0000FFFF) c -= 16;\n          if (n & 0x00FF00FF) c -= 8;\n\
    \          if (n & 0x0F0F0F0F) c -= 4;\n          if (n & 0x33333333) c -= 2;\n\
    \          if (n & 0x55555555) c -= 1;\n          return c;\n        }\n\n   \
    \   public:\n        using difference_type = int;\n        using value_type =\
    \ int;\n        using iterator_concept = std::forward_iterator_tag;\n\n      \
    \  explicit iterator(int bit = 0) : i(ctz(bit)), bit(bit) {}\n        auto operator*()\
    \ const { return i; }\n        auto &operator++() {\n          bit ^= (1 << i);\n\
    \          i = ctz(bit);\n          return *this;\n        }\n        auto operator++(int)\
    \ { return ++*this; }\n        auto operator==(const iterator &other) const {\n\
    \          return bit == other.bit;\n        }\n      };\n\n      int bit;\n\n\
    \      explicit bit_index_view(int bit) : bit(bit) {}\n      auto begin() const\
    \ { return iterator(bit); }\n      auto end() const { return iterator(); }\n \
    \   };\n\n    struct bit_subset_view\n        : public std::ranges::view_interface<bit_subset_view>\
    \ {\n      class iterator {\n        int i;\n        int bit;\n\n      public:\n\
    \        using difference_type = int;\n        using value_type = int;\n     \
    \   using iterator_concept = std::bidirectional_iterator_tag;\n\n        explicit\
    \ iterator(int bit = 0) : i(bit), bit(bit) {}\n        auto operator*() const\
    \ { return i; }\n        auto &operator++() {\n          i = (i - 1) & bit;\n\
    \          return *this;\n        }\n        auto operator++(int) { return ++*this;\
    \ }\n        auto operator==(const iterator &other) const { return i == other.i;\
    \ }\n      };\n\n      int bit;\n\n      explicit bit_subset_view(int bit) : bit(bit)\
    \ {}\n      auto begin() const { return iterator(bit); }\n      auto end() const\
    \ { return iterator(); }\n    };\n\n    struct bit_supset_view\n        : public\
    \ std::ranges::view_interface<bit_supset_view> {\n      class iterator {\n   \
    \     int i;\n        int bit;\n        int n;\n\n      public:\n        using\
    \ difference_type = int;\n        using value_type = int;\n        using iterator_concept\
    \ = std::bidirectional_iterator_tag;\n\n        explicit iterator(int bit = 0,\
    \ int n = 0) : i(bit), bit(bit), n(n) {}\n        auto operator*() const { return\
    \ i; }\n        auto &operator++() {\n          i = (i + 1) | bit;\n         \
    \ return *this;\n        }\n        auto operator++(int) { return ++*this; }\n\
    \        auto operator==(const std::default_sentinel_t &sentinel) const {\n  \
    \        return i >= (1 << n);\n        }\n      };\n\n      int bit;\n      int\
    \ n;\n\n      explicit bit_supset_view(int bit, int n) : bit(bit), n(n) {}\n \
    \     auto begin() const { return iterator(bit, n); }\n      auto end() const\
    \ { return std::default_sentinel; }\n    };\n\n    struct k_bit_subset_view\n\
    \        : public std::ranges::view_interface<k_bit_subset_view> {\n      class\
    \ iterator {\n        int i;\n        int n;\n\n      public:\n        using difference_type\
    \ = int;\n        using value_type = int;\n        using iterator_concept = std::bidirectional_iterator_tag;\n\
    \n        explicit iterator(int n = 0, int k = 0) : i((1 << k) - 1), n(n) {}\n\
    \        auto operator*() const { return i; }\n        auto &operator++() {\n\
    \          int x = i & -i;\n          int y = i + x;\n          i = (((i & ~y)\
    \ / x) >> 1) | y;\n          return *this;\n        }\n        auto operator++(int)\
    \ { return ++*this; }\n        auto operator==(const std::default_sentinel_t &sentinel)\
    \ const {\n          return i >= (1 << n);\n        }\n      };\n\n      int n,\
    \ k;\n\n      explicit k_bit_subset_view(int n, int k) : n(n), k(k) {}\n     \
    \ auto begin() const { return iterator(n, k); }\n      auto end() const { return\
    \ std::default_sentinel; }\n    };\n  }  // namespace ranges\n\n  namespace views\
    \ {\n    namespace __detail {\n      template <typename... _Args>\n      concept\
    \ __can_bit_index_view = requires {\n        ranges::bit_index_view(std::declval<_Args>()...);\n\
    \      };\n      template <typename... _Args>\n      concept __can_bit_subset_view\
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
    \ views\n\n}  // namespace mtd\n#line 2 \"Library/Range/check.hpp\"\n\n#include\
    \ <algorithm>\n#include <concepts>\n#include <iomanip>\n#include <iostream>\n\
    #line 8 \"Library/Range/check.hpp\"\n#include <string>\n#include <vector>\n\n\
    namespace mtd::check {\n  class Table {\n    std::string title;\n    std::vector<std::pair<std::string,\
    \ bool>> table;\n\n  public:\n    Table(const std::string& title) : title(title)\
    \ {}\n\n    auto add(const std::string& name, bool b) { table.emplace_back(name,\
    \ b); }\n    auto print() const {\n      auto size = std::ranges::max(\n     \
    \     table |\n          std::views::transform([](const std::pair<std::string,\
    \ bool>& p) {\n            return p.first.size();\n          }));\n\n      //\
    \ std::cout << std::string(size + 12, '_') << std::endl;\n      std::cout << \"\
    |\" << std::string(size + 10, '-') << \"|\" << std::endl;\n      std::cout <<\
    \ \"| \" << title << std::string(size + 9 - title.size(), ' ')\n             \
    \   << \"|\" << std::endl;\n      std::cout << \"|\" << std::string(size + 10,\
    \ '-') << \"|\" << std::endl;\n      for (const auto& [s, b] : table) {\n    \
    \    std::cout << \"| \" << std::left << std::setw(size) << s << \" | \"\n   \
    \               << (b ? \"True \" : \"False\") << \" |\" << std::endl;\n     \
    \ }\n      std::cout << \"|\" << std::string(size + 10, '_') << \"|\" << std::endl;\n\
    \    }\n  };\n\n  template <class T>\n  auto range() {\n    using iterator = std::ranges::iterator_t<T>;\n\
    \    using sentinel = std::ranges::sentinel_t<T>;\n\n    auto table = Table(\"\
    range\");\n    table.add(\"weakly-equality-comparable-with\",\n              std::__detail::__weakly_eq_cmp_with<iterator,\
    \ sentinel>);\n\n    table.add(\"default_initializable\", std::default_initializable<iterator>);\n\
    \    table.add(\"copyable\", std::copyable<sentinel>);\n    table.add(\"semiregular\"\
    , std::semiregular<sentinel>);\n    table.add(\"sentinel_for\", std::sentinel_for<sentinel,\
    \ iterator>);\n    table.add(\"range\", std::ranges::range<T>);\n    table.print();\n\
    \  }\n\n  template <class T>\n  auto input_range() {\n    using iterator = std::ranges::iterator_t<T>;\n\
    \n    auto table = Table(\"input_range\");\n    table.add(\"weakly_incrementable\"\
    , std::weakly_incrementable<iterator>);\n    table.add(\"input_or_output_iterator\"\
    ,\n              std::input_or_output_iterator<iterator>);\n    table.add(\"indirectly_readable\"\
    , std::indirectly_readable<iterator>);\n    table.add(\"input_iterator\", std::input_iterator<iterator>);\n\
    \    table.add(\"input_range\", std::ranges::input_range<T>);\n    table.print();\n\
    \  }\n\n  template <class T>\n  auto forward_range() {\n    using iterator = std::ranges::iterator_t<T>;\n\
    \n    auto table = Table(\"forward_range\");\n    table.add(\"incrementable\"\
    , std::incrementable<iterator>);\n    table.add(\"sentinel_for\", std::sentinel_for<iterator,\
    \ iterator>);\n    table.add(\"forward_range\", std::ranges::forward_range<T>);\n\
    \    table.print();\n  }\n\n  template <class T>\n  auto bidirectional_range()\
    \ {\n    using iterator = std::ranges::iterator_t<T>;\n\n    auto table = Table(\"\
    bidirectional_range\");\n    table.add(\n        \"decrementable\", requires(iterator\
    \ t) {\n          { --t } -> std::same_as<iterator&>;\n          { t-- } -> std::same_as<iterator>;\n\
    \        });\n    table.add(\"bidirectional_range\", std::ranges::bidirectional_range<T>);\n\
    \    table.print();\n  }\n\n  template <class T>\n  auto random_access_range()\
    \ {\n    using iterator = std::ranges::iterator_t<T>;\n\n    auto table = Table(\"\
    random_access_range\");\n    table.add(\"totally_ordered\", std::totally_ordered<iterator>);\n\
    \    table.add(\"sized_sentinel_for\",\n              std::sized_sentinel_for<iterator,\
    \ iterator>);\n\n    table.add(\n        \"plus\", requires(iterator i, const\
    \ iterator j,\n                         const std::iter_difference_t<iterator>\
    \ n) {\n          { i += n } -> std::same_as<iterator&>;\n          { j + n }\
    \ -> std::same_as<iterator>;\n          { n + j } -> std::same_as<iterator>;\n\
    \        });\n    table.add(\n        \"minus\", requires(iterator i, const iterator\
    \ j,\n                          const std::iter_difference_t<iterator> n) {\n\
    \          { i -= n } -> std::same_as<iterator&>;\n          { j - n } -> std::same_as<iterator>;\n\
    \        });\n    table.add(\n        \"access\",\n        requires(const iterator\
    \ j, const std::iter_difference_t<iterator> n) {\n          { j[n] } -> std::same_as<std::iter_reference_t<iterator>>;\n\
    \        });\n    table.add(\"random_access_range\", std::ranges::random_access_range<T>);\n\
    \    table.print();\n  }\n\n  template <class T>\n  auto view() {\n    auto table\
    \ = Table(\"view\");\n    table.add(\"object_v\", std::is_object_v<T>);\n    table.add(\"\
    move_constructible\", std::move_constructible<T>);\n    table.add(\"assignable_from\"\
    , std::assignable_from<T&, T>);\n    table.add(\"swappable\", std::swappable<T>);\n\
    \    table.add(\"movable\", std::movable<T>);\n    // table.add(\"derived_from\"\
    , std::derived_from<T, std::ranges::view_base>);\n    table.add(\"enable_view\"\
    , std::ranges::enable_view<T>);\n    table.add(\"view\", std::ranges::view<T>);\n\
    \    table.add(\"viewable_range\", std::ranges::viewable_range<T>);\n    table.print();\n\
    \  }\n\n  template <class T>\n  auto all() {\n    range<T>();\n    input_range<T>();\n\
    \    forward_range<T>();\n    bidirectional_range<T>();\n    random_access_range<T>();\n\
    \    view<T>();\n  }\n\n}  // namespace mtd::check\n#line 2 \"Library/Range/istream.hpp\"\
    \n\n#line 4 \"Library/Range/istream.hpp\"\n\n#line 2 \"Library/Utility/io.hpp\"\
    \n\n#line 5 \"Library/Utility/io.hpp\"\n#include <type_traits>\n#line 7 \"Library/Utility/io.hpp\"\
    \n\nnamespace mtd {\n  namespace io {\n\n    namespace type {\n      template\
    \ <class T, int Pre = 1, int Size = 0>\n      struct vec {\n        using value_type\
    \ = T;\n        static constexpr int pre = Pre;\n        static constexpr int\
    \ size = Size;\n      };\n      template <class T>\n      concept is_vec = requires\
    \ {\n        std::is_same_v<T, vec<typename T::value_type, T::pre, T::size>>;\n\
    \      };\n    }  // namespace type\n\n    template <type::is_vec T>\n    auto\
    \ _input(int n) {\n      std::vector<typename T::value_type> v(n);\n      for\
    \ (auto i : std::views::iota(0, n)) { std::cin >> v[i]; }\n      return v;\n \
    \   }\n\n    template <class T>\n    auto _input() {\n      T x;\n      std::cin\
    \ >> x;\n      return x;\n    }\n\n    template <int N, class Tuple, class T,\
    \ class... Args>\n    auto _tuple_input(Tuple& t) {\n      if constexpr (type::is_vec<T>)\
    \ {\n        if constexpr (T::size == 0) {\n          std::get<N>(t) = _input<T>(std::get<N\
    \ - T::pre>(t));\n        } else {\n          std::get<N>(t) = _input<T>(T::size);\n\
    \        }\n      } else {\n        std::get<N>(t) = _input<T>();\n      }\n \
    \     if constexpr (sizeof...(Args) > 0) {\n        _tuple_input<N + 1, Tuple,\
    \ Args...>(t);\n      }\n    }\n\n    template <class T>\n    struct _Converter\
    \ {\n      using type = T;\n    };\n    template <class T, int Pre, int Size>\n\
    \    struct _Converter<type::vec<T, Pre, Size>> {\n      using type = std::vector<T>;\n\
    \    };\n\n    template <class... Args>\n    auto in() {\n      auto base = std::tuple<typename\
    \ _Converter<Args>::type...>();\n      _tuple_input<0, decltype(base), Args...>(base);\n\
    \      return base;\n    }\n\n  }  // namespace io\n\n}  // namespace mtd\n#line\
    \ 6 \"Library/Range/istream.hpp\"\n\nnamespace mtd {\n  namespace ranges {\n\n\
    \    constexpr int _inf = 1e9;\n\n    template <class... Args>\n    struct istream_view\n\
    \        : public std::ranges::view_interface<istream_view<Args...>> {\n     \
    \ class iterator {\n        int count;\n        std::tuple<typename io::_Converter<Args>::type...>\
    \ val;\n\n      public:\n        using difference_type = int;\n        using value_type\
    \ = decltype(val);\n        using iterator_concept = std::input_iterator_tag;\n\
    \n        explicit iterator(int count = 0) : count(count) { operator++(); }\n\n\
    \        auto operator*() const { return val; }\n        auto& operator++() {\n\
    \          --count;\n          if (count >= 0) { val = io::in<Args...>(); }\n\
    \          return *this;\n        }\n        auto operator++(int) { return ++*this;\
    \ }\n\n        auto operator==(std::default_sentinel_t s) const {\n          return\
    \ count < 0 || std::cin.eof() || std::cin.fail() ||\n                 std::cin.bad();\n\
    \        }\n        friend auto operator==(std::default_sentinel_t s, const iterator&\
    \ li) {\n          return li == s;\n        }\n      };\n\n      int count;\n\n\
    \    public:\n      constexpr explicit istream_view(int count) : count(count)\
    \ {}\n      constexpr explicit istream_view() : istream_view(_inf) {}\n      auto\
    \ begin() const { return iterator(count); }\n      auto end() const { return std::default_sentinel;\
    \ }\n    };\n  }  // namespace ranges\n\n  namespace views {\n    namespace __detail\
    \ {\n      template <typename... _Args>\n      concept __can_istream_view = requires\
    \ {\n        ranges::istream_view(std::declval<_Args>()...);\n      };\n    }\
    \  // namespace __detail\n\n    template <class... Args>\n    struct _Istream\
    \ {\n      template <class... _Tp>\n      requires __detail::__can_istream_view<_Tp...>\n\
    \      constexpr auto operator() [[nodiscard]] (_Tp&&... __e) const {\n      \
    \  return ranges::istream_view<Args...>(std::forward<_Tp>(__e)...);\n      }\n\
    \    };\n\n    template <class... Args>\n    inline constexpr _Istream<Args...>\
    \ istream{};\n  }  // namespace views\n\n}  // namespace mtd\n#line 2 \"Library/Range/util.hpp\"\
    \n\n#include <functional>\n#line 6 \"Library/Range/util.hpp\"\n\nnamespace mtd\
    \ {\n  namespace ranges {\n    template <std::ranges::range _Range>\n    struct\
    \ enumerate_view\n        : public std::ranges::view_interface<enumerate_view<_Range>>\
    \ {\n      struct iterator {\n        size_t index;\n        _Range::iterator\
    \ _M_current;\n\n        using difference_type = int;\n        // TODO: tuple\u304C\
    \u6E21\u3055\u308C\u305F\u6642\u306Bflat\u306B\u3059\u308B\n        using value_type\
    \ =\n            std::tuple<size_t, typename _Range::iterator::value_type>;\n\
    \        using iterator_concept =\n            std::ranges::iterator_t<_Range>::iterator_concept;\n\
    \n        explicit iterator(const typename _Range::iterator& _M_current =\n  \
    \                            typename _Range::iterator{},\n                  \
    \        size_t index = 0)\n            : index(index), _M_current(_M_current)\
    \ {}\n        auto operator*() const { return std::make_tuple(index, *_M_current);\
    \ }\n        auto& operator++() {\n          ++_M_current;\n          ++index;\n\
    \          return *this;\n        }\n        auto operator++(int) { return ++*this;\
    \ }\n        auto operator==(const iterator& other) const {\n          return\
    \ _M_current == other._M_current;\n        }\n        auto& operator--() requires\
    \ std::ranges::bidirectional_range<_Range> {\n          --_M_current;\n      \
    \    --index;\n          return *this;\n        }\n        auto operator--(int)\
    \ requires std::ranges::bidirectional_range<_Range> {\n          return --*this;\n\
    \        }\n        auto operator<=>(const iterator&)\n            const requires\
    \ std::ranges::random_access_range<_Range>\n        = default;\n        auto operator-(const\
    \ iterator& itr)\n            const requires std::ranges::random_access_range<_Range>\
    \ {\n          return _M_current - itr._M_current;\n        }\n        auto operator+(const\
    \ difference_type n)\n            const requires std::ranges::random_access_range<_Range>\
    \ {\n          return iterator(_M_current + n, index + n);\n        }\n      \
    \  auto& operator+=(const difference_type n) requires\n            std::ranges::random_access_range<_Range>\
    \ {\n          _M_current += n;\n          index += n;\n          return *this;\n\
    \        }\n        friend auto operator+(const difference_type n,\n         \
    \                     const iterator& itr) requires\n            std::ranges::random_access_range<_Range>\
    \ {\n          return itr + n;\n        }\n        auto operator-(const difference_type\
    \ n)\n            const requires std::ranges::random_access_range<_Range> {\n\
    \          return iterator(_M_current - n, index - n);\n        }\n        auto&\
    \ operator-=(const difference_type n) requires\n            std::ranges::random_access_range<_Range>\
    \ {\n          _M_current -= n;\n          index -= n;\n          return *this;\n\
    \        }\n        auto operator[](const difference_type n)\n            const\
    \ requires std::ranges::random_access_range<_Range> {\n          return std::make_tuple(index\
    \ + n, _M_current[n]);\n        }\n      };\n\n      class sentinel {\n      \
    \  std::ranges::sentinel_t<_Range> _M_end;\n\n      public:\n        constexpr\
    \ explicit sentinel(std::ranges::sentinel_t<_Range>&& __end)\n            : _M_end(std::forward<std::ranges::sentinel_t<_Range>>(__end))\
    \ {}\n\n        friend constexpr bool operator==(const iterator& __x,\n      \
    \                                   const sentinel& __y) {\n          return __x._M_current\
    \ == __y._M_end;\n        }\n      };\n\n      _Range __r = _Range();\n\n    \
    \  enumerate_view() requires std::default_initializable<_Range>\n      = default;\n\
    \      constexpr explicit enumerate_view(const _Range& __r) : __r(__r) {}\n\n\
    \      auto begin() { return iterator(__r.begin()); }\n      auto end() {\n  \
    \      if constexpr (requires() { iterator(__r.end()); }) {\n          return\
    \ iterator(__r.end());\n        } else {\n          return sentinel(__r.end());\n\
    \        }\n      }\n    };\n\n    namespace __detail {\n      template <class\
    \ F, class T>\n      constexpr auto __tuple_transform(F&& f, T&& t) {\n      \
    \  return std::apply(\n            [&]<class... Ts>(Ts&&... elems) {\n       \
    \       return std::tuple<std::invoke_result_t<F&, Ts>...>(\n                \
    \  std::invoke(f, std::forward<Ts>(elems))...);\n            },\n            std::forward<T>(t));\n\
    \      }\n      template <class F, class T>\n      constexpr auto __tuple_for_each(F&&\
    \ f, T&& t) {\n        std::apply(\n            [&]<class... Ts>(Ts&&... elems)\
    \ {\n              (std::invoke(f, std::forward<Ts>(elems)), ...);\n         \
    \   },\n            std::forward<T>(t));\n      }\n    }  // namespace __detail\n\
    \n    template <std::ranges::range... _Range>\n    struct zip_view : public std::ranges::view_interface<zip_view<_Range...>>\
    \ {\n      struct iterator {\n      public:\n        std::tuple<std::ranges::iterator_t<_Range>...>\
    \ _M_current;\n\n        using difference_type = int;\n        using value_type\
    \ = std::tuple<\n            std::iter_reference_t<std::ranges::iterator_t<_Range>>...>;\n\
    \        using iterator_concept = std::input_iterator_tag;\n        // std::ranges::iterator_t<_Range>::iterator_concept;\n\
    \n        constexpr explicit iterator(const decltype(_M_current)& __current)\n\
    \            : _M_current(__current) {}\n        auto operator*() const {\n  \
    \        return __detail::__tuple_transform([](auto& __i) { return *__i; },\n\
    \                                             _M_current);\n        }\n      \
    \  auto& operator++() {\n          __detail::__tuple_for_each([](auto& __i) {\
    \ ++__i; }, _M_current);\n          return *this;\n        }\n        auto operator++(int)\
    \ { return ++*this; }\n        auto operator==(const iterator& other) const {\n\
    \          return _M_current == other._M_current;\n        }\n        // auto&\
    \ operator--() requires std::ranges::bidirectional_range<_Range>\n        // {\n\
    \        //   --_M_current;\n        //   --index;\n        //   return *this;\n\
    \        // }\n        // auto operator--(int) requires\n        // std::ranges::bidirectional_range<_Range>\
    \ {\n        //   return --*this;\n        // }\n        // auto operator<=>(const\
    \ iterator&)\n        //     const requires std::ranges::random_access_range<_Range>\n\
    \        // = default;\n        // auto operator-(const iterator& itr)\n     \
    \   //     const requires std::ranges::random_access_range<_Range> {\n       \
    \ //   return _M_current - itr._M_current;\n        // }\n        // auto operator+(const\
    \ difference_type n)\n        //     const requires std::ranges::random_access_range<_Range>\
    \ {\n        //   return iterator(_M_current + n, index + n);\n        // }\n\
    \        // auto& operator+=(const difference_type n) requires\n        //   \
    \  std::ranges::random_access_range<_Range> {\n        //   _M_current += n;\n\
    \        //   index += n;\n        //   return *this;\n        // }\n        //\
    \ friend auto operator+(const difference_type n,\n        //                 \
    \      const iterator& itr) requires\n        //     std::ranges::random_access_range<_Range>\
    \ {\n        //   return itr + n;\n        // }\n        // auto operator-(const\
    \ difference_type n)\n        //     const requires std::ranges::random_access_range<_Range>\
    \ {\n        //   return iterator(_M_current - n, index - n);\n        // }\n\
    \        // auto& operator-=(const difference_type n) requires\n        //   \
    \  std::ranges::random_access_range<_Range> {\n        //   _M_current -= n;\n\
    \        //   index -= n;\n        //   return *this;\n        // }\n        //\
    \ auto operator[](const difference_type n)\n        //     const requires std::ranges::random_access_range<_Range>\
    \ {\n        //   return std::make_tuple(index + n, _M_current[n]);\n        //\
    \ }\n      };\n\n      class sentinel {\n      public:\n        std::tuple<std::ranges::sentinel_t<_Range>...>\
    \ _M_end;\n\n      public:\n        constexpr explicit sentinel(const decltype(_M_end)&\
    \ __end)\n            : _M_end(__end) {}\n\n        friend constexpr bool operator==(const\
    \ iterator& __x,\n                                         const sentinel& __y)\
    \ {\n          return __x._M_current == __y._M_end;\n        }\n      };\n\n \
    \     std::tuple<_Range...> __r;\n      constexpr explicit zip_view(const _Range&...\
    \ __r) : __r(__r...) {}\n      auto begin() {\n        return iterator(__detail::__tuple_transform(std::ranges::begin,\
    \ __r));\n      }\n      auto end() {\n        return sentinel(__detail::__tuple_transform(std::ranges::end,\
    \ __r));\n      }\n    };\n  }  // namespace ranges\n\n  namespace views {\n \
    \   struct _Enumerate : std::views::__adaptor::_RangeAdaptorClosure {\n      template\
    \ <std::ranges::viewable_range _Range>\n      constexpr auto operator()(_Range&&\
    \ __r) const {\n        return ranges::enumerate_view{std::forward<_Range>(__r)};\n\
    \      }\n      static constexpr bool _S_has_simple_call_op = true;\n    };\n\n\
    \    inline constexpr _Enumerate enumerate{};\n  }  // namespace views\n}  //\
    \ namespace mtd\n#line 5 \"Library/Range/template.cpp\"\n\nnamespace mtd {\n \
    \ namespace ranges {\n    struct input_range_template_view\n        : public std::ranges::view_interface<input_range_template_view>\
    \ {\n      class iterator {\n        int i;\n\n      public:\n        using difference_type\
    \ = int;\n        using value_type = int;\n        using iterator_concept = std::input_iterator_tag;\n\
    \n        explicit iterator(int i = 0) : i(i) {}\n        auto operator*() const\
    \ { return i; }\n        auto &operator++() {\n          ++i;\n          return\
    \ *this;\n        }\n        auto operator++(int) { return ++*this; }\n      \
    \  auto operator==(const iterator &sentinel) const {\n          return i == sentinel.i;\n\
    \        }\n      };\n\n      int n;\n\n      explicit input_range_template_view(int\
    \ n) : n(n) {}\n      auto begin() const { return iterator(0); }\n      auto end()\
    \ const { return iterator(n); }\n    };\n\n    struct forward_range_template_view\n\
    \        : public std::ranges::view_interface<forward_range_template_view> {\n\
    \      class iterator {\n        int i;\n\n      public:\n        using difference_type\
    \ = int;\n        using value_type = int;\n        using iterator_concept = std::forward_iterator_tag;\n\
    \n        explicit iterator(int i = 0) : i(i) {}\n        auto operator*() const\
    \ { return i; }\n        auto &operator++() {\n          ++i;\n          return\
    \ *this;\n        }\n        auto operator++(int) { return ++*this; }\n      \
    \  auto operator==(const iterator &sentinel) const {\n          return i == sentinel.i;\n\
    \        }\n      };\n\n      int n;\n\n      explicit forward_range_template_view(int\
    \ n) : n(n) {}\n      auto begin() const { return iterator(0); }\n      auto end()\
    \ const { return iterator(n); }\n    };\n\n    struct bidirectional_range_template_view\n\
    \        : public std::ranges::view_interface<\n              bidirectional_range_template_view>\
    \ {\n      class iterator {\n        int i;\n\n      public:\n        using difference_type\
    \ = int;\n        using value_type = int;\n        using iterator_concept = std::bidirectional_iterator_tag;\n\
    \n        explicit iterator(int i = 0) : i(i) {}\n        auto operator*() const\
    \ { return i; }\n        auto &operator++() {\n          ++i;\n          return\
    \ *this;\n        }\n        auto operator++(int) { return ++*this; }\n      \
    \  auto &operator--() {\n          --i;\n          return *this;\n        }\n\
    \        auto operator--(int) { return --*this; }\n        auto operator==(const\
    \ iterator &sentinel) const {\n          return i == sentinel.i;\n        }\n\
    \      };\n\n      int n;\n\n      explicit bidirectional_range_template_view(int\
    \ n) : n(n) {}\n      auto begin() const { return iterator(0); }\n      auto end()\
    \ const { return iterator(n); }\n    };\n\n    struct random_access_range_template_view\n\
    \        : public std::ranges::view_interface<\n              random_access_range_template_view>\
    \ {\n      class iterator {\n        int i;\n\n      public:\n        using difference_type\
    \ = int;\n        using value_type = int;\n        using iterator_concept = std::random_access_iterator_tag;\n\
    \n        explicit iterator(int i = 0) : i(i) {}\n        auto operator*() const\
    \ { return i; }\n        auto &operator++() {\n          ++i;\n          return\
    \ *this;\n        }\n        auto operator++(int) { return ++*this; }\n      \
    \  auto &operator--() {\n          --i;\n          return *this;\n        }\n\
    \        auto operator--(int) { return --*this; }\n        auto operator==(const\
    \ iterator &sentinel) const {\n          return i == sentinel.i;\n        }\n\
    \        auto operator<=>(const iterator &) const = default;\n        auto operator-(const\
    \ iterator &itr) const { return i - itr.i; }\n        auto operator+(const difference_type\
    \ n) const {\n          return iterator(i + n);\n        }\n        auto &operator+=(const\
    \ difference_type n) {\n          i += n;\n          return *this;\n        }\n\
    \        friend auto operator+(const difference_type n, const iterator &itr) {\n\
    \          return itr + n;\n        }\n        auto operator-(const difference_type\
    \ n) const {\n          return iterator(i - n);\n        }\n        auto &operator-=(const\
    \ difference_type n) {\n          i -= n;\n          return *this;\n        }\n\
    \        auto operator[](const difference_type n) const { return i + n; }\n  \
    \    };\n\n      int n;\n\n      explicit random_access_range_template_view(int\
    \ n) : n(n) {}\n      auto begin() const { return iterator(0); }\n      auto end()\
    \ const { return iterator(n); }\n    };\n\n  }  // namespace ranges\n}  // namespace\
    \ mtd\n\nint main() {\n  // template\n  // mtd::check::all<mtd::ranges::input_range_template_view>();\n\
    \  // mtd::check::all<mtd::ranges::forward_range_template_view>();\n  // mtd::check::all<mtd::ranges::bidirectional_range_template_view>();\n\
    \  // mtd::check::all<mtd::ranges::random_access_range_template_view>();\n\n \
    \ // bit\n  // mtd::check::all<mtd::ranges::bit_index_view>();\n  // mtd::check::all<mtd::ranges::bit_subset_view>();\n\
    \  // mtd::check::all<mtd::ranges::bit_supset_view>();\n  // mtd::check::all<mtd::ranges::k_bit_subset_view>();\n\
    \n  // util\n  // mtd::check::all<\n  //     mtd::ranges::enumerate_view<mtd::ranges::input_range_template_view>>();\n\
    \  // mtd::check::all<mtd::ranges::enumerate_view<\n  //     mtd::ranges::bidirectional_range_template_view>>();\n\
    \  // mtd::check::all<mtd::ranges::enumerate_view<\n  //     mtd::ranges::random_access_range_template_view>>();\n\
    \  // mtd::check::all<\n  //     mtd::ranges::zip_view<mtd::ranges::input_range_template_view,\n\
    \  //                           mtd::ranges::input_range_template_view>>();\n\n\
    \  // istream\n  // mtd::check::all<mtd::ranges::k_bit_subset_view>();\n}\n"
  code: "#include \"./bit.hpp\"\n#include \"./check.hpp\"\n#include \"./istream.hpp\"\
    \n#include \"./util.hpp\"\n\nnamespace mtd {\n  namespace ranges {\n    struct\
    \ input_range_template_view\n        : public std::ranges::view_interface<input_range_template_view>\
    \ {\n      class iterator {\n        int i;\n\n      public:\n        using difference_type\
    \ = int;\n        using value_type = int;\n        using iterator_concept = std::input_iterator_tag;\n\
    \n        explicit iterator(int i = 0) : i(i) {}\n        auto operator*() const\
    \ { return i; }\n        auto &operator++() {\n          ++i;\n          return\
    \ *this;\n        }\n        auto operator++(int) { return ++*this; }\n      \
    \  auto operator==(const iterator &sentinel) const {\n          return i == sentinel.i;\n\
    \        }\n      };\n\n      int n;\n\n      explicit input_range_template_view(int\
    \ n) : n(n) {}\n      auto begin() const { return iterator(0); }\n      auto end()\
    \ const { return iterator(n); }\n    };\n\n    struct forward_range_template_view\n\
    \        : public std::ranges::view_interface<forward_range_template_view> {\n\
    \      class iterator {\n        int i;\n\n      public:\n        using difference_type\
    \ = int;\n        using value_type = int;\n        using iterator_concept = std::forward_iterator_tag;\n\
    \n        explicit iterator(int i = 0) : i(i) {}\n        auto operator*() const\
    \ { return i; }\n        auto &operator++() {\n          ++i;\n          return\
    \ *this;\n        }\n        auto operator++(int) { return ++*this; }\n      \
    \  auto operator==(const iterator &sentinel) const {\n          return i == sentinel.i;\n\
    \        }\n      };\n\n      int n;\n\n      explicit forward_range_template_view(int\
    \ n) : n(n) {}\n      auto begin() const { return iterator(0); }\n      auto end()\
    \ const { return iterator(n); }\n    };\n\n    struct bidirectional_range_template_view\n\
    \        : public std::ranges::view_interface<\n              bidirectional_range_template_view>\
    \ {\n      class iterator {\n        int i;\n\n      public:\n        using difference_type\
    \ = int;\n        using value_type = int;\n        using iterator_concept = std::bidirectional_iterator_tag;\n\
    \n        explicit iterator(int i = 0) : i(i) {}\n        auto operator*() const\
    \ { return i; }\n        auto &operator++() {\n          ++i;\n          return\
    \ *this;\n        }\n        auto operator++(int) { return ++*this; }\n      \
    \  auto &operator--() {\n          --i;\n          return *this;\n        }\n\
    \        auto operator--(int) { return --*this; }\n        auto operator==(const\
    \ iterator &sentinel) const {\n          return i == sentinel.i;\n        }\n\
    \      };\n\n      int n;\n\n      explicit bidirectional_range_template_view(int\
    \ n) : n(n) {}\n      auto begin() const { return iterator(0); }\n      auto end()\
    \ const { return iterator(n); }\n    };\n\n    struct random_access_range_template_view\n\
    \        : public std::ranges::view_interface<\n              random_access_range_template_view>\
    \ {\n      class iterator {\n        int i;\n\n      public:\n        using difference_type\
    \ = int;\n        using value_type = int;\n        using iterator_concept = std::random_access_iterator_tag;\n\
    \n        explicit iterator(int i = 0) : i(i) {}\n        auto operator*() const\
    \ { return i; }\n        auto &operator++() {\n          ++i;\n          return\
    \ *this;\n        }\n        auto operator++(int) { return ++*this; }\n      \
    \  auto &operator--() {\n          --i;\n          return *this;\n        }\n\
    \        auto operator--(int) { return --*this; }\n        auto operator==(const\
    \ iterator &sentinel) const {\n          return i == sentinel.i;\n        }\n\
    \        auto operator<=>(const iterator &) const = default;\n        auto operator-(const\
    \ iterator &itr) const { return i - itr.i; }\n        auto operator+(const difference_type\
    \ n) const {\n          return iterator(i + n);\n        }\n        auto &operator+=(const\
    \ difference_type n) {\n          i += n;\n          return *this;\n        }\n\
    \        friend auto operator+(const difference_type n, const iterator &itr) {\n\
    \          return itr + n;\n        }\n        auto operator-(const difference_type\
    \ n) const {\n          return iterator(i - n);\n        }\n        auto &operator-=(const\
    \ difference_type n) {\n          i -= n;\n          return *this;\n        }\n\
    \        auto operator[](const difference_type n) const { return i + n; }\n  \
    \    };\n\n      int n;\n\n      explicit random_access_range_template_view(int\
    \ n) : n(n) {}\n      auto begin() const { return iterator(0); }\n      auto end()\
    \ const { return iterator(n); }\n    };\n\n  }  // namespace ranges\n}  // namespace\
    \ mtd\n\nint main() {\n  // template\n  // mtd::check::all<mtd::ranges::input_range_template_view>();\n\
    \  // mtd::check::all<mtd::ranges::forward_range_template_view>();\n  // mtd::check::all<mtd::ranges::bidirectional_range_template_view>();\n\
    \  // mtd::check::all<mtd::ranges::random_access_range_template_view>();\n\n \
    \ // bit\n  // mtd::check::all<mtd::ranges::bit_index_view>();\n  // mtd::check::all<mtd::ranges::bit_subset_view>();\n\
    \  // mtd::check::all<mtd::ranges::bit_supset_view>();\n  // mtd::check::all<mtd::ranges::k_bit_subset_view>();\n\
    \n  // util\n  // mtd::check::all<\n  //     mtd::ranges::enumerate_view<mtd::ranges::input_range_template_view>>();\n\
    \  // mtd::check::all<mtd::ranges::enumerate_view<\n  //     mtd::ranges::bidirectional_range_template_view>>();\n\
    \  // mtd::check::all<mtd::ranges::enumerate_view<\n  //     mtd::ranges::random_access_range_template_view>>();\n\
    \  // mtd::check::all<\n  //     mtd::ranges::zip_view<mtd::ranges::input_range_template_view,\n\
    \  //                           mtd::ranges::input_range_template_view>>();\n\n\
    \  // istream\n  // mtd::check::all<mtd::ranges::k_bit_subset_view>();\n}\n"
  dependsOn:
  - Library/Range/bit.hpp
  - Library/Range/check.hpp
  - Library/Range/istream.hpp
  - Library/Utility/io.hpp
  - Library/Range/util.hpp
  isVerificationFile: false
  path: Library/Range/template.cpp
  requiredBy: []
  timestamp: '2024-08-24 17:51:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Range/template.cpp
layout: document
redirect_from:
- /library/Library/Range/template.cpp
- /library/Library/Range/template.cpp.html
title: Library/Range/template.cpp
---
