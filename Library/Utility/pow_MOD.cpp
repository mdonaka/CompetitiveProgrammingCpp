/**
 *	MOD付きの累乗計算
 */
ll pow(ll a, ll b) {
	ll ans = 1;
	while (b > 0) {
		if (b % 2 == 1) {
			ans *= a;
			ans %= MOD;
		}
		b /= 2;
		a *= a;
		a %= MOD;
	}
	return ans;
}