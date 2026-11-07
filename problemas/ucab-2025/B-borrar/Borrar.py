import sys
from itertools import groupby
# Se lee la linea COMPLETA (con espacios); solo se quita el salto de linea.
texto = sys.stdin.readline().rstrip("\n")
quitar = set(sys.stdin.readline().rstrip("\n")[1:-1])     # lo que esta entre [ y ], puede incluir ' '
filtrado = "".join(c for c in texto if c not in quitar)
mensaje = "".join(c for c, _ in groupby(filtrado))          # el mensaje no repite simbolos consecutivos
print(mensaje.strip())
