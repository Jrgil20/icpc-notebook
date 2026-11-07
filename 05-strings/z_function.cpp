// Z-function: z[i] = largo del mayor prefijo comun entre s y s[i..]
vector<int> zfn(const string& s){ int n = s.size(); vector<int> z(n, 0);
    for (int i = 1, l = 0, r = 0; i < n; i++){ if (i < r) z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++; if (i + z[i] > r){ l = i; r = i + z[i]; } }
    return z; }
