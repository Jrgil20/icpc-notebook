// DFS iterativo (componentes)
vector<int> components(vector<vector<int>>& adj, int &cnt){
    int n = adj.size(); vector<int> comp(n, -1); cnt = 0;
    for (int s = 0; s < n; s++) if (comp[s] == -1){
        stack<int> st; st.push(s); comp[s] = cnt;
        while (!st.empty()){ int u = st.top(); st.pop();
            for (int v : adj[u]) if (comp[v] == -1){ comp[v] = cnt; st.push(v); } }
        cnt++; }
    return comp;
}
