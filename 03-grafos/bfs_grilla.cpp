// BFS grid
int dr[4] = {-1,1,0,0}, dc[4] = {0,0,-1,1};
vector<vector<int>> bfsGrid(vector<string>& g, int sr, int sc){
    int R = g.size(), C = g[0].size();
    vector<vector<int>> d(R, vector<int>(C, -1)); queue<pair<int,int>> q;
    d[sr][sc] = 0; q.push({sr, sc});
    while (!q.empty()){ auto [r, c] = q.front(); q.pop();
        for (int k = 0; k < 4; k++){ int nr = r + dr[k], nc = c + dc[k];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (g[nr][nc] == '#' || d[nr][nc] != -1) continue;
            d[nr][nc] = d[r][c] + 1; q.push({nr, nc}); } }
    return d;
}
