/**
 *	立っているビットの数を数える
 */
ll bitConut(ll n) {
	ll c = 0;
	for (; n != 0; n &= n - 1) { ++c; }
	return c;
}
