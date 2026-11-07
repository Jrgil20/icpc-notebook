#include <bits/stdc++.h>
using namespace std;
// K = 2: la cadena debe alternar -> comparar con 0101... y 1010...
// K >= 3: cada racha de largo L necesita L / K cambios; se invierte el caracter K-1, 2K-1, ... de la racha.
//         Si el ultimo cae justo al final de la racha (L % K == 0), se mueve una posicion antes
//         para no pegarse a la racha siguiente.
int main(){
    int k; string s; cin >> k >> s; int n = s.size();
    if (k == 2){
        string a(n, '0'), b(n, '0'); int ca = 0, cb = 0;
        for (int i = 0; i < n; i++){ a[i] = '0' + (i % 2); b[i] = '0' + (1 - i % 2); ca += a[i] != s[i]; cb += b[i] != s[i]; }
        if (ca <= cb) cout << ca << " " << a << "\n"; else cout << cb << " " << b << "\n";
        return 0;
    }
    int ops = 0;
    for (int i = 0; i < n; ){
        int j = i; while (j < n && s[j] == s[i]) j++;
        int L = j - i;
        for (int p = k - 1; p < L; p += k){ int q = (p == L - 1) ? p - 1 : p; s[i + q] ^= 1; ops++; }
        i = j;
    }
    cout << ops << " " << s << "\n";
}
