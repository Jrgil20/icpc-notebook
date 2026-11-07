# C++ y la STL por tema

**[C1] Plantilla base** — Todas las plantillas de [A]–[GE] asumen este encabezado. Compila con `g++ -std=c++20 -O2 -Wall A.cpp -o A`.

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 4e18;
const ll MD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    // ... resolver ...
    cout << "respuesta" << "\n";
}
```

**[C2] Strings**

```cpp
string s; cin >> s;                    // una palabra
string line; getline(cin, line);       // linea completa (tras cin >>, llama getline 2 veces)
s.size(); s[i]; s += 'x'; s += "abc"; s.push_back('x'); s.pop_back();
s.substr(i, k);                        // desde i, largo k
s.find("na");                          // string::npos si no esta
count(s.begin(), s.end(), 'a');
reverse(s.begin(), s.end()); sort(s.begin(), s.end());
stoi(s); stoll(s); to_string(x);
c - '0'; c - 'a'; (char)('a' + k); isdigit(c); isalpha(c); toupper(c);
stringstream ss(line); string w; while (ss >> w) palabras.push_back(w);
```

**[C3] Vectores y ordenamiento**

```cpp
vector<int> v(n, 0); v.push_back(x); v.pop_back(); v.back(); v.size(); v.clear();
vector<vector<int>> m(R, vector<int>(C, 0));
sort(v.begin(), v.end());              // ascendente
sort(v.rbegin(), v.rend());            // descendente
sort(p.begin(), p.end(), [](auto &x, auto &y){
    if (x.first != y.first) return x.first > y.first;   // 1.o desc
    return x.second < y.second; });                     // 2.o asc
*max_element(v.begin(), v.end()); max_element(v.begin(), v.end()) - v.begin();
accumulate(v.begin(), v.end(), 0LL);   // 0LL, no 0, o se desborda
lower_bound(v.begin(), v.end(), x) - v.begin();   // primer >= x
upper_bound(v.begin(), v.end(), x) - v.begin();   // primer > x
v.erase(unique(v.begin(), v.end()), v.end());     // tras sort: quitar duplicados
next_permutation(v.begin(), v.end());             // do { ... } while (next_permutation(...));
pair<int,int> pr = {1, 2}; pr.first; pr.second;
for (auto &[k, val] : pares) { ... }              // desempaquetar
```

**[C4] set, multiset, map**

```cpp
set<int> st; st.insert(x); st.erase(x); st.count(x);   // ordenado, sin repetidos, O(log n)
*st.begin(); *st.rbegin();                             // menor / mayor
*st.lower_bound(x);                                    // menor elemento >= x (verifica != st.end())
multiset<int> ms; ms.erase(ms.find(x));                // borra UNA copia (ms.erase(x) borra todas)
map<string,int> mp; mp[k]++; mp.count(k);              // ordenado por clave
for (auto &[k, v] : mp) { ... }
unordered_map<int,int> um;                             // O(1) promedio, sin orden
```

**[C5] Colas, pilas, heaps**

```cpp
queue<int> q; q.push(x); q.front(); q.pop(); q.empty();
stack<int> sk; sk.push(x); sk.top(); sk.pop();
deque<int> dq; dq.push_front(x); dq.push_back(x); dq.front(); dq.back();
priority_queue<int> mx;                                    // saca el MAYOR
priority_queue<int, vector<int>, greater<int>> mn;         // saca el MENOR
priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;   // Dijkstra
```

**[C6] Bits y utilidades**

```cpp
__builtin_popcountll(x);      // bits en 1
__lg(x);                      // posicion del bit mas alto (floor log2)
x & (1 << i);                 // bit i encendido?
for (int mask = 0; mask < (1 << n); mask++)   // todos los subconjuntos
gcd(a, b); lcm(a, b);
bitset<32>(x).to_string();
cout << fixed << setprecision(6) << x;
min({a, b, c}); max({a, b, c}); swap(a, b);
```

**[C7] Trampas de C++**

| Trampa | Solución |
| --- | --- |
| Desborde: `int` llega a ~2·10^9 | Usa `ll` para sumas, productos y distancias; `1LL * a * b` |
| `endl` en bucles grandes | Usa `"\n"` |
| `cerr` de depuración en el envío | Bórralo: cuenta en el límite de salida (ver [J]) |
| `-7 % 3 == -1` | `((x % m) + m) % m` |
| `v.size() - 1` con vector vacío | Es `unsigned`: da un número gigante. Usa `(int)v.size() - 1` |
| `accumulate(..., 0)` | `0LL` |
| Arreglo local enorme (`int a[1000000]` en `main`) | Decláralo global o usa `vector` |
| Comparar `double` con `==` | `fabs(a - b) < 1e-9`, o trabaja en enteros |
