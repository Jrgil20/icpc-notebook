# UCAB-2025 L · Legend

- **Concurso:** Maratón Local UCAB 2025 — enunciado en [`enunciados/ucab-2025.pdf`](../../../enunciados/ucab-2025.pdf)
- **Técnica:** 4 BFS + "v en un camino más corto"
- **Complejidad:** O(N + C)
- **Plantilla relacionada:** [`03-grafos/en_camino_mas_corto.cpp`](../../../03-grafos/en_camino_mas_corto.cpp)
- **Solución:** [`Legend.cpp`](Legend.cpp)

## Idea

BFS desde U, Se, Sa y D. Un punto v sirve para caminar juntos si esta en un camino mas corto de U a cada casa: dU[v] + dX[v] == dU[X] para X = Se, Sa, D. Se elige el v con dU[v] maximo.

## Probar

```bash
python3 scripts/probar_problemas.py ucab-2025/L-legend
```

3 ejemplo(s) oficial(es) en [`ejemplos/`](ejemplos), todos correctos.
