# UCV-2025 E · Infection Lethality

- **Concurso:** XXXI Contest UCV 2025 — enunciado en [`enunciados/ucv-2025.pdf`](../../../enunciados/ucv-2025.pdf)
- **Técnica:** Tamaño de componente (DSU con tamaños)
- **Complejidad:** O((N + M) α + Q)
- **Plantilla relacionada:** [`03-grafos/dsu.cpp`](../../../03-grafos/dsu.cpp)
- **Solución:** [`infection.cpp`](infection.cpp)

## Idea

Infectados = tamano de la componente conexa del computador inicial. DSU con tamanos.

## Probar

```bash
python3 scripts/probar_problemas.py ucv-2025/E-infection-lethality
```

2 ejemplo(s) oficial(es) en [`ejemplos/`](ejemplos), todos correctos.
