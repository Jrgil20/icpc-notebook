#include "../../00-base/header.h"
#include "../../04-estructuras/ordered_set.cpp"
#include "../../04-estructuras/fenwick.cpp"
#include "../../04-estructuras/segtree_lazy.cpp"
#include "../../04-estructuras/sparse_table.cpp"
#include "../../04-estructuras/li_chao.cpp"
#include "../../04-estructuras/segtree_rachas_flip.cpp"
#include "../../04-estructuras/lista_circular.cpp"
int main(){
    mt19937 rng(7);
    int n = 50; BIT b(n); vector<ll> raw(n + 1, 0);
    for (int it = 0; it < 500; it++){ int i = rng() % n + 1; ll v = rng() % 5; b.add(i, v); raw[i] += v;
        int l = rng() % n + 1, r = rng() % n + 1; if (l > r) swap(l, r); ll s = 0; for (int j = l; j <= r; j++) s += raw[j]; assert(b.sum(l, r) == s);
        ll tot = b.sum(n); if (tot > 0){ ll k = rng() % tot + 1; int p = b.kth(k); assert(b.sum(p) >= k && b.sum(p - 1) < k); } }
    ordered_set os; os.insert(5); os.insert(1); os.insert(9); assert(*os.find_by_order(1) == 5 && os.order_of_key(9) == 2); os.erase(5); assert(*os.find_by_order(1) == 9);
    SegLazy sg(n); vector<ll> arr(n, 0);
    for (int it = 0; it < 500; it++){ int l = rng() % n, r = rng() % n; if (l > r) swap(l, r);
        if (rng() % 2){ ll v = rng() % 10; sg.update(l, r, v); for (int j = l; j <= r; j++) arr[j] += v; }
        else { ll s = 0; for (int j = l; j <= r; j++) s += arr[j]; assert(sg.query(l, r) == s); } }
    vector<ll> a(n); for (auto &x : a) x = rng() % 1000; Sparse sp(a);
    for (int it = 0; it < 300; it++){ int l = rng() % n, r = rng() % n; if (l > r) swap(l, r); assert(sp.query(l, r) == *min_element(a.begin() + l, a.begin() + r + 1)); }
    LiChao lc(-1000, 1000); vector<pair<ll,ll>> L;
    for (int it = 0; it < 300; it++){ ll A = (ll)(rng() % 200) - 100, B = (ll)(rng() % 20000) - 10000; lc.add(A, B); L.push_back({A, B});
        ll x = (ll)(rng() % 2001) - 1000; ll best = LLONG_MIN; for (auto [p, q] : L) best = max(best, p * x + q); assert(lc.query(x) == best); }

    // SegRuns vs fuerza bruta
    for (int tc = 0; tc < 200; tc++){ int n = rng() % 20 + 1; string s; for (int i = 0; i < n; i++) s += char('0' + rng() % 2); SegRuns st(s);
        for (int q = 0; q < 50; q++){ int l = rng() % n, r = rng() % n; if (l > r) swap(l, r);
            if (rng() % 2){ st.flip(l, r); for (int i = l; i <= r; i++) s[i] ^= 1; }
            else { int best = 0, cur = 0; for (int i = l; i <= r; i++){ cur = s[i] == '0' ? cur + 1 : 0; best = max(best, cur); } assert(st.longestZeros(l, r) == best); } } }
    for (int n = 1; n <= 30; n++) for (int k = 1; k <= 7; k++) assert(josephus(n, k) == josephusFormula(n, k));
    { CircList L(4); L.erase(1); assert(L.nxt[0] == 2 && L.prv[2] == 0); }
    puts("estructuras OK");
}
