# UCAB-2025 M · MST

- **Concurso:** Maratón Local UCAB 2025 — enunciado en [`enunciados/ucab-2025.pdf`](../../../enunciados/ucab-2025.pdf)
- **Técnica:** Kruskal repetido quitando aristas
- **Complejidad:** O(R · M) con R ≤ 50
- **Plantilla relacionada:** [`03-grafos/kruskal.cpp`](../../../03-grafos/kruskal.cpp)
- **Solución:** [`MST.cpp`](MST.cpp)

## Idea

Repetir: Kruskal sobre las aristas que quedan; si no conecta todo, parar; si conecta, borrar sus aristas. Cada ronda quita al menos una arista de cada vertice, asi que hay a lo sumo (grado minimo) <= 50 rondas.

## Probar

```bash
python3 scripts/probar_problemas.py ucab-2025/M-mst
```

1 ejemplo(s) oficial(es) en [`ejemplos/`](ejemplos), todos correctos.
