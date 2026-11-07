// Li-Chao tree: maximo de rectas a*x+b en x enteros [lo, hi]
struct LiChao {
    struct Line { ll a, b; ll eval(ll x) const { return a * x + b; } };
    struct Node { Line ln; int l = -1, r = -1; };
    vector<Node> t; ll lo, hi;
    LiChao(ll lo, ll hi) : lo(lo), hi(hi) { t.push_back({{0, LLONG_MIN / 2}}); }
    void add(Line nw, int x, ll l, ll r){
        ll m = l + (r - l) / 2;
        bool lef = nw.eval(l) > t[x].ln.eval(l), mid = nw.eval(m) > t[x].ln.eval(m);
        if (mid) swap(t[x].ln, nw);
        if (l == r) return;
        if (lef != mid){ if (t[x].l == -1){ t[x].l = t.size(); t.push_back({nw}); } else add(nw, t[x].l, l, m); }
        else { if (t[x].r == -1){ t[x].r = t.size(); t.push_back({nw}); } else add(nw, t[x].r, m + 1, r); } }
    ll query(ll q, int x, ll l, ll r){ if (x == -1) return LLONG_MIN / 2;
        ll m = l + (r - l) / 2, res = t[x].ln.eval(q);
        if (l == r) return res;
        return max(res, q <= m ? query(q, t[x].l, l, m) : query(q, t[x].r, m + 1, r)); }
    void add(ll a, ll b){ add({a, b}, 0, lo, hi); }
    ll query(ll x){ return query(x, 0, lo, hi); }
};
