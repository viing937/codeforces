n, k = input().split()
n, k = n[::-1], int(k)
r = 0
for i in range(len(n)):
    if n[i] != '0':
        r += 1
    if i-r+1 == k:
        break
else:
    r = len(n)-1
print(r)
