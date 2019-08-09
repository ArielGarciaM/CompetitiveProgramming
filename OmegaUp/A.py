def pers(n):
    res = 0 
    while(n > 9):
        m = n
        prod = 1
        while(m > 1):
            prod = prod * (m % 10)
            m = m // 10
        res = res + 1
        n = prod
    return res

best = 0
num = 0

for x in range(10, 10000000):
    p = pers(x)
    if(p > best):
        best = p
        num = x

for x in range(10, 400000000):
    if(pers(x) == best):
        y = x
        while(y % 2 == 0):
            y = y // 2
        while(y % 3 == 0):
            y = y // 3
        while(y % 7 == 0):
            y = y // 7
        if(y == 1):
            print(x)

print(num)
print(best)

# 34888999