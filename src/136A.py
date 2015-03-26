# coding: utf-8
n = int(input())
p = [int(i) for i in input().split()]
mark = {}
for i in range(n):
    mark[p[i]] = str(i+1)

print(' '.join(mark.values()))
