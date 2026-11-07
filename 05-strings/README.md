# Strings

En el regional casi nunca piden un algoritmo de strings "puro": suele ir mezclado con hashing, conteo o rangos.
Para manipulación simple con N ≤ 10^4, Python ([`01-sintaxis/python.md`](../01-sintaxis/python.md)) es lo más rápido de escribir.

| Necesito… | Archivo |
| --- | --- |
| Comparar subcadenas en O(1), hashear un estado | [`rolling_hash.cpp`](rolling_hash.cpp) |
| Todas las apariciones de un patrón | [`kmp.cpp`](kmp.cpp) |
| Prefijo común entre s y cada sufijo | [`z_function.cpp`](z_function.cpp) |
| Contar subcadenas con paréntesis balanceados | [`parentesis_balanceados.cpp`](parentesis_balanceados.cpp) |
| Rachas de caracteres iguales, colapsar repetidos | [`rachas.cpp`](rachas.cpp), [`rachas.py`](rachas.py) |

**[S1] Rolling hash (mod 2^61−1, base aleatoria)** — `get(l, r)` = hash de s[l..r) con r EXCLUSIVO. Base aleatoria = resistente a casos anti-hash. Trampa: si dos hashes coinciden, las subcadenas son iguales con probabilidad altísima, no 100 %.

Código: [`rolling_hash.cpp`](rolling_hash.cpp)

Hash de un vector de frecuencias que cambia: guarda H = Σ freq[i]·BASE^i; al hacer `freq[i]++` suma BASE^i a H (O(1)). Restar 1 a todas las entradas = restar Σ BASE^i (precálculalo). Guarda cada H en un `map<ull,int>` con su primer índice.

**[S2] KMP: función prefijo + buscar patrón** — O(|txt| + |pat|). `pi[i]` = largo del borde más largo de s[0..i]. Trampa: el separador `#` no debe aparecer en el texto.

Código: [`kmp.cpp`](kmp.cpp)

**[S3] Z-function** — `z[i]` = largo del mayor prefijo común entre s y s[i..]. `z[0]` queda en 0.

Código: [`z_function.cpp`](z_function.cpp)

**[S4] Contar subcadenas con paréntesis balanceados** — O(n log n). Idea: [l, r) es válida si el balance prefijo en l y r es igual y nunca baja de ese nivel entre medio; al bajar de nivel se "olvidan" los inicios de ese nivel.

Código: [`parentesis_balanceados.cpp`](parentesis_balanceados.cpp)

**[S5] Reducción canónica (parsing sin gramática)** — Cuándo: validar o contar expresiones. Pasos: (1) reemplaza cada nombre de variable por `a` y cada operador binario por `+`; (2) la expresión es válida si los paréntesis están balanceados, no empieza ni termina con `+` y no contiene ninguno de los pares prohibidos `()` `(+` `+)` `++` `)(` `)a` `a(`; (3) corta la cadena en los pares prohibidos y cuenta en cada trozo con [S4] adaptado.

```python
import re
def canon(s):                                  # Python: ideal para este paso
    s = re.sub(r"[A-Za-z_][A-Za-z_0-9]*", "a", s)
    return re.sub(r"[-*/+]", "+", s)
PROHIBIDOS = ["()", "(+", "+)", "++", ")(", ")a", "a("]
```

**[S6] Rachas (run-length encoding)** — Cuándo: "no puede haber K iguales seguidos", "el mensaje no repite símbolos
consecutivos", comprimir. `runs("aaabcc")` da `[(a,3),(b,1),(c,2)]`; `collapse` deja un carácter por racha.
En Python sale directo con `itertools.groupby`. Lo usan LAR 2024 K (Kool Strings) y UCAB 2025 B (Borrar).
Código: [`rachas.cpp`](rachas.cpp), [`rachas.py`](rachas.py).

Tests: [`tests/test_strings.cpp`](tests/test_strings.cpp).
