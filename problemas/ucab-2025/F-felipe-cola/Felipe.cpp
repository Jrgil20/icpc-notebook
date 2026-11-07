#include <bits/stdc++.h>
using namespace std;
// Cola + suma acumulada: sumar al encolar, restar al desencolar. O(1) por operacion.
int main(){
    int T; if (scanf("%d", &T) != 1) return 0;
    while (T--){ int q; if (scanf("%d", &q) != 1) return 0; queue<long long> Q; long long sum = 0;
        while (q--){ int op; if (scanf("%d", &op) != 1) return 0;
            if (op == 1){ long long v; if (scanf("%lld", &v) != 1) return 0; Q.push(v); sum += v; }
            else if (op == 2){ if (!Q.empty()){ sum -= Q.front(); Q.pop(); } }
            else { if (Q.empty()) puts("Empty!"); else printf("%lld\n", sum); } } }
}
