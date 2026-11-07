// Teorema chino del resto (modulos no necesariamente coprimos)
// Requiere: teoria-de-numeros/extgcd.cpp, aritmetica-modular/mulmod_int128.cpp (lll)
// x = r1 (mod m1), x = r2 (mod m2) -> {r, lcm} o {-1, -1} si no hay solucion
pair<ll,ll> crt(ll r1, ll m1, ll r2, ll m2){ ll p, q; ll g = extgcd(m1, m2, p, q);
    if ((r2 - r1) % g) return {-1, -1};
    ll l = m1 / g * m2; lll t = (lll)(r2 - r1) / g * p % (m2 / g);
    ll r = (ll)(((lll)r1 + (lll)m1 * t) % l); if (r < 0) r += l; return {r, l}; }
