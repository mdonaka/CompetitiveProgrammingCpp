#include <immintrin.h>
constexpr long long MOD = 1000000007;

namespace mtd {
  auto MMM(const __m512i& a, const __m512i& b) {
    static constexpr unsigned int r_size = 30;
    static constexpr long long r = (1LL << r_size);
    static constexpr long long r2 = (r * r) % MOD;
    static constexpr long long mask = r - 1;
    static constexpr long long MODm1 = MOD - 1;
    static constexpr long long MOD_r = [](long long N, long long R) {
      int result = 0, t = 0, r = R, i = 1;
      while (r > 1) {
        if (!(t % 2)) {
          t += N;
          result += i;
        }
        t >>= 1;
        r >>= 1;
        i <<= 1;
      }
      return result;
    }(MOD, r);

    static const __m512i MOD_512 =
        _mm512_set_epi64(MOD, MOD, MOD, MOD, MOD, MOD, MOD, MOD);
    static const __m512i MOD_r_512 = _mm512_set_epi64(
        MOD_r, MOD_r, MOD_r, MOD_r, MOD_r, MOD_r, MOD_r, MOD_r);
    static const __m512i MODm1_512 = _mm512_set_epi64(
        MODm1, MODm1, MODm1, MODm1, MODm1, MODm1, MODm1, MODm1);
    static const __m512i r2_512 =
        _mm512_set_epi64(r2, r2, r2, r2, r2, r2, r2, r2);
    static const __m512i mask_512 =
        _mm512_set_epi64(mask, mask, mask, mask, mask, mask, mask, mask);

    auto MR = [&](const __m512i& t) {
      auto tmod = _mm512_and_epi64(t, mask_512);
      auto val = _mm512_mullox_epi64(tmod, MOD_r_512);
      val = _mm512_and_epi64(val, mask_512);
      val = _mm512_mullox_epi64(val, MOD_512);
      val = _mm512_add_epi64(val, t);
      val = _mm512_srai_epi64(val, r_size);
      auto gt_mask = _mm512_cmpgt_epi64_mask(val, MODm1_512);
      val = _mm512_mask_sub_epi64(val, gt_mask, val, MOD_512);
      return val;
    };

    auto val = _mm512_mullox_epi64(a, b);
    val = MR(val);
    val = _mm512_mullox_epi64(val, r2_512);
    val = MR(val);
    return val;
  }
}  // namespace mtd
