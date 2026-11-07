#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const ld PI = acosl(-1);
// Volumen hasta la altura y: cono truncado con radios r y r + (R - r) * y / h. Es creciente en y:
// busqueda binaria de y tal que vol(y) = vol(h) / 2.
ld frustum(ld r, ld R, ld h){ return PI * h * (R*R + r*r + R*r) / 3; }
int main(){
    int t; if (scanf("%d", &t) != 1) return 0;
    while (t--){ double r0, R0, h0; if (scanf("%lf %lf %lf", &r0, &R0, &h0) != 3) return 0; ld r = r0, R = R0, h = h0;
        auto vol = [&](ld y){ return frustum(r, r + (R - r) * y / h, y); };
        ld target = vol(h) / 2, lo = 0, hi = h;
        for (int it = 0; it < 100; it++){ ld mid = (lo + hi) / 2; if (vol(mid) < target) lo = mid; else hi = mid; }
        printf("%.9Lf\n", (lo + hi) / 2); }
}
