// BFS
vector<int> bfs(int s, vector<vector<int>>& adj){
    vector<int> d(adj.size(), -1); queue<int> q; d[s] = 0; q.push(s);
    while (!q.empty()){ int u = q.front(); q.pop();
        for (int v : adj[u]) if (d[v] == -1){ d[v] = d[u] + 1; q.push(v); } }
    return d;
}
