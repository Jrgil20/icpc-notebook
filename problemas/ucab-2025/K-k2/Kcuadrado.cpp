#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef __int128 lll;
// Un triangulo de lado k se parte en k^2 triangulitos de lado 1. Modulo 1e18+3: k*k desborda ll -> __int128.
const ll M = 1000000000000000003LL;
int main(){
    int q; if (scanf("%d", &q) != 1) return 0;
    while (q--){ ll k; if (scanf("%lld", &k) != 1) return 0; ll r = (ll)((lll)(k % M) * (k % M) % M); printf("%lld\n", r); }
}
