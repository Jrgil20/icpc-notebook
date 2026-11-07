#include <bits/stdc++.h>
using namespace std;
// Por tarea: con prob 1/6 empatan (descansan x y se repite); si no, la hace Alice o Bob con prob 1/2 cada uno.
// E = (5/6)*(a+b)/2 + (1/6)*(x + E)  ->  E = (a+b)/2 + x/5.  Linealidad: total = n * E.
int main(){
    int q; if (scanf("%d", &q) != 1) return 0;
    while (q--){ long long n, a, b, x; if (scanf("%lld %lld %lld %lld", &n, &a, &b, &x) != 4) return 0;
        long double E = n * ((a + b) / 2.0L + x / 5.0L);
        printf("%.6Lf\n", E); }
}
