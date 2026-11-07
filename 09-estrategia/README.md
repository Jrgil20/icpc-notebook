# Estrategia, checklist del juez y mapa de problemas

Cómo reconocer qué técnica pide un problema, qué revisar antes de enviar y cómo repartir las 5 horas.

**[J1] Antes de CADA envío** (cada rechazo cuesta 20 minutos de penalización)

1. El archivo se llama como la letra del problema: `A.cpp`, `A.java`, `A.py3`. En Java/Kotlin: sin `package` y la clase pública se llama `A`.
2. Sin `cerr`/prints de depuración: stderr cuenta en el límite de salida (~1 MB) y puede dar Runtime Error.
3. Formato exacto: un espacio entre valores, `\n` al final de cada línea, sin líneas vacías extra (WA vs Presentation Error).
4. `ll` donde haya sumas, productos o distancias. ¿El peor caso desborda `int`?
5. Probaste: ejemplos del enunciado + N mínimo (1) + N máximo + todos iguales + negativos/ceros si se permiten.
6. Complejidad vs límites de la tabla del índice. Si es Python con N ≥ 10^5: pásalo a C++.
7. Decimales con la cantidad de cifras pedida (`setprecision`, `:.Nf`).
8. Interactivo: flush después de cada línea.

**[J2] Veredicto → qué revisar**

| Veredicto | Revisa primero |
| --- | --- |
| Wrong Answer | Desborde, caso N = 1, empates, índices 0/1, inicialización entre casos |
| Time Limit | Complejidad, Python → C++, `endl`, I/O rápido, bucle infinito |
| Runtime Error | Índice fuera de rango, división por 0, recursión profunda, arreglo enorme local, salida en stderr |
| Presentation Error | Espacios al final, líneas vacías, formato de decimales |
| Name/Problem mismatch | Nombre del archivo o de la clase |

**[J3] Estrategia de 5 horas (meta Top 10 SA-Norte = 4–5 problemas)**

| Tiempo | Qué hacer |
| --- | --- |
| 0:00–0:20 | Repartir los 12–13 enunciados entre los 3; cada uno marca fácil / medio / difícil |
| Todo el concurso | Mira el scoreboard: los problemas con más YES en el continente son los fáciles |
| 0:20–1:30 | Asegurar 2–3 fáciles (ad-hoc, simulación, strings, greedy). Python si cabe |
| 1:30–4:00 | Bloque medio: grafos [G], constructivos [M6], DP, estructuras [D] |
| 4:00–5:00 | Si el marcador se congela, sigue con el problema más avanzado; no abras uno nuevo en los últimos 30 min sin idea clara |

Regla de equipo: una persona en el teclado, las otras dos piensan en papel; si llevas 30 min atascado en un problema, cambia de problema o de persona.

## Señales en el enunciado → plantilla

| Si el enunciado dice… | Piensa en… | Ir a |
| --- | --- | --- |
| "mínimo/máximo valor tal que se pueda" | Búsqueda binaria sobre la respuesta | [A3] |
| "subarreglo/subcadena más larga que cumple" | Dos punteros o prefijos + map | [A4] [A1] |
| "camino más corto", pesos 1 | BFS | [G2] [G3] |
| "camino más corto", pesos variables ≥ 0 | Dijkstra | [G5] |
| "todos los caminos óptimos pasan por X" | Dijkstra con y sin X | [G5] |
| "qué nodos pueden llegar a X" | Invertir aristas + BFS desde X | [G6] |
| "tareas con dependencias", sin ciclos | Topo + DP en DAG | [G7] |
| "unir grupos", "¿están conectados?" | DSU | [G8] |
| "quitar aristas sin desconectar", "ciclo" | Árbol DFS, back-edges, puentes | [G9] |
| Árbol + "distancia entre u y v" / "ancestro" | LCA | [G10] |
| Árbol + "para cada nodo como raíz" | Rerooting | [G11] |
| "emparejar", "asignar sin repetir" | Matching bipartito | [G12] |
| "capacidad", "cortar mínimo" | Flujo / corte mínimo | [G13] |
| Muchas consultas de suma/min en rango | Prefijos, Fenwick, segment tree, sparse | [A1] [D1] [D3] [D4] |
| "k-ésimo disponible/menor" | Fenwick `kth` u ordered set | [D1] [D2] |
| max de Aᵢ·X + Bᵢ | Li-Chao / CHT | [D5] |
| Actualizaciones que fuerzan recalcular todo | Sqrt batching | [D6] |
| "igual frecuencia", comparar subcadenas | Rolling hash | [S1] |
| "expresión válida", paréntesis | Reducción canónica + balance | [S4] [S5] |
| "módulo 10^9+7" | Aritmética modular | [M1] |
| N hasta 10^12 y divisores/bases | O(√N) | [M2] [M3] |
| "k-ésima permutación con…" | DP de conteo + reconstrucción | [M4] |
| "dos jugadores, juego óptimo" | Invariante o Grundy | [M5] |
| "construye", "rellena los ceros" | Pensar hacia atrás, extremos, bloques | [M6] |
| Puntos y polígonos | Cruz, hull, ángulos | [GE] |

### Señales de matemática y geometría

| Si el enunciado dice… | Ir a |
| --- | --- |
| "error absoluto o relativo", salida con decimales | [F1] [F2] |
| "hasta qué altura / radio / tiempo para que…" | [F3] (+ [VO2]) |
| "máximo/mínimo de una función continua" que sube y baja | [F4] |
| Ángulo en grados, luz, sombra, pendiente | [TR1] [TR2] |
| Triángulo dado por sus lados | [TR2] |
| Girar puntos | [TR3] |
| Distancia de un punto a una recta / segmento | [GF2] |
| Círculos que se cortan, punto dentro de círculo | [GF3] |
| Punto dentro de un polígono, área, centro de masa | [GF4] |
| Cono, esfera, cilindro, taza, tanque | [VO1] [VO2] |
| "longitud total cubierta" | [IV1] |
| n hasta 10^18 y "módulo" | [CB1] [CB2] |
| Módulo como 10^18+3 o producto de dos ≤ 10^18 | [CB1] |
| "al menos uno de…", "ninguno de…" | [CB5] |
| "valor esperado", dados, monedas, "repetir hasta" | [PR1] [PR3] |
| "probabilidad módulo p" | [PR2] |
| a·x + b·y = c, "combinar paquetes de a y b" | [NT2] |
| "resto r1 al dividir entre m1 y r2 entre m2" | [NT4] |
| Divisores de n hasta 10^12, perfecto/abundante | [NT6] |
| "¿es primo?" con n hasta 10^18 | [NT7] |
| Recurrencia con n hasta 10^18 (Fibonacci y similares) | [NT8] |
| Σ de n / i | [NT10] |
| Intercambios, mezclas repetidas, "volver al orden inicial" | [PE1] |

## Problemas del Regional Latinoamericano por técnica

**[R2] Problemas del Regional Latinoamericano por tema**

| Año | Problema | Técnica | Complejidad | Plantillas |
| --- | --- | --- | --- | --- |
| 2022-23 | A. Asking for Money | Inversión de aristas + 3 BFS/DFS | O(N²) | [G6] |
| 2023 | E. Elevated Profits | Eliminación inversa de hojas + buckets por promedio | O(N log N) | [M6] [C4] |
| 2023 | M. Meeting Point | Dijkstra dos veces, omitiendo un nodo | O(M log N) | [G5] |
| 2024 | B. Biketopia's Cyclic Track | Árbol DFS + back-edge de costo máximo | O(N + M) | [G9] |
| 2024 | D. Diverse T-Shirts | Cliques maximales en grafo línea + matching bipartito | O(V·E) | [G12] |
| 2024 | G. Grand Glory Race | Rerooting (mejor y segundo mejor) + LCA y saltos | O(N log N + Q log² N) | [G11] [G10] |
| 2024 | H. Heraclosures | DP en DAG por orden topológico + sqrt batching | O(NM + E√M) | [G7] [D6] |
| 2022-23 | C. City Folding | Simulación inversa de pliegues | O(N) | [M6] |
| 2023 | B. Blackboard Game | Invariante: frecuencias módulo 3 | O(N) | [M5] |
| 2023 | F. Forward and Backward | Divisores y bases palindrómicas | O(√N) | [M2] [M3] |
| 2024 | E. Evereth Expedition | Dos punteros en permutación bitónica | O(N) | [M6] |
| 2024 | F. Finding Privacy | Sistema diofántico lineal + bloques greedy | O(N) | [M6] |
| 2024 | I. Inversion Insight | DP con sumas prefijas + order statistics | O(N·X) | [M4] [D1] [D2] |
| 2023 | C. Candy Rush | Rolling hash dinámico de frecuencias | O(N log N) | [S1] |
| 2023 | D. Deciphering WordWhiz | Simulación directa sobre diccionario | O(N·Q) | [P3] |
| 2023 | L. Latam++ | Reducción canónica + paréntesis | O(N) | [S5] [S4] |
| 2024 | A. Append and Panic! | Conteo con set / barrido inverso | O(∣S∣) | [P5] |
| 2022-23 | B. Board Game | Segment tree + CHT / Li-Chao | O(N log² N) | [D3] [D5] |
| 2023 | A. Analyzing Contracts | Li-Chao (cruce único) o sqrt + D&C | O(N + Q log N) | [D5] [D6] |
| 2024 | C. Cindy's Christmas Challenge | Búsqueda binaria + 16 RMQ | O(W log ∣S∣) | [A3] [D4] |

Practica estos en el gimnasio de Codeforces (Latin America Regional 2020–2025) en simulacros de 5 horas.

Los códigos entre corchetes ([G5], [D1], [CB2]…) son los mismos de los README de cada carpeta y de los PDF de
[`notebook/`](../notebook).
