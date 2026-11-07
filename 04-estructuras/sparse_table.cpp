// Sparse table (minimo en rango O(1))
struct Sparse {
    vector<vector<ll>> st;
    Sparse(vector<ll>& a){ int n = a.size(), K = __lg(n) + 1; st.assign(K, a);
        for (int k = 1; k < K; k++) for (int i = 0; i + (1 << k) <= n; i++)
            st[k][i] = min(st[k-1][i], st[k-1][i + (1 << (k-1))]); }
    ll query(int l, int r){ int k = __lg(r - l + 1); return min(st[k][l], st[k][r - (1 << k) + 1]); }
};
