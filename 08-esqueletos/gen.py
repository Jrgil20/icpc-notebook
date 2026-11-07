import random, sys
# Generador de casos PEQUENOS: el numero de semilla llega como argumento para poder repetir un caso.
random.seed(int(sys.argv[1]) if len(sys.argv) > 1 else 0)
n = random.randint(1, 8)
print(n)
print(*[random.randint(1, 10) for _ in range(n)])
