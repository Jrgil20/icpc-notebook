// Bloques de n / i: suma de floor(n / i) para i = 1..n en O(sqrt n)
ll sumFloor(ll n){ ll s = 0; for (ll i = 1; i <= n; ){ ll q = n / i, j = n / q; s += q * (j - i + 1); i = j + 1; } return s; }
