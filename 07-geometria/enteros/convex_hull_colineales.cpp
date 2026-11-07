// Convex hull que INCLUYE los puntos colineales del borde (monotone chain).
// Requiere: punto_entero.cpp
// Caso especial: si todos los puntos estan en una recta, devuelve todos ordenados.
vector<P> hullWithCollinear(vector<P> p){
    sort(p.begin(), p.end()); p.erase(unique(p.begin(), p.end()), p.end());
    int n = p.size(); if (n < 3) return p;
    bool allCol = true; for (int i = 2; i < n; i++) if (orient(p[0], p[1], p[i]) != 0) allCol = false;
    if (allCol) return p;
    vector<P> h(2 * n); int k = 0;
    for (int i = 0; i < n; i++){ while (k >= 2 && orient(h[k-2], h[k-1], p[i]) < 0) k--; h[k++] = p[i]; }
    for (int i = n - 2, t = k + 1; i >= 0; i--){ while (k >= t && orient(h[k-2], h[k-1], p[i]) < 0) k--; h[k++] = p[i]; }
    h.resize(k - 1); return h; }
