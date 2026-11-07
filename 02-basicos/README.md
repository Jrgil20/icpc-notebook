# Básicos: prefijos, búsqueda binaria, dos punteros, intervalos

Técnicas que aparecen dentro de casi cualquier problema medio.

| Archivo | Qué hace | Complejidad |
| --- | --- | --- |
| [`prefijos_2d.cpp`](prefijos_2d.cpp) | Suma de cualquier submatriz | O(1) por consulta |
| [`busqueda_binaria_respuesta.cpp`](busqueda_binaria_respuesta.cpp) | Menor x con `ok(x)` verdadero | O(log rango · costo de ok) |
| [`dos_punteros.cpp`](dos_punteros.cpp) | Ventana más larga con suma ≤ K | O(n) |
| [`intervalos_union.cpp`](intervalos_union.cpp) | Longitud total cubierta por intervalos reales | O(n log n) |
| [`intervalos_fusionar.cpp`](intervalos_fusionar.cpp) | Fusionar intervalos enteros solapados | O(n log n) |

**[A1] Sumas prefijas 1D** — Cuándo: muchas consultas "suma de a[l..r]". Trampa: el arreglo `p` mide n+1.

```cpp
vector<ll> p(n + 1, 0);
for (int i = 0; i < n; i++) p[i + 1] = p[i] + a[i];
// suma a[l..r] (0-indexado, inclusivo) = p[r + 1] - p[l]
```

**[A2] Sumas prefijas 2D** — Cuándo: suma de submatrices. Trampa: índices 1-indexados en `rect`.

Código: [`prefijos_2d.cpp`](prefijos_2d.cpp)

**[A3] Búsqueda binaria sobre la respuesta** — Cuándo: "el mínimo X tal que se puede…" y si X sirve, X+1 también sirve. Trampa: `ok` debe ser monótona (F…F T…T); para "el máximo X" invierte la condición.

Código: [`busqueda_binaria_respuesta.cpp`](busqueda_binaria_respuesta.cpp)

**[A4] Dos punteros / ventana deslizante** — Cuándo: subarreglo más largo/corto que cumple algo y la condición se mantiene al encoger. Trampa: requiere valores ≥ 0 (si hay negativos usa prefijos + map).

Código: [`dos_punteros.cpp`](dos_punteros.cpp)

**[IV1] Longitud de la unión** — Cuándo: "cuánto del eje queda cubierto" (sombras, rangos de luz, tramos). O(n log n). Probado con los 3 ejemplos de LAR 2024 J (Jigsaw of Shadows), donde cada intervalo es [X, X + H / tan(θ)].

Código: [`intervalos_union.cpp`](intervalos_union.cpp)

**[IV2] Fusionar intervalos enteros** — Devuelve la lista de bloques disjuntos. Por defecto une [1,3] y [4,6] (se tocan); quita el `+ 1` si no deben unirse.

Código: [`intervalos_fusionar.cpp`](intervalos_fusionar.cpp)

Otros patrones de intervalos: máximo de intervalos solapados en un punto → eventos (+1 en l, −1 en r+1), ordenar y barrer; máximo de intervalos disjuntos → ordenar por extremo derecho y tomar greedy.

Tests: [`tests/test_basicos.cpp`](tests/test_basicos.cpp).
