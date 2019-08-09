def big(n):
    if(n >= 63):
        return 0
    return n

n = int(input())
print(big(n))
print(big(n//2))
print(big(n//3))
print(big(n//4))
print(big(n//5))
print(big(n//6))