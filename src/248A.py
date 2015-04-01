# coding: utf-8
n = int(input())
left = []
right = []
for i in range(n):
    tmp = [int(j) for j in input().split()]
    left.append(tmp[0])
    right.append(tmp[1])
ans = min(left.count(0),left.count(1)) + min(right.count(0),right.count(1))
print(ans)
