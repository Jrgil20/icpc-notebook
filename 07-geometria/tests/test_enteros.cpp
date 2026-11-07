#include "../../00-base/header.h"
#include "../../07-geometria/enteros/punto_entero.cpp"
#include "../../07-geometria/enteros/convex_hull.cpp"
#include "../../07-geometria/enteros/interseccion_segmentos.cpp"
#include "../../07-geometria/enteros/orden_angular.cpp"
#include "../../07-geometria/enteros/convex_hull_colineales.cpp"
int main(){
    vector<P> sq = {{0,0},{2,0},{2,2},{0,2}}; assert(area2(sq) == 8);
    vector<P> pts = {{0,0},{2,0},{2,2},{0,2},{1,1},{1,0}}; auto h = hull(pts); assert(h.size() == 4 && area2(h) == 8);
    assert(segInter({0,0},{2,2},{0,2},{2,0})); assert(!segInter({0,0},{1,0},{2,0},{3,0})); assert(segInter({0,0},{2,0},{2,0},{3,1}));
    vector<P> v = {{-1,-1},{1,0},{0,1},{-1,0},{1,1},{0,-1}}; sort(v.begin(), v.end(), angLess);
    assert((v[0] == P{1,0}) && (v[1] == P{1,1}) && (v[2] == P{0,1}) && (v[3] == P{-1,0}) && (v[4] == P{-1,-1}) && (v[5] == P{0,-1}));

    // hull con colineales vs fuerza bruta: punto en el borde del hull estricto
    mt19937 rng(11);
    for (int tc = 0; tc < 300; tc++){ int n = rng() % 12 + 1; vector<P> p; for (int i = 0; i < n; i++) p.push_back({(ll)(rng() % 5), (ll)(rng() % 5)});
        auto strict = hull(p); auto withc = hullWithCollinear(p); sort(p.begin(), p.end()); p.erase(unique(p.begin(), p.end()), p.end());
        int cnt = 0;
        if (strict.size() < 3) cnt = p.size();
        else for (auto &q : p){ bool on = false; for (size_t i = 0; i < strict.size(); i++) if (onSeg(strict[i], strict[(i+1)%strict.size()], q)) on = true; cnt += on; }
        assert((int)withc.size() == cnt); }
    puts("geometria-enteros OK");
}
