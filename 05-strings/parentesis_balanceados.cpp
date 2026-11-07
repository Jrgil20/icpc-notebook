// Contar subcadenas con parentesis balanceados (prefijo + pila de conteos)
ll countBalanced(const string& s){ // '(' = +1, ')' = -1
    // c[b] = # prefijos con balance b que aun pueden iniciar una subcadena valida
    ll res = 0; int bal = 0; map<int,ll> c; c[0] = 1;
    for (char ch : s){
        if (ch == '('){ bal++; c[bal]++; }
        else { c[bal] = 0; bal--; res += c[bal]; c[bal]++; } }
    return res; }
