long long inv(long long a, long long m) {
  long long u = 0, v = 1, mod = m;
  while (a != 0) {
    long long t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  return (u % mod + mod) % mod;
}

long long binpow(long long a, long long b, long long MOD) {
	long long res = 1;
	a %= MOD;
	while(b) {
		if(b & 1) {
			res = res*a % MOD;
		}
		a *= a % MOD;
		b >>= 1;
	}
	return res;
}
