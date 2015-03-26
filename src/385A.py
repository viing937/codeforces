# coding: utf-8
n, c = [int(i) for i in input().split()]
x = [int(i) for i in input().split()]
for i in range(n-1):
    x[i] = x[i]-x[i+1]
ans = max(x[:-1])-c
if ans > 0:
    print(ans)
else:
    print(0)
