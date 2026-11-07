// Phi de Euler: phi(n) = cantidad de 1..n coprimos con n
ll phi(ll n){ ll r = n; for (ll p = 2; p * p <= n; p++) if (n % p == 0){ while (n % p == 0) n /= p; r -= r / p; } if (n > 1) r -= r / n; return r; }
vector<int> phiSieve(int n){ vector<int> ph(n + 1); iota(ph.begin(), ph.end(), 0);
    for (int i = 2; i <= n; i++) if (ph[i] == i) for (int j = i; j <= n; j += i) ph[j] -= ph[j] / i; return ph; }
