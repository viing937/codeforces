# coding: utf-8
n, m = [int(i) for i in input().split()]
f = [int(i) for i in input().split()]
f.sort()
ans = f[n-1] - f[0]
for i in range(n, m):
    if f[i]-f[i-n+1] < ans:
        ans = f[i]-f[i-n+1]
print(ans)
