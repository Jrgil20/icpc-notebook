// Orden angular alrededor del origen (barrido radial)
// Requiere: enteros/punto_entero.cpp
int half(P p){ return p.y < 0 || (p.y == 0 && p.x < 0); } // 0: [0,180)  1: [180,360)
bool angLess(P a, P b){ if (half(a) != half(b)) return half(a) < half(b); return cross(a, b) > 0; }
