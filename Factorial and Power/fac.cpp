#define MOD 1000000007

ll modpow(ll x, ll n, ll m = MOD) {
  if (x == 0 && n == 0) return 0;
  ll res = 1;
  while (n) {
    if (n & 1) res = ((res % m) * (x % m)) % m;
    x = ((x % m) * (x % m)) % m;
    n >>= 1;
  }
  return res;
}

ll modinv(ll x, ll m = MOD) {
  return modpow(x, m - 2, m);
}

const ll N = 100005;
ll fact[N], inv[N];

void precompute() {
  fact[0] = fact[1] = 1;
  inv[1] = inv[0] = modinv(1);
  rep(i, 2, N) {
    fact[i] = i * fact[i - 1];
    fact[i] %= MOD;
    inv[i] = modinv(fact[i]);
  }
}

ll ncr(ll n, ll r) {
  if (n < r) return 0;
  ll ans = fact[n];
  ans %= MOD;
  ans *= inv[r];
  ans %= MOD;
  ans *= inv[n - r];
  ans %= MOD;
  return ans;
}

ll npr(ll n, ll r) {
  if (n < r) return 0;
  ll ans = fact[n];
  ans %= MOD;
  ans *= inv[n - r];
  ans %= MOD;
  return ans;
}