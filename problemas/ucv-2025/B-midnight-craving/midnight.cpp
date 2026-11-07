#include <bits/stdc++.h>
using namespace std;
// Segment tree con merge personalizado: por nodo, prefijo/sufijo/mejor racha de 0s y de 1s.
// Invertir un rango = intercambiar los datos de 0s y 1s (lazy). Ver 04-estructuras/segtree_rachas_flip.cpp.
struct RunNode { int len = 0, pre[2] = {0, 0}, suf[2] = {0, 0}, best[2] = {0, 0}; };
RunNode mergeRun(const RunNode& a, const RunNode& b){
    if (a.len == 0) return b; if (b.len == 0) return a;
    RunNode r; r.len = a.len + b.len;
    for (int c = 0; c < 2; c++){
        r.pre[c] = a.pre[c] == a.len ? a.len + b.pre[c] : a.pre[c];
        r.suf[c] = b.suf[c] == b.len ? b.len + a.suf[c] : b.suf[c];
        r.best[c] = max({a.best[c], b.best[c], a.suf[c] + b.pre[c]}); }
    return r; }
struct SegRuns {
    int n; vector<RunNode> t; vector<bool> lz;
    SegRuns(const string& s) : n(s.size()), t(4 * s.size()), lz(4 * s.size(), false) { build(s, 1, 0, n - 1); }
    void build(const string& s, int x, int l, int r){
        if (l == r){ int c = s[l] - '0'; t[x].len = 1; t[x].pre[c] = t[x].suf[c] = t[x].best[c] = 1; return; }
        int m = (l + r) / 2; build(s, 2*x, l, m); build(s, 2*x+1, m + 1, r); t[x] = mergeRun(t[2*x], t[2*x+1]); }
    void applyFlip(int x){ swap(t[x].pre[0], t[x].pre[1]); swap(t[x].suf[0], t[x].suf[1]); swap(t[x].best[0], t[x].best[1]); lz[x] = !lz[x]; }
    void push(int x){ if (lz[x]){ applyFlip(2*x); applyFlip(2*x+1); lz[x] = false; } }
    void flip(int a, int b, int x, int l, int r){
        if (b < l || r < a) return;
        if (a <= l && r <= b){ applyFlip(x); return; }
        push(x); int m = (l + r) / 2; flip(a, b, 2*x, l, m); flip(a, b, 2*x+1, m + 1, r); t[x] = mergeRun(t[2*x], t[2*x+1]); }
    RunNode query(int a, int b, int x, int l, int r){
        if (b < l || r < a) return RunNode();
        if (a <= l && r <= b) return t[x];
        push(x); int m = (l + r) / 2; return mergeRun(query(a, b, 2*x, l, m), query(a, b, 2*x+1, m + 1, r)); }
};
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, q; string s; cin >> n >> q >> s; SegRuns st(s);
    while (q--){ int op, l, r; cin >> op >> l >> r; l--; r--;
        if (op == 1) cout << st.query(l, r, 1, 0, n - 1).best[0] << "\n"; else st.flip(l, r, 1, 0, n - 1); }
}
