#pragma once 

#include <vector>
#include <memory>

constexpr auto nullLambda = [](int n) {};
template<class Val = bool, Val ignore = false>
class TrieTree {
    Val m_val;
    std::vector<std::unique_ptr<TrieTree>> m_next;
    //static constexpr auto nullLambda = [](ll n) {}; c++17

    auto emplace(const std::vector<int>& vec, Val val, int it) {
        if(it == vec.size()) {
            m_val = val;
            return;
        }
        if(!m_next[vec[it]]) {
            m_next[vec[it]] = std::make_unique<TrieTree>();
        }
        m_next[vec[it]]->emplace(vec, val, it + 1);
    }

    template<class Lambda>
    auto find(const std::vector<int>& vec, int it, const Lambda& lambda)const {
        if(m_val != ignore) { lambda(m_val); }
        if(it == vec.size()) { return m_val; }
        if(!m_next[vec[it]]) { return ignore; }
        return m_next[vec[it]]->find(vec, it + 1, lambda);
    }

public:
    TrieTree() : TrieTree(ignore) {}
    TrieTree(Val val) :m_val(val), m_next(std::vector<std::unique_ptr<TrieTree>>(26)) {}

    auto emplace(const std::vector<int>& vec, Val val) { return emplace(vec, val, 0); }

    template<class Lambda = decltype(nullLambda)>
    auto find(const std::vector<int>& vec, const Lambda& lambda = nullLambda) { return find(vec, 0, lambda); }
};