// Poligonos
// Requiere: flotantes/punto.cpp
ld polyArea(vector<PT>& p){ ld s = 0; int n = p.size(); for (int i = 0; i < n; i++) s += cross(p[i], p[(i+1)%n]); return fabsl(s) / 2; }
PT centroid(vector<PT>& p){ ld A = 0; PT c = {0, 0}; int n = p.size();
    for (int i = 0; i < n; i++){ ld w = cross(p[i], p[(i+1)%n]); A += w; c = c + (p[i] + p[(i+1)%n]) * w; }
    return c / (3 * A); }
int inPolygon(vector<PT>& p, PT q){ // 1 dentro, 0 en el borde, -1 fuera
    int n = p.size(); bool in = false;
    for (int i = 0; i < n; i++){ PT a = p[i], b = p[(i+1)%n];
        if (sgn(cross(b - a, q - a)) == 0 && sgn(dot(a - q, b - q)) <= 0) return 0;
        if ((a.y > q.y) != (b.y > q.y) && q.x < a.x + (b.x - a.x) * (q.y - a.y) / (b.y - a.y)) in = !in; }
    return in ? 1 : -1; }
// poligono regular de n lados y lado s: area = n*s*s / (4*tan(PI/n)); circunradio R = s / (2*sin(PI/n)); apotema = s / (2*tan(PI/n))
ld regularArea(int n, ld s){ return n * s * s / (4 * tanl(PI / n)); }
