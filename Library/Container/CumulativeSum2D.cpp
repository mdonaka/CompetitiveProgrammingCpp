/**
 *  2次元累積和を生成
 *  閉区間([l1,r1],[l2,r2])における値を取得
 */
class CumulativeSum2D {
private:
	const ll h;
	const ll w;
	std::vector<std::vector<ll>> sumList;
public:

	CumulativeSum2D() = delete;
	CumulativeSum2D(const std::vector<std::vector<ll>>& v) :
		h(v.size()),
		w(v[0].size()),
		sumList(h + 1, std::vector<ll>(w + 1)) {
		for (ll i = 0; i < h; ++i) for (ll j = 0; j < w; ++j) {
			sumList[i + 1][j + 1] = v[i][j];
		}
		for (ll i = 0; i < h; ++i) for (ll j = 0; j < w + 1; ++j) {
			sumList[i + 1][j] += sumList[i][j];
		}
		for (ll i = 0; i < h + 1; ++i) for (ll j = 0; j < w; ++j) {
			sumList[i][j + 1] += sumList[i][j];
		}
	}
	ll get(ll y, ll x) {
		return sumList[y + 1][x + 1];
	}
	ll get(ll y1, ll x1, ll y2, ll x2) {
		if (y2 < y1 || x2 < x1) { return 0LL; }
		x1 = std::max(x1, 0LL); y1 = std::max(y1, 0LL);
		y2 = std::min(y2, h - 1); x2 = std::min(x2, w - 1);
		return sumList[y2 + 1][x2 + 1] + sumList[y1][x1] -
			sumList[y2 + 1][x1] - sumList[y1][x2 + 1];
	}
};
