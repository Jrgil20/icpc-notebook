// Desarreglos (nadie en su lugar) y Stirling 2da especie
vector<ll> derangements(int n, ll m){ vector<ll> D(max(n + 1, 2), 0); D[0] = 1 % m; D[1] = 0;
    for (int i = 2; i <= n; i++) D[i] = (ll)(i - 1) * ((D[i-1] + D[i-2]) % m) % m; return D; }
// S[n][k] = formas de repartir n elementos distintos en k grupos no vacios
vector<vector<ll>> stirling2(int N, ll m){ vector<vector<ll>> S(N + 1, vector<ll>(N + 1, 0)); S[0][0] = 1;
    for (int n = 1; n <= N; n++) for (int k = 1; k <= n; k++) S[n][k] = (S[n-1][k-1] + (ll)k * S[n-1][k]) % m; return S; }
