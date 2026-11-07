// Sumas prefijas 2D (indices 1..n, 1..m)
vector<vector<ll>> pref2D(vector<vector<ll>>& a){ int n = a.size(), m = a[0].size();
    vector<vector<ll>> p(n + 1, vector<ll>(m + 1, 0));
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) p[i][j] = a[i-1][j-1] + p[i-1][j] + p[i][j-1] - p[i-1][j-1];
    return p; }
ll rect(vector<vector<ll>>& p, int r1, int c1, int r2, int c2){ // inclusivo, 1-indexado
    return p[r2][c2] - p[r1-1][c2] - p[r2][c1-1] + p[r1-1][c1-1]; }
