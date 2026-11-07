// Rerooting: suma de distancias desde cada nodo a todos
vector<ll> sumDistAll(vector<vector<int>>& adj){
    int n = adj.size(); vector<int> order, par(n, -1); vector<ll> sz(n, 1), down(n, 0), ans(n);
    vector<int> st = {0}; par[0] = 0;
    while (!st.empty()){ int u = st.back(); st.pop_back(); order.push_back(u);
        for (int v : adj[u]) if (par[v] == -1){ par[v] = u; st.push_back(v); } }
    par[0] = -1;
    for (int i = n - 1; i >= 0; i--){ int u = order[i];       // 1) hijos -> padre
        for (int v : adj[u]) if (v != par[u]){ sz[u] += sz[v]; down[u] += down[v] + sz[v]; } }
    ans[0] = down[0];
    for (int u : order) for (int v : adj[u]) if (v != par[u])  // 2) padre -> hijos
        ans[v] = ans[u] - sz[v] + (n - sz[v]);
    return ans;
}
