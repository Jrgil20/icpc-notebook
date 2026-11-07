// Dos punteros: subarreglo mas largo con suma <= K (valores >= 0)
int longestAtMost(vector<ll>& a, ll K){ int best = 0; ll s = 0;
    for (int l = 0, r = 0; r < (int)a.size(); r++){ s += a[r]; while (s > K) s -= a[l++]; best = max(best, r - l + 1); }
    return best; }
