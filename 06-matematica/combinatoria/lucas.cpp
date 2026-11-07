// Lucas: C(n, k) mod p primo PEQUENO (p <= ~1e6), n y k enormes
// Requiere: aritmetica-modular/mulmod_int128.cpp
ll nCrSmall(ll n, ll k, ll p){ if (k < 0 || k > n) return 0; ll r = 1;
    for (ll i = 0; i < k; i++){ r = r * ((n - i) % p) % p; r = r * powmod(i + 1, p - 2, p) % p; } return r; }
ll lucas(ll n, ll k, ll p){ if (k == 0) return 1; return nCrSmall(n % p, k % p, p) * lucas(n / p, k / p, p) % p; }
