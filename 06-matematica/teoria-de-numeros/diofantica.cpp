// Diofantica a*x + b*y = c (a, b > 0): una solucion; todas = (x + k*b/g, y - k*a/g)
// Requiere: teoria-de-numeros/extgcd.cpp, aritmetica-modular/mulmod_int128.cpp (lll)
bool diophantine(ll a, ll b, ll c, ll &x, ll &y){ ll g = extgcd(a, b, x, y); if (c % g) return false;
    x = (ll)((lll)x * (c / g)); y = (ll)((lll)y * (c / g)); return true; }
