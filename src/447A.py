# coding: utf-8
p, n = [int(i) for i in input().split()]
mark = [0]*p
for i in range(n):
    num = int(input())%p
    if mark[num]==1:
        print(i+1)
        break
    mark[num] = 1
else:
    print(-1)
