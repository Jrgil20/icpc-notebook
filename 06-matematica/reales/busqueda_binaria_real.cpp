// Busqueda binaria en reales: f creciente, buscar x con f(x) = target
// Requiere: reales/base_flotante.cpp (ld)
template<class F> ld bsReal(ld lo, ld hi, ld target, F f){
    for (int it = 0; it < 200; it++){ ld mid = (lo + hi) / 2; if (f(mid) < target) lo = mid; else hi = mid; }
    return (lo + hi) / 2; }
