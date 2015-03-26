# coding: utf-8
n, k = [int(i) for i in input().split()]
f = [int(i) for i in input().split()]
current = 1
ans = 0
f.sort()
while f:
    length = len(f)
    if length%k == 0:
        ans += (f[0]-current)*((length//k)*2-1)
    else:
        ans += (f[0]-current)*((length//k)*2+1)
    current = f[0]
    while f and f[0] == current:
        del(f[0])
print(ans+current-1)
