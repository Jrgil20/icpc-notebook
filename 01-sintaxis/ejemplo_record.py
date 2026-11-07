n = int(input())
a = list(map(int, input().split()))   # toda la linea -> lista de enteros, una sola vez
mx, dias = a[0], 1
for v in a[1:]:
    if v > mx:
        mx = v
        dias += 1
print(dias)
