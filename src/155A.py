# coding: utf-8
n = int(input())
li = [int(i) for i in input().split()]
cnt = 0
for i in range(n):
    if i == 0:
        min = li[i]
        max = li[i]
    elif min > li[i]:
        min = li[i]
        cnt += 1
    elif max < li[i]:
        max = li[i]
        cnt += 1
print(cnt)
