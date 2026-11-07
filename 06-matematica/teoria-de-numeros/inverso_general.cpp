// Inverso modular con modulo NO primo (existe si gcd(a, m) = 1), -1 si no existe
// Requiere: teoria-de-numeros/extgcd.cpp
ll invGeneral(ll a, ll m){ ll x, y; ll g = extgcd(((a % m) + m) % m, m, x, y); if (g != 1) return -1; return ((x % m) + m) % m; }
