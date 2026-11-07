// Grundy / mex
int mex(vector<int>& v){ set<int> s(v.begin(), v.end()); int m = 0; while (s.count(m)) m++; return m; }
