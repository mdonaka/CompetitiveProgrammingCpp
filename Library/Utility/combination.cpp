/**
 *	MOD付きの組み合わせ計算
 */
ll comb(ll a, ll b) {
	static constexpr ll size = 1e6;
	static VL fac(size);
	static VL finv(size);
	static VL inv(size);
	static ll n = 0;
	if (n > a) {
		return fac[a] * (finv[b] * finv[a - b] % MOD) % MOD;
	}
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	FOR(i, 2, a + 1) {
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		fac[i] = fac[i - 1] * (ll)i%MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
	n = a + 1;
	return comb(a, b) % MOD;
}