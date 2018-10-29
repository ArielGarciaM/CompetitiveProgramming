prev = 1
curr = 1
for i in range(2, 10000):
    if(curr >= 10**999):
        print(i)
        break
    temp = curr
    curr = curr + prev
    prev = temp