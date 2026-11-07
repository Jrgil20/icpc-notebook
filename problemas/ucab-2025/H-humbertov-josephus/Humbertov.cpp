#include <bits/stdc++.h>
using namespace std;
// Simulacion con lista circular (nxt): el que escribe pasa la hoja a su izquierda (i + 1); el primero que
// reciba la hoja con MCD > 1 sale. Si nadie, la hoja vuelve al que escribio: MCD(x, x) = x > 1 y sale el.
// La siguiente ronda la empieza el de la izquierda del eliminado.
int main(){
    int t; if (scanf("%d", &t) != 1) return 0;
    while (t--){ int n; if (scanf("%d", &n) != 1) return 0;
        vector<int> nxt(n + 1), prv(n + 1);
        for (int i = 2; i <= n; i++){ nxt[i] = i == n ? 2 : i + 1; prv[i] = i == 2 ? n : i - 1; }
        int alive = n - 1, start = 2;
        while (alive > 1){
            int w = start, cur = nxt[w];
            while (__gcd(cur, w) == 1) cur = nxt[cur];      // termina: cur == w da MCD = w > 1
            nxt[prv[cur]] = nxt[cur]; prv[nxt[cur]] = prv[cur]; start = nxt[cur]; alive--; }
        printf("%d\n", start); }
}
