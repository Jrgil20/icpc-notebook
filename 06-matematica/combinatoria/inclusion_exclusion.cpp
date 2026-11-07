// Inclusion-exclusion: cuantos x en [1, N] son divisibles por AL MENOS uno de a[]
// Requiere: aritmetica-modular/mulmod_int128.cpp (lll)
ll countDivisible(ll N, vector<ll>& a){ int k = a.size(); ll res = 0;
    for (int mask = 1; mask < (1 << k); mask++){ ll l = 1; bool big = false;
        for (int i = 0; i < k; i++) if (mask >> i & 1){ l = l / gcd(l, a[i]); if ((lll)l * a[i] > N){ big = true; break; } l *= a[i]; }
        if (big) continue; ll c = N / l; res += (__builtin_popcount(mask) & 1) ? c : -c; }
    return res; }
