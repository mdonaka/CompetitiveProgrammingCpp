/**
 *	遅延セグメント木を構成する
 *	4methodの変更により調整
 */
class LazySegmentTree {
private:
	const ll initialValue = 0;
	const ll ignoreValue = 0;
	const ll lazyIgnoreValue = 1e5;

	const ll m_size;
	std::vector<ll> m_node;
	std::vector<ll> m_lazy;

	ll calcSize(ll n) {
		ll size = 1;
		while (size < n) {
			size *= 2;
		}
		return size;
	}

	void spreadLazy(ll k) {
		if (k >= m_size - 1) { return; }
		m_lazy[2 * k + 1] = m_lazy[k] / 2;
		m_lazy[2 * k + 2] = m_lazy[k] / 2;
	}
	void reflectLazy(ll k) {
		m_node[k] = m_lazy[k];
	}

	ll merge(ll xl, ll xr) {
		return xl + xr;
	}
	ll rangeUpdate(ll x, ll l, ll r) {
		return x * (r - l);
	}
public:
	LazySegmentTree() = delete;
	LazySegmentTree(ll n) :
		m_size(calcSize(n)),
		m_node(m_size * 2 - 1, initialValue),
		m_lazy(m_size * 2 - 1, lazyIgnoreValue) {
	}

	void add(ll a, ll b, ll x) {
		add(a, b + 1, x, 0, 0, m_size);
		/**
		cout << "-- tree -- " << endl;
		REP(i, 2 * m_size - 1) {
			cout << m_node[i] << " " << m_lazy[i] << endl;
		}
		/*//**/
	}
	void add(ll a, ll b, ll x, ll k, ll l, ll r) {
		eval(k);
		if (r <= a || b <= l) { return; }
		if (a <= l && r <= b) {
			m_lazy[k] = rangeUpdate(x, l, r);
			eval(k);
			return;
		}
		add(a, b, x, 2 * k + 1, l, (l + r) / 2);
		add(a, b, x, 2 * k + 2, (l + r) / 2, r);
		m_node[k] = merge(m_node[2 * k + 1], m_node[2 * k + 2]);
	}
	void eval(ll k) {
		if (m_lazy[k] == lazyIgnoreValue) { return; }
		reflectLazy(k);
		spreadLazy(k);
		m_lazy[k] = lazyIgnoreValue;
	}
	ll query(ll a, ll b) { return query(a, b + 1, 0, 0, m_size); }
	ll query(ll a, ll b, ll k, ll l, ll r) {
		if (r <= a || b <= l) { return ignoreValue; }
		eval(k);
		if (a <= l && r <= b) { return m_node[k]; }
		return merge(
			query(a, b, 2 * k + 1, l, (l + r) / 2),
			query(a, b, 2 * k + 2, (l + r) / 2, r)
		);
	}
};
