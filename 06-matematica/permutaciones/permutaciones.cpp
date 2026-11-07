// Permutaciones 0-indexadas: componer, inversa, ciclos
vector<int> compose(const vector<int>& p, const vector<int>& q){ // (p o q)[i] = p[q[i]]
    int n = p.size(); vector<int> r(n); for (int i = 0; i < n; i++) r[i] = p[q[i]]; return r; }
vector<int> inverse(const vector<int>& p){ int n = p.size(); vector<int> r(n); for (int i = 0; i < n; i++) r[p[i]] = i; return r; }
vector<vector<int>> cycles(const vector<int>& p){ int n = p.size(); vector<bool> vis(n); vector<vector<int>> cs;
    for (int i = 0; i < n; i++) if (!vis[i]){ vector<int> c; for (int j = i; !vis[j]; j = p[j]){ vis[j] = true; c.push_back(j); } cs.push_back(c); }
    return cs; }
// swaps minimos para ordenar = n - #ciclos; paridad = (n - #ciclos) % 2; orden (veces hasta volver a identidad) = lcm de largos
vector<int> permPow(const vector<int>& p, ll k){ // p aplicada k veces, O(n)
    vector<int> r(p.size());
    for (auto &c : cycles(p)){ int L = c.size(); for (int i = 0; i < L; i++) r[c[i]] = c[(i + k % L) % L]; }
    return r; }
