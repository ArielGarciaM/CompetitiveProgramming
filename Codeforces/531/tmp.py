n,k = [int(x) for x in input().split()]
L = [int(x) for x in input().split()]

D = {}
for i in L:
    if i in D:
        D[i] += 1
    else:
        D[i] = 1

s = max(D.values())

if s > k:
    print('NO')
else:
    print('YES')
    S = sorted(L)
    Pos = {}
    for i in range(n):
        if S[i] in Pos:
            Pos[S[i]].append(i)
        else:
            Pos[S[i]] = [i]
    Used = {}
    for i in Pos:
        Used[i] = 0
    for i in range(n):
        print(((Pos[L[i]][Used[L[i]]])%k)+1, end = ' ')
        Used[L[i]] += 1

    