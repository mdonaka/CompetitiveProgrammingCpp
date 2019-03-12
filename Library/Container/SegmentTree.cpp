/**
 *	セグメント木を構成する
 *	2methodの変更により調整
 */
class SegmentTree {
private:
	const ll initialValue = (1LL << 31) - 1;
	const ll ignoreValue = (1LL << 31) - 1;

	const ll m_size;
	std::vector<ll> m_node;

	ll calcSize(ll n) {
		ll size = 1;
		while (size < n) {
			size *= 2;
		}
		return size;
	}

	void update(ll k, ll x) {
		m_node[k] = x;
	}

	ll merge(ll xl, ll xr) {
		return std::min(xl, xr);
	}
public:
	SegmentTree(ll n) :
		m_size(calcSize(n)),
		m_node(m_size * 2 - 1, initialValue) {
	}

	void add(ll itr, ll val) {
		ll i = itr + m_size - 1;
		update(i, val);

		while (i > 0) {
			i = (i - 1) / 2;
			m_node[i] = merge(m_node[i * 2 + 1], m_node[i * 2 + 2]);
		}
		/**
		cout << "-- tree -- " << endl;
		REP(i, 2 * m_size - 1) {
		cout << m_node[i] << endl;
		}
		/*//**/
	}

	ll query(ll a, ll b) { return query(a, b + 1, 0, 0, m_size); }
	ll query(ll a, ll b, ll k, ll l, ll r) {
		if (r <= a || b <= l) { return ignoreValue; }
		if (a <= l && r <= b) { return m_node[k]; }
		return merge(
			query(a, b, 2 * k + 1, l, (l + r) / 2),
			query(a, b, 2 * k + 2, (l + r) / 2, r)
		);
	}
};