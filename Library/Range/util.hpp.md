---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Utility/Tuple.hpp
    title: Library/Utility/Tuple.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/SternBrocotTree.hpp
    title: Library/DataStructure/SternBrocotTree.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Normal/Topological.hpp
    title: Library/Graph/Normal/Topological.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/SternBrocotTree.test.cpp
    title: Test/DataStructure/SternBrocotTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Graph/Normal/Topological.test.cpp
    title: Test/Graph/Normal/Topological.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Range/cartesian_product.test.cpp
    title: Test/Range/cartesian_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Range/enumerate.test.cpp
    title: Test/Range/enumerate.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Range/flatten.test.cpp
    title: Test/Range/flatten.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Range/zip.test.cpp
    title: Test/Range/zip.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Range/util.hpp\"\n\n#include <algorithm>\n#include\
    \ <iostream>\n#include <ranges>\n\n#line 2 \"Library/Utility/Tuple.hpp\"\n\n#include\
    \ <functional>\n\nnamespace mtd {\n  namespace util {\n    template <class F,\
    \ class T>\n    constexpr auto tuple_transform(F&& f, T&& t) {\n      return std::apply(\n\
    \          [&]<class... Ts>(Ts&&... elems) {\n            return std::tuple<std::invoke_result_t<F&,\
    \ Ts>...>(\n                std::invoke(f, std::forward<Ts>(elems))...);\n   \
    \       },\n          std::forward<T>(t));\n    }\n    template <class F, class\
    \ T>\n    constexpr auto tuple_for_each(F&& f, T&& t) {\n      std::apply(\n \
    \         [&]<class... Ts>(Ts&&... elems) {\n            (std::invoke(f, std::forward<Ts>(elems)),\
    \ ...);\n          },\n          std::forward<T>(t));\n    }\n  }  // namespace\
    \ util\n}  // namespace mtd\n#line 8 \"Library/Range/util.hpp\"\n\nnamespace mtd\
    \ {\n  namespace ranges {\n\n    namespace __detail {\n      template <typename...\
    \ T>\n      concept __all_random_access = (std::ranges::random_access_range<T>\
    \ &&\n                                     ...);\n      template <typename...\
    \ T>\n      concept __all_bidirectional = (std::ranges::bidirectional_range<T>\
    \ &&\n                                     ...);\n      template <typename...\
    \ T>\n      concept __all_forward = (std::ranges::forward_range<T> && ...);\n\n\
    \      template <class... T>\n      constexpr auto _S_iter_concept() {\n     \
    \   if constexpr (__all_random_access<T...>) {\n          return std::random_access_iterator_tag{};\n\
    \        } else if constexpr (__all_bidirectional<T...>) {\n          return std::bidirectional_iterator_tag{};\n\
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
    \ product_n{};\n  }  // namespace views\n}  // namespace mtd\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <iostream>\n#include <ranges>\n\
    \n#include \"../Utility/Tuple.hpp\"\n\nnamespace mtd {\n  namespace ranges {\n\
    \n    namespace __detail {\n      template <typename... T>\n      concept __all_random_access\
    \ = (std::ranges::random_access_range<T> &&\n                                \
    \     ...);\n      template <typename... T>\n      concept __all_bidirectional\
    \ = (std::ranges::bidirectional_range<T> &&\n                                \
    \     ...);\n      template <typename... T>\n      concept __all_forward = (std::ranges::forward_range<T>\
    \ && ...);\n\n      template <class... T>\n      constexpr auto _S_iter_concept()\
    \ {\n        if constexpr (__all_random_access<T...>) {\n          return std::random_access_iterator_tag{};\n\
    \        } else if constexpr (__all_bidirectional<T...>) {\n          return std::bidirectional_iterator_tag{};\n\
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
    \ product_n{};\n  }  // namespace views\n}  // namespace mtd\n"
  dependsOn:
  - Library/Utility/Tuple.hpp
  isVerificationFile: false
  path: Library/Range/util.hpp
  requiredBy:
  - Library/Graph/Normal/Topological.hpp
  - Library/DataStructure/SternBrocotTree.hpp
  timestamp: '2025-01-24 16:53:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Range/zip.test.cpp
  - Test/Range/cartesian_product.test.cpp
  - Test/Range/enumerate.test.cpp
  - Test/Range/flatten.test.cpp
  - Test/Graph/Normal/Topological.test.cpp
  - Test/DataStructure/SternBrocotTree.test.cpp
documentation_of: Library/Range/util.hpp
layout: document
redirect_from:
- /library/Library/Range/util.hpp
- /library/Library/Range/util.hpp.html
title: Library/Range/util.hpp
---
