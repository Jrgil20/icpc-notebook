// Grados/radianes y angulos
// Requiere: reales/base_flotante.cpp
ld toRad(ld deg){ return deg * PI / 180; }
ld toDeg(ld rad){ return rad * 180 / PI; }
ld angle360(ld y, ld x){ ld a = atan2l(y, x); return a < 0 ? a + 2 * PI : a; } // [0, 2pi)
