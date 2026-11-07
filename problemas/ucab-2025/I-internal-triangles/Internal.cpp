#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef __int128 lll;
// Triangulos = C(n, 3) = n(n-1)(n-2)/6. Con n hasta 1e18: se divide exacto en __int128 por partes y luego mod.
const ll MD = 1e9 + 7;
int main(){
    int q; if (scanf("%d", &q) != 1) return 0;
    while (q--){ ll n; if (scanf("%lld", &n) != 1) return 0;
        lll a = (lll)n * (n - 1) / 2;                    // C(n,2) exacto (cabe en 128 bits)
        lll r = (a % MD) * ((n - 2) % MD) % MD;          // * (n-2)
        r = r * 333333336 % MD;                          // / 3  (inverso de 3 mod 1e9+7)
        printf("%lld\n", (ll)r); }
}
