# coding: utf-8
n = int(input())
cnt = 0
for i in range(n):
    sum = 0
    for j in input().split():
        sum += int(j)
    if sum >= 2:
        cnt += 1
        
print(cnt)
