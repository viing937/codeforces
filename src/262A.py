# coding: utf-8
n, k = [int(i) for i in input().split()]
ans = 0
for s in input().split():
    if s.count('4')+s.count('7')<=k:
        ans += 1
print(ans)
