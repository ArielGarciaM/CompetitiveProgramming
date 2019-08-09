t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    if((a+a-b)%3 or 2*min(a,b) < max(a,b)):
        print("NO")
    else:
        print("YES")