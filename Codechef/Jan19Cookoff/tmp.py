t = int(input())
while t>0:
    t-=1
    n = int(input())
    l1 = []
    l2 = []
    for i in range(n):
        l1.append([int(x) for x in input().split()])
    for i in range(n):
        l2.append([int(x) for x in input().split()])
    
    theer = True

    for i in range(n):
        for j in range(n):
            if l1[i][j]==l2[i][j]:
                if not (l1[j][i]==l2[j][i]):
                    theer = False
                    break
            if l1[i][j]==l2[j][i]:
                if not (l1[j][i]==l2[i][j]):
                    theer = False
                    break
    if not theer:
        print("No")
        continue

    def transpose(l1, j):
        jthrow = l1[j]
        jthcol = []
        for i in range(len(l1)):
            jthcol.append(l1[i][j])
            l1[i][j] = jthrow[i]
        l1[j] = jthcol

    for i in range(n):
        for j in range(n):
            if l1[i][j]==l2[i][j]:
                continue
            else:
                transpose(l1, j)
    for i in range(n):
        for j in range(n):
            if l1[i][j]!=l2[i][j]:
                theer = False
                break
    if not theer:
        print("No")
        continue
    else:
        print("Yes")
        continue


# 1 2 3
# 4 5 6
# 7 8 9
# 1 4 7
# 2 5 8
# 3 6 9
# 1 4 3
# 2 5 8
# 7 6 9