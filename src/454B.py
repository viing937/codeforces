# coding: utf-8
n = int(input())
a = [int(i) for i in input().split()]
for i in range(n):
    if i < n-1 and a[i+1]<a[i]:
        break
if i==n-1:
    ans = 0
else:
    ans = n-1-i
a = a[i+1:]+a[:i+1]
for i in range(n-1):
    if a[i] > a[i+1]:
        print(-1)
        break
else:
    print(ans)
