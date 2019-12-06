
template<class Val = bool, Val ignore = false>
class TrieTree {
	Val m_val;
	std::vector<std::unique_ptr<TrieTree>> m_next;

	auto emplace(const std::vector<int>& vec, Val val, int it) {
		if (it == vec.size()) {
			m_val = val;
			return;
		}
		if (!m_next[vec[it]]) {
			m_next[vec[it]] = std::make_unique<TrieTree>();
		}
		m_next[vec[it]]->emplace(vec, val, it + 1);
	}

	auto find(const std::vector<int>& vec, int it)const {
		if (it == vec.size()) { return m_val; }
		if (!m_next[vec[it]]) { return ignore; }
		return m_next[vec[it]]->find(vec, it + 1);
	}

public:
	TrieTree() : TrieTree(ignore) {}
	TrieTree(Val val) :m_val(val), m_next(std::vector<std::unique_ptr<TrieTree>>(26)) {}

	auto emplace(const std::vector<int>& vec, Val val) { return emplace(vec, val, 0); }

	auto find(const std::vector<int>& vec) { return find(vec, 0); }
};
