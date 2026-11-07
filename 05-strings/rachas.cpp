// Rachas (run-length encoding): bloques de caracteres iguales consecutivos
// "aaabcc" -> {('a',3), ('b',1), ('c',2)}
vector<pair<char,int>> runs(const string& s){
    vector<pair<char,int>> r;
    for (char c : s){ if (!r.empty() && r.back().first == c) r.back().second++; else r.push_back({c, 1}); }
    return r; }
string collapse(const string& s){ string r; for (char c : s) if (r.empty() || r.back() != c) r += c; return r; } // "aaabcc" -> "abc"
