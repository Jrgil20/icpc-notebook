#include <bits/stdc++.h>
using namespace std;
// BFS desde U, Se, Sa y D. Un punto v sirve para caminar juntos si esta en un camino mas corto de U a cada casa:
// dU[v] + dX[v] == dU[X] para X = Se, Sa, D. Se elige el v con dU[v] maximo.
vector<int> bfs(int s, vector<vector<int>>& g){ vector<int> d(g.size(), -1); queue<int> q; d[s] = 0; q.push(s);
    while (!q.empty()){ int u = q.front(); q.pop(); for (int v : g[u]) if (d[v] == -1){ d[v] = d[u] + 1; q.push(v); } } return d; }
int main(){
    int n, U, A, B, C, m; if (scanf("%d %d %d %d %d %d", &n, &U, &A, &B, &C, &m) != 6) return 0;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++){ int x, y; if (scanf("%d %d", &x, &y) != 2) return 0; g[x].push_back(y); g[y].push_back(x); }
    auto dU = bfs(U, g), dA = bfs(A, g), dB = bfs(B, g), dC = bfs(C, g);
    int best = U;
    for (int v = 1; v <= n; v++){
        if (dU[v] == -1) continue;
        bool ok = dU[v] + dA[v] == dU[A] && dU[v] + dB[v] == dU[B] && dU[v] + dC[v] == dU[C];
        if (ok && dU[v] > dU[best]) best = v; }
    printf("%d %d %d %d\n", dU[best], dA[best], dB[best], dC[best]);
}
