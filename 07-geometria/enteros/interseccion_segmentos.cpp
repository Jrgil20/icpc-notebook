// Interseccion de segmentos (incluye extremos)
// Requiere: enteros/punto_entero.cpp
bool onSeg(P a, P b, P p){ return orient(a, b, p) == 0 && min(a.x,b.x) <= p.x && p.x <= max(a.x,b.x) && min(a.y,b.y) <= p.y && p.y <= max(a.y,b.y); }
int sgn(ll v){ return (v > 0) - (v < 0); }
bool segInter(P a, P b, P c, P d){
    int o1 = sgn(orient(a,b,c)), o2 = sgn(orient(a,b,d)), o3 = sgn(orient(c,d,a)), o4 = sgn(orient(c,d,b));
    if (o1 != o2 && o3 != o4) return true;
    return onSeg(a,b,c) || onSeg(a,b,d) || onSeg(c,d,a) || onSeg(c,d,b); }
