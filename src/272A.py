# coding: utf-8
n = int(input())
figers = sum([int(i) for i in input().split()])
ans = 0
for i in range(1,6):
    if (figers+i)%(n+1)!=1:
        ans += 1
print(ans)
