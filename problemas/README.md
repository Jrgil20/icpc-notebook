# Problemas resueltos

Soluciones listas para enviar (un solo archivo, sin dependencias), cada una con su explicación y los ejemplos
oficiales del enunciado. Todas pasan sus ejemplos:

```bash
python3 scripts/probar_problemas.py
```

Las de LAR 2024 E, F y K además se compararon contra fuerza bruta en miles de casos pequeños.

| Concurso | Problema | Técnica | Lenguaje |
| --- | --- | --- | --- |
| LAR 2024 | [A · Append and Panic!](lar-2024/A-append-and-panic) | Strings / conteo | Python |
| LAR 2024 | [E · Evereth Expedition](lar-2024/E-evereth-expedition) | Constructivo, dos punteros, fechas límite | C++ |
| LAR 2024 | [F · Finding Privacy](lar-2024/F-finding-privacy) | Constructivo: bloques de 1 o 2 huecos | C++ |
| LAR 2024 | [J · Jigsaw of Shadows](lar-2024/J-jigsaw-of-shadows) | Trigonometría + unión de intervalos | C++ |
| LAR 2024 | [K · Kool Strings](lar-2024/K-kool-strings) | Rachas + caso especial K = 2 | C++ |
| UCAB 2025 | [A · Asignación Aleatoria de Tareas](ucab-2025/A-asignacion-aleatoria) | Valor esperado con repetición | C++ |
| UCAB 2025 | [B · Borrar, borrar, borrar, ...](ucab-2025/B-borrar) | Strings: filtrar + colapsar repetidos | Python |
| UCAB 2025 | [C · Café](ucab-2025/C-cafe) | Volumen de cono truncado + búsqueda binaria en reales | C++ |
| UCAB 2025 | [E · Ernesto](ucab-2025/E-ernesto) | Componentes conexas (DSU) + máximo por componente | C++ |
| UCAB 2025 | [F · Felipe Felipe y la Cola](ucab-2025/F-felipe-cola) | Cola + suma acumulada | C++ |
| UCAB 2025 | [G · Guanex y las Colas de Prioridad](ucab-2025/G-guanex-colas-prioridad) | Min-heap + I/O rápido | C++ |
| UCAB 2025 | [H · Humbertov y el Josephus de los No-Coprimos](ucab-2025/H-humbertov-josephus) | Simulación con lista circular | C++ |
| UCAB 2025 | [I · Internal Triangles](ucab-2025/I-internal-triangles) | C(n, 3) con n hasta 10^18 | C++ |
| UCAB 2025 | [J · Juego](ucab-2025/J-juego) | Simulación con dos heaps | C++ |
| UCAB 2025 | [K · K2](ucab-2025/K-k2) | k² mod (10^18 + 3) con __int128 | C++ |
| UCAB 2025 | [L · Legend](ucab-2025/L-legend) | 4 BFS + "v en un camino más corto" | C++ |
| UCAB 2025 | [M · MST](ucab-2025/M-mst) | Kruskal repetido quitando aristas | C++ |
| UCV 2025 | [A · Deficient, Perfect, Abundant](ucv-2025/A-deficient-perfect-abundant) | Suma de divisores en O(√N) | C++ |
| UCV 2025 | [B · Midnight Craving](ucv-2025/B-midnight-craving) | Segment tree con rachas + lazy de inversión | C++ |
| UCV 2025 | [D · Yummy](ucv-2025/D-yummy) | Contar subcadenas con s.count | Python |
| UCV 2025 | [E · Infection Lethality](ucv-2025/E-infection-lethality) | Tamaño de componente (DSU con tamaños) | C++ |

## Qué falta resolver

Estos problemas de los mismos concursos no tienen solución aquí todavía. Los marcados con * necesitan una idea
que no está en las plantillas:

| Concurso | Problemas |
| --- | --- |
| LAR 2024 | B (árbol DFS), C* (distancia de edición + 16 RMQ), D* (grafo línea + matching), G* (rerooting + LCA), H (DP en DAG + sqrt), I (DP de inversiones + k-ésimo), L* (ciclos de permutaciones) |
| UCAB 2025 | D (simulación de dominó) |
| UCV 2025 | C (cifrado: simulación), F (enunciado ambiguo: el ejemplo 1 solo cuadra si D es radio), G (capas de envolventes convexas) |

Para agregar uno: crea `problemas/<concurso>/<Letra>-<nombre>/` con la solución, `ejemplos/1.in` y `ejemplos/1.out`,
y opcionalmente `check.py` o `tolerancia`.
