// C(n, k) mod p primo con n enorme (hasta 1e18) y k pequeno (k < p)
// Requiere: aritmetica-modular/mulmod_int128.cpp
ll nCrBig(ll n, ll k, ll p){ if (k < 0 || k > n) return 0; ll num = 1, den = 1;
    for (ll i = 0; i < k; i++){ num = mulmod(num, (n - i) % p, p); den = mulmod(den, (i + 1) % p, p); }
    return mulmod(num, powmod(den, p - 2, p), p); }
