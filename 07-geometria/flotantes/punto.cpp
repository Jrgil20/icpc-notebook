// Punto/vector flotante
// Requiere: 06-matematica/reales/base_flotante.cpp
struct PT { ld x, y;
    PT operator+(PT o) const { return {x + o.x, y + o.y}; }
    PT operator-(PT o) const { return {x - o.x, y - o.y}; }
    PT operator*(ld k) const { return {x * k, y * k}; }
    PT operator/(ld k) const { return {x / k, y / k}; } };
ld dot(PT a, PT b){ return a.x * b.x + a.y * b.y; }
ld cross(PT a, PT b){ return a.x * b.y - a.y * b.x; }
ld norm(PT a){ return hypotl(a.x, a.y); }
ld dist(PT a, PT b){ return norm(a - b); }
PT perp(PT a){ return {-a.y, a.x}; }                                   // rota 90 antihorario
PT rotate(PT a, ld t){ return {a.x * cosl(t) - a.y * sinl(t), a.x * sinl(t) + a.y * cosl(t)}; }
ld angleBetween(PT a, PT b){ return fabsl(atan2l(cross(a, b), dot(a, b))); }  // [0, pi]
PT polar(ld r, ld t){ return {r * cosl(t), r * sinl(t)}; }
