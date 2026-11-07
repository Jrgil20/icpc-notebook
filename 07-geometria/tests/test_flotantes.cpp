#include "../../00-base/header.h"
#include "../../06-matematica/reales/base_flotante.cpp"
#include "../../06-matematica/reales/funciones_seguras.cpp"
#include "../../06-matematica/reales/busqueda_binaria_real.cpp"
#include "../../07-geometria/trigonometria/angulos.cpp"
#include "../../07-geometria/trigonometria/triangulos.cpp"
#include "../../07-geometria/flotantes/punto.cpp"
#include "../../07-geometria/flotantes/rectas.cpp"
#include "../../07-geometria/flotantes/circulos.cpp"
#include "../../07-geometria/flotantes/poligonos.cpp"
#include "../../07-geometria/volumenes/volumenes.cpp"
#include "../../07-geometria/volumenes/altura_llenado.cpp"
#include "../../02-basicos/intervalos_union.cpp"
int main(){
    assert(eq(toDeg(toRad(30)), 30) && eq(angle360(-1, 0), 3 * PI / 2));
    assert(eq(angleFromSides(3, 4, 5), PI / 2) && eq(sideFromAngle(3, 4, PI / 2), 5) && eq(heron(3, 4, 5), 6) && eq(areaSAS(3, 4, PI / 2), 6));
    PT r = rotate({1, 0}, PI / 2); assert(eq(r.x, 0) && eq(r.y, 1)); assert(eq(angleBetween({1,0},{0,-1}), PI/2));
    PT pr = project({1, 1}, {0, 0}, {2, 0}); assert(eq(pr.x, 1) && eq(pr.y, 0)); PT rf = reflect({1, 1}, {0, 0}, {2, 0}); assert(eq(rf.y, -1));
    assert(eq(distLine({0, 5}, {-1, 0}, {1, 0}), 5) && eq(distSeg({5, 0}, {0, 0}, {1, 0}), 4) && eq(distSeg({0.5L, 2}, {0, 0}, {1, 0}), 2));
    PT x; assert(lineInter({0,0},{1,1},{0,1},{1,0},x) && eq(x.x, 0.5L) && eq(x.y, 0.5L)); assert(!lineInter({0,0},{1,0},{0,1},{1,1},x));
    auto cl = circleLine({0,0}, 1, {-5, 0}, {5, 0}); assert(cl.size() == 2 && eq(cl[0].x, -1) && eq(cl[1].x, 1)); assert(circleLine({0,0},1,{-5,1},{5,1}).size() == 1);
    auto cc = circleCircle({0,0}, 1, {1,0}, 1); assert(cc.size() == 2 && eq(cc[0].x, 0.5L) && eq(fabsl(cc[0].y), sqrtl(3)/2));
    PT cc3 = circumcenter({0,0},{2,0},{0,2}); assert(eq(cc3.x, 1) && eq(cc3.y, 1));
    assert(eq(circleInterArea(1, 1, 0), PI) && eq(circleInterArea(1, 1, 2), 0) && fabsl(circleInterArea(1,1,1) - (2*PI/3 - sqrtl(3)/2)) < 1e-9);
    vector<PT> sq = {{0,0},{2,0},{2,2},{0,2}}; assert(eq(polyArea(sq), 4)); PT ce = centroid(sq); assert(eq(ce.x, 1) && eq(ce.y, 1));
    assert(inPolygon(sq, {1,1}) == 1 && inPolygon(sq, {2,1}) == 0 && inPolygon(sq, {3,1}) == -1);
    assert(eq(regularArea(4, 2), 4) && eq(regularArea(6, 1), 3*sqrtl(3)/2));
    assert(eq(frustum(3, 3, 2), cylinder(3, 2)) && eq(frustum(0, 3, 2), cone(3, 2)) && eq(cap(1, 2), sphere(1)) && eq(cap(1,1), sphere(1)/2));
    // UCAB C (Cafe): llenar hasta la mitad del volumen
    ld cafe[4][4] = {{2.5,3.8,8.8,5.271806416},{2.0,4.0,10.0,6.509636245},{1.5,2.5,9.0,5.561206129},{3.0,3.0,8.8,4.4}};
    for (auto &c : cafe) assert(fabsl(fillHeight(c[0], c[1], c[2], 0.5) - c[3]) < 1e-8);
    // LAR 2024 J (Jigsaw of Shadows): sombra = h / tan(theta)
    ld th[3] = {45, 60, 30}, ans[3] = {300, 215.47, 446.41016};
    for (int k = 0; k < 3; k++){ vector<pair<ld,ld>> v; ld X[3] = {50, 0, 100}, H[3] = {150, 100, 200};
        for (int i = 0; i < 3; i++) v.push_back({X[i], X[i] + H[i] / tanl(toRad(th[k]))});
        assert(fabsl(unionLength(v) - ans[k]) < 1e-2); }
    puts("geometria-flotantes OK");
}
