# Acepta cualquier fila valida: K 'X' sin vecinos y ningun '-' libre con ambos lados libres.
def check(inp, expected, out):
    k, n = map(int, inp.split()); t = out.strip()
    if expected.strip() == "*": return t == "*"
    if len(t) != n or t.count("X") != k or "XX" in t: return False
    return all(not (t[i] == "-" and (i == 0 or t[i-1] == "-") and (i == n - 1 or t[i+1] == "-")) for i in range(n))
