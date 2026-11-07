# LAR-2024 F · Finding Privacy

- **Concurso:** ICPC Latin American Regional 2024 — enunciado en [`enunciados/lar-2024.pdf`](../../../enunciados/lar-2024.pdf)
- **Técnica:** Constructivo: bloques de 1 o 2 huecos
- **Complejidad:** O(N)
- **Plantilla relacionada:** [`06-matematica/README.md`](../../../06-matematica/README.md)
- **Solución:** [`F.cpp`](F.cpp)

## Idea

Patron valido: K letras X sin vecinos, huecos internos de 1 o 2 '-', extremos con 0 o 1 '-'. N = K + huecos -> minimo 2K-1, maximo 3K. Se reparte el sobrante: primero extremos, luego huecos internos.

Hay varias respuestas válidas: `check.py` verifica que la salida cumpla las reglas en vez de compararla letra por letra.

## Probar

```bash
python3 scripts/probar_problemas.py lar-2024/F-finding-privacy
```

6 ejemplo(s) oficial(es) en [`ejemplos/`](ejemplos), todos correctos.
