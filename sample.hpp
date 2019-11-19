#pragma once
#include <random>

namespace Sample {
	class RandomGenerator {
		std::mt19937_64 mt;
	public:
		RandomGenerator(unsigned int seed = std::random_device()()) : mt(std::mt19937_64(seed)) {}

		// [l,r)
		auto random(long long l, long long r) { return (mt() % (r - l)) + l; }
		auto random(long long r) { return random(0, r); }
	};
}