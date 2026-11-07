// DFS tree: profundidad, back-edges, puentes y articulaciones
struct DfsTree {
    int n, timer = 0; vector<vector<pair<int,int>>> adj; // (vecino, id arista)
    vector<int> tin, low, dep, par; vector<bool> isArt; vector<int> bridges; vector<array<int,2>> back;
    DfsTree(int n) : n(n), adj(n), tin(n, -1), low(n), dep(n), par(n, -1), isArt(n) {}
    void addEdge(int u, int v, int id){ adj[u].push_back({v, id}); adj[v].push_back({u, id}); }
    void dfs(int u, int pe){ tin[u] = low[u] = timer++; int ch = 0;
        for (auto [v, id] : adj[u]){ if (id == pe) continue;
            if (tin[v] != -1){ low[u] = min(low[u], tin[v]); if (tin[v] < tin[u]) back.push_back({u, v}); }
            else { par[v] = u; dep[v] = dep[u] + 1; dfs(v, id); low[u] = min(low[u], low[v]); ch++;
                if (low[v] > tin[u]) bridges.push_back(id);
                if (pe != -1 && low[v] >= tin[u]) isArt[u] = true; } }
        if (pe == -1 && ch > 1) isArt[u] = true; }
    void run(){ for (int i = 0; i < n; i++) if (tin[i] == -1) dfs(i, -1); }
};
