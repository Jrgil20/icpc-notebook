#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++){ int u, v; cin >> u >> v; u--; v--; adj[u].push_back(v); adj[v].push_back(u); }
    vector<int> d(n, -1); queue<int> q; d[0] = 0; q.push(0);
    while (!q.empty()){ int u = q.front(); q.pop();
        for (int v : adj[u]) if (d[v] == -1){ d[v] = d[u] + 1; q.push(v); } }
    for (int i = 0; i < n; i++) cout << d[i] << " \n"[i == n - 1];
}
