# Python por tema

**[P1] Plantilla base** — Cópiala al empezar cualquier problema en Python.

```python
import sys
from collections import Counter, defaultdict, deque
import heapq, bisect, math, itertools
input = sys.stdin.readline          # lectura rapida
sys.setrecursionlimit(10**6)        # solo si usas recursion

def main():
    n = int(input())
    a = list(map(int, input().split()))
    s = input().strip()             # .strip() OBLIGATORIO con readline
    print(*a)

main()
```

Trampa: con `input = sys.stdin.readline` el string trae el `\n` al final; `int()` y `split()` lo ignoran, pero `s` sin `.strip()` no.

**[P2] Ejemplo corregido** — contar días en que aparece un nuevo máximo (el ejercicio de hoy).

```python
n = int(input())
a = list(map(int, input().split()))   # toda la linea -> lista de enteros, una sola vez
mx, dias = a[0], 1
for v in a[1:]:
    if v > mx:
        mx = v
        dias += 1
print(dias)
```

**[P3] Strings** — son inmutables: para modificar, pasa a lista y luego `"".join(lista)`.

```python
s = "banana"
s.count("a")      # 3
s.find("n")       # 2   (-1 si no esta)
s.rfind("n")      # 4   (ultima aparicion)
s.index("n")      # 2   (ValueError si no esta)
s[1:4]            # "ana"  (fin exclusivo)
s[::-1]           # "ananab"
s.replace("a","o")# "bonono"
s.startswith("ba") / s.endswith("na")
s.split() / s.split(",") / " ".join(lst)
s.strip() / s.upper() / s.lower() / s.isdigit() / s.isalpha()
"12".zfill(4)     # "0012"
ord("a") -> 97    chr(98) -> "b"
lista = list(s); lista[0] = "B"; s = "".join(lista)
```

**[P4] Listas**

```python
a.append(x); a.pop(); a.pop(0)   # pop(0) es O(n): usa deque
a.count(x); a.index(x); a.reverse(); a.sort()
sorted(a, reverse=True)
sorted(pares, key=lambda p: (-p[0], p[1]))   # 1.o desc, 2.o asc
max(range(n), key=lambda i: a[i])            # indice del maximo
max(words, key=len)
[x*x for x in a if x % 2 == 0]               # comprension
m = [[0]*C for _ in range(R)]                # NUNCA [[0]*C]*R (filas compartidas)
pre = [0]
for v in a: pre.append(pre[-1] + v)          # suma a[l..r] = pre[r+1] - pre[l]
```

**[P5] Diccionarios, sets y contadores**

```python
d = {}; d[k] = d.get(k, 0) + 1
d = defaultdict(int); d[k] += 1           # no falla si k no existe
g = defaultdict(list); g[u].append(v)     # lista de adyacencia
c = Counter(s); c["a"]; c.most_common(2)  # [("a",3),("n",2)]
for k, v in d.items(): ...
for k in sorted(d): ...                   # claves en orden
st = set(); st.add(x); st.discard(x); x in st   # O(1)
```

**[P6] Estructuras**

```python
q = deque([s]); q.append(x); q.appendleft(x); q.popleft(); q.pop()
h = []; heapq.heappush(h, (dist, nodo)); d, u = heapq.heappop(h)   # min-heap
heapq.heappush(h, -x); mayor = -heapq.heappop(h)                   # max-heap
b = [1,3,3,7]
bisect.bisect_left(b, 3)   # 1  primer indice con b[i] >= 3
bisect.bisect_right(b, 3)  # 3  primer indice con b[i] > 3
bisect.insort(b, 5)        # insertar manteniendo orden (O(n))
```

**[P7] Matemática e itertools**

```python
math.gcd(a,b); math.lcm(a,b); math.isqrt(n); math.comb(n,k); math.perm(n,k); math.factorial(n)
pow(b, e, m)          # potencia modular
pow(a, -1, m)         # inverso modular (m primo o coprimo)
divmod(17, 5)         # (3, 2)
-7 // 2  -> -4        # Python redondea hacia -inf
-7 % 3   -> 2         # resto siempre >= 0 (en C++ da -1)
bin(10)[2:]; int("1010", 2); int("ff", 16); hex(255)
itertools.permutations(a, 2); itertools.combinations(a, 2)
itertools.product([0,1], repeat=n)   # todas las mascaras
itertools.accumulate(a)              # sumas prefijas
```

**[P8] Trampas de Python en el juez**

| Trampa | Solución |
| --- | --- |
| TLE con N ≥ 10^5 y bucles anidados | Pasa a C++ |
| Recursión profunda (DFS) revienta | `sys.setrecursionlimit` no basta: usa pila explícita o C++ |
| `print` dentro de un bucle grande es lento | Junta en lista y haz un solo `sys.stdout.write` |
| `[[0]*C]*R` comparte filas | `[[0]*C for _ in range(R)]` |
| Comparar strings numéricos (`"10" < "9"` es True) | Convierte con `int()` antes |
| Nombre del archivo | Debe ser la letra del problema: `A.py3` (ver [J]) |
