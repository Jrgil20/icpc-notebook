// f[n][x] = # permutaciones de n con x inversiones (sumas prefijas, O(n*X))
vector<vector<ll>> invCount(int N, int X, ll cap = LLONG_MAX / 4){ // cap: tope para no desbordar
    vector<vector<ll>> f(N + 1, vector<ll>(X + 1, 0)); f[0][0] = 1;
    for (int n = 1; n <= N; n++){ vector<ll> g(X + 1); // g = prefijo de f[n-1]
        for (int x = 0; x <= X; x++) g[x] = min(cap, (x ? g[x-1] : 0) + f[n-1][x]);
        for (int x = 0; x <= X; x++) f[n][x] = min(cap, g[x] - (x - n >= 0 ? g[x-n] : 0)); }
    return f; }
