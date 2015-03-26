# coding: utf-8
r, c = [int(i) for i in input().split()]
row = []
ans = 0
for i in range(r):
    s = [ch for ch in input()]
    if 'S' not in s:
        ans += c
        s = 'X'*c 
    row.append(s)
for i in range(c):
    col = []
    for j in range(r):
        col.append(row[j][i])
    if 'S' not in col:
        ans += col.count('.')
print(ans)
