# coding: utf-8
n = int(input())
a = [int(i) for i in input().split()]
a.sort()
ans = 0
for i in range(1,n+1):
    ans += abs(a[i-1]-i)
print(ans)
