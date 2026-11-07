#include <bits/stdc++.h>
using namespace std;
// Lema: el 1 va en un extremo; quitando el 1 queda una montana de tamano N-1. Se colocan 1, 2, ..., N
// de afuera hacia adentro con dos punteros l, r. Si v ya esta escrito, debe estar en l o en r.
// Si ambos extremos estan vacios: cada lado tiene una "fecha limite" = el primer valor conocido de ese lado
// (los huecos antes de el deben llenarse con valores menores). Se pone v del lado con fecha limite menor.
// Empate (es el MISMO valor conocido visto desde ambos lados): se llena primero el lado con menos huecos.
int main(){
    int n; if (scanf("%d", &n) != 1) return 0; vector<int> a(n), pos(n + 1, -1);
    for (int i = 0; i < n; i++){ if (scanf("%d", &a[i]) != 1) return 0; if (a[i]) pos[a[i]] = i; }
    vector<int> nxt(n + 1, n), prv(n + 1, -1);   // nxt[i] = primer j >= i con a[j] != 0; prv[i] = ultimo j < i con a[j] != 0
    for (int i = n - 1; i >= 0; i--) nxt[i] = a[i] ? i : nxt[i + 1];
    for (int i = 0; i < n; i++) prv[i + 1] = a[i] ? i : prv[i];
    int l = 0, r = n - 1; vector<int> res = a;
    for (int v = 1; v <= n; v++){
        if (pos[v] != -1){
            if (pos[v] == l) l++; else if (pos[v] == r) r--; else { puts("*"); return 0; }
            continue;
        }
        bool el = a[l] == 0, er = a[r] == 0;
        if (!el && !er){ puts("*"); return 0; }
        bool putLeft = el;
        if (el && er){
            int pl = nxt[l], pr = prv[r + 1];
            bool inside = pl <= r;                       // hay algun valor conocido dentro de [l, r]
            if (!inside) putLeft = true;                 // todo libre: cualquier lado sirve
            else if (pl != pr) putLeft = a[pl] < a[pr];  // fecha limite menor primero
            else putLeft = (pl - l) <= (r - pr);         // mismo valor: el lado con menos huecos
        }
        if (putLeft) res[l++] = v; else res[r--] = v;
    }
    for (int i = 0; i < n; i++) printf("%d%c", res[i], i == n - 1 ? '\n' : ' ');
}
