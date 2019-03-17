/**
 *  累積和を生成
 *  閉区間([l,r])における値を取得
 */
class CumulativeSum {
	std::vector<ll> sumList;
public:

	CumulativeSum() = delete;
	CumulativeSum(const std::vector<ll>& v) :sumList(v.size() + 1) {
		for (ll i = 0; i < v.size(); ++i) {
			sumList[i + 1] = sumList[i] + v[i];
		}
	}
	ll get(ll n) {
		return sumList[n + 1];
	}
	ll get(ll l, ll r) {
        if(r < l){ return 0LL; }
		return sumList[r + 1] - sumList[l];
	}
};