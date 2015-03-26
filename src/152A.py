# coding: utf-8
n, m = [int(i) for i in input().split()]
stu = []
for i in range(n):
    stu.append([int(ch) for ch in input()])
best = []
for i in range(m):
    best.append(max([stu[j][i] for j in range(n)]))
ans = 0
for i in range(n):
    for j in range(m):
        if stu[i][j] == best[j]:
            ans += 1
            break
print(ans)
