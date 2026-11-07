#include <bits/stdc++.h>
using namespace std;
// Infectados = tamano de la componente conexa del computador inicial. DSU con tamanos.
struct DSU { vector<int> p, sz; DSU(int n) : p(n), sz(n, 1) { iota(p.begin(), p.end(), 0); }
    int find(int x){ while (p[x] != x) x = p[x] = p[p[x]]; return x; }
    void unite(int a, int b){ a = find(a); b = find(b); if (a == b) return; if (sz[a] < sz[b]) swap(a, b); p[b] = a; sz[a] += sz[b]; } };
int main(){
    int n, m, q; if (scanf("%d %d %d", &n, &m, &q) != 3) return 0; DSU d(n + 1);
    for (int i = 0; i < m; i++){ int u, v; if (scanf("%d %d", &u, &v) != 2) return 0; d.unite(u, v); }
    while (q--){ int s; if (scanf("%d", &s) != 1) return 0; printf("%d\n", d.sz[d.find(s)]); }
}
