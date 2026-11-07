#include <bits/stdc++.h>
using namespace std;
// Repetir: Kruskal sobre las aristas que quedan; si no conecta todo, parar; si conecta, borrar sus aristas.
// Cada ronda quita al menos una arista de cada vertice, asi que hay a lo sumo (grado minimo) <= 50 rondas.
struct DSU { vector<int> p; DSU(int n) : p(n) { iota(p.begin(), p.end(), 0); }
    int find(int x){ while (p[x] != x) x = p[x] = p[p[x]]; return x; }
    bool unite(int a, int b){ a = find(a); b = find(b); if (a == b) return false; p[a] = b; return true; } };
int main(){
    int n, m; if (scanf("%d %d", &n, &m) != 2) return 0;
    vector<array<long long,3>> e(m);
    for (auto &x : e){ if (scanf("%lld %lld %lld", &x[1], &x[2], &x[0]) != 3) return 0; x[1]--; x[2]--; }
    sort(e.begin(), e.end());                              // por peso
    vector<bool> removed(m, false); vector<long long> res;
    while (true){
        DSU d(n); long long w = 0; int cnt = 0; vector<int> used;
        for (int i = 0; i < m; i++) if (!removed[i] && d.unite(e[i][1], e[i][2])){ w += e[i][0]; cnt++; used.push_back(i); }
        if (cnt < n - 1) break;
        res.push_back(w); for (int i : used) removed[i] = true; }
    printf("%d\n", (int)res.size()); for (auto w : res) printf("%lld\n", w);
}
