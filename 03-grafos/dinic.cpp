// Dinic (flujo maximo / corte minimo)
struct Dinic {
    struct E { int to; ll cap; };
    vector<E> e; vector<vector<int>> g; vector<int> lvl, it;
    Dinic(int n) : g(n), lvl(n), it(n) {}
    void addEdge(int u, int v, ll c){ g[u].push_back(e.size()); e.push_back({v, c}); g[v].push_back(e.size()); e.push_back({u, 0}); }
    bool bfs(int s, int t){ fill(lvl.begin(), lvl.end(), -1); lvl[s] = 0; queue<int> q; q.push(s);
        while (!q.empty()){ int u = q.front(); q.pop();
            for (int id : g[u]) if (e[id].cap > 0 && lvl[e[id].to] == -1){ lvl[e[id].to] = lvl[u] + 1; q.push(e[id].to); } }
        return lvl[t] != -1; }
    ll dfs(int u, int t, ll f){ if (u == t) return f;
        for (int &i = it[u]; i < (int)g[u].size(); i++){ int id = g[u][i], v = e[id].to;
            if (e[id].cap > 0 && lvl[v] == lvl[u] + 1){ ll got = dfs(v, t, min(f, e[id].cap));
                if (got){ e[id].cap -= got; e[id ^ 1].cap += got; return got; } } }
        return 0; }
    ll maxflow(int s, int t){ ll fl = 0; while (bfs(s, t)){ fill(it.begin(), it.end(), 0); while (ll f = dfs(s, t, INF)) fl += f; } return fl; }
    // corte minimo: tras maxflow, nodos con lvl[v] != -1 estan del lado de s
};
