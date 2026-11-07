// Dijkstra (banned = nodo a ignorar, -1 = ninguno)
vector<ll> dijkstra(int s, vector<vector<pair<int,ll>>>& adj, int banned = -1){
    vector<ll> d(adj.size(), INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    d[s] = 0; pq.push({0, s});
    while (!pq.empty()){ auto [du, u] = pq.top(); pq.pop();
        if (du > d[u]) continue;
        for (auto [v, w] : adj[u]){ if (v == banned) continue;
            if (d[u] + w < d[v]){ d[v] = d[u] + w; pq.push({d[v], v}); } } }
    return d;
}
