#include "../../00-base/header.h"
#include "../../03-grafos/bfs.cpp"
#include "../../03-grafos/bfs_grilla.cpp"
#include "../../03-grafos/componentes.cpp"
#include "../../03-grafos/dijkstra.cpp"
#include "../../03-grafos/toposort.cpp"
#include "../../03-grafos/dsu.cpp"
#include "../../03-grafos/kruskal.cpp"
#include "../../03-grafos/arbol_dfs_puentes.cpp"
#include "../../03-grafos/lca.cpp"
#include "../../03-grafos/rerooting.cpp"
#include "../../03-grafos/hopcroft_karp.cpp"
#include "../../03-grafos/dinic.cpp"
#include "../../03-grafos/en_camino_mas_corto.cpp"
int main(){
    // BFS
    vector<vector<int>> adj = {{1,2},{0,3},{0,3},{1,2,4},{3}};
    auto d = bfs(0, adj); assert(d[4] == 3);
    vector<string> grid = {"..#", ".#.", "..."}; auto dg = bfsGrid(grid, 0, 0); assert(dg[1][2] == 5);
    int cnt; vector<vector<int>> a2 = {{1},{0},{},{4},{3}}; components(a2, cnt); assert(cnt == 3);
    // Dijkstra
    vector<vector<pair<int,ll>>> w(4); auto ae = [&](int u,int v,ll c){ w[u].push_back({v,c}); w[v].push_back({u,c}); };
    ae(0,1,1); ae(1,3,1); ae(0,2,5); ae(2,3,1);
    auto dd = dijkstra(0, w); assert(dd[3] == 2); auto db = dijkstra(0, w, 1); assert(db[3] == 6);
    // toposort
    vector<vector<int>> dag = {{1,2},{3},{3},{}}; auto ord = toposort(dag); assert(ord.size() == 4 && ord[0] == 0 && ord[3] == 3);
    vector<int> lp(4, 0); for (int u : ord) for (int v : dag[u]) lp[v] = max(lp[v], lp[u] + 1); assert(lp[3] == 2);
    // DSU
    DSU ds(5); ds.unite(0,1); ds.unite(3,4); assert(ds.find(1) == ds.find(0) && ds.find(2) != ds.find(3) && !ds.unite(0,1));
    // DfsTree: triangle 0-1-2 plus bridge 2-3
    DfsTree T(4); T.addEdge(0,1,0); T.addEdge(1,2,1); T.addEdge(2,0,2); T.addEdge(2,3,3); T.run();
    assert(T.bridges.size() == 1 && T.bridges[0] == 3); assert(T.isArt[2] && !T.isArt[0]); assert(T.back.size() == 1);
    // LCA vs brute
    mt19937 rng(1);
    for (int tc = 0; tc < 50; tc++){ int n = rng() % 30 + 1; vector<vector<int>> t(n);
        for (int i = 1; i < n; i++){ int p = rng() % i; t[i].push_back(p); t[p].push_back(i); }
        LCA L(t); for (int q = 0; q < 30; q++){ int x = rng() % n, y = rng() % n; auto bx = bfs(x, t); assert(L.dist(x, y) == bx[y]); }
        auto sd = sumDistAll(t); for (int x = 0; x < n; x++){ auto bx = bfs(x, t); ll s = 0; for (int v : bx) s += v; assert(sd[x] == s); } }
    // Matching vs flow
    for (int tc = 0; tc < 50; tc++){ int L = rng() % 8 + 1, R = rng() % 8 + 1; HopcroftKarp hk(L, R); Dinic fl(L + R + 2);
        int s = L + R, t = s + 1; for (int i = 0; i < L; i++) fl.addEdge(s, i, 1); for (int j = 0; j < R; j++) fl.addEdge(L + j, t, 1);
        for (int i = 0; i < L; i++) for (int j = 0; j < R; j++) if (rng() % 3 == 0){ hk.addEdge(i, j); fl.addEdge(i, L + j, 1); }
        assert(hk.maxMatching() == fl.maxflow(s, t)); }

    // Kruskal vs Prim O(n^2) en grafos aleatorios completos
    for (int tc = 0; tc < 100; tc++){ int n = rng() % 8 + 2; vector<array<ll,3>> E; vector<vector<ll>> W(n, vector<ll>(n));
        for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++){ ll w = rng() % 100; E.push_back({w, i, j}); W[i][j] = W[j][i] = w; }
        auto [tot, used] = kruskal(n, E); assert((int)used.size() == n - 1);
        vector<bool> in(n); vector<ll> best(n, INF); best[0] = 0; ll prim = 0;
        for (int it = 0; it < n; it++){ int u = -1; for (int v = 0; v < n; v++) if (!in[v] && (u == -1 || best[v] < best[u])) u = v;
            in[u] = true; prim += best[u]; for (int v = 0; v < n; v++) if (!in[v]) best[v] = min(best[v], W[u][v]); }
        assert(tot == prim); }
    { vector<array<ll,3>> E = {{1, 0, 1}, {2, 2, 3}}; assert(kruskal(4, E).second.size() == 2); }  // no conexo: 2 < 3
    // onShortestPath: camino 0-1-2 y atajo 0-3-2 del mismo largo; 4 colgado de 1
    { vector<vector<int>> g = {{1,3},{0,2,4},{1,3},{0,2},{1}}; auto ds0 = bfs(0, g), dt = bfs(2, g); auto on = onShortestPath(ds0, dt, 2);
      assert(on[0] && on[1] && on[2] && on[3] && !on[4]); }
    puts("grafos OK");
}
