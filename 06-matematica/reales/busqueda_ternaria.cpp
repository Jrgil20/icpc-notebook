// Busqueda ternaria: maximo de f unimodal en [lo, hi]
// Requiere: reales/base_flotante.cpp (ld)
template<class F> ld ternaryMax(ld lo, ld hi, F f){
    for (int it = 0; it < 200; it++){ ld m1 = lo + (hi - lo) / 3, m2 = hi - (hi - lo) / 3;
        if (f(m1) < f(m2)) lo = m1; else hi = m2; }
    return (lo + hi) / 2; }
