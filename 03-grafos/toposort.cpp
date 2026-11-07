// Toposort Kahn + DP en DAG (camino mas largo)
vector<int> toposort(vector<vector<int>>& adj){
    int n = adj.size(); vector<int> indeg(n, 0), order;
    for (int u = 0; u < n; u++) for (int v : adj[u]) indeg[v]++;
    queue<int> q; for (int u = 0; u < n; u++) if (!indeg[u]) q.push(u);
    while (!q.empty()){ int u = q.front(); q.pop(); order.push_back(u);
        for (int v : adj[u]) if (--indeg[v] == 0) q.push(v); }
    return order; // si order.size() < n -> hay ciclo
}
