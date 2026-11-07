// Longitud de la union de intervalos [l, r]
// Requiere: reales/base_flotante.cpp (ld)
ld unionLength(vector<pair<ld,ld>> v){
    sort(v.begin(), v.end()); ld tot = 0, curL = 0, curR = -1e30; bool open = false;
    for (auto [l, r] : v){
        if (!open || l > curR){ if (open) tot += curR - curL; curL = l; curR = r; open = true; }
        else curR = max(curR, r); }
    if (open) tot += curR - curL; return tot; }
