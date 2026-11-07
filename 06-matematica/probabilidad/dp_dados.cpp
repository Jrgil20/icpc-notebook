// DP de probabilidad: distribucion de la suma de n dados de c caras
// Requiere: reales/base_flotante.cpp (ld)
vector<ld> diceSum(int n, int c){ vector<ld> dp(1, 1.0L);
    for (int t = 0; t < n; t++){ vector<ld> nd(dp.size() + c, 0);
        for (size_t s = 0; s < dp.size(); s++) if (dp[s] > 0) for (int f = 1; f <= c; f++) nd[s + f] += dp[s] / c;
        dp = nd; }
    return dp; } // dp[s] = P(suma = s)
