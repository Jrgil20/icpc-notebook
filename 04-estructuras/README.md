# Estructuras de datos

Para muchas consultas o actualizaciones sobre rangos. Elige con la tabla de abajo.

| Necesito… | Archivo |
| --- | --- |
| Suma en rango + actualizar un punto; k-ésimo | [`fenwick.cpp`](fenwick.cpp) |
| `set` con "k-ésimo" y "cuántos son < x" | [`ordered_set.cpp`](ordered_set.cpp) |
| Sumar a un rango + suma de un rango | [`segtree_lazy.cpp`](segtree_lazy.cpp) |
| Racha más larga en un rango + invertir un rango | [`segtree_rachas_flip.cpp`](segtree_rachas_flip.cpp) |
| Mínimo/máximo en rango sin actualizaciones | [`sparse_table.cpp`](sparse_table.cpp) |
| Máximo de rectas a·x + b | [`li_chao.cpp`](li_chao.cpp) |
| Borrar de un círculo en O(1) (Josephus) | [`lista_circular.cpp`](lista_circular.cpp) |
| Actualizaciones que obligan a recalcular todo | Sqrt batching (esqueleto abajo) |

**[D1] Fenwick / BIT** — Índices 1..n. `kth(k)` = menor posición cuya suma prefija ≥ k (valores ≥ 0). Trampa: ¡nunca uses el índice 0!

Código: [`fenwick.cpp`](fenwick.cpp)

**[D2] Ordered set (PBDS)** — Cuándo: un `set` que además responde "k-ésimo" y "posición de x" en O(log n). Trampa: no admite repetidos; para multiset guarda `pair<valor, id_unico>`. Pon estas líneas debajo de `using namespace std;`.

```cpp
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ordered_set os; os.insert(5); os.erase(5);
*os.find_by_order(k);   // k-esimo (0-indexado)
os.order_of_key(x);     // cuantos elementos son < x
```

**[D3] Segment tree con lazy (sumar en rango, suma de rango)** — Índices 0..n-1, rangos inclusivos. Para mínimo: cambia `+` por `min`, el neutro 0 por INF, y `t[x] += v*(largo)` por `t[x] += v`.

Código: [`segtree_lazy.cpp`](segtree_lazy.cpp)

**[D4] Sparse table (RMQ en O(1))** — Cuándo: arreglo fijo, miles de consultas min/max. Sirve para min, max, gcd (operaciones idempotentes), no para suma.

Código: [`sparse_table.cpp`](sparse_table.cpp)

**[D5] Li-Chao tree (máximo de rectas)** — Cuándo: insertar rectas a·x+b y preguntar el máximo en un x entero de [lo, hi]; también con cualquier familia donde dos funciones se cruzan a lo sumo una vez (cambia `eval`). Para mínimo: inserta (−a, −b) y niega la respuesta. Trampa: cuida que a·x no desborde `ll`.

Código: [`li_chao.cpp`](li_chao.cpp)

**[D6] Sqrt batching (esqueleto)** — Cuándo: hay un recalculo global caro (O(N) o O(M), p. ej. DP en orden topológico) y las actualizaciones lo invalidan. Agrupa las actualizaciones en bloques de tamaño B ≈ √Q: entre recalculos, responde con el valor base + corrección por las ≤ B actualizaciones pendientes.

```cpp
const int B = 400;                      // ~ sqrt(numero de operaciones)
vector<Upd> pend;                       // actualizaciones aun no aplicadas al "base"
rebuild();                              // calcula base[] con todo aplicado, O(N)
for (auto &op : ops){
    if (op.esUpdate){
        pend.push_back(op.upd);
        if ((int)pend.size() == B){ aplicar(pend); rebuild(); pend.clear(); }
    } else {
        ll r = base[op.i];
        for (auto &u : pend) r += efecto(u, op.i);   // correccion O(B)
        cout << r << "\n";
    }
}
// total: O((Q/B)*N + Q*B), minimo con B ~ sqrt(N)
```

**[D7] Segment tree con merge personalizado** — Cuándo: la respuesta de un rango no es una suma, sino algo que se
arma uniendo dos mitades (racha más larga, mejor subarreglo, etc.). Cada nodo guarda prefijo, sufijo y mejor
racha; al unir, la mejor racha es max(mejor izq, mejor der, sufijo izq + prefijo der). Para "invertir" un rango se
guardan los datos de 0s y de 1s y la lazy solo los intercambia. Resuelve UCV 2025 B (Midnight Craving).
Código: [`segtree_rachas_flip.cpp`](segtree_rachas_flip.cpp).

**[D8] Lista circular con arreglos** — `nxt[i]` y `prv[i]`; borrar x es `nxt[prv[x]] = nxt[x]; prv[nxt[x]] = prv[x]`.
Para simular círculos donde se elimina gente (UCAB 2025 H). Incluye el Josephus clásico y su fórmula O(n).
Código: [`lista_circular.cpp`](lista_circular.cpp).

Tests: [`tests/test_estructuras.cpp`](tests/test_estructuras.cpp) (todo contra fuerza bruta).
