#include <bits/stdc++.h>
using namespace std;
// Min-heap directo. Q hasta 2e6: entrada/salida rapida y nada de endl.
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int q; cin >> q; priority_queue<int, vector<int>, greater<int>> pq; string out; out.reserve(1 << 22);
    while (q--){ int op; cin >> op;
        if (op == 1){ int v; cin >> v; pq.push(v); }
        else if (op == 2){ if (!pq.empty()) pq.pop(); }
        else { if (pq.empty()) out += "Empty!\n"; else { out += to_string(pq.top()); out += '\n'; } } }
    cout << out;
}
