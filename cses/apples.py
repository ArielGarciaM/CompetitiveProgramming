from itertools import *
n = int(input())
l = [map(int, input().split())]
print(min(abs(sum(l) - 2*sum(l[x] for x in c)) for m in range(n//2+1) for c in combinations(range(n), m)))