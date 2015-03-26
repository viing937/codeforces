# coding: utf-8
n = int(input())
cnt = [0]*3
for i in range(n):
    temp = [int(j) for j in input().split()]
    for j in range(3):
        cnt[j] += temp[j]
if cnt[0] == 0 and cnt[1] == 0 and cnt[2] == 0:
    print('YES')
else:
    print('NO')
