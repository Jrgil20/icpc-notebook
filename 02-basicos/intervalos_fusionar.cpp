// Fusionar intervalos enteros [l, r] que se solapan o tocan
vector<pair<ll,ll>> mergeIntervals(vector<pair<ll,ll>> v){
    sort(v.begin(), v.end()); vector<pair<ll,ll>> res;
    for (auto [l, r] : v){ if (!res.empty() && l <= res.back().second + 1) res.back().second = max(res.back().second, r); else res.push_back({l, r}); }
    return res; } // quita el +1 si [1,3] y [4,6] NO deben unirse
