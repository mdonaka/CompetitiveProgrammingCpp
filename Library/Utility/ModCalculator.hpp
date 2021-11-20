#pragma once
#include <vector>

class ModCalculator {
	const long long m_mod;
	const std::vector<long long> m_fac;
	const std::vector<long long> m_finv;

	auto constructFac(long long s) {
		std::vector<long long> fac(s);
		fac[0] = fac[1] = 1;
		for (long long i = 2; i < s; ++i) {
			fac[i] = fac[i - 1] * i;
			if (fac[i] > m_mod) { fac[i] %= m_mod; }
		}
		return fac;
	}
	auto constructInv(long long s) {
		std::vector<long long> finv(s);
		finv[s - 1] = this->pow(m_fac[s - 1], m_mod - 2);
		for (long long i = s - 2; i >= 0; --i) {
			finv[i] = finv[i + 1] * (i + 1);
			if (finv[i] > m_mod) { finv[i] %= m_mod; }
		}
		return finv;
	}
public:
	ModCalculator(long long mod = MOD, long long size = 3 * 1e6) :
		m_mod(mod), m_fac(constructFac(size)), m_finv(constructInv(size)) {}

	long long pow(long long a, long long b) const {
		a %= m_mod;
		if(a == 0) { return 0LL; }
		long long ans = 1;
		while (b > 0) {
			if (b & 1) { ans *= a; if (ans >= m_mod) { ans %= m_mod; } }
			b >>= 1; a *= a; if (a >= m_mod) { a %= m_mod; }
		}
		return ans;
	}

	auto C(int n, int r) const {
		long long val = m_fac[n] * m_finv[r];
		if (val > m_mod) { val %= m_mod; }
		val *= m_finv[n - r];;
		if (val > m_mod) { val %= m_mod; }
		return val;
	}
}calc;

/**
*	MOD‚È‚µcombination
*	n< 51, r<51
*/
long long combFast(long long a, long long b) {
	++a;
	static long long now = 1;
	static std::vector<std::vector<long long>> pascalComb(1);
	pascalComb.reserve(51);
	if (a < now) {
		return pascalComb[a][b];
	}
	for (; now < a + 1; ++now) {
		std::vector<long long> v(now);
		v[0] = v[now - 1] = 1;
		for (long long j = 1; j < now - 1; ++j) {
			v[j] = pascalComb[now - 1][j - 1] + pascalComb[now - 1][j];
		}
		pascalComb.emplace_back(v);
	}
	return pascalComb[a][b];
}

/**
*	ƒVƒ“ƒvƒ‹combination
*	O(r)
*/
long long combSimple(long long a, long long b) {
	if (b > a - b) { return combSimple(a, a - b); }
	long long ans = 1;
	for (long long i = 0; i < b; ++i) {
		ans *= a - i;
		ans %= MOD;
	}
	long long t = 1;
	for (long long i = 1; i < b + 1; ++i) {
		t *= i;
		t %= MOD;
	}
	ans *= calc.pow(t, MOD - 2);
	ans %= MOD;
	return ans;
}