// Segment tree con lazy (suma en rango, sumar en rango), indices 0..n-1
struct SegLazy {
    int n; vector<ll> t, lz;
    SegLazy(int n) : n(n), t(4 * n, 0), lz(4 * n, 0) {}
    void push(int x, int l, int r){ if (!lz[x]) return; int m = (l + r) / 2;
        t[2*x] += lz[x] * (m - l + 1); lz[2*x] += lz[x];
        t[2*x+1] += lz[x] * (r - m); lz[2*x+1] += lz[x]; lz[x] = 0; }
    void update(int a, int b, ll v, int x, int l, int r){
        if (b < l || r < a) return;
        if (a <= l && r <= b){ t[x] += v * (r - l + 1); lz[x] += v; return; }
        push(x, l, r); int m = (l + r) / 2;
        update(a, b, v, 2*x, l, m); update(a, b, v, 2*x+1, m + 1, r); t[x] = t[2*x] + t[2*x+1]; }
    ll query(int a, int b, int x, int l, int r){
        if (b < l || r < a) return 0;
        if (a <= l && r <= b) return t[x];
        push(x, l, r); int m = (l + r) / 2;
        return query(a, b, 2*x, l, m) + query(a, b, 2*x+1, m + 1, r); }
    void update(int a, int b, ll v){ update(a, b, v, 1, 0, n - 1); }
    ll query(int a, int b){ return query(a, b, 1, 0, n - 1); }
};
