/**
*  素因数分解をし，全ての素因数を返す
*/
std::unordered_multiset<ll> prime_decomposition(ll n) {
	ll i = 2;
	std::unordered_multiset<ll> table{};
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
