// Fenwick (indices 1..n) + k-esimo
struct BIT {
    int n; vector<ll> t;
    BIT(int n) : n(n), t(n + 1, 0) {}
    void add(int i, ll v){ for (; i <= n; i += i & -i) t[i] += v; }
    ll sum(int i){ ll s = 0; for (; i > 0; i -= i & -i) s += t[i]; return s; }
    ll sum(int l, int r){ return sum(r) - sum(l - 1); }
    int kth(ll k){ int pos = 0; // menor pos con sum(pos) >= k (valores >= 0)
        for (int pw = 1 << __lg(n); pw; pw >>= 1)
            if (pos + pw <= n && t[pos + pw] < k){ pos += pw; k -= t[pos]; }
        return pos + 1; }
};
