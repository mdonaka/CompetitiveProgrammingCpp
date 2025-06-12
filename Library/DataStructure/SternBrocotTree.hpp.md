---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Range/util.hpp
    title: Library/Range/util.hpp
  - icon: ':question:'
    path: Library/Utility/Tuple.hpp
    title: Library/Utility/Tuple.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/SternBrocotTree.test.cpp
    title: Test/DataStructure/SternBrocotTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/DataStructure/SternBrocotTree.hpp\"\n\n#include\
    \ <iostream>\n#include <numeric>\n#include <stdexcept>\n#include <tuple>\n#include\
    \ <vector>\n\n#line 2 \"Library/Range/util.hpp\"\n\n#include <algorithm>\n#line\
    \ 5 \"Library/Range/util.hpp\"\n#include <ranges>\n\n#line 2 \"Library/Utility/Tuple.hpp\"\
    \n\n#include <functional>\n\nnamespace mtd {\n  namespace util {\n    template\
    \ <class F, class T>\n    constexpr auto tuple_transform(F&& f, T&& t) {\n   \
    \   return std::apply(\n          [&]<class... Ts>(Ts&&... elems) {\n        \
    \    return std::tuple<std::invoke_result_t<F&, Ts>...>(\n                std::invoke(f,\
    \ std::forward<Ts>(elems))...);\n          },\n          std::forward<T>(t));\n\
    \    }\n    template <class F, class T>\n    constexpr auto tuple_for_each(F&&\
    \ f, T&& t) {\n      std::apply(\n          [&]<class... Ts>(Ts&&... elems) {\n\
    \            (std::invoke(f, std::forward<Ts>(elems)), ...);\n          },\n \
    \         std::forward<T>(t));\n    }\n  }  // namespace util\n}  // namespace\
    \ mtd\n#line 8 \"Library/Range/util.hpp\"\n\nnamespace mtd {\n  namespace ranges\
    \ {\n\n    namespace __detail {\n      template <typename... T>\n      concept\
    \ __all_random_access = (std::ranges::random_access_range<T> &&\n            \
    \                         ...);\n      template <typename... T>\n      concept\
    \ __all_bidirectional = (std::ranges::bidirectional_range<T> &&\n            \
    \                         ...);\n      template <typename... T>\n      concept\
    \ __all_forward = (std::ranges::forward_range<T> && ...);\n\n      template <class...\
    \ T>\n      constexpr auto _S_iter_concept() {\n        if constexpr (__all_random_access<T...>)\
    \ {\n          return std::random_access_iterator_tag{};\n        } else if constexpr\
    \ (__all_bidirectional<T...>) {\n          return std::bidirectional_iterator_tag{};\n\
    \        } else if constexpr (__all_forward<T...>) {\n          return std::forward_iterator_tag{};\n\
    \        } else {\n          return std::input_iterator_tag{};\n        }\n  \
    \    }\n    }  // namespace __detail\n\n    template <std::ranges::range... _Range>\n\
    \    struct zip_view : public std::ranges::view_interface<zip_view<_Range...>>\
    \ {\n      class iterator {\n      public:\n        std::tuple<std::ranges::iterator_t<_Range>...>\
    \ _M_current;\n\n        using difference_type = int;\n        using value_type\
    \ = std::tuple<\n            std::iter_reference_t<std::ranges::iterator_t<_Range>>...>;\n\
    \        using iterator_concept =\n            decltype(__detail::_S_iter_concept<_Range...>());\n\
    \n        constexpr iterator() = default;\n        constexpr explicit iterator(const\
    \ decltype(_M_current)& __current)\n            : _M_current(__current) {}\n \
    \       constexpr auto operator*() const {\n          return util::tuple_transform([](auto&\
    \ __i) { return *__i; },\n                                       _M_current);\n\
    \        }\n        constexpr auto& operator++() {\n          util::tuple_for_each([](auto&\
    \ __i) { ++__i; }, _M_current);\n          return *this;\n        }\n        constexpr\
    \ auto operator++(int) { return ++*this; }\n        constexpr auto operator==(const\
    \ iterator& other) const {\n          return [&]<size_t... _Is>(std::index_sequence<_Is...>)\
    \ {\n            return ((std::get<_Is>(_M_current) ==\n                     std::get<_Is>(other._M_current))\
    \ ||\n                    ...);\n          }\n          (std::make_index_sequence<sizeof...(_Range)>{});\n\
    \        }\n        constexpr auto& operator--() requires\n            __detail::__all_bidirectional<_Range...>\
    \ {\n          util::tuple_for_each([](auto& __i) { --__i; }, _M_current);\n \
    \         return *this;\n        }\n        constexpr auto operator--(\n     \
    \       int) requires __detail::__all_bidirectional<_Range...> {\n          return\
    \ --*this;\n        }\n        constexpr auto operator<=>(const iterator&)\n \
    \           const requires __detail::__all_random_access<_Range...>\n        =\
    \ default;\n        constexpr auto operator-(const iterator& itr)\n          \
    \  const requires __detail::__all_random_access<_Range...> {\n          return\
    \ [&]<size_t... _Is>(std::index_sequence<_Is...>) {\n            return std::ranges::min({difference_type(\n\
    \                std::get<_Is>(_M_current) - std::get<_Is>(itr._M_current))...});\n\
    \          }\n          (std::make_index_sequence<sizeof...(_Range)>{});\n   \
    \     }\n        constexpr auto& operator+=(const difference_type n) requires\n\
    \            __detail::__all_random_access<_Range...> {\n          util::tuple_for_each([&n](auto&\
    \ __i) { __i += n; }, _M_current);\n          return *this;\n        }\n     \
    \   constexpr auto operator+(const difference_type n)\n            const requires\
    \ __detail::__all_random_access<_Range...> {\n          auto __tmp = *this;\n\
    \          __tmp += n;\n          return __tmp;\n        }\n        constexpr\
    \ friend auto operator+(const difference_type n,\n                           \
    \             const iterator& itr) requires\n            __detail::__all_random_access<_Range...>\
    \ {\n          return itr + n;\n        }\n        constexpr auto& operator-=(const\
    \ difference_type n) requires\n            __detail::__all_random_access<_Range...>\
    \ {\n          util::tuple_for_each([&n](auto& __i) { __i -= n; }, _M_current);\n\
    \          return *this;\n        }\n        constexpr auto operator-(const difference_type\
    \ n)\n            const requires __detail::__all_random_access<_Range...> {\n\
    \          auto __tmp = *this;\n          __tmp -= n;\n          return __tmp;\n\
    \        }\n        constexpr auto operator[](const difference_type n)\n     \
    \       const requires __detail::__all_random_access<_Range...> {\n          return\
    \ util::tuple_transform([&n](auto& __i) { return __i[n]; },\n                \
    \                       _M_current);\n        }\n      };\n\n      class sentinel\
    \ {\n      public:\n        std::tuple<std::ranges::sentinel_t<_Range>...> _M_end;\n\
    \n        constexpr sentinel() = default;\n        constexpr explicit sentinel(const\
    \ decltype(_M_end)& __end)\n            : _M_end(__end) {}\n\n        friend constexpr\
    \ bool operator==(const iterator& __x,\n                                     \
    \    const sentinel& __y) {\n          return [&]<size_t... _Is>(std::index_sequence<_Is...>)\
    \ {\n            return (\n                (std::get<_Is>(__x._M_current) == std::get<_Is>(__y._M_end))\
    \ ||\n                ...);\n          }\n          (std::make_index_sequence<sizeof...(_Range)>{});\n\
    \        }\n      };\n\n      std::tuple<_Range...> _M_views;\n      constexpr\
    \ explicit zip_view(const _Range&... __views)\n          : _M_views(__views...)\
    \ {}\n      constexpr auto begin() {\n        return iterator(util::tuple_transform(std::ranges::begin,\
    \ _M_views));\n      }\n      constexpr auto end() {\n        return sentinel(util::tuple_transform(std::ranges::end,\
    \ _M_views));\n      }\n    };\n\n    namespace __detail {\n      template <typename\
    \ T>\n      auto _flatten(const T& t) {\n        return std::make_tuple(t);\n\
    \      }\n      template <typename... T>\n      auto _flatten(const std::tuple<T...>&\
    \ t);\n\n      template <typename Head, typename... Tail>\n      auto _flatten_impl(const\
    \ Head& head, const Tail&... tail) {\n        return std::tuple_cat(_flatten(head),\
    \ _flatten(tail)...);\n      }\n      template <typename... T>\n      auto _flatten(const\
    \ std::tuple<T...>& t) {\n        return std::apply(\n            [](const auto&...\
    \ args) { return _flatten_impl(args...); }, t);\n      }\n    }  // namespace\
    \ __detail\n\n    template <std::ranges::range _Range>\n    struct flatten_view\n\
    \        : public std::ranges::view_interface<flatten_view<_Range>> {\n      class\
    \ iterator {\n      public:\n        std::ranges::iterator_t<_Range> _M_current;\n\
    \n        using difference_type = std::ranges::range_difference_t<_Range>;\n \
    \       using value_type = decltype(__detail::_flatten(\n            std::declval<\n\
    \                std::iter_reference_t<std::ranges::iterator_t<_Range>>>()));\n\
    \        using iterator_concept = decltype(__detail::_S_iter_concept<_Range>());\n\
    \n        constexpr iterator() = default;\n        constexpr explicit iterator(decltype(_M_current)\
    \ __current)\n            : _M_current(__current) {}\n        constexpr auto operator*()\
    \ const {\n          return __detail::_flatten(*_M_current);\n        }\n    \
    \    constexpr auto& operator++() {\n          ++_M_current;\n          return\
    \ *this;\n        }\n        constexpr auto operator++(int) { return ++*this;\
    \ }\n        constexpr auto operator==(const iterator& other) const {\n      \
    \    return _M_current == other._M_current;\n        }\n        constexpr auto&\
    \ operator--() requires\n            __detail::__all_bidirectional<_Range> {\n\
    \          --_M_current;\n          return *this;\n        }\n        constexpr\
    \ auto operator--(\n            int) requires __detail::__all_bidirectional<_Range>\
    \ {\n          return --*this;\n        }\n        constexpr auto operator<=>(const\
    \ iterator&)\n            const requires __detail::__all_random_access<_Range>\n\
    \        = default;\n        constexpr auto operator-(const iterator& itr)\n \
    \           const requires __detail::__all_random_access<_Range> {\n         \
    \ return _M_current - itr._M_current;\n        }\n        constexpr auto& operator+=(const\
    \ difference_type n) requires\n            __detail::__all_random_access<_Range>\
    \ {\n          _M_current += n;\n          return *this;\n        }\n        constexpr\
    \ auto operator+(const difference_type n)\n            const requires __detail::__all_random_access<_Range>\
    \ {\n          auto __tmp = *this;\n          __tmp += n;\n          return __tmp;\n\
    \        }\n        constexpr friend auto operator+(const difference_type n,\n\
    \                                        const iterator& itr) requires\n     \
    \       __detail::__all_random_access<_Range> {\n          return itr + n;\n \
    \       }\n        constexpr auto& operator-=(const difference_type n) requires\n\
    \            __detail::__all_random_access<_Range> {\n          _M_current -=\
    \ n;\n          return *this;\n        }\n        constexpr auto operator-(const\
    \ difference_type n)\n            const requires __detail::__all_random_access<_Range>\
    \ {\n          auto __tmp = *this;\n          __tmp -= n;\n          return __tmp;\n\
    \        }\n        constexpr auto operator[](const difference_type n)\n     \
    \       const requires __detail::__all_random_access<_Range> {\n          return\
    \ __detail::_flatten(_M_current[n]);\n        }\n      };\n\n      class sentinel\
    \ {\n        std::ranges::sentinel_t<_Range> _M_end;\n\n      public:\n      \
    \  constexpr sentinel() = default;\n        constexpr explicit sentinel(const\
    \ decltype(_M_end)& __end)\n            : _M_end(__end) {}\n\n        friend constexpr\
    \ bool operator==(const iterator& __x,\n                                     \
    \    const sentinel& __y) {\n          return __x._M_current == __y._M_end;\n\
    \        }\n      };\n\n      _Range _M_views;\n      constexpr explicit flatten_view(const\
    \ _Range& __views)\n          : _M_views(__views) {}\n      constexpr auto begin()\
    \ { return iterator(std::ranges::begin(_M_views)); }\n      constexpr auto end()\
    \ { return sentinel(std::ranges::end(_M_views)); }\n    };\n\n    template <std::ranges::range...\
    \ _Range>\n    struct cartesian_product_view : public std::ranges::view_interface<\n\
    \                                        cartesian_product_view<_Range...>> {\n\
    \      class iterator {\n      public:\n        using _Parent = cartesian_product_view;\n\
    \        _Parent* _M_parent = nullptr;\n        std::tuple<std::ranges::iterator_t<_Range>...>\
    \ _M_current;\n\n        using difference_type = int;\n        using value_type\
    \ = std::tuple<\n            std::iter_reference_t<std::ranges::iterator_t<_Range>>...>;\n\
    \        using iterator_concept =\n            decltype(__detail::_S_iter_concept<_Range...>());\n\
    \n      private:\n        template <size_t _Nm = sizeof...(_Range) - 1>\n    \
    \    constexpr void _M_next() {\n          auto& __it = std::get<_Nm>(_M_current);\n\
    \          ++__it;\n          if constexpr (_Nm > 0)\n            if (__it ==\
    \ std::ranges::end(std::get<_Nm>(_M_parent->_M_views))) {\n              __it\
    \ = std::ranges::begin(std::get<_Nm>(_M_parent->_M_views));\n              _M_next<_Nm\
    \ - 1>();\n            }\n        }\n        template <size_t _Nm = sizeof...(_Range)\
    \ - 1>\n        constexpr void _M_prev() {\n          auto& __it = std::get<_Nm>(_M_current);\n\
    \          if constexpr (_Nm > 0)\n            if (__it ==\n                std::ranges::begin(std::get<_Nm>(_M_parent->_M_views)))\
    \ {\n              __it = std::ranges::end(std::get<_Nm>(_M_parent->_M_views));\n\
    \              _M_prev<_Nm - 1>();\n            }\n          --__it;\n       \
    \ }\n\n        template <size_t _Nm = sizeof...(_Range) - 1>\n        constexpr\
    \ void _M_advance(difference_type __x) requires\n            __detail::__all_random_access<_Range...>\
    \ {\n          if (__x == 1)\n            _M_next<_Nm>();\n          else if (__x\
    \ == -1)\n            _M_prev<_Nm>();\n          else if (__x != 0) {\n      \
    \      auto& __r = std::get<_Nm>(_M_parent->_M_views);\n            auto& __it\
    \ = std::get<_Nm>(_M_current);\n            if constexpr (_Nm == 0) {\n      \
    \        __it += __x;\n            } else {\n              auto __size = std::ranges::ssize(__r);\n\
    \              auto __begin = std::ranges::begin(__r);\n              auto __offset\
    \ = __it - __begin;\n              __offset += __x;\n              __x = __offset\
    \ / __size;\n              __offset %= __size;\n              if (__offset < 0)\
    \ {\n                __offset = __size + __offset;\n                --__x;\n \
    \             }\n              __it = __begin + __offset;\n              _M_advance<_Nm\
    \ - 1>(__x);\n            }\n          }\n        }\n\n      public:\n       \
    \ constexpr iterator() = default;\n        constexpr explicit iterator(_Parent&\
    \ __parent,\n                                    const decltype(_M_current)& __current)\n\
    \            : _M_parent(std::addressof(__parent)), _M_current(__current) {}\n\
    \        constexpr auto operator*() const {\n          return util::tuple_transform([](auto&\
    \ __i) { return *__i; },\n                                       _M_current);\n\
    \        }\n        constexpr auto& operator++() {\n          _M_next();\n   \
    \       return *this;\n        }\n        constexpr auto operator++(int) { return\
    \ ++*this; }\n        constexpr auto operator==(const iterator& other) const {\n\
    \          return [&]<size_t... _Is>(std::index_sequence<_Is...>) {\n        \
    \    return ((std::get<_Is>(_M_current) ==\n                     std::get<_Is>(other._M_current))\
    \ ||\n                    ...);\n          }\n          (std::make_index_sequence<sizeof...(_Range)>{});\n\
    \        }\n        constexpr auto& operator--() requires\n            __detail::__all_bidirectional<_Range...>\
    \ {\n          _M_prev();\n          return *this;\n        }\n        constexpr\
    \ auto operator--(\n            int) requires __detail::__all_bidirectional<_Range...>\
    \ {\n          return --*this;\n        }\n        constexpr auto operator<=>(const\
    \ iterator&)\n            const requires __detail::__all_random_access<_Range...>\n\
    \        = default;\n        constexpr auto operator-(const iterator& itr)\n \
    \           const requires __detail::__all_random_access<_Range...> {\n      \
    \    return [&]<size_t... _Is>(std::index_sequence<_Is...>) {\n            return\
    \ std::ranges::min({difference_type(\n                std::get<_Is>(_M_current)\
    \ - std::get<_Is>(itr._M_current))...});\n          }\n          (std::make_index_sequence<sizeof...(_Range)>{});\n\
    \        }\n        constexpr auto& operator+=(const difference_type n) requires\n\
    \            __detail::__all_random_access<_Range...> {\n          _M_advance(n);\n\
    \          return *this;\n        }\n        constexpr auto operator+(const difference_type\
    \ n)\n            const requires __detail::__all_random_access<_Range...> {\n\
    \          auto __tmp = *this;\n          __tmp += n;\n          return __tmp;\n\
    \        }\n        constexpr friend auto operator+(const difference_type n,\n\
    \                                        const iterator& itr) requires\n     \
    \       __detail::__all_random_access<_Range...> {\n          return itr + n;\n\
    \        }\n        constexpr auto& operator-=(const difference_type n) requires\n\
    \            __detail::__all_random_access<_Range...> {\n          *this += -n;\n\
    \          return *this;\n        }\n        constexpr auto operator-(const difference_type\
    \ n)\n            const requires __detail::__all_random_access<_Range...> {\n\
    \          auto __tmp = *this;\n          __tmp -= n;\n          return __tmp;\n\
    \        }\n        constexpr auto operator[](const difference_type n)\n     \
    \       const requires __detail::__all_random_access<_Range...> {\n          return\
    \ util::tuple_transform([&n](auto& __i) { return __i[n]; },\n                \
    \                       _M_current);\n        }\n      };\n\n      class sentinel\
    \ {\n      public:\n        std::tuple<std::ranges::sentinel_t<_Range>...> _M_end;\n\
    \n        constexpr sentinel() = default;\n        constexpr explicit sentinel(const\
    \ decltype(_M_end)& __end)\n            : _M_end(__end) {}\n\n        friend constexpr\
    \ bool operator==(const iterator& __x,\n                                     \
    \    const sentinel& __y) {\n          return [&]<size_t... _Is>(std::index_sequence<_Is...>)\
    \ {\n            return (\n                (std::get<_Is>(__x._M_current) == std::get<_Is>(__y._M_end))\
    \ ||\n                ...);\n          }\n          (std::make_index_sequence<sizeof...(_Range)>{});\n\
    \        }\n      };\n\n      std::tuple<_Range...> _M_views;\n      constexpr\
    \ explicit cartesian_product_view(const _Range&... __views)\n          : _M_views(__views...)\
    \ {}\n      constexpr auto begin() {\n        return iterator(*this,\n       \
    \                 util::tuple_transform(std::ranges::begin, _M_views));\n    \
    \  }\n      constexpr auto end() {\n        return sentinel(util::tuple_transform(std::ranges::end,\
    \ _M_views));\n      }\n    };\n\n  }  // namespace ranges\n\n  namespace views\
    \ {\n    namespace __detail {\n      template <typename... _Args>\n      concept\
    \ __can_zip_view = requires {\n        ranges::zip_view(std::declval<_Args>()...);\n\
    \      };\n      template <typename... _Args>\n      concept __can_flatten_view\
    \ = requires {\n        ranges::flatten_view(std::declval<_Args>()...);\n    \
    \  };\n      template <typename... _Args>\n      concept __can_cartesian_product_view\
    \ = requires {\n        ranges::cartesian_product_view(std::declval<_Args>()...);\n\
    \      };\n    }  // namespace __detail\n\n    struct _ZipView {\n      template\
    \ <class... _Tp>\n      requires __detail::__can_zip_view<_Tp...>\n      constexpr\
    \ auto operator() [[nodiscard]] (_Tp&&... __e) const {\n        return ranges::zip_view(std::forward<_Tp>(__e)...);\n\
    \      }\n    };\n    struct _Enumerate : std::views::__adaptor::_RangeAdaptorClosure\
    \ {\n      template <class _Tp>\n      requires __detail::__can_zip_view<std::ranges::iota_view<size_t>,\
    \ _Tp>\n      constexpr auto operator() [[nodiscard]] (_Tp&& __e) const {\n  \
    \      return ranges::zip_view{std::views::iota(0), std::forward<_Tp>(__e)};\n\
    \      }\n      static constexpr bool _S_has_simple_call_op = true;\n    };\n\
    \    struct _Flatten : std::views::__adaptor::_RangeAdaptorClosure {\n      template\
    \ <class... _Tp>\n      requires __detail::__can_flatten_view<_Tp...>\n      constexpr\
    \ auto operator() [[nodiscard]] (_Tp&&... __e) const {\n        return ranges::flatten_view(std::forward<_Tp>(__e)...);\n\
    \      }\n      static constexpr bool _S_has_simple_call_op = true;\n    };\n\
    \    struct _CartesianProduct {\n      template <class... _Tp>\n      requires\
    \ __detail::__can_cartesian_product_view<_Tp...>\n      constexpr auto operator()\
    \ [[nodiscard]] (_Tp&&... __e) const {\n        return ranges::cartesian_product_view(std::forward<_Tp>(__e)...);\n\
    \      }\n    };\n    struct _ProductN {\n      template <class... _Tp>\n    \
    \  requires __detail::__can_cartesian_product_view<\n          std::ranges::iota_view<size_t,\
    \ _Tp>...>\n      constexpr auto operator() [[nodiscard]] (_Tp... __e) const {\n\
    \        return ranges::cartesian_product_view(std::views::iota(0, __e)...);\n\
    \      }\n    };\n\n    inline constexpr _ZipView zip{};\n    inline constexpr\
    \ _Enumerate enumerate{};\n    inline constexpr _Flatten flatten{};\n    inline\
    \ constexpr _CartesianProduct cartesian_product{};\n    inline constexpr _ProductN\
    \ product_n{};\n  }  // namespace views\n}  // namespace mtd\n#line 10 \"Library/DataStructure/SternBrocotTree.hpp\"\
    \n\nnamespace mtd {\n\n  template <class T, class CompT = long long>\n  class\
    \ SternBrocotTree {\n    using Path = std::vector<std::tuple<bool, T>>;\n\n  \
    \  static constexpr T MAX_NUM = static_cast<T>(2e18);\n    static constexpr T\
    \ MAX_DEN = static_cast<T>(2e18);\n\n    class Node {\n      // \u5B9A\u6570\u500D\
    \u9AD8\u901F\u5316\u306E\u305F\u3081\u7834\u58CA\u7684\u5909\u66F4\u3084\u602A\
    \u3057\u3044\u4ED5\u69D8\u3042\u308A\n      T num_l, den_l, num_r, den_r;\n  \
    \    Path path_rle;\n      const T max_num;\n      const T max_den;\n\n      friend\
    \ std::ostream& operator<<(std::ostream& os, const Node& node) {\n        return\
    \ os << node.num_l + node.num_r << \"/\" << node.den_l + node.den_r\n        \
    \          << \": \" << node.num_l << \"/\" << node.den_l << \" \"\n         \
    \         << node.num_r << \"/\" << node.den_r;\n      }\n\n    public:\n    \
    \  static constexpr auto get_root(T max_num, T max_den) {\n        return Node(0,\
    \ 1, 1, 0, Path(), max_num, max_den);\n      }\n\n      constexpr auto get() const\
    \ {\n        return std::make_tuple(num_l + num_r, den_l + den_r);\n      }\n\
    \      constexpr auto get_l() const { return Node(num_l, den_l); }\n      constexpr\
    \ auto get_r() const { return Node(num_r, den_r); }\n      constexpr auto get_path_rle()\
    \ const { return path_rle; }\n\n      constexpr auto move_left(T d = 1) {\n  \
    \      if (num_l > 0) { d = std::min(d, (max_num - num_r - num_l) / num_l); }\n\
    \        if (den_l > 0) { d = std::min(d, (max_den - den_r - den_l) / den_l);\
    \ }\n        if (d <= 0) { return false; }\n        path_rle.emplace_back(false,\
    \ d);\n        num_r += d * num_l;\n        den_r += d * den_l;\n        return\
    \ true;\n      }\n      constexpr auto move_left_to(T num, T den) {\n        auto\
    \ den_d = static_cast<CompT>(den);\n        auto num_d = static_cast<CompT>(num);\n\
    \        auto tmp = den_l * num_d - den_d * num_l;\n        T d =\n          \
    \  (den_d * (num_l + num_r) - (den_l + den_r) * num_d + tmp - 1) / tmp;\n    \
    \    return move_left(d);\n      }\n      constexpr auto move_right(T d = 1) {\n\
    \        if (num_r > 0) { d = std::min(d, (max_num - num_l - num_r) / num_r);\
    \ }\n        if (den_r > 0) { d = std::min(d, (max_den - den_l - den_r) / den_r);\
    \ }\n        if (d <= 0) { return false; }\n        path_rle.emplace_back(true,\
    \ d);\n        num_l += d * num_r;\n        den_l += d * den_r;\n        return\
    \ true;\n      }\n      constexpr auto move_right_to(T num, T den) {\n       \
    \ auto den_d = static_cast<CompT>(den);\n        auto num_d = static_cast<CompT>(num);\n\
    \        auto tmp = den_d * num_r - den_r * num_d;\n        T d =\n          \
    \  ((den_l + den_r) * num_d - den_d * (num_l + num_r) + tmp - 1) / tmp;\n    \
    \    return move_right(d);\n      }\n\n      constexpr static auto generate_node(T\
    \ num, T den, T max_num, T max_den) {\n        if (den <= 0) {\n          throw\
    \ std::runtime_error(\"denominator must be positive\");\n        }\n        if\
    \ (num < 0) {\n          throw std::runtime_error(\"numerator must be non-negative\"\
    );\n        }\n        if (std::gcd(num, den) > 1) {\n          throw std::runtime_error(\"\
    numerator and denominator must be coprime\");\n        }\n\n        auto node\
    \ = get_root(max_num, max_den);\n        while (node.move_left_to(num, den) ||\
    \ node.move_right_to(num, den)) {}\n        return node;\n      }\n\n      constexpr\
    \ static auto decode(const Path& path_rle, T max_num = MAX_NUM,\n            \
    \                       T max_den = MAX_DEN) {\n        auto node = get_root(max_num,\
    \ max_den);\n        for (const auto& [right, k] : path_rle) {\n          right\
    \ ? node.move_right(k) : node.move_left(k);\n        }\n        return node;\n\
    \      }\n\n      constexpr Node(T num_l, T den_l, T num_r, T den_r, Path&& path_rle,\n\
    \                     T max_num, T max_den)\n          : num_l(num_l),\n     \
    \       den_l(den_l),\n            num_r(num_r),\n            den_r(den_r),\n\
    \            path_rle(std::move(path_rle)),\n            max_num(max_num),\n \
    \           max_den(max_den) {}\n      constexpr Node(T num_l, T den_l, T num_r,\
    \ T den_r)\n          : Node(num_l, den_l, num_r, den_r, Path(), MAX_NUM, MAX_DEN)\
    \ {}\n      constexpr Node(T num, T den)\n          : Node(generate_node(num,\
    \ den, MAX_NUM, MAX_DEN)) {}\n\n      constexpr auto operator!=(const Node& other)\
    \ const {\n        return std::tie(num_l, den_l, num_r, den_r) !=\n          \
    \     std::tie(other.num_l, other.den_l, other.num_r, other.den_r);\n      }\n\
    \      constexpr auto operator==(const Node& other) const {\n        return !(*this\
    \ != other);\n      }\n    };\n\n  public:\n    /*\n     * Encode the path from\
    \ the root to the fraction num/den\n     **/\n    constexpr auto encode(const\
    \ Node& node) const {\n      return node.get_path_rle();\n    }\n    constexpr\
    \ auto encode(T num, T den) const { return encode(Node(num, den)); }\n\n    /*\n\
    \     * Decode the path from the root to the fraction represented by\n     **/\n\
    \    constexpr auto decode(const Path& path_rle) const {\n      return Node::decode(path_rle);\n\
    \    }\n\n    /*\n     * Find the lowest common ancestor of two fractions num1/den1\
    \ and num2/den2\n     **/\n    constexpr auto lca(const Node& node1, const Node&\
    \ node2) const {\n      auto path_rle1 = encode(node1);\n      auto path_rle2\
    \ = encode(node2);\n      Path lca_path;\n      for (const auto [p1, p2] : mtd::views::zip(path_rle1,\
    \ path_rle2)) {\n        auto [right1, k1] = p1;\n        auto [right2, k2] =\
    \ p2;\n        if (right1 != right2) { return Node::get_root(MAX_NUM, MAX_DEN);\
    \ }\n        lca_path.emplace_back(right1, std::min(k1, k2));\n        if (p1\
    \ != p2) { break; }\n      }\n      return decode(lca_path);\n    }\n    constexpr\
    \ auto lca(T num1, T den1, T num2, T den2) const {\n      return lca(Node(num1,\
    \ den1), Node(num2, den2));\n    }\n\n    /*\n     * Find the k-th ancestor of\
    \ the fraction num/den\n     **/\n    constexpr auto ancestor(const Node& node,\
    \ T k) const {\n      Path k_path_rle;\n      for (const auto& [right, count]\
    \ : encode(node)) {\n        if (count > k) {\n          k_path_rle.emplace_back(right,\
    \ k);\n          k = 0;\n          break;\n        } else {\n          k_path_rle.emplace_back(right,\
    \ count);\n          k -= count;\n        }\n      }\n      if (k > 0) { throw\
    \ std::runtime_error(\"k is too large for the path\"); }\n      return decode(k_path_rle);\n\
    \    }\n    constexpr auto ancestor(T num, T den, T k) const {\n      return ancestor(Node(num,\
    \ den), k);\n    }\n\n    /*\n     * Find the lower and upper bounds of the descendants\
    \ of num/den\n     **/\n    constexpr auto range(const Node& node) const {\n \
    \     auto [num, den] = node.get();\n      if (num == 1 && den == 1) {\n     \
    \   return std::make_tuple(Node(0, 0, 0, 1), Node(0, 0, 1, 0));\n      }\n   \
    \   if (den == 1) { return std::make_tuple(node.get_l(), Node(0, 0, 1, 0)); }\n\
    \      if (num == 1) { return std::make_tuple(Node(0, 0, 0, 1), node.get_r());\
    \ }\n      return std::make_tuple(node.get_l(), node.get_r());\n    }\n    constexpr\
    \ auto range(T num, T den) const { return range(Node(num, den)); }\n\n    /*\n\
    \     * Create a node representing the fraction num/den\n     **/\n    constexpr\
    \ auto create_node(T num, T den, T max_num = MAX_NUM,\n                      \
    \         T max_den = MAX_DEN) const {\n      return Node::generate_node(num,\
    \ den, max_num, max_den);\n    }\n\n    /*\n     * Get the root node of the tree\n\
    \     **/\n    constexpr auto get_root(T max_num = MAX_NUM, T max_den = MAX_DEN)\
    \ const {\n      return Node::get_root(max_num, max_den);\n    }\n  };\n}  //\
    \ namespace mtd\n"
  code: "#pragma once\n\n#include <iostream>\n#include <numeric>\n#include <stdexcept>\n\
    #include <tuple>\n#include <vector>\n\n#include \"../Range/util.hpp\"\n\nnamespace\
    \ mtd {\n\n  template <class T, class CompT = long long>\n  class SternBrocotTree\
    \ {\n    using Path = std::vector<std::tuple<bool, T>>;\n\n    static constexpr\
    \ T MAX_NUM = static_cast<T>(2e18);\n    static constexpr T MAX_DEN = static_cast<T>(2e18);\n\
    \n    class Node {\n      // \u5B9A\u6570\u500D\u9AD8\u901F\u5316\u306E\u305F\u3081\
    \u7834\u58CA\u7684\u5909\u66F4\u3084\u602A\u3057\u3044\u4ED5\u69D8\u3042\u308A\
    \n      T num_l, den_l, num_r, den_r;\n      Path path_rle;\n      const T max_num;\n\
    \      const T max_den;\n\n      friend std::ostream& operator<<(std::ostream&\
    \ os, const Node& node) {\n        return os << node.num_l + node.num_r << \"\
    /\" << node.den_l + node.den_r\n                  << \": \" << node.num_l << \"\
    /\" << node.den_l << \" \"\n                  << node.num_r << \"/\" << node.den_r;\n\
    \      }\n\n    public:\n      static constexpr auto get_root(T max_num, T max_den)\
    \ {\n        return Node(0, 1, 1, 0, Path(), max_num, max_den);\n      }\n\n \
    \     constexpr auto get() const {\n        return std::make_tuple(num_l + num_r,\
    \ den_l + den_r);\n      }\n      constexpr auto get_l() const { return Node(num_l,\
    \ den_l); }\n      constexpr auto get_r() const { return Node(num_r, den_r); }\n\
    \      constexpr auto get_path_rle() const { return path_rle; }\n\n      constexpr\
    \ auto move_left(T d = 1) {\n        if (num_l > 0) { d = std::min(d, (max_num\
    \ - num_r - num_l) / num_l); }\n        if (den_l > 0) { d = std::min(d, (max_den\
    \ - den_r - den_l) / den_l); }\n        if (d <= 0) { return false; }\n      \
    \  path_rle.emplace_back(false, d);\n        num_r += d * num_l;\n        den_r\
    \ += d * den_l;\n        return true;\n      }\n      constexpr auto move_left_to(T\
    \ num, T den) {\n        auto den_d = static_cast<CompT>(den);\n        auto num_d\
    \ = static_cast<CompT>(num);\n        auto tmp = den_l * num_d - den_d * num_l;\n\
    \        T d =\n            (den_d * (num_l + num_r) - (den_l + den_r) * num_d\
    \ + tmp - 1) / tmp;\n        return move_left(d);\n      }\n      constexpr auto\
    \ move_right(T d = 1) {\n        if (num_r > 0) { d = std::min(d, (max_num - num_l\
    \ - num_r) / num_r); }\n        if (den_r > 0) { d = std::min(d, (max_den - den_l\
    \ - den_r) / den_r); }\n        if (d <= 0) { return false; }\n        path_rle.emplace_back(true,\
    \ d);\n        num_l += d * num_r;\n        den_l += d * den_r;\n        return\
    \ true;\n      }\n      constexpr auto move_right_to(T num, T den) {\n       \
    \ auto den_d = static_cast<CompT>(den);\n        auto num_d = static_cast<CompT>(num);\n\
    \        auto tmp = den_d * num_r - den_r * num_d;\n        T d =\n          \
    \  ((den_l + den_r) * num_d - den_d * (num_l + num_r) + tmp - 1) / tmp;\n    \
    \    return move_right(d);\n      }\n\n      constexpr static auto generate_node(T\
    \ num, T den, T max_num, T max_den) {\n        if (den <= 0) {\n          throw\
    \ std::runtime_error(\"denominator must be positive\");\n        }\n        if\
    \ (num < 0) {\n          throw std::runtime_error(\"numerator must be non-negative\"\
    );\n        }\n        if (std::gcd(num, den) > 1) {\n          throw std::runtime_error(\"\
    numerator and denominator must be coprime\");\n        }\n\n        auto node\
    \ = get_root(max_num, max_den);\n        while (node.move_left_to(num, den) ||\
    \ node.move_right_to(num, den)) {}\n        return node;\n      }\n\n      constexpr\
    \ static auto decode(const Path& path_rle, T max_num = MAX_NUM,\n            \
    \                       T max_den = MAX_DEN) {\n        auto node = get_root(max_num,\
    \ max_den);\n        for (const auto& [right, k] : path_rle) {\n          right\
    \ ? node.move_right(k) : node.move_left(k);\n        }\n        return node;\n\
    \      }\n\n      constexpr Node(T num_l, T den_l, T num_r, T den_r, Path&& path_rle,\n\
    \                     T max_num, T max_den)\n          : num_l(num_l),\n     \
    \       den_l(den_l),\n            num_r(num_r),\n            den_r(den_r),\n\
    \            path_rle(std::move(path_rle)),\n            max_num(max_num),\n \
    \           max_den(max_den) {}\n      constexpr Node(T num_l, T den_l, T num_r,\
    \ T den_r)\n          : Node(num_l, den_l, num_r, den_r, Path(), MAX_NUM, MAX_DEN)\
    \ {}\n      constexpr Node(T num, T den)\n          : Node(generate_node(num,\
    \ den, MAX_NUM, MAX_DEN)) {}\n\n      constexpr auto operator!=(const Node& other)\
    \ const {\n        return std::tie(num_l, den_l, num_r, den_r) !=\n          \
    \     std::tie(other.num_l, other.den_l, other.num_r, other.den_r);\n      }\n\
    \      constexpr auto operator==(const Node& other) const {\n        return !(*this\
    \ != other);\n      }\n    };\n\n  public:\n    /*\n     * Encode the path from\
    \ the root to the fraction num/den\n     **/\n    constexpr auto encode(const\
    \ Node& node) const {\n      return node.get_path_rle();\n    }\n    constexpr\
    \ auto encode(T num, T den) const { return encode(Node(num, den)); }\n\n    /*\n\
    \     * Decode the path from the root to the fraction represented by\n     **/\n\
    \    constexpr auto decode(const Path& path_rle) const {\n      return Node::decode(path_rle);\n\
    \    }\n\n    /*\n     * Find the lowest common ancestor of two fractions num1/den1\
    \ and num2/den2\n     **/\n    constexpr auto lca(const Node& node1, const Node&\
    \ node2) const {\n      auto path_rle1 = encode(node1);\n      auto path_rle2\
    \ = encode(node2);\n      Path lca_path;\n      for (const auto [p1, p2] : mtd::views::zip(path_rle1,\
    \ path_rle2)) {\n        auto [right1, k1] = p1;\n        auto [right2, k2] =\
    \ p2;\n        if (right1 != right2) { return Node::get_root(MAX_NUM, MAX_DEN);\
    \ }\n        lca_path.emplace_back(right1, std::min(k1, k2));\n        if (p1\
    \ != p2) { break; }\n      }\n      return decode(lca_path);\n    }\n    constexpr\
    \ auto lca(T num1, T den1, T num2, T den2) const {\n      return lca(Node(num1,\
    \ den1), Node(num2, den2));\n    }\n\n    /*\n     * Find the k-th ancestor of\
    \ the fraction num/den\n     **/\n    constexpr auto ancestor(const Node& node,\
    \ T k) const {\n      Path k_path_rle;\n      for (const auto& [right, count]\
    \ : encode(node)) {\n        if (count > k) {\n          k_path_rle.emplace_back(right,\
    \ k);\n          k = 0;\n          break;\n        } else {\n          k_path_rle.emplace_back(right,\
    \ count);\n          k -= count;\n        }\n      }\n      if (k > 0) { throw\
    \ std::runtime_error(\"k is too large for the path\"); }\n      return decode(k_path_rle);\n\
    \    }\n    constexpr auto ancestor(T num, T den, T k) const {\n      return ancestor(Node(num,\
    \ den), k);\n    }\n\n    /*\n     * Find the lower and upper bounds of the descendants\
    \ of num/den\n     **/\n    constexpr auto range(const Node& node) const {\n \
    \     auto [num, den] = node.get();\n      if (num == 1 && den == 1) {\n     \
    \   return std::make_tuple(Node(0, 0, 0, 1), Node(0, 0, 1, 0));\n      }\n   \
    \   if (den == 1) { return std::make_tuple(node.get_l(), Node(0, 0, 1, 0)); }\n\
    \      if (num == 1) { return std::make_tuple(Node(0, 0, 0, 1), node.get_r());\
    \ }\n      return std::make_tuple(node.get_l(), node.get_r());\n    }\n    constexpr\
    \ auto range(T num, T den) const { return range(Node(num, den)); }\n\n    /*\n\
    \     * Create a node representing the fraction num/den\n     **/\n    constexpr\
    \ auto create_node(T num, T den, T max_num = MAX_NUM,\n                      \
    \         T max_den = MAX_DEN) const {\n      return Node::generate_node(num,\
    \ den, max_num, max_den);\n    }\n\n    /*\n     * Get the root node of the tree\n\
    \     **/\n    constexpr auto get_root(T max_num = MAX_NUM, T max_den = MAX_DEN)\
    \ const {\n      return Node::get_root(max_num, max_den);\n    }\n  };\n}  //\
    \ namespace mtd\n"
  dependsOn:
  - Library/Range/util.hpp
  - Library/Utility/Tuple.hpp
  isVerificationFile: false
  path: Library/DataStructure/SternBrocotTree.hpp
  requiredBy: []
  timestamp: '2025-06-03 01:16:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/DataStructure/SternBrocotTree.test.cpp
documentation_of: Library/DataStructure/SternBrocotTree.hpp
layout: document
redirect_from:
- /library/Library/DataStructure/SternBrocotTree.hpp
- /library/Library/DataStructure/SternBrocotTree.hpp.html
title: Library/DataStructure/SternBrocotTree.hpp
---
