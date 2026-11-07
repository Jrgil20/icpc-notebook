# UCAB-2025 J · Juego

- **Concurso:** Maratón Local UCAB 2025 — enunciado en [`enunciados/ucab-2025.pdf`](../../../enunciados/ucab-2025.pdf)
- **Técnica:** Simulación con dos heaps
- **Complejidad:** O(n log n)
- **Plantilla relacionada:** [`01-sintaxis/cpp.md`](../../../01-sintaxis/cpp.md)
- **Solución:** [`Juego.cpp`](Juego.cpp)

## Idea

Simulacion con dos heaps: Emma saca su maximo, Otto su minimo. Cada turno el total de numeros baja en 1, asi que hay a lo sumo 2n turnos.

## Probar

```bash
python3 scripts/probar_problemas.py ucab-2025/J-juego
```

1 ejemplo(s) oficial(es) en [`ejemplos/`](ejemplos), todos correctos.
