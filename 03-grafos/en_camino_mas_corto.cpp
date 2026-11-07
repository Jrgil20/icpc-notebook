// "v esta en ALGUN camino mas corto de s a t"  <=>  ds[v] + dt[v] == ds[t]
// ds = distancias desde s, dt = distancias desde t (en grafo NO dirigido; si es dirigido, dt en el grafo invertido).
// Sirve con BFS (bfs.cpp, -1 = inalcanzable) o Dijkstra (con ll).
vector<bool> onShortestPath(const vector<int>& ds, const vector<int>& dt, int t){
    int n = ds.size(); vector<bool> on(n, false);
    for (int v = 0; v < n; v++) if (ds[v] != -1 && dt[v] != -1 && ds[v] + dt[v] == ds[t]) on[v] = true;
    return on; }
