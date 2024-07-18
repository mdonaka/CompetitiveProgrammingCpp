---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Library/Simd/MontgomeryMultiplication.hpp\"\n#include <immintrin.h>\r\
    \nconstexpr long long MOD = 1000000007;\r\n\r\nauto MMM(const __m512i& a, const\
    \ __m512i& b) {\r\n    static constexpr unsigned int r_size = 30;\r\n    static\
    \ constexpr long long r = (1LL << r_size);\r\n    static constexpr long long r2\
    \ = (r * r) % MOD;\r\n    static constexpr long long mask = r - 1;\r\n    static\
    \ constexpr long long MODm1 = MOD - 1;\r\n    static constexpr long long MOD_r\
    \ = [](long long N, long long R) {\r\n        int result = 0, t = 0, r = R, i\
    \ = 1;\r\n        while (r > 1) {\r\n            if (!(t % 2)) { t += N; result\
    \ += i; }\r\n            t >>= 1; r >>= 1; i <<= 1;\r\n        }\r\n        return\
    \ result;\r\n    }(MOD, r);\r\n\r\n    static const __m512i MOD_512 = _mm512_set_epi64(MOD,\
    \ MOD, MOD, MOD, MOD, MOD, MOD, MOD);\r\n    static const __m512i MOD_r_512 =\
    \ _mm512_set_epi64(MOD_r, MOD_r, MOD_r, MOD_r, MOD_r, MOD_r, MOD_r, MOD_r);\r\n\
    \    static const __m512i MODm1_512 = _mm512_set_epi64(MODm1, MODm1, MODm1, MODm1,\
    \ MODm1, MODm1, MODm1, MODm1);\r\n    static const __m512i r2_512 = _mm512_set_epi64(r2,\
    \ r2, r2, r2, r2, r2, r2, r2);\r\n    static const __m512i mask_512 = _mm512_set_epi64(mask,\
    \ mask, mask, mask, mask, mask, mask, mask);\r\n\r\n    auto MR = [&](const __m512i&\
    \ t) {\r\n        auto tmod = _mm512_and_epi64(t, mask_512);\r\n        auto val\
    \ = _mm512_mullox_epi64(tmod, MOD_r_512);\r\n        val = _mm512_and_epi64(val,\
    \ mask_512);\r\n        val = _mm512_mullox_epi64(val, MOD_512);\r\n        val\
    \ = _mm512_add_epi64(val, t);\r\n        val = _mm512_srai_epi64(val, r_size);\r\
    \n        auto gt_mask = _mm512_cmpgt_epi64_mask(val, MODm1_512);\r\n        val\
    \ = _mm512_mask_sub_epi64(val, gt_mask, val, MOD_512);\r\n        return val;\r\
    \n    };\r\n\r\n    auto val = _mm512_mullox_epi64(a, b);\r\n    val = MR(val);\r\
    \n    val = _mm512_mullox_epi64(val, r2_512);\r\n    val = MR(val);\r\n    return\
    \ val;\r\n}\n"
  code: "#include <immintrin.h>\r\nconstexpr long long MOD = 1000000007;\r\n\r\nauto\
    \ MMM(const __m512i& a, const __m512i& b) {\r\n    static constexpr unsigned int\
    \ r_size = 30;\r\n    static constexpr long long r = (1LL << r_size);\r\n    static\
    \ constexpr long long r2 = (r * r) % MOD;\r\n    static constexpr long long mask\
    \ = r - 1;\r\n    static constexpr long long MODm1 = MOD - 1;\r\n    static constexpr\
    \ long long MOD_r = [](long long N, long long R) {\r\n        int result = 0,\
    \ t = 0, r = R, i = 1;\r\n        while (r > 1) {\r\n            if (!(t % 2))\
    \ { t += N; result += i; }\r\n            t >>= 1; r >>= 1; i <<= 1;\r\n     \
    \   }\r\n        return result;\r\n    }(MOD, r);\r\n\r\n    static const __m512i\
    \ MOD_512 = _mm512_set_epi64(MOD, MOD, MOD, MOD, MOD, MOD, MOD, MOD);\r\n    static\
    \ const __m512i MOD_r_512 = _mm512_set_epi64(MOD_r, MOD_r, MOD_r, MOD_r, MOD_r,\
    \ MOD_r, MOD_r, MOD_r);\r\n    static const __m512i MODm1_512 = _mm512_set_epi64(MODm1,\
    \ MODm1, MODm1, MODm1, MODm1, MODm1, MODm1, MODm1);\r\n    static const __m512i\
    \ r2_512 = _mm512_set_epi64(r2, r2, r2, r2, r2, r2, r2, r2);\r\n    static const\
    \ __m512i mask_512 = _mm512_set_epi64(mask, mask, mask, mask, mask, mask, mask,\
    \ mask);\r\n\r\n    auto MR = [&](const __m512i& t) {\r\n        auto tmod = _mm512_and_epi64(t,\
    \ mask_512);\r\n        auto val = _mm512_mullox_epi64(tmod, MOD_r_512);\r\n \
    \       val = _mm512_and_epi64(val, mask_512);\r\n        val = _mm512_mullox_epi64(val,\
    \ MOD_512);\r\n        val = _mm512_add_epi64(val, t);\r\n        val = _mm512_srai_epi64(val,\
    \ r_size);\r\n        auto gt_mask = _mm512_cmpgt_epi64_mask(val, MODm1_512);\r\
    \n        val = _mm512_mask_sub_epi64(val, gt_mask, val, MOD_512);\r\n       \
    \ return val;\r\n    };\r\n\r\n    auto val = _mm512_mullox_epi64(a, b);\r\n \
    \   val = MR(val);\r\n    val = _mm512_mullox_epi64(val, r2_512);\r\n    val =\
    \ MR(val);\r\n    return val;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: Library/Simd/MontgomeryMultiplication.hpp
  requiredBy: []
  timestamp: '2020-05-17 10:05:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Simd/MontgomeryMultiplication.hpp
layout: document
redirect_from:
- /library/Library/Simd/MontgomeryMultiplication.hpp
- /library/Library/Simd/MontgomeryMultiplication.hpp.html
title: Library/Simd/MontgomeryMultiplication.hpp
---
