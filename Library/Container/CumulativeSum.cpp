/**
 *  累積和を生成
 *  閉区間([l,r])における値を取得
 */
class CumulativeSum {
	const ll size;
	std::vector<ll> sumList;
public:

	CumulativeSum() = delete;
	CumulativeSum(const std::vector<ll>& v) :size(v.size()), sumList(size + 1) {
		for (ll i = 0; i < size; ++i) {
			sumList[i + 1] = sumList[i] + v[i];
		}
	}
	ll get(ll n) {
		return sumList[n + 1];
	}
	ll get(ll l, ll r) {
		if (r < l) { return 0LL; }
		l = std::max(l, 0LL); r = std::min(r, size - 1);
		return sumList[r + 1] - sumList[l];
	}
};
