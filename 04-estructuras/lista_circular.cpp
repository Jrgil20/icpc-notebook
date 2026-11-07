// Lista doblemente enlazada (circular) con arreglos: borrar en O(1), recorrer vecinos.
// Uso tipico: Josephus / eliminar elementos de un circulo / simular una fila con borrados.
struct CircList {
    vector<int> nxt, prv;
    CircList(int n) : nxt(n), prv(n) { for (int i = 0; i < n; i++){ nxt[i] = (i + 1) % n; prv[i] = (i - 1 + n) % n; } }
    void erase(int x){ nxt[prv[x]] = nxt[x]; prv[nxt[x]] = prv[x]; }   // x deja el circulo; nxt[x] sigue valido
};
// Josephus clasico: n personas, se elimina cada k-esima. O(n*k). Devuelve el sobreviviente (0-indexado).
int josephus(int n, int k){ CircList L(n); int cur = 0, alive = n;
    while (alive > 1){ for (int i = 1; i < k; i++) cur = L.nxt[cur]; int nx = L.nxt[cur]; L.erase(cur); cur = nx; alive--; }
    return cur; }
// Formula O(n) del Josephus clasico: J(1)=0, J(i) = (J(i-1) + k) % i
int josephusFormula(int n, int k){ int r = 0; for (int i = 2; i <= n; i++) r = (r + k) % i; return r; }
