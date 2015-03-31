# coding: utf-8
n = int(input())
m = [[int(j) for j in input().split()] for i in range(n)]
rowsum = [sum(i) for i in m]
colsum = [sum([row[i] for row in m]) for i in range(n)]
ans = 0
for i in range(n):
    for j in range(n):
        if rowsum[i]<colsum[j]:
            ans += 1
print(ans)
