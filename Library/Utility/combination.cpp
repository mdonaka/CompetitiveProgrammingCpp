/**
 *	MOD付きの組み合わせ計算
 *	a<1e6, b<1e6
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

/**
*	MODなしの組み合わせ計算
*	a< 51, b<51
*/
ll comb(ll a, ll b) {
	++a;
	static ll now = 1;
	static VVL pascalComb(1);
	pascalComb.reserve(51);
	if (a < now) {
		return pascalComb[a][b];
	}
	for (; now < a + 1; ++now) {
		VL v(now);
		v[0] = v[now - 1] = 1;
		for (ll j = 1; j < now - 1; ++j) {
			v[j] = pascalComb[now - 1][j - 1] + pascalComb[now - 1][j];
		}
		pascalComb.emplace_back(v);
	}
	return pascalComb[a][b];
}