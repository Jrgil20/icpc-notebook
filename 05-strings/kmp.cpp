// KMP (funcion prefijo) + buscar patron
vector<int> prefixFn(const string& s){ int n = s.size(); vector<int> pi(n, 0);
    for (int i = 1; i < n; i++){ int j = pi[i-1]; while (j > 0 && s[i] != s[j]) j = pi[j-1]; if (s[i] == s[j]) j++; pi[i] = j; }
    return pi; }
vector<int> findAll(const string& txt, const string& pat){ // posiciones donde aparece pat
    string s = pat + "#" + txt; auto pi = prefixFn(s); vector<int> res; int m = pat.size();
    for (int i = m + 1; i < (int)s.size(); i++) if (pi[i] == m) res.push_back(i - 2 * m);
    return res; }
