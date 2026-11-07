#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const ld PI = acosl(-1);
// La sombra de alguien de altura H en X cubre [X, X + H / tan(theta)]: respuesta = longitud de la union.
int main(){
    int theta, n; scanf("%d %d", &theta, &n);
    ld t = tanl(theta * PI / 180);
    vector<pair<ld,ld>> v(n);
    for (auto &[l, r] : v){ int x, h; scanf("%d %d", &x, &h); l = x; r = x + h / t; }
    sort(v.begin(), v.end());
    ld tot = 0, curL = v[0].first, curR = v[0].second;
    for (int i = 1; i < n; i++){
        if (v[i].first > curR){ tot += curR - curL; curL = v[i].first; curR = v[i].second; }
        else curR = max(curR, v[i].second); }
    tot += curR - curL;
    printf("%.9Lf\n", tot);
}
