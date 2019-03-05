/**
 *  素因数分解をし，全ての素因数を返す
 */
multiset<ll> prime_decomposition(ll n) {
	ll i = 2;
	multiset<ll> table{};
	while (i * i <= n) {
		while (n % i == 0) {
			n /= i;
			table.emplace(i);
		}++i;
	}
	if (n > 1) {
		table.emplace(n);
		return table;
	}
	return table;
}