n = int(input())
a = [int(x) for x in input().split()]
cur = 1
bad = False
for i in range(n):
    cur = cur * 2
    cur = cur - a[i]
    if(cur < 0 and (not bad)):
        bad = True
        print("error")
if(not bad):
    print(cur % (1000000007))