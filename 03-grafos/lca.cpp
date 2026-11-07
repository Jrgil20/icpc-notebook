// LCA binary lifting
struct LCA {
    int n, LOG; vector<vector<int>> up; vector<int> dep;
    LCA(vector<vector<int>>& adj, int root = 0) : n(adj.size()) {
        LOG = 1; while ((1 << LOG) < n) LOG++;
        up.assign(LOG, vector<int>(n, root)); dep.assign(n, 0);
        vector<int> st = {root}; vector<bool> vis(n); vis[root] = true;
        while (!st.empty()){ int u = st.back(); st.pop_back();
            for (int v : adj[u]) if (!vis[v]){ vis[v] = true; up[0][v] = u; dep[v] = dep[u] + 1; st.push_back(v); } }
        for (int k = 1; k < LOG; k++) for (int v = 0; v < n; v++) up[k][v] = up[k-1][up[k-1][v]];
    }
    int kth(int v, int k){ for (int i = 0; i < LOG; i++) if (k >> i & 1) v = up[i][v]; return v; }
    int lca(int a, int b){ if (dep[a] < dep[b]) swap(a, b); a = kth(a, dep[a] - dep[b]);
        if (a == b) return a;
        for (int k = LOG - 1; k >= 0; k--) if (up[k][a] != up[k][b]){ a = up[k][a]; b = up[k][b]; }
        return up[0][a]; }
    int dist(int a, int b){ return dep[a] + dep[b] - 2 * dep[lca(a, b)]; }
};
