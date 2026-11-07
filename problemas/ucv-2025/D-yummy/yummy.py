import sys
s = sys.stdin.readline().rstrip("\n")
yu = s.count("Yu")
resto = len(s) - 2 * yu          # caracteres que no son parte de un "Yu"
print("Yummy" if yu > resto / 2 else "Not so Yummy")
