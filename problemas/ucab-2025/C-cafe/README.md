# UCAB-2025 C · Café

- **Concurso:** Maratón Local UCAB 2025 — enunciado en [`enunciados/ucab-2025.pdf`](../../../enunciados/ucab-2025.pdf)
- **Técnica:** Volumen de cono truncado + búsqueda binaria en reales
- **Complejidad:** O(t · 100)
- **Plantilla relacionada:** [`07-geometria/volumenes/altura_llenado.cpp`](../../../07-geometria/volumenes/altura_llenado.cpp)
- **Solución:** [`Cafe.cpp`](Cafe.cpp)

## Idea

Volumen hasta la altura y: cono truncado con radios r y r + (R - r) * y / h. Es creciente en y: busqueda binaria de y tal que vol(y) = vol(h) / 2.

Salida con decimales: se compara con error absoluto o relativo ≤ 1e-6.

## Probar

```bash
python3 scripts/probar_problemas.py ucab-2025/C-cafe
```

1 ejemplo(s) oficial(es) en [`ejemplos/`](ejemplos), todos correctos.
