#include "../../00-base/header.h"
#include "../../06-matematica/reales/base_flotante.cpp"
#include "../../02-basicos/prefijos_2d.cpp"
#include "../../02-basicos/busqueda_binaria_respuesta.cpp"
#include "../../02-basicos/dos_punteros.cpp"
#include "../../02-basicos/intervalos_union.cpp"
#include "../../02-basicos/intervalos_fusionar.cpp"
int main(){
    vector<vector<ll>> a = {{1,2,3},{4,5,6}}; auto p = pref2D(a); assert(rect(p,1,2,2,3) == 16);
    assert(firstTrue(0, 1000000, [](ll x){ return x * x >= 50; }) == 8);
    vector<ll> v = {2,1,3,1,1,4}; assert(longestAtMost(v, 5) == 3);
    auto m = mergeIntervals({{5,8},{1,3},{4,4},{10,12}}); assert(m.size() == 2 && m[0].second == 8);
    assert(eq(unionLength({{0,2},{1,3},{5,6}}), 4) && eq(unionLength({}), 0));
    puts("basicos OK");
}
