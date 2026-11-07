# Matemática

Separada por subtema. Varias plantillas dependen de otras: cada archivo lo dice en su línea `// Requiere:`.

| Carpeta | Contenido |
| --- | --- |
| [`reales/`](reales) | `long double`, EPS, búsqueda binaria y ternaria en reales, floor/ceil con negativos |
| [`aritmetica-modular/`](aritmetica-modular) | Potencia modular, factoriales y C(n,k) mod p, `__int128` para módulos de 10^18 |
| [`teoria-de-numeros/`](teoria-de-numeros) | Criba, divisores, bases, Euclides extendido, CRT, phi, Miller-Rabin, matrices, sumas |
| [`combinatoria/`](combinatoria) | C(n,k) con n enorme, Lucas, Pascal, inclusión-exclusión, desarreglos, inversiones |
| [`probabilidad/`](probabilidad) | Valor esperado, fracciones mod p, DP de probabilidades |
| [`permutaciones/`](permutaciones) | Componer, invertir, ciclos, potencia |
| [`juegos/`](juegos) | Grundy y mex |

**Regla de tipo numérico** (decídelo antes de escribir):

| Situación | Usa |
| --- | --- |
| Todo es entero y cabe en 9·10^18 | `ll` |
| Un producto de dos números ≤ 10^18 | `__int128` ([`mulmod_int128.cpp`](aritmetica-modular/mulmod_int128.cpp)) o Python |
| Hay π, raíces, senos o divisiones no exactas | `long double` ([`base_flotante.cpp`](reales/base_flotante.cpp)) |
| Se puede comparar con enteros (a/b < c/d ⇔ a·d < c·b si b, d > 0) | Enteros, siempre |
| Enteros gigantes o fracciones exactas, pocas operaciones | Python (`int`, `Fraction`) |

## Reales (flotantes)

**[F1] Base flotante** — Cópialo arriba de cualquier problema con decimales. `long double` da ~18 cifras (`double` ~15). Trampa: nunca compares flotantes con `==`; usa `sgn`/`eq`.

Código: [`reales/base_flotante.cpp`](reales/base_flotante.cpp)

Con `long double` usa las versiones con `l`: `sqrtl`, `fabsl`, `sinl`, `cosl`, `tanl`, `atan2l`, `acosl`, `hypotl`, `floorl`, `powl`. Leer: `ld x; cin >> x;` funciona igual.

**[F2] Imprimir decimales** — Cuando dicen "error absoluto o relativo ≤ 10^-6", imprime 9 cifras o más.

```cpp
cout << fixed << setprecision(9) << x << "\n";   // ponlo una vez al inicio de main
printf("%.9Lf\n", x);                           // ld con printf: %Lf (L mayuscula)
```
```python
print(f"{x:.9f}")
```

Trampa: si la salida esperada es entera ("16", "300") y el juez acepta error relativo, imprimir `16.000000000` también es correcto. Si piden un entero exacto, usa `llround(x)`.

**[F3] Búsqueda binaria en reales** — Cuándo: buscar x con f(x) = objetivo y f creciente (alturas, tiempos, radios). 200 iteraciones siempre alcanzan; no uses `while (hi - lo > EPS)` (puede no terminar).

Código: [`reales/busqueda_binaria_real.cpp`](reales/busqueda_binaria_real.cpp)

**[F4] Búsqueda ternaria** — Cuándo: f sube y luego baja (unimodal) y buscas el máximo. Para mínimo, cambia `<` por `>`. Trampa: con zonas planas en el medio falla.

Código: [`reales/busqueda_ternaria.cpp`](reales/busqueda_ternaria.cpp)

**[F5] Funciones seguras** — Por redondeo, `sqrt(-1e-18)` da NaN y `acos(1.0000001)` también. Usa siempre estas versiones.

Código: [`reales/funciones_seguras.cpp`](reales/funciones_seguras.cpp)

**[F6] División entera hacia abajo/arriba con negativos** — En C++ `-7 / 2 == -3` (trunca hacia 0), no −4.

Código: [`reales/division_floor_ceil.cpp`](reales/division_floor_ceil.cpp)

**[F7] Python para flotantes y exactitud**

```python
import math
from fractions import Fraction
from decimal import Decimal, getcontext
math.pi; math.radians(180); math.degrees(math.pi); math.atan2(y, x); math.hypot(3, 4)
math.isclose(0.1 + 0.2, 0.3)        # True (comparar flotantes)
math.floor(-2.5), math.ceil(-2.5)   # -3, -2
-7 // 2                             # -4 (floor: redondea hacia -inf)
-(-a // b)                          # ceil(a / b) con enteros: -(-7 // 2) = 4
f = Fraction(1, 6) + Fraction(1, 3) # 1/2 exacto; f.numerator, f.denominator
getcontext().prec = 50; Decimal(2).sqrt()   # 50 cifras
```

Trampa: `round(2.675, 2)` da `2.67` (2.675 no es exacto en binario). Para imprimir usa f-strings y deja que el juez tolere el error.

## Aritmética modular

**[M1] Aritmética modular y combinatoria** — Cuándo: "imprime la respuesta módulo 10^9+7". Trampa: reduce con `% MD` después de CADA producto; `inv` solo sirve si MD es primo. Llama `initFact()` una vez en `main`.

Código: [`aritmetica-modular/factoriales_ncr.cpp`](aritmetica-modular/factoriales_ncr.cpp)

Fórmulas útiles: estrellas y barras (repartir n iguales en k cajas) = C(n+k−1, k−1); caminos en grilla a×b = C(a+b, a); Catalan(n) = C(2n, n)/(n+1).

**[CB1] Multiplicar con módulos de hasta ~4·10^18** — Cuándo: el módulo es como 10^18+3 (UCAB 2025 K: respuesta k² mod 10^18+3). Trampa: `a * b % m` con `ll` desborda si a·b > 9·10^18.

Código: [`aritmetica-modular/mulmod_int128.cpp`](aritmetica-modular/mulmod_int128.cpp)

`cout` no imprime `__int128`: usa `print128` (con `printf`/`putchar`, no mezcles con `cout` sin `cout.flush()`). En Python: `k * k % (10**18 + 3)`.

## Teoría de números

**[M2] Criba, divisores, factorización** — `spf[x]` = menor primo que divide x (factoriza cualquier x ≤ n en O(log x)). `divisors` y `factorize` son O(√n).

Código: [`teoria-de-numeros/criba_divisores.cpp`](teoria-de-numeros/criba_divisores.cpp)

**[M3] Bases numéricas y palíndromos** — Cuándo: "¿en qué bases b es N palíndromo?". Truco O(√N): para b ≤ √N prueba con fuerza bruta; para b > √N el número tiene 2 dígitos `dd` y N = d·(b+1), así que b = N/d − 1 para cada divisor d de N con d < b.

Código: [`teoria-de-numeros/bases.cpp`](teoria-de-numeros/bases.cpp)

**[NT1] Euclides extendido** — Encuentra x, y con a·x + b·y = gcd(a, b).

Código: [`teoria-de-numeros/extgcd.cpp`](teoria-de-numeros/extgcd.cpp)

**[NT2] Ecuación diofántica a·x + b·y = c** — Tiene solución si y solo si gcd(a, b) divide a c. Todas las soluciones: (x + k·b/g, y − k·a/g) para k entero; elige k para que x, y ≥ 0 si lo piden.

Código: [`teoria-de-numeros/diofantica.cpp`](teoria-de-numeros/diofantica.cpp)

**[NT3] Inverso modular con módulo NO primo** — Existe solo si gcd(a, m) = 1. Si m es primo, usa `powmod(a, m - 2, m)`.

Código: [`teoria-de-numeros/inverso_general.cpp`](teoria-de-numeros/inverso_general.cpp)

**[NT4] Teorema chino del resto** — Cuándo: "x deja resto r1 al dividir entre m1 y resto r2 entre m2". Sirve aunque m1, m2 no sean coprimos. Para más ecuaciones, combínalas de a dos.

Código: [`teoria-de-numeros/crt.cpp`](teoria-de-numeros/crt.cpp)

**[NT5] Phi de Euler** — phi(n) = cuántos de 1..n son coprimos con n. Propiedad: a^phi(m) ≡ 1 (mod m) si gcd(a, m) = 1, así que a^e mod m = a^(e mod phi(m)) mod m.

Código: [`teoria-de-numeros/phi.cpp`](teoria-de-numeros/phi.cpp)

**[NT6] Cantidad y suma de divisores en O(√n)** — Cuando n = p1^e1·…·pk^ek: d(n) = (e1+1)·…·(ek+1), sigma(n) = Π (1 + p + … + p^e). Suma de divisores propios = sigma(n) − n (perfecto / abundante / deficiente).

Código: [`teoria-de-numeros/divisores_suma.cpp`](teoria-de-numeros/divisores_suma.cpp)

**[NT7] ¿Es primo? (n hasta 2^64)** — Miller-Rabin determinista, O(log³ n). Usa para n > 10^12, donde la división hasta √n es lenta.

Código: [`teoria-de-numeros/miller_rabin.cpp`](teoria-de-numeros/miller_rabin.cpp)

**[NT8] Exponenciación de matrices** — Cuándo: recurrencia lineal f(n) = c1·f(n−1) + … con n hasta 10^18. O(k³ log n) con matriz k×k. Trampa: con módulo > 3·10^9 el producto `A * B` desborda: cambia por `mulmod`.

Código: [`teoria-de-numeros/matriz_potencia.cpp`](teoria-de-numeros/matriz_potencia.cpp)

**[NT9] Sumas cerradas** — Con `__int128` para no desbordar con n hasta 10^9 o más. `geoSum` sirve con cualquier módulo (no divide).

Código: [`teoria-de-numeros/sumas_cerradas.cpp`](teoria-de-numeros/sumas_cerradas.cpp)

Suma de a hasta b = sum1(b) − sum1(a − 1). Progresión aritmética: n·(primero + último)/2.

**[NT10] Bloques de n / i** — Cuándo: Σ f(n / i) para i = 1..n con n hasta 10^12. n / i toma solo ~2√n valores distintos; cada bloque [i, j] comparte el mismo cociente q.

Código: [`teoria-de-numeros/bloques_n_div_i.cpp`](teoria-de-numeros/bloques_n_div_i.cpp)

## Combinatoria

**[CB2] C(n, k) con n hasta 10^18 y k pequeño** — Cuándo: "cuántos triángulos con vértices de un polígono de n lados" (UCAB 2025 I: C(n, 3) mod 10^9+7). O(k log p).

Código: [`combinatoria/ncr_n_grande.cpp`](combinatoria/ncr_n_grande.cpp)

En Python sale directo con enteros grandes: `n * (n - 1) * (n - 2) // 6 % MOD` (divide ANTES del módulo).

**[CB3] Lucas (p primo pequeño)**

Código: [`combinatoria/lucas.cpp`](combinatoria/lucas.cpp)

**[CB4] Triángulo de Pascal (cualquier módulo)** — O(n²) memoria y tiempo.

Código: [`combinatoria/pascal.cpp`](combinatoria/pascal.cpp)

**[CB5] Inclusión-exclusión** — Cuándo: "cuántos de 1..N cumplen al menos una condición". Suma las intersecciones de tamaño impar y resta las de tamaño par. Ejemplo: divisibles por alguno de a[] (k ≤ 20).

Código: [`combinatoria/inclusion_exclusion.cpp`](combinatoria/inclusion_exclusion.cpp)

**[CB6] Desarreglos y Stirling**

Código: [`combinatoria/desarreglos_stirling.cpp`](combinatoria/desarreglos_stirling.cpp)

| Contar… | Fórmula |
| --- | --- |
| Subconjuntos de n | 2^n |
| Ordenar n con repetidos (c₁, c₂, …) | n! / (c₁!·c₂!·…) |
| Funciones de k en n | n^k; sobreyectivas (todo n usado): n!·S[k][n] |
| Pares no ordenados de n | n(n−1)/2 |
| Desarreglos D(n) | 0, 1, 2, 9, 44, 265 para n = 1..6 |

**[M4] Permutaciones con x inversiones (DP + sumas prefijas)** — f[n][x] = Σ f[n−1][x−j] para 0 ≤ j < n, optimizado a O(n·X). `cap` evita desborde cuando K llega a 10^18.

Código: [`combinatoria/permutaciones_inversiones.cpp`](combinatoria/permutaciones_inversiones.cpp)

K-ésima permutación con x inversiones: con r elementos restantes, elegir el j-ésimo menor disponible (j = 0..r−1) aporta j inversiones y deja f[r−1][x−j] completaciones. Recorre j: si K > ese número, réstalo de K; si no, toma ese elemento (extráelo con [D1] `kth` o [D2]) y resta j a x.

## Probabilidad

**Reglas que resuelven casi todo**

| Regla | Uso |
| --- | --- |
| Linealidad: E[X + Y] = E[X] + E[Y] (aunque dependan) | n tareas iguales → n · E[una tarea] |
| Geométrica: si cada intento sale bien con prob p, E[intentos] = 1/p | "tirar hasta que salga" |
| Con repetición: E = p_fin·c_fin + p_rep·(c_rep + E) → despejar E | Ver [PR1] |
| Dos dados de 6 caras | P(iguales) = 1/6, P(A > B) = P(B > A) = 5/12 |
| Independientes: P(A y B) = P(A)·P(B) |  |
| Complemento: P(al menos uno) = 1 − P(ninguno) |  |

**[PR1] Valor esperado con "repetir"** — En cada ronda, con prob `pRep` se repite gastando `cRep`; si no, termina gastando en promedio `costFin`alPromedio. Despejando E = p_fin·c_fin + p_rep·(c_rep + E). Probado con los 4 ejemplos de UCAB 2025 A.

Código: [`probabilidad/esperanza_repetir.cpp`](probabilidad/esperanza_repetir.cpp), [`reales/base_flotante.cpp`](reales/base_flotante.cpp)

**[PR2] Probabilidad como fracción módulo p** — Cuándo: "imprime la probabilidad como P·Q⁻¹ mod 10^9+7". Suma y multiplica fracciones directamente en mod.

```cpp
const ll MD = 1e9 + 7;
ll fracMod(ll P, ll Q){ return mulmod(P % MD, powmod(Q, MD - 2, MD), MD); }   // usa [CB1]
// 1/2 -> 500000004
```

**[PR3] DP de probabilidad** — Cuándo: distribución de una suma o de un proceso por pasos. `dp[estado]` = probabilidad de estar ahí; cada paso reparte la probabilidad. Ejemplo: suma de n dados de c caras.

Código: [`probabilidad/dp_dados.cpp`](probabilidad/dp_dados.cpp)

Valor esperado por DP: E[estado] = Σ P(transición)·(costo + E[siguiente]). Si un estado puede volver a sí mismo, despeja como en [PR1].

## Permutaciones

**[PE1] Componer, invertir, ciclos, potencia** — Cuándo: intercambios de filas/columnas, "aplicar la mezcla k veces", "cuántas veces hasta volver al inicio".

Código: [`permutaciones/permutaciones.cpp`](permutaciones/permutaciones.cpp)

| Pregunta | Respuesta con los ciclos |
| --- | --- |
| Mínimo de intercambios (swaps) para ordenar | n − (número de ciclos) |
| Paridad (par/impar) | (n − ciclos) % 2; cada swap cambia la paridad |
| Veces hasta volver a la identidad (orden) | lcm de los largos de los ciclos (puede ser enorme: usa mod o `__int128`) |
| ¿p^k = identidad? | k es múltiplo del largo de cada ciclo |

Intercambios sucesivos de filas (o columnas): lleva un arreglo `row[i]` = fila original que está ahora en la posición i, aplica cada `swap(row[I], row[J])` en orden, y al final `row` es la permutación total. Filas y columnas son independientes.

## Juegos y constructivos

**[M5] Juegos: Grundy y mex** — Juego imparcial: grundy(estado) = mex de los grundy de los estados alcanzables; varios juegos independientes → XOR de sus grundy; el primero pierde si el XOR es 0. Antes de programar Grundy, prueba casos pequeños a mano y busca un invariante (paridad, módulo 3, simetría/imitar al rival).

Código: [`juegos/grundy.cpp`](juegos/grundy.cpp)

**[M6] Patrones constructivos** — Cuándo: "construye una secuencia/arreglo que cumpla…".

| Patrón | Idea |
| --- | --- |
| Pensar hacia atrás | Simula desde el estado final al inicial (pliegues, eliminaciones) |
| Extremos + inducción | Demuestra dónde va el 1 (o el máximo), quítalo y repite con n−1; dos punteros `l`, `r` |
| Sistema lineal de bloques | Si la solución se arma con bloques de tamaño 2 y 3: n = 2·a + 3·b y k = a + b → a = 3k − n, b = n − 2k (verifica a, b ≥ 0) |
| Fuerza bruta pequeña | Genera todas las respuestas para n ≤ 8 en Python y busca el patrón |

Tests: [`tests/test_matematica.cpp`](tests/test_matematica.cpp) (contra fuerza bruta y con los ejemplos de UCAB 2025 A, I, K).
