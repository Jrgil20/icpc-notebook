import sys
from collections import Counter, defaultdict, deque
import heapq, bisect, math, itertools
input = sys.stdin.readline          # lectura rapida: usa .strip() en strings
sys.setrecursionlimit(10**6)        # solo si usas recursion (y aun asi, cuidado)

def main():
    n = int(input())
    a = list(map(int, input().split()))
    # ... resolver ...
    print(sum(a))

main()
