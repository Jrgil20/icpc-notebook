#include <bits/stdc++.h>
using namespace std;
// Simulacion con dos heaps: Emma saca su maximo, Otto su minimo. Cada turno el total de numeros baja en 1,
// asi que hay a lo sumo 2n turnos.
int main(){
    int t; if (scanf("%d", &t) != 1) return 0;
    while (t--){ int n; if (scanf("%d", &n) != 1) return 0;
        priority_queue<long long> emma; priority_queue<long long, vector<long long>, greater<long long>> otto;
        for (int i = 0; i < n; i++){ long long x; if (scanf("%lld", &x) != 1) return 0; emma.push(x); }
        for (int i = 0; i < n; i++){ long long x; if (scanf("%lld", &x) != 1) return 0; otto.push(x); }
        long long turns = 0;
        while (!emma.empty() && !otto.empty()){
            long long e = emma.top(); emma.pop(); long long o = otto.top(); otto.pop(); turns++;
            long long s = e + o;
            if (s % 2) otto.push(s); else emma.push(s / 2); }
        printf("%lld %s\n", turns, emma.empty() ? "Otto" : "Emma"); }
}
