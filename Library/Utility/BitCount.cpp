long long bitConut(long long n) {
	long long c = 0;
	for (; n != 0; n &= n - 1) { ++c; }
	return c;
}
