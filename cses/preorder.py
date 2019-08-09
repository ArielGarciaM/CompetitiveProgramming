s = input()
n = len(s)
l = [0]*26
for i in range(n):
    l[ord(s[i])-65] += 1
if(sum(x%2 for x in l) > 1):
    print("NO SOLUTION")
t = ""
for i in range(26):
    t += chr(65+i)*(l[i]//2)
for i in range(26):
    if(l[i]%2):
        t += chr(65+i)
for i in range(25, -1, -1):
    t += chr(65 + i)*(l[i]//2)
print(t)