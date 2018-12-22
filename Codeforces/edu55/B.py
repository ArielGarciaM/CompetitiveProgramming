n = int(input())
L = [x for x in input()]
S = []
beggining = L[0]
temp = 1
for i in range(1,n):
    if L[i] == L[i-1]:
        temp += 1
    else:
        S.append((temp,L[i-1]))
        temp = 1
S.append((temp,L[n-1]))
high = 0
goldCount = 0
for i in S:
    if i[1] == 'G':
        goldCount += 1
        if i[0] > high:
            high = i[0]
start = high
goldCheck = goldCount >= 3
if len(S) == 1:
    if L[0] == 'G':
        print(S[0][0])
    elif L[0] == 'S':
        print(0)
else:
    for i in range(1,len(S)-1):
        if (S[i][0] == 1 and S[i][1] == 'S'):
            if S[i-1][0] + S[i+1][0]+goldCheck > high:
                high = S[i-1][0] + S[i+1][0]+goldCheck
    print(max(high,start+(goldCount >= 2)))