# Esqueletos de problema completos

Copia el que se parezca a la entrada y rellena el centro con la plantilla que toque.

| Archivo | Cuándo |
| --- | --- |
| [`t1_n_y_lista.py`](t1_n_y_lista.py) | "N y una lista", con o sin varios casos |
| [`t2_leer_todo.py`](t2_leer_todo.py) | Entrada grande o con formato raro: leer todo de golpe |
| [`t3_grafo_bfs.cpp`](t3_grafo_bfs.cpp) | "Grafo con N nodos y M aristas" |
| [`t4_varios_casos.cpp`](t4_varios_casos.cpp) | Varios casos de prueba en C++ |
| [`t5_interactivo.cpp`](t5_interactivo.cpp) | Problemas interactivos (preguntar al juez) |
| [`t6_stress.sh`](t6_stress.sh) + [`gen.py`](gen.py) + [`brute.py`](brute.py) | Encontrar el caso que rompe tu solución |

**[T1] Python — "N y una lista" (con o sin varios casos)**

```python
import sys
input = sys.stdin.readline

def main():
    t = int(input())                 # quita estas 2 lineas si hay un solo caso
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        print(sum(a))

main()
```

**[T2] Python — leer todo de golpe (entrada grande o formato raro)**

```python
import sys
data = sys.stdin.buffer.read().split()   # todo el input de golpe: lo mas rapido
pos = 0
def nxt():
    global pos
    pos += 1
    return data[pos - 1]
n, m = int(nxt()), int(nxt())
g = [[] for _ in range(n)]
for _ in range(m):
    u, v = int(nxt()) - 1, int(nxt()) - 1
    g[u].append(v); g[v].append(u)
```

Trampa: `data` contiene bytes; para strings usa `nxt().decode()`.

**[T3] C++ — "grafo con N nodos y M aristas" (BFS desde el nodo 1)**

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++){ int u, v; cin >> u >> v; u--; v--; adj[u].push_back(v); adj[v].push_back(u); }
    vector<int> d(n, -1); queue<int> q; d[0] = 0; q.push(0);
    while (!q.empty()){ int u = q.front(); q.pop();
        for (int v : adj[u]) if (d[v] == -1){ d[v] = d[u] + 1; q.push(v); } }
    for (int i = 0; i < n; i++) cout << d[i] << " \n"[i == n - 1];
}
```

**[T4] C++ — varios casos de prueba** — Trampa: reinicia TODAS las estructuras globales dentro del bucle.

```cpp
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<ll> a(n); for (auto &x : a) cin >> x;
        cout << accumulate(a.begin(), a.end(), 0LL) << "\n";
    }
}
```

**[T5] Interactivo (búsqueda binaria contra el juez)** — Trampa: vacía el búfer tras CADA mensaje (`endl` o `cout.flush()` en C++, `print(..., flush=True)` en Python); no uses `sync_with_stdio(false)` sin hacer flush.

```cpp
int main(){
    int lo = 1, hi = 1000000;
    while (lo < hi){
        int mid = lo + (hi - lo) / 2;
        cout << "? " << mid << endl;        // endl SI aqui: hace flush
        string r; cin >> r;                 // formato de respuesta segun el enunciado
        if (r == "<") hi = mid; else lo = mid + 1;
    }
    cout << "! " << lo << endl;
}
```

**[T6] Probar contra fuerza bruta (cuando da WA y no ves por qué)** — Escribe `brute.py` lento pero obvio, un generador de casos pequeños, y compara.

```bash
for i in $(seq 1 500); do
  python3 gen.py $i > in.txt
  ./A < in.txt > o1.txt; python3 brute.py < in.txt > o2.txt
  if ! cmp -s o1.txt o2.txt; then echo "FALLA"; cat in.txt; break; fi
done
```

### Cómo usar el stress test

1. Escribe tu solución en `A.cpp` y compílala como `./A`.
2. Escribe en `brute.py` una solución lenta pero obviamente correcta (fuerza bruta).
3. Ajusta `gen.py` para que genere entradas **pequeñas** con el formato del problema.
4. Corre `./t6_stress.sh`: si encuentra una diferencia, imprime el caso que falla.
