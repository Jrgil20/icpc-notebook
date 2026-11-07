# UCAB-2025 H · Humbertov y el Josephus de los No-Coprimos

- **Concurso:** Maratón Local UCAB 2025 — enunciado en [`enunciados/ucab-2025.pdf`](../../../enunciados/ucab-2025.pdf)
- **Técnica:** Simulación con lista circular
- **Complejidad:** O(n²) peor caso (0.2 s con n = 10^4)
- **Plantilla relacionada:** [`04-estructuras/lista_circular.cpp`](../../../04-estructuras/lista_circular.cpp)
- **Solución:** [`Humbertov.cpp`](Humbertov.cpp)

## Idea

Simulacion con lista circular (nxt): el que escribe pasa la hoja a su izquierda (i + 1); el primero que reciba la hoja con MCD > 1 sale. Si nadie, la hoja vuelve al que escribio: MCD(x, x) = x > 1 y sale el. La siguiente ronda la empieza el de la izquierda del eliminado.

## Probar

```bash
python3 scripts/probar_problemas.py ucab-2025/H-humbertov-josephus
```

1 ejemplo(s) oficial(es) en [`ejemplos/`](ejemplos), todos correctos.
