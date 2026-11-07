# Geometría

Dos mundos: si todas las coordenadas son enteras y solo necesitas cruz, punto o área, trabaja **en enteros**
(exacto). Si aparecen raíces, círculos, ángulos o divisiones, usa **flotantes** con `long double`.

| Carpeta | Contenido |
| --- | --- |
| [`enteros/`](enteros) | Punto entero, orientación, envolvente convexa (con y sin colineales), intersección de segmentos, orden angular |
| [`flotantes/`](flotantes) | Punto real, proyecciones, distancias, rectas, círculos, polígonos |
| [`trigonometria/`](trigonometria) | Grados/radianes, `atan2`, leyes de senos y cosenos, Herón |
| [`volumenes/`](volumenes) | Conos, esferas, cilindros, casquetes; altura de llenado |

## Enteros

**[GE1] Punto, cruz, orientación, área** — `orient(a,b,c)` > 0 si c está a la IZQUIERDA de a→b (giro antihorario), < 0 a la derecha, 0 colineal. `area2` devuelve 2·área con signo (positiva si el polígono va antihorario).

Código: [`enteros/punto_entero.cpp`](enteros/punto_entero.cpp)

**[GE2] Envolvente convexa (monotone chain)** — O(n log n), antihorario, sin puntos colineales. No la modifiques para incluir colineales: cambiar a `< 0` falla si todos los puntos están en una recta.

Código: [`enteros/convex_hull.cpp`](enteros/convex_hull.cpp)

**[GE3] ¿Se cortan dos segmentos?** — Incluye tocarse en un extremo y solaparse colineales.

Código: [`enteros/interseccion_segmentos.cpp`](enteros/interseccion_segmentos.cpp)

**[GE4] Orden angular (barrido radial)** — Ordena vectores por ángulo desde 0° hasta 360°, sin `atan2` ni flotantes. Para ordenar alrededor de un pivote q, ordena `p[i] - q`.

Código: [`enteros/orden_angular.cpp`](enteros/orden_angular.cpp)

Otras técnicas que aparecen en el regional (sin plantilla aquí): rotating calipers sobre el hull (diámetro, ancho), línea de barrido con eventos ordenados, intersección de semiplanos O(n log n).

**[GE5] Envolvente con los puntos colineales del borde** — Cuándo: el enunciado cuenta TODOS los puntos que están
sobre el borde (por ejemplo, "capas" de una cebolla de puntos, UCV 2025 G si los colineales cuentan). Es el mismo
monotone chain con `< 0`, más el caso especial de que todos estén en una recta. Probado contra fuerza bruta.
Código: [`enteros/convex_hull_colineales.cpp`](enteros/convex_hull_colineales.cpp).

## Trigonometría

**[TR1] Grados, radianes y ángulos** — Las funciones de C++ y Python trabajan en RADIANES. Trampa: si el enunciado da grados (θ = 45), convierte antes de `sin`/`cos`/`tan`.

Código: [`trigonometria/angulos.cpp`](trigonometria/angulos.cpp)

| Función | Devuelve | Nota |
| --- | --- | --- |
| `atan2l(y, x)` | Ángulo del vector (x, y) en (−π, π] | Usa esta, no `atan(y/x)` (falla con x = 0 y pierde el cuadrante) |
| `acosl(v)` | [0, π] | Pasa por `safeAcos` [F5] |
| `asinl(v)` | [−π/2, π/2] | Igual: recorta a [−1, 1] |
| `tanl(t)` | tan | Explota cerca de 90° |

**[TR2] Triángulos** — Lados a, b, c; el ángulo C es el opuesto al lado c.

Código: [`trigonometria/triangulos.cpp`](trigonometria/triangulos.cpp)

| Necesito | Fórmula |
| --- | --- |
| Área con base y altura | b·h / 2 |
| Radio circunscrito | R = a·b·c / (4·área) |
| Radio inscrito | r = área / s, con s = (a+b+c)/2 |
| Altura sobre el lado c | 2·área / c |
| Sombra de un objeto de altura h con luz a θ grados | h / tan(θ) |
| Triángulo equilátero de lado s | área = √3·s²/4, altura = √3·s/2 |

**[TR3] Rotación, ángulo entre vectores, polares** — Usa el struct `PT` de [GF1].

Código: [`flotantes/punto.cpp`](flotantes/punto.cpp)

Rotar alrededor de un punto c: `rotate(p - c, t) + c`. Rotar 90° exacto sin flotantes: (x, y) → (−y, x).

## Geometría con flotantes

Si todas las coordenadas son enteras y solo necesitas cruz/punto/área, usa la versión entera del primer cheatsheet ([GE]). Esta es para cuando aparecen raíces, divisiones o círculos.

**[GF1] Punto / vector** — Base de todo lo demás; requiere [F1].

Código: [`flotantes/punto.cpp`](flotantes/punto.cpp)

**[GF2] Rectas y segmentos** — Una recta se da con dos puntos a, b.

Código: [`flotantes/rectas.cpp`](flotantes/rectas.cpp)

**[GF3] Círculos** — Devuelven 0, 1 o 2 puntos. Trampa: `circleCircle` con dos círculos idénticos devuelve vacío (infinitos puntos): revísalo aparte.

Código: [`flotantes/circulos.cpp`](flotantes/circulos.cpp)

Relación de dos círculos con distancia d entre centros: separados si d > r1+r2; tangentes exteriores si d = r1+r2; se cortan si |r1−r2| < d < r1+r2; uno dentro del otro si d < |r1−r2|.

**[GF4] Polígonos** — Vértices en orden (horario o antihorario).

Código: [`flotantes/poligonos.cpp`](flotantes/poligonos.cpp)

| Polígono regular de n lados | Fórmula |
| --- | --- |
| Ángulo interior | (n − 2)·180° / n |
| Circunradio (centro a vértice) | R = s / (2·sin(π/n)) |
| Apotema (centro a lado) | s / (2·tan(π/n)) |
| Área con circunradio R | n·R²·sin(2π/n) / 2 |
| Diagonales | n·(n − 3) / 2 |
| Triángulos con vértices del polígono | C(n, 3) → [CB2] si n es enorme |

## Áreas y volúmenes

**[VO1] Volúmenes** — Requiere [F1].

Código: [`volumenes/volumenes.cpp`](volumenes/volumenes.cpp)

| Figura | Área / volumen |
| --- | --- |
| Círculo | área πr², perímetro 2πr |
| Sector de ángulo t (rad) | área r²·t/2, arco r·t |
| Segmento circular de ángulo t | r²·(t − sin t)/2 |
| Elipse de semiejes a, b | π·a·b |
| Trapecio | (b1 + b2)·h / 2 |
| Prisma / cilindro | área de la base · altura |
| Cono / pirámide | área de la base · altura / 3 |
| Superficie lateral del cono | π·r·g, g = √(r² + h²) |
| Caja con huecos verticales (cilindros) | (N·M − Σ πrᵢ²) · altura |

**[VO2] Altura de llenado** — Cuándo: "¿hasta qué altura llenar para tener la fracción f del volumen?". Patrón general: escribe vol(y) = volumen hasta la altura y (creciente) y aplícale [F3]. Probado con los 4 ejemplos de UCAB 2025 C (Café).

Código: [`volumenes/altura_llenado.cpp`](volumenes/altura_llenado.cpp)

Trampa: el "nivel de agua al meter objetos" es volumen / área libre de la base; compara `V >= A * areaLibre` en `long double` en vez de dividir.

Tests: [`tests/test_enteros.cpp`](tests/test_enteros.cpp), [`tests/test_flotantes.cpp`](tests/test_flotantes.cpp) (incluye los ejemplos de UCAB 2025 C y LAR 2024 J).
