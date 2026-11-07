#include <bits/stdc++.h>
using namespace std;
// Patron valido: K letras X sin vecinos, huecos internos de 1 o 2 '-', extremos con 0 o 1 '-'.
// N = K + huecos -> minimo 2K-1, maximo 3K. Se reparte el sobrante: primero extremos, luego huecos internos.
int main(){
    long long K, N; cin >> K >> N;
    if (N < 2 * K - 1 || N > 3 * K){ puts("*"); return 0; }
    long long extra = N - (2 * K - 1);
    int left = 0, right = 0; vector<int> gap(max(0LL, K - 1), 1);
    if (extra > 0){ left = 1; extra--; }
    if (extra > 0){ right = 1; extra--; }
    for (auto &g : gap) if (extra > 0){ g = 2; extra--; }
    string s(left, '-');
    for (long long i = 0; i < K; i++){ s += 'X'; if (i < K - 1) s += string(gap[i], '-'); }
    s += string(right, '-');
    puts(s.c_str());
}
