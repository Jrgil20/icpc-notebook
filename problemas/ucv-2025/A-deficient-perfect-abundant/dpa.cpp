#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// S(N) = sigma(N) - N, con sigma desde la factorizacion en O(sqrt N). El siguiente abundante esta cerca
// (todo multiplo de 6 mayor que 6 es abundante), asi que se prueba N+1, N+2, ... a lo sumo unos pocos.
ll sigma(ll n){ ll sum = 1;
    for (ll p = 2; p * p <= n; p++) if (n % p == 0){ ll pk = 1, s = 1; while (n % p == 0){ n /= p; pk *= p; s += pk; } sum *= s; }
    if (n > 1) sum *= n + 1; return sum; }
int main(){
    ll n; if (scanf("%lld", &n) != 1) return 0;
    ll s = sigma(n) - n; char c = s < n ? 'D' : (s == n ? 'P' : 'A');
    ll a = n + 1; while (sigma(a) - a <= a) a++;
    printf("%c %lld\n", c, a);
}
