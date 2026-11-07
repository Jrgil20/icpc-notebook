# UCV-2025 B · Midnight Craving

- **Concurso:** XXXI Contest UCV 2025 — enunciado en [`enunciados/ucv-2025.pdf`](../../../enunciados/ucv-2025.pdf)
- **Técnica:** Segment tree con rachas + lazy de inversión
- **Complejidad:** O((N + Q) log N)
- **Plantilla relacionada:** [`04-estructuras/segtree_rachas_flip.cpp`](../../../04-estructuras/segtree_rachas_flip.cpp)
- **Solución:** [`midnight.cpp`](midnight.cpp)

## Idea

Segment tree con merge personalizado: por nodo, prefijo/sufijo/mejor racha de 0s y de 1s. Invertir un rango = intercambiar los datos de 0s y 1s (lazy). Ver 04-estructuras/segtree_rachas_flip.cpp.

## Probar

```bash
python3 scripts/probar_problemas.py ucv-2025/B-midnight-craving
```

2 ejemplo(s) oficial(es) en [`ejemplos/`](ejemplos), todos correctos.
