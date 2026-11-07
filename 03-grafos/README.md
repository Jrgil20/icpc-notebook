# Grafos y árboles

El bloque con más peso en el regional latinoamericano: entre 3 y 5 problemas por edición. Todo en C++ y 0-indexado
(si la entrada es 1-indexada, resta 1 al leer).

| Archivo | Qué hace | Complejidad |
| --- | --- | --- |
| [`bfs.cpp`](bfs.cpp) | Distancias con aristas de costo 1 | O(n + m) |
| [`bfs_grilla.cpp`](bfs_grilla.cpp) | BFS en un laberinto (`#` = pared) | O(R·C) |
| [`componentes.cpp`](componentes.cpp) | Componentes conexas con DFS iterativo | O(n + m) |
| [`dijkstra.cpp`](dijkstra.cpp) | Caminos más cortos con pesos ≥ 0 (opción de ignorar un nodo) | O(m log n) |
| [`en_camino_mas_corto.cpp`](en_camino_mas_corto.cpp) | ¿v está en algún camino más corto de s a t? | O(n) |
| [`toposort.cpp`](toposort.cpp) | Orden topológico (Kahn); detecta ciclos | O(n + m) |
| [`dsu.cpp`](dsu.cpp) | Union-Find | ~O(1) por operación |
| [`kruskal.cpp`](kruskal.cpp) | Árbol de expansión mínima | O(m log m) |
| [`arbol_dfs_puentes.cpp`](arbol_dfs_puentes.cpp) | Árbol DFS, back-edges, puentes, articulaciones | O(n + m) |
| [`lca.cpp`](lca.cpp) | LCA, distancia y k-ésimo ancestro en árboles | O(log n) por consulta |
| [`rerooting.cpp`](rerooting.cpp) | DP "para cada nodo como raíz" | O(n) |
| [`hopcroft_karp.cpp`](hopcroft_karp.cpp) | Matching bipartito máximo | O(m √n) |
| [`dinic.cpp`](dinic.cpp) | Flujo máximo / corte mínimo | O(n² m) peor caso, rápido en la práctica |

**[G1] Leer un grafo** — Cuándo: siempre. Trampa: no dirigido = agrega la arista en ambos sentidos.

```cpp
int n, m; cin >> n >> m;
vector<vector<int>> adj(n);                    // sin pesos
vector<vector<pair<int,ll>>> wadj(n);          // con pesos (vecino, peso)
for (int i = 0; i < m; i++){
    int u, v; ll w; cin >> u >> v >> w; u--; v--;
    adj[u].push_back(v); adj[v].push_back(u);
    wadj[u].push_back({v, w}); wadj[v].push_back({u, w});
}
```

**[G2] BFS (distancias sin peso)** — Cuándo: camino más corto con aristas de costo 1. Trampa: marca `d[v]` al encolar, no al sacar.

Código: [`bfs.cpp`](bfs.cpp)

**[G3] BFS en grilla** — Cuándo: laberintos, `#` = pared. Trampa: revisa límites ANTES de leer `g[nr][nc]`.

Código: [`bfs_grilla.cpp`](bfs_grilla.cpp)

**[G4] DFS iterativo / componentes conexas** — Cuándo: contar componentes, alcanzabilidad. Trampa: DFS recursivo con N = 10^5 en línea puede desbordar la pila; esta versión no.

Código: [`componentes.cpp`](componentes.cpp)

**[G5] Dijkstra (+ omitir un nodo)** — Cuándo: caminos más cortos con pesos ≥ 0. `banned` sirve para el truco "¿todos los caminos óptimos pasan por G?": corre con y sin G y compara. Trampa: `if (du > d[u]) continue;` es obligatorio.

Código: [`dijkstra.cpp`](dijkstra.cpp)

**[G6] Grafo invertido + varias búsquedas** — Cuándo: "¿qué nodos llegan a X?" o "¿existe un v alcanzable por p, a y b a la vez?". En vez de un BFS por nodo (O(n²) BFS), invierte aristas y haz un BFS desde cada nodo especial.

```cpp
vector<vector<int>> radj(n);
for (int u = 0; u < n; u++) for (int v : adj[u]) radj[v].push_back(u);
auto dp = bfs(p, radj), da = bfs(a, radj), db = bfs(b, radj);
for (int v = 0; v < n; v++) if (dp[v] != -1 && da[v] != -1 && db[v] != -1) { /* v llega a p, a y b */ }
```

**[G7] Orden topológico (Kahn) + DP en DAG** — Cuándo: dependencias, "camino más largo", contar caminos en un DAG. Trampa: si `order.size() < n` hay ciclo.

```cpp
vector<int> toposort(vector<vector<int>>& adj){
    int n = adj.size(); vector<int> indeg(n, 0), order;
    for (int u = 0; u < n; u++) for (int v : adj[u]) indeg[v]++;
    queue<int> q; for (int u = 0; u < n; u++) if (!indeg[u]) q.push(u);
    while (!q.empty()){ int u = q.front(); q.pop(); order.push_back(u);
        for (int v : adj[u]) if (--indeg[v] == 0) q.push(v); }
    return order;
}
// DP: camino mas largo
vector<int> lp(n, 0);
for (int u : order) for (int v : adj[u]) lp[v] = max(lp[v], lp[u] + 1);
```

**[G8] DSU (Union-Find)** — Cuándo: unir grupos y preguntar "¿están juntos?", Kruskal. Trampa: compara siempre `find(a) == find(b)`, nunca `p[a] == p[b]`.

Código: [`dsu.cpp`](dsu.cpp)

**[G9] Árbol DFS: back-edges, puentes, articulaciones** — Cuándo: ciclos que no desconectan, aristas críticas, biconexidad. `back` guarda (descendiente, ancestro); `dep` es la profundidad. Trampa: recursivo; N ≤ ~2·10^5 suele estar bien.

Código: [`arbol_dfs_puentes.cpp`](arbol_dfs_puentes.cpp)

**[G10] LCA con binary lifting** — Cuándo: distancia entre nodos de un árbol, k-ésimo ancestro, saltos sobre caminos. O(N log N) preproceso, O(log N) por consulta.

Código: [`lca.cpp`](lca.cpp)

**[G11] Rerooting (DP con cambio de raíz)** — Cuándo: "para CADA nodo como raíz, calcula…" en O(N). Patrón: (1) DP de hijos hacia el padre en orden inverso; (2) pasa la respuesta del padre al hijo. Ejemplo: suma de distancias de cada nodo a todos.

Código: [`rerooting.cpp`](rerooting.cpp)

Variante "mejor y segundo mejor": en el paso 1 guarda, por nodo, el mejor valor y el segundo mejor que venga de un hijo DISTINTO; en el paso 2, si el mejor del padre viene de v, usa el segundo.

**[G12] Matching bipartito (Hopcroft-Karp)** — Cuándo: emparejar máximo izquierda↔derecha (tareas/personas, filas/columnas, color de texto/color de fondo). O(E√V). Conjunto independiente máximo en bipartito = V − matching.

Código: [`hopcroft_karp.cpp`](hopcroft_karp.cpp)

**[G13] Flujo máximo / corte mínimo (Dinic)** — Cuándo: capacidades, "mínimo de aristas a cortar para separar s de t", asignaciones con límites. Truco: un nodo con capacidad c se divide en `v_in → v_out` con capacidad c.

Código: [`dinic.cpp`](dinic.cpp)

**Kruskal** — Ordena las aristas por peso y agrega cada una si une dos componentes distintas (DSU).
Si al final se usaron menos de n − 1 aristas, el grafo no es conexo. Para "repetir el MST y quitar sus aristas"
(UCAB 2025 M) se ordena una sola vez y se marca qué aristas ya se usaron.
Requiere [`dsu.cpp`](dsu.cpp).
Código: [`kruskal.cpp`](kruskal.cpp)

**¿v está en un camino más corto de s a t?** — Sí, exactamente cuando d_s[v] + d_t[v] = d_s[t]. Con un BFS desde s
y otro desde t se marcan todos esos nodos en O(n). Para "caminar juntos el mayor tramo" (UCAB 2025 L) se exige
la condición para cada destino y se toma el v con d_s[v] máximo.
Código: [`en_camino_mas_corto.cpp`](en_camino_mas_corto.cpp).

Tests: [`tests/test_grafos.cpp`](tests/test_grafos.cpp) (LCA y rerooting contra BFS, matching contra flujo, Kruskal contra Prim).
