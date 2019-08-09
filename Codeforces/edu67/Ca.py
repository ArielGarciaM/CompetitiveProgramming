n,m = [int(x) for x in input().split()]
I = []
D = []
for _ in range(m):
    t,l,r = [int(x) for x in input().split()]
    if t == 1:
        I.append((l,r))
    else:
        D.append((l,r))
 
S = [0]*(n-1)
 
for i in I:
    for j in range(i[0]-1,i[1]-1):
        S[j] = 1
 
possible = True
for i in D:
    for j in range(i[0]-1,i[1]-1):
        if S[j] == 0:
            S[j] = -1
            break
        elif S[j] == -1:
            break
    else:
        possible = False
 
if not possible:
    print('NO')
else:
    print('YES')
    T = ['2']
    for a in S:
        if a == 1:
            T.append('2')
        elif a== 0:
            T.append('2')
        else:
            T.append('1')
    print(' '.join(T))
