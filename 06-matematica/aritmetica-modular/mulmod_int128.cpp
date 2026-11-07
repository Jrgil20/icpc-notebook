// Multiplicacion y potencia con modulos grandes (hasta ~4e18)
typedef __int128 lll;
ll mulmod(ll a, ll b, ll m){ return (ll)((lll)a * b % m); }
ll powmod(ll b, ll e, ll m){ ll r = 1 % m; b %= m; if (b < 0) b += m;
    while (e){ if (e & 1) r = mulmod(r, b, m); b = mulmod(b, b, m); e >>= 1; } return r; }
void print128(lll x){ if (x < 0){ putchar('-'); x = -x; } if (x > 9) print128(x / 10); putchar('0' + (int)(x % 10)); }
