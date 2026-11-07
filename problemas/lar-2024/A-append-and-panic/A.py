# y = letras distintas de t ordenadas, y t contiene todas las letras de S -> |y| = letras distintas de S
s = input().strip()
print(len(s) - len(set(s)))
