# UCAB-2025 A · Asignación Aleatoria de Tareas

- **Concurso:** Maratón Local UCAB 2025 — enunciado en [`enunciados/ucab-2025.pdf`](../../../enunciados/ucab-2025.pdf)
- **Técnica:** Valor esperado con repetición
- **Complejidad:** O(q)
- **Plantilla relacionada:** [`06-matematica/probabilidad/esperanza_repetir.cpp`](../../../06-matematica/probabilidad/esperanza_repetir.cpp)
- **Solución:** [`Asignacion.cpp`](Asignacion.cpp)

## Idea

Por tarea: con prob 1/6 empatan (descansan x y se repite); si no, la hace Alice o Bob con prob 1/2 cada uno. E = (5/6)*(a+b)/2 + (1/6)*(x + E)  ->  E = (a+b)/2 + x/5.  Linealidad: total = n * E.

Salida con decimales: se compara con error absoluto o relativo ≤ 1e-4.

## Probar

```bash
python3 scripts/probar_problemas.py ucab-2025/A-asignacion-aleatoria
```

1 ejemplo(s) oficial(es) en [`ejemplos/`](ejemplos), todos correctos.
