// Geometria en enteros
struct P { ll x, y;
    P operator-(const P& o) const { return {x - o.x, y - o.y}; }
    P operator+(const P& o) const { return {x + o.x, y + o.y}; }
    bool operator<(const P& o) const { return x != o.x ? x < o.x : y < o.y; }
    bool operator==(const P& o) const { return x == o.x && y == o.y; } };
ll cross(P a, P b){ return a.x * b.y - a.y * b.x; }
ll dot(P a, P b){ return a.x * b.x + a.y * b.y; }
ll orient(P a, P b, P c){ return cross(b - a, c - a); } // >0 izq (antihorario), <0 der, 0 colineal
ll area2(vector<P>& p){ ll s = 0; int n = p.size(); // 2*area con signo (shoelace)
    for (int i = 0; i < n; i++) s += cross(p[i], p[(i + 1) % n]); return s; }
