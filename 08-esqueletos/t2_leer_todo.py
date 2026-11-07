import sys
data = sys.stdin.buffer.read().split()   # todo el input de golpe: lo mas rapido
pos = 0
def nxt():
    global pos
    pos += 1
    return data[pos - 1]
n, m = int(nxt()), int(nxt())
g = [[] for _ in range(n)]
for _ in range(m):
    u, v = int(nxt()) - 1, int(nxt()) - 1
    g[u].append(v); g[v].append(u)
# ... resolver ...
print(sum(len(v) for v in g) // 2)   # ejemplo: cantidad de aristas
