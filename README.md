# ICPC Notebook — Python + C++

Plantillas probadas, explicaciones y problemas resueltos para la **ICPC South America/North** (Colombia,
Venezuela, Ecuador) y el Regional Latinoamericano. Pensado para alguien que **entiende cómo resolver** un problema
pero necesita tener a mano **cómo se escribe**.

Todo el código del repo compila con `g++ -std=c++20`, y está probado: las plantillas contra fuerza bruta y los
problemas contra sus ejemplos oficiales.

## Cómo está organizado

```
00-base/          plantilla de arranque (C++ y Python), elegir lenguaje, complejidades
01-sintaxis/      "quiero hacer X" -> codigo: leer, imprimir, strings, listas, dicts (Python y C++)
02-basicos/       sumas prefijas, busqueda binaria, dos punteros, intervalos
03-grafos/        BFS, Dijkstra, DSU, Kruskal, toposort, arbol DFS, LCA, rerooting, matching, flujo
04-estructuras/   Fenwick, ordered set, segment trees, sparse table, Li-Chao, lista circular
05-strings/       hashing, KMP, Z, parentesis, rachas
06-matematica/    reales, modular, teoria de numeros, combinatoria, probabilidad, permutaciones, juegos
07-geometria/     enteros, flotantes, trigonometria, volumenes
08-esqueletos/    archivos completos para empezar: N + lista, grafo, varios casos, interactivo, stress test
09-estrategia/    checklist del juez BOCA, mapa "senal del enunciado -> plantilla", estrategia de 5 horas
problemas/        21 problemas resueltos (LAR 2024, UCAB 2025, UCV 2025) con explicacion y ejemplos
enunciados/       los PDF originales de esos concursos
notebook/         PDF imprimibles (cheatsheets y el notebook generado desde este repo)
scripts/          probar todo y generar el PDF
```

Cada carpeta tiene un `README.md` que explica **cuándo** usar cada plantilla, la **trampa** típica y enlaza al
archivo de código. Los códigos entre corchetes (`[G5]`, `[D1]`, `[CB2]`…) son los mismos en los README y en los PDF.

## Cómo usarlo

- **En el concurso:** imprime [`notebook/notebook.pdf`](notebook) (o los cheatsheets). Empieza por
  [`09-estrategia`](09-estrategia/README.md) para reconocer el problema y salta a la plantilla.
- **Practicando:** copia [`00-base/template.cpp`](00-base/template.cpp) o un esqueleto de
  [`08-esqueletos`](08-esqueletos), pega la plantilla que toque y compara con [`problemas/`](problemas).
- **Si no recuerdas la sintaxis:** [`01-sintaxis`](01-sintaxis/README.md).

Las plantillas de C++ asumen el encabezado de [`00-base/template.cpp`](00-base/template.cpp)
(`bits/stdc++.h`, `using namespace std`, `ll`, `INF`, `MD`). Si una plantilla depende de otra, lo dice en su
primera línea (`// Requiere: ...`).

## Probar y generar el PDF

```bash
./scripts/probar_plantillas.sh          # tests de todas las plantillas
python3 scripts/probar_problemas.py     # soluciones contra sus ejemplos oficiales
python3 scripts/generar_pdf.py          # notebook/notebook.pdf (necesita: pip install markdown pygments, y Chrome)
```

## Agregar algo nuevo

1. Pon la plantilla en la carpeta del tema, con su comentario de una línea arriba.
2. Agrega su test en `<carpeta>/tests/` (incluye `00-base/header.h` y el archivo).
3. Explícala en el `README.md` de la carpeta con una línea `Código: [`archivo`](archivo)`: así entra sola al PDF.
4. Corre `./scripts/probar_plantillas.sh` y `python3 scripts/generar_pdf.py`.
