// Circulos
// Requiere: flotantes/rectas.cpp, reales/funciones_seguras.cpp
vector<PT> circleLine(PT c, ld r, PT a, PT b){ // puntos de corte circulo-recta
    PT p = project(c, a, b); ld h2 = r*r - dot(p - c, p - c);
    if (h2 < -EPS) return {}; PT d = (b - a) / norm(b - a); ld h = safeSqrt(h2);
    if (h < EPS) return {p}; return {p - d * h, p + d * h}; }
vector<PT> circleCircle(PT c1, ld r1, PT c2, ld r2){ // circulos distintos
    ld d = dist(c1, c2); if (d > r1 + r2 + EPS || d < fabsl(r1 - r2) - EPS || d < EPS) return {};
    ld a = (r1*r1 - r2*r2 + d*d) / (2*d), h = safeSqrt(r1*r1 - a*a);
    PT m = c1 + (c2 - c1) * (a / d), off = perp(c2 - c1) * (h / d);
    if (h < EPS) return {m}; return {m - off, m + off}; }
PT circumcenter(PT a, PT b, PT c){ // centro del circulo por 3 puntos (no colineales)
    PT B = b - a, C = c - a; ld D = 2 * cross(B, C);
    return a + PT{C.y * dot(B, B) - B.y * dot(C, C), B.x * dot(C, C) - C.x * dot(B, B)} / D; }
ld circleInterArea(ld r1, ld r2, ld d){ // area de la interseccion de dos circulos
    if (d >= r1 + r2) return 0; if (d <= fabsl(r1 - r2)){ ld r = min(r1, r2); return PI * r * r; }
    ld a1 = safeAcos((d*d + r1*r1 - r2*r2) / (2*d*r1)), a2 = safeAcos((d*d + r2*r2 - r1*r1) / (2*d*r2));
    return r1*r1*(a1 - sinl(2*a1)/2) + r2*r2*(a2 - sinl(2*a2)/2); }
