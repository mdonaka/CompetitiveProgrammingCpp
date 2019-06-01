/**
 *	セグメント木を構成する
 *	2methodの変更により調整
 */
template<class T>
class SegmentTree {
private:
	const T initialValue = T(1, 0);
	const T ignoreValue = T(1, 0);

	const ll m_size;
	vector<T> m_node;

	ll calcSize(ll n) {
		ll size = 1;
		while (size < n) {
			size *= 2;
		}
		return size;
	}

	/**
	 * 値の更新(更新:=, 加算:+=, etc...)
	 */
	void update(ll k, T x) {
		m_node[k] = x;
	}

	/**
	* 値の併合
	*/
	T merge(T xl, T xr) {
		return T(xl.first*xr.first, xl.second*xr.first + xr.second);
	}
public:
	SegmentTree(ll n) :
		m_size(calcSize(n)),
		m_node(m_size * 2 - 1, initialValue) {
	}

	void add(ll itr, T val) {
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

	T query(ll a, ll b) { return query(a, b + 1, 0, 0, m_size); }
	T query(ll a, ll b, ll k, ll l, ll r) {
		if (r <= a || b <= l) { return ignoreValue; }
		if (a <= l && r <= b) { return m_node[k]; }
		return merge(
			query(a, b, 2 * k + 1, l, (l + r) / 2),
			query(a, b, 2 * k + 2, (l + r) / 2, r)
		);
	}
};