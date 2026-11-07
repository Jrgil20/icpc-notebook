// Numero y suma de divisores desde la factorizacion n = p1^e1 * ... * pk^ek
// d(n) = (e1+1)(e2+1)...   sigma(n) = prod (p^(e+1) - 1) / (p - 1)
pair<ll,ll> divCountSum(ll n){ ll cnt = 1, sum = 1;
    for (ll p = 2; p * p <= n; p++) if (n % p == 0){ int e = 0; ll pk = 1, s = 1; while (n % p == 0){ n /= p; e++; pk *= p; s += pk; } cnt *= e + 1; sum *= s; }
    if (n > 1){ cnt *= 2; sum *= n + 1; } return {cnt, sum}; }
