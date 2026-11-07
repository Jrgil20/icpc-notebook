# Acepta cualquier montana valida (hay varias respuestas correctas).
def check(inp, expected, out):
    n_line, a_line = inp.split("\n")[:2]; n = int(n_line); a = list(map(int, a_line.split()))
    if expected.strip() == "*": return out.strip() == "*"
    p = list(map(int, out.split()))
    if sorted(p) != list(range(1, n + 1)) or any(a[i] and a[i] != p[i] for i in range(n)): return False
    i = 0
    while i + 1 < n and p[i] < p[i + 1]: i += 1
    while i + 1 < n and p[i] > p[i + 1]: i += 1
    return i == n - 1
