// Triangulo de Pascal: C(n, k) mod CUALQUIER m (n <= ~5000)
vector<vector<ll>> pascal(int N, ll m){ vector<vector<ll>> C(N + 1, vector<ll>(N + 1, 0));
    for (int n = 0; n <= N; n++){ C[n][0] = 1 % m; for (int k = 1; k <= n; k++) C[n][k] = (C[n-1][k-1] + C[n-1][k]) % m; }
    return C; }
