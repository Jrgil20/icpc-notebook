# LAR-2024 E · Evereth Expedition

- **Concurso:** ICPC Latin American Regional 2024 — enunciado en [`enunciados/lar-2024.pdf`](../../../enunciados/lar-2024.pdf)
- **Técnica:** Constructivo, dos punteros, fechas límite
- **Complejidad:** O(N)
- **Plantilla relacionada:** [`06-matematica/README.md`](../../../06-matematica/README.md)
- **Solución:** [`E.cpp`](E.cpp)

## Idea

Lema: el 1 va en un extremo; quitando el 1 queda una montana de tamano N-1. Se colocan 1, 2, ..., N de afuera hacia adentro con dos punteros l, r. Si v ya esta escrito, debe estar en l o en r. Si ambos extremos estan vacios: cada lado tiene una "fecha limite" = el primer valor conocido de ese lado (los huecos antes de el deben llenarse con valores menores). Se pone v del lado con fecha limite menor. Empate (es el MISMO valor conocido visto desde ambos lados): se llena primero el lado con menos huecos.

Hay varias respuestas válidas: `check.py` verifica que la salida cumpla las reglas en vez de compararla letra por letra.

## Probar

```bash
python3 scripts/probar_problemas.py lar-2024/E-evereth-expedition
```

3 ejemplo(s) oficial(es) en [`ejemplos/`](ejemplos), todos correctos.
