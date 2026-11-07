#include "../../00-base/header.h"
#include "../../06-matematica/reales/base_flotante.cpp"
#include "../../06-matematica/reales/busqueda_binaria_real.cpp"
#include "../../06-matematica/reales/busqueda_ternaria.cpp"
#include "../../06-matematica/reales/funciones_seguras.cpp"
#include "../../06-matematica/reales/division_floor_ceil.cpp"
#include "../../06-matematica/aritmetica-modular/mulmod_int128.cpp"
#include "../../06-matematica/aritmetica-modular/factoriales_ncr.cpp"
#include "../../06-matematica/teoria-de-numeros/criba_divisores.cpp"
#include "../../06-matematica/teoria-de-numeros/bases.cpp"
#include "../../06-matematica/teoria-de-numeros/extgcd.cpp"
#include "../../06-matematica/teoria-de-numeros/diofantica.cpp"
#include "../../06-matematica/teoria-de-numeros/inverso_general.cpp"
#include "../../06-matematica/teoria-de-numeros/crt.cpp"
#include "../../06-matematica/teoria-de-numeros/phi.cpp"
#include "../../06-matematica/teoria-de-numeros/divisores_suma.cpp"
#include "../../06-matematica/teoria-de-numeros/miller_rabin.cpp"
#include "../../06-matematica/teoria-de-numeros/matriz_potencia.cpp"
#include "../../06-matematica/teoria-de-numeros/sumas_cerradas.cpp"
#include "../../06-matematica/teoria-de-numeros/bloques_n_div_i.cpp"
#include "../../06-matematica/combinatoria/ncr_n_grande.cpp"
#include "../../06-matematica/combinatoria/lucas.cpp"
#include "../../06-matematica/combinatoria/pascal.cpp"
#include "../../06-matematica/combinatoria/inclusion_exclusion.cpp"
#include "../../06-matematica/combinatoria/desarreglos_stirling.cpp"
#include "../../06-matematica/combinatoria/permutaciones_inversiones.cpp"
#include "../../06-matematica/probabilidad/esperanza_repetir.cpp"
#include "../../06-matematica/probabilidad/fraccion_mod.cpp"
#include "../../06-matematica/probabilidad/dp_dados.cpp"
#include "../../06-matematica/permutaciones/permutaciones.cpp"
#include "../../06-matematica/juegos/grundy.cpp"
int main(){
    assert(sgn(1e-12) == 0 && sgn(1) == 1 && eq(0.1L + 0.2L, 0.3L));
    assert(eq(bsReal(0, 10, 2, [](ld x){ return x * x; }), sqrtl(2)));
    assert(eq(ternaryMax(0, PI, [](ld x){ return sinl(x); }), PI / 2) || fabsl(ternaryMax(0, PI, [](ld x){ return sinl(x); }) - PI/2) < 1e-6);
    for (ll a = -20; a <= 20; a++) for (ll b = -7; b <= 7; b++) if (b){ assert(floorDiv(a, b) == (ll)floorl((ld)a / b)); assert(ceilDiv(a, b) == (ll)ceill((ld)a / b)); }
    initFact(); assert(C(5,2) == 10 && C(1000,500) == 159835829); assert(pw(2, MD - 1) == 1);
    auto spf = sieve(100); assert(spf[91] == 7 && spf[97] == 97);
    assert((divisors(36) == vector<ll>{1,2,3,4,6,9,12,18,36})); auto fz = factorize(360); assert(fz.size() == 3 && fz[0].second == 3);
    assert(isPal(toBase(5, 2)) && !isPal(toBase(6, 2)));
    auto f = invCount(6, 15); assert(f[3][1] == 2 && f[4][3] == 6); ll tot = 0; for (ll v : f[6]) tot += v; assert(tot == 720);
    vector<int> v = {0,1,3}; assert(mex(v) == 2);
    ll M18 = 1000000000000000003LL;
    // UCAB K: k^2 mod 1e18+3
    assert(mulmod(1, 1, M18) == 1 && mulmod(3, 3, M18) == 9); ll k = 1000000000000000000LL; lll ex = (lll)k * k % M18; assert(mulmod(k, k, M18) == (ll)ex);
    assert(powmod(2, 64, M18) == (ll)(((lll)1 << 64) % M18));
    // UCAB I: C(n,3) mod 1e9+7, n hasta 1e18
    assert(nCrBig(3,3,MD) == 1 && nCrBig(4,3,MD) == 4 && nCrBig(5,3,MD) == 10 && nCrBig(7,3,MD) == 35);
    { ll n = 1000000000000000000LL; lll a = (lll)n * (n-1) / 2; a = a % MD * ((n-2) % MD) % MD; a = a * powmod(3, MD-2, MD) % MD; assert(nCrBig(n, 3, MD) == (ll)a); }
    auto C = pascal(60, MD), C7 = pascal(60, 7); for (int n = 0; n <= 60; n++) for (int r = 0; r <= n; r++) assert(lucas(n, r, 7) == C7[n][r] && nCrBig(n, r, MD) == C[n][r]);
    auto C6 = pascal(10, 6); assert(C6[10][5] == 252 % 6);
    vector<ll> dv = {2, 3, 5}; assert(countDivisible(30, dv) == 22); vector<ll> big = {1000000007, 998244353}; assert(countDivisible(1000000000000LL, big) == 1000000000000LL/1000000007 + 1000000000000LL/998244353 - 1000000000000LL/(1000000007LL*998244353));
    auto D = derangements(6, MD); assert(D[3] == 2 && D[4] == 9 && D[6] == 265); auto S = stirling2(5, MD); assert(S[4][2] == 7 && S[5][3] == 25);
    ll x, y; assert(extgcd(30, 12, x, y) == 6 && 30 * x + 12 * y == 6);
    assert(diophantine(6, 9, 21, x, y) && 6 * x + 9 * y == 21 && !diophantine(6, 9, 20, x, y));
    assert(invGeneral(3, 10) == 7 && invGeneral(4, 10) == -1);
    mt19937 rng(5);
    for (int t = 0; t < 2000; t++){ ll m1 = rng() % 50 + 1, m2 = rng() % 50 + 1, r1 = rng() % m1, r2 = rng() % m2; auto [r, l] = crt(r1, m1, r2, m2);
        ll br = -1; for (ll v = 0; v < m1 * m2; v++) if (v % m1 == r1 && v % m2 == r2){ br = v; break; } assert(r == br); }
    auto ph = phiSieve(1000); for (int n = 1; n <= 1000; n++){ int c = 0; for (int i = 1; i <= n; i++) if (gcd(i, n) == 1) c++; assert(ph[n] == c && phi(n) == c); }
    for (ll n = 1; n <= 500; n++){ ll c = 0, s = 0; for (ll i = 1; i <= n; i++) if (n % i == 0){ c++; s += i; } auto [dc, ds] = divCountSum(n); assert(dc == c && ds == s); }
    for (ll n = 0; n < 5000; n++){ bool b = n >= 2; for (ll i = 2; i * i <= n; i++) if (n % i == 0) b = false; assert(isPrime(n) == b); }
    assert(isPrime(1000000007) && isPrime(1000000000000000003LL) && !isPrime(1000000007LL * 998244353LL) && isPrime(998244353));
    assert(fib(1, MD) == 1 && fib(10, MD) == 55 && fib(90, (ll)4e18) == 2880067194370816120LL);
    assert(sum1(100) == 5050 && sum2(3) == 14 && sum3(3) == 36);
    for (ll r = 0; r < 6; r++) for (ll n = 0; n < 20; n++){ ll s = 0, p = 1; for (ll i = 0; i < n; i++){ s = (s + p) % 1000; p = p * r % 1000; } assert(geoSum(r, n, 1000) == s); }
    for (ll n = 1; n <= 300; n++){ ll s = 0; for (ll i = 1; i <= n; i++) s += n / i; assert(sumFloor(n) == s); }
    // UCAB A: dados 6 caras. pRep = 1/6 (empate, cuesta x); si no empate, la tarea cuesta a o b con prob 1/2 c/u
    ll cases[4][5] = {{1,10,20,5,16},{4,10,20,5,64},{3,10,13,10,0},{5,30,40,20,195}}; ld exp3 = 40.5;
    for (auto &c : cases){ ld E = c[0] * expectedRetry(1.0L/6, c[3], (c[1] + c[2]) / 2.0L); ld want = c[4] ? c[4] : exp3; assert(fabsl(E - want) < 1e-9); }
    assert(fracMod(1, 2) == 500000004);
    auto ds2 = diceSum(2, 6); assert(fabsl(ds2[7] - 6.0L/36) < 1e-12);
    vector<int> p = {1, 2, 0, 4, 3}; auto cs = cycles(p); assert(cs.size() == 2); auto iv = inverse(p); auto id = compose(p, iv); for (int i = 0; i < 5; i++) assert(id[i] == i);
    auto p3 = permPow(p, 3); auto b3 = compose(p, compose(p, p)); assert(p3 == b3); auto p6 = permPow(p, 6); for (int i = 0; i < 5; i++) assert(p6[i] == i);
    puts("matematica OK");
}
