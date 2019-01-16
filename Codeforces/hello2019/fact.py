n = int(input())
fact = {}
prime = True
for d in range(2, 1000000000000000000):
    if(n == 1):
        break
    while(n % d == 0):
        prime = False
        if(d in fact.keys()):
            fact[d] += 1
        else:
            fact[d] = 1
        n /= d
    if(d * d > n and prime):
        break
if(prime):
    fact[n] = 1
for p in fact:
    print(p, "^", fact[p])