// Funciones seguras
// Requiere: reales/base_flotante.cpp (ld)
ld safeSqrt(ld x){ return sqrtl(max((ld)0, x)); }
ld safeAcos(ld x){ return acosl(max((ld)-1, min((ld)1, x))); }
