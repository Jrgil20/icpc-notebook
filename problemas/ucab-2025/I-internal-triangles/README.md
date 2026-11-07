# UCAB-2025 I · Internal Triangles

- **Concurso:** Maratón Local UCAB 2025 — enunciado en [`enunciados/ucab-2025.pdf`](../../../enunciados/ucab-2025.pdf)
- **Técnica:** C(n, 3) con n hasta 10^18
- **Complejidad:** O(q)
- **Plantilla relacionada:** [`06-matematica/combinatoria/ncr_n_grande.cpp`](../../../06-matematica/combinatoria/ncr_n_grande.cpp)
- **Solución:** [`Internal.cpp`](Internal.cpp)

## Idea

Triangulos = C(n, 3) = n(n-1)(n-2)/6. Con n hasta 1e18: se divide exacto en __int128 por partes y luego mod.

## Probar

```bash
python3 scripts/probar_problemas.py ucab-2025/I-internal-triangles
```

1 ejemplo(s) oficial(es) en [`ejemplos/`](ejemplos), todos correctos.
