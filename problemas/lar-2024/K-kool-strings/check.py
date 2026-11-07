# Mismo numero minimo de cambios y una cadena kool que se obtenga con esos cambios.
def check(inp, expected, out):
    k, s = inp.split(); k = int(k); c, t = out.split(); ce = int(expected.split()[0])
    if int(c) != ce or len(t) != len(s) or sum(x != y for x, y in zip(s, t)) != ce: return False
    return all(len(set(t[i:i + k])) > 1 for i in range(len(t) - k + 1))
