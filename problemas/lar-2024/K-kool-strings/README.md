# LAR-2024 K · Kool Strings

- **Concurso:** ICPC Latin American Regional 2024 — enunciado en [`enunciados/lar-2024.pdf`](../../../enunciados/lar-2024.pdf)
- **Técnica:** Rachas + caso especial K = 2
- **Complejidad:** O(|S|)
- **Plantilla relacionada:** [`05-strings/rachas.cpp`](../../../05-strings/rachas.cpp)
- **Solución:** [`K.cpp`](K.cpp)

## Idea

K = 2: la cadena debe alternar -> comparar con 0101... y 1010... K >= 3: cada racha de largo L necesita L / K cambios; se invierte el caracter K-1, 2K-1, ... de la racha. Si el ultimo cae justo al final de la racha (L % K == 0), se mueve una posicion antes para no pegarse a la racha siguiente.

Hay varias respuestas válidas: `check.py` verifica que la salida cumpla las reglas en vez de compararla letra por letra.

## Probar

```bash
python3 scripts/probar_problemas.py lar-2024/K-kool-strings
```

4 ejemplo(s) oficial(es) en [`ejemplos/`](ejemplos), todos correctos.
