#!/usr/bin/env python3
"""Compila cada solucion de problemas/ y la corre contra sus ejemplos oficiales.

Uso:  python3 scripts/probar_problemas.py            (todos)
      python3 scripts/probar_problemas.py ucab-2025  (filtra por texto en la ruta)

Comparacion: si la carpeta tiene check.py se usa su funcion check(entrada, esperado, salida)
(problemas con varias respuestas validas); si tiene 'tolerancia', los numeros se comparan con
error absoluto o relativo; si no, la salida debe coincidir token por token.
"""
import glob, os, subprocess, sys, importlib.util, tempfile

RAIZ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
filtro = sys.argv[1] if len(sys.argv) > 1 else ""

def compilar(src, tmp):
    if src.endswith(".py"):
        return ["python3", src]
    exe = os.path.join(tmp, os.path.basename(src) + ".bin")
    r = subprocess.run(["g++", "-std=c++20", "-O2", src, "-o", exe], capture_output=True, text=True)
    if r.returncode != 0:
        print(r.stderr); return None
    return [exe]

def numeros_iguales(a, b, tol):
    ta, tb = a.split(), b.split()
    if len(ta) != len(tb): return False
    for x, y in zip(ta, tb):
        try:
            fx, fy = float(x), float(y)
            if abs(fx - fy) > tol * max(1.0, abs(fy)): return False
        except ValueError:
            if x != y: return False
    return True

total = fallos = 0
with tempfile.TemporaryDirectory() as tmp:
    for carpeta in sorted(glob.glob(os.path.join(RAIZ, "problemas", "*", "*"))):
        if filtro not in carpeta or not os.path.isdir(os.path.join(carpeta, "ejemplos")): continue
        fuentes = [f for f in glob.glob(os.path.join(carpeta, "*")) if f.endswith((".cpp", ".py")) and not f.endswith("check.py")]
        if not fuentes: continue
        cmd = compilar(fuentes[0], tmp)
        nombre = os.path.relpath(carpeta, os.path.join(RAIZ, "problemas"))
        if cmd is None:
            print(f"[ERROR] {nombre}: no compila"); fallos += 1; continue
        check = None
        if os.path.exists(os.path.join(carpeta, "check.py")):
            spec = importlib.util.spec_from_file_location("check", os.path.join(carpeta, "check.py"))
            mod = importlib.util.module_from_spec(spec); spec.loader.exec_module(mod); check = mod.check
        tol = None
        if os.path.exists(os.path.join(carpeta, "tolerancia")):
            tol = float(open(os.path.join(carpeta, "tolerancia")).read())
        ok_todos = True
        for entrada in sorted(glob.glob(os.path.join(carpeta, "ejemplos", "*.in"))):
            esperado = open(entrada[:-3] + ".out").read(); inp = open(entrada).read()
            salida = subprocess.run(cmd, input=inp, capture_output=True, text=True, timeout=20).stdout
            total += 1
            if check: ok = check(inp, esperado, salida)
            elif tol is not None: ok = numeros_iguales(salida, esperado, tol)
            else: ok = salida.split() == esperado.split()
            if not ok:
                ok_todos = False; fallos += 1
                print(f"[FALLA] {nombre} {os.path.basename(entrada)}\n  esperado: {esperado.strip()[:200]}\n  obtenido: {salida.strip()[:200]}")
        if ok_todos: print(f"[OK] {nombre}")
print(f"\n{total - fallos}/{total} ejemplos correctos")
sys.exit(1 if fallos else 0)
