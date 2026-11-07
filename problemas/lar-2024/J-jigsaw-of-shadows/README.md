# LAR-2024 J · Jigsaw of Shadows

- **Concurso:** ICPC Latin American Regional 2024 — enunciado en [`enunciados/lar-2024.pdf`](../../../enunciados/lar-2024.pdf)
- **Técnica:** Trigonometría + unión de intervalos
- **Complejidad:** O(N log N)
- **Plantilla relacionada:** [`02-basicos/intervalos_union.cpp`](../../../02-basicos/intervalos_union.cpp)
- **Solución:** [`J.cpp`](J.cpp)

## Idea

La sombra de alguien de altura H en X cubre [X, X + H / tan(theta)]: respuesta = longitud de la union.

Salida con decimales: se compara con error absoluto o relativo ≤ 1e-4.

## Probar

```bash
python3 scripts/probar_problemas.py lar-2024/J-jigsaw-of-shadows
```

3 ejemplo(s) oficial(es) en [`ejemplos/`](ejemplos), todos correctos.
