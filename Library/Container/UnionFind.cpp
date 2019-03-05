/**
 *	UnionFind木を構成する
 *	nodeの深さ，木のサイズを取得可能
 */
class UnionFind {
public:
	std::vector<ll> m_root;
	std::vector<ll> m_depth;
	std::vector<ll> m_size;
	ll root(ll x) {
		if (m_root[x] == x) return x;
		return m_root[x] = root(m_root[x]);
	}
public:
	UnionFind(ll size_) : m_root(size_), m_depth(size_, 0), m_size(size_, 1) {
		std::iota(m_root.begin(), m_root.end(), 0);
	}
	void unite(ll x, ll y) {
		x = root(x);
		y = root(y);
		if (x == y) return;
		ll t = size(x) + size(y);
		m_size[x] = m_size[y] = t;
		if (m_depth[x] < m_depth[y]) m_root[x] = y;
		else m_root[y] = x;
		if (m_depth[x] == m_depth[y]) ++m_depth[x];
	}
	bool isSame(ll x, ll y) {
		return root(x) == root(y);
	}
	ll size(ll x) {
		if (m_root[x] == x) return m_size[x];
		return size(m_root[x] = root(m_root[x]));
	}
};