// Hopcroft-Karp (izq 0..L-1, der 0..R-1)
struct HopcroftKarp {
    int L, R; vector<vector<int>> adj; vector<int> mL, mR, dist;
    HopcroftKarp(int L, int R) : L(L), R(R), adj(L), mL(L, -1), mR(R, -1), dist(L) {}
    void addEdge(int u, int v){ adj[u].push_back(v); }
    bool bfs(){ queue<int> q; bool found = false;
        for (int u = 0; u < L; u++){ if (mL[u] == -1){ dist[u] = 0; q.push(u); } else dist[u] = -1; }
        while (!q.empty()){ int u = q.front(); q.pop();
            for (int v : adj[u]){ int w = mR[v];
                if (w == -1) found = true; else if (dist[w] == -1){ dist[w] = dist[u] + 1; q.push(w); } } }
        return found; }
    bool dfs(int u){ for (int v : adj[u]){ int w = mR[v];
            if (w == -1 || (dist[w] == dist[u] + 1 && dfs(w))){ mL[u] = v; mR[v] = u; return true; } }
        dist[u] = -1; return false; }
    int maxMatching(){ int res = 0; while (bfs()) for (int u = 0; u < L; u++) if (mL[u] == -1 && dfs(u)) res++; return res; }
};
