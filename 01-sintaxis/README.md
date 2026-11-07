# Sintaxis: "quiero hacer X" → código

Para cuando sabes **qué** hacer pero no recuerdas **cómo se escribe**. Busca la intención en la columna izquierda.

| Archivo | Contenido |
| --- | --- |
| Este README | Tablas rápidas Python ↔ C++ (leer, imprimir, strings, listas, diccionarios, números) |
| [`python.md`](python.md) | Python por tema, con trampas del juez |
| [`cpp.md`](cpp.md) | C++ y la STL por tema, con trampas |
| [`ejemplo_record.py`](ejemplo_record.py) | Ejercicio resuelto: contar días con un nuevo máximo (leer `n` + lista) |

Leer líneas con espacios que importan (por ejemplo, la segunda línea es `[ abc]`):

```python
import sys
texto = sys.stdin.readline().rstrip("\n")   # NO uses .strip(): borraria espacios utiles
f, guia = input().split(" ", 1)             # separa solo en el PRIMER espacio
```

Busca la intención en la columna izquierda. En C++ se asume `#include <bits/stdc++.h>`, `using namespace std;` y `typedef long long ll;` (ver [C1]).

**Q1 — Leer entrada**

| Quiero… | Python | C++ |
| --- | --- | --- |
| Un entero | `n = int(input())` | `int n; cin >> n;` |
| Dos enteros en una línea | `x, y = map(int, input().split())` | `cin >> x >> y;` |
| Una línea de N enteros → lista | `a = list(map(int, input().split()))` | `vector<ll> a(n); for (auto &x : a) cin >> x;` |
| Una palabra / string sin espacios | `s = input().strip()` | `string s; cin >> s;` |
| Una línea completa con espacios | `line = input()` | `getline(cin, line);` (si antes usaste `cin >>`, llama `getline` una vez extra para comer el salto) |
| Matriz R×C de números | `m = [list(map(int, input().split())) for _ in range(R)]` | `vector<vector<int>> m(R, vector<int>(C)); for (auto &f : m) for (auto &x : f) cin >> x;` |
| Grilla de caracteres | `g = [input().strip() for _ in range(R)]` | `vector<string> g(R); for (auto &f : g) cin >> f;` |
| Todo lo que queda (hasta EOF) | `rest = sys.stdin.read().split()` | `while (cin >> x) { ... }` |
| Leer rápido (N ≥ 10^5) | `import sys; input = sys.stdin.readline` (luego usa `.strip()` en strings) | `ios::sync_with_stdio(false); cin.tie(nullptr);` |

**Q2 — Imprimir**

| Quiero… | Python | C++ |
| --- | --- | --- |
| Lista separada por espacios | `print(*a)` | `for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1];` |
| Un valor por línea | `print(*a, sep="\n")` | `for (auto x : a) cout << x << "\n";` |
| Decimal con 2 cifras | `print(f"{x:.2f}")` | `cout << fixed << setprecision(2) << x << "\n";` |
| Muchas líneas rápido | `sys.stdout.write("\n".join(out) + "\n")` | usa `"\n"`, nunca `endl` |
| Sí/No | `print("YES" if ok else "NO")` | `cout << (ok ? "YES" : "NO") << "\n";` |

**Q3 — Strings**

| Quiero… | Python | C++ |
| --- | --- | --- |
| Contar ocurrencias de un carácter | `s.count("a")` | `count(s.begin(), s.end(), 'a')` |
| Posición de una subcadena (−1 si no está) | `s.find("na")` | `s.find("na")` (devuelve `string::npos` si no está) |
| ¿Contiene? | `"na" in s` | `s.find("na") != string::npos` |
| Subcadena desde i, largo k | `s[i:i+k]` | `s.substr(i, k)` |
| Invertir | `s[::-1]` | `reverse(s.begin(), s.end());` |
| Reemplazar | `s.replace("a", "o")` | (a mano con un bucle) |
| Dividir por espacios / por coma | `s.split()` / `s.split(",")` | `stringstream ss(line); while (ss >> w) ...` |
| Unir lista de strings | `" ".join(lst)` | bucle con `+=` |
| String → número | `int(s)` | `stoi(s)` / `stoll(s)` |
| Número → string | `str(x)` | `to_string(x)` |
| Dígito carácter → valor | `int(c)` u `ord(c) - 48` | `c - '0'` |
| Letra → índice 0..25 | `ord(c) - ord('a')` | `c - 'a'` |
| Mayúsculas / minúsculas | `s.upper()` / `s.lower()` | `toupper(c)` / `tolower(c)` |
| ¿Es dígito / letra? | `c.isdigit()` / `c.isalpha()` | `isdigit(c)` / `isalpha(c)` |
| Frecuencia de cada letra | `Counter(s)` | `int f[26] = {}; for (char c : s) f[c - 'a']++;` |
| Caracteres ordenados | `"".join(sorted(s))` | `sort(s.begin(), s.end());` |

**Q4 — Listas / vectores**

| Quiero… | Python | C++ |
| --- | --- | --- |
| Contar cuántas veces aparece x | `a.count(x)` | `count(a.begin(), a.end(), x)` |
| Máximo / mínimo / suma | `max(a)`, `min(a)`, `sum(a)` | `*max_element(a.begin(), a.end())`, `accumulate(a.begin(), a.end(), 0LL)` |
| Índice del máximo | `a.index(max(a))` | `max_element(a.begin(), a.end()) - a.begin()` |
| Ordenar ascendente / descendente | `a.sort()` / `a.sort(reverse=True)` | `sort(a.begin(), a.end());` / `sort(a.rbegin(), a.rend());` |
| Ordenar por 2 criterios (1.º desc, 2.º asc) | `a.sort(key=lambda p: (-p[0], p[1]))` | `sort(..., [](auto &x, auto &y){ if (x.first != y.first) return x.first > y.first; return x.second < y.second; });` |
| Quitar duplicados | `sorted(set(a))` | `sort(...); a.erase(unique(a.begin(), a.end()), a.end());` |
| Último elemento | `a[-1]` | `a.back()` |
| Recorrer con índice | `for i, v in enumerate(a):` | `for (int i = 0; i < n; i++)` |
| Recorrer dos listas a la vez | `for u, v in zip(a, b):` | `for (int i = 0; i < n; i++) { a[i]; b[i]; }` |
| Primer índice con a[i] ≥ x (lista ordenada) | `bisect_left(a, x)` | `lower_bound(a.begin(), a.end(), x) - a.begin()` |
| Primer índice con a[i] > x | `bisect_right(a, x)` | `upper_bound(a.begin(), a.end(), x) - a.begin()` |
| Lista de N ceros / matriz | `[0]*n` / `[[0]*C for _ in range(R)]` | `vector<ll> v(n, 0);` / `vector<vector<int>> m(R, vector<int>(C, 0));` |
| ¿Alguno / todos cumplen? | `any(x > 7 for x in a)` / `all(...)` | `any_of(a.begin(), a.end(), [](ll x){ return x > 7; })` |

**Q5 — Contar, agrupar, buscar rápido**

| Quiero… | Python | C++ |
| --- | --- | --- |
| Diccionario contador | `d = defaultdict(int); d[k] += 1` | `map<string,int> d; d[k]++;` |
| Agrupar valores por clave | `d = defaultdict(list); d[k].append(v)` | `map<int, vector<int>> d; d[k].push_back(v);` |
| Lo más frecuente | `Counter(a).most_common(1)` | recorrer el map buscando el mayor |
| ¿Ya vi este valor? | `vis = set(); x in vis` | `set<int> vis; vis.count(x)` |
| Sacar siempre el menor | `heapq.heappush(h, x); heapq.heappop(h)` | `priority_queue<ll, vector<ll>, greater<ll>> pq;` |
| Sacar siempre el mayor | push `-x`, pop y niega | `priority_queue<ll> pq;` |
| Cola por ambos lados | `deque`: `append`, `appendleft`, `pop`, `popleft` | `deque`: `push_back`, `push_front`, `pop_back`, `pop_front` |

**Q6 — Números**

| Quiero… | Python | C++ |
| --- | --- | --- |
| División entera / resto | `a // b`, `a % b` | `a / b`, `a % b` (¡con negativos difiere! ver [P7]) |
| Redondear hacia arriba a/b (positivos) | `(a + b - 1) // b` | `(a + b - 1) / b` |
| MCD / MCM | `math.gcd(a, b)`, `math.lcm(a, b)` | `gcd(a, b)`, `lcm(a, b)` |
| Raíz entera | `math.isqrt(n)` | `ll r = sqrtl(n); while (r*r > n) r--; while ((r+1)*(r+1) <= n) r++;` |
| Potencia mod m | `pow(b, e, m)` | `pw(b, e, m)` en [M1] |
| Combinaciones n en k (exacto) | `math.comb(n, k)` | `C(n, k)` mod p en [M1] |
| Binario | `bin(x)[2:]`, `int("1010", 2)` | `bitset<32>(x).to_string()`, `stoll("1010", nullptr, 2)` |
| Contar bits en 1 | `x.bit_count()` (Python ≥ 3.10) o `bin(x).count("1")` | `__builtin_popcountll(x)` |
| Infinito | `float('inf')` o `10**18` | `const ll INF = 4e18;` |

