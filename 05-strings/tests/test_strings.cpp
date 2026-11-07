#include "../../00-base/header.h"
#include "../../05-strings/rolling_hash.cpp"
#include "../../05-strings/kmp.cpp"
#include "../../05-strings/z_function.cpp"
#include "../../05-strings/parentesis_balanceados.cpp"
#include "../../05-strings/rachas.cpp"
int main(){
    mt19937 rng(3);
    string s = "abracadabra"; Hash H(s); assert(H.get(0,4) == H.get(7,11)); assert(H.get(0,3) != H.get(1,4));
    auto pos = findAll("abababa", "aba"); assert((pos == vector<int>{0,2,4}));
    auto z = zfn("aabxaab"); assert(z[4] == 3);
    for (int tc = 0; tc < 300; tc++){ int n = rng() % 12 + 1; string t; for (int i = 0; i < n; i++) t += (rng() % 2 ? '(' : ')');
        ll br = 0; for (int l = 0; l < n; l++){ int bl = 0; for (int r = l; r < n; r++){ bl += t[r] == '(' ? 1 : -1; if (bl < 0) break; if (bl == 0) br++; } }
        assert(countBalanced(t) == br); }

    { auto r = runs("aaabcc"); assert(r.size() == 3 && r[0].second == 3 && r[2].first == 'c'); assert(collapse("ddddaata") == "data"); }
    puts("strings OK");
}
