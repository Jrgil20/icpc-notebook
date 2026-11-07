# UCAB-2025 K · K2

- **Concurso:** Maratón Local UCAB 2025 — enunciado en [`enunciados/ucab-2025.pdf`](../../../enunciados/ucab-2025.pdf)
- **Técnica:** k² mod (10^18 + 3) con __int128
- **Complejidad:** O(q)
- **Plantilla relacionada:** [`06-matematica/aritmetica-modular/mulmod_int128.cpp`](../../../06-matematica/aritmetica-modular/mulmod_int128.cpp)
- **Solución:** [`Kcuadrado.cpp`](Kcuadrado.cpp)

## Idea

Un triangulo de lado k se parte en k^2 triangulitos de lado 1. Modulo 1e18+3: k*k desborda ll -> __int128.

## Probar

```bash
python3 scripts/probar_problemas.py ucab-2025/K-k2
```

1 ejemplo(s) oficial(es) en [`ejemplos/`](ejemplos), todos correctos.
