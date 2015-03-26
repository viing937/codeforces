# coding: utf-8
n, x = [int(i) for i in input().split()]
current = 1
ans = 0
for i in range(n):
    l, r = [int(i) for i in input().split()]
    ans += (l-current)%x + (r-l+1)
    current = r+1
print(ans)
