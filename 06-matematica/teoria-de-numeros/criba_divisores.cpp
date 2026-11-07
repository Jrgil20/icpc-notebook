// Criba, divisores, factorizacion
vector<int> sieve(int n){ vector<int> spf(n + 1, 0); // spf[x] = menor primo que divide x
    for (int i = 2; i <= n; i++) if (!spf[i]) for (int j = i; j <= n; j += i) if (!spf[j]) spf[j] = i;
    return spf; }
vector<ll> divisors(ll n){ vector<ll> d; for (ll i = 1; i * i <= n; i++) if (n % i == 0){ d.push_back(i); if (i != n / i) d.push_back(n / i); }
    sort(d.begin(), d.end()); return d; }
vector<pair<ll,int>> factorize(ll n){ vector<pair<ll,int>> f;
    for (ll p = 2; p * p <= n; p++) if (n % p == 0){ int e = 0; while (n % p == 0){ n /= p; e++; } f.push_back({p, e}); }
    if (n > 1) f.push_back({n, 1}); return f; }
