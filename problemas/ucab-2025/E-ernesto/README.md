# UCAB-2025 E · Ernesto

- **Concurso:** Maratón Local UCAB 2025 — enunciado en [`enunciados/ucab-2025.pdf`](../../../enunciados/ucab-2025.pdf)
- **Técnica:** Componentes conexas (DSU) + máximo por componente
- **Complejidad:** O((N + M) α)
- **Plantilla relacionada:** [`03-grafos/dsu.cpp`](../../../03-grafos/dsu.cpp)
- **Solución:** [`Ernesto.cpp`](Ernesto.cpp)

## Idea

Contratar a alguien "quema" todo su grupo de amigos (componente conexa). Lo optimo: en cada componente, contratar al de mayor tolerancia H. Nombres -> ids con unordered_map; componentes con DSU.

## Probar

```bash
python3 scripts/probar_problemas.py ucab-2025/E-ernesto
```

1 ejemplo(s) oficial(es) en [`ejemplos/`](ejemplos), todos correctos.
