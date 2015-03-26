# coding: utf-8
n, s = [int(i) for i in input().split()]
ans = -1 
for i in range(n):
    x, y = [int(i) for i in input().split()]
    if s*100>=x*100+y:
        ans = max((s*100-x*100-y)%100,ans)
print(ans)
