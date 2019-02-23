class UnionFind {
	std::vector<ll> m_root;
	ll root(ll x) {
		if (m_root[x] == x) { return x; }
		return m_root[x] = root(m_root[x]);
	}
public:
	UnionFind() = delete;
	UnionFind(ll n) :m_root(n) {
		std::iota(m_root.begin(), m_root.end(), 0);
	}

	bool isSame(ll x, ll y) {
		return m_root[x] == m_root[y];
	}

	void merge(ll x, ll y) {
		ll rx = root(x);
		ll ry = root(y);
		if (rx == ry) return;
		m_root[rx] = ry;
	}
};
