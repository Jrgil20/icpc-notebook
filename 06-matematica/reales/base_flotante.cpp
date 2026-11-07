// Base flotante
typedef long double ld;
const ld PI = acosl(-1);
const ld EPS = 1e-9;
int sgn(ld x){ return (x > EPS) - (x < -EPS); }      // -1, 0, 1 con tolerancia
bool eq(ld a, ld b){ return fabsl(a - b) < EPS; }
