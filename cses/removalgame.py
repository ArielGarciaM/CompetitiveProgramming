def res(l, t):
    n = len(l)
    a = sum(l[x] for x in range(0, n, 2))
    b = sum(l[x] for x in range(1, n, 2))
    if(a > b):
        a, b = b, a
    return b if t > 0 else a

n = int(input())
l = list(map(int, input().split()))
if(n % 2):
    print(max(l[0] + res(l[1:], 0), l[n - 1] + res(l[:-1], 0)))
else:
    print(res(l, 1))