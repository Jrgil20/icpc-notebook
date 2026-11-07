# Plantilla base y reglas del juez

Lo primero que se copia en cualquier problema. Las plantillas del resto del repo **asumen** este encabezado
(`bits/stdc++.h`, `using namespace std`, `ll`, `INF`, `MD`).

| Archivo | Para qué |
| --- | --- |
| [`template.cpp`](template.cpp) | Arranque en C++: I/O rápido, lectura de `n` y un vector |
| [`template.py`](template.py) | Arranque en Python: `readline` rápido, imports útiles |
| [`header.h`](header.h) | Mismo encabezado, para que los tests lo incluyan (en el concurso NO se usa) |

## ¿Python o C++?

| Situación | Lenguaje |
| --- | --- |
| Strings / simulación con N ≤ 10^4, enteros gigantes, parsing | Python |
| N ≥ 10^5, grafos, árboles, DP grandes, estructuras de datos | C++ |
| Dudas | C++: los límites de tiempo se calibran con soluciones compiladas |

Operaciones por segundo aproximadas: C++ ≈ 10^8, Python ≈ 10^7 (menos con bucles anidados).

| N máximo | Complejidad que pasa |
| --- | --- |
| ≤ 12 | O(N!) |
| ≤ 20–25 | O(2^N · N) |
| ≤ 500 | O(N^3) |
| ≤ 5 000 | O(N^2) |
| ≤ 10^6 | O(N log N) |
| ≤ 10^8 | O(N) |
| > 10^9 | O(√N) o O(log N) |

## Compilar y probar en local

```bash
g++ -std=c++20 -O2 -Wall A.cpp -o A
./A < ejemplo.in
python3 A.py < ejemplo.in
```

## Antes de CADA envío (juez BOCA)

Ver [`09-estrategia`](../09-estrategia/README.md) para la lista completa. Lo mínimo:

1. Archivo con el nombre que pide el enunciado (`A.cpp`, `A.py3`); en Java/Kotlin sin `package`.
2. Nada en `cerr`/stderr: cuenta en el límite de salida y puede dar Runtime Error.
3. Un espacio entre valores, `\n` al final de cada línea.
4. `ll` en sumas, productos y distancias.
