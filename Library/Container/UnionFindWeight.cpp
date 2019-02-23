class UnionFindWeight {
public:
	std::vector<ll> m_root;
	std::vector<ll> m_rank;
	std::vector<ll> m_weight;

	ll root(ll x) {
		if (m_root[x] == x) { return x; }
		ll r = root(m_root[x]);
		m_weight[x] += m_weight[m_root[x]];
		return m_root[x] = r;
	}
	ll weight(ll x) {
		root(x);
		return m_weight[x];
	}
public:
	UnionFindWeight() = delete;
	UnionFindWeight(ll n) :m_root(n), m_rank(n), m_weight(n) {
		std::iota(m_root.begin(), m_root.end(), 0);
	}
	bool isSame(ll x, ll y) {
		return root(x) == root(y);
	}
	bool merge(ll x, ll y, ll w) {
		w += weight(x); w -= weight(y);
		x = root(x); y = root(y);
		if (x == y) { return false; }
		if (m_rank[x] < m_rank[y]) { std::swap(x, y); w = -w; }
		if (m_rank[x] == m_rank[y]) { ++m_rank[x]; }
		m_root[y] = x;
		m_weight[y] = w;
		return true;
	}
	ll diffWeight(ll x, ll y) {
		return weight(y) - weight(x);
	}
};