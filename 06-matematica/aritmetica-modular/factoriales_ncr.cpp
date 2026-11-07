// Modular: potencia, inverso, combinatoria
// Requiere: const ll MD (esta en la plantilla base)
ll pw(ll b, ll e, ll m = MD){ ll r = 1; b %= m; if (b < 0) b += m; while (e){ if (e & 1) r = r * b % m; b = b * b % m; e >>= 1; } return r; }
ll inv(ll a){ return pw(a, MD - 2); } // MD primo
const int MAXF = 1000005; ll fact[MAXF], ifact[MAXF];
void initFact(){ fact[0] = 1; for (int i = 1; i < MAXF; i++) fact[i] = fact[i-1] * i % MD;
    ifact[MAXF-1] = inv(fact[MAXF-1]); for (int i = MAXF - 1; i > 0; i--) ifact[i-1] = ifact[i] * i % MD; }
ll C(int n, int k){ if (k < 0 || k > n) return 0; return fact[n] * ifact[k] % MD * ifact[n-k] % MD; }
