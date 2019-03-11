class SegmentTree {
private:
	const ll m_size;
	const ll m_initialValue;
	std::vector<ll> m_tree;

	ll calcSize(ll n) {
		ll size = 1;
		while (size < n) {
			size *= 2;
		}
		return size;
	}
public:
	SegmentTree(ll n, ll val) :
		m_size(calcSize(n)),
		m_initialValue(val),
		m_tree(m_size * 2 - 1, m_initialValue) {
	}

	void update(ll itr, ll val) {
		ll i = itr + m_size - 1;
		m_tree[i] += val;

		while (i > 0) {
			i = (i - 1) / 2;
			m_tree[i] = m_tree[i * 2 + 1] + m_tree[i * 2 + 2];
		}
	}

	ll query(ll a, ll b) { return query(a, b + 1, 0, 0, m_size); }
	ll query(ll a, ll b, ll k, ll l, ll r) {
		if (r <= a || b <= l) { return m_initialValue; }
		if (a <= l && r <= b) { return m_tree[k]; }
		return query(a, b, 2 * k + 1, l, (l + r) / 2) +
			query(a, b, 2 * k + 2, (l + r) / 2, r);
	}
};