#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int lo = 1, hi = 1000000;
    while (lo < hi){
        int mid = lo + (hi - lo) / 2;
        cout << "? " << mid << endl;        // endl SI aqui: hace flush
        string r; cin >> r;                 // formato de respuesta segun el enunciado
        if (r == "<") hi = mid; else lo = mid + 1;
    }
    cout << "! " << lo << endl;
}
