// Kruskal: arbol de expansion minima (MST)
// Requiere: dsu.cpp
// aristas: {peso, u, v}. Devuelve {peso total, ids de aristas usadas}; si used.size() < n-1 el grafo no es conexo.
pair<ll, vector<int>> kruskal(int n, vector<array<ll,3>> edges){
    vector<int> id(edges.size()); iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](int a, int b){ return edges[a][0] < edges[b][0]; });
    DSU dsu(n); ll total = 0; vector<int> used;
    for (int i : id) if (dsu.unite(edges[i][1], edges[i][2])){ total += edges[i][0]; used.push_back(i); }
    return {total, used};
}
