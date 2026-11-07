// Sumas cerradas (con __int128 para no desbordar)
// Requiere: aritmetica-modular/mulmod_int128.cpp
lll sum1(ll n){ return (lll)n * (n + 1) / 2; }                         // 1 + 2 + ... + n
lll sum2(ll n){ return (lll)n * (n + 1) * (2 * n + 1) / 6; }           // 1^2 + ... + n^2
lll sum3(ll n){ lll s = sum1(n); return s * s; }                        // 1^3 + ... + n^3
ll geoSum(ll r, ll n, ll m){ // 1 + r + r^2 + ... + r^(n-1) mod m, m cualquiera
    if (n == 0) return 0; if (n % 2 == 1) return (1 + mulmod(r % m, geoSum(r, n - 1, m), m)) % m;
    ll h = geoSum(r, n / 2, m); return mulmod(h, (1 + powmod(r, n / 2, m)) % m, m); }
