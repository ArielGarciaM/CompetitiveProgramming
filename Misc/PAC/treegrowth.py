h = list(map(int, input().split()))
n = len(h)
while(True):
    g = [0]*n
    for i in range(n):
        if(i == 0 or h[i] > h[i - 1]):
            g[i] = 1
        else:
            g[i] = g[i - 1]
            if(h[i] < h[i - 1]):
                g[i] += 1
    d = []
    for i in range(1, n):
        d.append(h[i] - h[i - 1])
    #print('h = ' + str(h))
    #print('g = ' + str(g))
    print('d = ' + str(d))
    if(g == [1]*n):
        break
    for i in range(n):
        h[i] += g[i]