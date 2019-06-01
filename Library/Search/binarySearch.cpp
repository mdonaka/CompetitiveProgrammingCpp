/**
* 整数値 単調増加
* 単調減少 -> 真偽逆転 ng = ok
*/
ll ok = 1e18;
ll ng = -1;
while (ok - ng > 1) {
	ll mid = (ok + ng) / 2;
	ll isOk = true;
	/*** 判定 ***/
    
	/************/
	if (isOk) { ok = mid; }
	else { ng = mid; }
}
