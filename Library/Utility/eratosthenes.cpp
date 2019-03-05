/**
 *	エラトステネスの篩によって生成された素数判定リストを返す
 */
vector<bool> eratosthenes(ll n) {
	vector<bool> lst(n + 1, true);
	lst[0] = lst[1] = false;
	for (ll i = 2; i < n / 2 + 1; ++i) {
		lst[i * 2] = false;
	}
	for (ll i = 3; i <= n; i += 2) {
		if (lst[i] == false) {
			continue;
		}
		for (ll j = 2; j < n / i + 1; ++j) {
			lst[i*j] = false;
		}
	}
	return lst;
}
