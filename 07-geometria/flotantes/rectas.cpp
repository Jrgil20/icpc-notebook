// Rectas y segmentos (recta = dos puntos a, b)
// Requiere: flotantes/punto.cpp
PT project(PT p, PT a, PT b){ PT d = b - a; return a + d * (dot(p - a, d) / dot(d, d)); }
PT reflect(PT p, PT a, PT b){ return project(p, a, b) * 2 - p; }
ld distLine(PT p, PT a, PT b){ return fabsl(cross(b - a, p - a)) / norm(b - a); }
ld distSeg(PT p, PT a, PT b){ PT d = b - a; ld t = dot(p - a, d) / dot(d, d);
    t = max((ld)0, min((ld)1, t)); return dist(p, a + d * t); }
bool lineInter(PT a, PT b, PT c, PT d, PT &out){ // rectas ab y cd; false si paralelas
    ld den = cross(b - a, d - c); if (sgn(den) == 0) return false;
    out = a + (b - a) * (cross(c - a, d - c) / den); return true; }
