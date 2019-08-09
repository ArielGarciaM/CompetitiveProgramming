from itertools import *
s = input()
S = set(''.join(t) for t in permutations(s))
print(len(S))
for x in sorted(S):
    print(x)