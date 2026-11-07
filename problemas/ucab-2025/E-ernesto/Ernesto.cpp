#include <bits/stdc++.h>
using namespace std;
// Contratar a alguien "quema" todo su grupo de amigos (componente conexa). Lo optimo: en cada componente,
// contratar al de mayor tolerancia H. Nombres -> ids con unordered_map; componentes con DSU.
struct DSU { vector<int> p; DSU(int n) : p(n) { iota(p.begin(), p.end(), 0); }
    int find(int x){ while (p[x] != x) x = p[x] = p[p[x]]; return x; }
    void unite(int a, int b){ p[find(a)] = find(b); } };
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++){
        int n, m; cin >> n >> m; vector<string> name(n); vector<long long> h(n); unordered_map<string,int> id; id.reserve(2 * n);
        for (int i = 0; i < n; i++){ cin >> name[i] >> h[i]; id[name[i]] = i; }
        DSU d(n);
        for (int i = 0; i < m; i++){ string a, b; cin >> a >> b; d.unite(id[a], id[b]); }
        vector<int> best(n, -1);
        for (int i = 0; i < n; i++){ int c = d.find(i); if (best[c] == -1 || h[i] > h[best[c]]) best[c] = i; }
        vector<string> out; for (int c = 0; c < n; c++) if (best[c] != -1) out.push_back(name[best[c]]);
        sort(out.begin(), out.end());
        cout << "Case " << tc << ":\n"; for (auto &s : out) cout << s << "\n";
    }
}
