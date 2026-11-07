// Miller-Rabin determinista para n < 2^64
// Requiere: aritmetica-modular/mulmod_int128.cpp
bool isPrime(ll n){ if (n < 2) return false;
    for (ll p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) if (n % p == 0) return n == p;
    ll d = n - 1; int s = 0; while (d % 2 == 0){ d /= 2; s++; }
    for (ll a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){ ll x = powmod(a, d, n); if (x == 1 || x == n - 1) continue;
        bool comp = true; for (int r = 1; r < s; r++){ x = mulmod(x, x, n); if (x == n - 1){ comp = false; break; } }
        if (comp) return false; }
    return true; }
