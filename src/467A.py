# coding: utf-8
n = int(input())
cnt = 0
for i in range(n):
    p, q = [int(j) for j in input().split()]
    if q-p >= 2:
        cnt += 1
        
print(cnt)
