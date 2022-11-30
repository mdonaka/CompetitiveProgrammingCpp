#pragma once
#include <vector>

class ModCalculator {
    const long long m_mod;
    const std::vector<long long> m_fac;
    const std::vector<long long> m_finv;

    auto constructFac(long long s) {
        std::vector<long long> fac(s);
        fac[0] = fac[1] = 1;
        for(long long i = 2; i < s; ++i) {
            fac[i] = fac[i - 1] * i;
            if(fac[i] > m_mod) { fac[i] %= m_mod; }
        }
        return fac;
    }
    auto constructInv(long long s) {
        std::vector<long long> finv(s);
        finv[s - 1] = this->pow(m_fac[s - 1], m_mod - 2);
        for(long long i = s - 2; i >= 0; --i) {
            finv[i] = finv[i + 1] * (i + 1);
            if(finv[i] > m_mod) { finv[i] %= m_mod; }
        }
        return finv;
    }
public:
    ModCalculator(long long mod, long long size = 3 * 1e6) :
        m_mod(mod), m_fac(constructFac(size)), m_finv(constructInv(size)) {
    }

    static long long pow(long long a, long long b, long long mod) {
        a %= mod;
        long long ans = 1;
        while(b > 0) {
            if(b & 1) { ans *= a; if(ans >= mod) { ans %= mod; } }
            b >>= 1; a *= a; if(a >= mod) { a %= mod; }
        }
        return ans;
    }
    long long pow(long long a, long long b) const { return pow(a, b, m_mod); }

    auto fact(int n) const {
        if(n < 0) { return 0LL; }
        return m_fac[n];
    }

    auto factInv(int n) const {
        if(n < 0) { return 0LL; }
        return m_finv[n];
    }

    auto comb(int n, int r) const {
        auto val = fact(n) * factInv(r);
        if(val >= m_mod) { val %= m_mod; }
        val *= factInv(n - r);
        if(val >= m_mod) { val %= m_mod; }
        return val;
    }

    auto perm(int n, int r) const {
        auto val = fact(n) * factInv(n - r);
        if(val >= m_mod) { val %= m_mod; }
        return val;
    }

};
