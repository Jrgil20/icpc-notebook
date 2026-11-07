import sys
input = sys.stdin.readline

def main():
    t = int(input())                 # quita estas 2 lineas si hay un solo caso
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        print(sum(a))

main()
